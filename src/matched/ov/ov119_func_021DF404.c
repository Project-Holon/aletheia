/*
 * function: func_021DF404
 * address: 0x021DF404
 * packet: pkt_ov119_021DF404
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF37C 0x021DF37C thumb ov119
 */
extern void func_02045CAC(void *, unsigned, void *);
extern void func_021E1024(void *);
extern void func_021E1030(void *);
extern void func_021D8E84(void *, int);
extern void func_021DF37C(void *);
void func_021DF404(char *p)
{
    func_02045CAC(*(void **)(p + 0x720), 0x88, *(void **)(p + 0x738));
    func_021E1024(p);
    func_021E1030(p);
    *(unsigned char *)(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DF37C);
}
