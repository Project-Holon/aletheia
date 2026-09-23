/*
 * function: func_02027D44
 * address:  0x02027D44
 * packet:   pkt_02027D44
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02027B30  0x02027B30  thumb
 *   func_020061E4  0x020061E4  thumb
 *
 * The TaskMenu per-frame input step: up (0x40) / down (0x80) move the
 * cursor with wrap-around and play 0x548; A (held & 1) confirms (m->f0C = 1,
 * sound 0x551 or 0x54c by the row's +8 word); B (held & 2) jumps to the
 * last row, sound 0x551.  In the func_020355C4() == 1 mode a press that is
 * not B only re-highlights the current row.  When the cursor moved, the old
 * row is un-highlighted and the new one highlighted via func_02027B30.
 *
 * Closed in wave 12 from the 84-byte wave-4 source by two facts:
 *  - the up/down arms play 0x548, not 0x54C: the pool is 0x548, 0x551,
 *    0x54C in first-use order and the 0x40 arm's ldr reaches the first
 *    word (68 of the 84 bytes were this constant and the pool order it
 *    forced);
 *  - in the B arm the cursor store is written BEFORE the m->f0C = 1 store.
 *    The scheduler emits them the other way round, but the source order
 *    decides which of the constant 1 and the count temporary gets r0; the
 *    permuter never moves one store past another, so it could not find it.
 * No `one` local is needed; the constant is CSE'd by the compiler.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Row {
    u8  pad00[8];
    u32 f08;
};

struct Menu {
    u8  cursor;     /* +0x00 */
    u8  pad01;      /* +0x01 */
    u16 h2;         /* +0x02 */
    u32 pad04[2];   /* +0x04 */
    u32 f0C;        /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 pad14;      /* +0x14 */
    u32 *f18;       /* +0x18 */
    struct Row *f1C;/* +0x1C */
    u32 pad20;      /* +0x20 */
    u8  count;      /* +0x24 */
    u8  pad25[0x34 - 0x25];
    u32 f34;        /* +0x34 */
};

extern u32  func_020362DC(void);
extern u32  func_0203633C(void);
extern int  func_020355C4(void);
extern void func_020355D8(u32 a);
extern void func_02027B30(u32 cell, u32 ctx, u32 sel);
extern void func_020061E4(u32 id);

void func_02027D44(struct Menu *m)
{
    u32 held;
    u32 hit;
    int prev;

    held = func_020362DC();
    hit  = func_0203633C();
    if (m->f10 == 1) {
        return;
    }
    if (func_020355C4() == 1) {
        if ((held & 2) == 0) {
            if ((held & 0xC3) == 0) {
                return;
            }
            func_02027B30(m->f18[m->cursor], m->f34, 1);
            func_020355D8(0);
            func_020061E4(0x548);
            return;
        }
    }
    prev = m->cursor;
    if (hit & 0x40) {
        if (prev == 0) {
            m->cursor = (u8)(m->count - 1);
        } else {
            m->cursor = (u8)(prev - 1);
        }
        m->h2 = 0;
        func_020061E4(0x548);
    } else if (hit & 0x80) {
        if (prev >= m->count - 1) {
            m->cursor = 0;
        } else {
            m->cursor = (u8)(prev + 1);
        }
        m->h2 = 0;
        func_020061E4(0x548);
    } else {
        if (held & 1) {
            m->f0C = 1;
            if (m->f1C[prev].f08 == 1) {
                func_020061E4(0x551);
            } else {
                func_020061E4(0x54C);
            }
        } else if (held & 2) {
            m->cursor = (u8)(m->count - 1);
            m->f0C = 1;
            func_020061E4(0x551);
            func_020355D8(0);
        }
    }
    if (prev == m->cursor) {
        return;
    }
    func_02027B30(m->f18[prev], m->f34, 0);
    func_02027B30(m->f18[m->cursor], m->f34, 1);
}
