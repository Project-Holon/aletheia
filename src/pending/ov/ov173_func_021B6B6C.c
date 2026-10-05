/*
 * function: func_021B6B6C
 * address: 0x021B6B6C
 * packet: pkt_ov173_021B6B6C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave P23 lane 6): 48 of 52 bytes, 15 bytes differ. Only residue: the original
 *   builds 0x1b0 fresh (movs r0,#0x1b; movs r1,#3; lsls r0,r0,#4; str) after the pooled 0x1ba
 *   strb. The build derives it from the live 0x1ba register (movs r1,#3; subs r0,#0xa; str).
 *   Reverse order (str first) derives 0x1ba by adds, so the derivation runs from the first
 *   constant to the second. Tried, all unchanged at 15: struct fields (one struct, two structs),
 *   index local k=0x1ba, u32 array index [0x6c], static inline word setter, pointer block local,
 *   pragmas opt_common_subs, opt_propagation, opt_lifetimes, scheduling, peephole off.
 *   Callee func_021B7460 is void(char *, u32) in matched ov173 siblings: no arity problem.
 * symbols:
 *   func_021B7460 0x021B7460 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B7460(char *, u32);
int func_021B6B6C(char *p)
{
    u8 n;
    if (*(u8 *)(*(char **)p + 0x1b) < 4) {
        func_021B7460(p, 10);
        n = 4;
    } else {
        func_021B7460(p, 7);
        n = 3;
    }
    p[0x1ba] = n;
    *(u32 *)(p + 0x1b0) = 3;
    return 2;
}
