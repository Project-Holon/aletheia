/*
 * function: func_0689B0D4
 * address:  0x0689B0D4
 * packet:   pkt_ov095_0689B0D4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689B354  0x0689B354  thumb  ov095
 *   func_0689B174  0x0689B174  thumb  ov095
 *   func_0689B184  0x0689B184  thumb  ov095
 *   func_0689B194  0x0689B194  thumb  ov095
 *   func_0689B1A4  0x0689B1A4  thumb  ov095
 *   func_0689B1B4  0x0689B1B4  thumb  ov095
 *   func_0689B098  0x0689B098  thumb  ov095
 *   func_0689B1C4  0x0689B1C4  thumb  ov095
 *   func_0689B1D4  0x0689B1D4  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 pad : 7;
    u32 id : 16;
    u32 rest : 9;
} Q;

extern void func_0689B354(u8 *p);
extern int func_0689B174(u32 a);
extern u32 func_0689B184(u32 a);
extern void func_0689B194(u32 a, u32 b, u32 c);
extern u8 *func_0689B1A4(void);
extern void func_0689B1B4(Q *q, u16 id, u8 c);
extern void func_0689B098(u8 *p, u8 *s);
extern u8 func_0689B1C4(u16 id, int k);
extern u8 func_0689B1D4(u32 a);

int func_0689B0D4(int unused, u8 *s)
{
    u8 c;

    func_0689B354(s + 0x80);
    if (func_0689B174(*(u32 *)(s + 0xa0)) == 2) {
        c = 6;
        if (s[0x80] != 0) {
            func_0689B194(*(u32 *)(s + 0xa0), *(u32 *)(s + 0xa4),
                          func_0689B184(*(u32 *)(s + 0x6c)));
            c = func_0689B1A4()[4];
        }
        func_0689B1B4(*(Q **)(s + 0x70), (*(Q **)(s + 0x70))->id, c);
        s[0x89] = 1;
    }
    func_0689B098(s + 0x80, s);
    s[0x89] = 0;
    s[0x8a] = func_0689B1C4((*(Q **)(s + 0x70))->id, 0x1b);
    if ((*(Q **)(s + 0x70))->id == 0xae)
        s[0x8a] = func_0689B1D4(*(u32 *)(s + 0x6c));
    return 1;
}
