/*
 * file:     btlv_effvm_p79.c
 * unit:     yes
 * function: func_02201718, func_02201810
 * address:  0x02201718
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021F86C4 0x021F86C4 thumb ov094
 *   func_021F9824 0x021F9824 thumb ov094
 *   func_02015EF4 0x02015EF4 thumb
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_02030734 0x02030734 arm
 *   func_02015EEC 0x02015EEC thumb
 *   func_02016028 0x02016028 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   func_02201304 0x02201304 thumb ov094
 *   d_0220AE7C 0x0220AE7C data a4
 *   func_02015EFC  0x02015EFC  thumb
 */
#include "../../matched/include/Obj13608.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Flags { unsigned low:3; unsigned count:2; unsigned high:27; } Flags;

typedef struct GlobalFlags { unsigned low:2; unsigned disabled:1; unsigned high:29; } GlobalFlags;

typedef struct {
    int pad[2];
    void *h;
    char pad2[0x5C - 12];
} Row;

extern int func_021F8694(void);
extern int func_021F86C4(void);
extern int func_021F9824(void *);
extern u8 func_02015EF4(char *p);
extern u32 func_0203F0A8(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_02015EEC(char *p);
extern void func_02016028(void *, u32);
extern void *func_02030DA8(void *, void (*)(void *, int *), void *, u32);
extern void func_02201304(void *, int *);
extern u8 func_02015EFC(char *p, u8 i);
void func_02201718(int i);
int func_02201810(u32 flags, int a, int *out, int key);
extern const char d_0220AE7C[];

/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015EF4 and 02015EEC are Ilias-owned.
 * Verified C for 02015EF4 reused from ov094_func_02201810.c:
 *   typedef unsigned char u8;
 *   u8 func_02015EF4(char *p) { return **(u8 **)(p + 0x30); }
 * Verified C for 02015EEC: one, Thumb dsi/1.1p1 -O4,p EXACT 6 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/eec-proof.log
 *   typedef unsigned short u16;
 *   u16 func_02015EEC(char *p) { return **(u16 **)(p + 0x28); }
 * lever: Bind the random draw before the variable 64-bit product.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces;
 * 02015EEC has only this caller. No overlay leaves filed.
 */
void func_02201718(int i)
{
    char *p = (char *)func_021F8694();
    char *e;
    int off;
    unsigned n;
    u32 draw;
    int *q;
    if (i == -1) return;
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) return;
    if (func_021F9824((void *)func_021F86C4()) == 0) return;
    if (((GlobalFlags *)(p + 0x510))->disabled) return;
    if (func_02015EF4(*(void **)(e + off)) == 0xff) {
        *(u32 *)(p + 0x54 + off) |= 0x800;
        return;
    }
    n = ((Flags *)(p + 0x54 + off))->count;
    ((Flags *)(p + 0x54 + off))->count = n - 1;
    draw = func_0203F0A8();
    if ((u32)(((u64)draw * n) >> 32) != 0) return;
    ((Flags *)(p + 0x54 + off))->count = 3;
    q = func_02030734((u16)((((struct Obj13608 *)p)->f540 & 0x7fff) | 0x8000), 12, 1, d_0220AE7C, 0xd5e);
    q[1] = i;
    if (func_02015EEC(*(void **)(e + off)) > 1) func_02016028(*(void **)(e + off), 1);
    *(void **)(p + off + 0x30) = func_02030DA8(((struct Obj13608 *)p)->f0, func_02201304, q, 0);
}


/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): two unlabelled arm9 Thumb leaves (Ilias's; no witness outside this range).
 *   Every concrete byte matches; only the two bl relocation sites stay wildcarded.
 *   Verified C (match.py one --arm9 no --region, --thumb, dsi/1.1p1 -O4,p), both EXACT:
 *
 *     typedef unsigned char u8;
 *     u8 func_02015EF4(char *p)              // 0x02015EF4, 6 bytes
 *     {
 *         return **(u8 **)(p + 0x30);
 *     }
 *     u8 func_02015EFC(char *p, int i)       // 0x02015EFC, 8 bytes
 *     {
 *         return (*(u8 **)(p + 0x30) + i)[2];  // `[i + 2]` is 5 bytes out
 *     }
 *
 * lever: the first test reads the row through the indexed base (`base[idx].h`), the loop
 *   through `e = &base[idx]` inside the loop body; a shared `base + off` char cast is CSE'd
 *   into one register and comes out 8 bytes short. `idx == -1` (u16 against int -1) is not
 *   folded: it keeps the movs/mvns pair. The two `v = 1` arms cross-jump only when the
 *   found test is `if (found == 0) v = 0; else v = 1;`.
 */
int func_02201810(u32 flags, int a, int *out, int key)
{
    Row *base = (Row *)func_021F8694();
    u16 idx = flags;
    int found;
    int n;
    int i;
    int v;

    if (idx == -1)
        return 0;
    if (base[idx].h == 0)
        return 0;
    if (flags & 0x80000000) {
        found = 0;
        n = func_02015EF4(base[idx].h);
        for (i = 0; i < n; i++) {
            Row *e = &base[idx];

            if (key == func_02015EFC(e->h, i))
                found = 1;
        }
        if (found == 0)
            v = 0;
        else
            v = 1;
    } else {
        v = 1;
    }
    out[3] = v;
    return 1;
}
