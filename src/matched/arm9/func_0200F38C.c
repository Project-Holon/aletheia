/*
 * function: func_0200F38C
 * address:  0x0200F38C
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203D5EC   0x0203D5EC  arm
 *   func_0203D610   0x0203D610  arm
 *   func_0203D634   0x0203D634  arm
 *   func_020596D8   0x020596D8  arm
 *   func_020598EC   0x020598EC  arm
 *   func_02059A5C   0x02059A5C  arm
 *
 * Search for a free friend slot: the out-parameter starts at -1 and the
 * function reports 3 when the object is not known at all (func_020596D8),
 * 0 for the first record whose tester (func_02059A5C) accepts it with that
 * slot index, 1 when the key (func_020598EC) of the object matches the
 * record's, and 2 when the scan finishes.  A slot that no key names and that
 * the tester still rejects is kept as a fallback in *out.
 *
 * This is the callee src/pending/sub_0200F4E4.c is capped on: its only
 * branch anywhere in the image is that one call site, so this entry is the
 * witness that turns it EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200F38C.c \
 *       --func func_0200F38C --addr 0x0200F38C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D5EC(void);
extern u8   *func_0203D610(void);
struct DWCstAccUserData;
extern u32 func_0203D634(void);
extern int   func_020596D8(void *p);
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);
extern int   func_02059A5C(void *a, void *b);

int func_0200F38C(void *a, int *out)
{
    int   i;
    void *key = func_0203D5EC();
    u8   *tbl = func_0203D610();
    int   n = func_0203D634();

    *out = -1;
    if (func_020596D8(a) == 0)
        return 3;
    for (i = 0; i < n; i++) {
        int off = i * 12;

        if (func_02059A5C(a, tbl + off) != 0) {
            *out = i;
            return 0;
        }
        if (func_020598EC(key, a) > 0
            && func_020598EC(key, a) == func_020598EC(key, tbl + off)) {
            *out = i;
            return 1;
        }
        if (*out < 0 && func_020596D8(tbl + off) == 0)
            *out = i;
    }
    return 2;
}
