/*
 * function: func_021B994C
 * address: 0x021B994C
 * packet: pkt_ov093_021B994C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8ED8 0x021B8ED8 thumb ov093
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 * evidence: original narrows second argument before 021B8ED8 call.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 func_021B8DE4(char *p, int i);
int func_021B994C(u8 *p, u32 i, void **out)
{
    void *v;
    u32 n = func_021B8DE4((char *)p, func_021B8ED8(p, i));
    v = *(void **)(p + n * 4 + 0x3e0);
    if (v != 0) {
        *out = v;
        return 1;
    }
    return 0;
}
