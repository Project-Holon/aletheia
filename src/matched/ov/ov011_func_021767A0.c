/*
 * function: func_021767A0
 * address:  0x021767A0
 * packet:   pkt_ov011_021767A0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012B58  0x02012B58  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B80  0x02012B80  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u8  pad[0x86];
    u16 v : 3;
} Rec;

extern int  func_02012B58(void *p);
extern Rec *func_02158344(void *p);
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern int  func_02012B80(void *p);

u8 func_021767A0(void *a, void *b)
{
    u8 x;
    u8 y;
    Rec *r;

    x = func_02012B58(b);
    r = func_02158344(a);
    if (func_0200FB24()) {
        y = func_02012B80(b);
        if (y == x) {
            return 4;
        }
        return y;
    }
    if (r != 0) {
        if (r->v == x) {
            return 4;
        }
        return r->v;
    }
    return 4;
}
