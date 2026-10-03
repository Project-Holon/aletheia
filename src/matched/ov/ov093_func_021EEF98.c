/*
 * function: func_021EEF98
 * address:  0x021EEF98
 * packet:   pkt_ov093_021EEF98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045A90  0x02045A90  arm
 *   func_021EEF20  0x021EEF20  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct U16Vec;
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 *func_021EEF20(u16 *p, u32 *o1, u16 *o2, u8 *o3);

u8 func_021EEF98(void *s)
{
    u32 o1;
    u16 o2;
    u8 o3;
    u16 *p;
    u8 n;

    p = func_02045A90(s);
    n = 0;
    if (p != 0) {
        do {
            p = func_021EEF20(p, &o1, &o2, &o3);
            if (p != 0 && o1 == 1) {
                if (o2 == 1 || o2 == 2 || o2 == 12)
                    n = n + 1;
            }
        } while (p != 0);
    }
    return n;
}
