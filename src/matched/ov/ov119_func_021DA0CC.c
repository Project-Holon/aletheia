/*
 * function: func_021DA0CC
 * address: 0x021DA0CC
 * packet: pkt_ov119_021DA0CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA064 0x021DA064 thumb ov119
 */

extern void func_02045CAC(int,int,int);
extern void func_021E1024(void *);
extern void func_021E4E64(int,void *,int);
extern void func_021D8E84(void *,int);
extern void func_021DA064(void *);
void func_021DA0CC(char *p)
{
    func_02045CAC(*(int *)(p+0x720), 0x65, *(int *)(p+0x738));
    func_021E1024(p);
    *(short *)(p+0x1080) = -1;
    func_021E4E64(*(int *)(p+0x828), p, 0);
    func_021D8E84(p, (int)func_021DA064);
}
