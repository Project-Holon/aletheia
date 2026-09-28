/*
 * function: func_0203A338
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
 * src/matched/func_0203971C.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0203996C  0x0203996C  arm
 *   func_02039658  0x02039658  arm
 *   func_0203971C  0x0203971C  arm
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
 *   python tools/match.py one --src src/matched/func_0203A338.c \
 *       --func func_0203A338 --addr 0x0203A338 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02034714(const char *file, u32 line, const char *msg);
extern u32  func_0203996C(u32 v);
extern void func_02039658(u32 a, u32 b);
extern void func_0203971C(u32 a, u32 b);
extern const char file_020A7A68[];
extern const char file_020A7AB0[];

void func_0203A338(u32 a0)
{
    if (a0 == 0xFF)
        func_02034714(file_020A7A68, 0x3BE, file_020A7AB0);
    func_02039658(func_0203996C(a0), a0);
    func_0203971C(func_0203996C(0xFF), a0);
}
