/*
 * function: func_02034558
 * address:  0x02034558
 * packet:   pkt_02034558
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   sub_02030734  0x02030734  arm
 *   sub_02034520  0x02034520  arm
 *   sub_020345F8  0x020345F8  arm
 *   sub_02033C00  0x02033C00  arm
 *   _u32_div_f    0x0209C2B0  arm
 *   s_clact_c     0x020A7964  data
 *
 * vman.c: allocate a VRAM bank record and carve its area: the flag set's
 * size less the base, divided by the row height (0x20, or the caller's
 * value when kind is 1).  The 13-byte register rotation of
 * docs/notes/func_02034558.r6.c.txt was the height LOCAL: the image stores
 * the height into the record in each arm and the divide re-reads the field
 * (`strh` then `ldrh r1, [r5, #4]`), so there is no height value to
 * allocate.  Its two callees are matched now, so nothing caps it.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bank {
    void *data;
    u16   height;
    u16   base;
};

struct AreaMan;
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   sub_02034520(u32 flags);
extern u32   sub_020345F8(u32 b);
extern struct AreaMan *sub_02033C00(u32 size, u32 heap);
extern char  s_clact_c[];

struct Bank *func_02034558(u32 heapId, u32 kind, u32 flags, u32 base, u32 b)
{
    struct Bank *bank;
    u32 size;

    bank = sub_02030734(heapId, 8, 0, s_clact_c, 0x7a);
    size = sub_02034520(flags) - base;
    if (kind == 1)
        bank->height = sub_020345F8(b);
    else
        bank->height = 0x20;
    bank->data = sub_02033C00(size / bank->height, heapId);
    bank->base = base;
    return bank;
}
