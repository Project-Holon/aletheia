/*
 * function: func_021D76A8
 * address: 0x021D76A8
 * packet: pkt_ov125_021D76A8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   BATTLE_REC_Clear 0x0200B448 thumb
 *   GAME_DATA_PartSaveStart 0x02012E4C thumb
 */
struct Ctrl;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p); extern unsigned int SAVE_CONTROL_LoadExtraSave(struct Ctrl *,unsigned int,unsigned char); extern void *func_020073D8(void *,unsigned int,unsigned int); extern void BATTLE_REC_Clear(void *); extern void GAME_DATA_PartSaveStart(unsigned char *,unsigned int);
void func_021D76A8(unsigned char *p,unsigned char heap,unsigned int id) {void *s=GAME_DATA_GetSaveControl((struct Big *)p); SAVE_CONTROL_LoadExtraSave(s,id,heap); BATTLE_REC_Clear(func_020073D8(s,id,0)); GAME_DATA_PartSaveStart(p,id);}
