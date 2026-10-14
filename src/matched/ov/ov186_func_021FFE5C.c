/*
 * function: BR_POKESEARCH_Open
 * address:  0x021FFE5C
 * packet:   pkt_021FFE5C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_POKESEARCH_CreateBackButton  0x021FFEA8  thumb  ov186
 *   BR_POKESEARCH_CreateGroupWindows  0x021FFF28  thumb  ov186
 */
#include "../include/Obj02237.h"

extern void BR_POKESEARCH_CreateBackButton(char *p);
struct Work;
extern void BR_POKESEARCH_CreateGroupWindows(struct Work *p);

void BR_POKESEARCH_Open(char *p)
{
    BR_POKESEARCH_CreateBackButton(p);
    BR_POKESEARCH_CreateGroupWindows((struct Work *)p);
    ((struct Obj02237 *)p)->f6C = 1;
}
