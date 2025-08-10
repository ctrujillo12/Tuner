// Analyze raw audio samples to extract useful information (e.g., pitch/frequency).
#include "esp_dsp.h"
#include "esp_err.h"
#include <stdio.h>

void dsp_init(void)
{
    // Initialize FFT tables for up to 1024-point FFT
    esp_err_t ret = dsps_fft2r_init_fc32(NULL, 1024);
    if (ret != ESP_OK) {
        printf("DSP FFT init failed: %d\n", ret);
    } else {
        printf("DSP FFT initialized successfully\n");
    }
}
