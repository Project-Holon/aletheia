/*
 * function: func_021B83A0
 * address: 0x021B83A0
 * packet: pkt_ov070_021B83A0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT*: two bytes of zero alignment padding follow at 021B83B6.
 * The original explicitly narrows r1 before 0202E448; its extern uses u16.
 * symbols:
 *   func_0202E448 0x0202E448 thumb
 *   func_02012BF8 0x02012BF8 thumb
 */
typedef unsigned short u16;
extern int func_0202E448(u16 value);
extern int func_02012BF8(int p, int value);
int func_021B83A0(char *p, int value)
{
    return func_02012BF8(*(int *)p, func_0202E448(value));
}
