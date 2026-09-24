/*
 * function: func_021BF050
 * address:  0x021BF050
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 *
 * symbols:
 *   func_02156B8C  0x02156B8C  thumb  ov172
 * True unless the arm9 predicate answers -1.
 *
 * NOT EXACT.  MATCH: the 18 bytes and the single relocation are right, but the
 * target address 0x02156B8C is not a `func_` label in any overlay listing or in
 * arm9's, so no class attests it: `matched` has nothing, `label` wants a traced
 * function start and `sole-ref/code` wants the same.  It turns EXACT by itself
 * the moment 0x02156B8C is matched or labelled.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BF050.c --func func_021BF050 --addr 0x021BF050 \n    --region ov099 --thumb --cc dsi/1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_02156B8C(void);

BOOL func_021BF050(void)
{
    if (func_02156B8C() != -1) {
        return 1;
    }

    return 0;
}
