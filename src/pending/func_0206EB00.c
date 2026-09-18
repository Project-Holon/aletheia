/*
 * function: func_0206EB00
 * address:  0x0206EB00
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 124 compiled against 120: the halfword loop is right in shape but the clear call's argument order (value in r0, destination in r1) and the register the destination row counter lands in do not reproduce; parked for the next pass
 *
 * symbols:
 *   g_020A8224       0x020A8224  data
 *   func_02082A48    0x02082A48  arm
 *
 * Builds a halfword index at src + 0x1A from the source list: the byte at
 * src + 0x17 is both the count (doubled for the clear) and the clear length,
 * and each of the count's entry indices (halfwords at src + 0x14) selects a
 * word of src whose top byte becomes the high half of one output halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206EB00.c \
 *       --func func_0206EB00 --addr 0x0206EB00 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  g_020A8224;
extern void func_02082A48(u32 val, void *dst, u32 n);

void func_0206EB00(char *dst, char *src, char *tbl)
{
    int i;

    *(char **)(dst + 8) = src;
    *(u32 *)(dst + 0xC) = g_020A8224;
    *(u8 *)(dst + 0x19) = *(u8 *)(tbl + 0x17);
    func_02082A48(0, dst + 0x1A, (u32)(*(u8 *)(tbl + 0x17) << 1));
    for (i = 0; i < *(u16 *)(src + 6); i++)
        *(u16 *)(dst + 0x1A + i * 2) =
            (u16)((*(u32 *)(src + *(u16 *)(src + 0x14 + i * 2)) >> 24) | 0x100);
}
