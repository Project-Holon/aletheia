/*
 * function: BTL_MSG_DispatchTagged
 * address:  0x021EEEF4
 * packet:   pkt_ov093_021EEEF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sBtlMsgBuilders  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   BTL_MSG_BuildStandard  0x021EF1CC  thumb  ov093
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 pad;
    u32 pad2;
} E;

typedef struct {
    void (*fn)(u32, u32, u32);
    u32 pad;
} F;

extern E sBtlMsgBuilders[];
extern F d_021F39DC[];
extern void BTL_MSG_BuildStandard(u32 a, u32 b, u32 c);

void BTL_MSG_DispatchTagged(u32 a, u16 b, u32 c)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (b == sBtlMsgBuilders[i].id) {
            d_021F39DC[i].fn(a, b, c);
            return;
        }
    }
    BTL_MSG_BuildStandard(a, b, c);
}
