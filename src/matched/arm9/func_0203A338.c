/*
 * function: GFL_NET_HANDLE_RemoveHandle
 * address:  0x0203A338
 * packet:   pkt_0203A338
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Promoted from src/pending/ on lane 1: every concrete byte is right (80 of
 * 80).  The one open site was the `bl` to 0x0203971C, whose only branch site
 * image-wide is this one, so `label` had no outside witness.  With
 * src/matched/GFL_NET_HANDLE_ClearTimingMask.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0203996C  0x0203996C  arm
 *   GFL_NET_HANDLE_ResetHandle  0x02039658  arm
 *   GFL_NET_HANDLE_ClearTimingMask  0x0203971C  arm
 *   file_020A7A68  0x020A7A68  data
 *   file_020A7AB0  0x020A7AB0  data
 *
 * Pushes a slot's identity into both halves of the table, reporting at line
 * 0x3BE (958) when the identity is the 0xFF sentinel.  Each half is
 * `record(func_0203996C(selector), id)` with the selector's result already in
 * r0, so the second call's first argument is the first call's return value
 * and no local is needed to hold it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_RemoveHandle.c \
 *       --func GFL_NET_HANDLE_RemoveHandle --addr 0x0203A338 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02034714(const char *file, u32 line, const char *msg);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern void GFL_NET_HANDLE_ResetHandle(struct Entry *e, u32 idx);
extern void GFL_NET_HANDLE_ClearTimingMask(unsigned char *a, u32 b);
extern const char file_020A7A68[];
extern const char file_020A7AB0[];

void GFL_NET_HANDLE_RemoveHandle(u32 a0)
{
    if (a0 == 0xFF)
        func_02034714(file_020A7A68, 0x3BE, file_020A7AB0);
    GFL_NET_HANDLE_ResetHandle(func_0203996C(a0), a0);
    GFL_NET_HANDLE_ClearTimingMask((unsigned char *)func_0203996C(0xFF), a0);
}
