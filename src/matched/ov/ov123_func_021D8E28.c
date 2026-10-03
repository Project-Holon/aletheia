/*
 * function: func_021D8E28
 * address: 0x021D8E28
 * packet: pkt_ov123_021D8E28
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8DFC 0x021D8DFC thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D62BC(u8 *p, int i, u32 v);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8DFC(char *p);
void func_021D8E28(char *p)
{
    if (--*(int *)(p+0x60) == 0) {
        func_021D62BC(*(void **)(p+0x14), 0, 1);
        func_021D62B4(*(void **)(p+0x14), 2);
        func_021D62B4(*(void **)(p+0x14), 3);
        *(int *)(p+0x60) = 15;
        func_021D6EE0(p, (int)func_021D8DFC, 0x9cf);
    }
}
