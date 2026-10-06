/*
 * function: func_0220B1D4
 * address: 0x0220B1D4
 * packet: pkt_ov197_0220B1D4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj08353.h"
#include "../include/Obj24990.h"
#include "../include/Obj24991.h"
typedef unsigned short u16;
typedef short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 func_02045738(struct Descriptor *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
void func_0220B1D4(char *p,int i,int id,int y,u16 colour)
{
    int handle=*(int *)(p+0x28+i*8);
    int text=(int)func_02045EC0((struct MsgBank *)(((struct Obj08353 *)p)->fC),id);
    int width=func_0201D304((struct StrObj *)text,((struct Obj24990 *)(*(char * *)&((struct Obj08353 *)p)->f0))->f4,0);
    int x=(func_02045738((struct Descriptor *)handle)*8-width)>>1;
    int font=((struct Obj08353 *)p)->f18;
    int surface=(int)func_02045770((struct Descriptor *)*(int *)(p+0x28+i*8));
    func_0201C724((void *)font,(int)surface,(s16)x,(s16)y,(int)text,(int)(((struct Obj24991 *)(*(char * *)&((struct Obj08353 *)p)->f0))->f4),colour);
    (p+i*8)[0x2c]=1;
    func_02045808((struct U16Vec *)text);
}
