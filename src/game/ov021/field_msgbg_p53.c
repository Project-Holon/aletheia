/*
 * file:     field_msgbg_p53.c
 * unit:     yes
 * function: func_021904EC, func_02190538, func_02190550, func_02190590
 * address:  0x021904EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 */
#include "../../matched/include/Obj00126.h"

struct U16Vec;
struct MsgBank;
struct Descriptor;
struct PrintSys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Slot_021904EC {
    u32 *f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot_021904EC;

typedef short          s16;

typedef struct Slot_02190538 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot_02190538;

typedef struct Slot_02190550 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot_02190550;

typedef struct Slot_02190590 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot_02190590;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *a);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
Slot_021904EC *func_021904EC(u32 *p, u32 a, u32 b);
void func_02190538(Slot_02190538 *s);
void func_02190550(Slot_02190550 *s, int x, int y, u32 z);
void func_02190590(Slot_02190590 *s, int x, int y, u32 z);


/*
 * Addresses are Black-image addresses.
 */
Slot_021904EC *func_021904EC(u32 *p, u32 a, u32 b)
{
    Slot_021904EC *e;
    int i;

    i = 0;
    e = (Slot_021904EC *)((u8 *)p + 0x10);
    for (; i < 4; i++, e++) {
        if (e->f0c == 0) {
            e->f00 = p;
            e->f14 = b;
            e->f04 = 1;
            e->f08 = p[2];
            e->f0c = p[3];
            e->f18 = (u32)func_020457B0(0xa0, ((struct Obj00126 *)p)->f0);
            e->f10 = a;
            e->f1c = b;
            e->f20 = 0;
            return e;
        }
    }
    return 0;
}


void func_02190538(Slot_02190538 *s)
{
    s->f08 = 0;
    s->f0c = 0;
    func_02045808((struct U16Vec *)s->f18);
    s->f18 = 0;
    s->f10 = 0;
}


void func_02190550(Slot_02190550 *s, int x, int y, u32 z)
{
    u32 t;

    func_02045CAC((struct MsgBank *)s->f10, z, (void *)s->f18);
    t = s->f0c;
    func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16)x, (s16)y, (void *)s->f18, s->f08);
    s->f20 = 1;
}


void func_02190590(Slot_02190590 *s, int x, int y, u32 z)
{
    u32 t;

    t = s->f0c;
    func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16)x, (s16)y, (void *)z, s->f08);
    s->f20 = 1;
}
