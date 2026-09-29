/*
 * function: func_021BAE9C
 * address:  0x021BAE9C
 * packet:   pkt_ov072_021BAE9C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Pos;

typedef struct {
    int obj;
    int f4;
} W;

extern int func_021BA774(int a, int i);
extern void func_02082BCC(void *p, int v, int n);
extern int func_0204B294(int a, int b, int c, int d, Pos *pos, int f, u16 g);
extern void func_0204B84C(int obj, int v);
extern void func_0204B800(int obj, int v);
extern void func_0204B878(int obj, int v);
extern void func_0204B92C(int obj, int v);
extern void func_0204B3DC(int obj, int v);

void func_021BAE9C(W *p, int a, int b, int c, int s0, int s1, u16 s2)
{
    Pos pos;

    func_02082BCC(p, 0, 8);
    p->f4 = a;
    func_02082BCC(&pos, 0, 8);
    if (a != 0) {
        pos.x = func_021BA774(a, 2);
        pos.y = func_021BA774(a, 3);
    }
    p->obj = func_0204B294(b, c, s1, s0, &pos, 0, s2);
    func_0204B84C(p->obj, 2);
    func_0204B800(p->obj, 2);
    func_0204B878(p->obj, 6);
    func_0204B92C(p->obj, 1);
    if (a == 0) {
        func_0204B3DC(p->obj, 0);
    }
}
