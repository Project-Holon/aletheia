/*
 * function: FIELD_SAVEANIME_Stop
 * address:  0x021D11D8
 * packet:   pkt_ov021_021D11D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   FIELD_SAVEANIME_HideWindow  0x021D1418  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node;
extern void func_02030EAC(struct Node *n);
extern int FIELD_SAVEANIME_HideWindow(void *a);

void FIELD_SAVEANIME_Stop(u32 *p)
{
    if (p[3] != 0) {
        func_02030EAC((struct Node *)p[3]);
        p[3] = 0;
        FIELD_SAVEANIME_HideWindow(p);
    }
}
