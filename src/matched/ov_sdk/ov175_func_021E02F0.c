/*
 * function: sciReportAddIntValue
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
 *   sciSerializeInt16   0x021E0504  arm  ov175
 *   sciSerializeInt32   0x021E054C  arm  ov175
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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *sciSerializeInt16(u8 *dst, unsigned int v);
extern u8 *sciSerializeInt32(u8 *dst, u32 v);

int sciReportAddIntValue(Obj *o, int a, int b)
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
        sciSerializeInt16((u8 *)((char *)o->f124 + o->f4), (short)o->h8);
    } else if (f0 == 4) {
        n->h28++;
        n->w40 += 8;
        o->h8++;
        sciSerializeInt16((u8 *)((char *)o->f124 + o->f4), (short)o->h8);
    }
    sciSerializeInt16((u8 *)((char *)o->f124 + o->f120), (short)a);
    o->f120 += 2;
    sciSerializeInt16((u8 *)((char *)o->f124 + o->f120), (short)0);
    o->f120 += 2;
    sciSerializeInt32((u8 *)((char *)o->f124 + o->f120), (int)b);
    o->f120 += 4;
    return 0;
}

