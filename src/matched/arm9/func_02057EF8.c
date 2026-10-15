/*
 * function: SPL_EMITTER_LerpVec
 * address:  0x02057EF8
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef int fx32;
typedef long long fx64;

struct A {
    fx32 x;
    fx32 y;
    fx32 z;
    short w;
};

struct B {
    fx32 _00;
    fx32 _04;
    fx32 _08;
    fx32 _0C;
    fx32 _10;
};

static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800) >> 12);
}

void SPL_EMITTER_LerpVec(struct A *a, struct B *b)
{
    b->_08 = b->_08 + FX_Mul(a->w, a->x - b->_08);
    b->_0C = b->_0C + FX_Mul(a->w, a->y - b->_0C);
    b->_10 = b->_10 + FX_Mul(a->w, a->z - b->_10);
}
