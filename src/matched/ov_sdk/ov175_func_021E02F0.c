/*
 * function: func_021E02F0
 * address:  0x021E02F0
 * packet:   pkt_ov175_021E02F0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E0504   0x021E0504  arm  ov175
 *   func_021E054C   0x021E054C  arm  ov175
 */
typedef struct Node {
    char _0[0x24];
    unsigned short h24;
    unsigned short h26;
    unsigned short h28;
    char _2a[0x38 - 0x2a];
    int w38;
    int w3c;
    int w40;
} Node;

typedef struct Obj {
    int f0;
    int f4;
    unsigned short h8;
    char _a[0x120 - 0xa];
    int f120;
    Node *f124;
} Obj;

extern void func_021E0504(void *p, short v);
extern void func_021E054C(void *p, int v);

int func_021E02F0(Obj *o, int a, int b)
{
    int f0 = o->f0;
    Node *n = o->f124;

    if (f0 == 2) {
        n->h24++;
        n->w38 += 8;
    } else if (f0 == 3) {
        n->h26++;
        n->w3c += 8;
        o->h8++;
        func_021E0504((char *)o->f124 + o->f4, o->h8);
    } else if (f0 == 4) {
        n->h28++;
        n->w40 += 8;
        o->h8++;
        func_021E0504((char *)o->f124 + o->f4, o->h8);
    }
    func_021E0504((char *)o->f124 + o->f120, (short)a);
    o->f120 += 2;
    func_021E0504((char *)o->f124 + o->f120, 0);
    o->f120 += 2;
    func_021E054C((char *)o->f124 + o->f120, b);
    o->f120 += 4;
    return 0;
}

