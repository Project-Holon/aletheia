/*
 * function: WIPE_SUB_SetWindowInside
 * address:  0x02023B74
 * packet:   pkt_02023B74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merge bits into one of the two DS display-control halfwords.  a2 picks the
 * register bank (0x04000048 or the 0x04001048 engine-2 twin), a3 picks which
 * six-bit field: the low one (mask ~0x3f, source bit 0, extra bit 0x20) or
 * the middle one (mask ~0x3f00, source aligned to bit 8, extra bit 0x2000).
 * Both registers are read-modify-written as volatile halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_SetWindowInside.c \
 *       --func WIPE_SUB_SetWindowInside --addr 0x02023B74 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void WIPE_SUB_SetWindowInside(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (a2 == 0) {
        if (a3 == 0) {
            u32 v = *(volatile u16 *)0x04000048;

            v = (v & ~0x3f) | a0;
            if (a1 != 0) {
                v |= 0x20;
            }
            *(volatile u16 *)0x04000048 = v;
        } else {
            u32 v = *(volatile u16 *)0x04001048;

            v = (v & ~0x3f) | a0;
            if (a1 != 0) {
                v |= 0x20;
            }
            *(volatile u16 *)0x04001048 = v;
        }
    } else {
        if (a3 == 0) {
            u32 v = *(volatile u16 *)0x04000048;

            v = (v & ~0x3f00) | (a0 << 8);
            if (a1 != 0) {
                v |= 0x2000;
            }
            *(volatile u16 *)0x04000048 = v;
        } else {
            u32 v = *(volatile u16 *)0x04001048;

            v = (v & ~0x3f00) | (a0 << 8);
            if (a1 != 0) {
                v |= 0x2000;
            }
            *(volatile u16 *)0x04001048 = v;
        }
    }
}
