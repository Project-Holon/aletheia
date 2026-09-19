/*
 * function: func_02038924
 * address:  0x02038924
 * packet:   pkt_020385C4
 * status:   EXACT
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02039548  0x02039548  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02036428  0x02036428  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *lbl_021469D0;
extern int func_0203D798(void);
extern void func_0203D6BC(void);
extern int func_0203F1FC(u8 *p, s32 n);
extern void func_02039548(void);
extern u8 *func_0203CA98(void);
extern void func_0203C9AC(u32 a, u32 b, u32 c, u32 d);
extern void func_02036428(u8 *dst, u8 *src, s32 len);

int func_02038924(u32 a0, u8 *p, s32 n)
{
    u8 *g;
    u8 *q;
    u32 v;
    s32 len;
    int r;

    func_0203D798();
    func_0203D6BC();
    g = lbl_021469D0;
    *(u32 *)(g + 0x1b0) = *(u32 *)(g + 0x1b0) - 1;
    if (p == 0)
        return 0;
    if (a0 == 0)
        *(u16 *)(lbl_021469D0 + 0x100 + 0xe4) = p[3];
    v = p[4];
    if (v == 0xff)
        return 0;
    if (*(u32 *)(lbl_021469D0 + 0x34) == 0) {
        if (v & 2)
            return 0;
    }
    r = func_0203F1FC(p + 2, n - 2);
    if (p[0] != (u8)r || ((r & 0xff00) >> 8) != p[1]) {
        func_02039548();
        q = func_0203CA98();
        if (*(u32 *)(q + 0xc) == 0)
            func_0203C9AC(*(u32 *)q, *(u32 *)(q + 4), *(u32 *)(q + 8), 0x3f2);
        return 0;
    }
    *(u8 *)(lbl_021469D0 + 0x1d6) = p[5];
    len = p[2];
    if (p[4] & 8)
        len += 0xff;
    func_02036428(lbl_021469D0 + 0x2c, p + 7, len);
    *(u32 *)(lbl_021469D0 + 0x34) = 1;
    return 1;
}
