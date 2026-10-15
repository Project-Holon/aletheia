/*
 * function: P_STA_SKILL_InitSlotText
 * address: 0x021DB7D4
 * packet: pkt_ov131_021DB7D4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantic: selector loads are fresh bytes after each getter, additions
 *   <=321 fit int. Every branch initializes id/count/value. Late table
 *   index is the full byte, with no assumed menu bound; address arithmetic
 *   is u32 wrap. Table x+5<=260, times8<=2080; y*8<=2040, fit s16.
 *   All24 descriptor bytes (including its value and screen) are assigned.
 *   Pool B95C/B960 name the same byte-pair object at C2B8 and its +1 byte.
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   BMP_Create 0x02043678 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   P_STATUS_PrintMsg 0x021D614C thumb ov131
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   P_STATUS_PrintWordSetMsgRight 0x021D6244 thumb ov131
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   P_STATUS_PrintWordSetMsg 0x021D61B8 thumb ov131
 *   P_STA_OAM_CreateBitmapActors 0x021DBAD0 thumb ov131
 *   P_STA_SKILL_SlotTilePos 0x021DC2B8 data a1 ov131
 */
#include "../include/Obj01409.h"
#include "../include/Obj02846.h"
#include "../include/Obj04511.h"
#include "../include/Obj23172.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {void *pixels;u16 width,height,depth,kind;} Bmp;
typedef struct {Bmp *bmp;s16 x,y;u32 resource,value;u8 a,b;u16 c;u32 d;} Descriptor;
typedef struct {u8 x,y;} Pair;
struct MsgBank;
struct U16Vec;
struct Rec;
struct WordSet;
extern const Pair P_STA_SKILL_SlotTilePos[];
extern void *P_STATUS_GetPokePara(u8 *);
extern u32 func_02017E88(void *,u32,u32);
extern u32 WAZA_TOOL_GetParam(u16,u32);
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void P_STATUS_PrintMsg(u8 *,int,int,int,s16,u16);
extern struct WordSet *WORDSET_CreateDefault(u32);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void P_STATUS_PrintWordSetMsgRight(u8 *,int,void *,int,u16,s16,u16);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void P_STATUS_PrintWordSetMsg(u8 *,int,void *,int,s16,s16,u16);
extern u8 *P_STA_OAM_CreateBitmapActors(u8 *a, const u8 *b);
void P_STA_SKILL_InitSlotText(u8 *p,u8 *q,u8 *entry)
{
    Descriptor desc;
    void *mon;
    u32 id,count,value;
    struct MsgBank *bank;
    void *text;
    struct WordSet *first,*second;
    mon=P_STATUS_GetPokePara(p);
    if(entry[0]<4) {
        id=func_02017E88(mon,entry[0]+54,0);
        count=func_02017E88(mon,entry[0]+58,0);
        value=func_02017E88(mon,entry[0]+66,0);
    } else {
        id=((struct Obj23172 *)(*(u8 * *)&((struct Obj02846 *)p)->f8))->f14;
        count=WAZA_TOOL_GetParam(id,5);
        value=count;
    }
    *(Bmp * *)&((struct Obj01409 *)entry)->f10=(Bmp *)BMP_Create(11,4,32,((struct Obj02846 *)p)->f0);
    bank=func_02045B38(0,2,203,((struct Obj02846 *)p)->f0);
    text=func_02045EC0(bank,id);
    PRINTSYS_PrintQueColor(((struct Obj02846 *)p)->f84,*(u32 *)&((struct Obj01409 *)entry)->f10,3,2,(u32)text,((struct Obj02846 *)p)->f80,1088);
    STRBUF_Delete(text);
    MSGDATA_Delete((struct Rec *)bank);
    if(id!=0) {
        P_STATUS_PrintMsg(p,*(int *)&((struct Obj01409 *)entry)->f10,135,13,17,1088);
        first=WORDSET_CreateDefault(((struct Obj02846 *)p)->f0);
        WORDSET_SetSlotNumber(first,0,count,3,1,1);
        P_STATUS_PrintWordSetMsgRight(p,*(int *)&((struct Obj01409 *)entry)->f10,first,136,57,17,1088);
        WORDSET_DeleteStrbufED04(first);
        P_STATUS_PrintMsg(p,*(int *)&((struct Obj01409 *)entry)->f10,117,57,17,1088);
        second=WORDSET_CreateDefault(((struct Obj02846 *)p)->f0);
        WORDSET_SetSlotNumber(second,0,value,3,1,1);
        P_STATUS_PrintWordSetMsg(p,*(int *)&((struct Obj01409 *)entry)->f10,second,141,61,17,1088);
        WORDSET_DeleteStrbufED04(second);
    } else {
        P_STATUS_PrintMsg(p,*(int *)&((struct Obj01409 *)entry)->f10,153,49,17,1088);
    }
    desc.x=(*(const u8 *)((u32)&P_STA_SKILL_SlotTilePos[0].x+(u32)entry[0]*2U)+5)*8;
    desc.y=*(const u8 *)((u32)&P_STA_SKILL_SlotTilePos[0].y+(u32)entry[0]*2U)*8;
    desc.resource=*(u32 *)&((struct Obj02846 *)p)->fB8;
    desc.value=0;
    desc.a=6;
    desc.b=0;
    desc.c=0;
    desc.d=0;
    desc.bmp=*(Bmp * *)&((struct Obj01409 *)entry)->f10;
    *(u8 * *)&((struct Obj01409 *)entry)->f14=P_STA_OAM_CreateBitmapActors(*(u8 * *)&((struct Obj04511 *)q)->fA4,(const u8 *)(&desc));
    ((struct Obj01409 *)entry)->f4=1;
}
