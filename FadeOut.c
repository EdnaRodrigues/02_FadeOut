#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída para uso de funções como printf.
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.

// Definição de pinos de controle do LED RGB e do botão.
#define green_pin 11
#define blue_pin 12
#define red_pin 13
#define button_A 5

// Define o estado inicial do LED RGB como desligado (false), nos 3 momentos possíveis.
bool led_on = false;

// Define em qual interrupção está.
uint8_t i;

//Variável para comparação de tempo
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

void apagar_led (int apaga) {
    if (apaga == 0) { // Cor branca, 3 LEDs ligados.
        gpio_put(green_pin, true);
        gpio_put(blue_pin, true);
        gpio_put(red_pin, true);
    } else if (apaga == 1) { // Cor magenta, 2 LEDs ligados.
        gpio_put(green_pin, false);
        gpio_put(blue_pin, true);
        gpio_put(red_pin, true);
    } else if (apaga == 2) { // Cor azul, 1 LED ligado.
        gpio_put(green_pin, false);
        gpio_put(blue_pin, false);
        gpio_put(red_pin, true);
    } else if (apaga == 3) { // LEDs desligados.
        gpio_put(green_pin, false);
        gpio_put(blue_pin, false);
        gpio_put(red_pin, false);
    } else { //Opção inválida, cor verde.
        gpio_put(green_pin, true);
        gpio_put(blue_pin, false);
        gpio_put(red_pin, false);
    }
}

// Função de callback para desligar LEDs após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    
    // Rotinas para desligamento de LEDs.
    
    if (i == 1) {
        apagar_led (i); //Desligar 1 dos LEDs.
        i++;
        //led_on = true;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (i == 2) {
        apagar_led(i);// Desligar +1 (2) dos LEDs.
        i++;
        //led_on = true;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    } else if (i == 3) {
        apagar_led(i);// Desligar +1 (3) dos LEDs.
        i++;
        if (i > 3) {
            i = 1; // Reinicia o valor de i após 3
        }
        led_on = false;
    }

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}

//Rotina para interrupção do botão
void gpio_irq_handler(uint gpio, uint32_t events) {
    
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    
    if (current_time - last_time > 300000) { //Apenas ativa as funções quando o intervalo entre acionamentos é superior a 0.3 segundos
        last_time = current_time; //Atualiza o tempo do último evento

        if (gpio == button_A && !led_on) { // Verificação se o botão foi pressionado e se os LEDs estão deligados.
            apagar_led(0); // Liga todos os LEDs.
            led_on = true; // Define-se 'led_on' como true para indicar que existe LED aceso.
            i = 1; // Indicar a primeira chamada de alarme.
            // Agenda um alarme para desligar o LED após 3 segundos (3000 ms).
            // A função 'turn_off_callback' será chamada após esse tempo.
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        /*} else if (gpio == button_B) {
            reset_usb_boot(0,0); //Habilita o modo de gravação do microcontrolador
        }*/ else {
            // Não faz nada
        }  
    }
}

int main() {
    // Inicializa a comunicação serial para permitir o uso de printf.
    // Isso é útil para depuração, embora não seja solicitada nessa atividade.
    stdio_init_all();

    //Inicializa os pinos do LED RGB como saídas digitais.
    gpio_init(green_pin);
    gpio_set_dir(green_pin,GPIO_OUT);
    gpio_init(blue_pin);
    gpio_set_dir(blue_pin,GPIO_OUT);
    gpio_init(red_pin);
    gpio_set_dir(red_pin,GPIO_OUT);

    //Inicializa os pinos do botão como entradas digitais.
    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN);
    gpio_pull_up(button_A); //Habilita o resistor pull-up interno para o pino do botão, garantindo que o pino seja lido como 0 quando o botão está pressionado.

    //Interrupções por botóes habilitadas
    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, & gpio_irq_handler);

    while (true) {
        tight_loop_contents(); // Função que otimiza o loop vazio para evitar consumo excessivo de CPU.
    }
    
    // Retorno de 0, que nunca será alcançado devido ao loop infinito.
    // Isso é apenas uma boa prática em programas com um ponto de entrada main().
    return 0;
}
