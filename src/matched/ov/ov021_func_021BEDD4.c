/*
 * function: func_021BEDD4
 * address:  0x021BEDD4
 * packet:   pkt_ov021_021BEDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BEDD4  0x021BEDD4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BED14  0x021BED14  thumb  ov021
 *   func_021BED74  0x021BED74  thumb  ov021
 *   func_021BEC54  0x021BEC54  thumb  ov021
 *   func_021BECB4  0x021BECB4  thumb  ov021
 */

struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_021A3050(u8 *p);
typedef unsigned int   u32;
extern u32 func_021BED14(u32 a, u32 b);
extern int func_021BED74(int a, int b);
extern int func_021BEC54(int a, int b);
extern void *func_021BECB4(void *p, u32 b);

int func_021BEDD4(void *a, int b)
{
    switch (func_021A3050(func_02188CB4((struct Obj00020 *)b))) {
    case 2:
    default:
        return func_021BED14((u32)a, b);
    case 3:
        return func_021BED74((int)a, b);
    case 0:
        return func_021BEC54((int)a, b);
    case 1:
        return (int)func_021BECB4(a, b);
    }
}
