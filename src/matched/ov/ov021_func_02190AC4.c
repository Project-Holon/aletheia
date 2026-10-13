/*
 * function: FIELD_MSGBG_GetMenuItemCount
 * address:  0x02190AC4
 * packet:   pkt_ov021_02190AC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail call through a pool word), sole blocker of
 * ov010 SCRCMD_WORK_StartMenu's MATCH.
 *
 * symbols:
 *   BMP_MENUWORK_CountItems  0x0201F91C  thumb
 */

typedef unsigned int   u32;
struct Slot;
extern u32 BMP_MENUWORK_CountItems(struct Slot *s);

unsigned FIELD_MSGBG_GetMenuItemCount(void *p)
{
    return BMP_MENUWORK_CountItems(p);
}
