<h1 align="center">♻️BioVolt- Gerador de energia a partir de biomassa⚡</h1>

<h2 align="center"> BioVolt - Energia limpa, rios vivos: juntos por um futuro sustentável.</h2>
<br>

## Visão Geral
Projeto de sistema de geradores de energia movidos a biomassa, que a partir de resíduos orgânicos retirados de locais de fluxo d’água poluídos,
junto a um programa de incentivo a separação correta de material orgânico, com o uso de filtros para reduzir as emissões de gases nocivos, 
como CO₂, oferece uma solução sustentável de geração de energia que será destinada para empresas, para o setor de agronegócio.

## Gerador de Energia a Biomassa com Arduino
Este projeto simula o funcionamento de um gerador de energia a biomassa utilizando um Arduino Uno R3. 
O sistema monitora a temperatura e os níveis de gás do ambiente, ajustando automaticamente a velocidade de um motor CC e alertando o usuário sobre situações críticas.

## Componentes
- Arduino Uno R3
- Protoboard
- LCD I2C 16x2
- 3 LEDs (verde, amarelo, vermelho)
- 3 resistores de 100Ω (1 por LED) 
- Sensor de gás MQ-135 com resistor de 4.7kΩ
- Sensor de temperatura TMP-36
- Motor CC controlado por transistor PNP
- Resistor de 10kΩ para o transistor
- Buzzer com resistor de 1kΩ
- Interruptor deslizante
- Bateria de 9V
- Jumpers e cabos

## Montagem do Circuito
1. Conecte os LEDs verde, amarelo e vermelho aos pinos digitais 13, 12 e 11 do Arduino, respectivamente, cada um com um resistor de 100Ω.
2. Conecte o motor CC à bateria de 9V e controle-o com o transistor PNP ligado ao pino 10 do Arduino. Use um resistor de 10kΩ na base do transistor.
3. Conecte o sensor de gás MQ-135 ao pino analógico A0 e o resistor de 4.7kΩ.
4. Conecte o sensor de temperatura TMP-36 ao pino analógico A2.
5. Conecte os pinos SDA e SCL do LCD I2C aos pinos A4 e A5 do Arduino.
6. Conecte o buzzer ao pino 9 com um resistor de 1kΩ.
7. Utilize o interruptor deslizante para controlar a alimentação geral do sistema.
8. Monte o circuito na protoboard para manter as conexões organizadas.

## Funcionamento do Código
1. **Inicialização**: O sistema inicia exibindo mensagens no LCD e configurando os pinos.
2. **Leitura de Sensores**: 
   - Temperatura: Monitorada pelo sensor TMP-36 (pino A2).
   - Nível de gás: Monitorado pelo sensor MQ-135 (pino A0).
3. **Controle do Motor**:
   - A velocidade do motor varia de acordo com o nível de gás:
     - Baixo gás: Velocidade mínima.
     - Gás normal: Velocidade proporcional.
     - Gás alto: Velocidade máxima.
4. **Alertas**:
   - Temperatura alta: Desliga o gerador e emite um alerta sonoro.
   - Gás baixo: Acende o LED verde e reduz a velocidade.
   - Gás moderado: Acende o LED amarelo.
   - Gás alto: Acende o LED vermelho e ajusta a velocidade.
5. **LCD**:
   - Exibe a temperatura, nível de gás e velocidade do motor.
6. **Interruptor**:
   - Liga/desliga manualmente o gerador.

## Indicadores
- LED Verde: Operação normal.
- LED Amarelo: Atenção, gás em nível moderado.
- LED Vermelho: Alerta crítico.
- Buzzer: Soa em situações de alerta, como temperatura alta.

## Como Usar
1. Monte o circuito conforme o esquema.
2. Faça o upload do código no Arduino.
3. Ligue o sistema com o interruptor deslizante.
4. Monitore o LCD para informações em tempo real.
5. Ajuste os limites de temperatura e gás no código conforme necessário:
   - `limiteGas`: Nível máximo de gás permitido (padrão: 700).
   - `limiteTemperatura`: Temperatura máxima permitida (padrão: 100 °C).

## Arquivos
- Código Fonte: `gerador_biomassa.ino`
- Esquema do Circuito: Consulte a imagem anexada.

## Aplicações e Expansões
Este projeto é uma simulação funcional de um gerador de energia sustentável. Ele pode ser expandido para:
- Incorporar um sistema de monitoramento remoto.
- Usar sensores adicionais para monitorar outros fatores ambientais.
- Implementar uma interface gráfica para visualização dos dados.

## Link Tinkercad
https://www.tinkercad.com/things/74niww5IdBQ-global-solution-edge

## Colaboradores do projeto
- Lucas Alves Piereti - RM559533
- Rafaela Heer Robinson - RM560249
- Julia Hadja Kfouri Nunes - RM559410
