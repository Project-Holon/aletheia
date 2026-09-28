/*
 * function: func_0215C7E0
 * address:  0x0215C7E0
 * packet:   pkt_ov010_0215C7E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the func_0215C7C4 callback and
 * parks the result in the script's slot.
 *
 * MATCH, bytes exact. Blockers: func_0215C7C4 is an unlabelled leaf (no label class), ov136_id (0x88) and d_021C78A4 have no witness.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02014840  0x02014840  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215C7C4  0x0215C7C4  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov136_id       0x00000088  data
 *   d_021C78A4     0x021C78A4  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_020120F4(void *sys);
extern void *func_0201210C(void *sys);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern u32 func_02159AE8(void *c, void *vm);
extern void *func_02014840(void *sys, void *x, u32 ovId, const void *proc, void *work, void *cb, void *rec);
extern void func_0215897C(void *p, void *v);
extern void func_0215C7C4(void);
extern const char d_021728F0[];
extern const u8 d_021C78A4[];
extern u8 ov136_id[];

int func_0215C7E0(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 *a;
    u32 *b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = func_02030734(4, 8, 0, d_021728F0, 0x14F);
    b = func_02030734(4, 8, 0, d_021728F0, 0x150);
    a[0] = (u32)w;
    b[0] = (u32)a;
    b[1] = func_02159AE8(c, vm);
    func_0215897C(slot, func_02014840(sys, x, (u32)ov136_id, d_021C78A4, a, (void *)func_0215C7C4, b));
    return 1;
}
