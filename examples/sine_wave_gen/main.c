/*
 * MIT License
 *
 * Copyright (c) 2022 Weslley Duarte
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// gcc ../../algorithms/sine_wave_gen/sine_wave_gen.c -Wall ./main.c -o ./main -lm

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../algorithms/sine_wave_gen/sine_wave_gen.h"

int main(int argc, char *argv[])
{
    // int nb_samples = 33;
    // float sample_rate = 2000.0f;
    // float amplitude = 100.0f;
    // float frequency = 60.0f;
    // float theta = 0.0f;
    // float output[nb_samples];
    // float dc_offset = 0.0f;

    // sine_wave_gen_f32(nb_samples, sample_rate, amplitude, frequency, theta,
    //                   output, dc_offset);

    // for (size_t i = 0; i < nb_samples; i++)
    // {
    //     printf("%f\n", output[i]);
    // }

    // int nb_samples = 33;
    // float sample_rate = 2000.0f;
    // float amplitude = 100.0f;
    // float frequency = 60.0f;
    // float theta = 0.0f;
    // int16_t output[nb_samples];
    // int16_t dc_offset = 0;

    // sine_wave_gen_i16(nb_samples, sample_rate, amplitude, frequency, theta,
    //                   output, dc_offset);

    // for (size_t i = 0; i < nb_samples; i++)
    // {
    //     printf("%d\n", output[i]);
    // }

    int nb_samples = 33;
    float sample_rate = 2000.0f;
    float amplitude = 100.0f;
    float frequency = 60.0f;
    float theta = 0.0f;
    float output[nb_samples];
    int nb_harmonics = 10;
    float harmonics[] = {
        0.0f,   // DC component
        100.0f, // fundamental
        0.0f,   // % of 2nd harmonic
        0.0f,   // % of 3td harmonic
        0.0f,   // % of 4th harmonic
        0.0f,   // % of 5th harmonic
        0.0f,   // % of 6th harmonic
        0.0f,   // % of 7th harmonic
        0.0f,   // % of 8th harmonic
        0.0f,   // % of 9th harmonic
    };

    sine_wave_gen_f32_harmonics(nb_samples, sample_rate, amplitude, frequency,
                                theta, output, harmonics, nb_harmonics);

    for (size_t i = 0; i < nb_samples; i++)
    {
        printf("%f\n", output[i]);
    }

    return 0;
}
