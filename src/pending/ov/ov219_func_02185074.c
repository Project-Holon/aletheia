/*
 * function: func_02185074
 * address: 0x02185074
 * packet: pkt_ov219_02185074
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD6 lane16): still DIFF 17 bytes. Tried: static inline wrappers W(a, t, v, h) and W(h, a, t, v) calling
 *   f(a, t, v, v, h); Add(p, t, id) reading p inside; `v = d[i]` as the third argument with v as the fourth; a block
 *   with u16 h then u32 v locals. All keep the table load (CSE temp) before the stack argument.
 * 2026-10-05 (wD4 lane19): still DIFF 17 bytes, no new hypothesis beyond the 2026-10-04 notes closed it.
 * note 2026-10-04: DIFF, 17 bytes, loop body only. Original loads the u16 stack argument ((u16)*p) first,
 *   then the table pool address into r2 and indexes in r2; here the table base goes to r0 and the table
 *   load comes before the *p load. Everything else matches (u32 param c with (u16) casts in the call, loop
 *   as (i < 0x82) ? 1 : 0). Tried: locals k/w in both orders, static inline table reader, byte-offset read.
 *   2026-10-04 (D2): also tried plain d_02185F7C[i] twice, k local, callee last param u16 with u32 arg, local
 *   table pointer (59 bytes worse: hoists the pool load). Still 17 bytes: u16 stack arg must load before the table pool word.
 * 2026-10-05 (wD5 lane20): no new hypothesis closed it; the 17 byte residue is unchanged.
 * symbols:
 *   d_02185F7C 0x02185F7C data a4
 *   func_02184968 0x02184968 thumb ov219
 *   func_02045B38 0x02045B38 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02184FC8 0x02184FC8 thumb ov219
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_02185F7C[];
static inline u32 tb(int i) { return *(const u32 *)((const u8 *)d_02185F7C + i * 4); }
extern u32 func_02184968(const u8 *, int);
extern void *func_02045B38(u32, u32, u16, u16);
extern void *func_0201F81C(u32, u32);
extern void func_0201F878(void *, void *, u32, u32, u16);
extern void func_02045C04(void *);
extern void func_02184FC8(u8 *, u32, u32);

void func_02185074(u8 *p, const u8 *a, u32 b, u32 c)
{
    void *t;
    int i;
    *(u32 *)(p + 0xC018) = func_02184968(a, 1);
    t = func_02045B38(0, 2, (u16)c, (u16)*(u32 *)p);
    *(void **)(p + 0xC050) = func_0201F81C(0x82, *(u32 *)p);
    for (i = 0; (i < 0x82) ? 1 : 0; i++) {
        func_0201F878(*(void **)(p + 0xC050), t, tb(i), tb(i), (u16)*(u32 *)p);
    }
    func_02045C04(t);
    func_02184FC8(p, b, 0x82);
}
