/*
 * function: func_021859C4
 * address:  0x021859C4
 * packet:   pkt_ov023_021859C4
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218654C  0x0218654C  thumb  ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_021862B0  0x021862B0  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 */

extern int  func_0218654C(char *p);
extern int  func_02186558(char *p);
extern int  func_021862B0(char *p);
typedef unsigned int   u32;
extern void func_02186444(char *p, u32 v);
extern void func_02185354(char *p);

int func_021859C4(char *p, int a1)
{
    if (!((*(int *)(p + 0x927c) == 0 || *(int *)(p + 0x927c) == func_0218654C(p))
          && (func_02186558(p) & *(int *)(p + 0x9280))))
        *(int *)(p + 0x927c) = 0;
    if (func_021862B0(p)) {
        func_02186444(p, 0x1a);
        *(int *)(p + 0x1a4) = 0;
    }
    func_02185354(p);
    return a1;
}
