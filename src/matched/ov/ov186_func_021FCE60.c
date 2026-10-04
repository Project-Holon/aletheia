/*
 * function: func_021FCE60
 * address: 0x021FCE60
 * packet: pkt_ov186_021FCE60
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bitmap array field retains per-access base additions.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021FCF54 0x021FCF54 thumb ov186
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj00048.h"
typedef struct { char pad[0x8C];int bitmap[1]; } View;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef unsigned char  u8;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021FCF54(int,int,int,int,unsigned short,unsigned short,unsigned short,unsigned short);
void func_021FCE60(char *p,int start)
{
    int i,height;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38)),0);
    for(i=start;i<start+((struct Obj00048 *)p)->f44;i++) {
        if((unsigned)i<((struct Obj00048 *)p)->f4 && ((View *)p)->bitmap[i]) {
            height=((struct Obj00048 *)p)->fE;
            func_021FCF54(((View *)p)->bitmap[i],(int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38),0,0,0,(i-start)*height,((struct Obj00048 *)p)->fA,height);
        }
    }
    func_02045334((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38);
}
