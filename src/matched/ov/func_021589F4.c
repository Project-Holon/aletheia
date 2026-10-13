/*
 * function: SCRIPT_SYS_ClearLocalWork
 * address:  0x021589F4
 * packet:   pkt_021589F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_ResetEventFlagRange  0x02014368  thumb
 *   ZONEDATA_ClearEventWorkRange  0x020143D8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int ZONEDATA_ResetEventFlagRange();
extern int ZONEDATA_ClearEventWorkRange();

int SCRIPT_SYS_ClearLocalWork(int a0)
{
    int a1;
    int a2;
    int t4;

a1 = 0;
a2 = 0x63;
t4 = a0 + 0;
    a0 = ZONEDATA_ResetEventFlagRange(a0, a1, a2);
loc_02158A00:
a1 = 1;
a1 = a1 << 0xe;
a2 = a1 + 0;
a0 = t4 + 0;
a2 = a2 + 0x1f;
    a0 = ZONEDATA_ClearEventWorkRange(a0, a1, a2);
loc_02158A0E:
    return a0;}
