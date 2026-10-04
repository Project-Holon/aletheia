/*
 * function: func_021DB650
 * address:  0x021DB650
 * packet:   pkt_ov093_021DB650
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D70AC  0x021D70AC  thumb  ov093
 *   d_021F0B78     0x021F0B78  data   a2
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern unsigned char func_021D70AC(unsigned char *p);
extern const u16 d_021F0B78[];

int func_021DB650(int a, int b, int c, int d, int e, u8 g)
{
    u32 i;

    if (func_021D62C4(func_021C7CF4((int *)b, g), 0x10) != 0)
        return 0;
    if (c == 5 && g == func_021D70AC((unsigned char *)a)) {
        for (i = 0; i < 13; i++) {
            if (e == d_021F0B78[i])
                return 0;
        }
        return 1;
    }
    return 0;
}
