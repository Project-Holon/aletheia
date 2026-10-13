/*
 * function: GAME_EVENT_Create
 * address:  0x020122C0
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734        0x02030734  arm
 *   _GameEventFileName   0x020A727C  data
 *
 * Constructor for a five-word descriptor: allocate the 0x14-byte header off
 * heap 4, fill it with the caller's two handles and a zeroed counter,
 * allocate the caller-sized payload off the same heap and hang it at +0xc,
 * and record the owner at +0x10.
 *
 * Both allocations go through sub_02030734, whose last two arguments are
 * the file/line debug site pair (see src/matched/sub_02030734.c).  The file
 * pointer is one pool word loaded twice, so it is a single ABS32 into the
 * packed string area and has to be declared as an extern pinned by address
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), never as a
 * literal __FILE__.  The two line numbers, 55 and 59, are four apart but
 * each is its own `movs`: they are not consecutive arguments of one call,
 * so the add-chain form does not apply
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The owner pointer and the payload size arrive in r0 and r3 and are both
 * live across the first call, so r5 takes the owner and the size is spilled
 * to [sp,#4] rather than costing a sixth callee-saved register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_Create.c \
 *       --func GAME_EVENT_Create --addr 0x020122C0 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc {
    void *unk_00;
    void *unk_04;
    u32   unk_08;
    void *unk_0c;
    void *unk_10;
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern const char _GameEventFileName[];

struct Desc *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size)
{
    struct Desc *d;

    d = sub_02030734(4, sizeof(struct Desc), 1, _GameEventFileName, 55);
    d->unk_00 = a;
    d->unk_04 = b;
    d->unk_08 = 0;
    d->unk_0c = sub_02030734(4, size, 1, _GameEventFileName, 59);
    d->unk_10 = owner;
    return d;
}
