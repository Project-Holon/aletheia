/*
 * function: func_021C5D10
 * address:  0x021C5D10
 * packet:   pkt_ov021_021C5D10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021C5C64  0x021C5C64  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AA180  0x021AA180  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021C5DF4  0x021C5DF4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    void *f18;
    void *f1C;
    s16 f20[3];
    u16 pad26;
    u32 f28;
    u8 pad2C[8];
    VecFx32 f34;
    VecFx32 f40;
    u8 pad4C[0xC];
    u8 f58;
    u8 f59;
    u16 f5A;
    u8 pad5C[8];
    void *f64;
} Work;

struct Ctx;
struct Desc;
struct Obj;
struct Self;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, u32 n);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02188CE8(u8 *p);
extern u32 func_02012F2C(void *a);
extern void *func_02188C7C(u8 *q);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3038(void *id, VecFx32 *out);
extern u32 func_021A34EC(void *id);
extern int func_021C5C64(void *unused, u8 *a, VecFx32 *out);
extern int func_021AA900(struct Self *self, short *pos);
/* 021AA180 reads a mode in r1 (its own file: (ctx, mode)); this caller
 * passes none, leaving r1 = the f59 flag just stored.  Declaring the second
 * argument makes mwcc reload f59 (+4 bytes). */
extern void *func_021AA180(void *ctx);
extern void func_0216D9A0(void *o);
extern void func_021C5DF4(void);

void *func_021C5D10(u8 *a, void *b)
{
    void *task;
    Work *w;

    task = func_020122C0(b, 0, func_021C5DF4, sizeof(Work));
    w = func_020124E8(task);
    func_02082BCC(w, 0, sizeof(Work));
    w->f0 = b;
    w->f8 = a;
    w->f4 = func_020120F4(b);
    w->fC = func_02188CE8(w->f8);
    w->f10 = func_02012F2C(w->f4);
    w->f14 = func_02188C7C(w->f8);
    w->f18 = func_02188CB4(a);
    w->f1C = func_021A3074(w->f18);
    w->f58 = func_0216D5F8(w->f1C);
    func_021A3038(w->f18, &w->f34);
    w->f28 = func_021A34EC(w->f18);
    if (func_021C5C64(w->f4, w->f8, &w->f40) == 0)
        w->f5A = 1;
    w->f20[0] = (w->f40.x >> 4) / 4096;
    w->f20[1] = (w->f40.y >> 4) / 4096;
    w->f20[2] = (w->f40.z >> 4) / 4096;
    if (func_021AA900(w->fC, w->f20))
        w->f59 = 1;
    else
        w->f59 = 0;
    w->f64 = func_021AA180(w->fC);
    func_0216D9A0(w->f14);
    return task;
}
