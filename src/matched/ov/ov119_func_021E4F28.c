/*
 * function: func_021E4F28
 * address:  0x021E4F28
 * packet:   pkt_ov119_021E4F28
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * lever:    the hoisted column sum is written inside the else arm as two statements.
 * symbols:
 *   func_021E5158 0x021E5158 thumb ov119
 *   func_021DF6B4 0x021DF6B4 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef short s16;
typedef unsigned char u8;
typedef struct Pt { s16 x, y; } Pt;
extern int func_021E5158(int);
extern int func_021DF6B4(char *, int, int);
extern u8 func_020355C4(void);
extern void func_0204B800(int, u8);
extern void func_0204B404(int, const Pt *, unsigned int);
void func_021E4F28(char *p)
{
    char *q;
    int i, off, y, row, j, x, ty, col;
    Pt b, a;
    off = 0;
    y = *(s16 *)(p + 0x1080);
    for (i = 0; i < 12; i++) {
        row = func_021E5158(*(s16 *)(p + 0x1080) + i);
        if (y >= *(int *)(p + 0x634)) {
            y -= *(int *)(p + 0x634);
            off = *(int *)(p + 0x63c);
        }
        for (j = 0; j < 5; j++) {
            ty = j * 24 + 0x20;
            if (y == 0) x = 0x1c;
            else if (y == 1) x = 0x3c;
            else {
                col = (y - 2) / 6 * 160;
                col += (y - 2) % 6 * 24 + 0x14;
                x = col + 0x60;
            }
            b.x = off + (x - *(s16 *)(p + 0x107c));
            b.y = ty;
            a = b;
            if (func_021DF6B4(p, y, j) && func_020355C4() == 1) {
                b.y -= 8;
                q = p + row * 20 + j * 4;
                func_0204B800(*(int *)(q + 0xac0), 11);
            } else {
                q = p + row * 20 + j * 4;
                func_0204B800(*(int *)(q + 0xac0), 0x1c - i);
            }
            func_0204B404(*(int *)(q + 0xac0), &b, 1);
            if (*(u8 *)(p + row * 5 + j + 0xebc)) {
                *(Pt *)(q + 0xdcc) = a;
            }
            b.y = ty + 3;
            func_0204B404(*(int *)(q + 0xbb0), &b, 1);
        }
        y++;
    }
}
