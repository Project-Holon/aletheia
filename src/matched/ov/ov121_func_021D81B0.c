/*
 * function: func_021D81B0
 * address: 0x021D81B0
 * packet: pkt_ov121_021D81B0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   func_021D83CC 0x021D83CC thumb ov121
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045808 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_0204989C 0x0204989C arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_021DA4DC 0x021DA4DC thumb ov121
 *   func_0207D63C 0x0207D63C arm
 *   func_021D6CEC 0x021D6CEC thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 w[9]; s16 h[7]; u16 pad; void *callback,*arg,*result; } Desc;
extern void func_02082BCC(void *,int,int);
struct U16Vec;
extern void *func_021D6C58(u8 *p, int i);
extern void func_021D83CC(char *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *,const u16 *,u32);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,int,int,int,int,int);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_0204989C(int,int,int,int,int,int,int);
extern void func_02049238(void *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void func_02040588(u32 which, unsigned char enable);
extern void *func_021DA4DC(Desc *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D6CEC(u8 *p);
void func_021D81B0(u8 *p,u32 which,int heap)
{
    Desc d;
    void *archive;
    int i;
    if(((struct Obj00326 *)p)->f270) return;
    func_02082BCC(&d,0,64);
    d.w[1]=((struct Obj00326 *)p)->f398;
    d.w[2]=((struct Obj00326 *)p)->f39C;
    d.w[3]=(u32)func_021D6C58(p+660,0);
    d.h[0]=1;
    d.h[1]=15;
    d.h[2]=2;
    d.h[3]=4;
    d.callback=func_021D83CC;
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
        d.w[4]=(u32)func_020457B0(37,heap);
        func_02045994((struct Strbuf *)d.w[4],(const u16 *)(p+1068),37);
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
    func_02049238(archive);
    func_020413B0(2,0,0,32,24,4);
    func_020409B4(2);
    func_02040588(2,1);
    ((struct Obj00326 *)p)->f270=func_021DA4DC(&d,heap);
    if(!d.w[0]) {
        for(i=0;i<4;i++) {
            if(d.w[4+i]) func_02045808((void *)d.w[4+i]);
        }
    }
    func_0207D63C((void *)0x04000050,4,24,15,3);
    func_021D6CEC(p+660);
}
