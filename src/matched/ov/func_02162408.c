/*
 * function: EVENTDATA_SYSTEM_Load
 * address:  0x02162408
 * packet:   pkt_02162408
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENTDATA_SYSTEM_Clear  0x021623DC  thumb  ov010
 *   EVENTDATA_SYSTEM_LoadEventData  0x0216242C  thumb  ov010
 *   EVENTDATA_SYSTEM_LoadEncountData  0x02162438  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int EVENTDATA_SYSTEM_Clear();
extern int EVENTDATA_SYSTEM_LoadEventData();
extern int EVENTDATA_SYSTEM_LoadEncountData();

int EVENTDATA_SYSTEM_Load(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = EVENTDATA_SYSTEM_Clear(a0);
loc_02162414:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = EVENTDATA_SYSTEM_LoadEventData(a0, a1, a2);
loc_0216241E:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = EVENTDATA_SYSTEM_LoadEncountData(a0, a1, a2);
loc_02162428:
    return a0;}
