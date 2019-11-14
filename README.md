# motion-event-project
Repositório de um micro-projeto utilizando ESP-32 e um servidor em Flask (python), onde o ESP emite um sinal ao detectar movimentos, e este sinal aciona um atalho no computador que está rodando o servidor (um alt + tab, por exemplo)

## Oh God why?
A idéia deste projeto veio de um produto chinês aleatório com a mesma proposta, cuja propaganda apareceu no meu feed.

## Oh God how?
O projeto é dividido em duas partes:
- Uma app REST rodando na máquina, que dá um alt + tab ao receber uma request de alerta.
- O ESP32 com um sensor ultrassônico, posicionado em qualquer lugar da casa, na mesma rede wifi do computador onde está a API. O ESP emite a request de alerta quando o sensor detecta presença.
