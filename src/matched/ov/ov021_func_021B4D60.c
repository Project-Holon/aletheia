/*
 * function: func_021B4D60
 * address:  0x021B4D60
 * packet:   pkt_ov021_021B4D60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: builds a 0x2C-byte work (save handles, the hand-off kind
 * at +0x24) and a 12-byte hand-off record, then launches overlay 0xAA
 * (ov170) over them through func_02014840 with the func_021B4D14 callback
 * and parks the task in the script's slot.  Same shape as the ov010
 * pending func_0215C7E0.
 *
 * The work pointer is written back into the first parameter (c): with a
 * separate local, c/work and the save handle w swap r4/r5 whatever the
 * declaration order (docs/idioms/reassigning-a-parameter-to-the-callee-
 * result-keeps-its-register.md).
 *
 * Blocker (MATCH, every concrete byte right, 24 of 25 sites resolved): the
 * pool word 0x000000AA (ov170_id, +0xF0) has no witness.  It is the
 * overlay-id argument (r2) of func_02014840, which is not in
 * OVERLAY_ID_CONSUMERS; func_02014840 (EXACT, arm9) stores its a2 as
 * p[2] of the item func_020122C0 creates, the same shape as the
 * func_02012444 case ov000 func_021542C0's header describes.  Adding
 * 0x02014840 with register 2 to OVERLAY_ID_CONSUMERS (integrator's call,
 * after reading the item's state machine) would resolve it.  ov021 holds
 * one other 0xAA pool word (0x021D5598), yet match.py still reports no
 * witness: a small overlay-id value resolves only through that consumer
 * table, so no cut helps.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0200BBFC  0x0200BBFC  thumb
 *   func_02014840  0x02014840  thumb
 *   func_02030734  0x02030734  arm
 *   func_021B4D14  0x021B4D14  thumb  ov021
 *   d_021DE220     0x021DE220  data  a1
 *   ov170_id       0x000000AA  data  a1
 *   d_021EF78C     0x021EF78C  data  ov170  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const char d_021DE220[];
extern char ov170_id[];
extern const u8 d_021EF78C[];

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern u32 func_02159AE8(void *c, void *vm);
extern u32 func_02159B10(void *c, void *vm);
extern void func_0215897C(void *p, void *v);
extern void *func_020120F4(void *sys);
extern void *func_0201210C(void *sys);
extern void *func_02012EBC(void *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CA38(void *p);
extern u32 func_0200873C(void *p);
extern u32 func_0201293C(void *p);
extern u32 func_02012934(void *p);
extern u32 func_0201292C(void *p);
extern u32 func_02012944(void *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BAF4(void *p, int n);
extern u32 func_0200BBFC(void *p, int n);
extern void *func_02014840(void *sys, void *x, u32 ovId, const void *proc, void *work, void *cb, void *rec);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern void func_021B4D14(void);

int func_021B4D60(u32 *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    void *y;
    void *z;
    u32 r7;
    u32 kind;
    u32 *h;
    void *s;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_02012EBC(w);
    y = func_0200CA1C(w);
    z = func_0201210C(sys);
    r7 = func_02159AE8(c, vm);
    kind = func_02159B10(c, vm);
    c = func_02030734(4, 0x2c, 0, d_021DE220, 0x7c);
    c[0] = (u32)w;
    c[1] = func_0201293C(w);
    c[2] = func_02012934(w);
    c[3] = func_0201292C(w);
    c[4] = func_02012944(w);
    c[6] = func_0200873C(x);
    c[7] = func_0200CA38(y);
    c[9] = kind;
    c[5] = 0;
    if (kind == 4) {
        s = func_0200BAC8(x);
        c[2] = func_0200BAF4(s, 4);
        c[5] = func_0200BBFC(s, 3);
    }
    h = func_02030734(4, 0xc, 0, d_021DE220, 0x90);
    h[0] = (u32)w;
    h[1] = r7;
    h[2] = (u32)c;
    func_0215897C(slot, func_02014840(sys, z, (u32)ov170_id, d_021EF78C, c, (void *)func_021B4D14, h));
    return 1;
}
