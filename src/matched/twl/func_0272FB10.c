/*
 * function: MI_InitNDma
 * address:  0x0272FB10
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MI_SetNDmaArbitrament 0x0272FD5C arm twl
 *   MI_InitNDmaConfig 0x0272FD7C arm twl
 */

void MI_SetNDmaArbitrament(unsigned int, unsigned int);
void MI_InitNDmaConfig(void);

void MI_InitNDma(void) {
    MI_SetNDmaArbitrament(0x80000000, 0x60000);
    MI_InitNDmaConfig();
}
