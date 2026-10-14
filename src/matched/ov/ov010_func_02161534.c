/*
 * function: EVENT_FIELD_PROCLINK_UnloadMailOverlay
 * address: 0x02161534
 * packet: pkt_ov010_02161534
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   MAILTOOL_DeleteArgs 0x021C3E24 thumb ov136
 *   func_02034A5C 0x02034A5C arm
 *   ov136_id 0x88 data a1
 */

typedef unsigned int u32;
extern unsigned char ov136_id[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void MAILTOOL_DeleteArgs(unsigned char *);
void EVENT_FIELD_PROCLINK_UnloadMailOverlay(unsigned char *p) { func_02034AC4((u32)ov136_id); MAILTOOL_DeleteArgs(p); func_02034A5C((u32)ov136_id); }
