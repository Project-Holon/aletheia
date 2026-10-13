/*
 * function: func_021B8990
 * address:  0x021B8990
 * packet:   pkt_ov070_021B8990
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Exit proc of the ov070 proc triple (pool words at 0x021BB96C..74): once
 * the fade is done, tear down the menu's windows, sprites and text, hand the
 * selection back through the parent's work (+0x34/+0x38) and free the proc.
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_021B9AF8  0x021B9AF8  thumb  ov070
 *   func_021B9758  0x021B9758  thumb  ov070
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021BAF10  0x021BAF10  thumb  ov070
 *   func_0203FB44  0x0203FB44  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02028604  0x02028604  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_021B8E84  0x021B8E84  thumb  ov070
 *   func_021B8B6C  0x021B8B6C  thumb  ov070
 *   func_02051C6C  0x02051C6C  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   KEY_SetRepeatSpeed  0x02036270  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct Parent {
    u8 pad00[0x34];
    u32 f34;
    u32 f38;
} Parent;

typedef struct Obj {
    u8 pad000[0x14];
    void *gfx;
    u8 pad018[0x4FC - 0x18];
    u32 f4FC;
    u8 pad500[0x50C - 0x500];
    u32 f50C;
    u8 pad510[0x518 - 0x510];
    u32 f518;
    u32 f51C;
    u32 f520;
    u32 f524;
    u32 f528;
    u32 f52C;
    u32 f530;
    u8 pad534[0x694 - 0x534];
    u32 f694;
    u32 f698;
    u8 pad69C[0x730 - 0x69C];
    u32 f730;
    u8 pad734[0x7E0 - 0x734];
    u32 f7E0;
    u8 pad7E4[0x80C - 0x7E4];
    int f80C;
    int f810;
    int f814;
    u8 pad818[0x838 - 0x818];
    u32 f838;
    u8 pad83C[0x844 - 0x83C];
    u32 f844;
    u8 pad848[0x84C - 0x848];
    u32 f84C;
    u8 pad850[0x86C - 0x850];
    u32 f86C;
    u32 f870;
} Obj;

struct MyItemSave;
extern u32 func_020221A4(void);
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02030EAC(struct Node *n);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021B9AF8(char *p);
extern void func_021B9758(char *p);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021BAF10(char *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern u32 func_0201D83C(void *ptr);
extern int func_02028604(int a0);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021B8E84(char *p);
extern void func_021B8B6C(char *p);
extern void func_02051C6C(void *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern int KEY_SetRepeatSpeed(int a0, int a1);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);

int func_021B8990(void *proc, int b, Parent *par, Obj *o)
{
    if (func_020221A4() != 1)
        return 0;
    if (func_0201C6B4((const struct PrintSys *)o->f50C) == 0)
        return 0;
    func_02030EAC((struct Node *)o->f698);
    func_02008298(o->gfx, o->f80C);
    func_02008288(o->gfx, (u16)o->f80C, o->f810, o->f814 + 1);
    func_02027FD8((struct TaskMenuState *)o->f7E0);
    func_021B9AF8((char *)o);
    func_021B9758((char *)o);
    func_02031140((struct S02031140 *)o->f730);
    func_02045C04((struct Rec *)o->f51C);
    func_02045808((struct U16Vec *)o->f524);
    func_02045808((struct U16Vec *)o->f528);
    func_02045808((struct U16Vec *)o->f52C);
    func_0201ED04((struct WordSet *)o->f520);
    func_021BAF10((char *)o);
    if (o->f4FC != 0) {
        func_0203FB44((int)3, (unsigned short)o->f838, (unsigned short)(o->f838 >> 16));
        func_020452E8((struct Descriptor *)o->f4FC);
    }
    func_02040DA8(3, 1, 0);
    func_0201D83C((void *)o->f530);
    func_02028604(o->f518);
    func_0201C6EC((struct PrintSys *)o->f50C);
    func_0201C4C0((struct PrintSys *)o->f50C);
    func_021B8E84((char *)o);
    func_021B8B6C((char *)o);
    func_02051C6C((void *)o->f694);
    func_020450C8();
    func_0203F9B4();
    par->f34 = o->f844;
    par->f38 = o->f84C;
    KEY_SetRepeatSpeed(o->f86C, o->f870);
    func_020315D4(proc);
    func_020306F0(0xE);
    return 1;
}
