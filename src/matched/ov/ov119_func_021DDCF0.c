/*
 * function: func_021DDCF0
 * address: 0x021DDCF0
 * packet: pkt_ov119_021DDCF0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D94D4 0x021D94D4 thumb ov119
 *   func_021D95D0 0x021D95D0 thumb ov119
 *   func_021D95F0 0x021D95F0 thumb ov119
 *   func_021D9610 0x021D9610 thumb ov119
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_020399A8 0x020399A8 arm
 *   func_021DD080 0x021DD080 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDBF0 0x021DDBF0 thumb ov119
 */
typedef unsigned short u16;
extern int func_021D94D4(void *);
extern int func_021D95D0(void *);
extern int func_021D95F0(void *);
extern int func_021D9610(void *);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void *func_020399A8(void);
extern void func_021DD080(void *,int,void *);
extern void func_021D8E84(void *,int);
extern void func_021DDBF0(void *);
void func_021DDCF0(unsigned char *p)
{
    unsigned char b=13;if(func_021D94D4(p))b=5;else if(func_021D95D0(p))b=7;else if(func_021D95F0(p))b=8;else if(func_021D9610(p))b=6;if(func_0203D3A8(func_020399A8(),0xc00,1,&b)){func_021DD080(func_020399A8(),29,p);func_021D8E84(p,(int)func_021DDBF0);}
}
