/*
 * function: func_021D6D18
 * address: 0x021D6D18
 * packet: pkt_ov131_021D6D18
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: owner matched sources establish all prototypes. 0201EE0C
 *   keeps sixth argument 2 visibly loaded to outgoing stack by caller,
 *   despite legacy callee source's five-argument declaration.
 * semantics: full-word payload casts preserve target pointer bits; no
 *   selector bounds assumed and no arithmetic on external results.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj00436.h"
#include "../include/Obj01546.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02018438(void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
void func_021D6D18(u8 *p,u8 *q,void *mon)
{
    void *ws,*buf,*name,*text;
    ws=func_0201EC64(((struct Obj00436 *)p)->f0);
    buf=func_020457B0(32,((struct Obj00436 *)p)->f0);
    name=func_020457B0(32,((struct Obj00436 *)p)->f0);
    func_02017E88(mon,115,(u32)name);
    func_0201EE0C(ws,0,name,0,1,2);
    text=func_02045EC0(((struct Obj00436 *)p)->f7C,0);
    func_0201F250(ws,buf,text);
    func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),25,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    func_02045808(name);func_02045808(text);func_02045808(buf);func_0201ED04(ws);
    if(((struct Obj00436 *)p)->f38==0 && func_02017E88(mon,173,0)==1){
        u32 form=func_02017E88(mon,110,0);
        if(form==0){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,1);
            func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,5312);
            func_02045808(buf);
        }else if(form==1){
            buf=func_02045EC0(((struct Obj00436 *)p)->f7C,2);
            func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),89,1,(u32)buf,((struct Obj00436 *)p)->f80,3200);
            func_02045808(buf);
        }
    }
    if(((struct Obj00436 *)p)->f38==0){
        void *text2;
        ws=func_0201EC64(((struct Obj00436 *)p)->f0);buf=func_020457B0(16,((struct Obj00436 *)p)->f0);
        func_0201EFA4(ws,0,func_02018438(mon),3,0,1);
        text2=func_02045EC0(((struct Obj00436 *)p)->f7C,3);
        func_0201F250(ws,buf,text2);
        func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f18),9,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        func_02045808(text2);func_02045808(buf);func_0201ED04(ws);
    }
    buf=func_02045EC0(((struct Obj00436 *)p)->f7C,4);
    func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f1C),10,1,(u32)buf,((struct Obj00436 *)p)->f80,1088);
    func_02045808(buf);
    {
        void *text3;
        ws=func_0201EC64(((struct Obj00436 *)p)->f0);buf=func_020457B0(16,((struct Obj00436 *)p)->f0);
        func_0201EF40(ws,0,func_02017E88(mon,6,0));
        text3=func_02045EC0(((struct Obj00436 *)p)->f7C,5);
        func_0201F250(ws,buf,text3);
        func_0201C724(((struct Obj00436 *)p)->f84,(u32)func_02045770(((struct Obj01546 *)q)->f1C),6,17,(u32)buf,((struct Obj00436 *)p)->f80,1088);
        func_02045808(text3);func_02045808(buf);func_0201ED04(ws);
    }
}
