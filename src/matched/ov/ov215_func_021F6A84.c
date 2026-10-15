/*
 * function: EGG_DEMO_VIEW_IsFadeDone
 * address: 0x021F6A84
 * packet: pkt_ov215_021F6A84
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: existing followers 021F6A98/6AA4 unit and 021F6AB4 shard.
 * symbols:
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 */
#include "../include/Obj25758.h"

extern int MCSS_CheckPaletteFade(void *);
int EGG_DEMO_VIEW_IsFadeDone(char *p){if(MCSS_CheckPaletteFade(((struct Obj25758 *)p)->f34)==0)return 1;return 0;}
