#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída para uso de funções como printf.
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.

// Definição de pinos de controle do LED RGB e do botão.
#define green_pin 11
#define blue_pin 12
#define red_pin 13
#define button_pin 5

// Define o estado inicial do LED RGB como desligado (false), nos 3 momentos possíveis.
bool led_on = false;

// Função de callback para desligar LEDs após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    
    // Rotina para desligamento de LEDs.

    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}

int main() {
    // Inicializa a comunicação serial para permitir o uso de printf.
    // Isso é útil para depuração, embora não seja solicitada nessa atividade.
    stdio_init_all();

    //Inicializa os pinos do LED RGB como saídas digitais.
    gpio_init(green_pin);
    gpio_set_dir(green_pin,true);
    gpio_init(blue_pin);
    gpio_set_dir(blue_pin,true);
    gpio_init(red_pin);
    gpio_set_dir(red_pin,true);

    //Inicializa os pinos do botão como entradas digitais.
    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_OUT);
    gpio_pull_up(button_pin); //Habilita o resistor pull-up interno para o pino do botão, garantindo que o pino seja lido como 0 quando o botão está pressionado.

    while (true) {
        
        //Inserir verificação se o botão foi pressionado e se os LEDs estão deligados.

        //Ao ativar a rotina com o botão acionado, ligar LEDs.

        tight_loop_contents(); // Função que otimiza o loop vazio para evitar consumo excessivo de CPU.

    }
    // Retorno de 0, que nunca será alcançado devido ao loop infinito.
    // Isso é apenas uma boa prática em programas com um ponto de entrada main().
    return 0;
}
