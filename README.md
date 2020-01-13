# motion-event-project
Repositório de um micro-projeto utilizando ESP-32 e um servidor em Flask (python), onde o ESP emite um sinal ao detectar movimentos, e este sinal aciona um atalho no computador que está rodando o servidor (um alt + tab, por exemplo)

## Oh God why?
A idéia deste projeto veio [deste](https://www.tindie.com/products/dekuNukem/daytripper-hide-my-windows-laser-tripwire/) produto aleatório com a mesma proposta, cuja propaganda apareceu no meu feed em uma dia qualquer. Achei o produto interessante e resolvi replicar, porém, com os materiais que eu tinha em casa.

Ele detecta movimento no local que o sensor estiver sido posicionado. Ao detectar, ele envia uma request para o seu pc, minimizando assim, a janela que você estiver vendo aqueles vídeos daquelas pobres meninas sem roupas, ou aquele minecraft que você vergonhosamente ainda joga na sua sala escondido do seu chefe.

![funcionamento do produto](https://github.com/Doc-McCoy/motion-event-project/blob/master/screenshots/example.gif)

## Oh God how?
O projeto é dividido em duas partes:
- Uma API rodando na máquina, que utiliza o pyautogui para dar um comando específico (no caso, um "alt+tab") ao receber uma request de alerta.
- O ESP32 com um sensor de presença, posicionado em qualquer lugar da casa, na mesma rede wifi do computador onde está a API. O ESP32 emite a request para a API quando o sensor detecta presença.

![projeto finalizado](https://github.com/Doc-McCoy/motion-event-project/blob/master/screenshots/esp.jpg)

## Oh God give me pieces!
Para fazer este projeto, você precisará dos seguintes materiais:
- Placa ESP32 ou equivalente
- Sensor de movimento/presença PIR
- Fonte de 5v para o PIR (pois o ESP32 só fornece 3.3v)
- Protoboard
- Fios

## Oh God give me steps!
- Clone o projeto, óbvio
- Abra o arquivo `src/client/client-esp32.ino` com sua **IDE Arduino**
- Adicione o nome e senha da sua rede WIFI nas linhas indicadas
- Adicione o IP do seu PC na linha indicada (se vc não sabe ver seu IP, o comando é `ipconfig` para windows, e `ifconfig` para linux)
- Carregue o código para o seu ESP32
- Ligue o ESP32 ao sensor PIR, conecte o fio de *signal* do PIR ao pino 15 do ESP32
- Feche a IDE Arduino, abra o projeto no seu editor de códigos favorito
- Inicialize um ambiente virtual: `python -m venv .venv `
- Ative seu ambiente virtual `.venv\Scripts\activate` para windows ou `source .venv/bin/activate` para linux
- Instale as pedendências do projeto `pip install -r requirements.txt`
- Ligue seu ESP32 a uma fonte de energia, e aguarde alguns segundos para que o sensor seja calibrado automaticamente
- Suba o servidor com `python src\run.py`
- Pronto! Toda vez que o ESP detectar um movimento, dará `alt + tab` na tela.
