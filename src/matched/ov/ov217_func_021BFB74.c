/*
 * function: RESEARCH_GRAPH_CreateMessages
 * address:  0x021BFB74
 * packet:   pkt_ov217_021BFB74
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   d_021C3650 0x021C3650 data a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct W { u32 w0; u16 h; u16 pad; u32 w8; u32 obj[3]; } W;
extern u32 d_021C3650[];
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void RESEARCH_GRAPH_CreateMessages(W *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->obj[i] = (u32)func_02045B38(0, 2, (u16)d_021C3650[i], (u16)p->h);
    }
}
