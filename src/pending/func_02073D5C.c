/*
 * function: func_02073D5C
 * address:  0x2073D5C
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x0214E9B4 is named by one pool word, its own (literal class); 0x0214E9FC likewise
 * symbols:
 *   g_0214E9B4       0x214E9B4  data
 *   g_0214E9FC       0x214E9FC  data
 *
 * Both addresses are bss, so no label will ever exist for them and no branch
 *  * can witness them; the literal class is the only door and it has one witness
 *  * each, inside this function's own pool. Byte for byte correct otherwise.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int g_0214E9B4;
extern int g_0214E9FC;

void func_02073D5C(void)
{
    g_0214E9B4 = 0;
    g_0214E9FC = 0;
}
