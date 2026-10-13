/*
 * function: GIMMICK_OBJ_ELBOARD_AddLine
 * address: 0x021F472C
 * packet: pkt_ov048_021F472C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_CreateLine 0x021F4948 thumb ov048
 */
#include "../include/Obj01224.h"
struct P;
struct Q;
struct R;
extern struct R *GIMMICK_OBJ_ELBOARD_CreateLine(struct P *p, const struct Q *q, int c);
void GIMMICK_OBJ_ELBOARD_AddLine(unsigned char *p,const void *q) { if(p[3]>p[2]) { ((void **)((struct Obj01224 *)p)->f8)[p[2]]=GIMMICK_OBJ_ELBOARD_CreateLine((struct P *)p,q,p[2]); p[2]++; } }
