/*
 * function: EVENTDATA_SYSTEM_ScrCmdRunOverlay47
 * address: 0x02164778
 * packet: pkt_ov010_02164778
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   FIELD_GIMMICK_BRIDGE_ResetSave 0x021F3800 thumb ov047
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_47 0x0000002F data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern int func_02034AC4(int);
extern void FIELD_GIMMICK_BRIDGE_ResetSave(u32 a);
extern void func_02034A5C(int);
extern u8 ov_id_47[];
int EVENTDATA_SYSTEM_ScrCmdRunOverlay47(void *a,void *b){void *v=SCRCMD_WORK_GetGameSystem(b);func_02034AC4((int)ov_id_47);FIELD_GIMMICK_BRIDGE_ResetSave((u32)v);func_02034A5C((int)ov_id_47);return 0;}
