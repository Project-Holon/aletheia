/*
 * function: func_021D90C0
 * address: 0x021D90C0
 * packet: pkt_ov131_021D90C0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B878 0x0204B878 arm
 */

extern void func_021DBCA4(void *, int);
extern void func_02041300(unsigned int,int,int,int,unsigned char,unsigned char,unsigned char);
extern void func_020409B4(unsigned int);
extern void func_0204B878(void *, int);
void func_021D90C0(unsigned char *a, unsigned char *p)
{
    unsigned char i;
    for(i=0;i<10;i++) func_021DBCA4(*(void **)(p+0x80+i*20),0);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    *(int *)p=0;
    func_0204B878(*(void **)(a+0x180),2);
}
