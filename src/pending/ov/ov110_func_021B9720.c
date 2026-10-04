/*
 * function: func_021B9720
 * address: 0x021B9720
 * packet: pkt_ov110_021B9720
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-04 (wD1 lane17): DIFF, schedule only. Body logic is right (bitset at p+0x1D6E, range test base..base+7 via func_02024994). Orig emits `movs r1,#0` right after bl 0x202414C and before the str of the result, ours emits movs r0,#0 after the str. Stack slots (base 8, count 0xC, limit 0x10, obj 0x14) are matched by decl order limit,count,base. Tried: decl order permutations, count=0 as statement vs initialiser, base/limit as separate statements. Callees 0x0202414C and 0x02024994 have no arm9 label.
 * symbols:
 *   func_0202414C 0x0202414C thumb
 *   func_02024888 0x02024888 thumb
 *   func_02024994 0x02024994 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0202414C(u32 a);
extern u16 func_02024888(u32 idx, u16 add);
extern int func_02024994(void *o, u32 idx);
u32 func_021B9720(u8 *p, u16 *src, u32 n, u16 *out)
{
    u32 count = 0;
    u32 limit;
    u32 base;
    void *o = func_0202414C(*(u32 *)p);
    base = func_02024888(0x97, 0);
    limit = (u16)(base + 7);
    u32 i;
    for (i = 0; i < n; i++) {
        u32 v = src[i];
        if (v >= base && v <= limit) {
            if (func_02024994(o, v - base) == 0)
                continue;
        }
        v = src[i];
        p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
        *out = v;
        out++;
        count++;
    }
    return count;
}
