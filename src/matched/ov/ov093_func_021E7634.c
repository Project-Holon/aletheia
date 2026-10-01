/*
 * unit: yes
 * function: func_021E7634, func_021E7754
 * address: 0x021E7634
 * packet: pkt_ov093_021E7634
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: func_021E89C0 returns a one-word aggregate, reserving its frame temporary.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8374 0x021C8374 thumb ov093
 *   func_021C8234 0x021C8234 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021E89C0 0x021E89C0 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F274C 0x021F274C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int func_021D775C(int);
extern void *func_021C7CF4(int, int);
extern int func_021C8374(int, int);
extern int func_021C8234(int, int);
extern int func_021D62C4(void *, int);
extern int func_021D5BDC(void *, u32);
extern Word func_021E89C0(u32);
extern u8 *func_021C88A4(int, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(int, u8 *);
extern int d_021F274C[];
void func_021E7634(int a, int b, int c)
{
    u8 k;
    void *x;
    int flag;
    u8 *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        x = func_021C7CF4(b, k);
        flag = 0;
        if (func_021C8374(b, k) == 0) {
            if (func_021C8234(b, k) != 0 && func_021D62C4(x, 0x21) == 0) {
                p = func_021C88A4(b, 12, c);
                p[15] = k;
                *(int *)(p + 4) = 0x1f;
                *(Word *)(p + 8) = func_021E89C0(0x1f);
                func_021C8838(p + 20, 2, 0x468);
                func_021C8860(p + 20, k);
                func_021C88C8(b, p);
                flag = 1;
                if (func_021D62C4(x, 0x1e) != 0) {
                    p = func_021C88A4(b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    *(int *)(p + 4) = 0x1e;
                    func_021C88C8(b, p);
                }
                if (func_021D62C4(x, 0x20) != 0) {
                    p = func_021C88A4(b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    *(int *)(p + 4) = 0x20;
                    func_021C88C8(b, p);
                }
            }
            if (func_021D5BDC(x, 3) != 0) {
                p = func_021C88A4(b, 0x36, c);
                p[4] = k;
                *(int *)(p + 8) = 3;
                if (flag == 0) {
                    func_021C8838(p + 12, 2, 0x468);
                    func_021C8860(p + 12, k);
                }
                func_021C88C8(b, p);
            }
        }
    }
}

int *func_021E7754(int *p)
{
    *p = 1;
    return d_021F274C;
}
