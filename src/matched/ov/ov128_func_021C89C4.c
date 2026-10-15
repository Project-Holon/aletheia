/*
 * function: Wf2dmapFriend_ClearEntryPage
 * address: 0x021C89C4
 * packet: pkt_ov128_021C89C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding at 0x021C8A4E; next label 0x021C8A50.
 * symbols:
 *   Wf2dmapFriend_DeleteEntryActors 0x021C8A50 thumb ov128
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 */
#include "../include/Obj03282.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void Wf2dmapFriend_DeleteEntryActors(char *p, int unused);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void BG_SYS_SetTileEntry(u32,int,u8,u8,u8,u8,u8);
static inline int ab(int v) {return v<0?-v:v;}
void Wf2dmapFriend_ClearEntryPage(char *p, void *q, void *a2) {
 void *v;
 Wf2dmapFriend_DeleteEntryActors(p,(int)q);
 v=**(void ** *)&((struct Obj03282 *)p)->f8;BMP_WIN_ClearScreen(v);func_02041B6C(BMP_WIN_GetBgLayer(v));
 BG_SYS_SetTileEntry(2,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(2);
 BG_SYS_SetTileEntry(3,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(3);
}
