/*
 * function: func_021D81E0
 * address: 0x021D81E0
 * packet: pkt_ov120_021D81E0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7C48 0x021D7C48 thumb ov120
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_021D8118 0x021D8118 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int   u32;
extern void func_0201DD78(u32 r, u32 g, u32 b);
typedef unsigned char  u8;
extern int func_021D7C48(u8 *p, int n, int a, int b, int c, int d);
extern void *func_021D4F70(void **p, int i);
extern int func_021D8118(char *p, void *r, int n);
extern void func_02041B6C(u32 bit);
void func_021D81E0(char *p,void *q)
{
    int i;
    void *r;
    func_0201DD78(15,2,0);
    func_021D7C48((u8 *)p,30,0,0,20,5);
    for(i=0;i<3;i++) {
        r=func_021D4F70(q,i);
        if(r) func_021D8118(p,r,i+2);
    }
    func_02041B6C(5);
}
