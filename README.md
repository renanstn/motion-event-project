# motion-event-project
Repositório de um micro-projeto utilizando ESP-32 e um servidor em Flask (python), onde o ESP emite um sinal ao detectar movimentos, e este sinal aciona um atalho no computador que está rodando o servidor (um alt + tab, por exemplo)

## Oh God why?
A idéia deste projeto veio [deste](https://www.tindie.com/products/dekuNukem/daytripper-hide-my-windows-laser-tripwire/) produto aleatório com a mesma proposta, cuja propaganda apareceu no meu feed em uma dia qualquer. Achei o produto interessante e resolvi replicar, porém, com os materiais que eu tinha em casa.

![funcionamento do produto](https://github.com/Doc-McCoy/motion-event-project/blob/master/screenshots/example.gif)

## Oh God how?
O projeto é dividido em duas partes:
- Uma API rodando na máquina, que utiliza o pyautogui para dar um comando específico (no caso, um "alt+tab") ao receber uma request de alerta.
- O ESP32 com um sensor de presença, posicionado em qualquer lugar da casa, na mesma rede wifi do computador onde está a API. O ESP32 emite a request para a API quando o sensor detecta presença.
