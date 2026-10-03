/*
 * function: func_021767F0
 * address:  0x021767F0
 * packet:   pkt_ov011_021767F0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   d_02176FD8     0x02176FD8  data  ov011  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad[0x86];
    u16 v : 3;
    u8  pad2[0x902 - 0x88];
    u8  f902;
} Rec;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
} Cs;

extern Cs   d_02176FD8;
extern Rec *func_02158344(void *p);
struct BigObj;
extern u8 func_02012B58(const struct BigObj *p);

void func_021767F0(void *a, void *b, Cs *c)
{
    Rec *r;
    int d;

    r = func_02158344(a);
    if (r == 0 || r->v == func_02012B58(b)) {
        d = 0;
    } else {
        d = r->v - func_02012B58(b);
        if (d < 0) {
            d += r->f902;
        }
    }
    *c = d_02176FD8;
    c->w0 += d << 22;
}
