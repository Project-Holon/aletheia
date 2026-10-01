/*
 * function: func_021FED50
 * address: 0x021FED50
 * packet: pkt_ov186_021FED50
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FEEF4 0x021FEEF4 thumb ov186
 *   d_02200D78 0x02200D78 data a1
 *   d_02200B74 0x02200B74 data a4
 */
extern const char d_02200D78[];
extern const char d_02200B74[];
extern void *func_02030734(unsigned, unsigned, unsigned, const char *, unsigned);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_021FBE54(char *, unsigned, unsigned);
extern void func_021FEEF4(char *, int, char *, const char *, unsigned);
char *func_021FED50(int a, int unused, char *resources, unsigned heap)
{
    char *p = func_02030734(heap, 0x390, 0, d_02200D78, 0x132);
    int i;
    func_02082BCC(p, 0, 0x390);
    func_021FBE54(resources, 4, heap);
    func_021FBE54(resources, 5, heap);
    for (i = 0; i < 12; i++)
        func_021FEEF4(p + i * 0x4C, a, resources, d_02200B74 + i * 24, heap);
    return p;
}
