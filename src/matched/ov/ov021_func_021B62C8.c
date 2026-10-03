/*
 * function: func_021B62C8
 * address:  0x021B62C8
 * packet:   pkt_ov021_021B62C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_0202130C  0x0202130C  thumb
 *   func_0215B4AC  0x0215B4AC  thumb ov010
 *   func_020188AC  0x020188AC  thumb
 *   func_02018790  0x02018790  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02159B10(void *, void *);
extern u32 func_0202130C(u32);
extern int func_0215B4AC(void *, u32, u32 *);
extern int func_020188AC(u32, u32);
extern u32 func_02018790(void *p);

int func_021B62C8(void *a, void *b)
{
    u16 *p;
    u32 v;
    u32 w;
    u32 x;
    u16 r;

    p = func_02159AE8(a, b);
    v = func_02159B10(a, b);
    w = func_0202130C(0x151);
    if (func_0215B4AC(b, v, &x) == 0) {
        *p = 0xFFFF;
    } else if (func_020188AC(x, w) == 0) {
        *p = 0xFFFF;
    } else {
        *p = func_02018790((void *)x);
    }
    return 0;
}
