/*
 * function: UN_SELECT_InitRecord
 * address:  0x021B9924
 * packet:   pkt_ov218_021B9924
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialises one record: enable flag 1 through 0x02023F98, then issue the
 * five-argument setup 0x02023EF4(8, -8, 0, 0x3c, 1) and return its result.
 * Blocker target of UN_SELECT_SceneStepMessage.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   BRIGHTNESS_ChangeRequest  0x02023EF4  thumb  arm9
 *   BRIGHTNESS_ChangeReset  0x02023F98  thumb  arm9
 */

typedef unsigned int u32;

extern void BRIGHTNESS_ChangeReset(u32 mask);
extern int BRIGHTNESS_ChangeRequest(int a, int b, int c, int d, int e);

int UN_SELECT_InitRecord(void)
{
    BRIGHTNESS_ChangeReset(1);
    return BRIGHTNESS_ChangeRequest(8, -8, 0, 0x3c, 1);
}
