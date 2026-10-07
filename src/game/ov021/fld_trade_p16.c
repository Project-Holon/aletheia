/*
 * file:     fld_trade_p16.c
 * unit:     yes
 * function: func_021CE984, func_021CE9A0
 * address:  0x021CE984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02190794  0x02190794  thumb  ov021
 *   func_021CE934  0x021CE934  thumb  ov021
 */
struct Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02190794(struct Slot **p, int x, int y, int w, int h);
extern void func_021CE934(u8 *p, u8 *q, u32 c);
void func_021CE984(u32 *p, u32 n);
void func_021CE9A0(u8 *p);


void func_021CE984(u32 *p, u32 n)
{
    if (p[3] != 0) {
        func_02190794((struct Slot **)p[3], 0, n << 4, 0x90, 0x10);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021CE9A0(u8 *p)
{
    int i;

    if (p[0x518] != 0) {
        p[0x518] = 0;
        for (i = 0; i < 4; i++) {
            func_021CE984((u32 *)p, i);
            if (p[0x514] & (1 << i))
                func_021CE934(p, p + 0x494 + i * 32, (u8)i);
        }
    }
}
