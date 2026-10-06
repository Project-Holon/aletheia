/*
 * function: func_021A000C
 * address:  0x021A000C
 * packet:   pkt_ov021_021A000C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: func_020507F0 (0x020507F0) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   void func_020507F0(u8 *p, int i, u32 v) { *(u32 *)(*(u8 **)(p + 0x18) + i * 40 + 0x18) = v; }  (EXACT, verified)
 *
 * symbols:
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_0219C648  0x0219C648  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_0219C648(u32 a);
extern int func_0216D55C(int a0, int a1);
extern int func_02197C9C(u32 a);
extern int func_0216DAB4(void *a0);
extern void func_020507F0(void *p, int idx, u32 v);
extern int func_020507A0(void *p, int idx, u32 x);

void func_021A000C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 f;
    u32 k;

    f = 1;
    k = func_0219C648(a);
    if (d == 0) {
        if (e == 1) {
            if (k == 1 && func_0216D55C(a, 0x10) != 0) f = 0;
        } else {
            if (k == 1 && func_02197C9C(a) == 1) f = 0;
        }
    }
    func_020507F0((void *)b, c, f);
    f = 1;
    if (func_0216DAB4((void *)a) == 1) f = 0;
    func_020507A0((void *)b, c, f);
}
