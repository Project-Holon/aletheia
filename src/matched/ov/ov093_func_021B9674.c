/*
 * function: func_021B9674
 * address: 0x021B9674
 * packet: pkt_ov093_021B9674
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_Delete 0x021D53B8 thumb ov093
 */
extern void BTL_POKEPARAM_Delete(void *);
void func_021B9674(char *p)
{
    unsigned int i;
    for (i = 0; i < 24; i++) {
        if (*(void **)(p + i * 4 + 0x84) != 0) {
            BTL_POKEPARAM_Delete(*(void **)(p + i * 4 + 0x84));
            *(void **)(p + i * 4 + 0x84) = 0;
        }
    }
}
