/*
 * function: PMSIV_MENU_IsBackItemDone
 * address: 0x021BCE30
 * packet: pkt_ov110_021BCE30
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCE46.
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
#include "../include/Obj06390.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int PMSIV_MENU_IsBackItemDone(char *p) { if (CLACT_IsActorAnimActive(((struct Obj06390 *)p)->f8C)==0) return 1; return 0; }
