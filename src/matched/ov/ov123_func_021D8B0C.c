/*
 * function: func_021D8B0C
 * address: 0x021D8B0C
 * packet: pkt_ov123_021D8B0C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8A9C 0x021D8A9C thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_0203C9AC 0x0203C9AC arm
 *   func_0203C938 0x0203C938 arm
 */
extern void func_021D66D0(void *,int);
extern int func_02012DD0(void *);
extern void func_020307B0(void *);
extern void func_0203C9AC(int,int,int,int);
extern void func_0203C938(int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8A9C(void);
void func_021D8B0C(char *p)
{
    if (*(int *)(p+0x70)<100) ++*(int *)(p+0x70);
    func_021D66D0(*(void **)(p+0x14),*(int *)(p+0x70));
    switch (func_02012DD0(*(void **)(p+0x2c))) {
    case 1:
        if (*(void **)(p+0x34)) {
            func_020307B0(*(void **)(p+0x34));
            *(void **)(p+0x34)=0;
        }
        break;
    case 3:
        func_0203C9AC(0,0,0,0x3f3);
        func_0203C938(0);
        break;
    case 2:
        p[0xad]=0;
        func_021D6EE0(p,(int)func_021D8A9C,0x8e6);
        break;
    }
}
