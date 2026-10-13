/*
 * function: MIi_Wait
 * address:  0x0272FD40
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MI_IsNDmaBusy 0x0272FC90 arm twl
 */

int MI_IsNDmaBusy(int);

static void MIi_Wait(int a0) {
    do {
    } while (MI_IsNDmaBusy(a0) == 1);
}
