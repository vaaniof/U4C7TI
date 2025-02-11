#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Define o pino do servo motor que será utilizado
#define SERVO_PIN 22

// Define o valor de envolvimento (wrap) para o PWM, que é usado para configurar a frequência do sinal PWM
#define WRAP_VALUE 25000

// Define os valores de pulso para ângulos específicos do servo motor (180°, 90° e 0°)
#define PULSO_ANGULO_180 1920 
#define PULSO_ANGULO_90 1190 
#define PULSO_ANGULO_0 400 

// Define o tamanho do passo para o movimento suave do servo e o atraso em milissegundos entre cada passo
#define SMOOTH_MOVE_STEP 5
#define SMOOTH_MOVE_DELAY 10

// Função para definir o ângulo do servo motor através do valor de pulso
void set_servo_angle(uint gpio, uint16_t pulso){
    // Obtém o número do slice PWM associado ao pino GPIO do servo
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    // Calcula o nível do canal PWM com base no valor do pulso desejado
    uint16_t level = (pulso * WRAP_VALUE) / 20000;
    // Define o nível do canal PWM para o pino do servo
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), level);
}

// Função para inicializar todos os pinos necessários para o funcionamento do programa
void init_all_pins(){
    // Inicializa o sistema padrão de entrada/saída
    stdio_init_all();

    // Configura o pino do servo motor para funcionar como uma saída PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    // Obtém o número do slice PWM associado ao pino do servo
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Configura o valor de envolvimento (wrap) do slice PWM para o valor definido em WRAP_VALUE
    pwm_set_wrap(slice_num, WRAP_VALUE);
    // Define a frequência do sinal PWM para 50 Hz
    pwm_set_clkdiv(slice_num, 125.0f);
    // Habilita o slice PWM para que ele comece a gerar o sinal PWM no pino do servo
    pwm_set_enabled(slice_num, true);
}

// Função para mover o servo motor de forma suave entre dois ângulos
void move_smoothly(uint gpio, float pulso_inicial, float pulso_final, int step, int delay_ms){

    // Se o pulso inicial for menor que o pulso final, o servo se move de ângulos menores para maiores
    if (pulso_inicial < pulso_final) {
        for (uint16_t pulso = pulso_inicial; pulso <= pulso_final; pulso += step){
        
            // Define o ângulo do servo para o valor de pulso atual
            set_servo_angle(gpio, pulso);
            // Aguarda o tempo definido em delay_ms entre cada passo
            sleep_ms(delay_ms);
        }
    }
// Se o pulso inicial for maior que o pulso final, o servo se move de ângulos maiores para menores
    else {
        for (uint16_t pulso = pulso_inicial; pulso >= pulso_final; pulso -= step){

            // Define o ângulo do servo para o valor de pulso atual            
            set_servo_angle(gpio, pulso);
            // Aguarda o tempo definido em delay_ms entre cada passo
            sleep_ms(delay_ms);
        }
    }
}

// Função principal do programa
int main() {
    // Inicializa os pinos necessários
    init_all_pins();

    // Posiciona o servo motor no ângulo 0°
    set_servo_angle(SERVO_PIN, PULSO_ANGULO_0);
    sleep_ms(5000);

    // Posiciona o servo motor no ângulo 90°
    set_servo_angle(SERVO_PIN, PULSO_ANGULO_90);
    sleep_ms(5000);

    // Posiciona o servo motor no ângulo 180°
    set_servo_angle(SERVO_PIN, PULSO_ANGULO_180);
    sleep_ms(5000);

    while (true) {
        // Move o servo motor de 0° para 180°
        move_smoothly(SERVO_PIN, PULSO_ANGULO_180, PULSO_ANGULO_0, SMOOTH_MOVE_STEP, SMOOTH_MOVE_DELAY);
        // Move o servo motor de 180° para 0° 
        move_smoothly(SERVO_PIN, PULSO_ANGULO_0, PULSO_ANGULO_180, SMOOTH_MOVE_STEP, SMOOTH_MOVE_DELAY);
    }
}
