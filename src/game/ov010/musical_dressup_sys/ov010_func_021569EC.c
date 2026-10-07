/*
 * function: func_021569EC
 * address:  0x021569EC
 * packet:   pkt_ov010_021569EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Result class of member j: 0 for the local player, 1 or 4 from the
 * link peer record when linked, else the table value of its slot.
 *
 * Byte-correct. Blocker: 0x021FCE28 (ov132) has no func_ label.
 *
 * symbols:
 *   func_021568E8  0x021568E8  thumb  ov010
 *   func_021568A8  0x021568A8  thumb  ov010
 *   func_02157374  0x02157374  thumb  ov010
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_02008550  0x02008550  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x28 - 0x18];
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    u8 pad3C[0x4C - 0x3C];
    u8 f4c;             /* 0x4C */
} Work;

extern u8 func_021568E8(Work *w, u8 j);
extern u8 func_021568A8(Work *w, u8 n);
struct Deal;
struct Sub0200852CObj;
extern u8 func_02157374(struct Deal *d, u8 i);
extern int func_021FCE28(char *p, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);

u8 func_021569EC(Work *w, u8 j)
{
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4c)
        return 0;
    if (w->f14 == 1) {
        p = (void *)func_021FCE28(w->f28, k);
        if (p != 0) {
            if (func_02008550(p) == 0)
                return 1;
            return 4;
        }
    }
    return func_02157374(w->f38, func_021568A8(w, k));
}
