/*
 * function: sub_02045B38
 * address:  0x02045B38
 * packet:   pkt_02045B38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7E8C     0x020A7E8C  data
 *   sub_02030734   0x02030734  arm
 *   func_02046084  0x02046084  arm
 *   func_02046110  0x02046110  arm
 *   func_020461B8  0x020461B8  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049578  0x02049578  arm
 *
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
    u32 size;
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

extern char g_020A7E8C[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct ArcFile;
extern u32 func_02049578(struct ArcFile *arc, u32 member);
extern struct MsgFile *func_02046084(void *stream, u32 origin, u16 heapId);
extern u8 func_020461B8(const void *file);
extern void func_02046110(struct MsgBank *bank);

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
    bank->langIndex = func_020461B8(bank->file);

    if (bank->resident != 0) {
        bank->base = sub_02030734(bank->heapId, bank->file->size, 0,
                                  g_020A7E8C, 0x7b);
        func_02046110(bank);
    } else {
        bank->base = 0;
    }
    return bank;
}
