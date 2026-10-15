/*
 * unit:     yes
 * function: BMP_CreateFromArchive
 * address:  0x0204384C
 * packet:   pkt_0204384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204384C_File  0x020A7E68  data
 *   func_02030734       0x02030734  arm
 *   func_020307B0       0x020307B0  arm
 *   ARC_UTIL_LoadMember       0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx       0x02062A4C  arm
 *   BMP_InitFromCharData       0x02043900  arm
 *   OS_Terminate        0x02088234  arm
 *
 * bmp.c's "load a bitmap out of an archive" entry point,
 * 0x0204384C-0x02043900 including its three pool words.  It allocates the
 * twelve-byte bitmap object ("bmp.c", line 266), opens the archive member,
 * asks 0x02062A4C for the decoded header, hands both to the constructor at
 * 0x02043900 and releases the archive handle.  A header that does not
 * resolve is fatal: `OS_Terminate` and then NULL.
 *
 * The archive-handle argument is `(heap & 0x7FFF) | 0x8000` narrowed to a
 * halfword, which is what the `and`/`orr` against the pooled 0x7FFF followed
 * by the `lsl #16`/`lsr #16` pair spells: 0x7FFF is not an ARM rotated
 * immediate and costs a pool word, 0x8000 is one.
 *
 * The zero in r4 is the allocator's alignment argument and the NULL return
 * in one register; it is materialised once, before the call, and survives to
 * the failure epilogue
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The failure arm falls through the `bne`, so the source tests `== 0` and
 * not the success condition
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to the constructor at 0x02043900 resolves on the `matched` class
 * through src/matched/unit_02043900.c, which lives in this same shard, so
 * `manifest --verify --shard pkt_0204384C` has to run twice from a cold
 * shard: the first pass records 0x02043900 and the second one sees it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204384C.c \
 *       --addr 0x0204384C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   unk08;
    u16   unk0A;
};

extern const char func_0204384C_File[];

typedef signed int     s32;
struct BmpInfo;
struct NitroFileHeader;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
extern void BMP_InitFromCharData(struct Bmp *b, struct BmpInfo *info, u32 heap);
extern void  OS_Terminate(void);

struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap)
{
    struct Bmp *b;
    void       *handle;
    void       *info;

    b = (struct Bmp *)func_02030734(heap, 0xC, 0, func_0204384C_File, 266);
    handle = (void *)ARC_UTIL_LoadMember((u32)arc, (u32)member, (u32)heap2, (u16)((heap & 0x7FFF) | 0x8000));
    if (NNS_G2dGetUnpackedCharacterDataEx(handle, &info) == 0) {
        OS_Terminate();
        return 0;
    }
    BMP_InitFromCharData(b, info, heap);
    func_020307B0(handle);
    return b;
}
