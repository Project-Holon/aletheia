/*
 * function: func_021BA04C
 * address:  0x021BA04C
 * packet:   pkt_ov072_021BA04C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020355C4  0x020355C4  arm
 */

typedef unsigned short u16;

typedef struct {
    void *f0;
    void *f4;
    u16 f8;
    u16 fA;
    int pad[3];
} S;

extern void func_02082BCC(void *p, int v, int n);
extern void func_0204B404(void *a, void *b, int c);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Node;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *a, int b);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u8 func_020355C4(void);

void func_021BA04C(S *p, void *a, void *b)
{
    int z = 0;
    int one;

    func_02082BCC(p, 0, 0x18);
    p->f0 = a;
    p->f4 = b;
    p->f8 = 0x80;
    p->fA = 0x60;
    func_0204B404(a, &p->f8, 0);
    func_0204B404(p->f4, &p->f8, 0);
    func_0204B3DC(p->f0, 1);
    one = 1;
    func_0204B3DC(p->f4, 0);
    func_0204B84C(p->f0, 0);
    func_0204B800(p->f0, 0);
    func_0204B84C(p->f4, 2);
    func_0204B800(p->f4, 3);
    func_0204B92C(p->f4, 1);
    if (func_020355C4() == 0) {
        func_0204B3DC(p->f0, one);
    } else {
        func_0204B3DC(p->f0, z);
    }
}
