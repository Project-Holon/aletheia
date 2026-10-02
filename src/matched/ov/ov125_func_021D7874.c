/*
 * function: func_021D7874
 * address: 0x021D7874
 * packet: pkt_ov125_021D7874
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: case 6 uses an explicit nested if for the error-13 split; the ternary spelling compiled four bytes short.
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   func_021D8444 0x021D8444 arm ov125
 *   func_021D7E80 0x021D7E80 arm ov125
 *   func_021D7FA0 0x021D7FA0 arm ov125
 *   func_021D80E0 0x021D80E0 arm ov125
 *   func_021D824C 0x021D824C arm ov125
 *   func_021D7C90 0x021D7C90 arm ov125
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 */
extern int d_021D9E40[];
extern int func_021D8444(void);
extern int func_021D7E80(void);
extern int func_021D7FA0(void);
extern int func_021D80E0(void);
extern int func_021D824C(void);
extern void func_021D7C90(int);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
void func_021D7874(void)
{
    int finish, next;
    for (;;) {
        finish = 0;
        switch (d_021D9E40[0x13c/4]) {
        case 0: case 1: case 7: case 8: case 9:
            finish = 1;
            break;
        case 2:
            if (!func_021D8444()) {
                next = d_021D9E40[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 3;
            func_021D7CAC();
            d_021D9E40[0x13c/4] = next;
            break;
        case 3:
            if (!func_021D7E80()) {
                next = d_021D9E40[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 4;
            func_021D7CAC();
            d_021D9E40[0x13c/4] = next;
            break;
        case 4:
            if (!func_021D7FA0()) {
                next = d_021D9E40[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 5;
            func_021D7CAC();
            d_021D9E40[0x13c/4] = next;
            break;
        case 5:
            if (!func_021D80E0()) {
                next = d_021D9E40[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 6;
            if (d_021D9E40[0x258/4]) {
                func_021D7C90(d_021D9E40[0x258/4]);
                d_021D9E40[0x258/4] = 0;
            }
            func_021D7CAC();
            d_021D9E40[0x13c/4] = next;
            break;
        case 6:
            if (!func_021D824C()) {
                if (d_021D9E40[0x250/4] == 13) next = 7;
                else next = 9;
            } else {
                next = 8;
            }
            finish = 1;
            func_021D7CAC();
            d_021D9E40[0x13c/4] = next;
            break;
        }
        if (finish != 0) break;
        if (d_021D9E40[0x268/4] == 1) {
            d_021D9E40[0x13c/4] = 7;
            d_021D9E40[0x250/4] = 13;
            break;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
    func_021D7CC0();
}
