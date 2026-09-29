/*
 * function: func_021D0C58
 * address:  0x021D0C58
 * packet:   pkt_ov021_021D0C58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; capped at MATCH by unlabelled callees with no witness
 * outside this range.  Two are arm9 leaves inside the EXACT* extent of
 * func_0200E5A0 (Ilias's region), so the overlay leaves are not filed:
 *   arm9 0x0200E5E4 (thumb), verified EXACT with
 *     u16 func_0200E5E4(void *a0)
 *     { return *(u16 *)((u8 *)a0 + 0x5c4) & 0x7f; }
 *   arm9 0x0200E608 (thumb, saves lr but unlabelled), verified EXACT with
 *     symbols func_02012EBC/020072CC/02012E4C/02012E7C/0200734C thumb,
 *     func_02030734/02082D44/0208459C/020307B0 arm, g_020A721C data a1:
 *     void func_0200E608(void *sys, void *src, u32 heap)
 *     {
 *         void *sv; void *buf;
 *         sv = func_02012EBC(sys);
 *         buf = func_02030734(heap, 0x1000, 0, g_020A721C, 0x99);
 *         func_020072CC(sv, 5, heap, buf, 0x1000);
 *         func_02082D44(src, buf, 0x5c8);
 *         func_02012E4C(sys, 5);
 *         for (;;) {
 *             if (func_02012E7C(sys, 5) == 2) break;
 *             func_0208459C(1, 1);
 *         }
 *         func_0200734C(sv, 5);
 *         func_020307B0(buf);
 *     }
 *   Overlay leaves still unlabelled (not filed): ov010 0x021578F0,
 *   ov021 0x021D1058 and 0x021D1080 (thumb).
 *
 * symbols:
 *   func_021576D0  0x021576D0  thumb  ov010
 *   func_021578A0  0x021578A0  thumb  ov010
 *   func_020362DC  0x020362DC  arm
 *   func_02157928  0x02157928  thumb  ov010
 *   func_021578F0  0x021578F0  thumb  ov010
 *   func_02157910  0x02157910  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_0200E5E4  0x0200E5E4  thumb
 *   func_0200E5A0  0x0200E5A0  thumb
 *   func_021D1058  0x021D1058  thumb  ov021
 *   func_021D1080  0x021D1080  thumb  ov021
 *   func_0200E608  0x0200E608  thumb
 *   func_02157938  0x02157938  thumb  ov010
 *   func_0203D210  0x0203D210  arm
 *   func_021D09D0  0x021D09D0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x7c];
    u32 f7c;
    u32 f80;
    u8 *f84;
    u16 *f88;
    int f8c;
} W;

extern u32 func_021576D0(W *w);
extern int func_021578A0(u32 p);
extern u32 func_020362DC(void);
extern void func_02157928(u32 p);
extern int func_021578F0(u32 p);
extern int func_02157910(u32 p);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u8 *func_0200E8F8(u32 a);
extern int func_0200E5E4(u32 a);
extern int func_0200E5A0(u32 a);
extern int func_021D1058(u8 *a, int b);
extern void func_021D1080(u8 *a, int b);
extern void func_0200E608(u32 a, u32 b, u32 c);
extern int func_02157938(u32 p);
extern int func_0203D210(void);
extern void func_021D09D0(u32 a, u8 *b);

int func_021D0C58(u32 unused, u32 *state, W *w)
{
    u32 x;
    u32 h, sv;
    u8 *rec;
    int n, ok, r;

    x = w->f80;
    switch (*state) {
    case 0:
        w->f7c = func_021576D0(w);
        if (func_021578A0(w->f7c) == 0) {
            *w->f88 = 0;
            *state = 4;
        } else {
            *state = 1;
        }
        break;
    case 1:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928(w->f7c);
        if (++w->f8c > 120) {
            *state = 2;
        }
        break;
    case 2:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928(w->f7c);
        if (func_021578F0(w->f7c)) {
            *state = 3;
        } else {
            *w->f88 = 0;
            *state = 4;
        }
        break;
    case 3:
        if (func_020362DC() == 2) {
            *w->f88 = 3;
            *state = 4;
            break;
        }
        func_02157928(w->f7c);
        if (func_02157910(w->f7c) == 0) {
            break;
        }
        h = func_020120F4(x);
        rec = func_0200E8F8(func_02012EBC(h));
        sv = *(u32 *)(w->f84 + 0x14c);
        n = func_0200E5E4(sv);
        ok = func_0200E5A0(sv);
        r = func_021D1058(rec, n);
        if (ok != 0 && (r == 0 || n == 0)) {
            func_021D1080(rec, n);
            func_0200E608(h, *(u32 *)(w->f84 + 0x14c), 0x8004);
            *w->f88 = 1;
        } else if (r != 0) {
            *w->f88 = 2;
        } else {
            *w->f88 = 0;
        }
        *state = 4;
        break;
    case 4:
        func_02157938(w->f7c);
        *state = 5;
        break;
    case 5:
        if (func_0203D210()) {
            *state = 6;
        }
        break;
    case 6:
        func_021D09D0(x, w->f84);
        return 1;
    }
    return 0;
}
