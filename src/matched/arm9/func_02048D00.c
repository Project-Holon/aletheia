/*
 * function: func_02048D00
 * address:  0x02048D00
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048DDC  0x02048DDC  arm
 *   func_02048E34  0x02048E34  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 *
 * Read one sub-file of one archive into a buffer the caller owns.  The whole
 * archive handle is a 0x48 byte stack local: func_02048DDC binds it to the
 * archive named by `archive_id` (it indexes the 235-entry a/x/y/z name table
 * at 0x020A6C58), func_02048E34 seeks the member and returns its byte size,
 * func_02078B70 is the read and func_02078A80 closes the handle again.
 *
 * Nothing survives the call, so this is the one-shot form: a caller that wants
 * the archive to stay open uses func_020490F4 instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048D00.c \
 *       --func func_02048D00 --addr 0x02048D00 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ArcHandle {
    u8 raw[0x48];
};

extern void func_02048DDC(struct ArcHandle *h, u32 archive_id);
typedef signed int     s32;
struct FSFile;
extern u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_02078A80(struct ArcHandle *h);

void func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    struct ArcHandle h;

    func_02048DDC(&h, archive_id);
    func_02078B70((struct FSFile *)(&h), dst, func_02048E34(&h, member, mode, (u32)size_out));
    func_02078A80(&h);
}
