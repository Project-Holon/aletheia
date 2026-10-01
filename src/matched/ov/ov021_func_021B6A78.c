/*
 * function: func_021B6A78
 * address:  0x021B6A78
 * packet:   pkt_ov021_021B6A78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb ov010
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200A8AC  0x0200A8AC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *);
extern u16 *func_02159AE8(void *, void *);
extern void *func_02012EBC(void *);
extern void *func_0200A8A0(void *);
extern u16 func_0200A8AC(void *);

int func_021B6A78(void *a, void *b)
{
    void *t;
    u16 *p;

    t = func_0215A5E4(b);
    p = func_02159AE8(a, b);
    *p = func_0200A8AC(func_0200A8A0(func_02012EBC(t)));
    return 0;
}
