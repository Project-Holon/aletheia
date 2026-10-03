/*
 * function: func_021DCCF8
 * address: 0x021DCCF8
 * packet: pkt_ov119_021DCCF8
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
 *   func_021D4AB4 0x021D4AB4 thumb ov118
 */
extern void *func_021DC854(void *, int);
extern int func_021DC894(void *, int, void *, void *, int);
extern void func_021DCBA4(char *a, char *p);
extern void func_021D8E84(void *, int);
extern void func_021D4AB4(unsigned char *);
int func_021DCCF8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    *(int *)(c + 0x14) = *(int *)(c + 0x30);
    r = func_021DC894(a, b, c, p, 6);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D4AB4);
    return r;
}
