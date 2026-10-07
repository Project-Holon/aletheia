/*
 * file:     mystery_util_p10.c
 * unit:     yes
 * function: func_021DAE1C, func_021DAEF0, func_021DAFCC, func_021DB018
 * address:  0x021DAE1C
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
 *   func_021DD980 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_02040618 0x02040618 arm
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_021DB528 0x021DB528 thumb ov121
 *   func_021DB3E8 0x021DB3E8 thumb ov121
 *   func_0200A348 0x0200A348 thumb
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021DA890 0x021DA890 thumb ov121
 *   func_020307B0 0x020307B0 arm
 *   func_021DA898 0x021DA898 thumb ov121
 *   func_021DD240 0x021DD240 thumb ov121
 *   func_021DDF84 0x021DDF84 thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   func_021DE0DC 0x021DE0DC thumb ov121
 *   func_021DCFA4 0x021DCFA4 thumb ov121
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021D9B34 0x021D9B34 thumb ov121
 *   func_021DD9CC 0x021DD9CC thumb ov121
 *   func_021DA8AC 0x021DA8AC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_021D99A4 0x021D99A4 thumb ov121
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_021DCF54 0x021DCF54 thumb ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B604 0x0204B604 arm
 *   func_02040588 0x02040588 arm
 *   data_021DF86E 0x021DF86E data a1
 */
#include "../../matched/include/Obj01058.h"
#include "../../matched/include/Obj01153.h"
#include "../../matched/include/Obj10417.h"
#include "../../matched/include/Obj22899.h"

struct Obj;
struct Actor;
struct Cfg;
typedef unsigned int u32;

typedef struct Obj_021DAE1C { char pad[0xa7c]; char *slots[12]; } Obj_021DAE1C;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct Item { char raw[0xdc]; } Item;

typedef struct Obj_021DAEF0 { char pad[0x28]; Item items[12]; char tail[0xacc-0x28-12*0xdc]; volatile int index; } Obj_021DAEF0;

typedef int s32;

typedef struct { u16 h[4]; } Row;

typedef struct { u8 b[16]; } Tmp;

extern void func_021DD980(char *);
extern void func_021DD1FC(void **);
extern void func_021D9E04(u8 *p);
extern void func_02040618(u32,u32,u32);
extern void func_021DA2A8(u8 *p);
extern void func_021DA280(u8 *p);
extern void func_021DB528(char *,int);
extern void func_021DB3E8(char *);
extern u32 func_0200A348(struct Obj_021DAE1C *);
extern void func_021DBEE4(u32 p);
extern void func_020414EC(u32);
extern void func_02041B6C(u32);
extern void func_021DA890(void *);
extern u32 func_020307B0(void *p);
extern void func_021DA898(char *);
extern int func_021DD240(void **p);
extern void func_021DDF84(char *);
extern int func_021DBF04(int *p);
extern void func_021DE0AC(u8 *p, u32 b);
extern void func_021DE0DC(char *p);
extern void func_021DCFA4(u8 *p, int b, int c, u16 d);
extern int func_021DA2C8(u8 *p);
extern int func_021D9B34(u8 *p);
extern void func_021DD9CC(char *p);
extern int func_021DA8AC(u32 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern unsigned int func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_020409B4(u32);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02045374(struct Cfg *cfg);
extern void *func_021D99A4(u32, u32, u16, u16, u8, u8, u8, u32, u16);
extern s32 func_0204AC18(void *, u32, u32, u32, u16, u16, u16);
extern s32 func_0204AF28(void *, u32, u32, u32);
extern s32 func_0204A6C8(void *, u32, u32, u32, u16);
extern void func_021DCF54(char *, void *, int, int, u8, u16);
extern void func_02082BCC(void *, int, int);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021DAE1C(Obj_021DAE1C *obj);
void func_021DAEF0(Obj_021DAEF0 *obj);
void func_021DAFCC(char *p);
int func_021DB008(char *p);
void func_021DB018(u8 *p, u16 heap);
extern const Row data_021DF86E[];

/*
 * lever: The slot array at +0xa7c is the same layout as func_021DBC08;
 * its member access keeps the offset loaded before the loop index.
 */
void func_021DAE1C(Obj_021DAE1C *obj)
{
    char *p=(char *)obj;
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            func_021DD980(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    func_021DD1FC(*(void ** *)&((struct Obj01058 *)p)->fAB0);
    if(((struct Obj01058 *)p)->fABC) {
        func_021D9E04(((struct Obj01058 *)p)->fABC);
        ((struct Obj01058 *)p)->fABC=0;
    }
    func_02040618(3,0,0);
    func_02040618(2,0,0);
    func_021DA2A8(((struct Obj01058 *)p)->fAB8);
    func_021DA280(((struct Obj01058 *)p)->fAB8);
    func_021DB528(p,1);
    func_021DB528(p,0);
    func_021DB3E8(p);
    for(j=0;j<func_0200A348(((struct Obj01058 *)p)->fC);j++)
        func_021DBEE4((u32)(p+0x28+j*0xdc));
    func_020414EC(4);
    func_020414EC(6);
    func_02041B6C(4);
    func_02041B6C(6);
    func_021DA890(((struct Obj01058 *)p)->fAC4);
    func_020307B0(p);
}

void func_021DAEF0(Obj_021DAEF0 *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    func_021DA898(*(char * *)&((struct Obj01153 *)p)->fAC4);
    func_021DD240(((struct Obj01153 *)p)->fAB0);
    if(((struct Obj01153 *)p)->fA78) {
        flag=0;
        if(*(char * *)&((struct Obj01153 *)p)->fAAC) {
            func_021DDF84(*(char * *)&((struct Obj01153 *)p)->fAAC);
            *(char * *)&((struct Obj01153 *)p)->fAAC=0;
        }
        if(obj->index<4 && func_021DBF04((int *)(&obj->items[obj->index+((struct Obj01153 *)p)->fAC8*4]))) {
            flag=1;
            func_021DE0AC(*(void **)(p+0xa7c+(((struct Obj01153 *)p)->fACC+((struct Obj01153 *)p)->fAC8*4)*4),1);
        }
        if(flag==0) func_021DE0DC(((struct Obj01153 *)p)->fAB0);
        ((struct Obj01153 *)p)->fA78=0;
    }
    old=((struct Obj01153 *)p)->fBAC;
    angle=old+0x400;
    if(angle>=0x10000)
        ((struct Obj01153 *)p)->fBAC=old-0xfc00;
    else
        ((struct Obj01153 *)p)->fBAC=angle;
    func_021DCFA4((u8 *)(p+0xbae),14,0,((struct Obj01153 *)p)->fBAC);
    func_021DCFA4((u8 *)(p+0xc0e),14,2,((struct Obj01153 *)p)->fBAC);
}

static inline void update(void *p)
{
    if(p) func_021DD9CC(p);
}

/*
 * extent: unit includes tail-call follower func_021DB008 (function-start seed).
 */
void func_021DAFCC(char *p)
{
    int i;
    func_021DA2C8(((struct Obj10417 *)p)->fAB8);
    if(((struct Obj10417 *)p)->fAB4) func_021D9B34(((struct Obj10417 *)p)->fAB4);
    for(i=0;i<12;i++) {
        void *q=*(void **)(p+i*4+0xa7c);
        if(q) update(q);
    }
}

int func_021DB008(char *p)
{
    return func_021DA8AC(((struct Obj22899 *)p)->fAC4);
}

#pragma opt_dead_assignments off

/*
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns sub_0204968C); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * note (2026-10-05, lane P10): full body written; size is exact (976 bytes), 110 bytes differ.
 *   Fixed: heap is u16 with the matched u16 callee prototypes (no lsls/lsrs pairs); 0xAB4, 0xBA8
 *   and 320 held as int locals (off, off2, w) so the pool words and derived offsets matched.
 *   Residue 1: colour swap. Original has the early zero (and loop counter i) in r6 and arc in r4;
 *   the build has them swapped (j then takes r6 vs r4 the same way). Tried, no change: i,j and arc
 *   declaration order, separate arc names, loop-scoped i and j, named zero z (propagated),
 *   j = 0 at the top (worse). Pragmas opt_lifetimes/propagation/common_subs/dead_assignments/
 *   scheduling/peephole off: no help.
 *   Residue 2: the original uses movs for zero arguments in r0-r3 between 0xCC and 0x140 (before
 *   the first loop); the build copies the zero register there.
 *   Residue 3: in loop 2 the original forms add r0,sp,#0x44 once before the j test; the build
 *   adds it in each arm. A ternary for the x store and a real Tmp struct were worse.
 * note (2026-10-05, lane P10b): 110 -> 85 bytes, size exact (976). Fixed: loop 2 now writes
 *   the t stores in each if/else arm (x, y=0x10 and z=9 in both arms), so the &t add is hoisted
 *   above the j test and the tail shape matches (residue 3 closed, 110 -> 94). The locals off, off2
 *   and w were stand-ins (literals give identical bytes) and are gone. opt_dead_assignments off
 *   fixes the r0/r1 table-base colours in the i < 4 arm (94 -> 85).
 *   Left: the colour swap. Original W1 = early zero and loop-1 counter i in r6, arcs r4, W2 = copy
 *   of it (`adds r4,r6,#0` before loop 1) = zero args after the loop and loop-2 counter j in r4.
 *   Build: W1 r4, arcs and W2 r6. Likely W1 is coloured before W2 because W1 has about ten extra
 *   uses: between 0xCC and 0x140 the build copies zeros off W1 (adds rN,r4,#0) where the original
 *   has movs. Tried (no help): i=0 at the top of the function (hoists the movs above the first
 *   call, +12 B), `i = 0; j = i;` before loop 1 with empty for inits (+12 B, worse regs), pointer
 *   local for &t in loop 2 (hoisted to r7, worse), j/i and arc declaration order again with the
 *   new loop 2, pragmas opt_lifetimes, opt_propagation, scheduling, peephole (no change),
 *   opt_common_subs (much worse), lifetimes+dead_assignments (85, same), propagation+dead (worse).
 *   Parked per the human-written rule: not tried, a human-spelled zero local reused as the
 *   stack zero arguments (i passed as args 5 and 6) could explain r6 holding a live variable.
 * note (2026-10-05, lane P10c): still 85 B, no change kept. The pragma opt_dead_assignments off
 *   lines are present (the 85 B state). Callee prototypes already match the matched callers (u32
 *   args, u16 heap), so no argument type differs between the stack zeros and the register zeros.
 *   Facts: mine already uses movs for register zeros before +0xB0 and copies only from the last
 *   02049658/020498F4 pair on (+0xB0, +0xD0, +0xF6..+0x134); the original uses movs everywhere in
 *   W1's range, and the copy count raises W1's use count, which colours W1 before the arcs.
 *   Loop 2 original: k is a separate fresh `movs r7,#0`, j is r4.
 *   Tried (each one compile): (1) coordinator lead: i = 0 before the first call, i passed only as
 *   the two stack zero args of 02049658/020498F4, literal 0 for r1-r3 (87 B; the compiler folds
 *   i to 0 so register zeros still copy); (2) i = 0 early with `for (; i < 8; i++)` as in the
 *   matched twin ov099 021BE040 (87 B); (3) static inline helper pair(arc, x, y, heap) for the
 *   three 02049658/020498F4 pairs (85 B, +0xB0 now movs, others unchanged); (4) late zeros
 *   (02049B68 r2, 02040C14 r1/r3, 0201F5BC r0/r3, 0204ACEC r2) spelled 0u (85 B, no change);
 *   (5) first 23 lines of calls inside a static inline setup1(heap) helper (85 B); (6) helper
 *   variant with opt_propagation off (901 B) and opt_lifetimes off (85 B). Idea not done: a
 *   source where W1 is not provably 0 after the first loop-free section.
 */
void func_021DB018(u8 *p, u16 heap)
{
    Tmp t;
    void *arc;
    int i, j;
    u32 k;
    arc = func_020490F4(34, heap);
    func_02049B68(arc, 1, 0, 0, 320, heap);
    func_02049658(arc, 10, 3, 0, 0, 0, heap);
    func_020498F4(arc, 17, 3, 0, 0, 0, heap);
    func_02049658(arc, 10, 1, 0, 0, 0, heap);
    func_020498F4(arc, 19, 1, 0, 0, 0, heap);
    func_020409B4(3);
    func_02049B68(arc, 1, 4, 0, 320, heap);
    func_02049658(arc, 10, 7, 0, 0, 0, heap);
    func_020498F4(arc, 18, 7, 0, 0, 0, heap);
    func_02049238(arc);
    arc = func_020490F4(23, heap);
    func_02049B68(arc, 5, 0, 480, 32, heap);
    func_02049B68(arc, 5, 4, 480, 32, heap);
    func_02049238(arc);
    func_02040C14(1, 0, 1, 0);
    func_02040C14(2, 0, 1, 0);
    func_0201F5BC(0, 1, 13, 0, heap);
    arc = func_020490F4(7, heap);
    *(int *)(p + 0xBA8) = func_0204ACEC(arc, func_0201BC3C(), 0, 384, heap);
    func_02049238(arc);
    for (i = 0; i < 8; i++) {
        if (i >= 4) {
            *(u16 *)(t.b + 8) = data_021DF86E[i - 4].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i - 4].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i - 4].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i - 4].h[3];
            t.b[8] += 0x20;
            t.b[10] += 0x20;
        } else {
            *(u16 *)(t.b + 8) = data_021DF86E[i].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i].h[3];
        }
        *(u32 *)(p + i * 4 + 0xBA8 - 0xA0) = func_020450F0(2, t.b[10], t.b[11], 10, 2, 15, 0);
        func_02045374(*(void **)(p + i * 4 + 0xBA8 - 0xA0));
        func_020409B4(2);
    }
    *(void **)(p + 0xAB4) = func_021D99A4(0, 1, 13, 22, 6, 2, 3, *(u32 *)(p + 0x14), heap);
    arc = func_020490F4(34, heap);
    *(s32 *)(p + 0xAB4 + 0x50) = func_0204AC18(arc, 0, 0, 0, 0, 6, heap);
    *(s32 *)(p + 0xAB4 + 0x4C) = func_0204AF28(arc, 32, 35, heap);
    *(s32 *)(p + 0xAB4 + 0x48) = func_0204A6C8(arc, 9, 0, 0, heap);
    func_021DCF54((char *)p + 0xBAE, arc, 0, 0, 1, heap);
    func_021DCF54((char *)p + 0xC0E, arc, 0, 2, 3, heap);
    func_02049238(arc);
    func_02082BCC(&t, 0, 8);
    *(u16 *)(t.b) = 0;
    *(u16 *)(t.b + 2) = 24;
    t.b[7] = 1;
    t.b[6] = 1;
    {
        struct Obj *o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x38) = o;
        *(u16 *)(t.b + 4) = 2;
        o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x3C) = o;
        func_0204B3DC(o, 0);
    }
    t.b[6] = 0;
    k = 0;
    for (j = 0; j < 2; j++) {
        struct Obj *o;
        u8 *q;
        if (j == 0) {
            *(u16 *)(t.b) = 0x10;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        } else {
            *(u16 *)(t.b) = 0xF0;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        }
        q = p + j * 4;
        o = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, k, heap);
        *(struct Obj **)(q + 0xAB4 + 0x40) = o;
        func_0204B92C(*(struct Obj **)(q + 0xAB4 + 0x40), 1);
        func_0204B3DC(*(struct Obj **)(q + 0xAB4 + 0x40), k);
        if (j == 0) func_0204B604((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 1);
        else func_0204B604((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 0);
    }
    func_02040588(2, 1);
}

#pragma opt_dead_assignments reset
