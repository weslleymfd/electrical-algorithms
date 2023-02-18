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

#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>

#include "sine_wave_gen.h"

void sine_wave_gen_f32(int nb_samples, float sample_rate, float amplitude,
                       float frequency, float theta, float *output, float offset)
{
    assert(nb_samples > 0);
    assert(sample_rate > 0);
    assert(output);

    const float angular_frequency = (2.0f * M_PI * frequency);
    const float sample_period = (1.0f / sample_rate);

    for (size_t i = 0; i < nb_samples; i++)
    {
        output[i] = ((amplitude * sinf(angular_frequency * (i * sample_period) + theta)) + offset);
    }
}

void sine_wave_gen_i16(int nb_samples, float sample_rate, float amplitude,
                       float frequency, float theta, int16_t *output, int16_t offset)
{
    assert(nb_samples > 0);
    assert(sample_rate > 0);
    assert(output);

    const float w = (2.f * M_PI * frequency);
    const float sample_period = (1.0f / sample_rate);

    for (size_t i = 0; i < nb_samples; i++)
    {
        output[i] = ((int16_t)(amplitude * sinf(w * (i * sample_period) + theta)) + offset);
    }
}