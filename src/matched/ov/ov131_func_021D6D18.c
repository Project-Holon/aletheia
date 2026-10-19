/*
 * function: P_STA_SUB_PrintWindows
 * address: 0x021D6D18
 * packet: pkt_ov131_021D6D18
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: owner matched sources establish all prototypes. 0201EE0C
 *   keeps sixth argument 2 visibly loaded to outgoing stack by caller,
 *   despite legacy callee source's five-argument declaration.
 * semantics: full-word payload casts preserve target pointer bits; no
 *   selector bounds assumed and no arithmetic on external results.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STRBUF_Delete 0x02045808 arm
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb  arm9
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */
#include "../include/Obj00436.h"
#include "../include/Obj01546.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 POKE_TOOL_GetBoxValue(void *,u32,u32);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 POKE_TOOL_CalcBoxLevel(void *);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
void P_STA_SUB_PrintWindows(u8 *p,u8 *q,void *mon)
{
    void *ws,*buf,*name,*text;
    ws=WORDSET_CreateDefault(((struct Obj00436 *)p)->f0);
    buf=STRBUF_Create(32,((struct Obj00436 *)p)->f0);
    name=STRBUF_Create(32,((struct Obj00436 *)p)->f0);
    POKE_TOOL_GetBoxValue(mon,115,(u32)name);
    WORDSET_SetSlotTag(ws,0,name,0,1,2);
    text=func_02045EC0(((struct Obj00436 *)p)->f7C,0);
    WORDSET_CopyTaggedText(ws,buf,text);
    PRINTSYS_PrintQueColor(((struct Obj00436 *)p)->f84,(u32)BMP_WIN_GetBmp(((struct Obj01546 *)q)->f18),25,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    STRBUF_Delete(name);STRBUF_Delete(text);STRBUF_Delete(buf);WORDSET_Delete(ws);
    if(((struct Obj00436 *)p)->f38==0 && POKE_TOOL_GetBoxValue(mon,173,0)==1){
        u32 form=POKE_TOOL_GetBoxValue(mon,110,0);
        if(form==0){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,1);
            PRINTSYS_PrintQueColor(((struct Obj00436 *)p)->f84,(u32)BMP_WIN_GetBmp(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,5312);
            STRBUF_Delete(buf);
        }else if(form==1){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,2);
            PRINTSYS_PrintQueColor(((struct Obj00436 *)p)->f84,(u32)BMP_WIN_GetBmp(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,3200);
            STRBUF_Delete(buf);
        }
    }
    if(((struct Obj00436 *)p)->f38==0){
        void *text2;
        ws=WORDSET_CreateDefault(((struct Obj00436 *)p)->f0);buf=STRBUF_Create(16,((struct Obj00436 *)p)->f0);
        WORDSET_SetSlotNumber(ws,0,POKE_TOOL_CalcBoxLevel(mon),3,0,1);
        text2=func_02045EC0(((struct Obj00436 *)p)->f7C,3);
        WORDSET_CopyTaggedText(ws,buf,text2);
        PRINTSYS_PrintQueColor(((struct Obj00436 *)p)->f84,(u32)BMP_WIN_GetBmp(((struct Obj01546 *)q)->f18),9,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        STRBUF_Delete(text2);STRBUF_Delete(buf);WORDSET_Delete(ws);
    }
    buf=func_02045EC0(((struct Obj00436 *)p)->f7C,4);
    PRINTSYS_PrintQueColor(((struct Obj00436 *)p)->f84,(u32)BMP_WIN_GetBmp(((struct Obj01546 *)q)->f1C),10,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    STRBUF_Delete(buf);
    {
        void *text3;
        ws=WORDSET_CreateDefault(((struct Obj00436 *)p)->f0);buf=STRBUF_Create(16,((struct Obj00436 *)p)->f0);
        WORDSET_SetSlotFromMsg36(ws,0,POKE_TOOL_GetBoxValue(mon,6,0));
        text3=func_02045EC0(((struct Obj00436 *)p)->f7C,5);
        WORDSET_CopyTaggedText(ws,buf,text3);
        PRINTSYS_PrintQueColor(((struct Obj00436 *)p)->f84,(u32)BMP_WIN_GetBmp(((struct Obj01546 *)q)->f1C),6,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        STRBUF_Delete(text3);STRBUF_Delete(buf);WORDSET_Delete(ws);
    }
}
