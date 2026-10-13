/*
 * function: func_021DF6EC
 * address: 0x021DF6EC
 * packet: pkt_ov119_021DF6EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 */
extern int TOUCHPANEL_GetCont(void);
extern void func_021D8E84(void *, int);
extern void func_021DBBD0(char *p);
void func_021DF6EC(void *p)
{
    if (TOUCHPANEL_GetCont() == 0) {
        func_021D8E84(p, (int)func_021DBBD0);
    }
}
