/*
 * function: ITEMMENU_ReturnToBagMain
 * address: 0x021B8AF4
 * packet: pkt_ov070_021B8AF4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 *   ITEMMENU_TaskBagMain 0x021B7250 thumb ov070
 *   KEY_SetRepeatSpeed 0x02036270 arm
 */
typedef unsigned int u32;
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskBagMain(void *p);
extern int KEY_SetRepeatSpeed(int a0, int a1);
void ITEMMENU_ReturnToBagMain(void *p)
{
    ITEMMENU_SetTask(p, (int)ITEMMENU_TaskBagMain);
    KEY_SetRepeatSpeed(3, 6);
}
