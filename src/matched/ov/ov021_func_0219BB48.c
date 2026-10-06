/*
 * function: func_0219BB48
 * address:  0x0219BB48
 * packet:   pkt_ov021_0219BB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0219BCE4  0x0219BCE4  thumb  ov021
 *   func_0219BD30  0x0219BD30  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);
extern int func_0219BCE4(u32 a, u32 b);
struct Obj05999;
extern int func_0219BD30(char *a, struct Obj05999 *b);
extern void func_0216DA44(u32);

int func_0219BB48(char *a, u8 *s)
{
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    if (func_0219BCE4((u32)a, (u32)s) == 1 && func_0219BD30(a, (struct Obj05999 *)s) == 1) {
        func_0216DA44((u32)a);
        s[0]++;
        return 1;
    }
    return 0;
}
