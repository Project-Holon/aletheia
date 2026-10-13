/*
 * function: SCRCMD_NETWORK_CreateOv020Event
 * address: 0x0215FA00
 * packet: pkt_ov010_0215FA00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   EVENT_MAPCHANGE_CreateByMode 0x02183B6C thumb ov020
 *   ov020_id 0x14 data a1
 */

typedef unsigned int u32;
extern unsigned char ov020_id[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void EVENT_MAPCHANGE_CreateByMode(int a, int *p);
void SCRCMD_NETWORK_CreateOv020Event(void *p, void *q) { func_02034AC4((u32)ov020_id); EVENT_MAPCHANGE_CreateByMode((int)p,q); }
