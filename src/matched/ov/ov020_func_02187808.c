/*
 * function: func_02187808
 * address:  0x02187808
 * packet:   pkt_ov020_02187808
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback (0x28-byte work area), then field setup and a
 * state-set call. a1 must be u8: with int a1 (a2 either int or u8) the
 * scheduler hoists the spilled a1 reload above the strb of a2.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124EC  0x020124EC  thumb
 *   func_0202E8B8  0x0202E8B8  thumb
 *   func_021876E0  0x021876E0  thumb  ov020
 *   func_02187C20  0x02187C20  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *p;        /* 0x00 */
    int f04;        /* 0x04 */
    u16 f08;        /* 0x08 */
    int f0c;        /* 0x0c */
    int f10;        /* 0x10 */
    u8 f14;         /* 0x14 */
    u8 f15;         /* 0x15 */
    u8 pad16[10];
    int f20;        /* 0x20 */
    int f24;        /* 0x24 */
} Work02187808;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
u32 *func_020124EC(struct Obj *p);
u8 func_0202E8B8(int x);
int func_021876E0(void *unused, int *s, char *o);
void func_02187C20(Work02187808 *w, void *h, int state);

void *func_02187808(void *p, u8 a1, u8 a2)
{
    void *r0v = func_020122C0(p, 0, func_021876E0, 0x28);
    Work02187808 *w = func_020124E8(r0v);
    void *h = func_020124EC(r0v);

    w->p = p;
    w->f04 = 0;
    w->f08 = 4;
    w->f0c = 1;
    w->f10 = 0;
    w->f14 = a2;
    w->f15 = func_0202E8B8(a1);
    w->f20 = 0;
    w->f24 = 0;
    func_02187C20(w, h, 0);
    return r0v;
}
