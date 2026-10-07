/*
 * function: func_02039B5C
 * address:  0x02039B5C
 * packet:   pkt_02039B5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D4     0x021469D4  data
 *   func_020395EC  0x020395EC  arm
 *   sub_0203996C   0x0203996C  arm
 *   func_020399B8  0x020399B8  arm
 *   func_02039160  0x02039160  arm
 *
 * Record one peer's vote and raise the "everyone agreed" flag when the last
 * one lands.  The 3-byte message at `msg` is a u16 tag plus a u8 mask; the
 * sender's slot is `slot`, and the vote is only taken when func_020395EC says
 * the link is still the own link (0xff) and the slot is a real one.
 *
 * Both halves of the vote table hang off the one module global g_021469D4:
 * the u16 tags are the array at +0, the masks the bytes at +0x10 and the
 * ready flags the bytes at +0x18.  The global is re-read after each store and
 * inside the scan because every callee here is an ordinary extern.
 *
 * The scan then walks all eight slots: an ACTIVE slot must have voted the same
 * mask and the same tag, and must NOT carry that slot's own bit in its mask,
 * or the function returns without raising the flag; an INACTIVE slot is only allowed
 * through when func_02039160 says it is not merely late.  `1 << i` is kept
 * live in sb across the whole loop, which is what puts `mov sb, #1` above the
 * loop head rather than a rematerialised constant in the arm
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * EXACT* only: the inferred extent runs 20 bytes long because the unlabelled
 * leaf at 0x02039C2C (`ldrh r1,[r2] / ldr r0,[sp] / strh r1,[r0,#0x44] / bx lr`,
 * 16 bytes, saves no lr so disasm.py never labels it) follows this function's
 * own pool word at 0x02039C28.  Never a byte difference; 0x02039C2C wants
 * seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039B5C.c \
 *       --func func_02039B5C --addr 0x02039B5C --cc 1.1p1 --arm
 */

#include "../include/G_Votes.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Msg {
    u16 tag;
    u8  mask;
};

struct Entry;

extern struct Votes *g_021469D4;

typedef signed int     s32;
extern int func_020395EC(struct Entry *a);
extern struct Entry *sub_0203996C(s32 idx);
extern u32 func_020399B8(u8 *p);
extern u32 func_02039160(u16 mode);

void func_02039B5C(u32 slot, u32 a1, struct Msg *msg, u32 a3, u32 link)
{
    u16 tag = msg->tag;
    u8  mask = msg->mask;
    int i;
    u32 one;

    if (func_020395EC((void *)link) != 0xff) {
        return;
    }
    if (slot == 0xff) {
        return;
    }

    g_021469D4->tag[slot] = tag;
    g_021469D4->mask[slot] = mask;

    i = 0;
    one = 1;

    for (; i < 8; i++) {
        if (func_020399B8((u8 *)sub_0203996C(i)) != 0) {
            if (mask == g_021469D4->mask[i]) {
                if (tag != g_021469D4->tag[i]) {
                    return;
                }
            } else if ((mask & (one << i)) != 0) {
                return;
            }
        } else if (func_02039160((u16)i) == 1) {
            return;
        }
    }

    g_021469D4->ready[slot] = 1;
}
