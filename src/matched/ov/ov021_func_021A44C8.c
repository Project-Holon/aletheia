/*
 * function: func_021A44C8
 * address:  0x021A44C8
 * packet:   pkt_ov021_021A44C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A5610  0x021A5610  thumb  ov021
 *   func_021A53BC  0x021A53BC  thumb  ov021
 *   func_021A46F0  0x021A46F0  thumb  ov021
 *   func_021A4544  0x021A4544  thumb  ov021
 *   func_021A4598  0x021A4598  thumb  ov021
 *   func_021A4664  0x021A4664  thumb  ov021
 *   func_021A4698  0x021A4698  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3960(u32);
extern int func_021A5610(u8 *);
extern int func_021A53BC(u8 *);
extern int func_021A46F0(u8 *, u32);
extern int func_021A4544(u8 *, u32, u32);
extern int func_021A4598(u8 *, u32, u32);
extern int func_021A4664(u8 *, u32, u32);
extern int func_021A4698(u8 *, u32, u32);

int func_021A44C8(u8 *p, u32 s)
{
    u32 a;
    int r;

    a = func_021A3960(*(u32 *)(p + 0xc));
    r = 0;
    if (func_021A5610(p) == 1 || func_021A53BC(p) == 1) {
        return func_021A46F0(p, s);
    }
    switch (*(u32 *)p) {
    case 0:
        r = func_021A4544(p, a, s);
        break;
    case 1:
        r = func_021A4598(p, a, s);
        break;
    case 2:
        r = func_021A4664(p, a, s);
        break;
    case 3:
        r = func_021A4698(p, a, s);
        break;
    }
    return r;
}
