/*
 * file:     btl_rec_sel_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B9798, func_021B9834, func_021B9EB8, func_021B9ED4, func_021B9EF0, func_021B9EFC, func_021B9F10, func_021B9F18, func_021B9F24, func_021BA018, func_021BA058, func_021BA074, func_021BA0B0, func_021BA0DC, func_021BA108, func_021BA16C, func_021BA190, func_021BA254, func_021BA2B8, func_021BA2F4, func_021BA39C, func_021BA3A0, func_021BA3C4, func_021BA43C, func_021BA45C, func_021BA4E8, func_021BA5C8, func_021BA650, func_021BA6A0
 * address:  0x021B95A0
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02040588 0x02040588 arm
 *   func_021BB178 0x021BB178 thumb ov214
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_021BABF4 0x021BABF4 thumb ov214
 *   func_021BAD08 0x021BAD08 thumb ov214
 *   func_021BAD14 0x021BAD14 thumb ov214
 *   func_0204047C 0x0204047C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0204E720 0x0204E720 arm
 *   func_021BAC58 0x021BAC58 thumb ov214
 *   func_021BAE4C 0x021BAE4C thumb ov214
 *   func_021BAE9C 0x021BAE9C thumb ov214
 *   func_021BAE88 0x021BAE88 thumb ov214
 *   func_0203D34C 0x0203D34C arm
 *   ov67_id 0x00000043 data a1
 *   func_021BAF30 0x021BAF30 thumb ov214
 *   func_021BAE10 0x021BAE10 thumb ov214
 *   func_021BAC3C 0x021BAC3C thumb ov214
 *   func_02045C04 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BB220 0x021BB220 thumb ov214
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   func_02012EBC 0x02012EBC thumb
 *   func_020362DC 0x020362DC arm
 *   func_0204E804 0x0204E804 arm
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_0200B5CC 0x0200B5CC thumb
 *   func_021BA6F0 0x021BA6F0 thumb ov214
 *   func_0200B5A4 0x0200B5A4 thumb
 *   func_0200B934 0x0200B934 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_021BABB8 0x021BABB8 thumb ov214
 *   func_021BA8DC 0x021BA8DC thumb ov214
 *   func_021BAC90 0x021BAC90 thumb ov214
 *   func_021BACCC 0x021BACCC thumb ov214
 *   func_0200B438 0x0200B438 thumb
 *   func_021BAAB0 0x021BAAB0 thumb ov214
 *   func_020056BC 0x020056BC thumb
 *   func_0202EE30 0x0202EE30 thumb
 *   func_0200B6E0 0x0200B6E0 thumb
 *   func_0200B490 0x0200B490 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_02039CB4 0x02039CB4 arm
 *   func_021BAF64 0x021BAF64 thumb ov214
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BB27C 0x021BB27C thumb ov214
 *   func_021BB290 0x021BB290 thumb ov214
 *   func_021BB29C 0x021BB29C thumb ov214
 *   func_021BB0C4 0x021BB0C4 thumb ov214
 *   func_02030734 0x02030734 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   d_021BB658 0x021BB658 data a1
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02035630 0x02035630 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0203FA08 0x0203FA08 arm
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021BB480 0x021BB480 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BA794 0x021BA794 thumb ov214
 *   func_0201C724 0x0201C724 thumb
 */
#include "../../matched/include/Obj00182.h"
#include "../../matched/include/Obj06705.h"
#include "../../matched/include/Obj00636.h"
#include "../../matched/include/Obj05548.h"
#include "../../matched/include/Obj25721.h"
#include "../../matched/include/Obj10934.h"
#include "../../matched/include/Obj14698.h"
#include "../../matched/include/Obj00636.h"
#include "../../matched/include/Obj14699.h"
#include "../../matched/include/Obj10935.h"
#include "../../matched/include/Obj25724.h"
#include "../../matched/include/Obj14700.h"
#include "../../matched/include/Obj01782.h"
#include "../../matched/include/Obj04632.h"
#include "../../matched/include/Obj01082.h"
#include "../../matched/include/Obj04633.h"
#include "../../matched/include/Obj10937.h"
#include "../../matched/include/Obj00182.h"
#include "../../matched/include/Obj00202.h"
#include "../../matched/include/Obj01588.h"
#include "../../matched/include/Obj02552.h"
#include "../../matched/include/Obj25726.h"

struct Obj0203159C;
struct C;
struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct Node;
struct PrintSys;
struct S020315D4;
struct BattleRec;
struct Big;
struct Entry;
struct Link;
struct ObjC4;
struct S;
struct CharBuf;
struct Descriptor;
struct Tcbl;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Cfg;
struct WinDat;
struct BmpMenu;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct C {u16 heap; u8 pad[0x66]; void *task,*win1,*win0,*font; u32 f78;};

struct Palette {u16 a,b,c;};

typedef struct {u8 a,b,c,d,e,f;} Rec;

typedef struct {Rec r[4];} Table;

typedef struct {int a,b,c;} Obj;

struct S { u8 pad[0x8C]; struct Descriptor *descriptors[2]; struct Descriptor *other1,*other2; u32 flags[2]; };

extern int func_02034AC4(int);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void*,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32,u32);
extern void func_0204E720(u32,int,int,int);
extern char *func_021BB178(u32,u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void*);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_020056A0(void(*)(void*),void*,u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021BABF4(int,char*);
extern void func_021BAD08(void*,char*);
extern void func_021BAD14(void **a, char *p);
extern void func_021BAC58(int unused, u8 *p);
extern void func_021BAE4C(int unused, u8 *p);
extern void func_021BAE9C(int,char*);
extern void func_021BAE88(int unused, u8 *p);
extern void func_0203D34C(u32,u32);
extern void func_021BAF30(int unused, u8 *p);
extern void func_021BAE10(int unused,char *p);
extern void func_021BAC3C(int unused, u8 *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021BB220(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
extern void *func_02012EBC(struct Big *p);
extern u32 func_020362DC(void);
extern int func_0204E804(void);
extern u32 func_0201FEBC(u8*);
extern void func_0201FEF4(u8 *o);
extern void func_020355D8(u8);
extern u32 func_0200B5CC(void*,u32,u32*,u32);
extern void func_021BA6F0(void*,char*);
extern struct BattleRec *func_0200B5A4(void *a, u32 heap, u32 *dp, u32 id);
extern u8 *func_0200B934(struct ObjC4 *p);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021BABB8(int,char*);
extern void func_021BA8DC(void *unused, struct S *p);
extern void func_021BAC90(int unused, u8 *p);
extern void func_021BACCC(int unused, u8 *p);
extern void func_021B9EF0(void*,char*,u32,u32,u32),func_0200B438(void*);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u32 func_0200B6E0(void*,u16,u32,u32,u32,u16*,u16*);
extern void func_0200B490(void),func_0202F038(u8*),func_020061E4(u32);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern u32 func_0200FB24(void);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern void func_021BAF64(void *unused, struct S *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BB27C(u8*),func_021BB290(u8*),func_021BB29C(char*);
extern void func_021BB0C4(char *);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern void func_02040E78(u32,void*,u32,u32);
extern u32 func_020307B0(void *p);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void *func_0201F5DC(void*,u32,u32,u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32,u32,u32);
extern void func_02041B6C(u32);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02031140(struct S02031140 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020310C4(struct Tcbl *);
extern u8 func_02035630(void);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045374(struct Cfg *);
extern void func_0201F7A8(void *desc, u32 kind);
extern unsigned char func_02045730(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char func_02012FFC(void);
extern void*func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern unsigned func_0201CE30(void*);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void*);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern int func_02035C60(void);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32 func_0201C6C4(struct PrintSys *,void *);
extern unsigned func_0203FA08(unsigned,unsigned,unsigned);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,u16,u8,u8,u16);
extern void func_021BA794(Obj*,char*,unsigned int);
extern void func_0201C724(void*,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
int func_021B95A0(void *manager,char *state,char * const obj);
int func_021B9798(void *owner,int unused,int state,char *p);
int func_021B9834(void *unused,u32 *state,const char *obj,char *p);
void func_021B9EB8(char *a, int b, char *c, int d, int e, int f, int g, int h, int i);
void func_021B9ED4(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d);
void func_021B9EF0(void *unused,char *p,unsigned a,unsigned b,unsigned c);
void func_021B9EFC(int *out, int a, int b, int c, int d);
void func_021B9F10(int unused, char *b, int c, int d);
void func_021B9F18(void *unused, char *p);
void func_021B9F24(void *unused, struct C *p);
void func_021BA018(int unused,char*p);
void func_021BA058(int unused,char *p);
void func_021BA074(int unused,char *p);
void func_021BA0A4(int unused,char *p);
void func_021BA0B0(int unused, char *p);
void func_021BA0DC(int unused,char *p);
void func_021BA108(int unused,char*p,unsigned entry,int v);
int func_021BA16C(int a,char *p);
int func_021BA190(int unused,char*p);
void func_021BA254(void*obj,char*p,unsigned entry);
u32 func_021BA2B8(int unused,u8 *p);
void func_021BA2F4(int unused,char*p);
void func_021BA39C(int unused, char *p);
void func_021BA3A0(int unused,u8 *p);
void func_021BA3C4(int unused,char*p);
void func_021BA43C(int unused, char *p);
void func_021BA45C(Obj*obj,char*p);
void func_021BA4E8(void *unused,struct S *p);
void func_021BA5C8(void*obj,char*p);
void func_021BA650(int unused,char*p);
void func_021BA6A0(void *obj, char *p, u32 v);
extern u8 ov67_id[];
extern const char ov067_id[];
extern const char d_021BB658[];
extern const Table d_021BB480;







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







int func_021B9798(void *owner,int unused,int state,char *p)
{
    func_021BAF30(state,(u8 *)p);
    func_021BA43C(state,p);
    func_021BA39C(state,p);
    func_021BA018(state,p);
    func_021BAE10(state,p);
    func_021BAC3C(state,(u8 *)p);
    func_02045C04(*(struct Rec * *)&((struct Obj00636 *)p)->f58);
    func_02030EAC((struct Node *)(((struct Obj00636 *)p)->f4C));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    func_0201C6EC((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    func_0201C4C0((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    func_0201D83C(((struct Obj00636 *)p)->f8);
    func_021BB220(*(char * *)&((struct Obj00636 *)p)->f4);
    func_020315D4(owner);
    func_020306F0(117);
    func_02034A5C((int)ov067_id);
    return 1;
}






/*
 * note 2026-10-05: no default label (the dispatch bhi lands on case 3's own break stub);
 * the finish call (18,3,0,16,2,0) is written inline in case 15 and again in case 17, never by goto;
 * case 5 writes its own cancel copy (no goto into case 6); side and index are int; c = 0 is set
 * before the first func_0200B98C call; case 12 stores p+0x64 = 120 in both arms.
 * func_02012EBC 0x02012EBC thumb
 * func_020362DC 0x020362DC arm
 * func_0204E720 0x0204E720 arm
 * func_0204E804 0x0204E804 arm
 * func_021BA108 0x021BA108 thumb ov214
 * func_021BA16C 0x021BA16C thumb ov214
 * func_021BA3A0 0x021BA3A0 thumb ov214
 * func_0201FEBC 0x0201FEBC thumb
 * func_0201FEF4 0x0201FEF4 thumb
 * func_020355D8 0x020355D8 arm
 * func_0200B5CC 0x0200B5CC thumb
 * func_021B9EB8 0x021B9EB8 thumb ov214
 * func_021BA6F0 0x021BA6F0 thumb ov214
 * func_021B9ED4 0x021B9ED4 thumb ov214
 * func_0200B5A4 0x0200B5A4 thumb
 * func_021BAD08 0x021BAD08 thumb ov214
 * func_021BA0B0 0x021BA0B0 thumb ov214
 * func_0200B934 0x0200B934 thumb
 * func_0200B98C 0x0200B98C thumb
 * func_021BABB8 0x021BABB8 thumb ov214
 * func_021BA5C8 0x021BA5C8 thumb ov214
 * func_021BA8DC 0x021BA8DC thumb ov214
 * func_021BAC90 0x021BAC90 thumb ov214
 * func_021BACCC 0x021BACCC thumb ov214
 * func_021B9EF0 0x021B9EF0 thumb ov214
 * func_0200B438 0x0200B438 thumb
 * func_021BA650 0x021BA650 thumb ov214
 * func_021BAAB0 0x021BAAB0 thumb ov214
 * func_021BA0DC 0x021BA0DC thumb ov214
 * func_021BA0A4 0x021BA0A4 thumb ov214
 * func_021BA254 0x021BA254 thumb ov214
 * func_021BA2B8 0x021BA2B8 thumb ov214
 * func_020056BC 0x020056BC thumb
 * func_0202EE30 0x0202EE30 thumb
 * func_0200B6E0 0x0200B6E0 thumb
 * func_0200B490 0x0200B490 thumb
 * func_0202F038 0x0202F038 thumb
 * func_020061E4 0x020061E4 thumb
 * func_021B9EFC 0x021B9EFC thumb ov214
 * func_020399A8 0x020399A8 arm
 * func_02039C68 0x02039C68 arm
 * func_0200FB24 0x0200FB24 thumb
 * func_02039CB4 0x02039CB4 arm
 * func_021BA058 0x021BA058 thumb ov214
 * func_021BA45C 0x021BA45C thumb ov214
 * func_021BA4E8 0x021BA4E8 thumb ov214
 * func_021BAF64 0x021BAF64 thumb ov214
 * func_0201C4E4 0x0201C4E4 thumb
 * func_021BB27C 0x021BB27C thumb ov214
 * func_021BB290 0x021BB290 thumb ov214
 * func_021BB29C 0x021BB29C thumb ov214
 */
int func_021B9834(void *unused,u32 *state,const char *obj,char *p)
{
    void *owner,*record;
    u32 result;
    int done;
    int side,index;
    long i;
    u32 status0,status1,a,b,c;
    u32 addr;
    owner=func_02012EBC(*(void**)obj);
    func_020362DC();
    switch(*state){
    case 0:
        if((*(u32*)(p+0x54))){*state=18;break;}
        if((*(u32*)(p+0x30))==1){if((*(u32*)(p+0x24))==0)(*(u32*)(p+0x2e4))=2;else (*(u32*)(p+0x2e4))=1;}
        else func_0204E720((*(u32*)(p+0x20)),(*(u32*)(p+0x24)),(*(u32*)(p+0x28)),(*(u32*)(p+0x2c)));
        *state=1;break;
    case 1:
        done=0;
        if((*(u32*)(p+0x30))==1){if((*(u32*)(p+0x2e8))==0||(*(u32*)(p+0x2e8))==2)done=1;}
        else if(!func_0204E804())done=1;
        if(done){(*(u32*)(p+0xb4))=0;*state=(*(u32*)(p+0x1c));}break;
    case 2:func_021BA108((int)obj,p,(*(u32*)(p+0x38)),0);*state=3;break;
    case 3:
        if(!func_021BA16C((int)obj,p))break;
        func_021BA3A0((int)obj,(u8 *)p);*state=(*(u32*)(p+0x34));break;
    case 4:func_021BA108((int)obj,p,(*(u32*)(p+0x44)),0);*state=(*(u32*)(p+0x40));break;
    case 5:
        result=func_0201FEBC((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0){
                if(func_0200B5CC(owner,*(u16*)p,&status0,0)){
                    (*(u32*)(p+0xb4))=1;func_021B9EB8((char*)state,(int)obj,p,8,1,0,16,-2,1);break;
                }else{func_021BA6F0((void*)obj,p);*state=10;}
            }else func_021B9ED4(state,(void*)obj,p,6,3,1);
        }else if((*(u32*)(p+0xb8))){func_0201FEF4((void*)(*(u32*)(p+0x88)));*state=15;}
        break;
    case 6:
        result=func_0201FEBC((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0){func_021BA6F0((void*)obj,p);*state=15;}
            else func_021B9ED4(state,(void*)obj,p,5,0,1);
        }else if((*(u32*)(p+0xb8))){func_0201FEF4((void*)(*(u32*)(p+0x88)));*state=15;}
        break;
    case 7:
        result=func_0201FEBC((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0)(*(u32*)(p+0x48))=10;else (*(u32*)(p+0x48))=15;
            func_021BA6F0((void*)obj,p);
            func_021B9EB8((char*)state,(int)obj,p,9,1,0,16,-2,1);break;
        }else if((*(u32*)(p+0xb8))){
            func_0201FEF4((void*)(*(u32*)(p+0x88)));(*(u32*)(p+0x48))=15;
            func_021B9EB8((char*)state,(int)obj,p,9,1,0,16,-2,1);break;
        }
        break;
    case 8:
        (*(u32*)(p+0x2ac))=(u32)func_0200B5A4(owner,*(u16*)p,&status1,0);
        func_021BAD08((void*)obj,p);func_021BA0B0((int)obj,p);
        if(status1==1){
            record=func_0200B934((void*)(*(u32*)(p+0x2ac)));
            (*(u32*)(p+0x2b0))=func_0200B98C(record,3,0);
            func_021BABB8((int)obj,p);
            for(i=0;i<12;i++){
                b=0;c=0;a=func_0200B98C(record,0,i);
                if(a){b=func_0200B98C(record,1,i);c=func_0200B98C(record,6,i);}
                if((*(u32*)(p+0x2a8))){
                    if(i<6){
                        addr=(u32)p+(u32)(i%6)*40;
                        *(u32*)(addr+0x1b4)=a;*(u32*)(addr+0x1b8)=b;*(u32*)(addr+0x1bc)=c;
                    }else{
                        addr=(u32)p+(u32)(i%6)*40;
                        *(u32*)(addr+0xc4)=a;*(u32*)(addr+0xc8)=b;*(u32*)(addr+0xcc)=c;
                    }
                }else{
                    if(i<3){side=1;index=i;}
                    else if(i<6){side=0;index=i-3;}
                    else if(i<9){side=1;index=i-3;}
                    else{side=0;index=i-6;}
                    addr=(u32)p+(u32)side*240+(u32)index*40;
                    *(u32*)(addr+0xc4)=a;*(u32*)(addr+0xc8)=b;*(u32*)(addr+0xcc)=c;
                }
            }
            func_021BA5C8((void*)obj,p);func_021BA8DC((void*)obj,(struct S *)p);
            if((*(u32*)(p+0x2a8)))func_021BAC90((int)obj,(u8 *)p);else func_021BACCC((int)obj,(u8 *)p);
            func_021B9EB8((char*)state,(int)obj,p,2,1,16,0,-2,1);
            func_021B9EF0((void*)obj,p,7,6,0);
        }else func_021B9EB8((char*)state,(int)obj,p,10,1,16,0,-2,1);
        func_0200B438((void*)(*(u32*)(p+0x2ac)));break;
    case 9:
        func_021BA650((int)obj,p);func_021BAAB0((int)obj,(int)p);func_021BAD08((void*)obj,p);
        func_021B9EB8((char*)state,(int)obj,p,(*(u32*)(p+0x48)),1,16,0,-2,1);
        func_021BA0B0((int)obj,p);
        if((*(u32*)(p+0x48))==15 && (*(u32*)(p+0x50)) && (*(u32*)(obj+4)) && !(*(u32*)(obj+8))){func_021BA0DC((int)obj,p);func_021BA0A4((int)obj,p);}
        func_021BA6F0((void*)obj,p);break;
    case 10:func_021BA254((void*)obj,p,9);*state=11;break;
    case 11:
        if(func_021BA2B8((int)obj,(u8 *)p)){
            (*(u32*)(p+0x2ec))=(u32)func_0202EE30((void *)func_020056BC(),(void*)(*(u32*)(p+0x6c)),15,16,*(u16*)p);
            (*(u32*)(p+0x2b4))=0;*(u16*)(p+0x2b8)=0;*(u16*)(p+0x2ba)=0;(*(u32*)(p+0x2bc))=0;
            *state=12;
        }break;
    case 12:
        if((*(u32*)(p+0x2bc))!=2 && (*(u32*)(p+0x2bc))!=3)(*(u32*)(p+0x2bc))=func_0200B6E0(*(void**)obj,*(u16*)p,(*(u32*)(obj+0x10)),(*(u32*)(obj+0x14)),0,(u16*)(p+0x2b8),(u16*)(p+0x2ba));
        if((u32)((*(u32*)(p+0x2bc))-2)<=1){
            func_0200B490();func_0202F038((u8*)(*(u32*)(p+0x2ec)));
            if((*(u32*)(p+0x2bc))==2){func_020061E4(0x558);func_021B9EFC((int*)state,(int)obj,(int)p,13,10);(*(u32*)(p+0x64))=120;}
            else if((*(u32*)(p+0x2bc))==3){func_021B9EFC((int*)state,(int)obj,(int)p,14,11);(*(u32*)(p+0x64))=120;}
        }break;
    case 13:if(func_021BA16C((int)obj,p))*state=15;break;
    case 14:if(func_021BA16C((int)obj,p))*state=15;break;
    case 15:
        if((*(u32*)(p+0x50))){
            if((*(u32*)(obj+0xc))){
                if((*(u32*)(obj+4))){
                    if((*(u32*)(obj+8)))a=12;
                    else{func_021B9EB8((char*)state,(int)obj,p,18,3,0,16,2,0);break;}
                }else if((*(u32*)(obj+8)))a=13;else a=14;
            }else a=15;
        }else if((*(u32*)(obj+8)))a=12;else{*state=18;break;}
        if((*(u32*)(obj+8)))func_021BA254((void*)obj,p,a);else func_021BA108((int)obj,p,a,1);
        *state=16;break;
    case 16:
        done=0;
        if((*(u32*)(obj+8))){if(func_021BA2B8((int)obj,(u8 *)p))done=1;}
        else if(func_021BA16C((int)obj,p))done=1;
        if(done){
            if((*(u32*)(obj+8))){
                func_02039C68((struct Link *)func_020399A8(),150,43);
                (*(u32*)(p+0x2ec))=(u32)func_0202EE30((void *)func_020056BC(),(void*)(*(u32*)(p+0x6c)),15,16,*(u16*)p);
            }
            *state=17;
        }break;
    case 17:
        done=1;
        if((*(u32*)(obj+8))){
            if(!func_0200FB24())done=func_02039CB4((struct Link *)func_020399A8(),150,43);
            if(done)func_0202F038((u8*)(*(u32*)(p+0x2ec)));
        }
        if(done)func_021B9EB8((char*)state,(int)obj,p,18,3,0,16,2,0);
        break;
    case 18:return 1;
    }
    func_021BA058((int)obj,p);func_021BA45C((void*)obj,p);func_021BA4E8((void*)obj,(struct S *)p);func_021BAF64((void*)obj,(struct S *)p);
    func_0201C4E4((void*)(*(u32*)(p+0xc)));func_0201C4E4((void*)(*(u32*)(p+0x10)));func_0201C4E4((void*)(*(u32*)(p+0x14)));func_0201C4E4((void*)(*(u32*)(p+0x18)));
    func_021BB27C((u8*)(*(u32*)(p+4)));func_021BB290((u8*)(*(u32*)(p+4)));func_021BB29C((char*)(*(u32*)(p+4)));
    return 0;
}







void func_021B9EB8(char *a, int b, char *c, int d, int e, int f, int g, int h, int i)
{
    ((struct Obj25721 *)a)->f0 = 0;
    ((struct Obj05548 *)c)->f1C = d;
    ((struct Obj05548 *)c)->f20 = e;
    ((struct Obj05548 *)c)->f24 = f;
    ((struct Obj05548 *)c)->f28 = g;
    ((struct Obj05548 *)c)->f2C = h;
    ((struct Obj05548 *)c)->f30 = i;
}






void func_021B9ED4(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d){*out=2;func_021B9EF0(a,p,b,c,d);}






void func_021B9EF0(void *unused,char *p,unsigned a,unsigned b,unsigned c){((struct Obj10934 *)p)->f34=a;((struct Obj10934 *)p)->f38=b;((struct Obj10934 *)p)->f3C=c;}






void func_021B9EFC(int *out, int a, int b, int c, int d)
{
    *out = 4;
    func_021B9F10(a, (char *)b, c, d);
}






void func_021B9F10(int unused, char *b, int c, int d)
{
    ((struct Obj14698 *)b)->f40 = c;
    ((struct Obj14698 *)b)->f44 = d;
}





/*
 * blocker-leaf: sole callback blocker of ov214 021B95A0; no existing source/unit/shard, parent ownership cleared.
 */
void func_021B9F18(void *unused, char *p)
{
    func_021BB0C4(p);
}





static inline void init_palette(struct Palette *pal)
{
    pal->a=0x294b; pal->b=0x5694; pal->c=0x7fff;
}





void func_021B9F24(void *unused, struct C *p)
{
    struct Palette *pal = func_02030734(p->heap,6,1,d_021BB658,0x5e9);
    init_palette(pal);
    func_02040E78(2,pal,6,0x13a);
    func_020307B0(pal);
    func_02049B40(0x17,5,0,0x180,0x20,p->heap);
    p->win0=(void *)func_020450F0(1,0,0,1,1,9,0);
    func_02043B5C(func_02045770(p->win0),0);
    func_02045334(p->win0);
    p->win1=(void *)func_020450F0(1,1,0x13,0x1e,4,0xc,0);
    func_02043B5C(func_02045770(p->win1),0xf);
    func_02045334(p->win1);
    p->font=func_0201F5DC((void*)1,0xa,0,p->heap);
    p->task=func_0203101C(p->heap,p->heap,1,0);
    func_0201DD78(1,2,0xf);
    func_02041B6C(1);
    *(u32*)((u8*)p+0x5c)=0;
    *(u32*)((u8*)p+0x60)=0;
    *(u32*)((u8*)p+0x64)=0;
    p->f78=0;
}





void func_021BA018(int unused,char*p)
{
    if(*(void* *)&((struct Obj00636 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj00636 *)p)->f5C);
    if(*(void* *)&((struct Obj00636 *)p)->f78)func_02045808(*(void* *)&((struct Obj00636 *)p)->f78);
    func_02031140(*(void* *)&((struct Obj00636 *)p)->f68);
    func_0203FB44(1,(u16)(((struct Obj00636 *)p)->f74),(u16)(((struct Obj00636 *)p)->f74>>16));
    func_020452E8(*(void* *)&((struct Obj00636 *)p)->f6C);
    func_020452E8(*(void* *)&((struct Obj00636 *)p)->f70);
}





/*
 * Tail: two zero alignment bytes at 021BA072.
 */
void func_021BA058(int unused,char *p){func_020310C4(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);if(func_02035630()==30)func_020310C4(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);}




/*
 * Parameter evidence: original narrows third input to u16 before func_0201F73C.
 */
void func_021BA074(int unused,char *p){struct Descriptor *d;func_0201F73C(((struct Obj10935 *)p)->f6C,1,(unsigned short)(((struct Obj10935 *)p)->f74),10);d=*(struct Descriptor * *)&((struct Obj10935 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}




void func_021BA0A4(int unused,char *p){func_0201F7A8(((struct Obj25724 *)p)->f6C,(int)1);}




void func_021BA0B0(int unused, char *p)
{
    struct Descriptor *d;
    func_02043B5C(func_02045770(((struct Obj14700 *)p)->f6C), 15);
    d = ((struct Obj14700 *)p)->f6C;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_02041B6C(func_02045730(d));
}




/*
 * Tail: two zero alignment bytes at 021BA106.
 */
void func_021BA0DC(int unused,char *p){struct Descriptor *d;func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C),0);d=*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}




/*
 * note: 0201CCE4's r0 remains live and is stored at +5c after the call;
 * its caller declaration returns that word despite the own source's void.
 * extent-tail: 021BA16A alignment padding (two zero bytes).
 */
void func_021BA108(int unused,char*p,unsigned entry,int v)
{
    int x;
    func_02043B5C(func_02045770(*(void* *)&((struct Obj01782 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01782 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj01782 *)p)->f5C);
    if(*(void* *)&((struct Obj01782 *)p)->f78)func_02045808(*(void* *)&((struct Obj01782 *)p)->f78);
    *(void* *)&((struct Obj01782 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01782 *)p)->f58,entry);
    x=func_02012FFC();
    *(void* *)&((struct Obj01782 *)p)->f5C=func_0201CCE4(*(unsigned *)&((struct Obj01782 *)p)->f6C,0,0,*(unsigned *)&((struct Obj01782 *)p)->f78,((struct Obj01782 *)p)->f8,x,((struct Obj01782 *)p)->f68,2,((struct Obj01782 *)p)->f0,15);
    ((struct Obj01782 *)p)->f60=v;
}




int func_021BA16C(int a,char *p){int result=func_021BA190(a,p);if(result==0){if(func_02035630()==30)result=func_021BA190(a,p);}return result;}




int func_021BA190(int unused,char*p)
{
    int result=0;
    switch(func_0201CE30(*(void* *)&((struct Obj04632 *)p)->f5C)){
    case 0:
        if((func_0203630C()&3)||func_02035C38()){
            func_0201CE5C(*(void* *)&((struct Obj04632 *)p)->f5C,0);
            if(func_0203630C()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 1:
        if((func_020362DC()&3)||func_02035C60()){
            func_020061E4(0x547);
            func_0201CE38(*(void* *)&((struct Obj04632 *)p)->f5C);
            if(func_020362DC()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 2:
        if(((struct Obj04632 *)p)->f64)--((struct Obj04632 *)p)->f64;
        else if(((struct Obj04632 *)p)->f60){
            if((func_020362DC()&3)||func_02035C60()){
                if(func_020362DC()&3)func_020355D8(0);else func_020355D8(1);
                ((struct Obj04632 *)p)->f60=0;
                result=1;
            }
        }else result=1;
        break;
    }
    return result;
}




void func_021BA254(void*obj,char*p,unsigned entry)
{
    func_02043B5C(func_02045770(*(void* *)&((struct Obj01082 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01082 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj01082 *)p)->f5C);
    *(int *)&((struct Obj01082 *)p)->f5C=0;
    if(*(void* *)&((struct Obj01082 *)p)->f78)func_02045808(*(void* *)&((struct Obj01082 *)p)->f78);
    *(void* *)&((struct Obj01082 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01082 *)p)->f58,entry);
    *(int *)&((struct Obj01082 *)p)->f7C=0;
    func_0201C6FC(*(void* *)&((struct Obj01082 *)p)->fC,(unsigned)func_02045770(*(void* *)&((struct Obj01082 *)p)->f6C),0,0,*(void* *)&((struct Obj01082 *)p)->f78,((struct Obj01082 *)p)->f8);
    func_021BA2B8((int)obj,(u8 *)p);
}




u32 func_021BA2B8(int unused,u8 *p){struct Descriptor *d;if(((struct Obj01082 *)p)->f7C==0){if(func_0201C6C4(*(struct PrintSys * *)&((struct Obj01082 *)p)->fC,func_02045770(*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C))==0){d=*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));((struct Obj01082 *)p)->f7C=1;}}return ((struct Obj01082 *)p)->f7C;}




void func_021BA2F4(int unused,char*p)
{
    unsigned off;
    u16*colors;
    off=func_0203FA08(1,0x500,1);
    func_0203FB44(1,off,0x500);
    func_02049B40(0x17,5,0,0x160,0x20,((struct Obj04633 *)p)->f0);
    colors=func_02030734(((struct Obj04633 *)p)->f0,6,1,d_021BB658,0x6f9);
    colors[0]=0x294b;colors[1]=0x5694;colors[2]=0x7fff;
    func_02040E78(2,colors,6,0x17a);
    func_020307B0(colors);
    ((struct Obj04633 *)p)->f80=1;((struct Obj04633 *)p)->f81=0x18;((struct Obj04633 *)p)->f82=0xd;((struct Obj04633 *)p)->f83=0xb;
    ((struct Obj04633 *)p)->f84=off;
}




void func_021BA39C(int unused, char *p){}




void func_021BA3A0(int unused,u8 *p){*(struct BmpMenu * *)&((struct Obj10937 *)p)->f88=func_0201FDA0((const struct WinDat *)(p+0x80),((struct Obj10937 *)p)->f74,10,0,((struct Obj10937 *)p)->f0);}




void func_021BA3C4(int unused,char*p)
{
    Table t=d_021BB480;
    u8 i;
    for(i=0;i<4;i++){
        *(unsigned*)(p+i*4+0x8c)=func_020450F0(t.r[i].a,t.r[i].b,t.r[i].c,t.r[i].d,t.r[i].e,9,t.r[i].f);
        func_02043B5C(func_02045770(*(void**)(p+i*4+0x8c)),0);
        *(int*)(p+i*4+0x9c)=1;
    }
    ((struct Obj00182 *)p)->fBC=0;
    ((struct Obj00182 *)p)->fC0=0;
}




void func_021BA43C(int unused, char *p)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        func_020452E8(*(void **)(p + 0x8c + i * 4));
    }
}



/*
 * note: BA794's third argument is narrowed at 021BA49A..A0; caller
 * extern uses u16 despite its own source's unsigned parameter.
 */
void func_021BA45C(Obj*obj,char*p)
{
    unsigned threshold;
    if(func_02035630()==30)threshold=30;else threshold=60;
    if(obj->c && !((struct Obj00202 *)p)->fB4 && (((struct Obj00202 *)p)->fAC>=threshold || *(int *)&((struct Obj00202 *)p)->fB0)){
        func_021BA794(obj,p,(u16)(((struct Obj00202 *)p)->fAC/threshold));
        if(((struct Obj00202 *)p)->fAC>=threshold){
            --((struct Obj00202 *)p)->fAC;
            if(((struct Obj00202 *)p)->fAC==threshold-1)((struct Obj00202 *)p)->fB8=1;
        }else{
            --((struct Obj00202 *)p)->fB0;
            if(!((struct Obj00202 *)p)->fB0)func_021BA6F0(obj,p);
        }
    }
}



/*
 * extent: two bytes zero alignment at 021BA5C6.
 * lever: indexed struct members keep the fixed field offset inside the loop;
 *   raw pointer form was DIFF236/217, integer form DIFF222/66.
 */
void func_021BA4E8(void *unused,struct S *p)
{
    u8 i;
    struct Descriptor *d;
    for (i=0;i<=1;i++) {
        if (p->flags[i]==0) {
            if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj01588 *)p)->f10,func_02045770(p->descriptors[i]))==0) {
                d=p->descriptors[i];
                func_02045334(d);
                func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                p->flags[i]=1;
            }
        }
    }
    if (((struct Obj01588 *)p)->fA4==0) {
        if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj01588 *)p)->f14,func_02045770(p->other1))==0) {
            d=p->other1;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            ((struct Obj01588 *)p)->fA4=1;
        }
    }
    if (((struct Obj01588 *)p)->fA8==0) {
        if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj01588 *)p)->f18,func_02045770(p->other2))==0) {
            d=p->other2;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            ((struct Obj01588 *)p)->fA8=1;
        }
    }
}


void func_021BA5C8(void*obj,char*p)
{
    void*h;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,19);
    func_0201C724(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)func_02045770(*(void* *)&((struct Obj02552 *)p)->f8C),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    func_02045808(h);
    ((struct Obj02552 *)p)->f9C=0;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,((struct Obj02552 *)p)->f2A4);
    func_0201C724(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)func_02045770(*(void* *)&((struct Obj02552 *)p)->f90),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    func_02045808(h);
    ((struct Obj02552 *)p)->fA0=0;
    func_021BA4E8(obj,(struct S *)p);
}


void func_021BA650(int unused,char*p)
{
    u8 i;
    void*h;
    for(i=0;i<=1;i++){
        func_0201C6EC((struct PrintSys *)(((struct Obj25726 *)p)->f10));
        func_02043B5C(func_02045770(*(void**)(p+i*4+0x8c)),0);
        h=*(void**)(p+i*4+0x8c);
        func_02045334(h);
        func_02045374(h);
        func_02041B6C(func_02045730(h));
        *(int*)(p+i*4+0x9c)=1;
    }
}


void func_021BA6A0(void *obj, char *p, u32 v)
{
    u32 threshold;
    if (func_02035630() == 30) threshold = 30;
    else threshold = 60;
    ((struct Obj00202 *)p)->fAC = threshold * (v + 1) - 1;
    ((struct Obj00202 *)p)->fB0 = threshold >> 1;
    ((struct Obj00202 *)p)->fB4 = 0;
    ((struct Obj00202 *)p)->fB8 = 0;
    ((struct Obj00202 *)p)->fBC = 0;
    ((struct Obj00202 *)p)->fC0 = 0;
    func_021BA794(obj, p, v);
}
