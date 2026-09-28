/*
 * function: func_02019B44
 * address:  0x02019B44
 * packet:   pkt_02019388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The unlabelled leaf whose pool word is the second image-wide reference to
 * the table at 0x0209E324; traced via layout/function_starts.txt. Its pool
 * word witnesses the table for unit_02019B04.c and vice versa.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019B44.c \
 *       --func func_02019B44 --addr 0x02019B44
 *
 * symbols:
 *   func_02019B04_Table  0x0209E324  data
 */

typedef unsigned int u32;
typedef signed char  s8;

extern const s8 func_02019B04_Table[][5];

s8 func_02019B44(u32 a, u32 n)
{
    return func_02019B04_Table[a][n - 1];
}
