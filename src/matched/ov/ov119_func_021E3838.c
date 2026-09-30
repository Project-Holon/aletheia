/*
 * function: func_021E3838
 * address: 0x021E3838
 * packet: pkt_ov119_021E3838
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207F7A0 0x0207F7A0 arm
 *   func_02030734 0x02030734 arm
 *   d_021E81C0 0x021E81C0 data ov119 a4
 *   func_02082BCC 0x02082BCC arm
 *   func_021E380C 0x021E380C thumb ov119
 *   func_021E37D8 0x021E37D8 thumb ov119
 *   func_020862F0 0x020862F0 arm
 *   func_0207F7FC 0x0207F7FC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207F9B4 0x0207F9B4 arm
 *   func_021E3B2C 0x021E3B2C thumb ov119
 */
extern void func_0207F7A0(void);
extern void *func_02030734(unsigned short, int, int, const void *, int);
extern const char d_021E81C0[];
extern void func_02082BCC(void *, int, int);
extern void func_021E380C(void *, void *, int);
extern void func_021E37D8(void *, void *, int, int);
extern void func_020862F0(void *, int);
extern void func_0207F7FC(void *, int, int);
extern void func_020307B0(void *);
extern void func_0207F9B4(void);
extern void func_021E3B2C(char *);
void func_021E3838(char *p, int count)
{
    char *v;
    int i;
    func_0207F7A0();
    v = func_02030734(*(unsigned short *)(p + 0x5F4), 0x200, 1, d_021E81C0, 0x510);
    for (i = 0; i < count; i++) {
        func_02082BCC(v, 0, 0x200);
        if (i == 0)
            func_021E380C(v, p + 0x5B6, 2);
        else
            func_021E37D8(v, p + 0x2E6, i - 1, 2);
        func_020862F0(v, 0x200);
        func_0207F7FC(v, i * 0x200 + 0x3000, 0x200);
    }
    func_020307B0(v);
    func_0207F9B4();
    func_021E3B2C(p);
}
