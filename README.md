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
- **Simulação utilizando o simulador WokWi integrado ao VSCode**.
- **Simulação no BitDogLab com LED RGB e Botão A**.

---

## 🔧 Hardware Necessário - Presentes na Placa de Desenvolvimento BitDogLab
- **Microcontrolador Raspberry Pi Pico W**
- **LED RGB**, ou **3 LEDs** nas cores: vermelho (GPIO 13), verde (GPIO 11) e azul (GPIO 12).
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
### **Softwares Necessários**
1. **VS Code** com a extensão **Raspberry Pi Pico** instalada.
2. **CMake** e **Ninja** configurados.
3. **SDK do Raspberry Pi Pico** corretamente configurado.
4. Simulador **Wokwi** instalado e integrado ao VS Code.

### **Clonando o Repositório**
Para começar, clone o repositório no seu computador:
```bash
git clone https://github.com/EdnaRodrigues/02_FadeOut
cd 02_FadeOut
```

---

### **Execução no Projeto no VS Code**

#### **1. Importar o Projeto**
Após clonar o repositório:
1. Abra o **VS Code**.
2. No menu **Raspberry Pi Pico**, selecione **Import Project**.
3. Escolha a pasta clonada e clique em **Import**.

#### **2. Compilar o Código**
1. Clique no ícone **Raspberry Pi Pico** no lado esquerdo do VS Code.
2. Escolha a opção **Compile Project** para compilar o código.

---

### **Execução no Simulador Wokwi**

#### **1. Configurar o Simulador Wokwi**
1. Abra o arquivo `diagram.json` incluído no repositório.
2. Certifique-se de que o arquivo JSON está configurado corretamente para a simulação do hardware necessário:
   - LEDs conectados aos pinos GPIO 11, 12 e 13.

#### **2. Executar a Simulação**
1. Abra o painel do simulador Wokwi no VS Code.
2. Clique em **Play** para iniciar a simulação.
3. Aperte o botão A para acionamento dos LEDs.
4. Observe a mudança de estados entre os LEDs.

---

### **Execução na Placa BitDogLab**

#### **1. Coloque em Modo Reboot**
1. Aperte o botão **BOOTSEL** no microcontrolador Raspberry Pi Pico W.
2. Ao mesmo tempo, aperte o botão de **Reset**.

#### **2. Upload de Arquivo `FadeOut.uf2`**
1. Abra a pasta `build` incluído no repositório.
2. Mova o arquivo `FadeOut.uf2` para a placa de desenvolvimento.

#### **3. Acompanhar Execução do Programa**
1. Aperte o botão A para acionamento dos LEDs.
2. Observe a mudança de estados entre os LEDs.

---

## ✉️ Contato
Caso tenha dúvidas ou sugestões, entre em contato com o desenvolvedor.
