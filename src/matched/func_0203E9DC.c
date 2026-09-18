/*
 * function: func_0203E9DC
 * address:  0x0203E9DC
 * packet:   pkt_0203E484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F0      0x021469F0  data
 *   g_021469F4      0x021469F4  data
 *   s_020A7D34      0x020A7D34  data
 *   s_020A7D4C      0x020A7D4C  data
 *   s_020A7D68      0x020A7D68  data
 *   s_020A7D74      0x020A7D74  data
 *   s_020A7DA0      0x020A7DA0  data
 *   s_020A7E00      0x020A7E00  data
 */

typedef unsigned char u8;
extern int *g_021469F0;
extern int *g_021469F4;
extern char s_020A7D34[];
extern char s_020A7D4C[];
extern char s_020A7D68[];
extern char s_020A7D74[];
extern char s_020A7DA0[];
extern char s_020A7E00[];
extern void func_02034714(void *file, int line, void *msg);
int func_0203E9DC(unsigned int idx)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x105, s_020A7DA0);
    if (g_021469F4[idx] == 0)
        func_02034714(s_020A7D74, 0x106, s_020A7E00);
    return *(int *)(g_021469F4[idx] + 0xc);
}
