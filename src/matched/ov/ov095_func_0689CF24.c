/*
 * function: func_0689CF24
 * address:  0x0689CF24
 * packet:   pkt_ov095_0689CF24
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the j-side element pointer is a named local `(u16 *)p + j` (indexed as
 * halfwords 12 and 27), which keeps p+2j live in r6 across the func_0689CFE0
 * call; array indexing on j recomputes it after the call (26 differing words).
 *
 * symbols:
 *   func_0689CFD0  0x0689CFD0  thumb
 *   func_0689CFE0  0x0689CFE0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

u16 func_0689CFD0(int ctx, u32 id, int k);
int func_0689CFE0(int k);

void func_0689CF24(S *p, int ctx)
{
    u32 i;
    u32 j;
    u32 tid;
    u16 ta;
    u16 td;
    u16 *pj;

    if (p->n > 1) {
        for (i = 0; i < p->n; i++)
            p->d[i] = func_0689CFD0(ctx, p->id[i], 1);
        for (i = 0; i < p->n; i++) {
            for (j = i + 1; j < p->n; j++) {
                pj = (u16 *)p + j;
                if (pj[27] > p->d[i] || (pj[27] == p->d[i] && func_0689CFE0(2))) {
                    tid = p->id[i];
                    ta = p->a[i];
                    td = p->d[i];
                    p->id[i] = p->id[j];
                    p->a[i] = pj[12];
                    p->d[i] = pj[27];
                    p->id[j] = tid;
                    pj[12] = ta;
                    pj[27] = td;
                }
            }
        }
    }
}
