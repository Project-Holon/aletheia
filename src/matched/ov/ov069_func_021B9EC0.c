/*
 * function: BSUBWAY_RECORD_LIST_StateBackAnim
 * address: 0x021B9EC0
 * packet: pkt_ov069_021B9EC0
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 */
#include "../include/Obj13147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
int BSUBWAY_RECORD_LIST_StateBackAnim(u8 *p) { if (CLACT_IsActorAnimActive(((struct Obj13147 *)p)->f128)==0) ((struct Obj13147 *)p)->f158=3; return 1; }
