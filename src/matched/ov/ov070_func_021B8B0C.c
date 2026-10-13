/*
 * function: ITEMMENU_ReturnToListInput
 * address: 0x021B8B0C
 * packet: pkt_ov070_021B8B0C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 *   ITEMMENU_TaskListInput 0x021B66FC thumb ov070
 *   KEY_SetRepeatSpeed 0x02036270 arm
 */
typedef unsigned int u32;
extern void ITEMMENU_SetTask(char *p, int k);
typedef unsigned char  u8;
extern void ITEMMENU_TaskListInput(u8 *p);
extern int KEY_SetRepeatSpeed(int a0, int a1);
int ITEMMENU_ReturnToListInput(void *p)
{
    ITEMMENU_SetTask(p, (int)ITEMMENU_TaskListInput);
    return KEY_SetRepeatSpeed(3, 6);
}
