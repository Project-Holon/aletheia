/*
 * function: func_021B99C0
 * address: 0x021B99C0
 * packet: pkt_ov093_021B99C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B6994 0x021B6994 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 * evidence: entry r1 is forwarded unchanged to the two-argument 021B6994.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S;
extern int func_021B6994(struct S **, u32);
extern u32 func_021B8588(void *);
int func_021B99C0(struct S **p, u32 b)
{
    int result = func_021B6994(p, b);
    if (func_021B8588(p) == 3) result = (u8)(result + 2);
    return result;
}
