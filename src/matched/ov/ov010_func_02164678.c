/*
 * function: EVENTDATA_SYSTEM_AddFieldLinkObject
 * address: 0x02164678
 * packet: pkt_ov010_02164678
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 2-byte zero alignment padding at 0x0216469E.
 * symbols:
 *   EVENT_MAPCHANGE_CreateIntrudeWarpEvent 0x02185140 thumb ov020
 */

typedef struct { int x,y,z; } Vec;
extern void EVENT_MAPCHANGE_CreateIntrudeWarpEvent(void *, int, const Vec *, int);
void EVENTDATA_SYSTEM_AddFieldLinkObject(void *unused, void *a) { Vec v; v.x=0x200000; v.y=32; v.z=0x1E8000; EVENT_MAPCHANGE_CreateIntrudeWarpEvent(a,279,&v,0); }
