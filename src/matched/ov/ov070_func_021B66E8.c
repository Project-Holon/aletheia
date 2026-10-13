/*
 * function: ITEMMENU_TaskFinishClose
 * address: 0x021B66E8
 * packet: pkt_ov070_021B66E8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes.
 * symbols:
 *   ITEMMENU_UpdateSideButtonsForMode 0x021BB5DC thumb ov070
 *   ITEMMENU_ReturnToBagMain 0x021B8AF4 thumb ov070
 */
extern void ITEMMENU_UpdateSideButtonsForMode(int, int);
extern void ITEMMENU_ReturnToBagMain(void *p);
void ITEMMENU_TaskFinishClose(int p)
{
    ITEMMENU_UpdateSideButtonsForMode(p, 1);
    ITEMMENU_ReturnToBagMain((void *)p);
}
