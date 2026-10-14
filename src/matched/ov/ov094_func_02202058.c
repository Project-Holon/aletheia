/*
 * function: BTLV_INPUT_CreateDefault
 * address:  0x02202058
 * packet:   pkt_ov094_02202058
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_INPUT_Create  0x022020A0  thumb  ov094
 */
typedef unsigned short u16;
struct Obj;
extern struct Obj *BTLV_INPUT_Create(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap);

struct Obj *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k)
{
    return BTLV_INPUT_Create(a, b, 0, c, d, e, 0, 0, k);
}
