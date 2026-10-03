/*
 * function: func_021D77C4
 * address: 0x021D77C4
 * packet: pkt_ov123_021D77C4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5BA0 0x021D5BA0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7798 0x021D7798 thumb ov123
 *   func_0203F1FC 0x0203F1FC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_021D5BA0(int);
typedef unsigned int   u32;
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int func_0200C5C8(int,void *,int,u16);
extern void func_021D6EE0(int,int,int);
extern void func_021D6FF0(char *p);
extern void func_021D7798(u8 *p);
void func_021D77C4(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    *(u8 *)(a+0xa4)=0;
    p=func_021D5BA0(*(int *)(a+8));
    h=n/2;
    if(n>0x1fc0e) {
        *(int *)(a+0x80)=0xfff0;
        func_021D6EE0(a,(int)func_021D6FF0,0x39d);
        return;
    }
    checksum=func_0203F1FC(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        *(int *)(a+0x80)=0xfff0;
        func_021D6EE0(a,(int)func_021D6FF0,0x3a3);
        return;
    }
    *(u8 *)(a+0xae)=1;
    *(int *)(a+0x30)=func_0200C5C8(*(int *)(a+0x2c),p,n,*(u16 *)a);
    func_021D6EE0(a,(int)func_021D7798,0x3a9);
}
