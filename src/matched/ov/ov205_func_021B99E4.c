/*
 * function: func_021B99E4
 * address: 0x021B99E4
 * packet: pkt_ov205_021B99E4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Fourth parameter u16 restores the entry spill and delayed reload;
 *   unsigned moved the spill to +0010 and reloaded it before stack args.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 */
#include "../include/Obj01777.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,unsigned,unsigned,void *,void *,unsigned,void *,unsigned,u16,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F73C(void *,int,int,int);
void func_021B99E4(char *p,unsigned entry,unsigned index,u16 kind)
{
    void *buffer;
    buffer=func_020457B0(1024,((struct Obj01777 *)p)->f0);
    func_02043B5C(func_02045770(((struct Obj01777 *)p)->f1C),15);
    func_02045CAC(((struct Obj01777 *)p)->f14,entry,buffer);
    func_0201F02C(((struct Obj01777 *)p)->f18,0,((struct Obj01777 *)p)->f8);
    func_0201F250(((struct Obj01777 *)p)->f18,((struct Obj01777 *)p)->fC,buffer);
    ((struct Obj01777 *)p)->f20=func_0201CCE4(((struct Obj01777 *)p)->f1C,index,kind,((struct Obj01777 *)p)->fC,((struct Obj01777 *)p)->f10,func_02012FFC(),((struct Obj01777 *)p)->f24,0,((struct Obj01777 *)p)->f0,3855);
    func_02045808(buffer);
    func_0201F73C(((struct Obj01777 *)p)->f1C,2,1,12);
}
