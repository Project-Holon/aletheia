/*
 * function: func_021D9BC4
 * address:  0x021D9BC4
 * packet:   pkt_021D9BC4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020173E8  0x020173E8  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *
 * Equality of two lists: same count, and every pair of entries compares equal over the record size 0x020173E8 returns; 1 when equal, else 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_0201AA18(u32 list);
extern void *func_0201AB28(void *p, u32 idx);
extern u8 *func_020185F0(u32 entry);
extern u32 func_020173E8(void);
extern int func_0203EFC8(const u8 *a, const u8 *b, u32 n);

int func_021D9BC4(u32 a, u32 b)
{
    u32 n = func_0201AA18(a);
    u32 i;

    if (n == func_0201AA18(b)) {
        for (i = 0; i < n; i++) {
            u32 ea = (u32)func_0201AB28((void *)a, i);
            u32 eb = (u32)func_0201AB28((void *)b, i);
            u8 *pa = func_020185F0(ea);
            u8 *pb = func_020185F0(eb);
            if (func_0203EFC8(pa, pb, func_020173E8()) != 0)
                return 0;
        }
        return 1;
    }
    return 0;
}
