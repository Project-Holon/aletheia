/*
 * function: P_STATUS_UpdateTouch
 * address: 0x021D5280
 * packet: pkt_ov131_021D5280
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021DC114 0x021DC114 data a1
 */
#include "../include/Obj23123.h"
struct Rect36 { unsigned char b[36]; };
extern const struct Rect36 d_021DC114;
extern int TOUCHPANEL_HitTrg(const void *key);
void P_STATUS_UpdateTouch(char *p)
{
    struct Rect36 r = d_021DC114;
    ((struct Obj23123 *)p)->f24 = TOUCHPANEL_HitTrg(&r);
}
