/*
 * file:     btl_rec_p15.c
 * unit:     yes
 * function: func_021EF6F0, func_021EF71C, func_021EF7AC, func_021EF83C, func_021EF874, func_021EF884
 * address:  0x021EF6F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data   a4
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021EF988  0x021EF988  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 *   func_021EF9A8  0x021EF9A8  thumb  ov093
 */
#include "../../matched/include/G_Countdown.h"

struct MsgBank;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 pad[10];
    u32 f54;
    u16 f58;
    u16 f5a;
} D_021EF6F0;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D_021EF71C;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D_021EF7AC;

typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

extern void func_021EEFE0(void *s, const u32 *values, void *w);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern Slot func_021E8918(void);
extern int func_021EF988(void *mem, int a);
extern u8 func_021EF9A8(u32 *p);
void func_021EF6F0(u32 a, u32 b, u32 c);
void func_021EF71C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_021EF83C(S *a, u32 i);
int func_021EF874(int a);
int func_021EF884(void);
extern D_021EF6F0 d_021F6398;
extern struct Countdown d_021F63F4;


/*
 * Unlabelled leaf, callee of the tail stub 0x021EF6E8 that func_021EA55C calls.
 * Twin of func_021EF6B0 without the +0x5a flag stores, using the +0x28 slot.
 */
void func_021EF6F0(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.f28, b, (void *)d_021F6398.fc);
    func_021EEFE0((void *)d_021F6398.fc, (const u32 *)c, (void *)d_021F6398.f8);
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}


void func_021EF71C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_02045CAC((struct MsgBank *)d_021F6398.f1c, 0x10, (void *)d_021F6398.fc);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 0, b, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 1, c, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 2, d, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 3, e, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 4, f, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 5, g, 2, 0, 1);
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}


void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_02045CAC((struct MsgBank *)d_021F6398.f1c, 0x11, (void *)d_021F6398.fc);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 0, b, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 1, c, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 2, d, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 3, e, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 4, f, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f8, 5, g, 3, 0, 1);
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}


void func_021EF83C(S *a, u32 i)
{
    u32 j;

    a->t[i] = 0;
    a->c[i] = func_021E8918();
    a->z48[i] = 0;
    a->z128[i] = 0;
    a->used[i] = 0;
    for (j = 0; j < 6; j++)
        a->w[i][j] = 0x1f;
}


int func_021EF874(int a)
{
    return func_021EF988(&(*(char *)&d_021F63F4), a);
}


int func_021EF884(void)
{
    return func_021EF9A8((u32 *)(&(*(char *)&d_021F63F4)));
}
