/*
 * function: func_021DBA38
 * address: 0x021DBA38
 * packet: pkt_ov119_021DBA38
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D94A0 0x021D94A0 thumb ov119
 *   func_021D8E80 0x021D8E80 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBAF8 0x021DBAF8 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
extern int func_021D8A24(void *);
extern void func_021D94A0(void *,int);
extern void func_021D8E80(void *);
extern void func_021D8E84(void *,int);
extern void func_021DBAF8(void *);
extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
void func_021DBA38(void *p)
{
    if (func_021D8A24(p)==0) {
        func_021D94A0(p,1);
        func_021D8E80(p);
        func_021D8E84(p,(int)func_021DBAF8);
        return;
    }
    if (func_0203D3A8(func_020399A8(),0xc06,0,0)!=0)
        func_021D8E84(p,(int)func_021DBAF8);
}
