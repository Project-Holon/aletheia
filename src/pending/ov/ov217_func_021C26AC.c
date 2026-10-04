/*
 * function: func_021C26AC
 * address:  0x021C26AC
 * packet:   pkt_ov217_021C26AC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wC1 lane06): 58 bytes.  Search of a 12-byte-stride table of
 * u16 keys under group callee-result*0xd4 (+4).  Original: p kept in r5,
 * `adds r2,r5,#4` after the muls, i in r0 (the call result register), the
 * count e[1] (signed compare, `ble`) reloaded at the loop bottom into r3.
 * This draft caches e[1] and picks r5/r3 differently.  Tried u8/s32 counters,
 * do-while with guard, typed struct view, base-pointer local.
 *
 * symbols:
 *   func_021C2684  0x021C2684  thumb  ov217
 *
 * Note 2026-10-04 (wD1 lane06): Retried: e += n*0xd4 split, (u32) cast sum, e = n*0xd4 + (u32)(p+4), do-while with guard, typed Grp/Ent struct views, int/u8 count. Original does muls before adds r2,r5,#4 and reloads e[1] at the loop bottom; none of these spellings change either (26 bytes differ).
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C2684(void *p);

u32 func_021C26AC(u8 *p, u32 unused, u32 key)
{
    u8 *e = p + 4 + func_021C2684(p) * 0xd4;
    s32 i;
    for (i = 0; i < e[1]; i++) {
        if (key == *(u16 *)(e + 8 + i * 0xc))
            return (u8)i;
    }
    return 0;
}
