/*
 * file:     unit_021B6100_p01.c
 * unit:     yes
 * function: func_021B6100, func_021B6174, func_021B6250, func_021B6278, func_021B6348, func_021B6390, func_021B63AC, func_021B6460, func_021B6498, func_021B64C0, func_021B64D0, func_021B6678, func_021B66BC, func_021B6794, func_021B67A4, func_021B6828, func_021B6850, func_021B688C, func_021B68B0, func_021B68C8, func_021B69F8, func_021B6A64, func_021B6AAC
 * address:  0x021B6100
 * region:   ov173
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
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_021B7ADC 0x021B7ADC thumb ov173
 *   func_0203D34C 0x0203D34C arm
 *   func_021B6B0C 0x021B6B0C thumb ov173
 *   func_021B6B54 0x021B6B54 thumb ov173
 *   func_021B6B6C 0x021B6B6C thumb ov173
 *   func_021B6BA0 0x021B6BA0 thumb ov173
 *   func_021B7B60 0x021B7B60 thumb ov173
 *   func_021B7B8C 0x021B7B8C thumb ov173
 *   func_021B7C00 0x021B7C00 thumb ov173
 *   func_021B8110 0x021B8110 thumb ov173
 *   func_021B815C 0x021B815C thumb ov173
 *   func_021B817C 0x021B817C thumb ov173
 *   func_0204A600 0x0204A600 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   d_021B81FC 0x021B81FC data a4
 *   d_021B81EC 0x021B81EC data a4
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02028178  0x02028178  thumb
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_0204363C  0x0204363C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02049238  0x02049238  arm
 *   func_021B7A00  0x021B7A00  thumb  ov173
 *   func_021B7128  0x021B7128  thumb  ov173
 *   func_021B6BCC  0x021B6BCC  thumb  ov173
 *   func_021B6CC0  0x021B6CC0  thumb  ov173
 *   func_021B7C44  0x021B7C44  thumb  ov173
 *   func_021B8040  0x021B8040  thumb  ov173
 *   func_021B7C7C 0x021B7C7C thumb ov173
 *   func_021B71B8 0x021B71B8 thumb ov173
 *   func_021B7694 0x021B7694 thumb ov173
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7908 0x021B7908 thumb ov173
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   d_02FE0000 0x02FE0000 data a4
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040588 0x02040588 arm
 *   func_02040B94 0x02040B94 arm
 *   d_021B8280 0x021B8280 data a4
 *   d_021B82F0 0x021B82F0 data a4
 *   d_021B8330 0x021B8330 data a4
 *   d_021B8290 0x021B8290 data a4
 *   d_021B82B0 0x021B82B0 data a4
 *   d_021B82D0 0x021B82D0 data a4
 *   d_021B8310 0x021B8310 data a4
 *   func_02043598 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021B8420 0x021B8420 data a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02028590 0x02028590 thumb
 *   func_02028604 0x02028604 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021B7F50 0x021B7F50 thumb ov173
 *   func_021B80EC 0x021B80EC thumb ov173
 *   func_021B80A4 0x021B80A4 thumb ov173
 *   func_021B80C4 0x021B80C4 thumb ov173
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   func_021B7FD0 0x021B7FD0 thumb ov173
 *   func_02027778 0x02027778 thumb
 *   func_021B81B0 0x021B81B0 thumb ov173
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027974 0x02027974 thumb
 *   func_02027858 0x02027858 thumb
 *   d_021B8228 0x021B8228 data a4
 */
#include "../../matched/include/Obj06563.h"
#include "../../matched/include/Obj24149.h"
#include "../../matched/include/Obj06564.h"
#include "../../matched/include/Obj00362.h"
#include "../../matched/include/Obj00180.h"
#include "../../matched/include/Obj05449.h"
#include "../../matched/include/G_021B81EC.h"
#include "../../matched/include/Obj24150.h"
#include "../../matched/include/Obj24151.h"
#include "../../matched/include/Obj04557.h"
#include "../../matched/include/Obj06565.h"
#include "../../matched/include/Obj24152.h"
#include "../../matched/include/Obj24153.h"
#include "../../matched/include/Obj24154.h"
#include "../../matched/include/Obj24155.h"
#include "../../matched/include/Obj24156.h"
#include "../../matched/include/Obj14313.h"
#include "../../matched/include/Obj08264.h"

struct Obj0203159C;
struct GfFont;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct S020315D4;
struct MsgBank;
struct R;
struct TaskMenuState;
struct U16Vec;
struct Node;
struct DispVram;
struct Descriptor;
struct CharBuf;
struct WordSet;
struct Rec;
struct Sound;
struct Ctx;
struct Rec3;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 id,value;} Row;

typedef enum { FLAGS_OFFSET=0x3ff8, OFFSET_FORCE_UNSIGNED=0xffffffffu } SharedOffset;

struct DispConfig {u32 unk_00,unk_04,unk_08,unk_0c;};

struct BgTemplate {u32 unk_00,unk_04,bufSize,unk_0c;u8 unk_10,unk_11,unk_12,unk_13;u32 unk_14;u8 unk_18,unk_19,unk_1a,unk_1b;u32 unk_1c;};

typedef struct { u32 a,b,c,d,e,f,g; } Entry;

typedef signed int     s32;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;

typedef int (*Callback)(u8 *);

typedef struct { Callback a,b; } Pair;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_021B7ADC(unsigned char *p, u32 idx, int unused);
extern void func_0203D34C(u32 a, u32 b);
extern int func_021B6B0C(char **p);
extern int func_021B6B54(int *p);
extern int func_021B6B6C(char *p);
extern int func_021B6BA0(char *p);
extern int func_021B7B60(u8 *p);
extern int func_021B7B8C(char *p);
extern int func_021B7C00(void *);
extern int func_021B8110(u8 *p);
extern int func_021B815C(char *p);
extern int func_021B817C(char *p);
extern void func_0204A600(void);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021B7EB0(char *p, int flag);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02028178(u8 *p);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_0204363C(u32 swap);
extern u32 func_020056A0(void (*cb)(void), void *p, int n);
extern void func_02049238(u32 a);
extern void func_021B7A00(char *p, void *arg);
extern void func_021B7128(char *p);
extern void func_021B6BCC(char *p);
extern void func_021B6CC0(char *p);
extern void func_021B7C44(u8 *p);
extern void func_021B8040(u8 *p);
extern int func_021B7C7C(int *);
extern void func_021B71B8(char *);
extern void func_021B7694(u8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_021B7908(char *);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020403F4(unsigned int);
extern void func_0203F9B4(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_020307B0(void *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 func_02028590(int,int,int,int);
extern int func_02028604(int);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_020221A4(void);
extern u8 func_020260E0(struct Sound *);
extern int func_02025DE8(struct Sound *);
extern int func_02035C60(void);
extern void func_020061E4(unsigned);
extern int func_021B7F50(char *);
extern int func_021B80EC(char *,u16);
extern int func_021B80A4(char *,u16);
extern int func_021B80C4(u8 *p, u16 n);
extern u16 func_021B7438(char **);
extern void func_021B71C4(char *,int);
extern void func_021B70D8(char *);
extern void func_021B7F64(char *);
extern void func_021B7FD0(u8 *,int);
extern u32 func_0201CE30(void *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *p);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_021B81B0(int);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027974(u32);
extern void func_02027858(struct TaskMenu *m);
int func_021B6100(struct Obj0203159C *obj, int unused, u8 *input);
int func_021B6174(void *unused0,u32 *state,void *unused2,u8 *p);
int func_021B6250(void *p,u32 a,u32 b,char *ctx);
void func_021B6278(u8 *p);
void func_021B6348(u8 *p);
void func_021B6390(int *p);
void func_021B63AC(u8 *p);
void func_021B6460(char *p);
void func_021B6498(void *unused,char *p);
void func_021B64C0(void);
void func_021B64D0(void);
void func_021B6678(void);
void func_021B66BC(u8 *p, u8 *q);
int func_021B6794(int *p);
void func_021B67A4(u8 *p);
void func_021B6828(char *p);
void func_021B6850(char *p);
void func_021B688C(char *p);
int func_021B68B0(int *p);
int func_021B68C8(char *p);
int func_021B69F8(char *p);
int func_021B6A64(u8 *p);
int func_021B6AAC(u8 *p);
extern struct G_021B81EC d_021B81EC[];
extern const Row d_021B81FC[];
extern u8 d_02FE0000[];
extern const struct DispConfig d_021B8280;
extern const struct BgTemplate d_021B82F0,d_021B8330,d_021B8290,d_021B82B0,d_021B82D0,d_021B8310;
extern const Entry d_021B8420[];
extern Pair d_021B8228[];

int func_021B6100(struct Obj0203159C *obj, int unused, u8 *input)
{
    u8 *p;
    func_0203064C(1,79,0x50000);
    p=func_0203159C(obj,0x228,79);
    func_02082BCC(p,0,0x228);
    *(u8 * *)&((struct Obj06563 *)p)->f0=input;
    ((struct Obj06563 *)p)->f60=(u32)func_0201D7EC(23,0,0,0,79);
    ((struct Obj06563 *)p)->f64=(u32)func_0203101C(79,79,32,32);
    func_021B63AC(p);
    func_021B7ADC(p,(u8)(((struct Obj24149 *)(*(u8 * *)&((struct Obj06563 *)p)->f0))->f14),3);
    ((struct Obj06563 *)p)->f1B0=1;
    func_0203D34C(1,79);
    return 1;
}

/*
 * extent: final 2 bytes are alignment padding
 */
int func_021B6174(void *unused0,u32 *state,void *unused2,u8 *p)
{
    switch(*state) {
    case 0: *state=func_021B68B0((int *)p);break;
    case 1: *state=func_021B68C8((char *)p);break;
    case 2: *state=func_021B69F8((char *)p);break;
    case 3: *state=func_021B6A64(p);break;
    case 4: *state=func_021B6AAC(p);break;
    case 5: *state=func_021B6B0C((char **)p);break;
    case 6: *state=func_021B6B54((int *)p);break;
    case 7: *state=func_021B6B6C((char *)p);break;
    case 8: *state=func_021B6BA0((char *)p);break;
    case 9: return 1;
    case 10: *state=func_021B7B60(p);break;
    case 11: *state=func_021B7B8C((char *)p);return 0;
    case 12: *state=func_021B7C00(p);return 0;
    case 13: *state=func_021B8110(p);break;
    case 14: *state=func_021B815C((char *)p);break;
    case 15: *state=func_021B817C((char *)p);break;
    }
    func_021B6390((int *)p);
    func_0204A600();
    func_020310C4(((struct Obj06564 *)p)->f64);
    func_0201C4E4(((struct Obj06564 *)p)->f218);
    return 0;
}

int func_021B6250(void *p,u32 a,u32 b,char *ctx) { func_021B6460(ctx); func_02031140(((struct Obj00362 *)ctx)->f64); func_0201D83C(((struct Obj00362 *)ctx)->f60); func_020315D4(p); func_020306F0(79); return 1; }

void func_021B6278(u8 *p)
{
    int i;
    const Row *r;
    u8 *q;
    ((struct Obj00180 *)p)->f218=func_0201C440((void *)79);
    ((struct Obj00180 *)p)->f1DC=func_02027F60(4,10,((struct Obj00180 *)p)->f60,((struct Obj00180 *)p)->f218,79);
    for(i=0;i<2;i++) {
        r=&d_021B81FC[i];q=p+i*12;
        ((struct Obj05449 *)q)->f1E4=func_02045EC0(((struct Obj00180 *)p)->f44,r->id);
        ((struct Obj05449 *)q)->f1E8=14819;
        ((struct Obj05449 *)q)->f1EC=r->value;
    }
    for(i=0;i<2;i++) {
        r=&((Row *)d_021B81EC)[i];q=p+i*12;
        ((struct Obj05449 *)q)->f1FC=func_02045EC0(((struct Obj00180 *)p)->f44,r->id);
        ((struct Obj05449 *)q)->f200=14819;
        ((struct Obj05449 *)q)->f204=r->value;
    }
    ((struct Obj00180 *)p)->f220=0;((struct Obj00180 *)p)->f224=0;
}

/*
 * Extent remainder: two zero alignment bytes at 021B638E.
 */
void func_021B6348(u8 *p)
{
    func_021B7EB0((char *)p, 0);
    func_02045808((struct U16Vec *)(((struct Obj00362 *)p)->f1E4));
    func_02045808((struct U16Vec *)(((struct Obj00362 *)p)->f1F0));
    func_02045808((struct U16Vec *)(((struct Obj00362 *)p)->f1FC));
    func_02045808((struct U16Vec *)(((struct Obj00362 *)p)->f208));
    func_02027FD8((struct TaskMenuState *)(((struct Obj00362 *)p)->f1DC));
    func_0201C4C0((struct PrintSys *)(((struct Obj00362 *)p)->f218));
}


void func_021B6390(int *p)
{
    if (((struct Obj06564 *)p)->f220) {
        func_02028178((u8 *)(((struct Obj06564 *)p)->f220));
        func_02028178((u8 *)(((struct Obj06564 *)p)->f224));
    }
}


void func_021B63AC(u8 *p)
{
    u8 *q;

    func_020434CC();
    func_02043588();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    q = func_020490F4(0x7c, 0x4f);
    func_021B64C0();
    func_021B64D0();
    func_021B66BC(p, q);
    func_021B7A00((char *)p, q);
    func_021B6850((char *)p);
    func_021B67A4(p);
    func_021B7128((char *)p);
    func_021B6BCC((char *)p);
    func_021B6CC0((char *)p);
    func_021B7C44(p);
    func_021B8040(p);
    func_0202208C(0, 1, 1, 0, 6, 1, 0x4f);
    func_0204363C(1);
    ((struct Obj00180 *)p)->f68 = (u32)func_020056A0((void (*)(void))func_021B6498, p, 0x10);
    func_02049238((u32)q);
    func_021B6278(p);
}

void func_021B6460(char *p) { func_021B6348((u8 *)p); func_021B7C7C((int *)p); func_021B71B8(p); func_021B6828(p); func_021B6794((int *)p); func_021B6678(); func_021B688C(p); func_021B7694((u8 *)p); func_02030EAC(((struct Obj00362 *)p)->f68); }

static inline void setShared(u32 base,SharedOffset off) { *(u32 *)(base+off)|=1; }

void func_021B6498(void *unused,char *p) { func_021B7908(p); func_020419E4(); func_0204A648(); setShared((u32)d_02FE0000,FLAGS_OFFSET); }


void func_021B64C0(void)
{
    func_020433E0((void *)0x021B8250);
}

void func_021B64D0(void)
{
    struct DispConfig cfg;
    struct BgTemplate a,b,c,d,e,f;
    func_0203F8F4(79);func_02045088(79);
    cfg=d_021B8280;func_0203FC28(&cfg);
    a=d_021B82F0;func_0203FCA0(2,&a,0);func_020414EC(2);
    b=d_021B8330;func_0203FCA0(3,&b,0);func_020414EC(3);
    c=d_021B8290;func_0203FCA0(4,&c,0);func_020414EC(4);
    d=d_021B82B0;func_0203FCA0(6,&d,0);func_020414EC(6);
    e=d_021B82D0;func_0203FCA0(5,&e,0);func_020414EC(5);
    f=d_021B8310;func_0203FCA0(7,&f,0);func_020414EC(7);
    func_02040588(2,1);func_02040588(3,1);func_02040588(4,1);
    func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040B94(2,32,0,79);func_02040B94(4,32,0,79);
    func_02040B94(5,32,0,79);func_02040B94(2,32,0,79);func_02040B94(4,32,0,79);
    *(u16 *)0x04000050=0;*(u16 *)0x04001050=0;
}

/*
 * volatile: 021B66A8 reads and 021B66AE writes hardware halfword.
 */
void func_021B6678(void)
{
    func_02043598(29, 0);
    func_020403F4(5);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    *(volatile unsigned short *)0x04000304 |= 0x8000;
    func_0203F9B4();
}


void func_021B66BC(u8 *p, u8 *q)
{
    u32 v = 1 << 0xb;
    void *t;

    func_02049658(q, 1, 3, 0, 0, 0, 0x4f);
    func_020498F4(q, 4, 3, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 0, 0, 0, 0x4f);
    func_02049658(q, 1, 7, 0, 0, 0, 0x4f);
    func_020498F4(q, 2, 7, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 4, 0, 0, 0x4f);
    t = func_02049EF4(q, 3, 0, (void **)(p + 0x1c4), 0x4f);
    ((struct Obj00180 *)p)->f1C0 = t;
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4f);
    func_0201F5BC(4, 1, 0xd, 0, 0x4f);
}


int func_021B6794(int *p)
{
    return func_020307B0((void *)(((struct Obj24150 *)p)->f1C0));
}

void func_021B67A4(u8 *p)
{
    u32 i;
    u32 h;
    for (i=0;i<16;i++) {
        *(u32 *)(p+i*4+4)=func_020450F0((u8)d_021B8420[i].a,(u8)d_021B8420[i].b,(u8)d_021B8420[i].c,(u8)d_021B8420[i].d,d_021B8420[i].e,d_021B8420[i].f,(int)1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p+i*4+4))),0);
    }
    h=((struct Obj00180 *)p)->f28;
    func_020456F8((struct Descriptor *)h);
    func_02041B6C(func_02045730((struct Descriptor *)h));
    ((struct Obj00180 *)p)->f21C=func_02028590(15,1,1,79);
}

/*
 * extent: 2 zero alignment bytes at 0x021B684E follow the 38-byte function; no follower.
 */
void func_021B6828(char *p) { u32 i; func_02028604(((struct Obj24151 *)p)->f21C); for(i=0;i<16;i++) func_020452E8(*(void **)((u32)p+i*4+4)); func_020450C8(); }

void func_021B6850(char *p) { ((struct Obj04557 *)p)->f44=func_02045B38(0,2,204,79); ((struct Obj04557 *)p)->f48=func_0201EC64(79); ((struct Obj04557 *)p)->f4C=func_020457B0(256,79); ((struct Obj04557 *)p)->f50=func_02045EC0(((struct Obj04557 *)p)->f44,25); ((struct Obj04557 *)p)->f54=func_02045EC0(((struct Obj04557 *)p)->f44,31); }

void func_021B688C(char *p) { func_02045C04(((struct Obj06565 *)p)->f44); func_0201ED04(((struct Obj06565 *)p)->f48); func_02045808(((struct Obj06565 *)p)->f4C); func_02045808(((struct Obj06565 *)p)->f50); func_02045808(((struct Obj06565 *)p)->f54); }


int func_021B68B0(int *p)
{
    if (func_020221A4() == 1)
        return ((struct Obj24152 *)p)->f1B0;
    return 0;
}

int func_021B68C8(char *p)
{
    u32 v;
    ((struct Obj00362 *)p)->f1CC=func_020260E0(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    v=func_02025DE8(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    switch(v) {
    case 0:case 1:case 2:case 3:
        if(func_02035C60()==0) {
            if(((struct Obj24153 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8) {
                func_020061E4(0x54c);
                return func_021B817C(p);
            }
        } else {
            if(((struct Obj24154 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8)
                func_020061E4(0x54c);
        }
        break;
    case 4:case 5:break;
    case 6:case 8:
        func_020061E4(0x54c);
        if(func_021B7F50(p)) return func_021B80EC(p,14);
        else return func_021B80A4(p,14);
    case -2:
        func_020061E4(0x54c);
        func_021B7EB0(p,0);
        return func_021B80A4(p,14);
    case 7:
        if(func_021B7F50(p)) {
            func_020061E4(0x54c);
            return func_021B80C4((u8 *)p,15);
        }
        break;
    case -8:
        if(((struct Obj24155 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16!=0) {
            func_020061E4(0x54c);
            --((struct Obj24156 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16;
            func_021B71C4(p,func_021B7438((char **)p));
            func_021B70D8(p);
            func_021B7F64(p);
            func_021B7FD0((u8 *)p,-1);
        }
        break;
    case -4:case -3:case -1:break;
    }
    return 1;
}


int func_021B69F8(char *p)
{
    u32 r = func_0201CE30(*(void **)(p + 0x6c));
    func_020286C4(*(void **)(p + 0x21c), *(void **)(p + 0x6c), *(void **)(p + 0x20));
    if (r == 0) {
        if (func_0203630C() & 1)
            func_0201CE5C(*(void **)(p + 0x6c), 0);
    } else if (r == 2) {
        func_0201CE48(*(void **)(p + 0x6c));
        return *(int *)(p + 0x1b0);
    } else if (r == 1) {
        if ((func_020362DC() & 3) || func_02035C60()) {
            func_0201CE38(*(void **)(p + 0x6c));
            func_020061E4(0x547);
        }
    }
    return 2;
}

int func_021B6A64(u8 *p)
{
    Descriptor x;
    x.heap = 79;
    x.count = 2;
    x.items = p + 0x1fc;
    x.zero = 0;
    x.a = 21;
    x.b = 8;
    x.c = 10;
    x.d = 3;
    ((struct Obj14313 *)p)->f1E0 = (unsigned int)func_02027778((struct TaskMenuTmpl *)(&x), (void *)(((struct Obj14313 *)p)->f1DC));
    func_021B81B0(1);
    return 4;
}

int func_021B6AAC(u8 *p)
{
    int result=4;
    if (func_020279E8((struct TaskMenu *)(((struct Obj08264 *)p)->f1E0))) {
        if (func_02027A04((const u8 *)(((struct Obj08264 *)p)->f1E0)) == 0)
            result=d_021B8228[p[0x1ba]].a(p);
        else
            result=d_021B8228[p[0x1ba]].b(p);
        func_021B81B0(0);
    }
    func_02027974(((struct Obj08264 *)p)->f1E0);
    if (result != 4) func_02027858((struct TaskMenu *)(((struct Obj08264 *)p)->f1E0));
    return result;
}
