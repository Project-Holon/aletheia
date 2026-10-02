/*
 * function: func_021BD920
 * address:  0x021BD920
 * packet:   pkt_ov210_021BD920
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7AB0  0x021B7AB0  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE190  0x021BE190  thumb  ov210
 *   func_021BF728  0x021BF728  thumb  ov210
 *   func_021BEDB8  0x021BEDB8  thumb  ov210
 *   func_021BE2F4  0x021BE2F4  thumb  ov210
 *   func_021BF81C  0x021BF81C  thumb  ov210
 *   func_021BFABC  0x021BFABC  thumb  ov210
 *   func_021C014C  0x021C014C  thumb  ov210
 *   func_021BE20C  0x021BE20C  thumb  ov210
 *   func_021BF6E0  0x021BF6E0  thumb  ov210
 *   func_021BCEF0  0x021BCEF0  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern int func_021B7AB0(u32 a);
extern int func_020355C4(void);
extern void func_020061E4(u32 id);
extern void func_021BE190(u8 *p, int n);
extern void func_021BF728(u8 *p, int a);
extern void func_021BEDB8(u8 *p, u32 a, u32 b);
extern u32 func_021BE2F4(u8 *p, u32 a, u32 b, u32 c);
extern void func_021BF81C(u8 *p);
extern void func_021BFABC(u8 *p, u32 a, u32 b);
extern int func_021C014C(u8 *p);
extern void func_021BE20C(u8 *p);
extern void func_021BF6E0(u8 *p);
extern u32 func_021BCEF0(u32 a, u32 b);

u32 func_021BD920(u8 *p)
{
    u32 ret = 16;
    u32 r5 = func_021B7AB0(*(u32 *)(p + 0x1e0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (func_020355C4() == 0) {
            func_020061E4(0x54c);
            func_021BE190(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        func_021BF728(p, 0);
        break;
    case (u32)-7:
        func_021BEDB8(p, 6, 12);
        p[0x2c1] = 6;
        *(u32 *)(p + 0x14) = 0;
        *(u32 *)(p + 0x18) = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        func_021BEDB8(p, 5, 13);
        p[0x2c1] = 5;
        *(u32 *)(p + 0x14) = 0;
        *(u32 *)(p + 0x18) = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        func_021BEDB8(p, 6, 12);
        return func_021BE2F4(p, 1, 6, 16);
    case (u32)-4:
        func_021BEDB8(p, 5, 13);
        return func_021BE2F4(p, 1, 5, 16);
    case (u32)-3:
    case (u32)-2:
        func_021BF81C(p);
        func_021BFABC(p, 0, (u16)func_021BCEF0((u32)p, (*(u8 **)(*(u8 **)p + 8))[3]));
        func_021BFABC(p, 1, (u16)func_021BCEF0((u32)p, (*(u8 **)(*(u8 **)p + 8))[4]));
        p[0x2c1] = 0x39;
        *(u32 *)(p + 0x14) = 1;
        *(u32 *)(p + 0x18) = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = func_021C014C(p);
        switch (r5) {
        case 0:
            func_020061E4(0x551);
            func_021BEDB8(p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x11);
        case 8:
            func_020061E4(0x551);
            func_021BEDB8(p, 2, 9);
            return func_021BE2F4(p, 1, 2, 0x11);
        case 9:
            func_020061E4(0x54c);
            func_021BE20C(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            func_020061E4(0x54c);
            func_021BF728(p, 0);
            func_021BE190(p, r5 - 1);
            break;
        }
        break;
    }
    func_021BF6E0(p);
    return ret;
}
