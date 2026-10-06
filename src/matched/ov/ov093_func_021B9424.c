/*
 * function: func_021B9424
 * address: 0x021B9424
 * packet: pkt_ov093_021B9424
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D53B8 0x021D53B8 thumb ov093
 *   func_021B9B40 0x021B9B40 thumb ov093
 */
extern void func_021D53B8(void *);
typedef unsigned char  u8;
extern void func_021B9B40(u8 *p);
void func_021B9424(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            func_021D53B8(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
    for (i = 0; i < 4; i++) func_021B9B40((u8 *)(p + 4 + i * 28));
}
