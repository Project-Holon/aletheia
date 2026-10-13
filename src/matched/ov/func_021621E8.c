/*
 * function: EVENT_FIELD_PROCLINK_HandlerRemoveEntry
 * address:  0x021621E8
 * packet:   pkt_021621E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_GetEventdataEntry  0x02161DC4  thumb  ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry  0x02161E78  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CompactReturnList  0x02161E60  thumb  ov010
 */
#include "../include/Obj17712.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *EVENT_FIELD_PROCLINK_GetEventdataEntry(char *p, int id, unsigned mode);
extern int EVENT_FIELD_PROCLINK_ClearReturnEntry();
extern int EVENT_FIELD_PROCLINK_CompactReturnList(int a0, int a1);

int EVENT_FIELD_PROCLINK_HandlerRemoveEntry(int a0, int a1, int a2)
{
    int t4;
    int t5;
    char *s;

t5 = a1 + 0;
a1 = ((struct Obj17712 *)a2)->f4;
a0 = t5 + 0;
a2 = 1;
t4 = 1;
    s = EVENT_FIELD_PROCLINK_GetEventdataEntry((char *)a0, a1, a2);
loc_021621F8:
    if (s == 0) goto loc_02162208;
loc_021621FC:
    a0 = EVENT_FIELD_PROCLINK_ClearReturnEntry(s);
loc_02162200:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = EVENT_FIELD_PROCLINK_CompactReturnList(a0, a1);
loc_02162208:
a0 = 0;
    return a0;}
