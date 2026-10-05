/*
 * function: func_021E8568
 * address:  0x021E8568
 * packet:   pkt_ov177_021E8568
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note 2026-10-02: only prologue scheduling (orig spills r2,r3 before ldr r5 heap, mine
 *   after) and tail ldr r3/str order differ (10 lines). Tried u8 param, local copies,
 *   decl order, init-at-decl, heap types.
 *
 * note 2026-10-05: re-checked the listing: c and d are spilled (str r2,[sp,#0xc]; str r3,[sp,#0x10]) BEFORE
 * the heap load (ldr r5,[sp,#0x30]); ours spills r3 then r2 after the heap load, and loads r3 for the last call
 * above the w->fc store (orig after). Both are scheduler order only, 20 bytes. No source form tried this
 * round changed it (arguments are used in place, no stand-in casts). Still DIFF.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021E8DD4     0x021E8DD4  data
 */

typedef struct {
    char           pad0[4];
    int            f4;
    char           pad1[4];
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad2[3];
    int            f28;
    int            f2c;
} S;

extern unsigned char d_021E8DD4[];

extern void *func_02030734(int, int, int, void *, int);
extern void  func_02082BCC(void *, int, int);
extern int   func_0201C440(int);
extern int   func_020457B0(int, int);
extern int   func_020450F0(int, int, int, int, int, int, int);
extern int   func_02045770(int);
extern void  func_02043B5C(int, int);
extern void  func_02045334(int);
extern void  func_02045374(int);
extern int   func_02045730(int);
extern void  func_020409B4(int);
extern int   func_0203101C(int, int, int, int);
extern void  func_0201F73C(int, int, int, int);

S *func_021E8568(int a, int b, int c, int d, int e, int f, int heap)
{
    S *w;
    int h;

    w = func_02030734(heap, 0x40, 0, d_021E8DD4, 0x5e);
    func_02082BCC(w, 0, 0x40);
    w->f1c = 0xf;
    w->f4 = f;
    w->f28 = func_0201C440(heap);
    w->f2c = 3;
    w->f1e = heap;
    w->f18 = func_020457B0(0x300, heap);
    w->f14 = func_020450F0((unsigned char)a, 1, 0x13, 0x1e, 4, (unsigned char)b, 1);
    w->f20 = w->f14;
    w->f24 = 0;
    func_02043B5C(func_02045770(w->f14), (unsigned char)w->f1c);
    h = w->f14;
    func_02045334(h);
    func_02045374(h);
    func_020409B4(func_02045730(h));
    w->fc = func_0203101C(heap, heap, 1, 0x20);
    func_0201F73C(w->f14, 0, d, (unsigned char)c);
    return w;
}
