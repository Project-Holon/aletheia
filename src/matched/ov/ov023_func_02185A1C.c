/*
 * function: func_02185A1C
 * address:  0x02185A1C
 * packet:   pkt_ov023_02185A1C
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_0218654C  0x0218654C  thumb  ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_021862F4  0x021862F4  thumb  ov023
 *   func_02186304  0x02186304  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 func_02039338(void);
extern int  func_021841A4(unsigned char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern int  func_0218654C(char *p);
extern int  func_02186558(char *p);
extern void func_021862F4(char *p);
extern void func_02186304(char *p, int a);
extern void func_02186444(char *p, u32 v);
extern void func_02185354(char *p);

int func_02185A1C(char *p, int a1)
{
    if (!((*(int *)(p + 0x927c) == 0 || *(int *)(p + 0x927c) == func_0218654C(p))
          && (func_02186558(p) & *(int *)(p + 0x9280))))
        *(int *)(p + 0x927c) = 0;
    *(int *)(p + 0x1a4) += 1;
    if (*(int *)(p + 0x1a4) > 0x3c && *(int *)(p + 0x927c) == 0) {
        func_021862F4(p);
        func_02186444(p, 4);
        if (func_02039338() == 0) {
            *(int *)(p + 0x9e6c) = 1;
            func_02186304(p, 1);
        }
        *(int *)(p + 0x1ac) = func_021841A4(**(unsigned char ***)(p + 4));
        *(int *)(p + 0x1b0) = func_021841A0((unsigned char *)(**(u32 **)(p + 4)));
    }
    func_02185354(p);
    return a1;
}
