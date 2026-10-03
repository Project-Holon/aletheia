/*
 * function: func_020316C8
 * address:  0x020316C8
 * packet:   pkt_020315F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 124 concrete bytes
 * of the body reproduce and 6 of 7 relocation sites resolve, but
 * func_02033534 (PC24 at +0x6c) has exactly one branch reference image-wide
 * and it is this call, so the site has no witness outside 020316C8..0203174C
 * and no cut frees it.  Filing 0x02033534 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * backup_system.c: the one-time allocation of the 0x210-byte save block.
 * The first parameter is narrowed to 16 bits at function entry (the split
 * `lsl r0, r0, #0x10` / `lsr r0, r0, #0x10` pair); written with the mask
 * folded into the call site.
 * The file string is at 0x020A7848 ("backup_system.c", pool word at
 * 0x02031744) and __LINE__ = 0xdf.  The second size argument 0x1100 - 0xdf
 * is spelled as the subtraction because 0x1021 is not an ARM-encodable
 * immediate and mwcc had 0xdf live in a register from the allocator's line
 * argument.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020819B8  0x020819B8  arm
 *   func_02033534  0x02033534  arm
 *   str_020A7848   0x020A7848  data
 *   g_02146994     0x02146994  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020316C8.c \
 *       --func func_020316C8 --addr 0x020316C8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heap, u32 size, int align, const char *file,
                         u16 line);
extern void func_02082A7C(u32 a, void *p, u32 n);
extern void func_020819B8(void *p, u32 n);
extern int func_02033534(u32 a);
extern const u8 str_020A7848[];
extern u8 *g_02146994;

void func_020316C8(u32 a0, u32 a1, u32 a2)
{
    u8 *p = func_02030734((u16)a0, 0x210, 0, (const char *)str_020A7848, 0xdf);

    g_02146994 = p;
    func_02082A7C(0, p, 0x210);
    func_020819B8(g_02146994 + 4, 0x1100 - 0xdf);
    *(u32 *)(g_02146994 + 0x204) = a1;
    p = g_02146994;
    *(u32 *)(p + 0x208) = a2;
    *(u32 *)g_02146994 = func_02033534((u32)p);
}
