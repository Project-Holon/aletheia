/*
 * function: func_02057B10
 * address:  0x02057B10
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Angle {
    int _00;
    short _04;
};

struct Src {
    char _00[0x14];
    struct Angle *_14;
};

struct Obj {
    char _00[0x34];
    short _34;
};

void func_02057B10(struct Obj *o, struct Src *s, int t)
{
    short cur;

    cur = s->_14->_04;
    o->_34 = cur + (cur - 0x1000) * (t - 0xFF) / 255;
}
