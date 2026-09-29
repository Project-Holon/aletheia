/*
 * unit:     yes
 * function: func_021BC628, func_021BC6A0, func_021BC6C0
 * address:  0x021BC628
 * packet:   pkt_ov091_021BC628
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BC1D0  0x021BC1D0  thumb  ov091
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_021BB050  0x021BB050  thumb  ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BC350  0x021BC350  thumb  ov091
 *   func_021BE2B4  0x021BE2B4  thumb  ov091
 *   func_021BB2C0  0x021BB2C0  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BBA70  0x021BBA70  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021BC1D0(int);
extern void func_021BB7A4(int, int);
extern void func_021BB050(int, int, int);
extern int func_0201AB28(int, int);
extern void func_021BC350(int, int);
extern void func_021BE2B4(int, int, int, int, int);
extern void func_021BB2C0(int, int);
extern void func_020061E4(int);
extern void func_021BBA70(int, int);

void func_021BC628(int p)
{
    int n = func_021BC1D0(p);
    func_021BB7A4(p, *(int *)(p + 0x150));
    func_021BB050(p, *(int *)(p + *(int *)(p + 0x2c) * 4 + 0x160), 3);
    *(int *)(p + 0x2c) = n;
    *(int *)(p + 0x38) = func_0201AB28(**(int **)(p + 0x280), n);
    func_021BC350(p, 0);
    func_021BE2B4(*(int *)(p + 0x38),
                  *(u16 *)(*(int *)(p + 0x280) + 0x44), 0,
                  *(u16 *)(*(int *)(p + 0x280) + 0x30), *(u16 *)p);
    func_021BB2C0(p, *(int *)(p + *(int *)(p + 0x2c) * 4 + 0x160));
    func_020061E4(0x56f);
}

void func_021BC6A0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 0;
    *(int *)(*(int *)(p + 0x280) + 0x50) = 0;
    func_021BBA70((int)p, *(int *)(p + 0x150));
}

void func_021BC6C0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 6;
}
