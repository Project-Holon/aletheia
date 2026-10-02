/*
 * function: func_0202F640
 * address:  0x0202F640
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 */

typedef unsigned int u32;

extern u32  func_02017DBC(u32 a);
extern u32  func_0202F498(u32 a, u32 b);
extern void func_02017E64(u32 a, u32 b, u32 c);
extern void func_02017DE4(u32 a, u32 b);

void func_0202F640(u32 a, u32 b)
{
    u32 r = func_02017DBC(a);

    if (func_0202F498(a, b) == 1) {
        switch (b) {
        case 0:
            func_02017E64(a, 0x96, 0x753B);
            break;
        case 2:
            func_02017E64(a, 0x96, 0x753D);
            break;
        }
    }
    func_02017DE4(a, r);
}
