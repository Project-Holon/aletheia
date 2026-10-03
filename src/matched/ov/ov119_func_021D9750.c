/*
 * function: func_021D9750
 * address: 0x021D9750
 * packet: pkt_ov119_021D9750
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
 *   func_021D9670 0x021D9670 thumb ov119
 */
extern void func_02045CAC(int, int, int);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *, int);
extern void func_021D9670(char *p);
void func_021D9750(char *p)
{
    func_02045CAC(*(int *)(p + 0x720), 6, *(int *)(p + 0x738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, (int)func_021D9670);
}
