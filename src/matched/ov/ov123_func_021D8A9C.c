/*
 * function: func_021D8A9C
 * address: 0x021D8A9C
 * packet: pkt_ov123_021D8A9C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D57D0 0x021D57D0 thumb ov123
 *   func_021D56FC 0x021D56FC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8A7C 0x021D8A7C thumb ov123
 */
extern void func_020307B0(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D66D0(u8 *p, int n);
extern void func_021D57D0(void *, int, int, int);
extern void func_021D56FC(char *p, int mode);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D6650(u8 *p, int flag);
extern void func_021D62BC(u8 *p, int i, u32 v);
extern void func_020061E4(u32 a);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8A7C(char *p);
void func_021D8A9C(char *p)
{
    if (*(void **)(p+0x44)) {
        func_020307B0(*(void **)(p+0x44));
        *(void **)(p+0x44)=0;
    }
    *(int *)(p+0x70)=100;
    func_021D66D0(*(void **)(p+0x14),100);
    func_021D57D0(*(void **)(p+0x18),14,0,*(int *)(p+0xc));
    func_021D56FC(*(void **)(p+0x18),0);
    func_021D62B4(*(void **)(p+0x14),8);
    func_021D6650(*(void **)(p+0x14),0);
    func_021D62B4(*(void **)(p+0x14),0);
    func_021D62BC(*(void **)(p+0x14),4,6);
    func_020061E4(0x658);
    func_021D6EE0(p,(int)func_021D8A7C,0x8bd);
}
