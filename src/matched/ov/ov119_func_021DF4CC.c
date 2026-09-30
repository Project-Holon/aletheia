/*
 * function: func_021DF4CC
 * address: 0x021DF4CC
 * packet: pkt_ov119_021DF4CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF490 0x021DF490 thumb ov119
 */
extern unsigned func_020399A8(void);
extern unsigned func_0203D1A4(unsigned);
extern int func_021E12AC(void *);
extern int func_021DD140(void *);
extern void func_02045CAC(int,int,int);
extern void func_021E1024(void *);
extern void func_021D8E84(void *,int);
extern void func_021DF490(void *);
void func_021DF4CC(char *p)
{
    func_0203D1A4(func_020399A8());
    if (func_021E12AC(p) && func_021DD140(p)) {
        func_02045CAC(*(int *)(p+0x720),0x89,*(int *)(p+0x738));
        func_021E1024(p);
        func_021D8E84(p,(int)func_021DF490);
    }
}
