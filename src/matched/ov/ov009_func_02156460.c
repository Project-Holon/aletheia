/*
 * function: func_02156460
 * address:  0x02156460
 * packet:   pkt_ov009_02156460
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Classify a network error code (and its error kind) into a message class.
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 */

extern int _s32_div_f(int, int);
extern char d_021A1C5C[];
typedef unsigned int   u32;
void func_02034714(const char *expr, u32 line, const char *file);

int func_02156460(int err, int kind)
{
    int d100 = err / 100;
    int d1000 = err / 1000;

    if (err == 20101)
        return 1;
    if (d1000 == 23)
        return 1;
    if (err == 20108)
        return 2;
    if (err == 20110)
        return 3;
    if (d100 == 512)
        return 4;
    if (d100 == 500)
        return 5;
    if (err == 51103)
        return 6;
    if (d100 == 510)
        return 6;
    if (d100 == 511)
        return 6;
    if (d100 == 513)
        return 6;
    if (err >= 52000 && err <= 52003)
        return 8;
    if (err >= 52010 && err <= 52012)
        return 8;
    if (err >= 52100 && err <= 52103)
        return 8;
    if (err >= 52110 && err <= 52112)
        return 8;
    if (err >= 52200 && err <= 52203)
        return 8;
    if (err >= 52210 && err <= 52212)
        return 8;
    if (err >= 52400 && err <= 52403)
        return 8;
    if (err >= 52410 && err <= 52412)
        return 8;
    if (err >= 52500 && err <= 52503)
        return 8;
    if (err >= 52510 && err <= 52512)
        return 8;
    if (err >= 52700 && err <= 52703)
        return 8;
    if (err >= 52710 && err <= 52712)
        return 8;
    if (err == 80430)
        return 9;
    if (d1000 == 20)
        return 0;
    if (d100 == 520)
        return 0;
    if (d100 == 521)
        return 0;
    if (d100 == 522)
        return 0;
    if (d100 == 523)
        return 0;
    if (d100 == 530)
        return 0;
    if (d100 == 531)
        return 0;
    if (d100 == 532)
        return 0;
    if (err < 10000)
        return 14;
    if (d1000 == 31)
        return 12;
    switch (kind) {
    case 0:
    case 1:
        return 14;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return 11;
    default:
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
        break;
    case 7:
        return 15;
    }
    return -1;
}
