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

// gcc ../../algorithms/sine_wave_gen/sine_wave_gen.c ../../algorithms/measurements/rms.c -Wall ./main.c -o ./main -lm

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../algorithms/sine_wave_gen/sine_wave_gen.h"
#include "../../algorithms/measurements/rms.h"

int main(int argc, char *argv[])
{
    int nb_samples = 33;
    float sample_rate = 2000.0f;
    float A = 100.0f;
    float f = 60.0f;
    float theta = 0.0f;
    float output[400];
    float dc_offset = 0.0f;

    sine_wave_gen_f32(nb_samples, sample_rate, A, f, theta, output, dc_offset);

    float rms_measured = 0.0f;
    float rms_expected = (A * (sqrt(2.0f) / 2.0f));

    rms_measured = rms_from_samples_f32(nb_samples, output);

    printf("rms1: %f error: %f%%\n", rms_measured, (((rms_measured - rms_expected) / rms_expected) * 100.0f));

    /* When using the interpolated method, we need +1 sample */
    nb_samples += 1;

    sine_wave_gen_f32(nb_samples, sample_rate, A, f, theta, output, dc_offset);

    rms_measured = rms_from_samples_interpolated_f32(nb_samples, output, f, sample_rate);

    printf("rms2: %f error: %f%%\n", rms_measured, (((rms_measured - rms_expected) / rms_expected) * 100.0f));

    return 0;
}
