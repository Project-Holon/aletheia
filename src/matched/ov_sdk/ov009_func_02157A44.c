/*
 * function: func_02157A44
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
 *   g_021A826C                       0x021a826c data
 *   g_021A1CC0                       0x021a1cc0 data
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

extern struct CPSGlobal g_021A826C;
extern u8 g_021A1CC0[];
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);

void func_02157A44(u8 *srcAddr, u8 *dstAddr, u8 *buf1, u32 size1, u8 *buf2, u32 size2)
{
    u32 size;
    u32 new_putpnt;
    u16 blocklen;

    if (g_021A826C.buf == 0 || g_021A826C.bufsize == 0)
        return;
    size = size1 + size2;
    if (size < 8 || size > 0x5e4)
        return;
    if (buf1[0] != g_021A1CC0[0] || buf1[1] != g_021A1CC0[1] || buf1[2] != g_021A1CC0[2] || buf1[6] != 8)
        return;
    if (buf1[7] != 0 && buf1[7] != 6)
        return;
    blocklen = (u16)((size + 9) & ~1);
    new_putpnt = g_021A826C.putpnt + blocklen;
    if (g_021A826C.putpnt < g_021A826C.getpnt && g_021A826C.getpnt <= new_putpnt)
        return;
    if (new_putpnt == g_021A826C.bufsize) {
        new_putpnt = 0;
        if (g_021A826C.getpnt == 0)
            return;
    } else if (new_putpnt > g_021A826C.bufsize) {
        new_putpnt = blocklen;
        if (g_021A826C.getpnt <= blocklen)
            return;
    }
    if (g_021A826C.putpnt + blocklen > g_021A826C.bufsize) {
        if (g_021A826C.bufsize - g_021A826C.putpnt >= 2)
            *(u16 *)(g_021A826C.buf + g_021A826C.putpnt) = 0;
        g_021A826C.putpnt = 0;
    }
    *(u16 *)(g_021A826C.buf + g_021A826C.putpnt) = blocklen;
    MI_CpuCopy(dstAddr, g_021A826C.buf + g_021A826C.putpnt + 2, 6);
    MI_CpuCopy(srcAddr, g_021A826C.buf + g_021A826C.putpnt + 8, 6);
    MI_CpuCopy(buf1 + 6, g_021A826C.buf + g_021A826C.putpnt + 14, size1 - 6);
    if (buf2 != 0 && size2 != 0)
        MI_CpuCopy(buf2, g_021A826C.buf + g_021A826C.putpnt + 8 + size1, size2);
    g_021A826C.putpnt = new_putpnt;
}
