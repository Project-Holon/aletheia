/*
 * file:     dwc_rap_p08.c
 * unit:     yes
 * function: func_02156DC4, func_02156DE0, func_02156DFC, func_02156E24, func_02156E30, func_02156ED0, func_02156F14, func_02156F50, func_02156F5C, func_02156FDC
 * address:  0x02156DC4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 *   abs_id_11  0x00000011  data
 *   func_02157108  0x02157108  thumb  ov009
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021B6100  0x021B6100  thumb  ov017
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02060C5C  0x02060C5C  arm
 *   func_02060F18  0x02060F18  arm
 *   func_02060F40  0x02060F40  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02060C94  0x02060C94  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02060CA0  0x02060CA0  arm
 *   func_0200FB6C  0x0200FB6C  thumb
 *   func_02060F98  0x02060F98  arm  arm9
 *   func_02060E30  0x02060E30  arm
 */
#include "../../matched/include/G_Obj.h"

struct ExpHeap;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
} Obj;

typedef signed int     s32;

extern int func_02157108(u16 a);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int id);
extern void func_021B6100(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02060C5C(void *start, u32 size, u32 attr);
extern u32 func_02060F18(char *p, u32 v);
extern u16 func_02060F40(char *p, u16 v);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_02060C94(void *heap);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 heap);
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
extern void func_0200FB6C(void);
extern u8 func_02060F98(char *p);
extern void func_02060E30(struct ExpHeap *heap, void *block);
/* * Recursive MATCH unblocker: callee of func_021DA5D0 (ov123) +004A. Coherent * Thumb code in ov009 (ov010 holds the tail of another function), so the ov009 * shard makes that site attest as `matched`. */ void func_02156DC4(int a0, int a1);
/* * leaf: sole blocker of owned ov123 021D920C; parent ownership audit passed. * extent: next labelled function 02156DFC follows the 28-byte leaf. */ void func_02156DE0(int a, int b);
/* * The pooled 0x11 is the overlay id of ov017 (absolute linker symbol, see * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): load * ov017, run func_021B6100 there, unload it. */ void func_02156DFC(int a);
void func_02156E24(int a, int b, int c);
void func_02156E30(u32 a, u32 b, u32 c, u32 d);
void func_02156ED0(void);
void func_02156F14(void);
/* * Setter after the function ending at pool 0x02156F4C, which stores to the * same halfword: writes its argument to +0x20 of the object d_021A8268 * points to. Called from the ov175 root func_021D7E18 (0x021D85E0). */ void func_02156F50(int a);
u32 func_02156F5C(u32 a, u32 b, u32 c);
void func_02156FDC(u32 a, void *p, int b);
extern int *g_021A8264;
extern unsigned char abs_id_11[];
extern struct Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];







/*
 * Recursive MATCH unblocker: callee of func_021DA5D0 (ov123) +004A. Coherent
 * Thumb code in ov009 (ov010 holds the tail of another function), so the ov009
 * shard makes that site attest as `matched`.
 */
void func_02156DC4(int a0, int a1)
{
    *(int *)((char *)g_021A8264 + 0x28C) = a0;
    *(int *)((char *)g_021A8264 + 0x290) = a1;
}






/*
 * leaf: sole blocker of owned ov123 021D920C; parent ownership audit passed.
 * extent: next labelled function 02156DFC follows the 28-byte leaf.
 */
void func_02156DE0(int a, int b)
{
    *(int *)((char *)g_021A8264+0x294)=a;
    *(int *)((char *)g_021A8264+0x298)=b;
}







/*
 * The pooled 0x11 is the overlay id of ov017 (absolute linker symbol, see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): load
 * ov017, run func_021B6100 there, unload it.
 */
void func_02156DFC(int a)
{
    if (func_02157108(a) == 3) {
        func_02034AC4((int)abs_id_11);
        func_021B6100();
        func_02034A5C((int)abs_id_11);
    }
}






/*
 * Calls func_02156E30 with a zero third argument.
 */
void func_02156E24(int a, int b, int c)
{
    func_02156E30(a, b, 0, c);
}





/*
 * 2026-10-05 (wave D7 lane 18): the blocker func_02060F18 is now EXACT in
 *   src/matched/arm9/func_02060F18.c (old bit read first, two stores through a u16 pointer local).
 *   This file stays MATCH only until the integrator regenerates the matched-label layout; then the
 *   0x02060F18 relocation resolves and this file can be filed EXACT unchanged.
 * 2026-10-05 (wave D6 lane 19): still MATCH, blocked only by arm9 func_02060F18 (DIFF). New finding on
 *   that leaf: a u16 (or u8) RETURN type with `u32 old = *(u16 *)(p + 0x36); ... return old & 1;` stops the
 *   and-sink (gives `and; ...; mov r0,rX` as in the image), but the colours move (old in ip, v&1 in r2;
 *   image old r3, v&1 in r1). Early `old = x & 1` with u32 return still sinks. Compound `&= ~1` / `|=`
 *   on a u16 lvalue gives a 0xFFFE pool mask and lsl/lsr. Not filed.
 * 2026-10-05 (wave D5 lane 02): re-verified MATCH; the only open site is func_02060F18 (arm9), still DIFF by 13 bytes (see src/pending/arm9/func_02060F18.c).
 * 2026-10-04: 0x02060F40 now EXACT in src/matched/arm9/func_02060F40.c. 0x02060F18 (an
 * ARM setter, bit 0 of the halfword at +0x36) is parked DIFF in
 * src/pending/arm9/func_02060F18.c (13 bytes: and-sink scheduling). Bytes here are correct.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Only open reloc is THM_CALL func_02060F18 (arm9 setter, parked DIFF in
 * src/pending/arm9/func_02060F18.c); it needs that arm9 leaf filed EXACT.
 */
void func_02156E30(u32 a, u32 b, u32 c, u32 d)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->fC != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f8 != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    d_021A8268->fC = (u32)func_02030734(d, b - 0x80, 0, d_021A1C7C, 0x62);
    d_021A8268->f8 = (u32)func_02060C5C((void *)((d_021A8268->fC + 0x1f) & ~0x1f), b - 0xc0, 0);
    d_021A8268->f10 = a;
    func_02060F18((char *)d_021A8268->f8, 1);
    func_02060F40((char *)d_021A8268->f8, 0xea);
    d_021A8268->f18 = c;
}




void func_02156ED0(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f14 != 0) {
        func_0203C9AC(0, 0, 0, 0x3EE);
        d_021A8268->f1C = 1;
        return;
    }
    func_02156F14();
}



void func_02156F14(void)
{
    if (d_021A8268->fC != 0) {
        func_02060C94((void *)d_021A8268->f8);
        func_020307B0((void *)d_021A8268->fC);
        d_021A8268->f8 = 0;
        d_021A8268->fC = 0;
        if (d_021A8268->f20 != 0) {
            func_020306F0(d_021A8268->f20);
            d_021A8268->f20 = 0;
        }
    }
}




/*
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object d_021A8268
 * points to. Called from the ov175 root func_021D7E18 (0x021D85E0).
 */
void func_02156F50(int a)
{
    *(u16 *)(((char *)d_021A8268) + 0x20) = a;
}




u32 func_02156F5C(u32 a, u32 b, u32 c)
{
    u32 h;
    u32 r;

    if (d_021A8268->f8 != 0 && a == d_021A8268->f10 && b > d_021A8268->f18) {
        h = func_02087988();
        r = (u32)func_02060CA0((struct ExpHeap *)d_021A8268->f8, b, c);
        func_0208799C(h);
        d_021A8268->f14++;
    } else {
        h = func_02087988();
        r = (u32)func_02060CA0((struct ExpHeap *)d_021A8268->f0, b, c);
        func_0208799C(h);
    }
    if (r == 0) {
        func_0200FB6C();
        func_0203C9AC(0, 0, 0, 0x3EE);
        return 0;
    }
    return r;
}


/*
 * witness:  callee 0x02060F98 is witnessed by its ARM9 entry
 *           (src/matched/arm9/func_02060F98.c, pkt_02060F98).
 */
void func_02156FDC(u32 a, void *p, int b)
{
    u32 h;

    if (p == 0) {
        return;
    }
    if (func_02060F98(p) == 0xEA) {
        if (d_021A8268->f8 != 0) {
            h = func_02087988();
            func_02060E30((struct ExpHeap *)d_021A8268->f8, p);
            func_0208799C(h);
            d_021A8268->f14--;
            return;
        }
        func_0203C9AC(0, 0, 0, 0x3EE);
        return;
    }
    h = func_02087988();
    func_02060E30((struct ExpHeap *)d_021A8268->f0, p);
    func_0208799C(h);
}
