/*
 * file:     unit_021B23E0_p03.c
 * unit:     yes
 * function: func_021B279C, func_021B2848
 * address:  0x021B279C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B3AF0  0x021B3AF0  data  ov013  a1
 *   d_021B3AF5  0x021B3AF5  data  ov013  a1
 *   d_021B60D8 0x021B60D8 data ov013 a4
 */
typedef unsigned char u8;

typedef struct Q {
    int f0;
    u8 b4;
    u8 b5;
    u8 pad[2];
    int f8;
    int fC;
} Q;

typedef struct Msg {
    unsigned int magic;
    u8 b4, b5, b6, b7, b8, b9, b10, b11;
    int fC;
} Msg;

int func_021B279C(u8 *o, Q *q);
int func_021B2848(u8 *o, Msg *p, int n);
extern u8 d_021B3AF0[];
extern u8 d_021B3AF5[];
extern u8 d_021B60D8;


int func_021B279C(u8 *o, Q *q)
{
    q->b5 = o[0xb];
    if (o[4] == 0xff) {
        if (o[6] == 0) {
            q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
        }
        return d_021B3AF0[o[6]];
    }
    if (o[4] == 0) {
        if (o[6] == 0) {
            if (q->fC == 1) {
                q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
                return 7;
            }
            if (q->fC == 5)
                return 9;
            return 12;
        }
        return d_021B3AF5[o[6]];
    }
    return 12;
}

/*
 * lever: Returning zero keeps the clearing value in r0 and frees r2 for byte loads.
 */
int func_021B2848(u8 *o, Msg *p, int n)
{
    p->magic = 0x5f564354;
    p->b5 = 0x10;
    p->b6 = n;
    p->b8 = d_021B60D8;
    p->b9 = o[4];
    p->b10 = 0;
    p->b11 = d_021B60D8;
    p->fC = 0;
    return 0;
}
