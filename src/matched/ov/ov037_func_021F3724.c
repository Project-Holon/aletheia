/*
 * function: func_021F3724
 * address:  0x021F3724
 * packet:   pkt_ov037_021F3724
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern unsigned char *func_0200B3A4(unsigned int, unsigned int);

void func_021F3724(unsigned int a0, int a1)
{
    unsigned char *p = func_0200B3A4((unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)a0)), 4);
    unsigned char i;

    for (i = 0; i < 3; i++)
        p[i] = 0;
    if (a1 & 1)
        p[0] = 1;
    if ((a1 >> 1) & 1)
        p[1] = 1;
    if ((a1 >> 2) & 1)
        p[2] = 1;
}
