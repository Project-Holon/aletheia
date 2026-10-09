/*
 * file:     mystery_util_p01.c
 * unit:     yes
 * function: func_021D9624, func_021D96C4, func_021D9718, func_021D972C, func_021D9738, func_021D9744, func_021D9750, func_021D9790, func_021D97B4, func_021D97C8, func_021D9828, func_021D9860, func_021D9864, func_021D986C, func_021D98C0, func_021D98E0, func_021D98E8, func_021D98F4, func_021D9960, func_021D9974, func_021D9994, func_021D99A4, func_021D9A40, func_021D9A58, func_021D9A64, func_021D9AC8, func_021D9B28, func_021D9B2C, func_021D9B34, func_021D9B9C, func_021D9BC0, func_021D9BE8, func_021D9CA4, func_021D9D4C, func_021D9E04, func_021D9E50, func_021D9F08, func_021D9F24, func_021D9FF8, func_021D9FFC, func_021DA010, func_021DA038, func_021DA148, func_021DA178, func_021DA1BC, func_021DA280, func_021DA2A8, func_021DA2C8, func_021DA2F0, func_021DA318, func_021DA338, func_021DA3C0
 * address:  0x021D9624
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021DFB8C 0x021DFB8C data a1
 *   d_021DF604 0x021DF604 data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040588 0x02040588 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02050B80 0x02050B80 arm
 *   d_021DF598 0x021DF598 data a4
 *   func_02050ED4 0x02050ED4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   d_021DF634 0x021DF634 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DF5A8 0x021DF5A8 data a4
 *   d_021DF5C4 0x021DF5C4 data a4
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021D9580 0x021D9580 thumb ov121
 *   d_021DF574 0x021DF574 data a4
 *   d_021DF58C 0x021DF58C data a4
 *   d_021DF580 0x021DF580 data a4
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02050BE8 0x02050BE8 arm
 *   func_02047970  0x02047970  arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   func_020452E8  0x020452E8  arm
 *   func_02045808  0x02045808  arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045838 0x02045838 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028470 0x02028470 thumb
 *   func_02031140 0x02031140 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0202F038 0x0202F038 thumb
 *   d_021DF78C 0x021DF78C data a4
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02043994 0x02043994 arm
 *   func_02043678 0x02043678 arm
 *   func_020437AC 0x020437AC arm
 */
#include "../../matched/include/Obj13944.h"
#include "../../matched/include/Obj22873.h"
#include "../../matched/include/Obj13945.h"
#include "../../matched/include/Obj13946.h"
#include "../../matched/include/Obj13948.h"
#include "../../matched/include/Obj10413.h"
#include "../../matched/include/Obj01929.h"
#include "../../matched/include/Obj13950.h"
#include "../../matched/include/Obj22875.h"
#include "../../matched/include/Obj01057.h"
#include "../../matched/include/Obj22876.h"
#include "../../matched/include/Obj02179.h"
#include "../../matched/include/Obj08092.h"
#include "../../matched/include/Obj02180.h"
#include "../../matched/include/Obj00909.h"
#include "../../matched/include/Obj00236.h"
#include "../../matched/include/Obj22877.h"
#include "../../matched/include/Obj22878.h"
#include "../../matched/include/Obj01542.h"
#include "../../matched/include/Obj01731.h"
#include "../../matched/include/Obj06448.h"
#include "../../matched/include/Obj04493.h"
#include "../../matched/include/Obj02469.h"
#include "../../matched/include/Obj04494.h"
#include "../../matched/include/Obj08093.h"
#include "../../matched/include/Obj22879.h"
#include "../../matched/include/Obj22880.h"
#include "../../matched/include/Obj22881.h"
#include "../../matched/include/Obj13951.h"
#include "../../matched/include/Obj22882.h"
#include "../../matched/include/Obj13952.h"
#include "../../matched/include/Obj13953.h"
#include "../../matched/include/Obj22883.h"
#include "../../matched/include/Obj22884.h"

struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Obj;
struct Light;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct MsgBank;
struct PrintSys;
struct Bmp;
struct StrObj;
struct Tcbl;
struct Rec3;
struct S02031140;
struct Blk;
struct Ctx;
struct Slot;
struct Src;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { int a,b,c,d; } Config_021D9624;

typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;

typedef signed short s16;

typedef struct { int x; int y; } Pair;

typedef struct {u32 word[13];} Config_021D9BC0;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FC28(const struct DispConfig *cfg);
extern void func_02050B80(u32 heap);
extern void func_02050ED4(void);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B084(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021D9580(void);
extern void func_02046440(int, int, int, int, int, u32, void (*)(void *));
extern void *func_02048A24(int, int, int, int, int, int, int, int, const void *, const void *, const void *, u32);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_02047964(void *);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_02050BE8(void);
extern void func_02047970(void);
extern void *func_020457B0(u32, u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_020456F8(struct Descriptor *d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02041B6C(unsigned);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(u8 *);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *, u32);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void *func_02028590(u32,u32,u32,u32);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,u32,u32,u32,u32,int,void *,u32,u16,u16);
extern void func_0201F73C(void *, int, int, int);
extern void *func_0201F81C(u32,u32);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02020D10(u8 *p, u32 v);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020350(struct Obj *obj, u32 what);
extern u8 func_02043994(struct Bmp *b);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
u8 *func_021D9624(int arg,u16 heap);
void func_021D96C4(u8 *p);
void func_021D9718(u8 *p);
void func_021D972C(char *p);
void func_021D9738(char *p);
unsigned func_021D9744(char *p);
void func_021D9750(u8 *p);
void func_021D9790(char *p);
void func_021D97B4(void *a, u8 *q);
void func_021D97C8(void *p, u32 a);
void func_021D9828(void *p);
void func_021D9860(void *a0);
void func_021D9864(void *a0);
void func_021D986C(void **p, u32 a, u32 heap);
void func_021D98C0(u8 *p);
void func_021D98E0(void *a0);
void func_021D98E8(void *a0);
unsigned func_021D98F0(unsigned *p);
void func_021D98F4(u32 *p, u32 heap);
void func_021D9960(char *p);
void func_021D9974(void **p);
void func_021D9994(void **p);
void *func_021D99A4(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap);
void func_021D9A40(u8 *p);
void func_021D9A58(u8 *p);
void func_021D9A64(u8 *p, u16 a, int b, int c);
void func_021D9AC8(u8 *p, int a, int b);
void func_021D9B28(u8 *p,unsigned v);
void func_021D9B2C(char *p, u32 a, u32 b, int c);
int func_021D9B34(u8 *p);
void func_021D9B9C(u8 *p);
void func_021D9BC0(const u8 *p,int a,Pair *out);
void func_021D9BE8(u32 mode, const Pair *in, const void *bitmap, void *obj, int a, Pair *out);
void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap);
void func_021D9E04(u8 *p);
void func_021D9E50(u8 *p);
void func_021D9F08(u8 *a, int b, int c, int d);
void func_021D9F24(u8 *p,int mode);
unsigned func_021D9FF8(u8 *p);
void func_021D9FFC(u8 *p, int a, int b);
void func_021DA010(u8 *p);
void *func_021DA038(const u8 *p,u16 heap);
void func_021DA148(u8 *p);
int func_021DA178(char *p);
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,u16 e,int f,u16 heap);
void func_021DA280(u8 *p);
void func_021DA2A8(u8 *p);
int func_021DA2C8(u8 *p);
void func_021DA2F0(u8 *p,u32 i);
void func_021DA318(u8 *p);
void *func_021DA338(char *p,u16 heap);
void func_021DA3C0(u8 *p);
extern const char d_021DFB8C[];
extern const int d_021DF604[];
extern const Config_021D9624 d_021DF598;
extern const Entry d_021DF634[];
extern const u32 d_021DF5A8[];
extern const u32 d_021DF5C4[];
extern const u32 d_021DF574[];
extern const u32 d_021DF58C[];
extern const u32 d_021DF580[];
extern const char d_021DFBA0[];
extern const Config_021D9BC0 d_021DF78C;



/*
 * volatile: hardware reads at 021D9654 and 021D965E
 */
u8 *func_021D9624(int arg,u16 heap)
{
    u8 *p;
    p=func_02030734(heap,28,0,d_021DFB8C,448);
    func_02082BCC(p,0,28);
    ((struct Obj13944 *)p)->f18=heap;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021DF604);
    func_0204363C(arg);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021D97C8(p,heap);
    func_021D986C((void **)(p+4),(u32)d_021DF604,heap);
    ((struct Obj13944 *)p)->f14=func_020056A0(func_021D97B4,p,0);
    return p;
}



/*
 * volatile: hardware reads at 021D96EA and 021D96F4
 */
void func_021D96C4(u8 *p)
{
    func_02030EAC(((struct Obj22873 *)p)->f14);
    func_021D98C0(p+4);
    func_021D9828(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,28);
    func_020307B0(p);
}




/*
 * Addresses are Black-image addresses.
 */
void func_021D9718(u8 *p)
{
    func_021D98E0(p + 4);
    func_021D9860(p);
}



void func_021D972C(char *p) { func_021D9974((void **)(p+12)); }



void func_021D9738(char *p) { func_021D9994((void **)(p+12)); }



unsigned func_021D9744(char *p) { return func_021D98F0((unsigned *)(p+4)); }



void func_021D9750(u8 *p)
{
    Config_021D9624 c;
    func_02040588(0,0);
    c=d_021DF598;
    c.d=1;
    func_0203FC28((const struct DispConfig *)(&c));
    func_021D98F4((u32 *)(p+12),((struct Obj13945 *)p)->f18);
    func_02050B80(((struct Obj13945 *)p)->f18);
}




void func_021D9790(char *p) { func_02040588(0,0);func_02050ED4();func_021D9960(p+12);func_0203FC28((const struct DispConfig *)&d_021DF598); }





void func_021D97B4(void *a, u8 *q)
{
    func_021D9864(q);
    func_021D98E8(q + 4);
}




void func_021D97C8(void *p, u32 a)
{
    u32 i;
    const Entry *e;
    u32 id;
    i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(a);
    func_02045088(a);
    func_0203FC28((const struct DispConfig *)&d_021DF598);
    do {
        e = &d_021DF634[i];
        id = e->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)e->config, (u8)e->a);
        func_020414AC((u8)id);
        func_02040588((u8)id, (u8)e->b);
        ++i;
    } while (i < 7);
}




/*
 * note: u8 extern parameter reproduces original truncation before BLX.
 */
void func_021D9828(void *p) {
    u32 i=0;
    do { func_020403F4((u8)d_021DF634[i].id); ++i; } while(i<7);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}




/*
 * note: two trailing zero alignment bytes.
 */
void func_021D9860(void *a0) {}




void func_021D9864(void *a0) { func_020419E4(); }




void func_021D986C(void **p, u32 a, u32 heap)
{
    void *q;
    func_02082BCC(p, 0, 8);
    func_0204A48C((const struct Cfg *)d_021DF5A8, a, heap);
    p[0] = func_0204B100(128, 0, heap);
    q = func_0204B034((unsigned char *)d_021DF5C4, 2, heap);
    p[1] = q;
    func_0204B258(p[0], q);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}




void func_021D98C0(u8 *p) {
    func_0204B084(((struct Obj13946 *)p)->f4);
    func_0204B1CC(((struct Obj13946 *)p)->f0);
    func_0204A5AC();
    func_02082BCC(p,0,8);
}




void func_021D98E0(void *a0) { func_0204A600(); }




/*
 * note: tail wrapper plus unlabelled getter follower; seed 021D98F0.
 */
void func_021D98E8(void *a0) { func_0204A648(); }




unsigned func_021D98F0(unsigned *p) { return *p; }




void func_021D98F4(u32 *p, u32 heap)
{
    func_02046440(0, 1, 0, 1, 0, heap, (void (*)(void *))func_021D9580);
    p[0] = (u32)func_02048A24(2, 0x18000, -0x18000, -0x20000, 0x20000, 0x1000, 0x400000, 0,
                         d_021DF574, d_021DF58C, d_021DF580, heap);
    p[1] = 1;
}





void func_021D9960(char *p)
{
    ((struct Obj13948 *)p)->f4 = 0;
    func_02048AC4(((struct Obj13948 *)p)->f0);
    func_02046788();
}




void func_021D9974(void **p) {
    if(((struct Obj10413 *)p)->f4) {
        func_02047964(((struct Obj10413 *)p)->f4);
        func_02048AD0(((struct Obj10413 *)p)->f0);
        func_020479D8();
        func_02050BE8();
    }
}





void func_021D9994(void **p)
{
    if (p[1])
        func_02047970();
}




void *func_021D99A4(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap)
{
    u8 *p;
    void *q;
    p = func_02030734(heap, 0x28, 0, d_021DFBA0, 0x55);
    func_02082BCC(p, 0, 0x28);
    ((struct Obj01929 *)p)->f8 = h;
    ((struct Obj01929 *)p)->f14 = b;
    ((struct Obj01929 *)p)->f16 = 0x440;
    ((struct Obj01929 *)p)->f24 = a;
    ((struct Obj01929 *)p)->f10 = func_020457B0(0x200, heap);
    q = (void *)func_020450F0((u8)b, (u16)c, (u16)d, (u8)e, f, g, 1);
    ((struct Obj01929 *)p)->fC = q;
    ((struct Obj01929 *)p)->f0 = q;
    p[4] = 0;
    func_02043B5C(func_02045770(q), ((struct Obj01929 *)p)->f16 & 31);
    if (((struct Obj01929 *)p)->f24 == 0) {
        func_02045334(((struct Obj01929 *)p)->fC);
        func_02045374(((struct Obj01929 *)p)->fC);
        func_020409B4(func_02045730(((struct Obj01929 *)p)->fC));
    }
    return p;
}





void func_021D9A40(u8 *p)
{
    func_020452E8(((struct Obj13950 *)p)->fC);
    func_02045808(((struct Obj13950 *)p)->f10);
    func_020307B0(p);
}




void func_021D9A58(u8 *p) { func_020456F8(((struct Obj22875 *)p)->fC); }




/*
 * extent: two zero padding bytes at 0x021D9AC6.
 */
void func_021D9A64(u8 *p, u16 a, int b, int c)
{
    Pair xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045CAC((struct MsgBank *)a, b, ((struct Obj01057 *)p)->f10);
    func_021D9BC0(p, c, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), c, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}




/*
 * extent: two zero padding bytes at 0x021D9B26.
 */
void func_021D9AC8(u8 *p, int a, int b)
{
    Pair xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045838(((struct Obj01057 *)p)->f10, (struct U16Vec *)a);
    func_021D9BC0(p, b, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), b, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}




void func_021D9B28(u8 *p,unsigned v) { ((struct Obj22876 *)p)->f16=v; }





void func_021D9B2C(char *p, u32 a, u32 b, int c)
{
    *(u32 *)(p + 0x18) = a;
    *(u32 *)(p + 0x1c) = b;
    *(u32 *)(p + 0x20) = c;
}




int func_021D9B34(u8 *p)
{
    u32 q;
    if (((struct Obj02179 *)p)->f24 == 0) {
        q = ((struct Obj02179 *)p)->f8;
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj02179 *)p)->f0);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)(((struct Obj02179 *)p)->f8), (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}




void func_021D9B9C(u8 *p) {
    func_02045334(((struct Obj08092 *)p)->fC);
    if(((struct Obj08092 *)p)->f24==1) {
        func_02045374(((struct Obj08092 *)p)->fC);
        func_02041B6C(func_02045730(((struct Obj08092 *)p)->fC));
    }
}



/*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 */
void func_021D9BC0(const u8 *p,int a,Pair *out) {
    void *bitmap=func_02045770(((struct Obj01057 *)p)->fC);
    func_021D9BE8(((struct Obj01057 *)p)->f20,(const Pair *)(p+0x18),bitmap,((struct Obj01057 *)p)->f10,a,out);
}



/*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a Pair assignment.
 */
void func_021D9BE8(u32 mode, const Pair *in, const void *bitmap, void *obj, int a, Pair *out)
{
    int x;
    int y;
    switch (mode) {
    case 0:
        *out = *in;
        return;
    case 1:
        x = (u32)func_020437DC(bitmap) / 2;
        y = (u32)func_020437E4(bitmap) / 2;
        x -= func_0201D304(obj, a, 0) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)func_020437E4(bitmap) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = func_020437DC(bitmap);
        x -= func_0201D304(obj, a, 0);
        if (x < 0) x = 0;
        out->x = x + in->x;
        out->y = in->y;
        break;
    }
}



static inline void *allocate(u16 heap, u32 size, const char *site, u16 line)
{
    return func_02030734(heap, size, 0, site, line);
}



/*
 * lever: final push 2026-10-05 G3L5. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, func_020457B0 second, func_0203101C first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order
 *   (lsls of the line constant after the heap load). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov177 func_021E8568.
 */
void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = func_020457B0(0x300, heap);
    q = (void *)func_020450F0((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    *(void **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}



/*
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, func_020457B0 second, func_0203101C first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 func_021D9CA4.
 */
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = func_02030734(heap, 0x40, 0, d_021DFBA0, 0x1ae);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    func_02028470(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = func_020457B0(0x200, heap);
    q = (struct Descriptor *)func_020450F0((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    func_02045334(q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730(q));
    *(struct Tcbl **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}



void func_021D9E04(u8 *p)
{
    if (((struct Obj02180 *)p)->f8) {
        func_0201CE48(((struct Obj02180 *)p)->f8);
        ((struct Obj02180 *)p)->f8 = 0;
    }
    if (((struct Obj02180 *)p)->f3C) {
        func_0202F038(((struct Obj02180 *)p)->f3C);
        ((struct Obj02180 *)p)->f3C = 0;
    }
    if (((struct Obj02180 *)p)->f30) func_02028604((int)(((struct Obj02180 *)p)->f30));
    func_02031140(((struct Obj02180 *)p)->fC);
    func_0201F7A8(((struct Obj02180 *)p)->f10, 0);
    func_020452E8(((struct Obj02180 *)p)->f10);
    func_02045808(((struct Obj02180 *)p)->f14);
    func_020307B0(p);
}



/*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 */
void func_021D9E50(u8 *p)
{
    u32 q;
    switch (((struct Obj00909 *)p)->f28) {
    case 2:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        ((struct Obj00909 *)p)->f2C = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (((struct Obj00909 *)p)->f8) {
            if (((struct Obj00909 *)p)->f30)
                func_020286C4((struct Ctx *)(((struct Obj00909 *)p)->f30), (void *)(((struct Obj00909 *)p)->f8), (void *)(((struct Obj00909 *)p)->f10));
            if (func_02028484((struct Blk *)(p + 0x34), (void *)(((struct Obj00909 *)p)->f8)))
                ((struct Obj00909 *)p)->f2C = 1;
        }
        break;
    case 3:
        break;
    }
    func_020310C4((struct Tcbl *)(((struct Obj00909 *)p)->fC));
}




void func_021D9F08(u8 *a, int b, int c, int d)
{
    func_02045CAC((struct MsgBank *)b, c, ((struct Obj00236 *)a)->f14);
    func_021D9F24(a, d);
}



void func_021D9F24(u8 *p,int mode)
{
    u32 q;
    func_02043B5C(func_02045770(((struct Obj00236 *)p)->f10),((struct Obj00236 *)p)->f18);
    if(((struct Obj00236 *)p)->f8) {
        func_0201CE48(((struct Obj00236 *)p)->f8);
        ((struct Obj00236 *)p)->f8=0;
    }
    if(((struct Obj00236 *)p)->f30) {
        func_02028604((int)(((struct Obj00236 *)p)->f30));
        ((struct Obj00236 *)p)->f30=0;
    }
    func_021DA010(p);
    switch(mode) {
    case 2:
        ((struct Obj00236 *)p)->f3C=func_0202EE30((void *)func_020056BC(),((struct Obj00236 *)p)->f10,((struct Obj00236 *)p)->f18,16,((struct Obj00236 *)p)->f1A);
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 0:
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 1:
        func_02028470(p+0x34,2);
        ((struct Obj00236 *)p)->f30=func_02028590(((struct Obj00236 *)p)->f18,1,0,((struct Obj00236 *)p)->f1A);
        ((struct Obj00236 *)p)->f8=func_0201CCE4(((struct Obj00236 *)p)->f10,0,0,*(u32 *)&((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4,func_02012FFC(),((struct Obj00236 *)p)->fC,0,((struct Obj00236 *)p)->f1A,((struct Obj00236 *)p)->f18);
        ((struct Obj00236 *)p)->f28=1;
        break;
    }
    ((struct Obj00236 *)p)->f2C=0;
}



unsigned func_021D9FF8(u8 *p) { return ((struct Obj22877 *)p)->f2C; }




void func_021D9FFC(u8 *p, int a, int b)
{
    func_0201F73C(((struct Obj22878 *)p)->f10, 0, a, b);
}



void func_021DA010(u8 *p) { ((struct Obj00236 *)p)->f2C=1; if(*(u8 * *)&((struct Obj00236 *)p)->f3C) { func_0202F038(*(u8 * *)&((struct Obj00236 *)p)->f3C); *(u32 *)&((struct Obj00236 *)p)->f3C=0; func_02045374(((struct Obj00236 *)p)->f10); func_020409B4(func_02045730(((struct Obj00236 *)p)->f10)); } }



/*
 * lever: const source parameter and the original heap stack argument to 0201F878.
 */
void *func_021DA038(const u8 *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    Config_021D9BC0 cfg;
    out=func_02030734(heap,24,0,d_021DFBA0,0x2cb);
    func_02082BCC(out,0,24);
    ((struct Obj01731 *)out)->f4=((struct Obj01542 *)p)->f8;
    ((struct Obj01731 *)out)->f0=(void *)func_020450F0((u8)(((struct Obj01542 *)p)->f1C),(u16)19,(u16)((u8)(17-(u8)(((struct Obj01542 *)p)->f18*2))),(u8)12,(u8)(((struct Obj01542 *)p)->f18*2),((struct Obj01542 *)p)->f1E,1);
    func_0201F73C(((struct Obj01731 *)out)->f0,2,((struct Obj01542 *)p)->f22,(u8)(((struct Obj01542 *)p)->f20));
    q=((struct Obj01731 *)out)->f0;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    ((struct Obj01731 *)out)->f8=((struct Obj01731 *)out)->f0;
    out[12]=0;
    ((struct Obj01731 *)out)->f14=func_0201F81C(((struct Obj01542 *)p)->f18,heap);
    for(i=0;i<((struct Obj01542 *)p)->f18;i++)
        func_0201F878(((struct Obj01731 *)out)->f14,((struct Obj01542 *)p)->f0,*(u32 *)(p+12+i*4),i,(u16)heap);
    cfg=d_021DF78C;
    cfg.word[0]=*(u32 *)&((struct Obj01731 *)out)->f14;
    *(u16 *)((u8 *)&cfg+0x10)=((struct Obj01542 *)p)->f18;
    *(u16 *)((u8 *)&cfg+0x12)=((struct Obj01542 *)p)->f18;
    cfg.word[3]=*(u32 *)&((struct Obj01731 *)out)->f0;
    cfg.word[9]=((struct Obj01542 *)p)->f0;
    cfg.word[10]=(u32)(out+8);
    cfg.word[11]=((struct Obj01542 *)p)->f8;
    cfg.word[12]=((struct Obj01542 *)p)->f4;
    ((struct Obj01731 *)out)->f10=func_0201FF30((struct Src *)(&cfg),0,0,heap);
    func_02020CF8(((struct Obj01731 *)out)->f10,heap);
    func_02020D10(((struct Obj01731 *)out)->f10,0);
    return out;
}



void func_021DA148(u8 *p) { func_0202020C(((struct Obj06448 *)p)->f10,0,0); func_0201F868(((struct Obj06448 *)p)->f14); func_0201F7A8(((struct Obj06448 *)p)->f0,0); func_020456F8(((struct Obj06448 *)p)->f0); func_020452E8(((struct Obj06448 *)p)->f0); func_020307B0(p); }



/*
 * extent: two bytes of zero alignment padding follow the return.
 */
int func_021DA178(char *p)
{
    u32 q = ((struct Obj04493 *)p)->f4;
    int r;
    if (((struct Obj04493 *)p)->fC) {
        if (func_0201C6C4((struct PrintSys *)q,(void *)((u32)func_02045770((struct Descriptor *)((struct Obj04493 *)p)->f8))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj04493 *)p)->f8);
            ((struct Obj04493 *)p)->fC=0;
        }
    }
    r=func_020200CC(((struct Obj04493 *)p)->f10);
    if (r == -2) r=func_02020350(((struct Obj04493 *)p)->f10,2)-1;
    return r;
}



/*
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 */
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u8 c,u32 d,u16 e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x374);
    func_02082BCC(out,0,size);
    *(const char * *)&((struct Obj04494 *)out)->f0=desc;
    ((struct Obj04494 *)out)->f4=n;
    ((struct Obj04494 *)out)->f8=f;
    ((struct Obj04494 *)out)->fC=e;
    for(i=0;i<((struct Obj04494 *)out)->f4;i++) {
        const char *v=desc+i*24;
        char *slot=out+i*4;
        void *q=func_021D99A4((u32)a,b,((struct Obj02469 *)v)->f0,((struct Obj02469 *)v)->f1,((struct Obj02469 *)v)->f2,((struct Obj02469 *)v)->f3,c,d,heap);
        ((struct Obj08093 *)slot)->f10=q;
        func_021D9B2C(q,((struct Obj02469 *)v)->f10,((struct Obj02469 *)v)->f12,((struct Obj02469 *)v)->fC);
        func_021D9B28(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f14);
        if(((struct Obj02469 *)v)->f8) func_021D9AC8(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f8,((struct Obj04494 *)out)->f8);
        else func_021D9A64(((struct Obj08093 *)slot)->f10,e,((struct Obj02469 *)v)->f4,((struct Obj04494 *)out)->f8);
    }
    return out;
}



void func_021DA280(u8 *p) { u32 i; for(i=0;i<((struct Obj22879 *)p)->f4;i++) func_021D9A40(*(u8 **)(p+16+i*4)); func_020307B0(p); }



void func_021DA2A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22880 *)p)->f4;i++) func_021D9A58(*(u8 **)(p+16+i*4)); }



int func_021DA2C8(u8 *p) { u32 i; int result=1; for(i=0;i<((struct Obj22881 *)p)->f4;i++) result &= func_021D9B34(*(u8 **)(p+16+i*4)); return result; }



void func_021DA2F0(u8 *p,u32 i) { u8 *d=*(u8 **)(p+16+i*4); func_02043B5C(func_02045770(((struct Obj13951 *)d)->fC),((struct Obj13951 *)d)->f16&31); func_02045334(*(void **)(*(u8 **)(p+16+i*4)+12)); }



void func_021DA318(u8 *p) { u32 i; for(i=0;i<((struct Obj22882 *)p)->f4;i++) func_021D9B9C(*(u8 **)(p+16+i*4)); }



/*
 * lever: heap is u16 in this function and the two callees receiving it.
 */
void *func_021DA338(char *p,u16 heap)
{
    u32 i;
    int size=((struct Obj13952 *)p)->f4*4+8;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x42e);
    func_02082BCC(out,0,size);
    *(char * *)&((struct Obj13953 *)out)->f4=p;
    ((struct Obj13953 *)out)->f0=heap;
    for(i=0;i<((struct Obj13952 *)p)->f4;i++) {
        void *win=func_02045770(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=func_020437DC(win);
        u32 y=func_020437E4(win);
        u32 type=func_02043994(win);
        *(void **)(out+i*4+8)=func_02043678(x/8,y/8,type,heap);
    }
    return out;
}



void func_021DA3C0(u8 *p) { u32 i; for(i=0;i<((struct Obj22884 *)(*(u8 * *)&((struct Obj22883 *)p)->f4))->f4;i++) func_020437AC(*(void **)(p+8+i*4)); func_020307B0(p); }
