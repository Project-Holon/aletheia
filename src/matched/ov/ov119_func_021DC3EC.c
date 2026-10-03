/*
 * function: func_021DC3EC
 * address: 0x021DC3EC
 * packet: pkt_ov119_021DC3EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E55BC 0x021E55BC thumb ov119
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 */
extern void func_021E55BC(char *p);
extern void *func_02014B08(int, unsigned short);
extern void func_02016020(void *, unsigned int);
extern void func_02015BF0(void *);
void func_021DC3EC(char *p)
{
    func_021E55BC(p);
    *(void **)(p + 0x840) = func_02014B08(4, (*(unsigned short *)(p + 0x5F4) & 0x7FFF) | 0x8000);
    func_02016020(*(void **)(p + 0x840), 3 << 16);
    func_02015BF0(*(void **)(p + 0x840));
}
