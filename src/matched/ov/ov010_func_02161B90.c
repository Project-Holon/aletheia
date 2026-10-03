/*
 * function: func_02161B90
 * address:  0x02161B90
 * packet:   pkt_ov010_02161B90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012138  0x02012138  thumb
 *   func_02161CDC  0x02161CDC  thumb  ov010
 *   func_02161D18  0x02161D18  thumb  ov010
 *   func_0216570C  0x0216570C  thumb  ov010
 *   func_02161BF8  0x02161BF8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x1C];       /* 0x08 */
} Node;

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02012138(void *p);
extern void func_02161CDC(void *a, void *b, u8 c, u8 d);
extern void func_02161D18(void *a, void *b, u8 c, u8 d);
extern void func_0216570C(void);
extern int func_02161BF8(void *a0, int *state, struct Obj *o);

void *func_02161B90(void *p, void *a1, int kind, int sub, int flag)
{
    void *h;
    Node *n;

    h = func_020122C0(p, a1, func_02161BF8, 0x24);
    n = func_020124E8(h);
    func_02082BCC(n, 0, 0x24);
    n->f00 = p;
    n->f04 = func_02012138(p);
    if (flag != 0)
        func_02161CDC(n->f08, p, kind, sub);
    else
        func_02161D18(n->f08, p, kind, sub);
    if (kind == 3)
        func_0216570C();
    return h;
}
