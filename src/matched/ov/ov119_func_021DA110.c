/*
 * function: func_021DA110
 * address: 0x021DA110
 * packet: pkt_ov119_021DA110
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA064 0x021DA064 thumb ov119
 */

extern void func_02045CAC(int,int,int);
extern void func_021E0FF4(void *,int,int);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021D8E84(void *,int);
extern void func_021DA064(char *p);
void func_021DA110(char *p)
{
    func_02045CAC(*(int *)(p+0x720), 0x8E, *(int *)(p+0x738));
    func_021E0FF4(p,1,0);
    *(short *)(p+0x1080) = -1;
    func_021E4E64(*(int *)(p+0x828), p, 0);
    func_021D8E84(p, (int)func_021DA064);
}
