/*
 * function: UNION_ONESELF_RunPlayCategory
 * address:  0x0217B840
 * packet:   pkt_ov019_0217B840
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gUnionOneselfActionStart  0x02180074  data  a4
 *   gUnionOneselfActionMain  0x02180078  data  a4
 *   gUnionOneselfActionEnd  0x0218007C  data  a4
 */

typedef int (*fn_t)(char *, unsigned char *, int, unsigned char *);
struct ent { fn_t f; int a; int b; };

extern struct ent gUnionOneselfActionStart[];
extern struct ent gUnionOneselfActionMain[];
extern struct ent gUnionOneselfActionEnd[];

int UNION_ONESELF_RunPlayCategory(char *base, int r1)
{
    unsigned char *q = (unsigned char *)base + 0x2830;
    int res = 1;
    fn_t fn;

    switch (q[0x72]) {
    case 0:
        fn = gUnionOneselfActionStart[q[1]].f;
        break;
    case 1:
        fn = gUnionOneselfActionMain[q[1]].f;
        break;
    case 2:
        fn = gUnionOneselfActionEnd[q[1]].f;
        break;
    }
    if (fn != 0) {
        res = fn(base, q, r1, q + 0x73);
    }
    if (res == 1) {
        q[0x73] = 0;
        q[0x72] = q[0x72] + 1;
        if (q[0x72] > 2) {
            q[0x72] = 0;
            q[0x70] = q[1];
            q[1] = q[0x71];
            q[0x71] = 0;
        }
    }
    return q[1];
}
