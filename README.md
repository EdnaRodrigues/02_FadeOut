# 🌟 FadeOut com Raspberry Pi Pico W

## 📌 Descrição do Projeto
Este projeto implementa um sistema de temporização para acionamento de LEDs utilizando um **botão pushbutton** e a função `add_alarm_in_ms()` do **Pico SDK**. O sistema segue uma sequência de desligamento gradual (**fade-out**) dos LEDs após o clique do botão.

---

## 🛠️ Funcionalidades
- **Acionamento de LEDs via pushbutton**.
- **Sequência de desligamento gradual dos LEDs**.
- **Uso de temporizador para controle de atraso (3 segundos entre estados)**.
- **Prevenção de reativação durante a execução das rotinas**.
- **Implementação de debounce por software para estabilidade do botão**.
- **Simulação no BitDogLab com LED RGB e Botão A**.

---

## 🔧 Hardware Necessário - Presentes na Placa de Desenvolvimento BitDogLab
- **Microcontrolador Raspberry Pi Pico W**
- **LED RGB**, ou 3 LEDs nas cores: vermelho, verde e azul.
- **3 Resistores de valor adequado** (Sugestão de 3 Resistores de 330 Ω).
- **Botão (Pushbutton)**, denominado como A na placa de desenvolvimento.
- **Fonte de alimentação adequada**.

---

## 📝 Código Principal
O código principal:
- **Liga os três LEDs ao pressionar o botão**.
- **Controla a sequência de desligamento utilizando temporizadores**.
- **Impede nova ativação do botão enquanto a rotina está em execução**.
- **Implementa debounce via software para evitar leituras instáveis**.

---

## 📌 Como Rodar o Projeto
1. **Faça git clone** deste repositório no Visual Studio Code.
2. **Importe a pasta como projeto Raspberry Pi Pico**.
3. **Compile e grave o código na placa**.
4. **Pressione o botão para iniciar a sequência de fade-out dos LEDs**.
5. **Adicione o executável na placa BitDogLab**
6. **Experimente a simulação com LED RGB e Botão no Wokwi integrado ao VSCode**.

---

## ✉️ Contato
Caso tenha dúvidas ou sugestões, entre em contato com o desenvolvedor.