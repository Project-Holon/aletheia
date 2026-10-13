/*
 * function: GFL_NET_HANDLE_StartTimingSync
 * address:  0x02039C3C
 * packet:   pkt_02039B5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *
 * Arm one pending vote on the record at `p`: park the tag at +0x46, mark the
 * slot unresolved with 0xff at +0x48, and record at +0x49 whether the record
 * is NOT the own link -- GFL_NET_HANDLE_GetNetHandleID returning 0xff is the own link, which
 * is the one case that stores zero.
 *
 * The record pointer is copied to r4 before the two stores because the call
 * clobbers r0; the boolean is built with the `moveq`/`movne` pair rather than
 * a branch, which is 1.1p1's normal shape for a comparison stored straight to
 * memory.  The pair's ORDER is the source order of the arms: written as
 * `p->remote = (... != 0xff)` or as a ternary, 1.1p1 emits `movne r0,#1`
 * first and is 4 bytes out; the explicit if/else with the `== 0xff` arm first
 * puts `moveq r0,#0` first, as the image has it
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_StartTimingSync.c \
 *       --func GFL_NET_HANDLE_StartTimingSync --addr 0x02039C3C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u8  pad_00[0x46];
    u16 tag;
    u8  slot;
    u8  remote;
};

struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);

void GFL_NET_HANDLE_StartTimingSync(struct Rec *p, u16 tag)
{
    p->tag = tag;
    p->slot = 0xff;
    if (GFL_NET_HANDLE_GetNetHandleID((struct Entry *)p) == 0xff) {
        p->remote = 0;
    } else {
        p->remote = 1;
    }
}
