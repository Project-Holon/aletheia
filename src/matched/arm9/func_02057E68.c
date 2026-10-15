/*
 * function: SPL_EMITTER_EvalCurve
 * address:  0x02057E68
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 */

struct Curve {
    short _00;
    short _02;
    short _04;
    unsigned char _06;
    unsigned char _07;
};

struct Src {
    int _00;
    struct Curve *_04;
};

struct Obj {
    char _00[0x34];
    short _34;
};

void SPL_EMITTER_EvalCurve(struct Obj *o, struct Src *s, int t)
{
    struct Curve *cv;
    int b0;
    int b1;

    cv = s->_04;
    b0 = cv->_06;
    b1 = cv->_07;
    if (t < b0) {
        o->_34 = cv->_00 + t * (cv->_02 - cv->_00) / b0;
        return;
    }
    if (t < b1) {
        o->_34 = cv->_02;
        return;
    }
    o->_34 = cv->_04 + (t - 0xFF) * (cv->_04 - cv->_02) / (0xFF - b1);
}
