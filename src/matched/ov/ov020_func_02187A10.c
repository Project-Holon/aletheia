/*
 * function: func_02187A10
 * address: 0x02187A10
 * packet: pkt_ov020_02187A10
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02187D20 0x02187D20 thumb ov020
 *   func_02187A38 0x02187A38 thumb ov020
 *   func_02187B38 0x02187B38 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02187D20(char *);
extern void func_02187A38(const char *, int);
extern void func_02187B38(char *, int);
void func_02187A10(char *p, int st)
{
    switch (func_02187D20(p)) {
    case 0: func_02187A38(p, st); break;
    case 1: func_02187B38(p, st); break;
    }
}
