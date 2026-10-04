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
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D5C2C(char *p);
extern int func_021D5C0C(char *p);
extern void *func_021D5D8C(u8 *p);
extern void func_021D5C9C(char *p);
extern void func_021D6FF0(char *p);
extern void func_021D7960(int a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D79A4(int a)
{
    if(func_021D5C2C((char *)(*(int *)(a+8)))) {
        *(int *)(a+0x80)=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3fe);
        return;
    }
    if(func_021D5C0C((char *)(*(int *)(a+8)))) {
        if(func_021D5D8C((u8 *)(*(int *)(a+8)))==0) {
            *(int *)(a+0x80)=0xfff0;
            func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x407);
            return;
        }
        func_021D5C9C((char *)(*(int *)(a+8)));
        func_021D6EE0((u8 *)a,(int)func_021D7960,0x40d);
    }
}
