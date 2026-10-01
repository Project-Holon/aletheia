/*
 * function: func_021BBA78
 * address: 0x021BBA78
 * packet: pkt_ov223_021BBA78
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040EBC 0x02040EBC arm
 *   func_021B9854 0x021B9854 thumb ov223
 *   func_021BAB78 0x021BAB78 thumb ov223
 *   func_021BAC0C 0x021BAC0C thumb ov223
 *   func_021BB2A4 0x021BB2A4 thumb ov223
 *   func_0207D63C 0x0207D63C arm
 */
extern void func_02040EBC(unsigned, unsigned);
extern void func_021B9854(void *);
extern void func_021BAB78(void *);
extern void func_021BAC0C(unsigned short *);
extern void func_021BB2A4(void *);
extern void func_0207D63C(void *, unsigned, unsigned, unsigned, unsigned);
int func_021BBA78(char *p)
{
    func_02040EBC(0, 0x2F3B);
    func_02040EBC(4, 0x2F3B);
    func_021B9854(p);
    func_021BAB78(p);
    func_021BAC0C((unsigned short *)p);
    func_021BB2A4(p);
    *(unsigned *)(p + 0x24) |= 2;
    *(unsigned char *)(p + 0x268) = 0;
    func_0207D63C((void *)0x04000050, 5, 63,
                 *(unsigned char *)(p + 0x268), 16 - *(unsigned char *)(p + 0x268));
    *(int *)(p + 0x10) = 0;
    return 3;
}
