/*
 * unit:     no
 * function: func_0202D7D8
 * address:  0x0202D7D8
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202D060       0x0202D060  thumb
 *   sub_0202D0D4        0x0202D0D4  thumb
 *   ENV_SetResourceSet  0x0204AC18  arm
 */

extern int func_0202D060(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 sub_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern int ENV_SetResourceSet(int a0, int a1, int a2, int a3, int a4, int a5, int a6);

int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                   unsigned short a8, unsigned short a9)
{
    int t0 = func_0202D060();
    int t1 = sub_0202D0D4(t0, a1, a2, a3, a4, a5, a6);
    return ENV_SetResourceSet(a0, t1, a7, a8, 0, 1, a9);
}
