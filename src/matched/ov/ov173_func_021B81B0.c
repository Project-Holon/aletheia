/*
 * function: POKE_SUMMARY_ACTOR_SetSubBrightness
 * address:  0x021B81B0
 * packet:   pkt_021B81B0
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0207D658  0x0207D658  arm
 */

typedef unsigned int   u32;
extern void func_0207D658(u32 addr, int plane, int brightness);

void POKE_SUMMARY_ACTOR_SetSubBrightness(int a)
{
    volatile unsigned short *p = (volatile unsigned short *)0x04001050;

    if (a == 1) {
        func_0207D658((u32)p, 0x1e, -8);
    } else {
        *p = 0;
    }
}
