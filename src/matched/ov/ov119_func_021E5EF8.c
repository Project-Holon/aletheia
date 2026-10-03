/*
 * function: func_021E5EF8
 * address: 0x021E5EF8
 * packet: pkt_ov119_021E5EF8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 */
extern void func_0204B3B4(int);
extern void func_021B6284(unsigned int *p);

void func_021E5EF8(void *p)
{
    if (*(int *)((char *)p + 0x10)) {
        func_0204B3B4(*(int *)((char *)p + 0x10));
        func_021B6284(p);
        *(int *)((char *)p + 0x10) = 0;
    }
}
