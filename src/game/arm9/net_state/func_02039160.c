/*
 * function: func_02039160
 * address:  0x02039160
 * packet:   pkt_02039160
 * status:   EXACT
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_020392EC  0x020392EC  arm
 *   func_02039338  0x02039338  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *lbl_021469D0;
extern int func_0203D788(void);
extern int func_0203D798(void);
extern int func_020392EC(void);
extern int func_02039338(void);

int func_02039160(u32 mode)
{
    u8 *p5;
    u8 *p4;
    u8 *g;
    u32 v;
    u16 m;

    p5 = (u8 *)func_0203D788();
    p4 = (u8 *)func_0203D798();
    g = lbl_021469D0;
    if (g == 0)
        return 0;
    v = (u8)(p4[0x65] + 0xff);
    if (v <= 1) {
        if (g[0x1e7] != 0) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x80)))() != -1) {
                if (mode == 0)
                    return 1;
                if (mode == 1)
                    return 1;
            }
        }
        return 0;
    }
    v = (u8)(p4[0x65] + 0xfd);
    if (v <= 1) {
        if (mode < 2 || mode == 0xff) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() != 0)
                return 1;
        }
        return 0;
    }
    if (func_020392EC() == 0)
        return 0;
    if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() == 0)
        return 0;
    if (mode == (u32)func_02039338())
        return 1;
    if (func_02039338() == 0 || p4[0x64] == 0) {
        m = (u16)((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x7c)))();
        if (((1 << mode) & m) != 0)
            return 1;
    } else {
        if (((1 << mode) & *(u16 *)(lbl_021469D0 + 0x100 + 0xe4)) != 0)
            return 1;
    }
    return 0;
}
