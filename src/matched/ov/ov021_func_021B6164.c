/*
 * function: func_021B6164
 * address:  0x021B6164
 * packet:   pkt_ov021_021B6164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215B500  0x0215B500  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021B5FB8  0x021B5FB8  thumb  ov021
 *   func_021B5FB4  0x021B5FB4  thumb  ov021
 *   func_021B5F24  0x021B5F24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern int func_0215B500(u32 a, u32 b);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern int func_021B5FB8(u32 a, int sel);
extern int func_021B5FB4(u32 a);
extern int func_021B5F24(u32 a, int sel);

int func_021B6164(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;

    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    o = func_02159AE8((void *)a, (void *)b);
    *o = 1;
    if (func_0215B4AC((void *)b, y, (void **)(&rec)) == 0)
        return 0;
    if (func_021B5FB8(rec, x) == 0) {
        *o = 1;
    } else if (func_0215B500(rec, func_021B5F24(rec, x)) == 1) {
        *o = 3;
    } else if (func_02017E1C((void *)rec, 9, 0) < func_021B5FB4(x)) {
        *o = 2;
    } else {
        *o = 0;
    }
    return 0;
}
