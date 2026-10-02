/*
 * function: func_021E2054
 * address: 0x021E2054
 * packet: pkt_ov119_021E2054
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_020452E8 0x020452E8 arm
 */
extern void func_021E36D8(void *, int);
extern void func_020452E8(void *);
void func_021E2054(char *p, int a, int b)
{
    func_021E36D8(p, b);
    if (*(void **)(p + 0x6B4)) {
        func_020452E8(*(void **)(p + 0x6B4));
    }
}
