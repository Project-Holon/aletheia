/*
 * function: func_021DDB64
 * address: 0x021DDB64
 * packet: pkt_ov119_021DDB64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021DD080 0x021DD080 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDB10 0x021DDB10 thumb ov119
 */

extern unsigned func_020399A8(void);
extern int func_021E12AC(void *);
extern void func_021DD080(unsigned,int,void *);
extern void func_021D8E84(void *,int);
extern void func_021DDB10(unsigned char *p);

void func_021DDB64(unsigned char *p)
{
    func_020399A8();
    if(func_021E12AC(p)) {
        func_021DD080(func_020399A8(),25,p);
        func_021D8E84(p,(int)func_021DDB10);
    }
}
