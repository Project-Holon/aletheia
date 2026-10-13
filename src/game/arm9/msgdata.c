/*
 * file:     msgdata.c
 * unit:     yes
 * function: func_02045B38, func_02045C04, func_02045C44, func_02045CAC, func_02045E04, func_02045E3C, func_02045EC0, func_02045F50, func_02045F5C, func_02046084, func_02046110, sub_02046180, sub_020461B8
 * address:  0x02045B38
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bmp.c at 0x02045B38 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   sub_02030734  0x02030734  arm
 *   g_020A7E8C     0x020A7E8C  data
 *   func_020461B8  0x020461B8  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049578  0x02049578  arm
 *   func_02049238  0x02049238  arm
 *   func_0204581C  0x0204581C  arm
 *   func_02045E04  0x02045E04  arm
 *   func_02046180  0x02046180  arm
 *   func_020495F4  0x020495F4  arm
 *   func_0204960C  0x0204960C  arm
 *   sub_02045E3C  0x02045E3C  arm
 *   sub_0204960C  0x0204960C  arm
 *   sub_020495F4  0x020495F4  arm
 *   sub_02045CAC  0x02045CAC  arm
 *   func_02082D44  0x02082D44  arm
 *   sub_02046110  0x02046110  arm
 *   sub_020461E4  0x020461E4  arm
 *   sub_020457B0 0x020457B0 arm
 *   sub_020458F8 0x020458F8 arm
 *   sub_02045900 0x02045900 arm
 *   func_02045A00 0x02045A00 arm
 *   sub_02045A90 0x02045A90 arm
 *   func_02045A98 0x02045A98 arm
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

extern u32 func_020307B0(void *p);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_02049578(struct ArcFile *arc, u32 member);
extern s32 sub_020461E4(const struct MsgFile *file);
extern void func_02049238(void *handle);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void func_0204960C(void *stream, u32 pos);
extern void func_0204581C(struct Strbuf *vec);
extern void func_02082D44(const void *src, void *dest, u32 size);
struct Strbuf *sub_020457B0(u32 capacity, u32 heapId);
u16 sub_020458F8(struct Strbuf *vec);
void sub_02045900(struct Strbuf *vec, u32 length);
void func_02045A00(struct Strbuf *buf, const void *src, u32 n);
u16 *sub_02045A90(struct Strbuf *vec);
u16 func_02045A98(void);
struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
u32 func_02045C04(struct MsgBank *bank);
struct MsgBank *func_02045C44(const void *file, u32 heapId);
void func_02045CAC(struct MsgBank *bank, u32 index, struct Strbuf *dest);
void sub_02045E04(struct Strbuf *str, u32 msgIndex);
u32 func_02045E3C(u16 *str, u32 count, u32 msgIndex);
struct Strbuf *sub_02045EC0(struct MsgBank *bank, u32 index);
u16 sub_02045F50(const struct MsgBank *bank);
void func_02045F5C(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen);
struct MsgFile *func_02046084(void *stream, u32 origin, u16 heapId);
void func_02046110(struct MsgBankLoad *bank);
void sub_02046180(struct MsgBank *bank);
s32 sub_020461B8(const struct MsgFile *file);
extern char g_020A7E8C[];



/*
 * The archive-backed constructor for the message bank whose object layout is
 * pinned by src/matched/unit_02045C44.c, and the reason that object carries
 * both a `stream` handle and a `resident` flag.  func_02045C44 builds a bank
 * over a file the caller already has; this one opens the archive, seeks the
 * member, reads its header and then decides: a resident bank allocates the
 * whole payload up front and calls func_02046110 to index it, a streamed bank
 * leaves `base` null and reads entries on demand in func_02045CAC.
 *
 * The allocation tags are 0x68 for the bank and 0x7b for the payload, both
 * passed as the fifth argument on the stack, with the same BSS provenance
 * object at 0x020A7E8C in the fourth (not a __FILE__ string; see the note in
 * unit_02045C44.c).  The provenance pointer and the constant zero are each
 * loaded once into a callee-saved register and reused at both call sites,
 * which is what pins them as plain literals at the calls rather than named
 * locals.
 *
 * The file offset returned by func_02049578 is bound to a local: the original
 * spends `mov r1, r0` on it before the store to +0x10, four bytes that vanish
 * if the store's value is re-read from the field for the func_02046084 call
 * (docs/idioms/cmp-operand-order-names-the-temporary.md, same tell).  The
 * stream handle and the file pointer are not: both are read back from the
 * field and the compiler forwards the store it just made.
 *
 * The resident arm is the fall-through, so the guard is spelled `!= 0` and the
 * one-store arm is left to be if-converted into `streq`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045B38.c \
 *       --func sub_02045B38 --addr 0x02045B38 --cc 1.1p1 --arm
 */
struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId)
{
    struct MsgBank *bank;
    u32 origin;

    bank = (struct MsgBank *)sub_02030734(heapId, 0x1c, 0, g_020A7E8C, 0x68);
    bank->heapId = (u16)heapId;
    bank->stream = func_020490F4(arcId, heapId);
    origin = func_02049578(bank->stream, fileId);
    bank->origin = origin;
    bank->resident = (u8)resident;
    bank->file = func_02046084(bank->stream, origin, bank->heapId);
    bank->langIndex = sub_020461B8(bank->file);

    if (bank->resident != 0) {
        bank->base = sub_02030734(bank->heapId, bank->file->size, 0,
                                  g_020A7E8C, 0x7b);
        func_02046110((struct MsgBankLoad *)bank);
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
 *   python tools/match.py one --src src/matched/func_02045C04.c \
 *       --func func_02045C04 --addr 0x02045C04 --cc 1.1p1 --arm
 */
u32 func_02045C04(struct MsgBank *bank)
{
    if (bank->stream != 0) {
        func_020307B0((void *)bank->file);
        if (bank->base != 0) {
            func_020307B0(bank->base);
        }
        func_02049238(bank->stream);
    }
    return func_020307B0(bank);
}



/*
 * The whole of pkt_02045C44, 448 bytes with both literal pools: the message
 * bank's constructor and its one reader.  Both functions are EXACT
 * individually as well (src/matched/func_02045C44.c and
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
 * straight to func_02045A00.  Streamed: the descriptor is an 8-byte archive
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
 * end and has 41 pool references image-wide.  In func_02045C44 the
 * allocator's third argument (clear) shares one `mov r5, #0` with the two
 * zero field stores, so it is written as a plain literal at the call rather
 * than bound to a named local (the shape of src/matched/sub_020457B0.c).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045C44.c \
 *       --addr 0x02045C44 --arm
 */
struct MsgBank *func_02045C44(const void *file, u32 heapId)
{
    struct MsgBank *bank;

    bank = (struct MsgBank *)sub_02030734(heapId, 0x1c, 0, g_020A7E8C, 0xa6);
    bank->heapId = (u16)heapId;
    bank->stream = 0;
    bank->origin = 0;
    bank->resident = 1;
    bank->file = (const struct MsgFile *)file;
    bank->langIndex = sub_020461B8(bank->file);
    func_02046110((struct MsgBankLoad *)bank);
    return bank;
}



void func_02045CAC(struct MsgBank *bank, u32 index, struct Strbuf *dest)
{
    u32 size;
    struct MsgEntry *entry;

    if (index >= bank->file->count) {
        func_0204581C(dest);
        return;
    }

    sub_02046180(bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        func_0204960C(bank->stream, pos + (index * 8 + 4));
        func_020495F4(bank->stream, 8, &bank->cache);
        entry = &bank->cache;
    } else {
        entry = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    if (bank->resident == 0) {
        void *encrypted;

        size = entry->length * 2;
        encrypted = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
                                 0, g_020A7E8C, 0xd6);
        if (encrypted != 0) {
            func_0204960C(bank->stream,
                          entry->offset + (bank->origin
                              + bank->file->langOff[bank->langIndex]));
            func_020495F4(bank->stream, size, encrypted);
            func_02045A00(dest, encrypted, entry->length);
            func_020307B0(encrypted);
        }
    } else {
        func_02045A00(dest, (u8 *)bank->base + entry->offset, entry->length);
    }

    func_02045E04(dest, index);
}



/*
 * Advance the object by one: read its current index (sub_020458F8), ask
 * sub_02045E3C for the entry one past it in the list sub_02045A90 returns,
 * and install the answer with sub_02045900.
 *
 * Three of the four calls need the object pointer, so it is pinned in r6
 * for the whole body; the incoming second argument survives in r5 across
 * two calls before reaching sub_02045E3C's r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045E04.c \
 *       --func sub_02045E04 --addr 0x02045E04 --cc 1.1p1 --arm
 */
void sub_02045E04(struct Strbuf *str, u32 msgIndex)
{
    s32 used = sub_020458F8(str);

    sub_02045900(str, func_02045E3C(sub_02045A90(str), used + 1, msgIndex));
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
 * end-of-string code func_02045A98() returns (0xFFFF in this build), and the
 * function returns the index of that unit, i.e. the decoded length; if no
 * terminator is found inside count units it returns count.
 *
 * Note for the asset side: there is no compression layer on top of this
 * cipher. Decoded streams are plain code units plus in-band control codes
 * (0xFFFF terminator, 0xFFFE line break, 0xF000 escape introducer followed
 * by a kind word, an argument count and that many argument words).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045E3C.c \
 *       --func func_02045E3C --addr 0x02045E3C --cc 1.1p1
 */
u32 func_02045E3C(u16 *str, u32 count, u32 msgIndex)
{
    u16 eos = func_02045A98();
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
 * sub_02045CAC, and returns the allocated buffer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045EC0.c \
 *       --func sub_02045EC0 --addr 0x02045EC0 --cc 1.1p1 --arm
 */
struct Strbuf *sub_02045EC0(struct MsgBank *bank, u32 index)
{
    struct MsgEntry *entry;
    struct Strbuf *str;

    sub_02046180(bank);

    if (bank->resident == 0) {
        u32 pos = bank->origin + bank->file->langOff[bank->langIndex];

        func_0204960C(bank->stream, pos + (index * 8 + 4));
        func_020495F4(bank->stream, 8, &bank->cache);
        entry = &bank->cache;
    } else {
        entry = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
    }

    str = sub_020457B0(entry->length, bank->heapId);
    func_02045CAC(bank, index, str);
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
 *   python tools/match.py one --src src/matched/sub_02045F50.c \
 *       --func sub_02045F50 --addr 0x02045F50 --cc 1.1p1 --arm
 */
u16 sub_02045F50(const struct MsgBank *bank)
{
    return bank->file->count;
}



/*
 * msgdata.c: read string msgIndex into str (at most maxLen characters),
 * either from the resident bank (mode != 0) or by seeking the archive file,
 * then decode it in place (func_02045E3C) and terminate it with the EOM
 * code (func_02045A98).
 *
 * The 11-byte scheduling residue of docs/notes/pkt_02045F5C.c.txt was the
 * first test's polarity: written `mode == 0` with the file arm first, the
 * compiler predicates the else arm (ldrne/addne/addne/bne) and schedules
 * the file arm's loads in the image's order.
 */
void func_02045F5C(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen)
{
    const struct MsgEntry *entry;
    u32 count;
    u32 len;

    sub_02046180(bank);

    if (bank->resident == 0) {
        u32 sectionOffset = bank->file->langOff[bank->langIndex];
        func_0204960C(bank->stream, (bank->origin + sectionOffset) + (msgIndex * 8 + 4));
        func_020495F4(bank->stream, 8, &bank->cache);
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
            func_0204960C(bank->stream, (bank->origin + sectionOffset) + entry->offset);
            func_020495F4(bank->stream, readBytes, str);
        }
    } else {
        const u16 *src = (const u16 *)((u8 *)bank->base + entry->offset);
        u32 i;
        for (i = 0; i < count; i++) {
            str[i] = src[i];
        }
    }

    len = func_02045E3C(str, count, msgIndex);
    str[len] = func_02045A98();
}



/*
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
 *   python tools/match.py one --src src/matched/func_02046084.c \
 *       --func func_02046084 --addr 0x02046084 --cc 1.1p1 --arm
 */
struct MsgFile *func_02046084(void *stream, u32 origin, u16 heapId)
{
    u8 hdr[12];
    struct MsgFileHeader *hp;
    struct MsgFile *file;

    func_0204960C(stream, origin);
    hp = (struct MsgFileHeader *)hdr;
    func_020495F4(stream, sizeof(struct MsgFileHeader), hp);

    file = (struct MsgFile *)sub_02030734(heapId, hp->langCount * 4 + 0xc, 0,
                                          g_020A7E8C, 0x1f3);
    func_02082D44(hp, file, sizeof(struct MsgFileHeader));
    func_020495F4(stream, file->langCount * 4, file->langOff);
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
 * func_02046110.c.txt, pkt_02046110.c.txt) are the `ldreq r0, [r4]`
 * reload of the archive pointer in the resident arm.  Every plain spelling
 * CSEs it into the load already made for the offset table; declaring the
 * member `volatile` keeps both loads and leaves every other instruction,
 * the predication included, unchanged.
 */
void func_02046110(struct MsgBankLoad *bank)
{
    u32 size;
    u32 sectionOffset = bank->file->langOff[bank->langIndex];

    if (bank->stream == 0) {
        bank->base = (u8 *)bank->file + sectionOffset;
    } else {
        func_0204960C(bank->stream, bank->origin + sectionOffset);
        func_020495F4(bank->stream, 4, &size);
        func_0204960C(bank->stream, bank->origin + sectionOffset);
        func_020495F4(bank->stream, size, bank->base);
    }
}


/*
 * Re-read the clamped index for the header at +0 and, if it moved, record
 * it at +0x1a and redraw through sub_02046110 when the enable byte at +0x1b
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
 *   python tools/match.py one --src src/matched/sub_02046180.c \
 *       --func sub_02046180 --addr 0x02046180 --cc 1.1p1 --arm
 */
void sub_02046180(struct MsgBank *bank)
{
    s32 langIndex = sub_020461B8(bank->file);

    if (bank->langIndex == langIndex) {
        return;
    }
    if (bank->resident != 1) {
        bank->langIndex = (u8)langIndex;
        return;
    }
    bank->langIndex = (u8)langIndex;
    func_02046110((struct MsgBankLoad *)bank);
}


/*
 * Clamp sub_020461E4's answer to the count the header keeps at +0: past the
 * end wraps back to entry zero.  The comparison is signed (`movge`), so the
 * count is read as a halfword but compared as an int.
 *
 * The verdict is EXACT*, not EXACT: the next function, the one-byte global
 * setter at 0x020461D4, saves nothing, so disasm.py folds it into this
 * function's extent and the inferred range runs sixteen bytes long.  It is
 * decompiled separately in src/matched/sub_020461D4.c and wants seeding
 * into layout/function_starts.txt, which is the integrator's file.
 *
 * `movge r0, #0` in place of a branch is the whole `if` body: one
 * conditional instruction, no shared exit block to reason about, because
 * both arms fall into the same `pop`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020461B8.c \
 *       --func sub_020461B8 --addr 0x020461B8 --cc 1.1p1 --arm
 */
s32 sub_020461B8(const struct MsgFile *file)
{
    s32 langIndex = sub_020461E4(file);

    if (langIndex >= file->langCount) {
        langIndex = 0;
    }
    return langIndex;
}
