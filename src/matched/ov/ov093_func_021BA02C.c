/*
 * function: func_021BA02C
 * address: 0x021BA02C
 * packet: pkt_ov093_021BA02C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 */
extern void *func_021B86B8(void ***);
typedef unsigned char  u8;
extern int func_021B9F70(u8 *p, int i);
typedef unsigned int u32;
void *func_021BA02C(char *p, int i, int mode)
{
    if ((int)func_021B86B8((void ***)p) == 2 && func_021B9F70((u8 *)p, i)) {
        if (mode == 1) return (void *)(((u32)p + 0x40) + (u32)i * 0x28);
        return (void *)(((u32)p + 0x38) + (u32)i * 0x28);
    }
    return 0;
}
