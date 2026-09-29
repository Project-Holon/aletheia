/*
 * function: func_021B1E80
 * address:  0x021B1E80
 * packet:   pkt_ov021_021B1E80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B1E80  0x021B1E80  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021627C8  0x021627C8  thumb  ov010
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   d_021D93FC     0x021D93FC  data   a2
 *   d_021D9404     0x021D9404  data   a4
 *   d_021D940C     0x021D940C  data   a4
 *   d_021D9414     0x021D9414  data   a4
 *   d_021D941C     0x021D941C  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } V;
typedef struct { u16 v[4]; } Ids;

extern Ids d_021D93FC;
extern u8 d_021D9404[];
extern u8 d_021D940C[];
extern u8 d_021D9414[];
extern u8 d_021D941C[];

extern u32 func_0215A5F4(u32);
extern int *func_02158F58(u32);
extern u32 func_0215A5E4(u32);
extern void *func_0215A5DC(u32);
extern u32 func_02012844(u32);
extern u32 func_0201296C(u32);
extern u32 func_02188CB4(int);
extern void func_021A3038(u32, V *);
extern int func_021627C8(u32, u32, V *, int);
extern int func_021A3050(u32);
extern void *func_021618A0(void *p, int a1, int a2, void *a3);
extern void func_0215897C(u32, void *);

int func_021B1E80(void *a, u32 b)
{
    u32 o;
    int q;
    u32 e;
    void *d;
    Ids ids;
    int i;
    u32 h, f, m;
    V pos;
    int id;
    int found;
    int k;
    u8 *tbl;

    o = func_0215A5F4(b);
    q = func_02158F58(o)[1];
    e = func_0215A5E4(b);
    d = func_0215A5DC(b);
    ids = d_021D93FC;
    h = func_02012844(e);
    f = func_0201296C(e);
    m = func_02188CB4(q);
    func_021A3038(m, &pos);
    for (i = 0; i < 4; i++) {
        id = ids.v[i];
        if (func_021627C8(h, f, &pos, id) != 0) {
            found = id;
            break;
        }
    }
    k = func_021A3050(m);
    if (k != found) {
        if (found == 0) {
            tbl = d_021D941C;
        } else if (found == 1) {
            tbl = d_021D9414;
        } else if (found == 2) {
            tbl = d_021D940C;
        } else if (found == 3) {
            tbl = d_021D9404;
        } else {
            return 0;
        }
        func_0215897C(o, func_021618A0(d, q, 0xff, tbl));
        return 1;
    }
    return 0;
}
