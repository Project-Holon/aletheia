/*
 * file:     event_field_proclink_p09.c
 * unit:     yes
 * function: func_0215F920, func_0215F948, func_0215F9C4, func_0215F9DC, func_0215F9EC, func_0215FA00, func_0215FA1C, func_0215FA34
 * address:  0x0215F920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_020111E8  0x020111E8  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C3B8  0x0200C3B8  thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02183B6C 0x02183B6C thumb ov020
 *   OS_SleepThread     0x02034ac4  arm
 *   DSP_SyncPipe       0x0218571c  thumb
 *   DSPiBlockingQueue  0x00000014  data
 *   abs_id_14      0x00000014  data
 *   sub_02034AC4   0x02034AC4  arm
 */
#include "../../matched/include/Obj05853.h"
#include "../../matched/include/Obj17707.h"

struct Big;
struct Sub02008700Obj;
struct DSPPipe;
struct _OSThreadQueue;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x34];
    u32 step;           /* 0x34 */
    u32 seq[1];         /* 0x38 */
} Work;

typedef signed int     s32;

extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern u32 func_020111E8(void);
extern void *func_02012F08(int *p);
extern int func_0200C3B8();
extern int func_02034AC4(s32 handle);
extern void func_02183B6C(int a, int *p);
void OS_SleepThread(struct _OSThreadQueue *queue);
void DSP_SyncPipe(struct DSPPipe *pipe);
extern int sub_02034AC4(int id);
int func_0215F920(int a0);
void func_0215F948(u8 *p);
int func_0215F9C4(void);
void func_0215F9DC(Work *w, u32 *i);
int func_0215F9EC(int a0);
void func_0215FA00(void *p, void *q);
void func_0215FA34(void);
extern unsigned char ov020_id[];
extern struct _OSThreadQueue DSPiBlockingQueue;
extern unsigned char abs_id_14[];


/*
 * blocked:  listing 40 compiled 38
 */
int func_0215F920(int a0)
{
    int t4;
    void *big;
    struct Sub02008700Obj *obj;

t4 = a0 + 0;
a0 = ((struct Obj05853 *)t4)->f8;
    if (a0 != 1) goto loc_0215F92E;
loc_0215F92A:
a0 = 1;
    goto loc_0215F930;
loc_0215F92E:
a0 = 0;
loc_0215F930:
((struct Obj05853 *)t4)->f28 = a0;
a0 = ((struct Obj05853 *)t4)->f4;
    big = func_02012EBC((struct Big *)a0);
loc_0215F938:
    obj = func_0200873C(big);
loc_0215F93C:
    a0 = func_020083E4((short unsigned int *)obj);
loc_0215F940:
((struct Obj05853 *)t4)->f2C = a0;
((struct Obj05853 *)t4)->f30 = a0;
    return a0;}


/*
 * Addresses are Black-image addresses.
 */
void func_0215F948(u8 *p)
{
    u32 *t = (u32 *)p;
    if (t[2] == 0 || t[2] != 1) {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 3;
        t[0x44 / 4] = 4;
        t[0x48 / 4] = 7;
        t[0x4c / 4] = 8;
        t[0x50 / 4] = 12;
        t[0x54 / 4] = 9;
        t[0x58 / 4] = 12;
        t[0x5c / 4] = 10;
        t[0x60 / 4] = 11;
        t[0x64 / 4] = 12;
        t[0x68 / 4] = 13;
        t[0x6c / 4] = 14;
    } else {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 1;
        t[0x44 / 4] = 3;
        t[0x48 / 4] = 4;
        t[0x4c / 4] = 5;
        t[0x50 / 4] = 6;
        t[0x54 / 4] = 10;
        t[0x58 / 4] = 11;
        t[0x5c / 4] = 7;
        t[0x60 / 4] = 8;
        t[0x64 / 4] = 13;
        t[0x68 / 4] = 14;
    }
    t[0x34 / 4] = t[0x38 / 4];
}


int func_0215F9C4(void)
{
    int a0;

    a0 = func_020111E8();
loc_0215F9CA:
    if (a0 == 0x14) goto loc_0215F9D2;
loc_0215F9CE:
    if (a0 == 0x15) goto loc_0215F9D6;
loc_0215F9D2:
a0 = 8;
    return a0;
loc_0215F9D6:
a0 = 7;
    return a0;}


/*
 * Advance the step counter and load the next step from the sequence.
 */
void func_0215F9DC(Work *w, u32 *i)
{
    (*i)++;
    w->step = w->seq[*i];
}


int func_0215F9EC(int a0)
{
    int a1;
    void *p;

a0 = ((struct Obj17707 *)a0)->f4;
    p = func_02012F08((int *)a0);
loc_0215F9F4:
a1 = 0x5a;
a1 = a1 << 4;
    a0 = func_0200C3B8(p, a1);
loc_0215F9FC:
    return a0;}

void func_0215FA00(void *p, void *q) { func_02034AC4((u32)ov020_id); func_02183B6C((int)p,q); }


static void DSPi_WaitForPipe(struct DSPPipe *pipe)
{
    OS_SleepThread(&DSPiBlockingQueue);
    DSP_SyncPipe(pipe);
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM sub_02034AC4 with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA44 (same id, into sub_02034A5C).
 */
void func_0215FA34(void)
{
    sub_02034AC4((int)abs_id_14);
}
