/*
 * function: func_021D6D6C
 * address:  0x021D6D6C
 * packet:   pkt_021D6D6C
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);

int func_021D6D6C(void **p, int x)
{
    return PARTICLE_StartEffectWithCallback(*p, x, 0, (int)p);
}
