/*
 * function: func_020398B4
 * address:  0x020398B4
 * packet:   pkt_02039764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D4     0x021469D4  data
 *   file_020A7A68  0x020A7A68  data
 *   msg_020A7A88   0x020A7A88  data
 *   sub_0203996C   0x0203996C  arm
 *   func_02039658  0x02039658  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *
 * The teardown twin of func_02039834: clear every one of the eight peer slots
 * (func_02039658 on each slot's entry), release the eight resource handles the
 * own-slot entry parks at +8..+0x24, clear the own slot too, then assert the
 * module handle g_021469D4 is live and free it.
 *
 * The own-slot entry is taken once, before the release loop, and the address
 * of each handle word is recomputed per iteration rather than kept in a
 * cursor: func_020307B0 is an ordinary extern, so the store after it needs a
 * fresh `add r0, r5, r6, lsl #2`
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The two `mov` of the slot key 0xff share one register with the clear loop's
 * counter, which is why the tail spells the key as `mov r4, #0xff`.
 *
 * The __FILE__ argument is "net_handle.c" at 0x020A7A68, line 0x100.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020398B4.c \
 *       --func func_020398B4 --addr 0x020398B4 --cc 1.1p1 --arm
 */

#include "../include/G_Votes.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8   pad_00[8];
    void *handle[8];
};

extern struct Votes *g_021469D4;
extern const char file_020A7A68[];
extern const char msg_020A7A88[];

typedef signed int     s32;
extern struct Entry *sub_0203996C(s32 idx);
extern void func_02039658(struct Entry *e, u32 idx);
extern u32 func_020307B0(void *p);
extern void func_02034714(const char *file, u32 line, const char *msg);

void func_020398B4(void)
{
    struct Entry *own;
    int i;
    u32 key;

    for (i = 0; i < 8; i++) {
        func_02039658(sub_0203996C(i), i);
    }

    own = sub_0203996C(0xff);

    for (i = 0; i < 8; i++) {
        if (own->handle[i] != 0) {
            func_020307B0(own->handle[i]);
            own->handle[i] = 0;
        }
    }

    key = 0xff;
    func_02039658(sub_0203996C(key), key);

    if (g_021469D4 == 0) {
        func_02034714(file_020A7A68, 0x100, msg_020A7A88);
    }
    func_020307B0(g_021469D4);
    g_021469D4 = 0;
}
