# Capítulo 12 - A Eletrônica de uma IA
O objetivo deste projeto é criar um sistema inteligente de monitoramento agrícola usando o microcontrolador ESP32 e quatro sensores diferentes simulado no [Wokwi.com](wokwi.com).

O sistema será capaz de coletar dados do ambiente para tomada decisões automatizadas visando otimizar o uso de recursos na agricultura, como a irrigação e o controle de condições climáticas.

## Building
### Desenho do Circuito
![image](https://github.com/user-attachments/assets/f885aad5-6c1a-4068-bb46-514700606ae4)

## Papel de cada sensor no sistema:

1. Monitoramento climático: com o DHT22, o sistema mede constantemente a umidade e temperatura do ambiente, podendo enviar alertas ou tomando ações automáticas para aumentar ou diminuir a irrigação dependendo das condições.

2. Controle de irrigação automatizada: o sensor HC-SR04 verifica o nível de água nos tanques podendo acionar a irrigação apenas quando o nível está adequado, evitando desperdício de água.

3. Detecção de presença: o sensor PIR pode ser utilizado para detectar invasões de animais ou pessoas em áreas restritas da fazenda, ativando alarmes ou sistemas de segurança.

4. Ajuste de irrigação com base na luminosidade: o sensor LDR mede a quantidade de luz solar recebida e pode ajustar a irrigação automaticamente, diminuindo a quantidade de água em dias mais ensolarados e aumentando em dias nublados.

## Configuração e Execução do Projeto
Este é um projeto baseado no [PlatformIO](https://platformio.org/) e no [Wokwi.com](wokwi.com). 

Sugere-se a execução via VS Code, onde deve-se instalar dentro da IDE:
1. [Wokwi for VS Code](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode);
2. [PlatformIO](https://docs.platformio.org/en/latest/core/installation/index.html);
3. Copiar os arquivos de projeto para o repositorio local do VS Studio;
4. Executar o seguinte comando no Terminal do PlatformIO:
```
pio run
```
4. Abrir o aquivo diagram.json e clicar em "Start Simulation"

Outra opção mais simples seria a execução diretamente no portal da [Wokwi.com](wokwi.com). Basta copiar o arquivo projeto.ino dentro de src para a automação do ESP32 e o diagram.json para atualizar o desenho do circuito. Feito isso basta executar que o projeto será recompilado e os resultados apresentados no serial monitor.




