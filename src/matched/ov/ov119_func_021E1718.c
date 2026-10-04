/*
 * function: func_021E1718
 * address: 0x021E1718
 * packet: pkt_ov119_021E1718
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 */
#include "../include/Obj00001.h"
typedef signed short s16;
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021E1718(int a,int b,int x,int y,char *p)
{
    int i;
    for(i=0;i<6;i++) {
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),30+i,(void *)(*(int *)&((struct Obj00001 *)p)->f730));
        func_0201C7A4(func_02045770((struct Descriptor *)b),x,y+16*i,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
    }
}
