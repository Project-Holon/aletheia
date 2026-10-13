/*
 * function: STARTMENU_SaveEraseUpdateTimeIcon
 * address:  0x021BCE70
 * packet:   pkt_ov088_021BCE70
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (four instructions and two pool words) between
 * STARTMENU_SaveEraseStepSecondConfirm and STARTMENU_SaveEraseStepErase: loads the pointer held at 0x021BDA20 and
 * tail-calls TIME_ICON_Update with it.  Its only reference is the callback
 * pointer 0x021BCE71 in STARTMENU_SaveEraseStepErase.
 *
 * symbols:
 *   TIME_ICON_Update  0x0202F0B0  thumb
 *   d_021BDA20     0x021BDA20  data  a4
 */

extern void *d_021BDA20;
typedef unsigned char  u8;
extern void TIME_ICON_Update(u8 *p);

void STARTMENU_SaveEraseUpdateTimeIcon(void)
{
    TIME_ICON_Update(d_021BDA20);
}
