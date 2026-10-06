/*
 * function: func_02017A20
 * address:  0x02017A20
 * packet:   pkt_02017A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020181F4  0x020181F4  thumb
 *   func_02017BC8  0x02017BC8  thumb
 *   func_02017988  0x02017988  thumb
 *   sMoveTbl       0x0209E298  data  a2
 *
 * Species check (id 5 == 0x1DF), then teach the move tbl[idx] from a
 * six-entry u16 table {0, 0x13B, 0x38, 0x3B, 0x193, 0x1B5} at 0x0209E298:
 * any slot already holding one of tbl[1..5] is overwritten (first hit) or
 * deleted (func_02017BC8, then the slot is re-examined), else the first
 * empty slot, else slot `val`; slot 0 empty gets move 0x54; finally
 * func_02017988(p, idx).  Wave 11, 2026-09-23.
 *
 * The straight-line six ldrh/strh copy with TWO `add rN, sp, #8` is a
 * 12-byte, 2-aligned aggregate copy scoped AFTER the guard: in the original
 * very likely a local initializer `u16 tbl[6] = {...}` inside a block (that
 * spelling is byte-identical but its anonymous rodata symbol cannot be named
 * in `symbols:`), written here as the equivalent struct copy from a named
 * extern so the relocation resolves (sole-ref).  Also load-bearing: `v` and
 * `val` are u32, so the (u16)/(u8) truncations land at the func_020181F4
 * calls; `k` is unsigned (`blo`), `i` signed (`blt`); `r != 0 && r ==
 * tbl.v[k]` is the inner test.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_02017BC8(u8 *p, u32 i);
extern u32 func_02017988(void *p, u32 a);

struct MoveTbl { u16 v[6]; };
extern const struct MoveTbl sMoveTbl;

u32 func_02017A20(void *p, u32 idx, u32 val)
{
    u32 v;
    int i;
    u32 k;

    if (func_02017E1C(p, 5, 0) != 0x1df)
        return 0;
    {
    struct MoveTbl tbl = sMoveTbl;
    v = tbl.v[idx];
    for (i = 0; i < 4; i++) {
        u32 r = func_02017E1C(p, i + 0x36, 0);

        for (k = 1; k < 6; k++) {
            if (r != 0 && r == tbl.v[k]) {
                if (v != 0) {
                    func_020181F4(p, v, (u8)i);
                    v = 0;
                } else {
                    func_02017BC8(p, i);
                    i--;
                }
                break;
            }
        }
    }
    }
    if (v != 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(p, i + 0x36, 0) == 0) {
                func_020181F4(p, v, (u8)i);
                break;
            }
        }
        if (i == 4)
            func_020181F4(p, v, (u8)val);
    }
    if (func_02017E1C(p, 0x36, 0) == 0)
        func_020181F4(p, 0x54, (u8)0);
    func_02017988(p, (u16)idx);
    return 1;
}
