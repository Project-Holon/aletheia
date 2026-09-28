/*
 * function: func_02156B74
 * address:  0x02156B74
 * packet:   pkt_ov010_02156B74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct (first draft). Blocker: 0x021FD954 and 0x021FD95C have no
 * func_ label in any overlay listing (ov094/ov132/ov135/ov186 overlap).
 *
 * symbols:
 *   func_021FD954  0x021FD954  thumb  ov186
 *   func_021FD95C  0x021FD95C  thumb  ov186
 *   func_02157028  0x02157028  thumb  ov010
 *   func_02157278  0x02157278  thumb  ov010
 *   func_021572A8  0x021572A8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
} Work;

extern u32 func_021FD954(void *p);
extern u32 func_021FD95C(void *p);
extern void *func_02157028(u32 heap, void *p, u32 a);
extern void func_02157278(void *p, u32 v);
extern void func_021572A8(void *p, u32 v);

void func_02156B74(Work *w)
{
    u32 a;
    u32 b;

    a = func_021FD954(w->f28);
    b = func_021FD95C(w->f28);
    if (w->f38 == 0)
        w->f38 = func_02157028(4, w->f24, 0);
    func_02157278(w->f38, a);
    func_021572A8(w->f38, b);
}
