/*
 * function: func_021E12F8
 * address: 0x021E12F8
 * packet: pkt_ov119_021E12F8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027858 0x02027858 thumb
 */
extern void func_02027858(void *);
void func_021E12F8(char *p)
{
    if (*(void **)(p + 0x64C)) {
        *(volatile unsigned short *)0x04000050 = 0;
        func_02027858(*(void **)(p + 0x64C));
        *(void **)(p + 0x64C) = 0;
    }
}
