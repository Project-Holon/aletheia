/*
 * function: func_021B6114
 * address:  0x021B6114
 * packet:   pkt_ov090_021B6114
 * region:   ov090
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   d_021B6228     0x021B6228  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_020399A8(void);
extern void func_02039C68(u32 h, u32 a, u32 b);
extern int func_02039CB4(u32 h, u32 a, u32 b);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0200FB24(void);
extern u8 d_021B6228[];

void func_021B6114(u8 *p)
{
    switch (p[0x62]) {
    case 0:
        func_02039C68(func_020399A8(), 1, 0x2d);
        p[0x62] = 1;
        break;
    case 1:
        if (func_02039CB4(func_020399A8(), 1, 0x2d) == 1) {
            func_0203A574(0x2d00, (u32)d_021B6228, 1, (u32)p);
            p[0x62] = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_0200FB24() != 0 && p[0x63] == 0)
        p[0x63] = 1;
}
