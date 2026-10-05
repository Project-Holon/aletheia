/*
 * function: func_02189548
 * address: 0x02189548
 * packet: pkt_ov096_02189548
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes). Whole-body swap: image p=r4 q=r5, ours p=r5 q=r4. Allocation looks priority-ordered by reference count (q has four references, p four); no source tie-break found without changing the bytes.
 * note: 2026-10-04 Residue: whole-body register swap (original p in r4, q in r5; ours p in r5, q in r4); branch layout and instructions match otherwise. First param is unused (original uses r1 as p). Tried: ternary, early store, v-first, int v, copy of p, hoisted field pointer, struct p, split index locals, || vs && with Y-first.
 * note: 2026-10-05 (wD4 lane20): tried swapped declaration order of q and v, and the nested call chain split into three statements (a = f(x); a = g(p,a); q = h(p,a)); p stays r5, q r4. Residue unchanged: whole-body p/q colour swap (10 bytes).
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D679C 0x021D679C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(u8 *);
extern u32 func_0218A160(u8 *, u32);
extern u8 *func_0218A2FC(u8 *, u32);
extern u16 func_021D67A8(u8 *);
extern u32 func_021D679C(u8 *);
u32 func_02189548(u8 *x, u8 *p)
{
    u8 *q;
    u32 v;
    q = func_0218A2FC(p, func_0218A160(p, func_0201134C(x)));
    if (func_021D67A8(q) != 0xB6 && func_021D67A8(q) != 0xC5 && func_021D67A8(q) != 0xCB)
        v = 0;
    else
        v = func_021D679C(q);
    *(u32 *)(p + 0x38) = v;
    return *(u32 *)(p + 0xC4);
}
