/*
 * function: func_021BF264
 * address: 0x021BF264
 * packet: pkt_ov217_021BF264
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF910 0x021BF910 thumb ov217
 *   func_021C0FF8 0x021C0FF8 thumb ov217
 *   func_021C0F78 0x021C0F78 thumb ov217
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj00021.h"
typedef unsigned short u16;
struct MsgBank; struct U16Vec; struct WordSet;
typedef unsigned int u32;
extern u32 func_021BF810(void *p);
extern unsigned func_021BF910(char *);
typedef unsigned char  u8;
extern void func_021C0FF8(u8 *p, int visible);
extern unsigned func_021C0F78(unsigned,struct U16Vec *);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern struct U16Vec *func_020457B0(unsigned,unsigned);
extern void func_02045808(struct U16Vec *);
extern void func_0201EE0C(struct WordSet *,unsigned,const void *,unsigned,unsigned,unsigned);
extern void func_0201F250(struct WordSet *,void *,void *);
void func_021BF264(char *p)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (((struct Obj00021 *)p)->f3C8==0 || func_021BF810(p)==0) {
        func_021C0FF8((u8 *)(((struct Obj00021 *)p)->f358),0);
        return;
    }
    index=func_021BF910(p);
    a=func_02045EC0(*(struct MsgBank * *)&((struct Obj00021 *)p)->fC,14);
    b=func_02045EC0(*(struct MsgBank * *)&((struct Obj00021 *)p)->f14,index);
    buf=func_020457B0(128,((struct Obj00021 *)p)->f4);
    func_0201EE0C(*(struct WordSet * *)&((struct Obj00021 *)p)->f18,0,b,0,1,2);
    func_0201F250(*(struct WordSet * *)&((struct Obj00021 *)p)->f18,buf,a);
    func_021C0FF8((u8 *)(((struct Obj00021 *)p)->f358),1);
    func_021C0F78(((struct Obj00021 *)p)->f358,buf);
    func_02045808(a);
    func_02045808(buf);
    func_02045808(b);
}
