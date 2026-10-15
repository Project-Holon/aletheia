/*
 * function: MYSTERY_CreateCardMenu
 * address: 0x021D81B0
 * packet: pkt_ov121_021D81B0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_GetClactActor 0x021D6C58 thumb ov121
 *   MYSTERY_CardMenuCallback 0x021D83CC thumb ov121
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_0204989C 0x0204989C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   MYSTERY_UTIL_CreateDetailWindow 0x021DA4DC thumb ov121
 *   func_0207D63C 0x0207D63C arm
 *   MYSTERY_ResetActorAngle 0x021D6CEC thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 w[9]; s16 h[7]; u16 pad; void *callback,*arg,*result; } Desc;
extern void MI_CpuFill8(void *,int,int);
struct U16Vec;
extern void *MYSTERY_GetClactActor(u8 *p, int i);
extern void MYSTERY_CardMenuCallback(char *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *,const u16 *,u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,int,int,int,int,int);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_0204989C(int,int,int,int,int,int,int);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *MYSTERY_UTIL_CreateDetailWindow(Desc *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void MYSTERY_ResetActorAngle(u8 *p);
void MYSTERY_CreateCardMenu(u8 *p,u32 which,int heap)
{
    Desc d;
    void *archive;
    int i;
    if(((struct Obj00326 *)p)->f270) return;
    MI_CpuFill8(&d,0,64);
    d.w[1]=((struct Obj00326 *)p)->f398;
    d.w[2]=((struct Obj00326 *)p)->f39C;
    d.w[3]=(u32)MYSTERY_GetClactActor(p+660,0);
    d.h[0]=1;
    d.h[1]=15;
    d.h[2]=2;
    d.h[3]=4;
    d.callback=MYSTERY_CardMenuCallback;
    d.arg=p;
    d.h[4]=0;
    d.h[5]=0;
    d.h[6]=0;
    d.result=p+628+which*4;
    switch(which) {
    case 0:
        d.w[0]=*(u32 *)&((struct Obj00326 *)p)->f3A4;
        d.w[4]=80; d.w[5]=81; d.w[6]=131; d.w[7]=82; d.w[8]=4;
        break;
    case 1:
        d.w[0]=*(u32 *)&((struct Obj00326 *)p)->f3A4;
        d.w[4]=87; d.w[5]=88; d.w[6]=89; d.w[7]=90; d.w[8]=4;
        break;
    case 2:
        d.w[0]=0;
        d.w[4]=(u32)STRBUF_Create(37,heap);
        STRBUF_SetStringN((struct Strbuf *)d.w[4],(const u16 *)(p+1068),37);
        d.w[8]=1;
        d.h[4]=-1;
        d.h[5]=-2;
        d.h[6]=10;
        break;
    case 3:
        d.w[0]=*(u32 *)&((struct Obj00326 *)p)->f3A4;
        d.w[4]=127; d.w[5]=128; d.w[6]=129; d.w[7]=130; d.w[8]=4;
        break;
    }
    archive=func_020490F4(34,heap);
    func_02049B68(archive,6,0,0,160,heap);
    func_02049658(archive,15,2,0,0,0,heap);
    if(which==2) func_0204989C(34,30,2,0,0,0,heap);
    else func_0204989C(34,29,2,0,0,0,heap);
    ARC_TOOL_DeleteHandle(archive);
    BG_SYS_FillTileMap(2,0,0,32,24,4);
    BG_SYS_PushTile(2);
    func_02040588(2,1);
    ((struct Obj00326 *)p)->f270=MYSTERY_UTIL_CreateDetailWindow(&d,heap);
    if(!d.w[0]) {
        for(i=0;i<4;i++) {
            if(d.w[4+i]) STRBUF_Delete((void *)d.w[4+i]);
        }
    }
    func_0207D63C((void *)0x04000050,4,24,15,3);
    MYSTERY_ResetActorAngle(p+660);
}
