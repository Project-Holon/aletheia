/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * Blocked at MATCH on `literal`: the two table words 0x0209FE94 and 0x0209FE98
 * each appear in exactly one literal pool image-wide, this function's own at
 * 0x02029EAC/0x02029EB0.  Nothing else in the image reads either table, so no
 * cut helps and the file is capped regardless of the C.  Both sites close the
 * day another reader of either table turns up (or a matched entry reproduces
 * the table's own bytes, which data cannot do here).
 *
 * function: func_02029E74
 * address:  0x02029E74
 * packet:   pkt_02029E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   g_0209FE94     0x0209FE94  data
 *   g_0209FE98     0x0209FE98  data
 *
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern s32 func_0201296C(void *a0);
extern s32 func_020142E8(s32 a, s32 b);
extern u8  g_0209FE94[];
extern u8  g_0209FE98[];

s32 func_02029E74(void *a0, u32 a1)
{
    s32 r = func_0201296C(a0);
    u32 i;
    u32 j;

    for (i = 0; i < 8; i++) {
        j = i * 8;
        if (a1 == *(u16 *)(g_0209FE94 + j + 2)) {
            if (func_020142E8(r, *(u16 *)(g_0209FE94 + j)) == 1)
                return *(u32 *)(g_0209FE98 + j);
        }
    }
    return -1;
}
