/*
 * function: func_021AF13C
 * address:  0x021AF13C
 * packet:   pkt_ov013_021AF13C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_02156400  0x02156400  thumb  ov009
 *   func_021B20B0  0x021B20B0  arm  ov013
 */

typedef unsigned char u8;

typedef struct Work {
    u8 pad0[0x19AC];
    int f19AC;
    u8 pad19B0[0x1A1C - 0x19B0];
    int f1A1C;
} Work;

extern Work *d_021B3C80;
extern void func_02156400(void);
extern int func_021B20B0(int a, int b);

void func_021AF13C(void)
{
    if (d_021B3C80->f1A1C == 0 || d_021B3C80->f19AC == 0) {
        func_02156400();
        return;
    }
    if (d_021B3C80->f19AC == 1) {
        if (func_021B20B0(d_021B3C80->f1A1C, 2)) {
            func_02156400();
            return;
        }
    }
    if (func_021B20B0(d_021B3C80->f1A1C, 1)) {
        func_02156400();
    }
}
