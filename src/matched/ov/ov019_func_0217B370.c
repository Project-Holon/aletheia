/*
 * function: func_0217B370
 * address:  0x0217B370
 * packet:   pkt_ov019_0217B370
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_02180044  0x02180044  data  a4
 *   d_02180048  0x02180048  data  a4
 *   d_0218004C  0x0218004C  data  a4
 */

typedef int (*fn_t)(char *, unsigned char *, int, unsigned char *);
struct ent { fn_t f; int a; int b; };

extern struct ent d_02180044[];
extern struct ent d_02180048[];
extern struct ent d_0218004C[];

int func_0217B370(char *base, unsigned char *p, int r2)
{
    int res = 1;
    fn_t fn;

    switch (p[0xa]) {
    case 0:
        fn = d_02180044[p[8]].f;
        break;
    case 1:
        fn = d_02180048[p[8]].f;
        break;
    case 2:
        fn = d_0218004C[p[8]].f;
        break;
    }
    if (fn != 0) {
        res = fn(base, p, r2, p + 0xb);
    }
    if (res == 1) {
        p[0xb] = 0;
        p[0xa] = p[0xa] + 1;
        if (p[0xa] > 2) {
            if (p[8] == 2) {
                return 0;
            }
            p[0xa] = 0;
            p[8] = p[9];
            p[9] = 0;
        }
    }
    return 1;
}
