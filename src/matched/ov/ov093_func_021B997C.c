/*
 * function: func_021B997C
 * address: 0x021B997C
 * packet: pkt_ov093_021B997C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9114 0x021B9114 thumb ov093
 *   func_02007B50 0x02007B50 thumb
 *   func_02007C70 0x02007C70 thumb
 */
typedef unsigned char u8;
extern u8 func_021B9114(u8 **);
extern int func_02007B50(void *);
extern int func_02007C70(void *);
int func_021B997C(u8 *p, unsigned int i)
{
    if (func_021B9114((u8 **)p) == 0) {
        unsigned int q = (unsigned int)p + 0x3e0;
        if (*(void **)(q + i * 4) != 0 && func_02007B50(*(void **)(q + i * 4)) != 0)
            return func_02007C70(*(void **)(q + i * 4));
        return 0;
    }
    return *(u8 *)((unsigned int)*(u8 **)p + i + 0x44);
}
