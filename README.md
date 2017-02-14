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

## Bibliotecas utilizadas
- [Grove - LCD RGB Backlight](https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight)
- [IRremote Arduino Library](https://github.com/z3t0/Arduino-IRremote)
