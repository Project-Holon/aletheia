/*
 * function: func_0220461C
 * address:  0x0220461C
 * packet:   pkt_ov094_0220461C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    the table extern is `const` (non-const put the cnt store before the address add)
 *
 * symbols:
 *   func_02040618  0x02040618  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 *   d_0220A46C     0x0220A46C  data  ov094  a4
 */
typedef struct Ent {
    int v0;
    int v1;
} Ent;

typedef struct Ctx {
    char *main;
    int idx;
    int set;
    int cnt;
} Ctx;

extern const Ent d_0220A46C[][2];
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0220687C(char *p, int v);

void func_0220461C(int a0, Ctx *c)
{
    int i;

    c->cnt = c->cnt - 1;
    if (c->cnt == 0) {
        c->cnt = 2;
        func_02040618(5, 0, d_0220A46C[c->set][c->idx].v0);
        i = c->idx;
        c->idx = i + 1;
        func_02040618(5, 3, d_0220A46C[c->set][i].v1);
        if (c->idx >= 2)
            func_0220687C(c->main, a0);
    }
}
