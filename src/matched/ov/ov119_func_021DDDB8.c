/*
 * function: func_021DDDB8
 * address: 0x021DDDB8
 * packet: pkt_ov119_021DDDB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021DD080 0x021DD080 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDBF0 0x021DDBF0 thumb ov119
 */

extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
extern void func_021DD080(unsigned,int,void *);
extern void func_021D8E84(void *,int);
extern void func_021DDBF0(void *);

void func_021DDDB8(unsigned char *p)
{
    unsigned char v=14;
    if(func_0203D3A8(func_020399A8(),0xc00,1,&v)) {
        func_021DD080(func_020399A8(),29,p);
        func_021D8E84(p,(int)func_021DDBF0);
    }
}
