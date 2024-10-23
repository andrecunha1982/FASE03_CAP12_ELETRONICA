# Capítulo 12 - A Eletrônica de uma IA
O objetivo deste projeto é criar um sistema inteligente de monitoramento agrícola usando o microcontrolador ESP32 e quatro sensores diferentes simulado no [Wokwi.com](wokwi.com).

O sistema será capaz de coletar dados do ambiente e tomar decisões automatizadas para otimizar o uso de recursos na agricultura, como a irrigação e o controle de condições climáticas.

## Funcionalidades:

1. Monitoramento climático: com o DHT22, o sistema mede constantemente a umidade e temperatura do ambiente, enviando alertas ou tomando ações automáticas para aumentar ou diminuir a irrigação dependendo das condições.

2. Controle de irrigação automatizada: o sensor HC-SR04 verifica o nível de água nos tanques e aciona a irrigação apenas quando o nível está adequado, evitando desperdício de água.

3. Detecção de presença: o sensor PIR pode ser utilizado para detectar invasões de animais ou pessoas em áreas restritas da fazenda, ativando alarmes ou sistemas de segurança.

4. Ajuste de irrigação com base na luminosidade: o sensor LDR mede a quantidade de luz solar recebida e ajusta a irrigação automaticamente, diminuindo a quantidade de água em dias mais ensolarados e aumentando em dias nublados.

## Building
Este é um projeto baseado no [PlatformIO](https://platformio.org/) e no [Wokwi.com](wokwi.com). 

Para execução via VS Code deve-se instalar no VS Code:
1. [Wokwi for VS Code](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode);
2. [PlatformIO](https://docs.platformio.org/en/latest/core/installation/index.html);
3. Executar o seguinte comando no Terminal:
```
pio run
```
4. Abrir o aquivo diagram.json e clicar em "Start Simulation"
   
![image](https://github.com/user-attachments/assets/90a7c46c-1f1e-4d73-b502-ebf1f07c462c)


![image](https://github.com/user-attachments/assets/40418769-7686-4910-8561-d9dd0ac018e1)
