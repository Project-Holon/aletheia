/*
 * function: func_0201A2A8
 * address:  0x0201A2A8
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* note: the 98 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A30A before the next labelled function at 0x0201A30C.
 *
 * symbols:
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0201A26C   0x0201A26C  thumb
 *   func_02019CA0   0x02019CA0  thumb
 *
 * Sweeps the records of the second argument and rewrites those whose 0xA9
 * flag is set and whose recomputed value disagrees with what the first
 * argument's own query returns.  The value from before the loop is a spilled
 * local, so it is re-read from the frame at the one place it is used.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A2A8.c \
 *       --func func_0201A2A8 --addr 0x0201A2A8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Reg;
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u32  func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern u32  func_0201A26C(void *a0, u32 a1);
extern void func_02019CA0(void *p, u32 v);

void func_0201A2A8(void *a0, void *a1)
{
    u32 v = func_0200AE54(a0, 4);
    int i;

    for (i = 0; i < (int)func_0201AA18(a1); i++) {
        void *e = func_0201AB28(a1, i);

        if (func_02017E1C(e, 0xA9, 0) != 0) {
            u32 w = func_02017E1C(e, 0x9E, 0);

            if (func_0201A26C(a0, w) != w)
                func_02019CA0(e, v);
        }
    }
}
