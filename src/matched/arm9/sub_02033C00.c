/*
 * function: AREAMAN_Create
 * address:  0x02033C00
 * packet:   pkt_02033C00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02033C00_File  0x020A7958  data
 *   func_02030734      0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *
 * alias: "areaman.c".  The pool word at 0x02033C94 holds 0x020A7958 and the
 * bytes there spell "areaman.c", so this range is the head of that file; the
 * `string` class closes the site because "gmdataid < svdt->table_max" ends
 * with its NUL at 0x020A7956 and two bytes of padding put the next string at
 * 0x020A7958 by construction.
 *
 * The constructor of the area manager: `size` is a count of areas, and the
 * object carries a bitmap one bit per area.  The byte count is rounded up
 * from the bit count and then up again to a multiple of four, the allocation
 * is 0xC bytes of header plus the bitmap plus the four byte guard word
 * 0x573C765A that is written immediately past the bitmap, and the bitmap
 * itself is cleared.  The guard word is what the checker in this subsystem
 * re-reads to catch an overrun.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AREAMAN_Create.c \
 *       --func AREAMAN_Create --addr 0x02033C00 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

extern const char sub_02033C00_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);

struct AreaMan *AREAMAN_Create(u32 size, u32 heap)
{
    struct AreaMan *p;
    u32 n;
    u16 nbytes;

    n = ((size & 7) != 0) + (size >> 3);
    while ((n & 3) != 0) {
        n++;
    }
    nbytes = (u16)n;

    p = func_02030734(heap, nbytes + 0x10, 0, sub_02033C00_File, 0x94);
    p->unk00 = (u16)size;
    p->unk02 = nbytes;
    p->guard = (u32 *)(p->bits + nbytes);
    *p->guard = 0x573C765A;
    p->unk08 = 0;
    MI_CpuFill8(p->bits, 0, nbytes);
    return p;
}
