/*
 * file:     un_select_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95D0, func_021B9674, func_021B96CC, func_021B9820, func_021B9888, func_021B9890, func_021B9898, func_021B9914
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
 *   func_021B9A80 0x021B9A80 thumb ov218
 *   func_021BA4B4 0x021BA4B4 thumb ov218
 *   func_021BA2EC 0x021BA2EC thumb ov218
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021BA8F0 0x021BA8F0 thumb ov218
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data a1
 *   func_021B6144 0x021B6144 thumb ov067
 *   func_021B9AD0 0x021B9AD0 thumb ov218
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
 */
#include "../../matched/include/Obj26039.h"
#include "../../matched/include/Obj01983.h"
#include "../../matched/include/Obj10971.h"

struct Node;
struct TaskMenuState;
struct S020315D4;
struct S;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
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

extern char *func_021B9E48(void *,char *);
extern int func_021B7A64(struct S *p);
extern void func_0204E720(unsigned int, int, int, int);
extern int func_0204E804(void);
extern void func_02030EAC(struct Node *);
extern void func_021B9E28(char *);
extern void func_021B613C(void *);
extern void func_021B9A80(char *);
extern void func_021BA4B4(char *);
extern void func_021BA2EC(char *);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021BA8F0(char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
extern int func_021B6144(struct S *);
extern void func_021B9AD0(char *);
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
int func_021B95A0(void *owner,int *state,char *input,u8 *p);
int func_021B95D0(struct S020315D4 *ctx, int *state, void *unused, char *p);
int func_021B9674(void *ctx, int *state, void *unused, char *p);
void func_021B96CC(u8 *p, u16 heap);
R *func_021B9820(int heap, int id);
void func_021B9888(u8 *p);
void func_021B9890(S *p);
struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap);
void func_021B9914(struct TaskMenu *p);
extern char ov067_id[];
extern const Table d_021BAC20;

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
