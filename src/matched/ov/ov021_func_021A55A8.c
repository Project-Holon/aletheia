/*
 * function: func_021A55A8
 * address:  0x021A55A8
 * packet:   pkt_ov021_021A55A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5458  0x021A5458  thumb  ov021
 *   func_021A5334  0x021A5334  thumb  ov021
 *   data_021D89EC  0x021D89EC  data  a4
 */

typedef unsigned int u32;

typedef int (*Fn021A55A8)(u32 *p, int a);

extern Fn021A55A8 const data_021D89EC[];

int func_021A5458(u32 *p);
void func_021A5334(u32 a);

int func_021A55A8(u32 *p, int a, int b)
{
    if (b == 0) {
        if (data_021D89EC[func_021A5458(p)](p, a) == 1)
            return 1;
    }
    func_021A5334((u32)p);
    return 0;
}
