/*
 * function: func_021D79A4
 * address: 0x021D79A4
 * packet: pkt_ov123_021D79A4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7960 0x021D7960 thumb ov123
 *   func_021D5C2C 0x021D5C2C thumb ov123
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5C9C 0x021D5C9C thumb ov123
 *   func_021D5D8C 0x021D5D8C thumb ov123
 */
extern int func_021D5C2C(int);
extern int func_021D5C0C(int);
extern int func_021D5D8C(int);
extern void func_021D5C9C(int);
extern void func_021D6FF0(char *p);
extern void func_021D7960(int a);
extern void func_021D6EE0(int,int,int);
void func_021D79A4(int a)
{
    if(func_021D5C2C(*(int *)(a+8))) {
        *(int *)(a+0x80)=0xfff0;
        func_021D6EE0(a,(int)func_021D6FF0,0x3fe);
        return;
    }
    if(func_021D5C0C(*(int *)(a+8))) {
        if(func_021D5D8C(*(int *)(a+8))==0) {
            *(int *)(a+0x80)=0xfff0;
            func_021D6EE0(a,(int)func_021D6FF0,0x407);
            return;
        }
        func_021D5C9C(*(int *)(a+8));
        func_021D6EE0(a,(int)func_021D7960,0x40d);
    }
}
