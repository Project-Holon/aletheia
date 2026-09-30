/*
 * function: func_021DCC38
 * address: 0x021DCC38
 * packet: pkt_ov119_021DCC38
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC854 0x021DC854 thumb ov119
 *   func_021DC894 0x021DC894 thumb ov119
 *   func_021DCBA4 0x021DCBA4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D4B88 0x021D4B88 thumb ov117
 */
extern void *func_021DC854(void *, int);
extern int func_021DC894(void *, int, void *, void *, int);
extern void func_021DCBA4(void *, void *);
extern void func_021D8E84(void *, int);
extern void func_021D4B88(unsigned char *);
int func_021DCC38(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0xc6000);
    *(int *)(c + 0x14) = *(int *)(c + 0x30);
    r = func_021DC894(a, b, c, p, 4);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D4B88);
    return r;
}
