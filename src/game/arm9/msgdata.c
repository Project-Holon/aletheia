/*
 * file:     msgdata.c
 * unit:     yes
 * function: MSGDATA_CreateFromArchive, MSGDATA_Delete, MSGDATA_CreateFromMemory, MSGDATA_ReadString, MSGDATA_DecryptStrbuf, MSGDATA_DecryptUnits, MSGDATA_AllocString, MSGDATA_GetMessageCount, MSGDATA_ReadUnits, MSGDATA_LoadFileHeader, MSGDATA_LoadBank, MSGDATA_RefreshLanguage, MSGDATA_GetLanguageIndex, MSGDATA_SetLanguage, MSGDATA_GetLanguage
 * address:  0x02045B38
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Split from bmp.c at 0x02045B38 (__FILE__ anchor boundary, certain cut).
 * The one-byte global setter that closes pkt_02045C44.  It saves nothing,
 * so disasm.py folded it into MSGDATA_GetLanguageIndex's extent and reported that
 * function as EXACT* until this file existed
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x020461D4
 * wants seeding into layout/function_starts.txt.
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_SetLanguage.c \
 *       --func MSGDATA_SetLanguage --addr 0x020461D4 --cc 1.1p1 --arm
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MSGDATA_AllocSite     0x020A7E8C  data
 *   MSGDATA_GetLanguageIndex  0x020461B8  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_GetHandleMemberOffset  0x02049578  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   MSGDATA_DecryptStrbuf  0x02045E04  arm
 *   MSGDATA_RefreshLanguage  0x02046180  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   ARC_TOOL_SeekHandle  0x0204960C  arm
 *   MSGDATA_DecryptUnits  0x02045E3C  arm
 *   ARC_TOOL_SeekHandle  0x0204960C  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   MSGDATA_LoadBank  0x02046110  arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_Truncate 0x02045900 arm
 *   STRBUF_SetChars 0x02045A00 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   g_Byte_02146A54  0x02146A54  data
 *   g_02146A54 0x02146A54 data
 */
struct ArcFile;
struct Strbuf;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

/* String buffer (strbuf.c): capacity in code units, used length, tag, units. */
struct Strbuf {
    u16 capacity;
    u16 length;
    u32 magic;
    u16 chars[1];
};

/* One message entry: offset of the encrypted units inside the language
 * section (resident: inside the loaded bank) and the unit count. */
struct MsgEntry {
    u32 offset;
    u16 length;
    u16 reserved;
};

/* Message file header (12 bytes) followed by one section offset per
 * language; each section starts with an 8-byte-per-entry table (the first
 * four bytes of the section are the section size). */
struct MsgFile {
    u16 langCount;
    u16 count;
    u32 size;
    u32 reserved;
    u32 langOff[1];
};

/* Fixed part of the header, as read from the archive. */
struct MsgFileHeader {
    u16 langCount;
    u16 count;
    u32 size;
    u32 reserved;
};

/* A message bank: the open message file, its language and (when resident)
 * the loaded language section. */
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

/* The same bank seen by MSGDATA_LoadBank; the volatile file pointer keeps
 * the original's second load of the file pointer (stand-in, the original
 * source form is unknown). */
struct MsgBankLoad {
    const struct MsgFile * volatile file;
    void *base;
    u32 cacheOffset;
    u32 cacheLength;
    u32 origin;
    void *stream;
    u16 heapId;
    u8 langIndex;
    u8 resident;
};

extern u32 GFL_HEAP_Free(void *p);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);
extern u32 ARC_TOOL_GetHandleMemberOffset(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_DeleteHandle(void *handle);
extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);
extern void ARC_TOOL_SeekHandle(void *stream, u32 pos);
extern void STRBUF_Clear(struct Strbuf *vec);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
u16 STRBUF_GetLength(struct Strbuf *vec);
void STRBUF_Truncate(struct Strbuf *vec, u32 length);
void STRBUF_SetChars(struct Strbuf *buf, const void *src, u32 n);
u16 *STRBUF_GetChars(struct Strbuf *vec);
u16 STRBUF_GetEosChar(void);
extern void g_02146A54(void);
struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
u32 MSGDATA_Delete(struct MsgBank *bank);
struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
void MSGDATA_DecryptStrbuf(struct Strbuf *str, u32 msgIndex);
u32 MSGDATA_DecryptUnits(u16 *str, u32 count, u32 msgIndex);
struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
u16 MSGDATA_GetMessageCount(const struct MsgBank *bank);
void MSGDATA_ReadUnits(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen);
struct MsgFile *MSGDATA_LoadFileHeader(void *stream, u32 origin, u16 heapId);
void MSGDATA_LoadBank(struct MsgBankLoad *bank);
void MSGDATA_RefreshLanguage(struct MsgBank *bank);
s32 MSGDATA_GetLanguageIndex(const struct MsgFile *file);
void MSGDATA_SetLanguage(u8 languageId);
u8 MSGDATA_GetLanguage(void);
extern char MSGDATA_AllocSite[];
extern u8 g_Byte_02146A54;




/*
 * The archive-backed constructor for the message bank whose object layout is
 * pinned by src/matched/unit_02045C44.c, and the reason that object carries
 * both a `stream` handle and a `resident` flag.  MSGDATA_CreateFromMemory builds a bank
 * over a file the caller already has; this one opens the archive, seeks the
 * member, reads its header and then decides: a resident bank allocates the
 * whole payload up front and calls MSGDATA_LoadBank to index it, a streamed bank
 * leaves `base` null and reads entries on demand in MSGDATA_ReadString.
 *
 * The allocation tags are 0x68 for the bank and 0x7b for the payload, both
 * passed as the fifth argument on the stack, with the same BSS provenance
 * object at 0x020A7E8C in the fourth (not a __FILE__ string; see the note in
 * unit_02045C44.c).  The provenance pointer and the constant zero are each
 * loaded once into a callee-saved register and reused at both call sites,
 * which is what pins them as plain literals at the calls rather than named
 * locals.
 *
 * The file offset returned by ARC_TOOL_GetHandleMemberOffset is bound to a local: the original
 * spends `mov r1, r0` on it before the store to +0x10, four bytes that vanish
 * if the store's value is re-read from the field for the MSGDATA_LoadFileHeader call
 * (docs/idioms/cmp-operand-order-names-the-temporary.md, same tell).  The
 * stream handle and the file pointer are not: both are read back from the
 * field and the compiler forwards the store it just made.
 *
 * The resident arm is the fall-through, so the guard is spelled `!= 0` and the
 * one-store arm is left to be if-converted into `streq`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_CreateFromArchive.c \
 *       --func MSGDATA_CreateFromArchive --addr 0x02045B38 --cc 1.1p1 --arm
 */
struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId)
{
    struct MsgBank *bank;
    u32 origin;

    bank = (struct MsgBank *)GFL_HEAP_Alloc(heapId, 0x1c, 0, MSGDATA_AllocSite, 0x68);
    bank->heapId = (u16)heapId;
    bank->stream = ARC_TOOL_CreateHandle(arcId, heapId);
    origin = ARC_TOOL_GetHandleMemberOffset(bank->stream, fileId);
    bank->origin = origin;
    bank->resident = (u8)resident;
    bank->file = MSGDATA_LoadFileHeader(bank->stream, origin, bank->heapId);
    bank->langIndex = MSGDATA_GetLanguageIndex(bank->file);

    if (bank->resident != 0) {
        bank->base = GFL_HEAP_Alloc(bank->heapId, bank->file->size, 0,
                                  MSGDATA_AllocSite, 0x7b);
        MSGDATA_LoadBank((struct MsgBankLoad *)bank);
    } else {
        bank->base = 0;
    }
    return bank;
}




/*
 * Tear down the record: when the +0x14 handle is live, release the two
 * buffers it owns (the second only if non-NULL) and close the handle, then
 * free the record itself either way.
 *
 * The +0x14 guard reads the field once and the close reads it again, which
 * is why the original has two `ldr r0, [r4, #0x14]` around the calls: the
 * intervening frees may alias it, so no `const` local is involved.  The
 * second buffer's guard needs no register move, the guarded call consuming
 * the value the `cmp` already loaded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_Delete.c \
 *       --func MSGDATA_Delete --addr 0x02045C04 --cc 1.1p1 --arm
 */
u32 MSGDATA_Delete(struct MsgBank *bank)
{
    if (bank->stream != 0) {
        GFL_HEAP_Free((void *)bank->file);
        if (bank->base != 0) {
            GFL_HEAP_Free(bank->base);
        }
        ARC_TOOL_DeleteHandle(bank->stream);
    }
    return GFL_HEAP_Free(bank);
}




/*
 * The whole of pkt_02045C44, 448 bytes with both literal pools: the message
 * bank's constructor and its one reader.  Both functions are EXACT
 * individually as well (src/matched/MSGDATA_CreateFromMemory.c and
 * src/matched/MSGDATA_ReadString.c); this unit is the consolidated shape.
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
 * MSGDATA_ReadString has two residency modes.  Resident: the entry descriptor is
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
 * Shape note that cost the last eleven bytes of MSGDATA_ReadString: both guards
 * test bank->resident, but the source spells them `== 0`, not `!= 0`.  That
 * puts the streamed arm on the fall-through and leaves the short arm to be
 * if-converted (ldrne/addne), per
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.  The other
 * polarity emits exactly the same instructions but transposes
 * `ldr r3, [sb, #0x10]` and `lsl r0, r8, #3` in the seek block: the arm
 * linearisation order is what breaks the scheduler's tie between the two
 * ready gap fillers.
 *
 * The fourth argument of GFL_HEAP_Alloc is the BSS provenance object at
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
struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId)
{
    struct MsgBank *bank;

    bank = (struct MsgBank *)GFL_HEAP_Alloc(heapId, 0x1c, 0, MSGDATA_AllocSite, 0xa6);
    bank->heapId = (u16)heapId;
    bank->stream = 0;
    bank->origin = 0;
    bank->resident = 1;
    bank->file = (const struct MsgFile *)file;
    bank->langIndex = MSGDATA_GetLanguageIndex(bank->file);
    MSGDATA_LoadBank((struct MsgBankLoad *)bank);
    return bank;
}




void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest)
{
    u32 size;
    struct MsgEntry *entry;

    if (index >= bank->file->count) {
        STRBUF_Clear(dest);
        return;
    }

    MSGDATA_RefreshLanguage(bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        ARC_TOOL_SeekHandle(bank->stream, pos + (index * 8 + 4));
        ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
        entry = &bank->cache;
    } else {
        entry = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    if (bank->resident == 0) {
        void *encrypted;

        size = entry->length * 2;
        encrypted = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000), size,
                                 0, MSGDATA_AllocSite, 0xd6);
        if (encrypted != 0) {
            ARC_TOOL_SeekHandle(bank->stream,
                          entry->offset + (bank->origin
                              + bank->file->langOff[bank->langIndex]));
            ARC_TOOL_ReadHandle(bank->stream, size, encrypted);
            STRBUF_SetChars(dest, encrypted, entry->length);
            GFL_HEAP_Free(encrypted);
        }
    } else {
        STRBUF_SetChars(dest, (u8 *)bank->base + entry->offset, entry->length);
    }

    MSGDATA_DecryptStrbuf(dest, index);
}




/*
 * Advance the object by one: read its current index (STRBUF_GetLength), ask
 * MSGDATA_DecryptUnits for the entry one past it in the list STRBUF_GetChars returns,
 * and install the answer with STRBUF_Truncate.
 *
 * Three of the four calls need the object pointer, so it is pinned in r6
 * for the whole body; the incoming second argument survives in r5 across
 * two calls before reaching MSGDATA_DecryptUnits's r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_DecryptStrbuf.c \
 *       --func MSGDATA_DecryptStrbuf --addr 0x02045E04 --cc 1.1p1 --arm
 */
void MSGDATA_DecryptStrbuf(struct Strbuf *str, u32 msgIndex)
{
    s32 used = STRBUF_GetLength(str);

    STRBUF_Truncate(str, MSGDATA_DecryptUnits(STRBUF_GetChars(str), used + 1, msgIndex));
}




/*
 * The message-bank string cipher, decrypting a raw UTF-16-code-unit run in
 * place. This is the routine the asset lane's tools/assets/text.py was
 * reverse-engineering; the code states the scheme exactly:
 *
 *   key = (u16)((msgIndex + 3) * 0x2983)
 *   for each code unit: unit ^= key, then key = rotate_left_16(key, 3)
 *
 * The seed is derived forward from the entry's own descriptor index in the
 * message file, so no brute force or terminator-anchored back-solve is
 * needed. Decryption stops at the first unit that equals the global
 * end-of-string code STRBUF_GetEosChar() returns (0xFFFF in this build), and the
 * function returns the index of that unit, i.e. the decoded length; if no
 * terminator is found inside count units it returns count.
 *
 * Note for the asset side: there is no compression layer on top of this
 * cipher. Decoded streams are plain code units plus in-band control codes
 * (0xFFFF terminator, 0xFFFE line break, 0xF000 escape introducer followed
 * by a kind word, an argument count and that many argument words).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_DecryptUnits.c \
 *       --func MSGDATA_DecryptUnits --addr 0x02045E3C --cc 1.1p1
 */
u32 MSGDATA_DecryptUnits(u16 *str, u32 count, u32 msgIndex)
{
    u16 eos = STRBUF_GetEosChar();
    u16 key = (u16)((msgIndex + 3) * 0x2983);
    u32 i;

    for (i = 0; i < count; i++) {
        *str ^= key;
        if (*str == eos) {
            return i;
        }
        str++;
        key = (u16)(((key & 0xE000) >> 13) | (u16)(key << 3));
    }

    return count;
}




/*
 * Message bank string allocator and loader: given a bank and an entry index,
 * reads the entry descriptor (from the resident array or stream), allocates
 * a buffer sized for the string length, decodes the string into it via
 * MSGDATA_ReadString, and returns the allocated buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_AllocString.c \
 *       --func MSGDATA_AllocString --addr 0x02045EC0 --cc 1.1p1 --arm
 */
struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index)
{
    struct MsgEntry *entry;
    struct Strbuf *str;

    MSGDATA_RefreshLanguage(bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        ARC_TOOL_SeekHandle(bank->stream, pos + (index * 8 + 4));
        ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
        entry = &bank->cache;
    } else {
        entry = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    str = STRBUF_Create(entry->length, bank->heapId);
    MSGDATA_ReadString(bank, index, str);
    return str;
}




/*
 * A three-instruction accessor: follow the pointer at +0 of the object and
 * return the halfword at +2 of what it points at.  It saves nothing, so
 * disasm.py never labelled it and it only shows up by sweeping the packet
 * by address (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * `ldrh` with no sign extension fixes the field as u16; an s16 would have
 * needed a register-offset `ldrsh`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_GetMessageCount.c \
 *       --func MSGDATA_GetMessageCount --addr 0x02045F50 --cc 1.1p1 --arm
 */
u16 MSGDATA_GetMessageCount(const struct MsgBank *bank)
{
    return bank->file->count;
}




/*
 * msgdata.c: read string msgIndex into str (at most maxLen characters),
 * either from the resident bank (mode != 0) or by seeking the archive file,
 * then decode it in place (MSGDATA_DecryptUnits) and terminate it with the EOM
 * code (STRBUF_GetEosChar).
 *
 * The 11-byte scheduling residue of docs/notes/pkt_02045F5C.c.txt was the
 * first test's polarity: written `mode == 0` with the file arm first, the
 * compiler predicates the else arm (ldrne/addne/addne/bne) and schedules
 * the file arm's loads in the image's order.
 */
void MSGDATA_ReadUnits(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen)
{
    const struct MsgEntry *entry;
    u32 count;
    u32 len;

    MSGDATA_RefreshLanguage(bank);

    if (bank->resident == 0) {
        u32 sectionOffset = bank->file->langOff[bank->langIndex];
        ARC_TOOL_SeekHandle(bank->stream, (bank->origin + sectionOffset) + (msgIndex * 8 + 4));
        ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
        entry = &bank->cache;
    } else {
        entry = (const struct MsgEntry *)((u8 *)bank->base + 4 + msgIndex * 8);
    }

    count = entry->length;
    if (count > maxLen) {
        count = maxLen;
    }

    if (bank->resident == 0) {
        u32 readBytes = count * 2;
        if (readBytes > maxLen * 2) {
            readBytes = maxLen * 2;
        }
        {
            u32 sectionOffset = bank->file->langOff[bank->langIndex];
            ARC_TOOL_SeekHandle(bank->stream, (bank->origin + sectionOffset) + entry->offset);
            ARC_TOOL_ReadHandle(bank->stream, readBytes, str);
        }
    } else {
        const u16 *src = (const u16 *)((u8 *)bank->base + entry->offset);
        u32 i;
        for (i = 0; i < count; i++) {
            str[i] = src[i];
        }
    }

    len = MSGDATA_DecryptUnits(str, count, msgIndex);
    str[len] = STRBUF_GetEosChar();
}




/*
 * Read a message file's header out of the archive and keep it.  The fixed
 * twelve-byte part is read onto the stack first because its language count is
 * what sizes the real allocation, 0xc + 4 * langCount; the stack copy is then
 * moved into the front of that block and the language offset table is read
 * straight in behind it.  This is the only caller of GFL_HEAP_Alloc with tag
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
 * MI_CpuCopy8 takes source first and destination second (the MI_CpuCopy8
 * order), which is why the stack buffer is in r0 and the freshly allocated
 * block in r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_LoadFileHeader.c \
 *       --func MSGDATA_LoadFileHeader --addr 0x02046084 --cc 1.1p1 --arm
 */
struct MsgFile *MSGDATA_LoadFileHeader(void *stream, u32 origin, u16 heapId)
{
    u8 hdr[12];
    struct MsgFileHeader *hp;
    struct MsgFile *file;

    ARC_TOOL_SeekHandle(stream, origin);
    hp = (struct MsgFileHeader *)hdr;
    ARC_TOOL_ReadHandle(stream, sizeof(struct MsgFileHeader), hp);

    file = (struct MsgFile *)GFL_HEAP_Alloc(heapId, hp->langCount * 4 + 0xc, 0,
                                          MSGDATA_AllocSite, 0x1f3);
    MI_CpuCopy8(hp, file, sizeof(struct MsgFileHeader));
    ARC_TOOL_ReadHandle(stream, file->langCount * 4, file->langOff);
    return file;
}



/*
 * msgdata.c: point the MsgData object at the selected language bank.  The
 * archive header holds one u32 bank offset per language at +0x0C; with no
 * file handle the bank is resident and the object records archive +
 * offset, otherwise it seeks, reads the leading u32 size, seeks back and
 * reads the whole bank.
 *
 * The four bytes the earlier notes could not reach (docs/notes/
 * MSGDATA_LoadBank.c.txt, pkt_02046110.c.txt) are the `ldreq r0, [r4]`
 * reload of the archive pointer in the resident arm.  Every plain spelling
 * CSEs it into the load already made for the offset table; declaring the
 * member `volatile` keeps both loads and leaves every other instruction,
 * the predication included, unchanged.
 */
void MSGDATA_LoadBank(struct MsgBankLoad *bank)
{
    u32 size;
    u32 sectionOffset = bank->file->langOff[bank->langIndex];

    if (bank->stream == 0) {
        bank->base = (u8 *)bank->file + sectionOffset;
    } else {
        ARC_TOOL_SeekHandle(bank->stream, bank->origin + sectionOffset);
        ARC_TOOL_ReadHandle(bank->stream, 4, &size);
        ARC_TOOL_SeekHandle(bank->stream, bank->origin + sectionOffset);
        ARC_TOOL_ReadHandle(bank->stream, size, bank->base);
    }
}



/*
 * Re-read the clamped index for the header at +0 and, if it moved, record
 * it at +0x1a and redraw through MSGDATA_LoadBank when the enable byte at +0x1b
 * says so.
 *
 * The two guards do not share an exit: the first `popeq` returns from the
 * comparison itself and the second `popne` from the enable test, which is
 * what a plain chain of early returns compiles to.  The enable byte is read
 * one instruction before the store to +0x1a: both are separate fields of
 * the same struct, so the compiler is free to schedule the load first and
 * does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_RefreshLanguage.c \
 *       --func MSGDATA_RefreshLanguage --addr 0x02046180 --cc 1.1p1 --arm
 */
void MSGDATA_RefreshLanguage(struct MsgBank *bank)
{
    s32 langIndex = MSGDATA_GetLanguageIndex(bank->file);

    if (bank->langIndex == langIndex) {
        return;
    }
    if (bank->resident != 1) {
        bank->langIndex = (u8)langIndex;
        return;
    }
    bank->langIndex = (u8)langIndex;
    MSGDATA_LoadBank((struct MsgBankLoad *)bank);
}



/*
 * Clamp MSGDATA_GetLanguage's answer to the count the header keeps at +0: past the
 * end wraps back to entry zero.  The comparison is signed (`movge`), so the
 * count is read as a halfword but compared as an int.
 *
 * The verdict is EXACT*, not EXACT: the next function, the one-byte global
 * setter at 0x020461D4, saves nothing, so disasm.py folds it into this
 * function's extent and the inferred range runs sixteen bytes long.  It is
 * decompiled separately in src/matched/MSGDATA_SetLanguage.c and wants seeding
 * into layout/function_starts.txt, which is the integrator's file.
 *
 * `movge r0, #0` in place of a branch is the whole `if` body: one
 * conditional instruction, no shared exit block to reason about, because
 * both arms fall into the same `pop`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_GetLanguageIndex.c \
 *       --func MSGDATA_GetLanguageIndex --addr 0x020461B8 --cc 1.1p1 --arm
 */
s32 MSGDATA_GetLanguageIndex(const struct MsgFile *file)
{
    s32 langIndex = MSGDATA_GetLanguage();

    if (langIndex >= file->langCount) {
        langIndex = 0;
    }
    return langIndex;
}


/* Stores the current text language code.  The getter at 0x020461E4 returns
 * this byte; the message bank loader (msgdata.c) clamps it to the language
 * count of the file it opens, and the config code and the save-control
 * screen set it. */
void MSGDATA_SetLanguage(u8 languageId)
{
    g_Byte_02146A54 = languageId;
}

u8 MSGDATA_GetLanguage(void)
{
    return g_Byte_02146A54;
}
