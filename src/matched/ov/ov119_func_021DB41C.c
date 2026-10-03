/*
 * function: func_021DB41C
 * address: 0x021DB41C
 * packet: pkt_ov119_021DB41C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E5C64 0x021E5C64 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E0EF4 0x021E0EF4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB304 0x021DB304 thumb ov119
 */
extern void func_021E5C64(char *p);
extern void func_02045CAC(int,int,int);
extern void func_021E0EF4(char *p, int flag, int x, int y, int w, int h);
extern void func_021D8E84(void *,int);
extern void func_021DB304(char *p);
void func_021DB41C(char *p)
{
    func_021E5C64(p);
    func_02045CAC(*(int *)(p+0x720),0x33,*(int *)(p+0x738));
    func_021E0EF4(p,1,1,1,0x1d,4);
    func_021D8E84(p,(int)func_021DB304);
}
