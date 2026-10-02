/*
 * function: func_021B50D0
 * address:  0x021B50D0
 * packet:   pkt_ov021_021B50D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_02012A44  0x02012A44  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0216EFCC  0x0216EFCC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern u32 func_02012A44(void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0216EFCC(u32);

int func_021B50D0(u32 a, u32 b)
{
    u32 x = func_02012A44(func_0215A5E4((void *)b));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_0216EFCC(x);
    return 0;
}
