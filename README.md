# Controle de Servomotor por PWM no Raspberry Pi Pico W

## Descrição do Projeto

Este projeto tem como objetivo simular o controle do ângulo de um servomotor utilizando o microcontrolador RP2040, presente no Raspberry Pi Pico W. A simulação é realizada no simulador de eletrônica online Wokwi, empregando a ferramenta Pico SDK para programar a geração do sinal PWM.

## Funcionamento do Projeto

1. **Configuração do PWM na GPIO 22:**
   - Frequência: Aproximadamente 50 Hz (período de 20 ms).
2. **Definição do ciclo ativo para 2.400µs:**
   - Ajusta o servomotor para a posição de ~180 graus.
   - Aguarda 5 segundos.
3. **Definição do ciclo ativo para 1.470µs:**
   - Ajusta o servomotor para a posição de ~90 graus.
   - Aguarda 5 segundos.
4. **Definição do ciclo ativo para 500µs:**
   - Ajusta o servomotor para a posição de ~0 graus.
   - Aguarda 5 segundos.
5. **Movimentação periódica entre 0 e 180 graus:**
   - Incremento do ciclo ativo de ±5µs com atraso de 10ms.
   - Movimentação suave.
6. **Experimento com LED RGB na GPIO 12 usando BitDogLab:**
   - Observar o comportamento do LED ao executar o código.

## Ferramentas Utilizadas

- **Ambiente de desenvolvimento:** Visual Studio Code (VS Code)
- **Linguagem de programação:** C (com Pico SDK)
- **Simulador:** Wokwi
- **Repositório para versionamento:** GitHub

## Instruções de Uso

### Configuração do Ambiente

1. Instale o [Pico SDK](https://github.com/raspberrypi/pico-sdk) no VS Code.
2. Clone este repositório:
   ```sh
   git clone https://github.com/vaaniof/U4C7TI.git
   ```
3. Compile o projeto e execute no simulador Wokwi.

### Execução do Código

1. Configure a GPIO 22 para gerar PWM a 50 Hz.
2. Ajuste os ciclos ativos conforme descrito nos requisitos.
3. Observe o movimento do servomotor e o comportamento do LED RGB na GPIO 12.

## Demonstração

O vídeo com a execução do projeto pode ser acessado no seguinte link:
[Vídeo da Simulação](https://drive.google.com/file/d/1uNHusDBApm6NKcIEGXJHEFp5-i4oUkpX)

---

**Autor: Vanio Ferreira dos Santos Júnior**

