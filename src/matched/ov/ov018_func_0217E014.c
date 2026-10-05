/*
 * function: func_0217E014
 * address:  0x0217E014
 * packet:   pkt_ov018_0217E014
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * final push 2026-10-05 G7L8: closed with opt_propagation off, a named slot
 * pointer `s` (declared first, assigned after the call, used for the three
 * zero stores and the first loop), n zeroed right before the first loop,
 * do-while loops (for loops gain entry guards under the pragma), an explicit
 * `if (n > 0)` guard on the second loop, and the mask test written as
 * `p[0xd9] & (1 << i)`.
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0204B404  0x0204B404  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pos;

typedef struct {
    u8 slot[4];
    Pos pos;
} Layout;

struct Ctx;
extern void *func_020120F4(const struct Ctx *);
extern void func_0204B404(void *, const Pos *, unsigned);
extern void func_0204B6F4(void *, u8, unsigned);
extern void func_0204B3DC(void *, unsigned);

#pragma opt_propagation off
void func_0217E014(u8 *p)
{
    u8 *s;
    void *act;
    int cur;
    int sel;
    int max;
    int n;
    int i;
    int j;
    Layout l;

    func_020120F4(*(void **)p);
    s = l.slot;
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    max = p[0xda];
    cur = p[0xd8];
    sel = 0;
    l.pos.y = 0x1c;
    n = 0;
    i = 0;
    do {
        if (p[0xd9] & (1 << i)) {
            s[n] = i;
            if (i == cur) {
                sel = n;
            }
            n++;
        }
        i++;
    } while (i < 3);
    j = 0;
    i = 0;
    if (n > 0) {
        do {
            if (sel != i) {
                if (l.slot[i] == cur + 1 || (l.slot[i] == 0 && cur == max - 1)) {
                    l.pos.x = 0xa0;
                } else {
                    l.pos.x = 0x60;
                }
                act = ((void **)(p + 0x80))[j];
                func_0204B404(act, &l.pos, 0);
                func_0204B6F4(act, l.slot[i] + 1, 1);
                func_0204B3DC(act, 1);
                j++;
            }
            i++;
        } while (i < n);
    }
    for (; i < 3; i++) {
        func_0204B3DC(((void **)(p + 0x80))[i], 0);
    }
}
#pragma opt_propagation reset
