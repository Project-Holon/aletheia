/*
 * function: P_STA_SKILL_ShowSlot
 * address: 0x021DB964
 * packet: pkt_ov131_021DB964
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DB9E6.
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   WAZA_TOOL_GetType 0x0201C1C8 thumb
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 */
#include "../include/Obj00112.h"
#include "../include/Obj02847.h"
#include "../include/Obj23173.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *P_STATUS_GetPokePara(u8 *);
extern unsigned POKE_TOOL_GetBoxValue(void *,unsigned,unsigned);
extern int WAZA_TOOL_GetType(u16);
struct Rec;
extern void CLACT_GetCharacterProxy(unsigned int idx, struct Rec *dst);
struct Struct36;
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern u8 APP_ICON_GetTypePaletteOffset(int i);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void P_STA_OAM_TransferBitmap(u8 *p);
void P_STA_SKILL_ShowSlot(u8 *a,void *b,u8 *p) {
    unsigned v;
    int i;
    unsigned words[9];
    void *q;
    q=P_STATUS_GetPokePara(a);
    if(p[0]<4) v=POKE_TOOL_GetBoxValue(q,p[0]+54,0);
    else v=((struct Obj23173 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f14;
    if(((struct Obj02847 *)p)->f4==1) {
        if(v!=0) {
            i=WAZA_TOOL_GetType(v);
            CLACT_GetCharacterProxy((unsigned int)(*(void **)(a+304+i*4)),(struct Rec *)words);
            CLACT_SetActorImageProxy(((struct Obj02847 *)p)->fC,(const struct Struct36 *)words);
            CLACT_SetActorPaletteOffset(((struct Obj02847 *)p)->fC,APP_ICON_GetTypePaletteOffset(i),1);
            CLACT_SetActorDrawEnable(((struct Obj02847 *)p)->fC,1);
        } else CLACT_SetActorDrawEnable(((struct Obj02847 *)p)->fC,0);
        P_STA_OAM_TransferBitmap(((struct Obj02847 *)p)->f14);
        CLACT_SetActorDrawEnable(((struct Obj02847 *)p)->f8,1);
        ((struct Obj02847 *)p)->f4=0;
    }
}
