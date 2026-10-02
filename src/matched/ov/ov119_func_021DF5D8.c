/*
 * function: func_021DF5D8
 * address: 0x021DF5D8
 * packet: pkt_ov119_021DF5D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF59C 0x021DF59C thumb ov119
 *   func_021E26AC 0x021E26AC thumb ov119
 */
extern void func_02045CAC(void *, unsigned, void *);
extern void func_021E1024(void *);
extern void func_021B6548(void *, int, int);
extern void func_021D8E84(void *, int);
extern void func_021DF59C(void *);
extern void func_021E26AC(void *);
void func_021DF5D8(char *p)
{
    func_02045CAC(*(void **)(p + 0x720), 0x87, *(void **)(p + 0x738));
    func_021E1024(p);
    func_021B6548(*(void **)(p + 0x9C0), 1, 0);
    func_021D8E84(p, (int)func_021DF59C);
    func_021E26AC(p);
}
