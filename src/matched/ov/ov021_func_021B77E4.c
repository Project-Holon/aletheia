/*
 * function: func_021B77E4
 * address:  0x021B77E4
 * packet:   pkt_ov021_021B77E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A104  0x0200A104  thumb
 *   func_0200A000  0x0200A000  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

struct Ent { u8 pad00[0xB3]; u8 fB3; };

typedef unsigned int   u32;
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A104(char *p, unsigned int idx);
extern int func_0200A000(char *p, int idx, void *buf);

struct Ent *func_021B77E4(void *a, void *b, struct Ent *c)
{
    u8 v;

    if (func_0200A0E4(a, (u32)b) == 0)
        return 0;
    if (func_0200A104(a, (unsigned int)b) == 1)
        return 0;
    if (func_0200A000(a, (int)b, c) == 0)
        return 0;
    v = c->fB3;
    if (v == 0)
        return 0;
    if (v > 3)
        c = 0;
    return c;
}
