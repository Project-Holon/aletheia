/*
 * function: func_021BC9A8
 * address: 0x021BC9A8
 * packet: pkt_ov209_021BC9A8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ov067 is loaded by the same overlay's 021BCC94/021BCD48 path.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0200CA8C 0x0200CA8C thumb
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   STRBUF_Delete 0x02045808 arm
 *   data_021BE7AC 0x021BE7AC data a4
 *   data_020A7370 0x020A7370 data a4
 */
#include "../include/Obj00123.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Template {u8 head[20];u16 count,pad16;u8 index,pad19;u16 start;u32 p1c,p20;void *p24;};
struct Inputs {u32 p0;void *save;u16 pad8,count;u16 *ids;};
struct Context {struct Inputs *in;u8 pad4[0xc2c-4];void *list;u32 padc30;u32 visible;};
extern const struct Template data_021BE7AC;
extern void *data_020A7370;
extern void *func_020490F4(u32 id, u32 heap);
struct Blk37;
struct MsgBank;
struct U16Vec;
extern u16 func_0200CA8C(struct Blk37 *p);
struct S;
struct Tmpl;
extern struct S *FRAME_LIST_Create(struct Tmpl *tmpl, u32 heap);
extern void FRAME_LIST_CopyMapToBuffer(u8 *p, u32 a, u32 b, u32 c, u32 index);
extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021BC9A8(struct Context *p)
{
    struct Template tmpl;
    void *arc,*str;
    u32 species,i;
    arc=func_020490F4(159,0x806b);
    species=func_0200CA8C((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save);
    tmpl=data_021BE7AC;
    tmpl.count=649;tmpl.p24=p;
    for(i=0;i<(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count;i++){
        if(species==(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]){
            if(i>(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count-7){
                tmpl.index=i-((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count-7);
                tmpl.start=i-tmpl.index;
            }else if(i<7){tmpl.index=i;}
            else{tmpl.start=i;}
            break;
        }
    }
    p->list=FRAME_LIST_Create((struct Tmpl *)(&tmpl),107);
    if(p->in->count<7)p->visible=p->in->count;else p->visible=7;
    FRAME_LIST_CopyMapToBuffer(p->list,(u32)arc,66,0,0);
    FRAME_LIST_CopyMapToBuffer(p->list,(u32)arc,67,0,1);
    FRAME_LIST_CopyMapToBuffer(p->list,(u32)arc,68,0,2);
    FRAME_LIST_LoadPalettes(p->list,arc,48,2,3);
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count;i++){
        if(func_0200CED4((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=STRBUF_Clone(str,107);
            STRBUF_Delete(str);
            FRAME_LIST_AddItem(p->list,0,0x20000000|(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }else if(func_0200D064((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=STRBUF_Clone(str,107);
            STRBUF_Delete(str);
            FRAME_LIST_AddItem(p->list,1,0x10000000|(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }else{
            *(void **)((u32)p+i*4+0x4c)=func_02045EC0(((struct Obj00123 *)p)->f3C,7);
            FRAME_LIST_AddItem(p->list,2,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }
    }
}
