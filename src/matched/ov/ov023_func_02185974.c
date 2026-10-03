/*
 * function: func_02185974
 * address:  0x02185974
 * packet:   pkt_ov023_02185974
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02039338  0x02039338  arm
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02186304  0x02186304  thumb  ov023
 *   func_0218654C  0x0218654C  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern u16 func_02039338(void);
extern void func_021861C4(char *p, int a, int b);
extern void func_02186480(char *p);
extern void func_02186444(char *p, u32 v);
extern void func_02186304(char *p, int a);
extern int  func_0218654C(char *p);
extern void func_02185354(char *p);

int func_02185974(char *p, int a1)
{
    func_021861C4(p, 2, 1);
    func_02186480(p);
    func_02186444(p, 0x19);
    func_020061E4(0x54c);
    if (func_02039338() == 0)
        func_02186304(p, 0);
    *(int *)(p + 0x927c) = func_0218654C(p);
    func_02185354(p);
    return a1;
}
