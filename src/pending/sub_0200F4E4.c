/*
 * function: sub_0200F4E4
 * address:  0x0200F4E4
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0203D610  0x0203D610  arm
 *   func_0200F38C  0x0200F38C  thumb
 *   func_0203D44   0x02082D44  arm
 *
 * Looks up a friend slot for `a` via func_0200F38C, which returns a status
 * and, for status 1, a slot index through the out-parameter. Status 0
 * reports "not found" (0); status 1 copies the 12-byte record at that
 * index out of the table func_0203D610() returns into `a` and also
 * reports 0; status 2 reports "found, no copy" (1). Anything else falls
 * through to 0 as well.
 *
 * Every concrete byte matches; func_0200F38C (0x0200F38C, in this same
 * packet, not yet matched) is called from exactly this one site in the
 * whole ROM, so that relocation stays unresolved under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200F4E4.c \
 *       --func sub_0200F4E4 --addr 0x0200F4E4 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_0200F38C is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0203D610(void);
extern int   func_0200F38C(void *a, u32 *out_idx);
extern void  func_0203D44(void *dst, void *src, u32 len);

int sub_0200F4E4(void *a)
{
    int flag = 0;
    u8 *base = (u8 *)func_0203D610();
    u32 idx;
    int status = func_0200F38C(a, &idx);

    if (status != 0) {
        if (status == 1) {
            func_0203D44(a, base + idx * 12, 12);
        } else if (status == 2) {
            flag = 1;
        }
    }
    return flag;
}
