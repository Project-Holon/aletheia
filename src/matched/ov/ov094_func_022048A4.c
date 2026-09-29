/*
 * function: func_022048A4
 * address:  0x022048A4
 * packet:   pkt_ov094_022048A4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220A3B4     0x0220A3B4  data   ov094  a4
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef short s16;
typedef unsigned int u32;

typedef struct Main {
    unsigned char pad00[0x68];
    u32 f68;
} Main;

typedef struct Ctx {
    Main *main;
    int f4;
} Ctx;

extern const int d_0220A3B4[][2];
extern void func_0204B454(void *h, s16 *out, int k);
extern void func_0204B404(void *h, s16 *in, int k);
extern void func_0220687C(Main *m, int a);

void func_022048A4(int a0, Ctx *c)
{
    int k;
    int changed = 0;
    int target;
    char *p;
    int j;
    s16 v[2];

    for (k = 0; k < 2; k++) {
        target = d_0220A3B4[k][c->f4];
        if (k == 0) {
            p = (char *)c->main + 0x47 * 4;
        } else {
            if (((c->main->f68 << 17) >> 31) == 0) {
                break;
            }
            p = (char *)c->main + 0x53 * 4;
        }
        for (j = 0; j < 6; j++) {
            func_0204B454(*(void **)(p + j * 8), v, 1);
            if (v[1] > target) {
                v[1] = v[1] - 4;
                changed = 1;
            } else if (v[1] < target) {
                v[1] = v[1] + 4;
                changed = 1;
            }
            func_0204B404(*(void **)(p + j * 8), v, 1);
        }
    }
    if (changed == 0) {
        func_0220687C(c->main, a0);
    }
}
