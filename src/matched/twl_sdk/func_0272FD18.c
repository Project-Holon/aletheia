/*
 * function: MI_StopAllNDma
 * address:  0x0272FD18
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MI_StopNDma 0x0272FCE0 arm twl
 */

void MI_StopNDma(int);

void MI_StopAllNDma(void) {
    MI_StopNDma(0);
    MI_StopNDma(1);
    MI_StopNDma(2);
    MI_StopNDma(3);
}
