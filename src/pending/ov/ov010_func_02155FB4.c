/*
 * function: func_02155FB4
 * address:  0x02155FB4
 * packet:   pkt_ov010_02155FB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct (first draft). Blocker: 0x021FD948 has no func_ label in any
 * overlay listing (ov186 has it mid-function; ov094/ov132/ov135 overlap).
 *
 * symbols:
 *   func_021FD948  0x021FD948  thumb  ov186
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

extern void func_021FD948(void *p, void *q);

void func_02155FB4(Work *w)
{
    if (w->f14 == 1)
        func_021FD948(w->f28, w->f3C);
}
