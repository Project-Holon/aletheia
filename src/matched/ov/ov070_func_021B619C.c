/*
 * function: ITEMMENU_GetSellTotal
 * address: 0x021B619C
 * packet: pkt_ov070_021B619C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment follow the 26-byte function.
 * lever: enum quotient preserves its r1 web and the copy to return r0.
 * The signed quotient is multiplied with unsigned modular arithmetic.
 * symbols:
 *   func_02020FE4 0x02020FE4 thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
int ITEMMENU_GetSellTotal(int a, int b, unsigned int id)
{
    typedef enum { HALF_ZERO } Half;
    Half half;
    half = (Half)((int)func_02020FE4((void *)((u16)a), 0, id) / 2);
    return (int)((unsigned int)half * (unsigned int)b);
}
