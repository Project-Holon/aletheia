/*
 * function: func_021DE9BC
 * address:  0x021DE9BC
 * packet:   pkt_ov175_021DE9BC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolved: the ov175 region hint on d_021E3F04 was contested (another
 * overlapping overlay starts a data object there); un-hinted, sole-ref/data
 * picks the unique overlay start, so all 19 sites resolve and the 280 bytes
 * are exact.
 *
 * symbols:
 *   func_02182AC0   0x02182AC0  arm
 *   func_02182CF0   0x02182CF0  arm
 *   func_021DE26C   0x021DE26C  arm  ov175
 *   func_021DE184   0x021DE184  arm  ov175
 *   d_021E3DF8      0x021E3DF8  data  ov175
 *   d_021E3EFC      0x021E3EFC  data  ov175
 *   d_021E3F04      0x021E3F04  data  a4
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
typedef unsigned int   u32;
extern void func_021DE26C(u32 ctx, u32 *arr, int n);
extern void func_021DE184(u32 ctx, u32 *arr, int n);
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
    func_021DE26C((u32)o, (u32 *)s->f24, s->f28);
    func_02182CF0(o->f18, d_021E3DF8, d_021E3F3C, s->f2c);
    func_021DE184((u32)o, (u32 *)s->f4, s->f8);
    return 0;
}
