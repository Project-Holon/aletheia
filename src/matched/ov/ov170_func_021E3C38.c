/*
 * function: func_021E3C38
 * address: 0x021E3C38
 * packet: pkt_ov170_021E3C38
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 */
extern void func_020061E4(unsigned);
extern void func_021DD530(unsigned char *);
extern void func_021EA1E8(unsigned char *);
extern void func_020260E4(void *, unsigned char);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
int func_021E3C38(unsigned char *p)
{
    func_020061E4(0x667);
    func_021DD530(p);
    func_021EA1E8(p);
    func_020260E4(*(void **)(*(char **)(p + 0x2c) + 0x70), 9);
    func_021EE3E4((char **)p, 9);
    func_021ED55C((char **)p, 1);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x1b;
}
