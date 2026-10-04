/*
 * function: func_021D01D8
 * address:  0x021D01D8
 * packet:   pkt_ov021_021D01D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Rec;
struct Tagged;
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);

void func_021D01D8(u32 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (p[1 + i] != 0) {
            func_02047504((struct Rec *)p[13 + i]);
            func_020470D0((u32 *)p[1 + i]);
            func_02046EFC((struct Tagged *)p[1 + i]);
        }
    }
    for (i = 0; i < 4; i++) {
        if (p[9 + i] != 0) {
            func_02046EFC((struct Tagged *)p[9 + i]);
        }
    }
}
