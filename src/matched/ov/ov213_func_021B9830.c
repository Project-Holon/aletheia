/*
 * function: COMM_BTL_DEMO_MAIN_Exit
 * address: 0x021B9830
 * packet: pkt_ov213_021B9830
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_DeleteRows 0x021BA408 thumb ov213
 *   COMM_BTL_DEMO_MAIN_DeleteBattleContext 0x021BA624 thumb ov213
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void COMM_BTL_DEMO_MAIN_DeleteRows(char *);
extern void COMM_BTL_DEMO_MAIN_DeleteBattleContext(char *);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
void COMM_BTL_DEMO_MAIN_Exit(u8 *task, char *p) {
    COMM_BTL_DEMO_MAIN_DeleteRows(p);
    COMM_BTL_DEMO_MAIN_DeleteBattleContext(p + 0x498C);
    UI_SCENE_SetNextScene(task,65534);
}
