/*
 * function: func_021B15C8
 * address:  0x021B15C8
 * packet:   pkt_ov021_021B15C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021904DC  0x021904DC  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Stream;
extern int func_02158F58(int a0);
extern u16 func_02011330(struct Stream *s);
extern void func_021904DC(u8 *p, u8 v);
extern void func_02159144(int n);
extern void func_02159168(int n);

int func_021B15C8(u32 a, u32 b)
{
    u32 *p = (u32 *)func_02158F58((int)func_0215A5F4((void *)b));

    if (func_02011330((struct Stream *)a)) {
        func_021904DC((u8 *)(*p), 1);
        func_02159144(9);
    } else {
        func_021904DC((u8 *)(*p), 0);
        func_02159168(9);
    }
    return 0;
}
