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
#include <stdbool.h>
#include <stdlib.h>

#include "rms.h"

float rms_from_samples_f32(int nb_samples, float *samples, bool no_offset)
{
    assert(nb_samples > 0);
    assert(samples);

    float avg = 0.0f;

    if (no_offset == true)
    {
        for (size_t i = 0; i < nb_samples; i++)
        {
            avg += samples[i];
        }

        avg /= nb_samples;
    }

    float rms = 0.0f;

    for (size_t i = 0; i < nb_samples; i++)
    {
        rms += powf((samples[i] - avg), 2.0f);
    }

    rms /= nb_samples;
    rms = sqrtf(rms);

    return rms;
}

float rms_from_samples_interpolated_f32(int nb_samples, float *samples,
                                        float frequency, float sample_rate,
                                        bool no_offset)
{
    assert(nb_samples > 0);
    assert(samples);
    assert(frequency > 0);
    assert(sample_rate > 0);

    const float samples_per_cycle = (sample_rate / frequency);
    const int total_cycles = (int)(nb_samples / samples_per_cycle);

    if (total_cycles <= 0)
    {
        return 0.0f; // minimal samples for 1 cycle needed
    }

    float avg = 0.0f;

    if (no_offset == true)
    {
        for (size_t i = 0; i < nb_samples; i++)
        {
            avg += samples[i];
        }

        avg /= nb_samples;
    }

    float cycles_integer_part = 0.0f;
    float cycles_fractional_part = modff((total_cycles * samples_per_cycle),
                                         &cycles_integer_part);

    float period_adjustment;
    period_adjustment = ((1.0f - cycles_fractional_part) / 2.0f) * samples[nb_samples - 2];
    period_adjustment += ((1.0f + cycles_fractional_part) / 2.0f) * samples[nb_samples - 1];
    period_adjustment -= avg;
    period_adjustment = powf(period_adjustment, 2.0f);
    period_adjustment *= cycles_fractional_part;

    float rms = 0.0f;

    for (size_t i = 0; i < (nb_samples - 1); i++)
    {
        rms += powf((samples[i] - avg), 2.f);
    }

    rms += period_adjustment;
    rms /= (cycles_integer_part + cycles_fractional_part);
    rms = sqrtf(rms);

    return rms;
}