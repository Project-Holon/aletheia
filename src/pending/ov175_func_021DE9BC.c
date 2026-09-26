/*
 * function: func_021DE9BC
 * address:  0x021DE9BC
 * packet:   pkt_ov175_021DE9BC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocker: one site, d_021E3F04, is capped at `sole-ref` because its ov175
 * hint is contested (another overlapping overlay starts a data object there).
 * The other eight literal addresses resolve; bytes are otherwise exact
 * (compiled 280 == original 280).  --suggest-split cannot help: the site's
 * only witness is this range's own pool word.  The four callees in other
 * overlays resolve as `label`/`sdk`/`matched`.
 *
 * symbols:
 *   func_02182AC0   0x02182AC0  arm
 *   func_02182CF0   0x02182CF0  arm
 *   func_021DE26C   0x021DE26C  arm  ov175
 *   func_021DE184   0x021DE184  arm  ov175
 *   d_021E3DF8      0x021E3DF8  data  ov175
 *   d_021E3EFC      0x021E3EFC  data  ov175
 *   d_021E3F04      0x021E3F04  data  ov175
 *   d_021E3F0C      0x021E3F0C  data  ov175
 *   d_021E3F14      0x021E3F14  data  ov175
 *   d_021E3F1C      0x021E3F1C  data  ov175
 *   d_021E3F20      0x021E3F20  data  ov175
 *   d_021E3F30      0x021E3F30  data  ov175
 *   d_021E3F3C      0x021E3F3C  data  ov175
 */
typedef struct S {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
} S;

typedef struct O {
    char _0[8];
    S *f8;
    char _c[0x18 - 0xc];
    void *f18;
} O;

extern void func_02182AC0(void *log, void *a, void *b, int v);
extern void func_02182CF0(void *log, void *a, void *b, int v);
extern void func_021DE26C(O *o, int a, int b);
extern void func_021DE184(O *o, int a, int b);
extern char d_021E3DF8[];
extern char d_021E3EFC[];
extern char d_021E3F04[];
extern char d_021E3F0C[];
extern char d_021E3F14[];
extern char d_021E3F1C[];
extern char d_021E3F20[];
extern char d_021E3F30[];
extern char d_021E3F3C[];

int func_021DE9BC(O *o)
{
    S *s = o->f8;

    func_02182AC0(o->f18, d_021E3DF8, d_021E3EFC, s->f0);
    if (s->fc) {
        func_02182AC0(o->f18, d_021E3DF8, d_021E3F04, s->fc);
    }
    if (s->f10) {
        func_02182AC0(o->f18, d_021E3DF8, d_021E3F0C, s->f10);
    }
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F14, s->f14);
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F1C, s->f18);
    if (s->f1c) {
        func_02182AC0(o->f18, d_021E3DF8, d_021E3F20, s->f1c);
    }
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F30, s->f20);
    func_021DE26C(o, s->f24, s->f28);
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F3C, s->f2c);
    func_021DE184(o, s->f4, s->f8);
    return 0;
}
