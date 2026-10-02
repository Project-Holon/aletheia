/*
 * function: func_021E0E4C
 * address: 0x021E0E4C
 * packet: pkt_ov119_021E0E4C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 */
extern void func_0204B3B4(void *);
extern void func_021B6284(void *);
void func_021E0E4C(char *p)
{
    if (*(void **)(p + 0x10)) {
        func_0204B3B4(*(void **)(p + 0x10));
        *(int *)(p + 0x10) = 0;
        func_021B6284(p);
    }
}
