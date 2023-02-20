/*
 * MIT License
 *
 * Copyright (c) 2022 - 2023 Weslley Duarte
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

#ifndef SINE_WAVE_GEN_H_
#define SINE_WAVE_GEN_H_

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Sine wave generator f32
     *
     * @param nb_samples    Number of samples to generate
     * @param sample_rate   Sample rate ... samples per second
     * @param amplitude     Amplitude of the signal
     * @param frequency     Frequency in Hertz
     * @param theta         Lag in degrees
     * @param output        Output array
     * @param offset        DC offset
     */
    void sine_wave_gen_f32(int nb_samples, float sample_rate, float amplitude,
                           float frequency, float theta, float *output, float offset);

    /**
     * @brief Sine wave generator f32 with harmonics
     *
     * @param nb_samples    Number of samples to generate
     * @param sample_rate   Sample rate ... samples per second
     * @param amplitude     Amplitude of the signal
     * @param frequency     Frequency in Hertz
     * @param theta         Lag in degrees
     * @param output        Output array
     * @param harmonics     Array with harmonics percentages
     * @param nb_harmonics  Number of harmonics (including DC and fundamental)
     */
    void sine_wave_gen_f32_harmonics(int nb_samples, float sample_rate, float amplitude,
                                     float frequency, float theta, float *output,
                                     float *harmonics, int nb_harmonics);

    /**
     * @brief Sine wave generator u16
     *
     * @param nb_samples    Number of samples to generate
     * @param sample_rate   Sample rate ... samples per second
     * @param amplitude     Amplitude of the signal
     * @param frequency     Frequency in Hertz
     * @param theta         Lag in degrees
     * @param output        Output array
     * @param offset        DC offset
     */
    void sine_wave_gen_i16(int nb_samples, float sample_rate, float amplitude,
                           float frequency, float theta, int16_t *output, int16_t offset);

#ifdef __cplusplus
}
#endif

#endif // SINE_WAVE_GEN_H_