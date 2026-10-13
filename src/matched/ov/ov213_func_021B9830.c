/*
 * function: func_021B9830
 * address: 0x021B9830
 * packet: pkt_ov213_021B9830
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA408 0x021BA408 thumb ov213
 *   func_021BA624 0x021BA624 thumb ov213
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BA408(char *);
extern void func_021BA624(char *);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
void func_021B9830(u8 *task, char *p) {
    func_021BA408(p);
    func_021BA624(p + 0x498C);
    UI_SCENE_SetNextScene(task,65534);
}
