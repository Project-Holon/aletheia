/*
 * function: UN_SELECT_CreateFrameList
 * address: 0x021B9D48
 * packet: pkt_ov218_021B9D48
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BB060 0x021BB060 data ov218 a4
 *   template_021BB060 0x021BB060 data ov218 a4
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj02556.h"
#include "../include/G_Template.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Template Template;
extern struct Template d_021BB060;
extern struct Template template_021BB060;
extern int tbl_021BAC80[];
struct S;
struct Tmpl;
extern struct S *FRAME_LIST_Create(struct Tmpl *tmpl, u32 heap);
extern void FRAME_LIST_CopyMapToBuffer(u8 *p, u32 a, u32 b, u32 c, u32 index);
struct MsgBank;
struct Rec;
extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
void UN_SELECT_CreateFrameList(char *p)
{
    int i,value;
    u32 offset;
    int disabled;
    void *archive,*bank;
    d_021BB060.owner=p;
    value=**(u8 * *)&((struct Obj02556 *)p)->f20;
    if(value<=1)value=2;
    for(i=0;i<130;i++) {
        if(131-i==value) {
            if(i>126) {
                d_021BB060.page=i-126;
                d_021BB060.start=i-d_021BB060.page;
            } else d_021BB060.start=i;
        }
    }
    ((struct Obj02556 *)p)->f2C=FRAME_LIST_Create((struct Tmpl *)(&template_021BB060),((struct Obj02556 *)p)->f0);
    archive=func_020490F4(193,((struct Obj02556 *)p)->f0);
    FRAME_LIST_CopyMapToBuffer(((struct Obj02556 *)p)->f2C,(u32)archive,3,0,0);
    FRAME_LIST_CopyMapToBuffer(((struct Obj02556 *)p)->f2C,(u32)archive,4,0,1);
    FRAME_LIST_LoadPalettes(((struct Obj02556 *)p)->f2C,archive,1,2,3);
    ARC_TOOL_DeleteHandle(archive);
    bank=func_02045B38(0,2,229,((struct Obj02556 *)p)->f0);
    for(i=0;i<130;i++) {
        offset=i*4;
        disabled=1;
        if(*(u32 *)(p+0x34+offset)==1)disabled=0;
        FRAME_LIST_AddItem(((struct Obj02556 *)p)->f2C,disabled,i);
        if(disabled==0)
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,*(int *)((char *)tbl_021BAC80+offset));
        else
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,238);
    }
    MSGDATA_Delete(bank);
}
