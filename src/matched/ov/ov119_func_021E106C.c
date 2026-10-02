/*
 * function: func_021E106C
 * address: 0x021E106C
 * packet: pkt_ov119_021E106C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_020452E8 0x020452E8 arm
 */
extern void func_0202F038(void *);
extern void func_020452E8(void *);
void func_021E106C(char *p)
{
    if (*(void **)(p + 0x5F0)) {
        func_0202F038(*(void **)(p + 0x5F0));
        *(void **)(p + 0x5F0) = 0;
    }
    if (*(void **)(p + 0x71C)) {
        func_020452E8(*(void **)(p + 0x71C));
        *(void **)(p + 0x71C) = 0;
    }
}
