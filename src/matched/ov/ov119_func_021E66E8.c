/*
 * function: func_021E66E8
 * address: 0x021E66E8
 * packet: pkt_ov119_021E66E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
extern void func_0204B3B4(int);

void func_021E66E8(void *p)
{
    if (*(int *)((char *)p + 0xf20)) {
        func_0204B3B4(*(int *)((char *)p + 0xf20));
        *(int *)((char *)p + 0xf20) = 0;
    }
}
