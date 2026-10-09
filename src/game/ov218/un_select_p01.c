/*
 * file:     un_select_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95D0, func_021B9674, func_021B96CC, func_021B9820, func_021B9888, func_021B9890, func_021B9898, func_021B9914, func_021B991C, func_021B9924, func_021B9944, func_021B9964, func_021B9A80, func_021B9AD0, func_021B9AE4, func_021B9B78, func_021B9C00
 * address:  0x021B95A0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9E48 0x021B9E48 thumb ov218
 *   func_021B7A64 0x021B7A64 thumb ov067
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021B9E28 0x021B9E28 thumb ov218
 *   func_021B613C 0x021B613C thumb ov067
 *   func_021BA4B4 0x021BA4B4 thumb ov218
 *   func_021BA2EC 0x021BA2EC thumb ov218
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021BA8F0 0x021BA8F0 thumb ov218
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data a1
 *   func_021B6144 0x021B6144 thumb ov067
 *   func_021BA94C 0x021BA94C thumb ov218
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   func_021B64F8 0x021B64F8 thumb ov067
 *   func_021B6568 0x021B6568 thumb ov067
 *   d_021BAC20 0x021BAC20 data a4
 *   func_021B639C 0x021B639C thumb ov067
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02027778 0x02027778 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02027974 0x02027974 thumb
 *   func_02023F98 0x02023F98 thumb
 *   func_02023EF4 0x02023EF4 thumb
 *   d_021BB088 0x021BB088 data ov218 a4
 *   func_02030734 0x02030734 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_0201D2C8 0x0201D2C8 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj26039.h"
#include "../../matched/include/Obj01983.h"
#include "../../matched/include/Obj10971.h"
#include "../../matched/include/Obj02264.h"
#include "../../matched/include/Obj14771.h"
#include "../../matched/include/Obj02265.h"
#include "../../matched/include/Obj05563.h"

struct Node;
struct TaskMenuState;
struct S020315D4;
struct S;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
struct WordSet;
struct Rec3;
struct Rec;
struct PrintSys;
struct S02031140;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct S S;

typedef struct { u8 *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } A;

typedef struct { u32 words[24]; } Table;

typedef struct R R;

struct Item { void *text; u16 color; u16 padding; u32 value; };

struct TaskMenuTmpl { u32 heapId; u8 count; u8 pad05[3]; const void *unk08; u32 unk0c; u8 pad10[2]; u8 unk12, unk13; };

typedef struct Obj Obj;

extern char *func_021B9E48(void *,char *);
extern int func_021B7A64(struct S *p);
extern void func_0204E720(unsigned int, int, int, int);
extern int func_0204E804(void);
extern void func_02030EAC(struct Node *);
extern void func_021B9E28(char *);
extern void func_021B613C(void *);
extern void func_021BA4B4(char *);
extern void func_021BA2EC(char *);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021BA8F0(char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
extern int func_021B6144(struct S *);
extern void func_021BA94C(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern void func_02082BCC(void *, u32, u32);
extern R *func_021B62E0(A *, int);
extern void func_021B64F8(u8 *, u32);
extern void func_021B6568(unsigned char *p, unsigned int id, int v);
extern void func_021B639C(u8 *);
extern void func_021B63D0(struct S *p);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void func_02045808(struct U16Vec *);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *, void *);
extern void func_02027858(struct TaskMenu *);
extern void func_02027974(Obj *);
extern void func_02023F98(u32 mask);
extern int func_02023EF4(int a, int b, int c, int d, int e);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_0201CE48(struct Rec3 *);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *);
extern unsigned int func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D2C8(struct StrObj *s);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *, int, int, int);
extern unsigned int func_0201CE30(void *);
extern void func_0201CE38(void *);
extern void func_0201CE5C(struct Rec *, int);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(unsigned int);
int func_021B95A0(void *owner,int *state,char *input,u8 *p);
int func_021B95D0(struct S020315D4 *ctx, int *state, void *unused, char *p);
int func_021B9674(void *ctx, int *state, void *unused, char *p);
void func_021B96CC(u8 *p, u16 heap);
R *func_021B9820(int heap, int id);
void func_021B9888(u8 *p);
void func_021B9890(S *p);
struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap);
void func_021B9914(struct TaskMenu *p);
void func_021B991C(Obj *p);
int func_021B9924(void);
void func_021B9944(void);
void *func_021B9964(u16 heap);
void func_021B9A80(char *p);
void func_021B9AD0(char *p);
void func_021B9AE4(u8 *p, u8 *a, void *b, unsigned long long cd);
void func_021B9B78(char *p, u32 id);
int func_021B9C00(char *p);
extern char ov067_id[];
extern const Table d_021BAC20;
extern char d_021BB088[];




int func_021B95A0(void *owner,int *state,char *input,u8 *p)
{
    switch(*state){
    case 0:func_021B9E48(owner,input);++*state;break;
    case 1:if(func_021B7A64(*(S * *)&((struct Obj26039 *)p)->f2C)==0)return 1;break;
    }
    return 0;
}




int func_021B95D0(struct S020315D4 *ctx, int *state, void *unused, char *p)
{
    switch (*state) {
    case 0:
        func_0204E720(3, 0, 16, 1);
        ++*state;
        break;
    case 1:
        if (func_0204E804() != 1)
            ++*state;
        break;
    case 2: {
        u16 heap;
        func_02030EAC(*(struct Node * *)&((struct Obj01983 *)p)->f23C);
        *(volatile u16 *)0x04000050 = 0;
        *(volatile u16 *)0x04001050 = 0;
        func_021B9E28(p);
        func_021B613C(((struct Obj01983 *)p)->f24);
        func_021B9A80(*(char * *)&((struct Obj01983 *)p)->f28);
        func_021BA4B4(p);
        func_021BA2EC(p);
        func_02027FD8(*(struct TaskMenuState * *)&((struct Obj01983 *)p)->f18);
        func_021B9888(((struct Obj01983 *)p)->f8);
        func_021BA8F0(*(char * *)&((struct Obj01983 *)p)->f4);
        heap = ((struct Obj01983 *)p)->f0;
        func_020315D4(ctx);
        func_020306F0(heap);
        func_02034A5C((int)ov067_id);
        return 1;
    }
    }
    return 0;
}




int func_021B9674(void *ctx, int *state, void *unused, char *p)
{
    int result = 0;
    switch (*state) {
    case 0:
        func_0204E720(3, 16, 0, 1);
        ++*state;
        break;
    case 1:
        if (func_0204E804() == 0)
            ++*state;
        break;
    case 2:
        if (func_021B6144(*(struct S * *)&((struct Obj10971 *)p)->f24) != 0)
            result = 1;
        break;
    }
    func_021B9AD0(*(char * *)&((struct Obj10971 *)p)->f28);
    func_021BA94C(*(char * *)&((struct Obj10971 *)p)->f4);
    return result != 0;
}




void func_021B96CC(u8 *p, u16 heap)
{
    void *h;
    void *w2;
    void *w1;
    u8 *o2;
    u8 *o1;
    int a;
    int i;
    h = func_020490F4(0xc1, heap);
    func_02049B68(h, 1, 0, 0, 0xe0, heap);
    func_02049B68(h, 1, 4, 0, 0xe0, heap);
    func_02049658(h, 0xc, 4, 0, 0x200, 0, heap);
    func_020498F4(h, 6, 7, 0, 0, 0, heap);
    func_020498F4(h, 0xd, 4, 0, 0, 0, heap);
    w1 = func_02049DF4(h, 0, 0, (u32)((void **)&o1), heap);
    func_020498F4(h, 5, 3, 0, 0, 0, heap);
    w2 = func_02049DF4(h, 0, 0, (u32)((void **)&o2), heap);
    func_02049658(h, 2, 2, 0, 0, 0, heap);
    func_02049658(h, 2, 6, 0, 0, 0, heap);
    for (i = 0; i < 0x82; i++) {
        u8 *buf;
        a = 0x81 - i;
        buf = (i < 0x32) ? *(u8 **)(o1 + 0x14) : *(u8 **)(o2 + 0x14);
        if (*(u32 *)(p + 0x34 + i * 4) == 0) {
            u32 col = (u8)((u8)((3 - a % 4) * 2) * 4);
            u32 off = col + (((u8)(a / 4) << 5) + 0x20);
            buf[off] = 0xff;
            buf[off + 1] = 0xff;
            buf[off + 2] = 0xff;
            buf[off + 3] = 0xff;
            buf[off + 4] = 0xff;
            buf[off + 5] = 0xff;
            buf[off + 6] = 0xff;
            buf[off + 7] = 0xff;
        }
    }
    func_02040B1C(7, *(void **)(o1 + 0x14), *(u32 *)(o1 + 0x10), 0);
    func_020307B0(w1);
    func_02040B1C(3, *(void **)(o2 + 0x14), *(u32 *)(o2 + 0x10), 0);
    func_020307B0(w2);
    func_02049238(h);
}




R *func_021B9820(int heap, int id)
{
    Table table = d_021BAC20;
    A config;
    R *p;
    func_02082BCC(&config, 0, sizeof(config));
    config.f0 = (u8 *)&table;
    config.f4 = 3;
    config.f8 = heap;
    config.fC = 1;
    config.f10 = 13;
    config.f14 = 0;
    config.f18 = 0;
    p = func_021B62E0(&config, id);
    func_021B64F8((u8 *)p, 1);
    func_021B6568((unsigned char *)p, 4, 0);
    func_021B6568((unsigned char *)p, 5, 0);
    return p;
}




void func_021B9888(u8 *p)
{
    func_021B639C(p);
}




void func_021B9890(S *p)
{
    func_021B63D0(p);
}




struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap)
{
    struct TaskMenuTmpl config;
    struct Item items[2];
    struct TaskMenu *menu;
    u32 i;
    for (i = 0; i < 2; i++) {
        items[i].text = func_02045EC0(bank, i + 235);
        items[i].color = 0x39e3;
        items[i].value = 0;
    }
    config.heapId = heap;
    config.count = 2;
    config.unk08 = items;
    config.unk0c = 1;
    config.pad10[0] = 32;
    config.pad10[1] = 18;
    config.unk12 = 13;
    config.unk13 = 3;
    menu = func_02027778(&config, arg);
    for (i = 0; i < 2; i++)
        func_02045808((struct U16Vec *)items[i].text);
    return menu;
}




void func_021B9914(struct TaskMenu *p)
{
    func_02027858(p);
}




void func_021B991C(Obj *p)
{
    func_02027974(p);
}





/*
 * Initialises one record: enable flag 1 through 0x02023F98, then issue the
 * five-argument setup 0x02023EF4(8, -8, 0, 0x3c, 1) and return its result.
 * Blocker target of func_021BA0B0.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9924(void)
{
    func_02023F98(1);
    return func_02023EF4(8, -8, 0, 0x3c, 1);
}



void func_021B9944(void)
{
    func_02023F98(1);
    func_02023EF4((int)((void *)8), 0, -8, 60, 1);
}



void *func_021B9964(u16 heap)
{
    char *p;
    void *window;
    p=func_02030734(heap,0x234,1,d_021BB088,0x3cc);
    *(u16 *)p=heap;
    func_02049B40(23,5,0,0x1c0,32,heap);
    func_0201F5BC(0,1,15,0,heap);
    *(void **)(p+0x14)=func_0201EC64(heap);
    *(void **)(p+8)=func_02045B38(0,2,229,heap);
    *(void **)(p+0x10)=(void *)func_0201C440((void *)heap);
    *(void **)(p+0xc)=func_0201D7EC(23,0,0,0,heap);
    *(void **)(p+0x18)=func_020457B0(1600,heap);
    *(void **)(p+0x1c)=func_020457B0(1600,heap);
    *(void **)(p+4)=func_0203101C(heap,heap,1,0);
    *(void **)(p+0x24)=(void *)func_020450F0(0,1,19,30,4,14,1);
    window=*(void **)(p+0x28)=(void *)func_020450F0(4,1,1,30,2,6,1);
    func_02043B5C(func_02045770(window),15);
    func_0201DD78(1,2,15);
    func_02045CAC(*(void **)(p+8),233,*(void **)(p+0x18));
    func_0201C7A4(func_02045770(window),4,0,*(void **)(p+0x18),*(void **)(p+0xc));
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    return p;
}


void func_021B9A80(char *p)
{
    if (*(struct Rec3 * *)&((struct Obj02264 *)p)->f20 != 0) {
        func_0201CE48(*(struct Rec3 * *)&((struct Obj02264 *)p)->f20);
        *(struct Rec3 * *)&((struct Obj02264 *)p)->f20 = 0;
    }
    func_020452E8(*(struct Descriptor * *)&((struct Obj02264 *)p)->f28);
    func_020452E8(*(struct Descriptor * *)&((struct Obj02264 *)p)->f24);
    func_02045808(*(struct U16Vec * *)&((struct Obj02264 *)p)->f18);
    func_02045808(*(struct U16Vec * *)&((struct Obj02264 *)p)->f1C);
    func_02045C04(*(struct Rec * *)&((struct Obj02264 *)p)->f8);
    func_0201C4C0(*(struct PrintSys * *)&((struct Obj02264 *)p)->f10);
    func_0201D83C(((struct Obj02264 *)p)->fC);
    func_02031140(*(struct S02031140 * *)&((struct Obj02264 *)p)->f4);
    func_0201ED04(*(struct WordSet * *)&((struct Obj02264 *)p)->f14);
    func_020307B0(p);
}



void func_021B9AD0(char *p)
{
    func_0201C4E4((struct PrintSys *)(((struct Obj14771 *)p)->f10));
    func_020310C4((struct Tcbl *)(((struct Obj14771 *)p)->f4));
}


void func_021B9AE4(u8 *p, u8 *a, void *b, unsigned long long cd)
{
    u32 c = (u32)cd; u32 d = (u32)(cd >> 32);
    u32 r = 12;
    u32 t = 0x83 - d;
    func_02045CAC(*(void **)(p + 8), (t == 2) ? 0xF0 : 0xED, *(void **)(p + 0x18));
    func_0201EFA4(*(void **)(p + 0x14), 2, t, 3, 0, 1);
    func_0201F250(*(void **)(p + 0x14), *(void **)(p + 0x1C), *(void **)(p + 0x18));
    func_021B6AE4(a, b, 0, 12, *(u32 *)(p + 0x1C), c, 0x39E0, 0);
    p += 0x2C;
    if (func_0201D2C8((struct StrObj *)(*(u32 *)(p + d * 4))) > 1) r = 4;
    func_021B6AE4(a, b, 0x1E, r, *(u32 *)(p + d * 4), c, 0x39E0, 0);
}


void func_021B9B78(char *p, u32 id)
{
    int value = func_02012FFC();
    struct Descriptor *obj = *(struct Descriptor * *)&((struct Obj02265 *)p)->f24;
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    func_02045CAC(*(struct MsgBank * *)&((struct Obj02265 *)p)->f8, id, ((struct Obj02265 *)p)->f18);
    func_0201F250(*(struct WordSet * *)&((struct Obj02265 *)p)->f14, ((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->f18);
    ((struct Obj02265 *)p)->f20 = func_0201CCE4((u32)obj, 4, 0, *(u32 *)&((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->fC, value, ((struct Obj02265 *)p)->f4, 65535, ((struct Obj02265 *)p)->f0, 15);
    func_0201F73C(((struct Obj02265 *)p)->f24, 2, 1, 15);
    func_02045334(obj);
    func_02045374((struct Cfg *)obj);
    func_02041B6C(func_02045730(obj));
}


int func_021B9C00(char *p)
{
    if (((struct Obj05563 *)p)->f20 != 0) {
        switch (func_0201CE30(((struct Obj05563 *)p)->f20)) {
        case 2:
            func_0201CE48(*(struct Rec3 * *)&((struct Obj05563 *)p)->f20);
            ((struct Obj05563 *)p)->f20 = 0;
            return 1;
        case 1:
            if (func_020362DC() == 1 || func_020362DC() == 2 || func_02035C60() != 0) {
                func_0201CE38(((struct Obj05563 *)p)->f20);
                func_020061E4(1356);
            }
            break;
        case 0:
            if (((unsigned int)func_0203630C() & 3) != 0 || func_02035C38() != 0)
                func_0201CE5C(*(struct Rec * *)&((struct Obj05563 *)p)->f20, 0);
            break;
        }
        return 0;
    }
    return 0;
}
