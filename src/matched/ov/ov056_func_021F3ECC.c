/*
 * function: func_021F3ECC
 * address:  0x021F3ECC
 * packet:   pkt_ov056_021F3ECC
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F425C  0x021F425C  data  ov056  a4
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u32 f4;
    u16 f8;
    s16 fa;
    int fc;
} S3ECC;

struct SoundSys2;
extern int func_0218C6F4(unsigned char *p, int b, int id);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern int d_021F425C[];

void func_021F3ECC(int a, int b, S3ECC *c)
{
    int i;
    int r;

    i = 0;
    r = func_0218C6F4((unsigned char *)c->f0, c->f4, 0);
    for (; i < 2; i++) {
        if (r == d_021F425C[i]) {
            func_02028A7C((struct SoundSys2 *)c->fc, 0x743);
            c->f8 = 1;
            c->fa = 0x1f;
            break;
        }
    }
    if (c->f8 != 0) {
        c->fa = c->fa - 1;
        if (c->fa <= 0) {
            func_02028A7C((struct SoundSys2 *)c->fc, 0x76e);
            c->f8 = 0;
            c->fa = 0;
        }
    }
}
