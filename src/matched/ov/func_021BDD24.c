/*
 * function: ZUKAN_DETAIL_TOUCHBAR_ReleaseResources
 * address:  0x021BDD24
 * packet:   pkt_021BDD24
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources 0x021BDFA8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources 0x021BE4DC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources 0x021BE680  thumb  ov208

 */
#include "../include/Obj01081.h"

struct Ov208Eff;
extern void ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources(struct Ov208Eff *e);
extern void ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources(struct Ov208Eff *e);
extern void ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(char *);

void ZUKAN_DETAIL_TOUCHBAR_ReleaseResources(char *p)
{
    switch (((struct Obj01081 *)p)->fC) {
    case 0:
        ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources((struct Ov208Eff *)p);
        break;
    case 1:
        ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources((struct Ov208Eff *)p);
        break;
    case 2:
        ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(p);
        break;
    }
}

