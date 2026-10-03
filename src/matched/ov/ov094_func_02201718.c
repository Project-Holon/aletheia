/*
 * function: func_02201718
 * address: 0x02201718
 * packet: pkt_ov094_02201718
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Flags { unsigned low:3; unsigned count:2; unsigned high:27; } Flags;
typedef struct GlobalFlags { unsigned low:2; unsigned disabled:1; unsigned high:29; } GlobalFlags;
extern char *func_021F8694(void);
extern void *func_021F86C4(void);
extern int func_021F9824(void *);
extern u8 func_02015EF4(char *p);
extern u32 func_0203F0A8(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_02015EEC(char *p);
extern void func_02016028(void *, u32);
extern void *func_02030DA8(void *, void (*)(void *, int *), void *, u32);
extern void func_02201304(void *, int *);
extern const char d_0220AE7C[];
void func_02201718(int i)
{
    char *p = func_021F8694();
    char *e;
    int off;
    unsigned n;
    u32 draw;
    int *q;
    if (i == -1) return;
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) return;
    if (func_021F9824(func_021F86C4()) == 0) return;
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
    q = func_02030734((u16)((*(u16 *)(p + 0x540) & 0x7fff) | 0x8000), 12, 1, d_0220AE7C, 0xd5e);
    q[1] = i;
    if (func_02015EEC(*(void **)(e + off)) > 1) func_02016028(*(void **)(e + off), 1);
    *(void **)(p + off + 0x30) = func_02030DA8(*(void **)p, func_02201304, q, 0);
}
