/*
 * function: func_021DB998
 * address: 0x021DB998
 * packet: pkt_ov119_021DB998
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C38 0x02035C38 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
extern int func_02035C38(void);
extern void func_021D8E84(void *, int);
extern void func_021DBE70(char *p);
void func_021DB998(char *p)
{
    if (func_02035C38() == 0)
        func_021D8E84(p, (int)func_021DBE70);
}
