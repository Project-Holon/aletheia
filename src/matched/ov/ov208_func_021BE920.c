/*
 * function: ov208_func_021BE920
 * address:  0x021BE920
 * packet:   pkt_ov208_021BE920
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4        0x020490F4  arm
 *   func_02049BDC        0x02049BDC  arm
 *   func_02049238        0x02049238  arm
 *   func_0204384C        0x0204384C  arm
 *   func_02043814        0x02043814  arm
 *   func_020437AC        0x020437AC  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_0201C724        0x0201C724  thumb
 *   func_02045808        0x02045808  arm
 *   ov208_func_021BE9CC  0x021BE9CC  thumb
 *   data_021C84F4        0x021C84F4  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *h);
struct Bmp;
struct Obj020437AC;
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
struct MsgBank;
struct U16Vec;
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
extern void ov208_func_021BE9CC(struct Ov208Icon *p);

struct Ov208PalTbl {
    u32 v[5];
};

extern const struct Ov208PalTbl data_021C84F4;

void ov208_func_021BE920(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->fc < 0 || p->fc >= 5)
        return;
    h = func_020490F4(0x9f, p->heap);
    pal = data_021C84F4;
    func_02049BDC(h, 4, 4, pal.v[p->fc] << 5, 0x1a0, 0x20, p->heap);
    func_02049238(h);
    h = func_0204384C(0x9f, 0xe, 0, p->heap);
    func_02043814(h, (const struct Bmp *)p->f18);
    func_020437AC(h);
    s = (u32)func_02045EC0((struct MsgBank *)p->f24, p->fc + 0xb2);
    func_0201C724(p->f2c, p->f18, 0x18, 5, s, p->f4, 0x3dc0);
    func_02045808((struct U16Vec *)s);
    p->f30 = 1;
    ov208_func_021BE9CC(p);
}
