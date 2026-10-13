/*
 * function: MSGDATA_LoadFileHeader
 * address:  0x02046084
 * packet:   pkt_02045F5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_AllocSite     0x020A7E8C  data
 *   sub_02030734   0x02030734  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   func_0204960C  0x0204960C  arm
 *   func_02082D44  0x02082D44  arm
 *
 * Read a message file's header out of the archive and keep it.  The fixed
 * twelve-byte part is read onto the stack first because its language count is
 * what sizes the real allocation, 0xc + 4 * langCount; the stack copy is then
 * moved into the front of that block and the language offset table is read
 * straight in behind it.  This is the only caller of sub_02030734 with tag
 * 0x1f3.
 *
 * The header is twelve bytes here but sixteen in the MsgFile view used by
 * src/matched/unit_02045C44.c, which declares langOff[1] inline, so the fixed
 * part gets its own struct.  The scratch is declared as a raw twelve-byte
 * buffer and cast, not as that struct: `ldrh r1, [r6]` reads the language
 * count back through the pointer the reader was handed, and a declared struct
 * local folds to `ldrh r1, [sp, #4]` instead, two bytes and the only
 * difference in the function
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md).
 *
 * The shared 0xc is a single `mov r5, #0xc` feeding both the read length and
 * the copy length, and the `add r1, r1, #0xc` of the allocation size is a
 * separate literal, so the size argument is written as the literal at each
 * call and not bound to a named local.
 *
 * func_02082D44 takes source first and destination second (the MI_CpuCopy8
 * order), which is why the stack buffer is in r0 and the freshly allocated
 * block in r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_LoadFileHeader.c \
 *       --func MSGDATA_LoadFileHeader --addr 0x02046084 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgFileHdr {
    u16 langCount;
    u16 count;
    u32 size;
    u32 unk_08;
};

struct MsgFile {
    u16 langCount;
    u16 count;
    u32 size;
    u32 unk_08;
    u32 langOff[1];
};

extern char MSGDATA_AllocSite[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
struct ArcFile;
extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);
extern void func_0204960C(void *stream, u32 pos);
extern void func_02082D44(const void *src, void *dest, u32 size);

struct MsgFile *MSGDATA_LoadFileHeader(void *stream, u32 origin, u16 heapId)
{
    u8 hdr[12];
    struct MsgFileHdr *hp;
    struct MsgFile *file;

    func_0204960C(stream, origin);
    hp = (struct MsgFileHdr *)hdr;
    ARC_TOOL_ReadHandle(stream, sizeof(struct MsgFileHdr), hp);

    file = (struct MsgFile *)sub_02030734(heapId, hp->langCount * 4 + 0xc, 0,
                                          MSGDATA_AllocSite, 0x1f3);
    func_02082D44(hp, file, sizeof(struct MsgFileHdr));
    ARC_TOOL_ReadHandle(stream, file->langCount * 4, file->langOff);
    return file;
}
