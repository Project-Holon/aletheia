/*
 * function: func_0217BA48
 * address: 0x0217BA48
 * packet: pkt_ov019_0217BA48
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 */
extern void *func_02012934(void *);
extern int func_0201A090(void *, void *, unsigned int *);
int func_0217BA48(char *p, unsigned int *mask)
{
    void *party;
    *mask = 0;
    party = func_02012934(*(void **)(*(char **)p + 8));
    return func_0201A090(*(void **)(p + 0x352c), party, mask);
}
