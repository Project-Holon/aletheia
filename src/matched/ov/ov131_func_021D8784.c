/*
 * function: func_021D8784
 * address: 0x021D8784
 * packet: pkt_ov131_021D8784
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: arm9 witnesses func_0202F688 / func_0202F6D8 filed (unlabelled Thumb
 *   leaves); 92-byte listing extent includes 2 bytes of alignment padding.
 * symbols:
 *   func_0202F688 0x0202F688 thumb
 *   func_0202F6D8 0x0202F6D8 thumb
 *   func_02045EC0 0x02045EC0 arm
 */

extern unsigned int func_0202F688(unsigned int);
extern unsigned int func_0202F6D8(unsigned int);
extern void *func_02045EC0(void *, unsigned int);
void func_021D8784(void *a, unsigned char *p, unsigned int n)
{
    unsigned int bank = func_0202F688(n);
    unsigned int index = func_0202F6D8(n);
    switch (bank) {
    case 89: func_02045EC0(*(void **)(p + 0x3c), index); break;
    case 92: func_02045EC0(*(void **)(p + 0x40), index); break;
    case 90: func_02045EC0(*(void **)(p + 0x44), index); break;
    case 91: func_02045EC0(*(void **)(p + 0x48), index); break;
    default: func_02045EC0(*(void **)(p + 0x3c), 0); break;
    }
}
