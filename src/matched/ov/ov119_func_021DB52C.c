/*
 * function: func_021DB52C
 * address: 0x021DB52C
 * packet: pkt_ov119_021DB52C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_021DD018 0x021DD018 thumb ov119
 *   func_021E4E0C 0x021E4E0C thumb ov119
 *   func_021DB4EC 0x021DB4EC thumb ov119
 *   func_021DB4B4 0x021DB4B4 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021DB7AC 0x021DB7AC thumb ov119
 *   d_021E7FE0 0x021E7FE0 data a4
 */
extern unsigned int func_0203633C(void);
extern void func_020355D8(int);
extern void func_021DD018(char *, int);
extern int func_021E4E0C(char *, int *);
extern int func_021DB4EC(char *, int);
extern int func_021DB4B4(int);
extern void func_020061E4(int);
extern void func_021DB7AC(char *, int, int);
extern const int d_021E7FE0[];
void func_021DB52C(char *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = func_0203633C();
    if (*(int *)(p + 0xF60) != 0)
        return;
    if (k & 0x100) {
        func_020355D8(0);
        for (i = 0; i < *(int *)(p + 0x630) + 1; i++) {
            if (d_021E7FE0[i] > *(short *)(p + 0x107C)) {
                *(short *)(p + 0x107C) = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            *(short *)(p + 0x107C) = d_021E7FE0[0];
        }
        func_021DD018(p, changed);
    } else if (k & 0x200) {
        func_020355D8(0);
        for (i = *(int *)(p + 0x630); i >= 0; i--) {
            if (d_021E7FE0[i] < *(short *)(p + 0x107C)) {
                *(short *)(p + 0x107C) = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            *(short *)(p + 0x107C) = d_021E7FE0[*(int *)(p + 0x630)];
        }
        func_021DD018(p, changed);
    } else if (func_0203633C() == 0x40) {
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            *(int *)(p + 0xF74) = v;
        if (--*(int *)(p + 0xF78) < 0) {
            if (*(int *)(p + 0xF74) < 2)
                *(int *)(p + 0xF78) = 2;
            else
                *(int *)(p + 0xF78) = 4;
        }
        *(short *)(p + 0x1080) = *(short *)(p + 0x1080) - 1;
        changed = 1;
    } else if (func_0203633C() == 0x80) {
        int x;
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            *(int *)(p + 0xF74) = v;
        x = ++*(int *)(p + 0xF78);
        if (*(int *)(p + 0xF74) < 2) {
            if (x >= 3)
                *(int *)(p + 0xF78) = 0;
        } else if (x >= 5)
            *(int *)(p + 0xF78) = 0;
        *(short *)(p + 0x1080) = *(short *)(p + 0x1080) - 1;
        changed = 1;
    } else if (func_0203633C() == 0x10) {
        func_020355D8(0);
        *(short *)(p + 0x1080) = *(short *)(p + 0x1080) - 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            *(int *)(p + 0xF74) = v;
        } else {
            *(int *)(p + 0xF74) = *(int *)(p + 0xF74) + 1;
            if (func_021DB4EC(p, *(int *)(p + 0xF74)) == 0) {
                *(short *)(p + 0x107C) = func_021DB4B4(*(int *)(p + 0xF74) + 1) - 0x100;
                *(short *)(p + 0x1080) = -1;
            }
        }
        if (*(int *)(p + 0xF74) >= *(int *)(p + 0x634))
            *(int *)(p + 0xF74) = 0;
        if (*(int *)(p + 0xF74) < 2 && *(int *)(p + 0xF78) >= 3)
            *(int *)(p + 0xF78) = 2;
    } else if (func_0203633C() == 0x20) {
        func_020355D8(0);
        *(short *)(p + 0x1080) = *(short *)(p + 0x1080) + 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            *(int *)(p + 0xF74) = v;
        } else {
            *(int *)(p + 0xF74) = *(int *)(p + 0xF74) - 1;
            if (*(int *)(p + 0xF74) < 0)
                *(int *)(p + 0xF74) = *(int *)(p + 0x634) - 1;
            if (func_021DB4EC(p, *(int *)(p + 0xF74)) == 0) {
                *(short *)(p + 0x107C) = func_021DB4B4(*(int *)(p + 0xF74));
                *(short *)(p + 0x1080) = -1;
            }
        }
        if (*(int *)(p + 0xF74) < 0)
            *(int *)(p + 0xF74) = *(int *)(p + 0x634) - 1;
        if (*(int *)(p + 0xF74) < 2 && *(int *)(p + 0xF78) >= 3)
            *(int *)(p + 0xF78) = 2;
    }
    if (changed) {
        *(int *)(p + 0x1084) = 1;
        func_020061E4(0x548);
        func_021DB7AC(p, 0, 1);
    }
}
