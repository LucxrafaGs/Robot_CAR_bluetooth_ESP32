# Robot_CAR_bluetooth_ESP32
Este código para o ESP32 utiliza a biblioteca ESP32Servo.h e a comunicação Bluetooth para controlar um ESC e quatro pinos digitais que podem ser usados para acionar motores ou outro sistema de movimento, como uma plataforma móvel. O controle é feito por meio de comandos enviados via Bluetooth.

Descrição do Código
Importação de Bibliotecas
#include <ESP32Servo.h>: Esta biblioteca permite o controle de servos ou ESCs usando o ESP32.
#include "BluetoothSerial.h": Habilita a comunicação Bluetooth no ESP32.
Definição de Variáveis
Servo esc: Declara um objeto esc que será responsável por controlar o ESC.
int escPin = 2: Define o pino digital 2 para controlar o sinal do ESC.
Pinos de controle de motores: São definidos quatro pinos (13, 27, 26, 25) para o controle do movimento de motores em diferentes direções.
BluetoothSerial SerialBT: Configura o Bluetooth do ESP32 com o nome "Patrickbot" para se comunicar com dispositivos externos.
char comando: Variável que armazenará o comando recebido via Bluetooth.
Função setup()
Configuração do ESC:

O servo é associado ao pino escPin (pino 2) com o intervalo de sinal PWM entre 1000 e 2000 µs.
O valor inicial de 1000 µs é enviado para armar o ESC, com um delay de 2 segundos para garantir a inicialização.
Configuração do Bluetooth:

Inicializa o Bluetooth com o nome "Patrickbot", permitindo o controle remoto por dispositivos móveis.
Configuração dos Pinos de Controle:

Os pinos 13, 27, 26 e 25 são configurados como saídas para controlar motores.
Função loop()
Leitura de Comandos Bluetooth:

Se houver um comando disponível via Bluetooth, ele será armazenado na variável comando.
Controle de Movimento (Switch Case):

Dependendo do comando recebido via Bluetooth, diferentes ações são executadas para controlar os motores conectados aos pinos definidos:
'F': Move a plataforma para frente.
'I': Gira a plataforma para frente e para a direita.
'G': Gira para frente e para a esquerda.
'R': Rotaciona para a direita.
'L': Rotaciona para a esquerda.
'B': Move a plataforma para trás.
'H': Move para trás e para a esquerda.
'J': Move para trás e para a direita.
Controle de Velocidade do ESC:

'W': Ajusta o sinal do ESC para 1200 µs, o que representa uma velocidade baixa.
'w': Desliga o motor enviando um sinal de 0 µs ao ESC.
Comando Padrão:

Se nenhum comando específico for recebido, os motores são desligados, configurando todos os pinos de controle como LOW.
Explicação do Controle
Bluetooth: Os comandos são enviados via Bluetooth e processados pelo ESP32 para controlar o movimento e a velocidade dos motores.
ESC: Controla a velocidade do motor conectado ao ESC usando sinais PWM ajustados via o comando Bluetooth.
Motores: Os pinos de controle configuram a direção dos motores para mover a plataforma em várias direções.
