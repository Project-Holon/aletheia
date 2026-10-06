/*
 * unit:     no
 * function: sub_0204D104
 * address:  0x0204D104
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_020A1394  0x020A1394  data
 *   MI_CpuFill8    0x02082BCC  arm
 *
 * Destructor for the 0x7c-byte sub-object embedded at +0x68 of the
 * 0x0204Bxxx owner: dispatch on the kind tag in word 0 through row 5 of the
 * handler table, then wipe the whole record.  `blx` rather than `bl`
 * because the table entries may be Thumb.
 *
 * Previously parked at MATCH on the reading that the pool word 0x020A13D0
 * was a table symbol of its own, which had no witness anywhere.  It is row 5
 * of the one eight-by-three array based at 0x020A1394; see
 * src/matched/func_0204D324.c for the row map.  With the array declared as
 * the two-dimensional object it is, the ABS32 names 0x020A1394, which the
 * pool word at 0x0204D490 attests `literal` from well outside this range,
 * and the +0x3c comes from the row index in the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D104.c \
 *       --func sub_0204D104 --addr 0x0204D104 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Dispatchable {
    u32 kind;
};

extern void (*const gUnk_020A1394[][3])(struct Dispatchable *p);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void sub_0204D104(struct Dispatchable *p)
{
    gUnk_020A1394[5][p->kind](p);
    MI_CpuFill8(p, 0, 0x7c);
}
