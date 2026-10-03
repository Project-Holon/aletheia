/*
 * function: func_0218DAEC
 * address:  0x0218DAEC
 * packet:   pkt_ov021_0218DAEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218D9B8  0x0218D9B8  thumb ov021
 *   func_0218D9E8  0x0218D9E8  thumb ov021
 *   func_021AB100  0x021AB100  thumb ov021
 *   _ll_mul        0x0209C054  arm
 */

typedef unsigned short u16;

typedef struct { u16 a; u16 b; u16 c; u16 d; int p; int q; } E;
typedef struct { E e[16]; u16 n; } B;

extern void func_0218D9B8(E *e);
extern int func_0218D9E8(void *p, void *q, B *b);
typedef unsigned int   u32;
extern int func_021AB100(u32 attr);

int func_0218DAEC(char *p, char *q, E *out)
{
    B b;
    int i;
    int best;
    int mn;

    func_0218D9B8(out);
    if (func_0218D9E8(p, q, &b) == 0)
        return 0;
    if (b.n == 1) {
        *out = b.e[0];
        return 1;
    }
    best = 0;
    mn = 0x00FFF000;
    for (i = 0; i < b.n; i++) {
        if (func_021AB100(b.e[i].p)) {
            int d = b.e[i].q - *(int *)(q + 4);
            if (d < 0)
                d = (int)(((long long)d * -4096LL + 0x800LL) >> 12);
            if (d < mn) {
                best = i;
                mn = d;
            }
        }
    }
    *out = b.e[best];
    return 1;
}
