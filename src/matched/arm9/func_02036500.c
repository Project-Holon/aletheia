/*
 * function: GFL_NET_RING_BUFF_ReadByte
 * address:  0x02036500
 * packet:   pkt_02036428
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * second pool word, file_020A79C0, whose only literal pool in the whole image
 * is this function's own, at 0x0203653C and therefore inside the compared
 * range.  The `string` class cannot stand in for it either: 0x020A79C0 holds
 * the one-character string "0" (the listing shows `.word 0x00000030` there,
 * preceded by the terminator of "pDataArea"), and attest_string() requires at
 * least four printable characters before the NUL, so the address is refused by
 * rule 2.  It closes the day the same string address is referenced from a pool
 * outside this range, or the rule's four-character floor is revisited for
 * one-character strings.  The three other sites resolve: GFL_NET_RING_BUFF_Read and
 * func_02034714 as `label`, file_020A79A4 as `literal`.
 *
 * symbols:
 *   GFL_NET_RING_BUFF_Read    0x020364D4  arm
 *   func_02034714    0x02034714  arm
 *   file_020A79A4    0x020A79A4  data
 *   file_020A79C0    0x020A79C0  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int GFL_NET_RING_BUFF_Read(char *p, unsigned char *dst, int len, int max);
extern void func_02034714(const char *file, u32 line, const char *fmt);
extern const char file_020A79A4[];
extern const char file_020A79C0[];

u32 GFL_NET_RING_BUFF_ReadByte(u32 a)
{
    u8 b;

    if (GFL_NET_RING_BUFF_Read((char *)a, &b, 1, 1) == 1)
        return b;
    func_02034714(file_020A79A4, 0x6C, file_020A79C0);
    return 0;
}
