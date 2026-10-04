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

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_0215A5E4(void *a0);
extern void *func_0215A5DC(void *a0);
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02188CB4(unsigned char *p);
struct VecFx32;
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern int func_021627C8(u32, u32, V *, int);
extern u16 func_021A3050(u8 *p);
extern void *func_021618A0(void *p, int a1, int a2, int a3);
extern void func_0215897C(void *, void *);

int func_021B1E80(void *a, u32 b)
{
    void *o;
    int q;
    void *e;
    void *d;
    Ids ids;
    int i;
    u32 h, f;
    void *m;
    V pos;
    int id;
    int found;
    int k;
    u8 *tbl;

    o = func_0215A5F4((void *)b);
    q = ((int *)func_02158F58((int)o))[1];
    e = func_0215A5E4((void *)b);
    d = func_0215A5DC((void *)b);
    ids = d_021D93FC;
    h = func_02012844(e);
    f = func_0201296C(e);
    m = func_02188CB4((void *)q);
    func_021A3038(m, (struct VecFx32 *)&pos);
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
        func_0215897C(o, func_021618A0(d, q, 0xff, (int)tbl));
        return 1;
    }
    return 0;
}
