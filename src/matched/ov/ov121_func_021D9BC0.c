/*
 * function: MYSTERY_UTIL_ComputeTextPosition
 * address: 0x021D9BC0
 * packet: pkt_ov121_021D9BC0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   MYSTERY_UTIL_AlignText 0x021D9BE8 thumb ov121
 */
#include "../include/Obj01057.h"
typedef unsigned char u8;
typedef struct { int x; int y; } Pair;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void MYSTERY_UTIL_AlignText(unsigned,const Pair *,const void *,void *,int,Pair *);
void MYSTERY_UTIL_ComputeTextPosition(const u8 *p,int a,Pair *out) {
    void *bitmap=BMP_WIN_GetBmp(((struct Obj01057 *)p)->fC);
    MYSTERY_UTIL_AlignText(((struct Obj01057 *)p)->f20,(const Pair *)(p+0x18),bitmap,((struct Obj01057 *)p)->f10,a,out);
}
