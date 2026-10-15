/*
 * function: G3_LoadMtx44
 * address:  0x0207D8C4
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_SendFifo64B   0x02080CA8  arm
 *
 * Original (28 bytes):
 *   ldr r1, [pc, #0xc]   ; 0x04000400
 *   mov r2, #0x16
 *   ldr ip, [pc, #8]     ; 0x02080CA8
 *   str r2, [r1]
 *   bx  ip
 */

extern void GX_SendFifo64B(const void *src);

void G3_LoadMtx44(const void *m)
{
    *(volatile unsigned int *)0x04000400 = 0x16;
    GX_SendFifo64B(m);
}
