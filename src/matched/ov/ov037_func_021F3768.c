/*
 * function: func_021F3768
 * address:  0x021F3768
 * packet:   pkt_ov037_021F3768
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_0200B3A8  0x0200B3A8  thumb
 *   d_021F3840     0x021F3840  data ov037 a1
 *   d_021F3834     0x021F3834  data a1
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(unsigned int, unsigned int);
extern unsigned short *func_0200B3A8(unsigned int, unsigned int);
extern signed char d_021F3840[][2];
extern unsigned char d_021F3834[][2];

void func_021F3768(unsigned int a0, unsigned short **a1)
{
    unsigned int t = (unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)a0));
    int *p = func_0200B3A4(t, 6);
    unsigned short *q = func_0200B3A8(t, 6);
    int i;
    int j;
    int k;

    for (i = 0; i < 8; i++) {
        if (q[i] != 0) {
            p[i] = 1;
            *a1[i] = 1;
            for (j = 0; j < 2; j++) {
                k = d_021F3840[i][j];
                if (k != -1)
                    p[8 + k] = 1;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            if (p[8 + d_021F3834[i][j]] == 0)
                break;
        }
        if (j == 2)
            p[18 + i] = 1;
    }
    p[24] = 1;
}
