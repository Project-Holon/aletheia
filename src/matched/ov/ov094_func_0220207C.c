/*
 * function: BTLV_INPUT_CreateWithMode
 * address:  0x0220207C
 * packet:   pkt_ov094_0220207C
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

void BTLV_INPUT_CreateWithMode(int a, int b, int c, int d, int e, int f, int g, u16 k)
{
    BTLV_INPUT_Create(a, b, c, d, e, f, g, 1, k);
}
