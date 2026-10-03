/*
 * function: func_021864DC
 * address: 0x021864DC
 * packet: pkt_ov020_021864DC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 66 bytes of code followed by two zero alignment bytes.
 * Lever: the inline helper holds the loaded byte in a full-width unsigned
 * local before clearing its bits; the constant argument stays positive
 * and is hoisted to a spill instead of folding to the byte complement.
 * symbols:
 *   func_02161ECC 0x02161ECC thumb ov010
 *   func_02186BB8 0x02186BB8 thumb ov020
 */
typedef unsigned char u8;
extern int func_02161ECC(void *p);
extern int func_02186BB8(u8 *p, int a);

static inline void clear_flag(u8 *p, unsigned int mask)
{
    unsigned int value = *p;
    value &= ~mask;
    *p = value;
}

void func_021864DC(u8 *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC(p + 8 + i * 0x18) &&
            (*(u8 *)((unsigned int)p + i * 0x18 + 0xb) & 2)) {
            func_02186BB8(p + 8 + i * 0x18, 3);
            clear_flag((u8 *)((unsigned int)p + i * 0x18 + 0xb), 2);
        }
    }
}
