/*
 * function: BR_RES_Delete
 * address: 0x021FB92C
 * packet: pkt_ov186_021FB92C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_ReleaseUiPalette 0x021FC1F8 thumb ov186
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10788.h"
struct Rec {void *a,*b;unsigned char pad[12];void *handle;};
struct WordSet;
extern void BR_RES_ReleaseUiPalette(int *,int);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int GF_FONT_Delete(void *ptr);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void BR_RES_Delete(char *p) {BR_RES_ReleaseUiPalette((int *)p,0);BR_RES_ReleaseUiPalette((int *)p,1);WORDSET_DeleteStrbufED04(((struct Obj10788 *)p)->fF0);MSGDATA_Delete(*(struct Rec * *)&((struct Obj10788 *)p)->fEC);GF_FONT_Delete(((struct Obj10788 *)p)->fE8);func_020307B0(p);}
