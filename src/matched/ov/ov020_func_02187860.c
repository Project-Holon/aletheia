/*
 * function: func_02187860
 * address: 0x02187860
 * packet: pkt_ov020_02187860
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   func_02187D20 0x02187D20 thumb ov020
 *   func_02187884 0x02187884 thumb ov020
 *   func_021878C0 0x021878C0 thumb ov020
 */
typedef unsigned int u32;
extern u32 func_02187D20(char *p);
extern void func_02187884(char *p);
extern void func_021878C0(char *p);
void func_02187860(char *p)
{
    switch (func_02187D20(p)) {
    case 0: func_02187884(p); break;
    case 1: func_021878C0(p); break;
    }
}
