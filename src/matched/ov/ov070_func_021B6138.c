/*
 * function: func_021B6138
 * address: 0x021B6138
 * packet: pkt_ov070_021B6138
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   func_021B9850 0x021B9850 thumb ov070
 *   func_021B9AAC 0x021B9AAC thumb ov070
 *   func_021BA218 0x021BA218 thumb ov070
 *   func_021B81F4 0x021B81F4 thumb ov070
 */
extern int func_020355C4(void);
extern void func_021B9850(char *p);
extern void func_021B9AAC(char *p);
extern void func_021BA218(char *p);
extern void func_021B81F4(char *p);
void func_021B6138(char *p)
{
    if (func_020355C4() == 0)
        func_021B9850(p);
    else
        func_021B9AAC(p);
    func_021BA218(p);
    func_021B81F4(p);
    *(unsigned short *)(p + 0x83E) = 1;
}
