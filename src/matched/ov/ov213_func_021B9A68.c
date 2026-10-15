/*
 * function: COMM_BTL_DEMO_MAIN_Exit2
 * address: 0x021B9A68
 * packet: pkt_ov213_021B9A68
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_DeleteRows 0x021BA408 thumb ov213
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void COMM_BTL_DEMO_MAIN_DeleteRows(void *);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
int COMM_BTL_DEMO_MAIN_Exit2(u8 *task,void *p) {COMM_BTL_DEMO_MAIN_DeleteRows(p);UI_SCENE_SetNextScene(task,65534);return 1;}
