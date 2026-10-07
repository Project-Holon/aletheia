/*
 * file:     btl_net_p02.c
 * unit:     yes
 * function: func_021D3F98, func_021D3FA8, func_021D3FAC, func_021D3FC4, func_021D3FD0, func_021D3FDC, func_021D4150, func_021D4230, func_021D4254, func_021D4270
 * address:  0x021D3F98
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
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021EAE64 0x021EAE64 thumb ov093
 *   func_021EAE04 0x021EAE04 thumb ov093
 *   func_021EAECC 0x021EAECC thumb ov093
 *   func_02005E30 0x02005E30 thumb
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006734 0x02006734 thumb
 *   func_021F8B10 0x021F8B10 thumb ov094
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021EAE14 0x021EAE14 thumb ov093
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   d_021F3A98 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D4A6C 0x021D4A6C thumb ov093
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 */
#include "../../matched/include/Obj13430.h"

struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 pad[2]; u8 f0:1,f1:1,f2:1,f3:1,f4:1,rest:3; } Flags_021D3FAC;

typedef struct { u8 pad[2]; u8 low:4,flag:1,rest:3; } Flags_021D3FC4;

struct Q {
    u8 state, mode;
    u8 flag0:1, flag1:1, flag2:1, flag3:1, flag4:1, flag5:1, rest:2;
    u8 unk3;
    u16 delay, current, target, maximum, tick;
};

struct S {
    void *link;
    u16 heap;
    u8 id, f07;
    u16 mask;
    u8 f0a, count, f0c, f0d, f0e, f0f, f10, states[4];
    u8 pad[0x3ae4 - 0x15];
    void *tblA[4], *tblB[4], *tblC[4], *f3b14, *f3b18;
};

extern void func_021EAE74(char *p, u32 a, u32 b);
extern int func_021EAE64(void *);
extern void func_021EAE04(u32 *p);
extern void func_021EAECC(u8 *p, int v, int w);
extern void func_02005E30(u32);
extern void func_02005CA4(int,u32);
extern void func_02006734(u8);
extern int func_021F8B10(void);
extern void func_021B92A0(u8 *p);
extern int func_021EAE14(u32 *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_0203D1A4(struct Link *p);
extern int func_0203D1B4(void);
extern void func_021D4AF4(int a);
extern int func_021D4B18(int);
extern void func_021D4A6C(void);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
int func_021D3F98(u8 *p);
u16 func_021D3FA8(u8 *p);
int func_021D3FAC(Flags_021D3FAC *p);
void func_021D3FC4(Flags_021D3FC4 *p);
void func_021D3FD0(unsigned char *p);
void func_021D3FDC(u8 *p, struct Q *q);
void func_021D4150(void *link, u16 mask, u16 heap);
int func_021D4230(void);
void func_021D4254(void);
int func_021D4270(void);
extern struct S *d_021F3B88;
extern u8 d_021F3A98[];

int func_021D3F98(u8 *p)
{
    if (((struct Obj13430 *)p)->fC == ((struct Obj13430 *)p)->f8) return 1;
    return 0;
}


/*
 * ldrh at #0x8
 */
u16 func_021D3FA8(u8 *p)
{
    return *(u16 *)&p[0x8];
}

/*
 * extent: Twenty-two code bytes plus two zero padding bytes at 021D3FC2;
 * the approved separate 021D3FC4 leaf and existing 021D3FD0 follow.
 */
int func_021D3FAC(Flags_021D3FAC *p)
{
    if (p->f1) return 0;
    p->f4 = 1;
    return 1;
}

/*
 * match-note: Clearing the unsigned-char bitfield emits bics #0x10;
 * raw p[2] &= ~0x10 emits ands #0xef and was four bytes out.
 * extent: Ten bytes of code, two zero padding bytes at 021D3FCE, then
 * existing matched func_021D3FD0 at 021D3FD0; no follower included.
 */
void func_021D3FC4(Flags_021D3FC4 *p)
{
    p->flag = 0;
}

void func_021D3FD0(unsigned char *p)
{
    p[2] |= 0x20;
}

/*
 * note 2026-10-05: now verifies EXACT (func_021F8B10 resolves).
 * match-note: A goto to the bottom epilogue reproduces the entry guards;
 * input is called before adjusted=0, preserving the original scheduling.
 */
void func_021D3FDC(u8 *p, struct Q *q)
{
    int changed, adjusted, input;
    if (p[0x1a7] != 2 || q->flag4 || q->flag5 || !q->maximum) goto done;
    changed = 0;
    if (q->flag3) {
        q->flag3 = 0;
        if (!q->flag0) {
            if (q->current < q->maximum && q->state == 0) {
                ++q->current;
                if (!q->delay) q->target = q->current;
                changed = 1;
            }
        } else {
            if (q->tick < q->target) {
                ++q->tick;
                if (q->tick == q->target) {
                    q->current = q->target;
                    if (*(void **)(p+0x54)) func_021EAE74(*(void **)(p+0x54),q->current,q->target);
                }
            }
            return;
        }
    }
    if (!q->current || !*(void **)(p+0x54)) return;
    switch (q->state) {
    case 0:
        input = func_021EAE64(*(void **)(p+0x54));
        adjusted = 0;
        switch (input) {
        case 2:
            q->mode = 1;
            func_021EAE04(*(void **)(p+0x54));
            q->flag1 = 1;
            q->state = 1;
            func_021EAECC(*(void **)(p+0x54),q->current,1);
            func_02005E30(30);
            func_02005CA4(0,62);
            func_02006734(0);
            func_021F8B10();
            func_021B92A0((u8 *)(*(u32 *)p));
            break;
        case 0:
            if (q->target > 1) { --q->target; adjusted = 1; }
            q->delay = 45;
            break;
        case 1:
            if (q->target < q->maximum) { ++q->target; adjusted = 1; }
            q->delay = 45;
            break;
        }
        if (adjusted || changed) func_021EAE74(*(void **)(p+0x54),q->current,q->target);
        if (q->delay) {
            --q->delay;
            if (!q->delay) {
                q->mode = 2;
                func_021EAE04(*(void **)(p+0x54));
                q->flag1 = 1;
                q->state = 1;
                func_02005E30(30);
                func_02005CA4(0,62);
                func_02006734(0);
                func_021F8B10();
            }
        }
        break;
    case 1:
        if (func_021EAE14(*(void **)(p+0x54))) { q->flag2 = 1; q->state = 2; }
        break;
    case 2:
        break;
    }
done:
    return;
}

/*
 * lever: Separate loop counters; use the first counter's initialized zero
 * for f0d/f0e stores before entering that loop.
 */
void func_021D4150(void *link, u16 mask, u16 heap)
{
    u32 count, i, j, k, limit;
    if (link) {
        d_021F3B88 = func_02030734(heap, 0x3b2c, 1, (const char *)d_021F3A98, 0xd4);
        d_021F3B88->link = link;
        d_021F3B88->mask = mask;
        d_021F3B88->heap = heap;
        d_021F3B88->id = func_0203D1A4(link);
        d_021F3B88->f07 = 0x28;
        i = 0;
        d_021F3B88->f0d = i;
        d_021F3B88->f0e = i;
        count = 0;
        for (; i < 4; i++) if (mask & (1U << i)) count++;
        limit = func_0203D1B4();
        if (count > limit) count = limit;
        d_021F3B88->count = count;
        d_021F3B88->f0f = 0;
        d_021F3B88->f10 = 0;
        d_021F3B88->f0a = 0;
        for (j = 0; j < 4; j++) {
            d_021F3B88->tblA[j] = 0;
            d_021F3B88->tblB[j] = 0;
            d_021F3B88->states[j] = 4;
        }
        for (k = 0; k < 4; k++) d_021F3B88->tblC[k] = 0;
        d_021F3B88->f3b14 = 0;
        d_021F3B88->f3b18 = 0;
        func_021D4AF4(1);
    } else d_021F3B88 = 0;
}

int func_021D4230(void) { int r; if(d_021F3B88) { r=1; if(func_021D4B18(1)==0) r=0; return r; } return 1; }

void func_021D4254(void) { if(d_021F3B88) { func_021D4A6C(); func_020307B0(d_021F3B88); } }

int func_021D4270(void) { if(d_021F3B88) { if(func_0200FB24()) return 1; return 0; } return 0; }
