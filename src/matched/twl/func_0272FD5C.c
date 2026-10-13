/*
 * function: MI_SetNDmaArbitrament
 * address:  0x0272FD5C
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void MI_SetNDmaArbitrament(unsigned int a0, unsigned int a1) {
    if (a0 == 0x80000000) {
        *(volatile unsigned int *)0x04004100 = a1 | 0x80000000;
    } else {
        *(volatile unsigned int *)0x04004100 = 0;
    }
}
