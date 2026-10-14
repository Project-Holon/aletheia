/*
 * function: ZUKAN_LIST_ShowSpeciesActor
 * address: 0x021BE29C
 * packet: pkt_ov209_021BE29C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Enum position preserves the full-width update and repeated signed-halfword argument conversions.
 * symbols:
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   ZUKAN_LIST_IsActorHidden 0x021BE25C thumb ov209
 *   ZUKAN_LIST_TransferSpeciesGraphics 0x021BE1B8 thumb ov209
 *   ZUKAN_LIST_SetActorVisible 0x021BD8D8 thumb ov209
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 *   ZUKAN_LIST_AddActorPos 0x021BD934 thumb ov209
 */
#include "../include/Obj25578.h"
#include "../include/Obj25579.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern int ZUKAN_LIST_IsActorHidden(int,int);
extern void ZUKAN_LIST_TransferSpeciesGraphics(char *,int,unsigned,u16,u16,int);
extern void ZUKAN_LIST_SetActorVisible(char *p, u32 idx, u32 value);
extern void ZUKAN_LIST_StartActorAnim(char *,int,int);
extern void ZUKAN_LIST_AddActorPos(char *,int,short,short,u16);
enum Position { POSITION_ZERO=0 };
void ZUKAN_LIST_ShowSpeciesActor(char *p,u16 species,enum Position pos,int mode)
{
    unsigned out1,outForm,out2;
    int index;
    ZUKAN_SAVE_GetViewGenderAndForm(*(u8 * *)&((struct Obj25579 *)(*(char * *)&((struct Obj25578 *)p)->f0))->f4,species,&out1,&out2,&outForm,0x806b);
    index=ZUKAN_LIST_IsActorHidden((int)p,mode);
    ZUKAN_LIST_TransferSpeciesGraphics(p,index,species,outForm,out1,mode);
    ZUKAN_LIST_SetActorVisible(p,index,1);
    ZUKAN_LIST_StartActorAnim(p,index,0);
    if (mode==1) {
        pos+=8;
        ZUKAN_LIST_AddActorPos(p,index,112,pos,0);
        return;
    }
    pos+=8;
    ZUKAN_LIST_AddActorPos(p,index,112,pos,1);
    ZUKAN_LIST_AddActorPos(p,index+16,112,pos,1);
    index+=16;
    ZUKAN_LIST_SetActorVisible(p,index,1);
}
