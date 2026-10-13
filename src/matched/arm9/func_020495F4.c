/*
 * unit:     no
 * function: ARC_TOOL_ReadHandle
 * address:  0x020495F4
 * packet:   pkt_02049250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078B70  0x02078B70  arm
 *
 * Argument-swapping shim in front of the FS read: this entry point takes the
 * length before the destination, the reader takes them the other way round.
 * The swap costs the three-way `mov r3, r1 / mov r1, r2 / mov r2, r3`
 * shuffle and nothing else, so there is no frame at all and the call is a
 * tail call through a pool word and `bx ip`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandle.c \
 *       --func ARC_TOOL_ReadHandle --addr 0x020495F4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ArcFile {
    u8 raw[0x50];
};

typedef signed int     s32;
struct FSFile;
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst)
{
    func_02078B70((struct FSFile *)arc, dst, size);
}
