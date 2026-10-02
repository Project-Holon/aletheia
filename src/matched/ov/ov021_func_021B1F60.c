/*
 * function: func_021B1F60
 * address:  0x021B1F60
 * packet:   pkt_ov021_021B1F60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Each arm stores its constant through o itself; cross-jumping merges the
 * stores, leaving cases 2 and 3 branching onto case 1's branch.
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 *func_02158F58(u32);
extern u32 func_02188CB4(u32);
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0215A5F4(u32);
extern u32 *func_02158F58(u32);
extern u32 func_02188CB4(u32);
extern u16 *func_02159AE8(u32, u32);
extern u32 func_021A3098(u32);

int func_021B1F60(u32 a, u32 b)
{
    u32 x = func_02188CB4(func_02158F58(func_0215A5F4(b))[1]);
    u16 *o = func_02159AE8(a, b);

    switch (func_021A3098(x)) {
    case 0:
        *o = 0;
        break;
    case 1:
        *o = 1;
        break;
    case 2:
        *o = 2;
        break;
    case 3:
        *o = 3;
        break;
    default:
        *o = 0;
        break;
    }
    return 0;
}
