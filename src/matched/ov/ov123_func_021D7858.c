/*
 * function: func_021D7858
 * address: 0x021D7858
 * packet: pkt_ov123_021D7858
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Word-array offset ((int *)a)[28] update avoids the cached
 *        address emitted for an integer-address lvalue at a+0x70.
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7BDC 0x021D7BDC thumb ov123
 *   func_021D5C2C 0x021D5C2C thumb ov123
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_021D66D0 0x021D66D0 thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D5C2C(char *p);
extern int func_021D5C0C(char *p);
extern void func_021D5B70(char *p);
extern void func_021D66D0(unsigned char *,int);
extern void func_021D6FF0(char *p);
extern void func_021D7BDC(char *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
void func_021D7858(int a)
{
    if(func_021D5C0C((char *)(*(int *)(a+8)))) {
        if(func_021D5C2C((char *)(*(int *)(a+8)))) {
            *(int *)(a+0x80)=0xfff0;
            func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3b6);
            return;
        }
        func_021D5B70((char *)(*(int *)(a+8)));
        *(int *)(a+8)=0;
        if(((int *)a)[28]<100) ((int *)a)[28]+=10;
        func_021D66D0(*(unsigned char **)(a+0x14),*(int *)(a+0x70));
        func_021D6EE0((u8 *)a,(int)func_021D7BDC,0x3c3);
    }
}
