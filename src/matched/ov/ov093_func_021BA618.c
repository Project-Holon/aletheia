/*
 * function: func_021BA618
 * address: 0x021BA618
 * packet: pkt_ov093_021BA618
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CDDCC 0x021CDDCC thumb ov093
 */
typedef unsigned char u8;
extern int func_021CDDCC(void *);
int func_021BA618(char *p)
{
    int v;
    if (*(u8 *)(*(char **)p + 0x23)) {
        v = func_021CDDCC(*(void **)(p + 0x10 + *(u8 *)(p + 0x46c) * 4));
        if (v) *(int *)(p + 0x444) = 2;
        return v;
    }
    return 0;
}
