/*
 * function: func_021BD318
 * address:  0x021BD318
 * packet:   pkt_ov099_021BD318
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0201A918  0x0201A918  thumb
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern int func_0203D378(void);
extern int func_020399A8(void);
extern u32 func_0201A918(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);

int func_021BD318(char *p, int v)
{
    int t;
    u32 h;

    t = 0;
    if (func_0203D378() == 0) {
        t = 1;
    }
    h = func_020399A8();
    if (func_0203D3F8(h, 0xFF, 0xA07, func_0201A918(),
                      *(u32 *)(*(char **)(p + 0x248) + t * 4 + 0x14), 0, 0, 1) != 0) {
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        *(u32 *)(p + 0x1CC) = 0x98;
    }
    return v;
}
