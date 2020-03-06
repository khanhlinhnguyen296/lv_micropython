#if MICROPY_HW_CLK_USE_HSI
// (M, P/2-1, SYS) values for 16 MHz source
static const uint16_t pll_freq_table[21] = {
    (0 << 10) | (0 << 8) | 16,
    (16 << 10) | (3 << 8) | 24,
    (13 << 10) | (3 << 8) | 30,
    (16 << 10) | (2 << 8) | 32,
    (11 << 10) | (3 << 8) | 36,
    (13 << 10) | (2 << 8) | 40,
    (10 << 10) | (3 << 8) | 42,
    (16 << 10) | (1 << 8) | 48,
    (8 << 10) | (3 << 8) | 54,
    (10 << 10) | (2 << 8) | 56,
    (13 << 10) | (1 << 8) | 60,
    (8 << 10) | (2 << 8) | 64,
    (11 << 10) | (1 << 8) | 72,
    (10 << 10) | (1 << 8) | 84,
    (16 << 10) | (0 << 8) | 96,
    (8 << 10) | (1 << 8) | 108,
    (13 << 10) | (0 << 8) | 120,
    (11 << 10) | (0 << 8) | 144,
    (10 << 10) | (0 << 8) | 168,
    (8 << 10) | (0 << 8) | 192,
    (8 << 10) | (0 << 8) | 216,
};
#else
// (M, P/2-1, SYS) values for 16 MHz source
static const uint16_t pll_freq_table[22] = {
    (0 << 10) | (0 << 8) | 16,
    (1 << 10) | (0 << 8) | 16,
    (16 << 10) | (3 << 8) | 24,
    (13 << 10) | (3 << 8) | 30,
    (16 << 10) | (2 << 8) | 32,
    (11 << 10) | (3 << 8) | 36,
    (13 << 10) | (2 << 8) | 40,
    (10 << 10) | (3 << 8) | 42,
    (16 << 10) | (1 << 8) | 48,
    (8 << 10) | (3 << 8) | 54,
    (10 << 10) | (2 << 8) | 56,
    (13 << 10) | (1 << 8) | 60,
    (8 << 10) | (2 << 8) | 64,
    (11 << 10) | (1 << 8) | 72,
    (10 << 10) | (1 << 8) | 84,
    (16 << 10) | (0 << 8) | 96,
    (8 << 10) | (1 << 8) | 108,
    (13 << 10) | (0 << 8) | 120,
    (11 << 10) | (0 << 8) | 144,
    (10 << 10) | (0 << 8) | 168,
    (8 << 10) | (0 << 8) | 192,
    (8 << 10) | (0 << 8) | 216,
};
#endif
