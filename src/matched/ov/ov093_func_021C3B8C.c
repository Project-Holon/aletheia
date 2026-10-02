/*
 * function: func_021C3B8C
 * address: 0x021C3B8C
 * packet: pkt_ov093_021C3B8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021EF884 0x021EF884 thumb ov093
 *   func_021EF894 0x021EF894 thumb ov093
 */
typedef unsigned int u32;
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern int func_021EF884(void);
extern int func_021EF894(void);
BOOL func_021C3B8C(void *p, u32 a, u32 b)
{
    if (a >= 5) return FALSE;
    if (a == func_021EF884() && (b != 255 || func_021EF894() == 255)) {
        return FALSE;
    }
    return TRUE;
}
