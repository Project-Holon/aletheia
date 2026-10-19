/*
 * function: P_STA_SKILL_PrintStats
 * address: 0x021DA0B0
 * packet: pkt_ov131_021DA0B0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantics: full-word results retained; only explicit u8 call arguments
 * narrow. No signed arithmetic or caller-domain assumptions.
 * prototype: 618C final stack argument is full u32 here: original stores
 * B6D0 result directly at 021DA182, with no u16 truncation; its body reads
 * only low 16 bits at 021D61A6. Narrow extern adds five absent shift pairs.
 * symbols:
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   P_STATUS_PrintMsgToWin 0x021D618C thumb ov131
 *   P_STATUS_PrintWordSetMsgRightToWin 0x021D62B4 thumb ov131
 *   P_STA_SKILL_GetNatureStatColor 0x021DB6D0 thumb ov131
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 */
#include "../include/Obj00112.h"
#include "../include/Obj01061.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int P_STATUS_GetPokeParaSource(char *p);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void P_STATUS_PrintMsgToWin(u8 *,void *,int,int,s16,u32);
extern void P_STATUS_PrintWordSetMsgRightToWin(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
extern int P_STA_SKILL_GetNatureStatColor(u32 a, u32 b, unsigned char c, u32 d);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void P_STA_SKILL_PrintStats(u8 *a,u8 *p)
{
    void *data;
    u32 selected;
    int one;
    void *o1,*o2,*o3,*o4,*o5,*o6,*o7;
    u32 value;
    void *t1,*t2,*str;
    data=(void *)P_STATUS_GetPokeParaSource((char *)a);
    selected=POKE_TOOL_GetPartyValue(data,112,0);
    one=1;
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f5C,110,25,one,15424);
    o1=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o1,0,POKE_TOOL_GetPartyValue(data,160,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o1,119,89,one,1088);
    WORDSET_Delete(o1);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f5C,117,93,one,1088);
    o2=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o2,0,POKE_TOOL_GetPartyValue(data,161,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o2,118,121,one,1088);
    WORDSET_Delete(o2);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f64,111,one,one,P_STA_SKILL_GetNatureStatColor((u32)a,(u32)p,selected,one));
    o3=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o3,0,POKE_TOOL_GetPartyValue(data,162,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f64),o3,120,105,one,1088);
    WORDSET_Delete(o3);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f68,112,one,one,P_STA_SKILL_GetNatureStatColor((u32)a,(u32)p,selected,2));
    o4=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o4,0,POKE_TOOL_GetPartyValue(data,163,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f68),o4,121,105,one,1088);
    WORDSET_Delete(o4);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f6C,113,one,one,P_STA_SKILL_GetNatureStatColor((u32)a,(u32)p,selected,3));
    o5=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o5,0,POKE_TOOL_GetPartyValue(data,165,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f6C),o5,122,105,one,1088);
    WORDSET_Delete(o5);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f70,114,one,one,P_STA_SKILL_GetNatureStatColor((u32)a,(u32)p,selected,4));
    o6=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o6,0,POKE_TOOL_GetPartyValue(data,166,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f70),o6,123,105,one,1088);
    WORDSET_Delete(o6);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f74,115,one,one,P_STA_SKILL_GetNatureStatColor((u32)a,(u32)p,selected,5));
    o7=WORDSET_CreateDefault(((struct Obj00112 *)a)->f0);
    WORDSET_SetSlotNumber(o7,0,POKE_TOOL_GetPartyValue(data,164,0),3,one,one);
    P_STATUS_PrintWordSetMsgRightToWin(a,(unsigned int)(((struct Obj01061 *)p)->f74),o7,124,105,one,1088);
    WORDSET_Delete(o7);
    P_STATUS_PrintMsgToWin(a,((struct Obj01061 *)p)->f78,116,5,one,15424);
    value=POKE_TOOL_GetPartyValue(data,10,0);
    t1=func_02045B38(0,2,183,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t1,value);
    PRINTSYS_PrintQueColor(((struct Obj00112 *)a)->f84,(int)BMP_WIN_GetBmp(((struct Obj01061 *)p)->f78),5,17,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(t1);
    t2=func_02045B38(0,2,182,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t2,value);
    PRINTSYS_PrintQueColor(((struct Obj00112 *)a)->f84,(int)BMP_WIN_GetBmp(((struct Obj01061 *)p)->f78),65,one,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(t2);
    ((struct Obj01061 *)p)->f4=one;
}
