/*
 * function: func_021E6840
 * address: 0x021E6840
 * packet: pkt_ov093_021E6840
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Callback kind 10 is reused as the multiplier, then decreased by 11;
 * this retains the live constant and reproduces the spill frame and muls.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021E6908 0x021E6908 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D7040 0x021D7040 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern int func_021E6908(u16);
extern void *func_021C7CF4(void *, int);
extern int func_021D5B68(void *);
extern u8 func_021D5778(void *, u16);
extern void *func_021C88A4(void *, int, int);
extern u8 func_021D5584(void *, u32);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(void *, void *);
extern void func_021D7040(void *);
void func_021E6840(void *x, void *a, int c)
{
    u8 k;
    void *m;
    u16 id;
    int i;
    u8 *p;
    int multiplier;
    if (c == func_021D775C(4)) {
        if (func_021E6908((u16)func_021D775C(18)) == 0) {
            if (func_021D5B68(func_021C7CF4(a, c)) != 0) {
                k = func_021D775C(3);
                m = func_021C7CF4(a, k);
                id = func_021D775C(20);
                i = func_021D5778(m, id);
                if (i != 4) {
                    multiplier = 10;
                    p = func_021C88A4(a, multiplier, c);
                    p[5] = k;
                    p[6] = i;
                    multiplier -= 11;
                    p[4] = func_021D5584(m, (u8)i) * multiplier;
                    p[7] |= 2;
                    func_021C8838(p + 8, 2, 0x27b);
                    func_021C8860(p + 8, k);
                    func_021C8860(p + 8, id);
                    func_021C88C8(a, p);
                }
                func_021D7040(x);
            }
        }
    }
}
