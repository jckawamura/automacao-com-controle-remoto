# Automação de um ambiente com controle remoto
Projeto final da disciplina de Laboratório de Microcontroladores e Aplicações desenvolvido por [Bruno Figueiredo](https://github.com/BrunoFig), [Gleno Mendes](https://github.com/gmpsmendes) e [Jorge Kawamura](https://github.com/jckawamura).

## Índice
1. [Proposta](https://github.com/jckawamura/automacao-com-controle-remoto#proposta)
2. [Material](https://github.com/jckawamura/automacao-com-controle-remoto#material)
3. [Vídeo de apresentação](https://github.com/jckawamura/automacao-com-controle-remoto#vídeo-de-apresentação)
4. [Bibliotecas utilizadas](https://github.com/jckawamura/automacao-com-controle-remoto#bibliotecas-utilizadas)
5. [Instalação das bibliotecas](https://github.com/jckawamura/automacao-com-controle-remoto#instalação-das-bibliotecas)
6. [Comunicação com o LCD](https://github.com/jckawamura/automacao-com-controle-remoto#comunicação-com-o-lcd)
7. [Comunicação com o sensor IR](https://github.com/jckawamura/automacao-com-controle-remoto#comunicação-com-o-sensor-ir)
8. [Configuração do controle remoto](https://github.com/jckawamura/automacao-com-controle-remoto#configuração-do-controle-remoto)

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

## Comunicação com o sensor IR
A comunicação do sensor IR é feita pelo protocolo NEC que utiliza apenas 3 pinos, sendo eles: Vcc, Ground e Out.
O pino Out é o responsável pela transmissão dos dados interpretados pelo receptor IR, de modo que é ele que será lido pelo arduino para se saber qual botão foi pressionado.
O protocolo Nec, também conhecido como formato japonês, utiliza uma frequência transmissora de 38 kHz e pulsos de codificação a distância. O protocolo faz uso de 8 bits de endereçamento com 8 bits de comando com um tempo entre os bits 1.12 ms ou 2.25 ms.

## Configuração do controle remoto
O mapeamento do controle é feito usando o Serial Monitor para reconhecer o hexadecimal associado ao botão.
Execute o programa no Arduino e teste cada tecla do controle remoto com o Serial Monitor aberto. A cada vez que o receptor IR receber o sinal enviado pelo controle o Serial Monitor exibirá o hexadecimal correspondente. Identifique o  hexadecimal correspondente a cada botão e substitua nas constantes de configuração do controle. Por exemplo, se o botão de ligar o LED for identificado como A0A0A0A0, substitua
```sh
const long int botaoLed = 0xA90;
```
por

```sh
const long int botaoLed = 0xA0A0A0A0;
```
Repita o procedimento para o restante dos botões.



