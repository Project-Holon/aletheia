/*
 * function: func_021E42B4
 * address: 0x021E42B4
 * packet: pkt_ov119_021E42B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   func_021E421C 0x021E421C thumb ov119
 *   func_021E41A0 0x021E41A0 thumb ov119
 *   func_02042FB0 0x02042FB0 arm
 *   func_02041B6C 0x02041B6C arm
 */
extern int func_021E4DBC(char *);
extern int func_021E421C(char *, int, int);
extern unsigned short func_021E41A0(int, int, char *, int);
extern void func_02042FB0(int, int, int, unsigned short);
extern void func_02041B6C(int);
void func_021E42B4(char *p)
{
    int x, y, n, mode;
    n = *(short *)(p + 0x107c) / 8;
    func_021E4DBC(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = func_021E421C(p, x, y);
            func_02042FB0(7, x, y, func_021E41A0(n + x, y, p, mode));
        }
    }
    *(int *)(p + 0x108c) = *(short *)(p + 0x107c) % 8;
    *(int *)(p + 0x1084) = 1;
    func_02041B6C(7);
}
