/*
 * function: func_021F0C34
 * address: 0x021F0C34
 * packet: pkt_ov031_021F0C34
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F0C60 0x021F0C60 thumb ov031
 *   func_021F0CEC 0x021F0CEC thumb ov031
 */
typedef struct B B;
extern void func_021F0C60(B *, B *);
extern void func_021F0CEC(char *, B *);
void func_021F0C34(char *a, unsigned char *b)
{
    if (b[0x31] == 1)
        func_021F0C60((B *)b, (B *)(a + 0x30e0));
    else
        func_021F0CEC((char *)b, (B *)(a + 0x30e0));
}
