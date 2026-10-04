/*
 * function: func_021D0328
 * address:  0x021D0328
 * packet:   pkt_ov021_021D0328
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020478B8  0x020478B8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct St021D0328 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u32 f4;
    u32 f8;
    u32 fC;
} St021D0328;

extern int func_020478B8(void *a, int idx, int amount);

void func_021D0328(void *unused, St021D0328 *p)
{
    if (p->f2 != 4) {
        p->f3 = 0;
        if (func_020478B8((void *)p->fC, p->f2, 0x1000) == 0) {
            p->f3 = 1;
        }
    }
}
