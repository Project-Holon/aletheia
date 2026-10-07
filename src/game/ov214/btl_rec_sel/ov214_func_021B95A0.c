/*
 * function: func_021B95A0
 * packet: pkt_ov214_021B95A0
 * checks: 1 callee own bodies/forwarders and original register setup rederived; 2 ov214 neighbours read; 3 const object unchanged in prior run, mutable pointee conversions prohibit const; 4 shared-tail idiom gives MATCH after each incoming arm repeats the call; 5 directory/neighbours refreshed.
 * retry: safe temporaries after the common label stayed DIFF67; repeated branch calls gave MATCH504; callback 021B9F18 separately matched and verified.
 * address: 0x021B95A0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203159C own source returns void, but its ARM body leaves the allocator result in r0 after str r0,[r4,#14]; this caller preserves that live return as its context.
 * symbols:
 * func_02034AC4 0x02034AC4 arm
 * func_0203064C 0x0203064C arm
 * func_0203159C 0x0203159C arm
 * func_02082BCC 0x02082BCC arm
 * func_02040588 0x02040588 arm
 * func_021BB178 0x021BB178 thumb ov214
 * func_0201D7EC 0x0201D7EC thumb
 * func_0201C440 0x0201C440 thumb
 * func_0201292C 0x0201292C thumb
 * func_02007F68 0x02007F68 thumb
 * func_020056A0 0x020056A0 thumb
 * func_021B9F18 0x021B9F18 thumb ov214
 * func_02045B38 0x02045B38 arm
 * func_021BABF4 0x021BABF4 thumb ov214
 * func_021BAD08 0x021BAD08 thumb ov214
 * func_021BAD14 0x021BAD14 thumb ov214
 * func_021B9F24 0x021B9F24 thumb ov214
 * func_021BA074 0x021BA074 thumb ov214
 * func_021BA2F4 0x021BA2F4 thumb ov214
 * func_021BA3C4 0x021BA3C4 thumb ov214
 * func_0204047C 0x0204047C arm
 * func_02040EBC 0x02040EBC arm
 * func_0204E720 0x0204E720 arm
 * func_021B9EB8 0x021B9EB8 thumb ov214
 * func_021B9EF0 0x021B9EF0 thumb ov214
 * func_021BA6A0 0x021BA6A0 thumb ov214
 * func_021BAC58 0x021BAC58 thumb ov214
 * func_021BAE4C 0x021BAE4C thumb ov214
 * func_021BAE9C 0x021BAE9C thumb ov214
 * func_021BAE88 0x021BAE88 thumb ov214
 * func_0203D34C 0x0203D34C arm
 * ov67_id 0x00000043 data a1
 */
#include "../../../matched/include/Obj00182.h"
#include "../../../matched/include/Obj06705.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 ov67_id[];
extern int func_02034AC4(int);
extern void func_0203064C(u32,u32,u32);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void*,u32,u32);
struct C;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32,u32);
extern void func_0204E720(u32,int,int,int);
extern char *func_021BB178(u32,u32);
struct BigObj;
struct GfFont;
struct MsgBank;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void*);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_020056A0(void(*)(void*),void*,u32);
extern void func_021B9F18(void *unused, char *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021BABF4(int,char*);
extern void func_021BAD08(void*,char*);
extern void func_021BAD14(void **a, char *p);
extern void func_021B9F24(void *unused, struct C *p);
extern void func_021BA074(int,char*);
extern void func_021BA2F4(int,char*);
extern void func_021BA3C4(int,char*);
extern void func_021B9EB8(char*,int,char*,int,int,int,int,int,int);
extern void func_021B9EF0(void*,char*,u32,u32,u32);
extern void func_021BA6A0(void*,char*,u32);
extern void func_021BAC58(int unused, u8 *p);
extern void func_021BAE4C(int unused, u8 *p);
extern void func_021BAE9C(int,char*);
extern void func_021BAE88(int unused, u8 *p);
extern void func_0203D34C(u32,u32);
int func_021B95A0(void *manager,char *state,char * const obj)
{
    char *p;
    u8 i;
    enum {K=3} k;
    func_02034AC4((int)ov67_id);
    func_0203064C(1,0x75,0x50000);
    p=func_0203159C(manager,0x2f0,0x75);
    func_02082BCC(p,0,0x2f0);
    ((struct Obj00182 *)p)->f0=0x75;
    for(i=0;i<=7;i++)func_02040588(i,0);
    *(void* *)&((struct Obj00182 *)p)->f4=func_021BB178(1,((struct Obj00182 *)p)->f0);
    *(void* *)&((struct Obj00182 *)p)->f8=func_0201D7EC(23,0,0,0,((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->fC=func_0201C440((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f10=func_0201C440((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f14=func_0201C440((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f18=func_0201C440((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f50=func_02007F68(func_0201292C(*(void* *)&((struct Obj06705 *)obj)->f0),0x1d1,1,((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f54=0;
    ((struct Obj00182 *)p)->f4C=func_020056A0((void (*)(void *))func_021B9F18,p,1);
    *(void* *)&((struct Obj00182 *)p)->f58=func_02045B38(0,2,19,((struct Obj00182 *)p)->f0);
    func_021BABF4((int)obj,p);func_021BAD08(obj,p);func_021BAD14((void **)obj,p);
    func_021B9F24(obj,(struct C *)p);func_021BA074((int)obj,p);func_021BA2F4((int)obj,p);func_021BA3C4((int)obj,p);
    func_0204047C(2,2);k=K;func_0204047C(k,1);func_0204047C(1,0);
    func_02040588(2,1);func_02040588(3,1);func_02040588(1,1);
    func_02040EBC(0,0);func_02040EBC(4,0);func_0204E720(3,16,16,0);
    if(((struct Obj00182 *)p)->f50){
        if(((struct Obj06705 *)obj)->fC){
          if(((struct Obj06705 *)obj)->f4){
            func_021B9EB8(state,(int)obj,p,2,k,16,0,2,0);
            func_021B9EF0(obj,p,5,0,1);func_021BA6A0(obj,p,60);
            if(((struct Obj06705 *)obj)->f8)func_021BAC58((int)obj,(u8 *)p);
            ((struct Obj00182 *)p)->fB4=1;
          }else {func_021B9EB8(state,(int)obj,p,15,k,16,0,2,0);}
        }else {common:func_021B9EB8(state,(int)obj,p,15,k,16,0,2,0);}
    }else if(((struct Obj06705 *)obj)->f8){func_021B9EB8(state,(int)obj,p,15,k,16,0,2,0);}
    else ((struct Obj00182 *)p)->f54=1;
    func_021BAE4C((int)obj,(u8 *)p);func_021BAE9C((int)obj,p);func_021BAE88((int)obj,(u8 *)p);
    func_0203D34C(1,((struct Obj00182 *)p)->f0);
    return 1;
}
