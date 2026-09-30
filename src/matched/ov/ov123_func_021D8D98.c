/*
 * function: func_021D8D98
 * address: 0x021D8D98
 * packet: pkt_ov123_021D8D98
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D65F4 0x021D65F4 thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D6650 0x021D6650 thumb ov123
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8D08 0x021D8D08 thumb ov123
 */
extern void func_021D65F4(char *);
extern void func_021D57B8(char *,int);
extern void func_021D5A7C(char *);
extern void func_021D6650(void *,int);
extern void func_021D62BC(void *,int,unsigned int);
extern void func_021D62B4(void *,int);
extern void func_020061E4(int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8D08(void);
void func_021D8D98(char *p)
{
    if (--*(int *)(p+0x60)==0) {
        func_021D65F4(*(char **)(p+0x14));
        func_021D57B8(*(char **)(p+0x18),8);
        func_021D5A7C(*(char **)(p+0x18));
        func_021D6650(*(void **)(p+0x14),1);
        func_021D62BC(*(void **)(p+0x14),4,5);
        func_021D62BC(*(void **)(p+0x14),0,0);
        func_021D62B4(*(void **)(p+0x14),12);
        func_020061E4(0x657);
        func_021D6EE0(p,(int)func_021D8D08,0x9a8);
    }
}
