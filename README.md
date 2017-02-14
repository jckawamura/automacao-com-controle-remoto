# Automação de um ambiente com controle remoto
Projeto final da disciplina de Laboratório de Microcontroladores e Aplicações desenvolvido por [Bruno Figueiredo](https://github.com/BrunoFig), [Gleno Mendes](https://github.com/gmpsmendes) e [Jorge Kawamura](https://github.com/jckawamura).

## Proposta
O projeto tem como objetivo automatizar um ambiente com um Arduino. Será simulado um ambiente com luzes, um ventilador e um display LCD que são controlados por controle remoto infravermelho.
O usuário poderá ligar, desligar e controlar a intensidade de um conjunto de leds, controlar a velocidade e a direção de um motor que simula um ventilador e definir uma mensagem de status pré-definidas (por exemplo: "Em aula", "Ocupado", "Disponível", "Em casa", "No mercado") a ser exibida em um display LCD.

## Material
- Arduino
- Controle remoto IR e respectivo receptor IR
- LEDS
- Motor elétrico
- Display LCD

## Vídeo de apresentação
[![Apresentação do projeto](https://img.youtube.com/vi/Y13-LeeWbRk/0.jpg)](https://www.youtube.com/watch?edit=vd&v=Y13-LeeWbRk "Apresentação do projeto")

## Bibliotecas utilizadas
- [Grove - LCD RGB Backlight](https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight)
- [IRremote Arduino Library](https://github.com/z3t0/Arduino-IRremote)

## Instalação das bibliotecas
- Faça o download das duas bibliotecas
- Copie a pasta para o diretório de bibliotecas do Arduino (C:\Program Files (x86)\Arduino\libraries)
- Exclua a seguinte biblioteca: \libraries\RobotIRremote

## Comunicação com o LCD
A comunicação com o LCD é feita pelo protocolo I2C que utiliza apenas 4 pinos: Vcc, Ground, SDA e SCL.
Serial Data (SDA) é a porta utilizada para transferência de dados; Serial Clock (SCL) serve para temporização entre os dispositivos, de modo que a comunicação pela SDA possa ter confiabilidade.
Para o endereçamento do dispositivo são utilizados 7 bits, portanto é possível comunicar 127 dispositivos utilizando esse protocolo. Além disso há um bit que indica se a operação é de escrita ou leitura.
A comunicação é feita então utilizando as seguintes funções:

| Função | Descrição |
| ------ | ------ |
| Wire.beginTransmission(endereço); | Define o dispositivo que receberá os dados |
| Wire.write(memória); | Informa qual registrador do dispositivo será utilizado |
| Wire.write(valor); | Envia o valor (sempre 1 byte) pela SDA para o dispositivo informado anteriormente |
| Wire.endTransmission(); | Finaliza a operação, liberando o dispositivo e o barramento I2C para novas operações |



