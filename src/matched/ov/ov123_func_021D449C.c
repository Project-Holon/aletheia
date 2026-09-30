/*
 * function: func_021D449C
 * address: 0x021D449C
 * packet: pkt_ov123_021D449C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4FB8 0x021D4FB8 thumb ov123
 *   func_021D4A04 0x021D4A04 thumb ov123
 *   func_021D4D40 0x021D4D40 thumb ov123
 */
extern int func_020279E8(void *);
extern int func_02027A04(void *);
extern void func_020414EC(int);
extern void func_02027858(void *);
extern void func_021D4244(char *, void *, int);
extern void func_021D4FB8(void);
extern void func_021D4A04(void);
extern void func_021D4D40(char *, int);
void func_021D449C(char *p)
{
    if (func_020279E8(*(void **)(p + 0x238))) {
        if (!func_02027A04(*(void **)(p + 0x238))) {
            func_021D4244(p, func_021D4FB8, 0x1b6);
        } else {
            func_020414EC(5);
            *(int *)(p + 8) = 0;
            func_021D4244(p, func_021D4A04, 0x1bb);
        }
        func_02027858(*(void **)(p + 0x238));
        *(int *)(p + 0x238) = 0;
        func_021D4D40(p, 0);
    }
}
