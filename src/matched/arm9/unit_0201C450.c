/*
 * unit:     yes
 * address:  0x0201C450
 * packet:   pkt_0201C450
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201C450, sub_0201C4C0, sub_0201C4C8, sub_0201C4DC
 *
 * symbols:
 *   sub_0201C450_File   0x020A734C  data
 *
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * sub_0201C4DC writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

extern const char sub_0201C450_File[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);

union Ticks {
    u64 v;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    union Ticks unk08;
    void *unk10;
    void *unk14;
};

void *sub_0201C450(u16 n, u32 heap)
{
    u16 v = n + 0x1C;
    struct PrintSys *p;

    while (v % 4 != 0) {
        v++;
    }
    p = func_02030734(heap, v + 0x18, 0, sub_0201C450_File, 287);
    p->unk04 = n;
    p->unk08.v = 0x1130;
    p->unk10 = 0;
    p->unk14 = 0;
    ((u8 *)p)[7] = ((u8 *)p)[7] & ~0xFu;
    ((u8 *)p)[7] = ((u8 *)p)[7] & ~0xF0u;
    p->unk06 = 0;
    p->unk00 = 0;
    p->unk02 = n;
    return p;
}

void sub_0201C4C0(struct PrintSys *p)
{
    func_020307B0(p);
}

void sub_0201C4C8(struct PrintSys *p, u32 v)
{
    ((u8 *)p)[7] = (((u8 *)p)[7] & ~0xF0u) | (u8)((u8)v << 4);
}

void sub_0201C4DC(struct PrintSys *p, u32 lo, u32 hi)
{
    p->unk08.w.lo = lo;
    p->unk08.w.hi = hi;
}
