/*
 * function: func_021DA1EC
 * address: 0x021DA1EC
 * packet: pkt_ov123_021DA1EC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021D9730 0x021D9730 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA1C8 0x021DA1C8 thumb ov123
 */
extern void func_021B9774(void *);
extern void func_021D9730(void *,unsigned);
extern void func_021DA034(char *,void *,int);
extern void func_021DA1C8(void);
void func_021DA1EC(char *p)
{
    unsigned n;
    n = *(unsigned *)(p + 0x70) + 11;
    if (*(void **)(p + 8)) func_021B9774(*(void **)(p + 8));
    if (*(unsigned *)(p + 0x70) == 0xfff1) n = 22;
    else if (*(unsigned *)(p + 0x70) == 0xfff2) n = 23;
    else if (*(unsigned *)(p + 0x70) == 0xfff3) n = 20;
    else if (*(unsigned *)(p + 0x70) >= 10) n = 20;
    func_021D9730(*(void **)(p + 0x10),n);
    func_021DA034(p,func_021DA1C8,0x167);
}
