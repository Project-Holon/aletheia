/*
 * function: func_02185954
 * address: 0x02185954
 * packet: pkt_ov023_02185954
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021862B0 0x021862B0 thumb ov023
 *   func_02186444 0x02186444 thumb ov023
 *   func_02185354 0x02185354 thumb ov023
 */
extern int func_021862B0(char *);
extern void func_02186444(char *, unsigned int);
extern void func_02185354(char *);
int func_02185954(char *p, int a)
{
    if (func_021862B0(p))
        func_02186444(p, 0xe);
    func_02185354(p);
    return a;
}
