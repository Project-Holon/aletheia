/*
 * function: GFL_NET_GetMaxConnectNum
 * address:  0x0203D680
 * packet:   pkt_0203D680
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   func_02034714  0x02034714  arm
 *   sNetFileName  0x020A7CA0  data
 *   file_020A7CF8  0x020A7CF8  data
 *
 * Returns the net context's +0x60 byte, reporting through func_02034714 with
 * the source file at 0x020A7CA0 ("net.c") and line 0x593 (1427) when the byte
 * is past 8.  The guard is unsigned (`bls`), so the comparison is
 * `> 8` against an unsigned char.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetMaxConnectNum.c \
 *       --func GFL_NET_GetMaxConnectNum --addr 0x0203D680 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern const char sNetFileName[];
extern const char file_020A7CF8[];

u32 GFL_NET_GetMaxConnectNum(void)
{
    u8 *p = GFL_NET_GetSession();

    if (p[0x60] > 8)
        func_02034714(sNetFileName, 0x593, file_020A7CF8);
    return p[0x60];
}
