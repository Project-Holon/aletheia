/*
 * function: func_021E1030
 * address: 0x021E1030
 * packet: pkt_ov119_021E1030
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
extern void func_0202F038(void *);
extern void *func_0202EE8C(void *, void *, unsigned char, unsigned char, unsigned short);
void func_021E1030(char *p)
{
    if (*(void **)(p + 0x5F0)) {
        func_0202F038(*(void **)(p + 0x5F0));
        *(void **)(p + 0x5F0) = 0;
    }
    *(void **)(p + 0x5F0) = func_0202EE8C(*(void **)(p + 0x744), *(void **)(p + 0x71C), 0xF, 0x10, *(unsigned short *)(p + 0x5F4));
}
