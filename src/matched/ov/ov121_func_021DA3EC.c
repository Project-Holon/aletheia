/*
 * function: func_021DA3EC
 * address: 0x021DA3EC
 * packet: pkt_ov121_021DA3EC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045838 0x02045838 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D9BE8 0x021D9BE8 thumb ov121
 */
#include "../include/Obj03262.h"
#include "../include/Obj06449.h"
#include "../include/Obj22885.h"
#include "../include/Obj22886.h"
#include "../include/Obj22887.h"
#include "../include/Obj22888.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct { int x,y; } Pair;
struct CharBuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct MsgBank;
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020307B0(void *p);
extern void func_021D9BE8(int,Pair *,void *,void *,int,Pair *);
extern void func_0201C724(void *,void *,s16,s16,void *,int,u16);
void func_021DA3EC(char *p,char *desc,void *dst)
{
    u32 i;
    Pair pos,out;
    void *text=func_020457B0(512,((struct Obj06449 *)p)->f0);
    for(i=0;i<((struct Obj22885 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f4;i++) {
        char *d=desc+i*24;
        if(((struct Obj03262 *)d)->f0) {
            func_02043B5C(*(void **)(p+i*4+8),(u8)(((struct Obj03262 *)d)->f14&31));
            pos.x=((struct Obj03262 *)d)->f10;
            pos.y=((struct Obj03262 *)d)->f12;
            func_021D9BE8(((struct Obj03262 *)d)->fC,&pos,*(void **)(p+i*4+8),text,((struct Obj22886 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,&out);
            if(((struct Obj03262 *)d)->f8) func_02045838(text,(struct U16Vec *)(((struct Obj03262 *)d)->f8));
            else func_02045CAC((struct MsgBank *)(((struct Obj22887 *)(*(char * *)&((struct Obj06449 *)p)->f4))->fC),((struct Obj03262 *)d)->f4,text);
            func_0201C724(dst,*(void **)(p+i*4+8),(s16)out.x,(s16)out.y,text,((struct Obj22888 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,((struct Obj03262 *)d)->f14);
        }
    }
    func_020307B0(text);
}
