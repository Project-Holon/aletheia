/*
 * function: PLIST_PLATE_SetLabelState
 * address: 0x021BB440
 * packet: pkt_ov091_021BB440
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PLIST_PLATE_Redraw 0x021BB2C0 thumb ov091
 *   PLIST_PLATE_UpdateLabelState 0x021BB46C thumb ov091
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern void PLIST_PLATE_UpdateLabelState(u8 *p, u32 *q);
void PLIST_PLATE_SetLabelState(u8 *p, u32 *q, int v)
{
    if (q[7] != v) {
        if (v < 6) {
            q[7] = v;
        } else {
            PLIST_PLATE_UpdateLabelState(p, (u32 *)q);
        }
        PLIST_PLATE_Redraw(p, (u8 *)q);
    }
}
