/*
 * function: put_in_buffer
 * address:  0x02157A44
 * packet:   pkt_ov009_02157A44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      put_in_buffer (libcps.TWL.HYB.a network.o)
 * symbols:
 *   MI_CpuCopy                       0x02082ea4 arm
 *   gCpsNetVars                       0x021a826c data
 *   gCpsUdpHeaderTemplate                       0x021a1cc0 data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct CPSGlobal {
    u8 pad0[0x20];
    u8 *buf;
    u8 pad1[0x5c - 0x24];
    volatile u32 bufsize;
    volatile u32 putpnt;
    volatile u32 getpnt;
};

extern struct CPSGlobal gCpsNetVars;
extern u8 gCpsUdpHeaderTemplate[];
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);

void put_in_buffer(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2)
{
    u32 size;
    u32 new_putpnt;
    u16 blocklen;

    if (gCpsNetVars.buf == 0 || gCpsNetVars.bufsize == 0)
        return;
    size = size1 + size2;
    if (size < 8 || size > 0x5e4)
        return;
    if (buf1[0] != gCpsUdpHeaderTemplate[0] || buf1[1] != gCpsUdpHeaderTemplate[1] || buf1[2] != gCpsUdpHeaderTemplate[2] || buf1[6] != 8)
        return;
    if (buf1[7] != 0 && buf1[7] != 6)
        return;
    blocklen = (u16)((size + 9) & ~1);
    new_putpnt = gCpsNetVars.putpnt + blocklen;
    if (gCpsNetVars.putpnt < gCpsNetVars.getpnt && gCpsNetVars.getpnt <= new_putpnt)
        return;
    if (new_putpnt == gCpsNetVars.bufsize) {
        new_putpnt = 0;
        if (gCpsNetVars.getpnt == 0)
            return;
    } else if (new_putpnt > gCpsNetVars.bufsize) {
        new_putpnt = blocklen;
        if (gCpsNetVars.getpnt <= blocklen)
            return;
    }
    if (gCpsNetVars.putpnt + blocklen > gCpsNetVars.bufsize) {
        if (gCpsNetVars.bufsize - gCpsNetVars.putpnt >= 2)
            *(u16 *)(gCpsNetVars.buf + gCpsNetVars.putpnt) = 0;
        gCpsNetVars.putpnt = 0;
    }
    *(u16 *)(gCpsNetVars.buf + gCpsNetVars.putpnt) = blocklen;
    MI_CpuCopy(dstAddr, gCpsNetVars.buf + gCpsNetVars.putpnt + 2, 6);
    MI_CpuCopy(srcAddr, gCpsNetVars.buf + gCpsNetVars.putpnt + 8, 6);
    MI_CpuCopy(buf1 + 6, gCpsNetVars.buf + gCpsNetVars.putpnt + 14, size1 - 6);
    if (buf2 != 0 && size2 != 0)
        MI_CpuCopy(buf2, gCpsNetVars.buf + gCpsNetVars.putpnt + 8 + size1, size2);
    gCpsNetVars.putpnt = new_putpnt;
}
