/*
 * function: func_021CF498
 * address:  0x021CF498
 * packet:   pkt_ov021_021CF498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a row of the 0x25-entry table at 0x021DB4FC (0x14 bytes each) and calls its
 * builder.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0203038C  0x0203038C  arm
 *   func_021CF564  0x021CF564  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    u32 (*fn)(u32, void *, u32);   /* 0x00 */
    u32 f04;                       /* 0x04 */
    int f08;                       /* 0x08 */
    u32 f0c;                       /* 0x0C */
    u32 f10;                       /* 0x10 */
} Ent;

typedef struct Ctx {
    u32 f00;
    u32 f04;
    void *f08;
} Ctx;

extern Ent d_021DB4FC[];

struct Evt;
struct Obj;
extern void *func_02188C80(void *p);
extern u32  func_0203038C(u32 a);
extern void func_021CF564(Ctx *c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020124E8(struct Obj *p);

void func_021CF498(Ctx *c, u32 x, int idx)
{
    u32 r;
    u32 y;
    void *p = c->f08;

    y = (u32)func_02188C80(p);

    if (idx >= 0x25) {
        idx = 0;
    }
    if (func_0203038C(0x15) < d_021DB4FC[idx].f10) {
        idx = 7;
    }
    if (d_021DB4FC[idx].f08 != -1) {
        func_021CF564(c);
    }
    r = d_021DB4FC[idx].fn(y, p, d_021DB4FC[idx].f0c);
    func_02012374((struct Evt *)x, (struct Evt **)r);
    c->f00 = (u32)func_020124E8((struct Obj *)r);
    c->f04 = d_021DB4FC[idx].f04;
}
