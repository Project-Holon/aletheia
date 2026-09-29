/*
 * function: func_021ADF94
 * address:  0x021ADF94
 * packet:   pkt_ov021_021ADF94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D92E0     0x021D92E0  data  a1
 *   d_021D92E8     0x021D92E8  data  a4
 */

typedef unsigned char u8;

typedef struct Tb { u8 b[8]; } Tb;
typedef struct V { int x, y, z; } V;
typedef struct Arg { int a; V v; } Arg;

extern Tb d_021D92E0;
extern u8 d_021D92E8[];

extern int func_021ABEA0(int a, int b);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern void func_021ABFA8(int a, u8 *b, int c, int d, Arg *e, int f);

void func_021ADF94(int a, V *b, int c, int d)
{
    Tb t = d_021D92E0;
    Arg s;
    int v;
    int r;

    s.a = func_021ABEA0(a, 13);
    s.v = *b;
    v = (t.b + d * 4)[c];
    if (v != 0) {
        r = func_0209C95C(0x3f000000, func_0209BDBC(v << 12));
    } else {
        r = func_0209CB8C(func_0209BDBC(v << 12), 0x3f000000);
    }
    s.v.z +=func_0209C494(r);
    func_021ABFA8(a, d_021D92E8, 0, 0, &s, 0);
}
