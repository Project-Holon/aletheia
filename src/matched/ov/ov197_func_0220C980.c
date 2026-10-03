/*
 * function: func_0220C980
 * address: 0x0220C980
 * packet: pkt_ov197_0220C980
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: word-address arithmetic reuses the MMIO pool base, as in matched ov197 0220CAAC.
 * symbols:
 *   d_04001050 0x04001050 data a2
 *   func_0207D534 0x0207D534 arm
 *   sub_0203101C 0x0203101C arm
 *   func_0220AF40 0x0220AF40 thumb ov196
 *   func_0220D5C0 0x0220D5C0 thumb ov197
 *   func_0220D6DC 0x0220D6DC thumb ov197
 *   func_0220D798 0x0220D798 thumb ov197
 *   func_0220BB78 0x0220BB78 thumb ov197
 *   func_0220BA2C 0x0220BA2C thumb ov197
 *   func_0220B120 0x0220B120 thumb ov197
 *   func_0220B1B0 0x0220B1B0 thumb ov197
 *   func_0220B990 0x0220B990 thumb ov197
 *   func_0220BBE4 0x0220BBE4 thumb ov197
 *   func_0220BD24 0x0220BD24 thumb ov197
 *   func_0220C034 0x0220C034 thumb ov197
 *   func_0220C4EC 0x0220C4EC thumb ov197
 *   func_0220AFDC 0x0220AFDC thumb ov196
 *   func_0220D8C4 0x0220D8C4 thumb ov197
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_0202173C 0x0202173C thumb
 *   func_0220D7F0 0x0220D7F0 thumb ov197
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 d_04001050[];
extern void func_0207D534(u16 *,int);
extern void *sub_0203101C(unsigned,u16,unsigned,unsigned);
extern void *func_0220AF40(unsigned);
extern void func_0220D5C0(char *),func_0220D6DC(char *),func_0220D798(char *);
extern void func_0220BB78(char *),func_0220BA2C(char *),func_0220B120(char *);
extern void func_0220B1B0(char *,int);
extern unsigned func_0220B990(u8 *);
extern void func_0220BBE4(char *),func_0220BD24(char *,int),func_0220C034(char *),func_0220C4EC(char *,int);
extern void func_0220AFDC(char *,void *);
extern void func_0220D8C4(u8 *,unsigned,unsigned),func_0203D34C(unsigned,unsigned);
extern void func_020216D4(void *,unsigned,unsigned,unsigned);
extern void *func_021F86D4(void);
extern int func_0202173C(void *,u16,u16,short,u8,u8,u16,void *);
extern void func_0220D7F0(void *,int);
int func_0220C980(char *p)
{
    d_04001050[0]=0;
    func_0207D534((u16 *)((unsigned)d_04001050+0x1c),-16);
    *(void **)(p+4)=sub_0203101C(*(u16 *)(*(char **)p+0xc),*(u16 *)(*(char **)p+0xc),1,4);
    *(void **)(p+0x148)=func_0220AF40(*(u16 *)(*(char **)p+0xc));
    func_0220D5C0(p);
    func_0220D6DC(p);
    func_0220D798(p);
    if(*(int *)(*(char **)p+8)==2) func_0220BB78(p);
    else func_0220BA2C(p);
    func_0220B120(p);
    func_0220B1B0(p,*(u8 *)(p+0x532));
    func_0220B990((u8 *)p);
    func_0220BBE4(p);
    func_0220BD24(p,*(u8 *)(p+0x532));
    func_0220C034(p);
    func_0220C4EC(p,*(u8 *)(p+0x532));
    if(**(u8 **)(*(char **)p+0x2c)==1) *(void **)(p+0x598)=(void *)1;
    else *(void **)(p+0x598)=0;
    func_0220AFDC(*(char **)(p+0x148),*(void **)(p+0x598));
    if(*(u8 *)(p+0x532)==0) func_0220D8C4((u8 *)p,*(u8 *)(p+0x532),*(u8 *)(p+0x542));
    else func_0220D8C4((u8 *)p,*(u8 *)(p+0x532),0);
    func_0203D34C(0,*(u16 *)(*(char **)p+0xc));
    func_020216D4(*(void **)(p+8),3,224,32);
    func_0202173C(*(void **)(p+8),10,65535,0,16,0,0,func_021F86D4());
    if(*(int *)(*(char **)p+8)==3) func_0220D7F0(p,*(u8 *)(p+0x532));
    *(unsigned *)(p+0x5a0)=1;
    return 2;
}
