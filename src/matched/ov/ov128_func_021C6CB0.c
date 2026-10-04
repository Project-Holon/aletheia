/*
 * function: func_021C6CB0
 * address: 0x021C6CB0
 * packet: pkt_ov128_021C6CB0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: 0204B294 returns the handle read in r0; heap is not truncated.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021CA800 0x021CA800 data a2
 *   d_021CA810 0x021CA810 data a2
 *   d_021CA818 0x021CA818 data a2
 */
#include "../include/Obj02481.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct {s16 x,y,z;u8 a,b;} Point;
extern const Point d_021CA800[];
extern const Point d_021CA810;
extern const Point d_021CA818;
extern void *func_0204B294(u32,u32,u32,u32,const Point *,u16,u32);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021C6CB0(char *p,int heap)
{
    int a,b,c,d,e,f,i;
    char *q;
    void *handle;
    a=0x138;a=0x148;
    b=0x138;b=0x150;
    c=0x138;c=0x158;
    d=0x138;d=0x15c;
    e=0x138;e=0x15c;
    f=0x138;f=0x15c;
    for(i=0;i<2;i++) {
        q=p+i*4;
        *(void **)(q+d)=func_0204B294(((struct Obj02481 *)p)->f138,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&d_021CA800[i],0,heap);
        func_0204B92C(*(void **)(q+e),1);
        func_0204B3DC(*(void **)(q+f),0);
    }
    handle=func_0204B294(((struct Obj02481 *)p)->f138,((struct Obj02481 *)p)->f148,((struct Obj02481 *)p)->f150,((struct Obj02481 *)p)->f158,&d_021CA810,0,heap);
    ((struct Obj02481 *)p)->f164=handle;
    func_0204B3DC(handle,1);
    handle=func_0204B294(((struct Obj02481 *)p)->f138,((struct Obj02481 *)p)->f148,((struct Obj02481 *)p)->f150,((struct Obj02481 *)p)->f158,&d_021CA818,0,heap);
    ((struct Obj02481 *)p)->f168=handle;
    func_0204B3DC(handle,1);
}
