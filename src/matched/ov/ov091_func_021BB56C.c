/*
 * function: PLIST_PLATE_GetActorOffset
 * address: 0x021BB56C
 * packet: pkt_ov091_021BB56C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_GetSurfacePos 0x0204B0C8 arm
 */
#include "../include/Obj20885.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y; } Pair;
struct Owner;
struct Pt;
extern void CLACT_GetSurfacePos(struct Owner *owner, u32 index, struct Pt *out);
void PLIST_PLATE_GetActorOffset(u32 p,int x,int y,u16 *out) { Pair pos; CLACT_GetSurfacePos((struct Owner *)(((struct Obj20885 *)p)->f24),0,(struct Pt *)(&pos)); out[0]=x-pos.x; out[1]=y-pos.y; }
