/*
 * function: CLACT_AllocCharacterTable
 * address:  0x0204DA5C
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes one of the two clact.c fan-in-1 blockers of CLACT_InitResources
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * CLACT_AllocPaletteTable, the packet's next function).
 *
 * Allocate `count` 0x40-byte records and initialise each: set bit 31 of
 * the word at +0x3c (a one-bit bitfield, unconditional `bic`/`orr` of the
 * same immediate is the bitfield-store tell), then hand the two
 * two-word sentinel pairs at +0x2c and +0x34 to VMAN_InvalidateHandle (already
 * matched, src/matched/unit_02034630.c).
 *
 * symbols:
 *   s_clact_c     0x020A7F74  data
 *   VMAN_InvalidateHandle  0x02034630  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AllocCharacterTable.c \
 *       --func CLACT_AllocCharacterTable --addr 0x0204DA5C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sentinel {
    u32 lo;
    u32 hi;
};

struct Rec {
    u8  pad_00[0x2c];
    struct Sentinel a;      /* 0x2c */
    struct Sentinel b;      /* 0x34 */
    u32 unk_3c_0  : 31;     /* 0x3c */
    u32 unk_3c_31 : 1;
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void  VMAN_InvalidateHandle(struct Sentinel *p);

extern char s_clact_c[];

void *CLACT_AllocCharacterTable(u32 heapId, u32 count)
{
    u32 i;
    struct Rec *arr;

    arr = sub_02030734(heapId, count << 6, 0, s_clact_c, 0x1bbe);

    for (i = 0; i < count; i++) {
        struct Rec *r = &arr[i];
        r->unk_3c_31 = 1;
        VMAN_InvalidateHandle(&r->a);
        VMAN_InvalidateHandle(&r->b);
    }

    return arr;
}
