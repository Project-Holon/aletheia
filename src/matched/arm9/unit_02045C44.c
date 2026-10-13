/*
 * unit:     yes
 * function: MSGDATA_CreateFromMemory, func_02045CAC
 * address:  0x02045C44
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_SetChars  0x02045A00  arm
 *   func_02045E04  0x02045E04  arm
 *   MSGDATA_LoadBank  0x02046110  arm
 *   func_02046180  0x02046180  arm
 *   func_020461B8  0x020461B8  arm
 *   sub_02030734   0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   func_0204960C  0x0204960C  arm
 *   MSGDATA_AllocSite     0x020A7E8C  data
 *
 * The whole of pkt_02045C44, 448 bytes with both literal pools: the message
 * bank's constructor and its one reader.  Both functions are EXACT
 * individually as well (src/matched/MSGDATA_CreateFromMemory.c and
 * src/matched/func_02045CAC.c); this unit is the consolidated shape.
 *
 * The object is 0x1c bytes and its layout is pinned by the pair:
 *
 *   +0x00  const MsgFile *file   the mapped message file header
 *   +0x04  void          *base   entry table plus payload, when resident
 *   +0x08  MsgEntry       cache  one streamed descriptor
 *   +0x10  u32            origin file offset of the bank inside the archive
 *   +0x14  void          *stream archive handle
 *   +0x18  u16            heapId
 *   +0x1a  u8             langIndex
 *   +0x1b  u8             resident
 *
 * func_02045CAC has two residency modes.  Resident: the entry descriptor is
 * &((MsgEntry *)(base + 4))[index] and the payload is base + e->off, handed
 * straight to STRBUF_SetChars.  Streamed: the descriptor is an 8-byte archive
 * read into the cache at +0x8, then a scratch buffer of 2 * e->len bytes is
 * allocated, filled by a second read, consumed and freed.  The allocator
 * heap id for that scratch buffer is (u16)((heapId & 0x7fff) | 0x8000), the
 * "allocate from the far end" form.
 *
 * Both file offsets are origin + file->langOff[langIndex] plus the entry's
 * own displacement, so langOff[] at +0xc of the file header is a
 * per-language section table and the entry table starts four bytes into its
 * section.
 *
 * Shape note that cost the last eleven bytes of func_02045CAC: both guards
 * test bank->resident, but the source spells them `== 0`, not `!= 0`.  That
 * puts the streamed arm on the fall-through and leaves the short arm to be
 * if-converted (ldrne/addne), per
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.  The other
 * polarity emits exactly the same instructions but transposes
 * `ldr r3, [sb, #0x10]` and `lsl r0, r8, #3` in the seek block: the arm
 * linearisation order is what breaks the scheduler's tie between the two
 * ready gap fillers.
 *
 * The fourth argument of sub_02030734 is the BSS provenance object at
 * 0x020A7E8C, not a __FILE__ string: it sits above the arm9 static image
 * end and has 41 pool references image-wide.  In MSGDATA_CreateFromMemory the
 * allocator's third argument (clear) shares one `mov r5, #0` with the two
 * zero field stores, so it is written as a plain literal at the call rather
 * than bound to a named local (the shape of src/matched/STRBUF_Create.c).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045C44.c \
 *       --addr 0x02045C44 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MsgEntry {
    u32 off;
    u16 len;
    u16 pad_06;
};

struct MsgFile {
    u16 langCount;
    u16 count;
    u32 unk_04;
    u32 unk_08;
    u32 langOff[1];
};

struct MsgBank {
    const struct MsgFile *file;
    void                 *base;
    struct MsgEntry       cache;
    u32                   origin;
    void                 *stream;
    u16                   heapId;
    u8                    langIndex;
    u8                    resident;
};

extern char MSGDATA_AllocSite[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
struct ArcFile;
struct Buf;
struct Obj;
struct U16Vec;
extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);
extern void func_0204960C(void *stream, u32 pos);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void STRBUF_SetChars(struct Buf *buf, const void *src, u32 n);
extern void func_02045E04(struct Obj *o, u32 mode);
typedef signed int     s32;
struct Header;
struct MsgData;
extern s32 func_020461B8(struct Header *h);
extern void MSGDATA_LoadBank(struct MsgData *msg);
extern void func_02046180(struct Obj *o);

struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId)
{
    struct MsgBank *bank;

    bank = (struct MsgBank *)sub_02030734(heapId, 0x1c, 0, MSGDATA_AllocSite, 0xa6);
    bank->heapId = (u16)heapId;
    bank->stream = 0;
    bank->origin = 0;
    bank->resident = 1;
    bank->file = (const struct MsgFile *)file;
    bank->langIndex = func_020461B8((struct Header *)file);
    MSGDATA_LoadBank((struct MsgData *)bank);
    return bank;
}

void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
{
    u32 size;
    struct MsgEntry *e;

    if (index >= bank->file->count) {
        STRBUF_Clear(dest);
        return;
    }

    func_02046180((struct Obj *)bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        func_0204960C(bank->stream, pos + (index * 8 + 4));
        ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
        e = &bank->cache;
    } else {
        e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    if (bank->resident == 0) {
        void *buf;

        size = e->len * 2;
        buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
                           0, MSGDATA_AllocSite, 0xd6);
        if (buf != 0) {
            func_0204960C(bank->stream,
                          e->off + (bank->origin
                              + bank->file->langOff[bank->langIndex]));
            ARC_TOOL_ReadHandle(bank->stream, size, buf);
            STRBUF_SetChars(dest, buf, e->len);
            func_020307B0(buf);
        }
    } else {
        STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
    }

    func_02045E04(dest, index);
}
