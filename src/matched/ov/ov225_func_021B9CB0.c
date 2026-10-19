/*
 * function: MANUAL_COMMON_SetSaveValue
 * address: 0x021B9CB0
 * packet: pkt_ov225_021B9CB0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   func_0200EE14 0x0200EE14 thumb
 */
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *MET_TRAINERS_GetFromSave(void *);
extern void func_0200EE14(char *obj, int i);
void MANUAL_COMMON_SetSaveValue(void *unused,int code,struct Big *save) {func_0200EE14(MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(save)),code);}
