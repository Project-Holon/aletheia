/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov068_021B95A0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `adds r1, r7, #0` before the zero store to args->x0 is the store
 * written through the field just set (w->args->x0 = 0): the forwarded value
 * gets its own register. args->x0 = 0, *(int *)args = 0 and an inline
 * setter all store through r7 directly (452 B).
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B9850  0x021B9850  thumb  ov068
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0203101C  0x0203101C  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_021BAF5C  0x021BAF5C  thumb  ov068
 *   func_021BB0F8  0x021BB0F8  thumb  ov068
 *   func_021BB148  0x021BB148  thumb  ov068
 *   func_021B9950  0x021B9950  thumb  ov068
 *   func_021BA37C  0x021BA37C  thumb  ov068
 *   func_021BA734  0x021BA734  thumb  ov068
 *   func_021BA024  0x021BA024  thumb  ov068
 *   func_021B995C  0x021B995C  thumb  ov068
 *   func_021BA1C4  0x021BA1C4  thumb  ov068
 *   func_021BAD60  0x021BAD60  thumb  ov068
 *   ov067_id       0x00000043  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
} Args;

typedef struct {
    u8 pad0[0xd4];
    u8 xD4[0x10];
    u8 xE4[0x20];
    u8 x104[0x44];
    u8 x148[0x58];
    u8 x1A0[0x38];
    u8 x1D8[0x70];
    u8 x248[0xc];
    u32 font;
    u32 x258;
    u32 msg;
    u32 x260;
    u32 x264;
    u32 x268;
    Args *args;
} Work;

extern u8 ov067_id[];

typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern Work *func_0203159C(void *proc, u32 size, u32 heap);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void  func_021B9850(Work *p, u32 heap);
extern u32   func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32   func_0201C440(u32 heap);
extern u32   func_02027F60(u32 a, u32 b, u32 c, u32 d, u32 heap);
extern u32   func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern u32   func_0203101C(u32 a, u32 b, u32 c, u32 d);
extern u32   func_020120F4(u32 a);
extern u32   func_02012EBC(u32 a);
extern u32   func_0200873C(u32 a);
extern void  func_021BAF5C(u8 *p, u32 a);
extern void  func_021BB148(void *unused, u32 *p);
extern void  func_021BB0F8(u8 *p, Work *w, void (*cb)(void *, u32 *));
extern u32   func_021B9950(Work *p);
extern void  func_021BA37C(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3);
extern void  func_021BA734(u8 *p, u16 a1, u16 a2, Work *a3, u8 *src, u32 heap);
extern void  func_021BA024(u8 *p, u32 heap);
extern u32   func_021B995C(Work *p, u32 i);
extern void  func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);
extern void  func_021BAD60(u8 *p, u32 a, u32 b, u32 c, u32 s0, u32 s1, u32 s2, u16 s3);

int func_021B95A0(void *proc, int *seq, Args *args)
{
    Work *w;
    u32 t;

    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x1c, 0x21000);
    w = func_0203159C(proc, sizeof(Work), 0x1c);
    func_02082BCC(w, 0, sizeof(Work));
    w->args = args;
    w->args->x0 = 0;
    func_021B9850(w, 0x1c);
    w->font = func_0201D7EC(0x17, 0, 0, 0, 0x1c);
    w->x258 = func_0201C440(0x1c);
    w->x260 = func_02027F60(0, 0xd, w->font, w->x258, 0x1c);
    w->x264 = func_02027F60(3, 9, w->font, w->x258, 0x1c);
    w->msg = func_02045B38(0, 2, 0x1d, 0x1c);
    w->x268 = func_0203101C(0x1c, 0x1c, 0x20, 0x20);
    func_021BAF5C(w->x248, func_0200873C(func_02012EBC(func_020120F4(w->args->x4))));
    func_021BB0F8(w->xD4, w, func_021BB148);
    t = func_020120F4(w->args->x4);
    func_021BA37C(w->x104, func_021B9950(w), w->font, w->x258, w->msg, w->x260, t, 0x1c);
    func_021BA734(w->x148, 1, 2, w, w->x248, 0x1c);
    func_021BA024(w->xE4, 0x1c);
    func_021BA1C4(w->x1A0, func_021B995C(w, 0x11), w->font, w->msg, w->x268, w->x258, 0x1c);
    func_021BAD60(w->x1D8, func_021B995C(w, 0x12), w->font, w->msg, w->x268, w->x264, w->x258, 0x1c);
    return 1;
}
