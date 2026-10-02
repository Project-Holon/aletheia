/*
 * function: func_021BB160
 * address: 0x021BB160
 * packet: pkt_ov206_021BB160
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB2C4 0x021BB2C4 thumb
 *   func_021BB214 0x021BB214 thumb
 */
extern void func_021BB2C4(char *, int);
extern void func_021BB214(char *, int);
void func_021BB160(char *p, int i)
{
    void **slot = (void **)(p + 0xac) + i;
    if (*slot != 0) {
        func_021BB2C4(p, i);
        func_021BB214(p, i);
        *slot = 0;
    }
}
