/*
 * function: func_02155DCC
 * address:  0x02155DCC
 * packet:   pkt_ov009_02155DCC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_0216B838  0x0216B838  arm
 *   func_02155DA4  0x02155DA4  thumb  ov009
 *   func_021AEF44  0x021AEF44  thumb  ov013
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef void (*Cb)(u32, u8 *, u16);

typedef struct {
    char pad[0x27c];
    Cb cb0;
    Cb cb1;
    char pad2[0x79d - 0x284];
    u8 b79d;
    char pad3[0x7a6 - 0x79e];
    u8 b7a6;
    u8 b7a7;
    u8 b7a8;
} G;

extern G *d_021A8264;
extern char d_021A1C5C[];
void func_02034714(const char *expr, u32 line, const char *file);
unsigned char func_0216B838(void);
void func_02155DA4(u32 x);
int func_021AEF44(int a, int b, int c);

void func_02155DCC(u32 a, u8 *p, int c)
{
    u32 x = p[0] | ((p[3] << 24) | (p[2] << 16) | (p[1] << 8));

    if (a >= 2)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a < 2) {
        d_021A8264->b7a8 = 1;
        if ((u8)x == 1) {
            func_02155DA4(x);
            d_021A8264->b79d = p[2];
            d_021A8264->b7a7 = 1;
        } else if ((u8)x == 3) {
            d_021A8264->b7a6 = 1;
            return;
        } else {
            if (func_021AEF44(a, (int)p, c) == 0)
                return;
            return;
        }
        if (func_0216B838() == 0) {
            if (d_021A8264->cb0 != 0)
                d_021A8264->cb0(a, p + 4, (u16)(c - 4));
        } else {
            if (d_021A8264->cb1 != 0)
                d_021A8264->cb1(a, p + 4, (u16)(c - 4));
        }
    }
}
