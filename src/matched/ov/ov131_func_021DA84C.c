/*
 * function: P_STA_SKILL_FreeMovesPage
 * address: 0x021DA84C
 * packet: pkt_ov131_021DA84C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA8BA.
 * symbols:
 *   BMP_Delete 0x020437AC arm
 *   P_STA_OAM_DeleteBitmapActors 0x021DBC3C thumb ov131
 *   P_STA_SKILL_FreeSlot 0x021DB9E8 thumb ov131
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj02190.h"
typedef unsigned char u8;
struct Descriptor;
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);
extern void P_STA_OAM_DeleteBitmapActors(u8 *p);
extern void P_STA_SKILL_FreeSlot(void *,void *,u8 *);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void P_STA_SKILL_FreeMovesPage(u8 *a,u8 *b) {
    u8 i;
    if(b[43]==5) {
        BMP_Delete(((struct Obj02190 *)b)->fA8);
        P_STA_OAM_DeleteBitmapActors(((struct Obj02190 *)b)->fAC);
    }
    for(i=0;i<b[43];i++) P_STA_SKILL_FreeSlot(a,b,b+176+i*24);
    for(i=0;i<13;i++) BMP_WIN_Delete(*(void **)(b+92+i*4));
    *(int *)&((struct Obj02190 *)b)->f0=0;
}
