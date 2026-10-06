/*
 * function: func_02156E30
 * address:  0x02156E30
 * packet:   pkt_ov009_02156E30
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * blocker:  relocation witness (label/sole-ref): callee 0x02060F18 has no outside witness
 * 2026-10-04: 0x02060F40 now EXACT in src/matched/arm9/func_02060F40.c. 0x02060F18 (an
 * ARM setter, bit 0 of the halfword at +0x36) is parked DIFF in
 * src/pending/arm9/func_02060F18.c (13 bytes: and-sink scheduling). Bytes here are correct.
 *
 * 2026-10-05 (wD4 lane 15): re-run, still MATCH. Only open reloc is THM_CALL func_02060F18 (arm9 setter, parked DIFF in
 * src/pending/arm9/func_02060F18.c); it needs that arm9 leaf filed EXACT.
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02060C5C  0x02060C5C  arm
 *   func_02060F18  0x02060F18  arm
 *   func_02060F40  0x02060F40  arm
 */

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

extern Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];

typedef unsigned short u16;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02060C5C(void *start, u32 size, u32 attr);
extern u32 func_02060F18(char *p, u32 v);
extern u16 func_02060F40(char *p, u16 v);

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
