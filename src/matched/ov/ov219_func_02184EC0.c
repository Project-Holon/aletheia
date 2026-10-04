/*
 * function: func_02184EC0
 * address: 0x02184EC0
 * packet: pkt_ov219_02184EC0
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: retain 1F878 fifth u16 stack argument loaded by this caller, absent from legacy callee declaration; 1FF30 heap explicitly narrowed in caller.
 * symbols:
 *   func_02184968 0x02184968 thumb ov219
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201DC80 0x0201DC80 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02184EAC 0x02184EAC thumb ov219
 */
#include "../include/Obj00927.h"
#include "../include/Obj14777.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Src {u32 w[13];};
struct Descriptor;struct Font;struct Obj;struct Slot;
typedef struct {u32 bank,id;} Entry;
typedef unsigned char  u8;
extern u32 func_02184968(const u8 *p, int flag);
extern void *func_0201F81C(u32,u32);
extern void func_0201F878(struct Slot *,u32,u32,u32,u16);
extern u32 func_0201DC80(struct Font *);
extern struct Obj *func_0201FF30(struct Src *,u16,u16,u16);
extern void func_02020CF8(struct Obj *,int);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045334(struct Descriptor *);
extern void func_02184EAC(int,int,int);
void func_02184EC0(char *p,const unsigned char *descriptor,const struct Src *source,const Entry *entries)
{
    int i;
    struct Src cfg;
    *(struct Descriptor * *)&((struct Obj00927 *)p)->fC018=(struct Descriptor *)func_02184968(descriptor,1);
    ((struct Obj00927 *)p)->fC050=func_0201F81C(((struct Obj14777 *)source)->f10,((struct Obj00927 *)p)->f0);
    for(i=0;i<((struct Obj14777 *)source)->f10;i++)
        func_0201F878(*(struct Slot * *)&((struct Obj00927 *)p)->fC050,((struct Obj00927 *)p)->fC070,entries[i].bank,entries[i].id,((struct Obj00927 *)p)->f0);
    ((struct Obj00927 *)p)->fC078=((struct Obj00927 *)p)->fC018;
    p[0xC07C]=0;
    cfg=*source;
    cfg.w[0]=*(u32 *)&((struct Obj00927 *)p)->fC050;
    cfg.w[3]=*(u32 *)(p+0xC018);
    cfg.w[1]=(u32)func_02184EAC;
    *(u16 *)((char *)&cfg+32)=12;
    *(u16 *)((char *)&cfg+34)=func_0201DC80(*(struct Font * *)&((struct Obj00927 *)p)->fC06C);
    cfg.w[9]=((struct Obj00927 *)p)->fC070;
    cfg.w[10]=(u32)(p+0xC078);
    cfg.w[11]=((struct Obj00927 *)p)->fC080;
    cfg.w[12]=*(u32 *)&((struct Obj00927 *)p)->fC06C;
    *(struct Obj * *)&((struct Obj00927 *)p)->fC04C=func_0201FF30(&cfg,0,0,((struct Obj00927 *)p)->f0);
    func_02020CF8(*(struct Obj * *)&((struct Obj00927 *)p)->fC04C,((struct Obj00927 *)p)->f0);
    func_0201F73C(((struct Obj00927 *)p)->fC018,0,34,7);
    func_02045334(*(struct Descriptor **)(p+0xC018));
}
