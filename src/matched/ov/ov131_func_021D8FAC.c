/*
 * function: P_STA_RIBBON_Show
 * address: 0x021D8FAC
 * packet: pkt_ov131_021D8FAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: The image's 20-byte records are subscripted per field, avoiding
 *   the pointer-arithmetic spelling's cached object-field base and spill.
 * proof: i is initialized u8 and bounded by 10; i*20 fits int.
 *   Loaded address payloads use u32 +12 for full-word modulo arithmetic.
 * symbols:
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   P_STA_RIBBON_GetRowY 0x021D9440 thumb ov131
 *   P_STA_OAM_SetBitmapActorsPos 0x021DBE2C thumb ov131
 *   P_STA_OAM_SetBitmapActorsEnabled 0x021DBCA4 thumb ov131
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 */
#include "../include/Obj01548.h"
#include "../include/Obj23149.h"
#include "../include/Obj23150.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Entry { u16 id; u8 gap[14]; u8 *object; };
struct List { u8 gap[0x70]; struct Entry entries[10]; };
extern void BG_SYS_DrawTileEx(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
struct Obj;
extern void BG_SYS_DecodeTile(u32 index, const void *src, u32 mode);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern s16 P_STA_RIBBON_GetRowY(u8 *,u32);
extern void P_STA_OAM_SetBitmapActorsPos(u8 *,s16,s16);
extern void P_STA_OAM_SetBitmapActorsEnabled(u8 *,int);
extern void P_STA_OAM_TransferBitmap(u8 *p);
void P_STA_RIBBON_Show(u8 *a,u8 *p)
{
    u8 i;
    u16 value;
    BG_SYS_DrawTileEx(2,0,0,32,24,((struct Obj01548 *)p)->f28+12,0,0,32,32);
    func_02041B6C(2);
    BG_SYS_DecodeTile(6,*(u8 * *)&((struct Obj01548 *)p)->f30+12,((struct Obj23150 *)(*(u8 * *)&((struct Obj01548 *)p)->f30))->f8);
    func_02041B6C(6);
    BG_SYS_DrawTileEx(5,0,0,32,3,((struct Obj01548 *)p)->f40+12,0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        value=((struct List *)p)->entries[i].id;
        P_STA_OAM_SetBitmapActorsPos(((struct List *)p)->entries[i].object,8,P_STA_RIBBON_GetRowY(p,i));
        if(value!=0xffff) {
            P_STA_OAM_SetBitmapActorsEnabled(((struct List *)p)->entries[i].object,1);
            P_STA_OAM_TransferBitmap(((struct List *)p)->entries[i].object);
        } else P_STA_OAM_SetBitmapActorsEnabled(((struct List *)p)->entries[i].object,0);
    }
    ((struct Obj01548 *)p)->f14=0;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj01548 *)p)->f0=1;
    ((struct Obj01548 *)p)->fC=1;
    CLACT_SetActorAnimSeq(((struct Obj23149 *)a)->f180,5);
}
