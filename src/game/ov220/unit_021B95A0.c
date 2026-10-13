/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B9770, func_021B97F4, func_021B995C, func_021B9960, func_021B99D8, func_021B99DC, func_021B9B20, func_021B9B64, func_021B9C70, func_021B9CBC, func_021B9FF0, func_021BA01C, func_021BA068
 * address:  0x021B95A0
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BA0D8 0x021BA0D8 thumb ov220
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   bgtable 0x021BA370 data a4
 *   resources 0x021BA4E0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021BA178 0x021BA178 thumb ov220
 *   d_021BA370 0x021BA370 data a4
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_0204E804 0x0204E804 arm
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BA1CC 0x021BA1CC thumb ov220
 *   sounds 0x021BA3B0 data a4
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_021BA1E0 0x021BA1E0 thumb ov220
 *   func_0204B294 0x0204B294 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   coords3 0x021BA318 data a2
 *   coords4 0x021BA328 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   table 0x021BA3AC data ov220 a1
 *   coords 0x021BA338 data ov220 a2
 *   func_02049B90 0x02049B90 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_021BA354 0x021BA354 data ov220 a1
 *   d_021BA314 0x021BA314 data a1
 *   d_021BA3A8 0x021BA3A8 data a2
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 */
#include "../../matched/include/Obj01297.h"
#include "../../matched/include/Obj03379.h"
#include "../../matched/include/Obj26059.h"
#include "../../matched/include/Obj26060.h"
#include "../../matched/include/Obj01181.h"
#include "../../matched/include/Obj01297.h"

struct BgTemplate;
struct GfFont;
struct Obj;
struct Obj0203159C;
struct Node;
struct PrintSys;
struct S020315D4;
struct Cfg;
struct Descriptor;
struct Bmp;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct Strbuf;
struct U16Vec;
struct WordSet;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { LOOP_ZERO=0 } Loop;

struct Row {u32 id;u8 body[32];u32 kind,on;};

struct Resources {u32 a,b,c;};

typedef struct {unsigned first;char pad[40];} Entry;

typedef short s16;

struct Param_021B95A0
{
  s16 x;
  s16 y;
  u32 zero;
};

typedef struct {unsigned a,b,c;} Row;

typedef struct {char pad0[24];u8 count;char pad19[3];Row rows[4];void *objects[4];} Context;

struct Param_021B9B64 {s16 x,y;u32 zero;};

struct Info { u8 pad0[4]; u8 *base; u32 flag; };

struct Obj {
    u16 heap; u16 pad2; struct Info *info; u32 pad8;
    void *str; void *bmp; u8 pad14[0x5c - 0x14];
    void *bank; void *ptr[4]; u32 done[4]; u32 f80;
};

struct Rec { u32 msg; u16 a; u16 level; u32 b; };



extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void*,u32,u32);
extern void * func_021BA0D8(u32,u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void*);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void BG_SYS_ClearSubPlanes(void),BG_SYS_ClearSubBgPlanes(void),func_0207D518(int);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_02043598(u32,u32),func_020409B4(u32),func_0203D34C(u32,u32),GFL_USE_FadeOutBgm(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void*,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void*,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void*);
extern void func_0204E720(u32,int,int,int);
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020306F0(unsigned int heap);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021BA178(unsigned char *p);
extern int GFL_USE_IsBgmFading(void),GFL_USE_PushBgm(void),GFL_USE_PopBgm(void),func_02005F38(void),func_0204E804(void);
extern void GFL_USE_SetBgmPlayerParam(void*),GFL_USE_CancelChangeAndPlayBgm(u32,u16),GFL_USE_FadeInBgmFull(u32);
extern u32 func_020362DC(void);
extern u32 func_02035D20(u32*,u32*);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020355D8(u8);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021BA1CC(char*);
extern void func_02049238(void *),func_020409B4(unsigned);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0204AF28(void *, u32, u32, u32);
extern u32 func_021BA1E0(u8 *p);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32, u32, u32, u32);
extern u32 func_0201BB5C(u32, u32, u32, u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned),func_0204A8D4(unsigned),func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_02049B90(u32,u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
int func_021B95A0(void *host,void *unused,void *args);
int func_021B9770(void *state,int unused1,int unused2,char *p);
int func_021B97F4(void *unused, u32 *state, void *unused2, char *p);
void func_021B995C(void);
void func_021B9960(u16 *p);
void func_021B99D8(void *a0);
void func_021B99DC(char *p);
void func_021B9B20(Context *p);
void func_021B9B64(char *p);
void func_021B9C70(unsigned char *p);
void func_021B9CBC(struct Obj *p);
void func_021B9FF0(u8*p);
void func_021BA01C(struct Obj *o);
unsigned char func_021BA068(unsigned value);
extern const struct Row bgtable[];
extern struct Resources resources[];
extern const Entry d_021BA370[];
extern const u32 sounds[];
extern const u8 coords3[];
extern const u8 coords4[];
extern const u8 table[],coords[];
extern const u8 d_021BA354[];
extern u8 d_021BA314[];
extern const struct Rec d_021BA3A8[];










int func_021B95A0(void *host,void *unused,void *args)
{
    char *p;
    char *desc;
    Loop i;
    u16 variant;
    void *owner;
    u16 heap;
    func_0203064C((u32)((void *)1),131,0x50000);
    p=func_0203159C(host,0xB4,131);
    func_02082BCC(p,0,0xB4);
    *(u16 *)p=131;
    *(void **)(p+4)=args;
    *(void **)(p+8)=func_021BA0D8(1,*(u16 *)p);
    *(void **)(p+0xC)=func_0201D7EC(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+0x10)=func_0201C440((void *)(u32)*(u16 *)p);
    func_0204047C(1,2);func_0204047C(2,1);func_0204047C(3,0);
    *(void **)(p+0x14)=func_020056A0((u32)func_021B995C,(u32)p,1);
    if (*(u32 *)(*(char **)(p+4)+8)) desc=*(char **)(*(char **)(p+4)+4)+0x14;
    else desc=*(char **)(*(char **)(p+4)+4);
    if (!*(u8 *)desc) *(u32 *)(p+0xB0)=7;
    else *(u32 *)(p+0xB0)=func_021BA068(*(u16 *)(desc+2));
    func_021B9960((u16*)p);func_021B99DC(p);func_021B9B64(p);func_021B9CBC((struct Obj *)p);
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 |= 0x10000;
    BG_SYS_ClearSubPlanes();func_0207D518(0);BG_SYS_ClearSubBgPlanes();
    i=0;
    do {
        const struct Row *r=(const struct Row *)((u32)bgtable+i*44);
        u32 layer=r->id;
        func_0203FCA0((u8)layer,(const struct BgTemplate*)r->body,(u8)r->kind);
        func_020414AC(layer);func_02040588(layer,r->on);
    } while ((u32)++i<1);
    func_02043598(16,1);
    heap=*(u16 *)p;
    variant=1;
    if (*(u8 *)*(char **)(p+4)!=1) variant=0;
    owner=func_020490F4(30,heap);
    func_02049B68(owner,resources[variant].a,4,0,0,heap);
    func_02049658(owner,resources[variant].b,4,0,0,0,heap);
    func_020498F4(owner,resources[variant].c,4,0,0,0,heap);
    func_02049238(owner);func_020409B4(4);func_0204E720(3,16,16,0);func_0203D34C(0,*(u16 *)p);
    if (*(u32 *)(*(char **)(p+4)+0xC) && *(u32 *)(p+0xB0)!=7) GFL_USE_FadeOutBgm(6);
    return 1;
}










/*
 * volatile: hardware accesses at 021B9794 and 021B9798/021B979E.
 */
int func_021B9770(void *state,int unused1,int unused2,char *p)
{
    int i;
    for(i=0;i<1u;i++) func_020403F4((u8)d_021BA370[i].first);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_021B9FF0((u8 *)p);
    func_021B9C70((unsigned char *)p);
    func_021B9B20((Context *)p);
    func_021B99D8(p);
    func_02030EAC(((struct Obj01297 *)p)->f14);
    func_0201C6EC(((struct Obj01297 *)p)->f10);
    func_0201C4C0(((struct Obj01297 *)p)->f10);
    func_0201D83C(((struct Obj01297 *)p)->fC);
    func_021BA178(((struct Obj01297 *)p)->f8);
    func_020315D4(state);
    func_020306F0(131);
    return 1;
}









int func_021B97F4(void *unused, u32 *state, void *unused2, char *p)
{
    u32 x,y;
    u8 i;
    int flag;
    switch (*state) {
    case 0:
        flag=1;
        if (((struct Obj26059 *)(*(char * *)&((struct Obj03379 *)p)->f4))->fC && ((struct Obj03379 *)p)->fB0!=7) {
            if (GFL_USE_IsBgmFading()) flag=0;
            else {
                GFL_USE_SetBgmPlayerParam((void *)1);
                GFL_USE_PushBgm();
                GFL_USE_CancelChangeAndPlayBgm(*(const u32 *)((u32)sounds+((struct Obj03379 *)p)->fB0*12),0xFFFF);
            }
        }
        if (flag) {func_0204E720(3,16,0,0);*state=1;}
        break;
    case 1:
        if (!func_0204E804()) {
            if (((struct Obj26060 *)(*(char * *)&((struct Obj03379 *)p)->f4))->fC && ((struct Obj03379 *)p)->fB0!=7) *state=2;
            else *state=3;
        }
        break;
    case 2:
        if (!func_02005F38()) {
            GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(6);*state=3;
        }
        break;
    case 3:
        flag=0;
        if (func_020362DC()&3) {func_020355D8(0);flag=1;}
        else if (func_02035D20(&x,&y)) {func_020355D8(1);flag=1;}
        if (flag) {*state=4;func_0204E720(3,0,16,0);}
        break;
    case 4:
        if (!func_0204E804()) *state=5;
        break;
    case 5:return 1;
    }
    if (func_0201C4E4(((struct Obj03379 *)p)->f10) && !((struct Obj03379 *)p)->f80) {
        for (i=1;i<4;i++) {
            void *v=*(void **)((u32)p+(u32)i*4+0x60);
            func_02045334(v);func_02045374(v);func_02041B6C(func_02045730(v));
        }
        ((struct Obj03379 *)p)->f80=1;
    }
    func_021BA01C((struct Obj *)p);
    func_021BA1CC(*(char * *)&((struct Obj03379 *)p)->f8);
    return 0;
}









void func_021B995C(void) {}








void func_021B9960(u16 *p)
{
    void *object;
    object=func_020490F4(201,*p);
    func_02049B68(object,0,0,0,64,*p);
    func_02049658(object,2,2,0,0,0,*p);
    func_020498F4(object,4,2,0,0,0,*p);
    func_020498F4(object,5,1,0,0,0,*p);
    func_02049238(object);
    func_020409B4(2);
    func_020409B4(1);
}







void func_021B99D8(void *a0){}






void func_021B99DC(char *p)
{
  const u8 *coords;
  void *owner;
  u16 species;
  u8 form;
  u8 gender;
  u8 *desc;
  u8 i;
  char *res;
  char *slot;
  struct Param_021B95A0 param;
  void *actor;
  char *args = *((char **) (p + 4));
  *((u8 *) (p + 0x18)) = 0;
  if (*((u32 *) (args + 8)))
    desc = (*((u8 **) (args + 4))) + 0x14;
  else
    desc = *((u8 **) (args + 4));
  if (*desc)
  {
    if (desc[1] == 0)
    {
      *((u8 *) (p + 0x18)) = 3;
      coords = coords3;
    }
    else
    {
      *((u8 *) (p + 0x18)) = 4;
      coords = coords4;
    }
    owner = func_020490F4(7, *((u16 *) p));
    for (i = 0; i < (*((u8 *) (p + 0x18))); i++)
    {
      species = *((u16 *) (desc + i * 4 + 4));
      form = desc[i * 4 + 6];
      gender = desc[i * 4 + 7];
      if (i == 0)
        *((u32 *) (p + i * 12 + 0x20)) = func_0204ACEC(owner, func_0201BC3C(), 0, 32, *((u16 *) p));
      res = p + i * 12;
      *((u32 *) (res + 0x1C)) = func_0204A6C8(owner, POKE_TOOL_CalcGraphicIndex(species, form, gender, 0), 0, 0, *((u16 *) p));
      *((u32 *) (res + 0x24)) = func_0204AF28(owner, func_0201BC40(), func_0201BCB4(), *((u16 *) p));
      func_02082BCC(&param, 0, 8);
      param.x = *((const s16 *) (coords + i * 4));
      param.y = *((const s16 *) (coords + i * 4 + 2));
      slot = p + i * 4;
      actor = func_0204B294((void *)func_021BA1E0(*((void **) (p + 8))), *((u32 *) (res + 0x1C)), *((u32 *) (p + 0x20)), *((u32 *) (res + 0x24)), (const void *)((u32) (&param)), 0, *((u16 *) p));
      *((void **) (slot + 0x4C)) = actor;
      func_0204B878(actor, 1);
      func_0204B92C(*((void **) (slot + 0x4C)), 0);
      func_0204B6F4(*((void **) (slot + 0x4C)), func_0201BB5C(species, form, gender, 0), 0);
    }
    func_02049238(owner);
  }
}





void func_021B9B20(Context *p)
{
    u8 i;
    for(i=0;i<p->count;i++) {
        func_0204B3B4(p->objects[i]);
        func_0204AFD8(p->rows[i].c);
        func_0204A8D4(p->rows[i].a);
        if(i==0) func_0204ADA4(p->rows[i].b);
    }
}




void func_021B9B64(char *p)
{
    void *owner;
    struct Param_021B9B64 param;
    u8 i=0;
    ((struct Obj01181 *)p)->f84=0;
    if(((struct Obj01181 *)p)->fB0!=7){
        ((struct Obj01181 *)p)->f84=*(const u8*)((u32)table+((struct Obj01181 *)p)->fB0*12);
        if(*(volatile u8 *)&((struct Obj01181 *)p)->f84){
            owner=func_020490F4(201,((struct Obj01181 *)p)->f0);
            *(int *)&((struct Obj01181 *)p)->f8C=func_0204AC18(owner,1,0,0,0,1,((struct Obj01181 *)p)->f0);
            *(int *)&((struct Obj01181 *)p)->f88=func_0204A6C8(owner,3,0,0,((struct Obj01181 *)p)->f0);
            *(int *)&((struct Obj01181 *)p)->f90=func_0204AF28(owner,6,7,((struct Obj01181 *)p)->f0);
            func_02049238(owner);
            func_02082BCC(&param,0,8);
            for(;i<((struct Obj01181 *)p)->f84;i++){
                param.x=*(const s16*)((u32)coords+(u32)i*4);
                param.y=*(const s16*)((u32)coords+(u32)i*4+2);
                *(void**)((u32)p+(u32)i*4+0x94)=func_0204B294((void *)func_021BA1E0(*(void* *)&((struct Obj01181 *)p)->f8),((struct Obj01181 *)p)->f88,((struct Obj01181 *)p)->f8C,((struct Obj01181 *)p)->f90,&param,0,((struct Obj01181 *)p)->f0);
                func_0204B878(*(void**)((u32)p+(u32)i*4+0x94),0);
                func_0204B92C(*(void**)((u32)p+(u32)i*4+0x94),1);
            }
        }
    }
}



void func_021B9C70(unsigned char *p)
{
    unsigned char i;
    if(p[0x84]) {
        for(i=0;i<p[0x84];i++) func_0204B3B4(*(struct Obj **)(p+0x94+4*i));
        func_0204AFD8(((struct Obj01297 *)p)->f90);
        func_0204A8D4(((struct Obj01297 *)p)->f88);
        func_0204ADA4(((struct Obj01297 *)p)->f8C);
    }
}



void func_021B9CBC(struct Obj *p)
{
    u8 i;
    u8 *b;
    u8 *a;
    void *x;
    void *y;
    void *g, *t, *z, *q;
    u16 off, n;
    u32 w1;
    u32 h, idx, m;
    u8 k;
    p->bank = 0;
    for (i = 0; i < 4; i++) {
        p->ptr[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->f80 = 0;
    if (p->info->flag) {
        b = a = p->info->base;
        b += 0x14;
        a += 0x38;
    } else {
        b = p->info->base;
    }
    if (b[0] == 0) return;
    func_02049B90(0x17, 5, 0, 0, 0x40, 0x20, p->heap);
    p->bank = func_02045B38(0, 3, 0x1CD, p->heap);
    for (i = 0; i < 4; i++) {
        p->ptr[i] = (void *)func_020450F0(d_021BA354[i*7], d_021BA354[i*7+1], d_021BA354[i*7+2], d_021BA354[i*7+3], d_021BA354[i*7+4], d_021BA354[i*7+5], d_021BA354[i*7+6]);
        func_02043B5C(func_02045770(p->ptr[i]), (u32)0);
        func_02045334(p->ptr[i]);
    }
    if (p->info->flag) {
        x = func_020457B0(0x11, (u16)p->heap);
        func_02045994(x, (const u16 *)a, 0x11);
    } else {
        idx = 0x26;
        if (b[1]) idx = 0x27;
        x = func_02045EC0(p->bank, idx);
    }
    y = func_02045EC0(p->bank, 0x28);
    off = 0;
    w1 = (u16)func_0201D304(x, (u32)p->str, 0);
    h = (u16)func_0201D304(y, (u32)p->str, 0);
    n = w1 + 8 + h;
    h = (u32)func_020437DC(func_02045770(p->ptr[1]));
    if (h >= n) off = ((int)(h - n)) / 2;
    k = d_021BA314[1];
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[1]), (s16)off, k, (u32)x, (u32)p->str, 0x440);
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[1]), (s16)(u16)(off + w1 + 8), k, (u32)y, (u32)p->str, 0x440);
    func_02045808(y);
    func_02045808(x);
    m = *(u16 *)(b + 2);
    if (m > 9999) m = 9999;
    g = func_0201EC64(p->heap);
    t = func_02045EC0(p->bank, 0x2a);
    z = func_020457B0(5, (u16)p->heap);
    off = 0;
    func_0201EFA4(g, 0, (u16)m, 4, 0, 1);
    func_0201F250(g, z, t);
    q = func_02045EC0(p->bank, 0x29);
    w1 = (u16)func_0201D304(z, (u32)p->str, 0);
    h = (u16)func_0201D304(q, (u32)p->str, 0);
    n = w1 + 8 + h;
    h = (u32)func_020437DC(func_02045770(p->ptr[2]));
    if (h >= n) off = ((int)(h - n)) / 2;
    k = d_021BA314[2];
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[2]), (s16)off, k, (u32)z, (u32)p->str, 0x440);
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[2]), (s16)(u16)(off + w1 + 8), k, (u32)q, (u32)p->str, 0x440);
    func_02045808(q);
    func_02045808(z);
    func_02045808(t);
    func_0201ED04(g);
    y = func_02045EC0(p->bank, d_021BA3A8[func_021BA068(*(u16 *)(b + 2))].msg);
    w1 = (u16)func_0201D304(y, (u32)p->str, 0);
    h = (u32)func_020437DC(func_02045770(p->ptr[3]));
    off = ((int)(h - w1)) / 2;
    func_0201C724(p->bmp, (u32)func_02045770(p->ptr[3]), (s16)off, d_021BA314[3], (u32)y, (u32)p->str, 0x440);
    func_02045808(y);
    for (i = 1; i < 4; i++) {
        void *d = p->ptr[i];
        func_02045334(d);
        func_02045374(d);
        func_02041B6C(func_02045730(d));
    }
    func_021BA01C(p);
}



void func_021B9FF0(u8*p){u8 i;for(i=0;i<4;i++)if(*(struct Descriptor**)(p+96+i*4))BMP_WIN_Delete(*(struct Descriptor**)(p+96+i*4));if(*(struct Rec* *)&((struct Obj01297 *)p)->f5C)func_02045C04(*(struct Rec* *)&((struct Obj01297 *)p)->f5C);}



void func_021BA01C(struct Obj *o)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (o->done[i] == 0) {
            if (func_0201C6C4(o->bmp, func_02045770(o->ptr[i])) == 0) {
                void *p = o->ptr[i];
                func_02045334(p);
                func_02045374(p);
                func_02041B6C(func_02045730(p));
                o->done[i] = 1;
            }
        }
    }
}


unsigned char func_021BA068(unsigned value)
{
    unsigned level;
    unsigned char i;
    if(value>=6000) level=6;
    else if(value>=5000) level=5;
    else if(value>=4000) level=4;
    else if(value>=3000) level=3;
    else if(value>=2000) level=2;
    else if(value>=1000) level=1;
    else level=0;
    for(i=0;i<7;i++) if(level==d_021BA3A8[i].level) return i;
    return 0;
}
