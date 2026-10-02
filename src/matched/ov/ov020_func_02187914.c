/*
 * function: func_02187914
 * address: 0x02187914
 * packet: pkt_ov020_02187914
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   func_02187D20 0x02187D20 thumb ov020
 *   func_02187938 0x02187938 thumb ov020
 *   func_0218793C 0x0218793C thumb ov020
 */
typedef unsigned int u32;
extern u32 func_02187D20(char *p);
extern void func_02187938(char *p);
extern void func_0218793C(char *p);
void func_02187914(char *p)
{
    switch (func_02187D20(p)) {
    case 0: func_02187938(p); break;
    case 1: func_0218793C(p); break;
    }
}
