/*
 * function: func_021D746C
 * address: 0x021D746C
 * packet: pkt_ov123_021D746C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020092D0 0x020092D0 thumb
 *   func_021D7224 0x021D7224 thumb ov123
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D7CB4 0x021D7CB4 thumb ov123
 *   func_021D7DE8 0x021D7DE8 thumb ov123
 *   func_021D7C54 0x021D7C54 thumb ov123
 *   func_021D7D18 0x021D7D18 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7430 0x021D7430 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02009448(int);
extern void func_021D7224(int);
extern int func_021D6EBC(int);
extern void func_021D7CB4(int,int);
extern void func_021D7DE8(int,int,int);
extern void func_021D7C54(int,int);
extern void func_020092D0(int,u8);
typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern void func_021D7D18(int,int,u16,u8,u8,u16,int);
extern void func_02009348(int,int,u16,u8);
extern int func_02012DAC(int a0);
extern void func_021D6EE0(int,int,int);
extern void func_021D7430(u8 *p);
void func_021D746C(int a)
{
    int b;
    int i;
    u8 *p;
    b=func_02009448(*(int *)(a+0x28));
    *(u8 *)(a+0xab)=1;
    func_021D7224(a);
    if(func_021D6EBC(a)==0) {
        func_021D7CB4(b,*(int *)(a+0x38));
        func_021D7DE8(a,b,*(int *)(a+0x38));
        func_021D7C54(b,*(int *)(a+0x38));
        func_020092D0(b,*(u8 *)(*(int *)(a+0x38)+0x5a));
    } else {
        p=*(u8 **)(a+0x20)+0xc;
        func_021D7D18(a,b,*(u16 *)(p+2),p[7],p[6],*(u16 *)(p+4),func_020056EC(8));
        for(i=0;i<20;i++) func_02009348(b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    *(u8 *)(a+0xad)=1;
    func_02012DAC(*(int *)(a+0x2c));
    func_021D6EE0(a,(int)func_021D7430,0x311);
}
