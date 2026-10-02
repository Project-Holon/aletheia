/*
 * function: func_021E2680
 * address: 0x021E2680
 * packet: pkt_ov119_021E2680
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_021E6DEC 0x021E6DEC thumb
 */
extern void func_020452E8(void *);
extern void func_021E6DEC(char *);
void func_021E2680(char *p)
{
    int i;
    for (i=0;i<4;i++) {
        char *q = p+i*4;
        if (*(void **)(q+0x1038)) {
            func_020452E8(*(void **)(q+0x1038));
            *(void **)(q+0x1038)=0;
        }
    }
    func_021E6DEC(p);
}
