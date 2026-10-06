/*
 * function: func_0218A8BC
 * address:  0x0218A8BC
 * packet:   pkt_ov021_0218A8BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Checks the background event in front of the player: shows its message when
 * the player stands at the event's centre tile, or when the tile behaviour is
 * one of 0x58..0x5B or 0xA3..0xA6 (range test spelled as the add of the
 * complement,
 * docs/idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md)
 * or func_021A3098 allows it.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB188  0x021AB188  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021A3098  0x021A3098  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
    u32 f1C;
    char pad20[0x04];
    u16 f24;
    u16 f26;
    char pad28[0x04];
    u32 f2C;
};

struct BgEvent {
    u16 msg;
    char pad02[0x06];
    u16 f8;
    struct {
        u16 x;
        u16 z;
        u16 w;
        u16 h;
    } rect;
};

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(u8 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *id, struct VecFx32 *out);
struct BigObj;
struct Desc;
extern u32 func_02188C98(u8 *p);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u32 func_0201296C(const struct BigObj *p);
struct Rec;
extern struct Rec *func_0216282C(struct Ctx *c, void *a, int *key, int mode);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021A3098(void *v);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D7C4(u8 *p);

int func_0218A8BC(struct FieldCtx *p)
{
    void *obj = func_0201210C(p->f4);
    void *id = func_02188CB4(obj);
    int pos[3];
    struct BgEvent *e;
    int a;
    u16 b;
    u32 cx;
    u16 *r;
    u32 cz;

    func_021A3038(id, (struct VecFx32 *)pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(obj), pos))) != 1)
        return 0;
    e = (struct BgEvent *)func_0216282C(p->fC, (void *)func_0201296C(p->f8), pos, 9);
    if (e == 0)
        return 0;
    if (e->f8 != 0)
        return 0;
    r = (u16 *)&e->rect;
    cz = r[1] + ((u32)r[3] >> 1);
    cx = e->rect.x + ((u32)r[2] >> 1);
    if (cx == (pos[0] >> 12) / 16 && cz == (pos[2] >> 12) / 16)
        return (int)func_02158768((int)p->f4, e->msg, 0, p->f0);
    a = func_021A3098(id);
    b = func_0216D7C4(func_021A3074(id));
    if (a != 0 || b == 0x58 || b == 0x59 || b == 0x5A || b == 0x5B || (u16)(b + 0xFF5D) <= 3)   /* b - 0xA3 */
        return (int)func_02158768((int)p->f4, e->msg, 0, p->f0);
    return 0;
}
