/*
 * function: CLACT_CreateUnit
 * address:  0x0204B100
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   CLACT_ClearActor  0x0204CAE4  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   CLACT_SetUnitDrawEnable   0x0204B22C  arm
 *   CLACT_LinkUnit  0x0204BBC8  arm
 *
 * The cell-actor bank constructor.  The __FILE__ pointer is the same
 * s_clact_c 0x020A7F74 that src/matched/CLACT_LoadArchiveData.c pins, so this whole
 * 0x0204Bxxx run is clact.c.
 *
 * Allocate the 0x18-byte bank header, zero it, allocate `count` 0xE4-byte
 * actor records behind it, record the count at +0x0c and the caller's flag at
 * +0x0f, run each record through CLACT_ClearActor, then the three bank-wide
 * initialisers.  src/matched/CLACT_DeleteUnit.c is the exact inverse.
 *
 * The two allocation sites are one pool word apart in the source's line
 * numbering: 0x6eb is materialised from the literal pool and 0x6ef is derived
 * with `add r0, r5, #4`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md), so
 * the second call has to be written with the literal 0x6ef, not with a second
 * pooled constant.
 *
 * The zero shared by the two `clear` arguments, the fill byte and the loop
 * counter all live in r7 for the whole function; `i` therefore has to be a
 * function-scope local, not declared inside the `for`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateUnit.c \
 *       --func CLACT_CreateUnit --addr 0x0204B100 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Actor {
    u8 pad_00[0xe4];
};

struct Bank {
    struct Actor *actors;   /* 0x00 */
    u8            pad_04[8];
    u16           count;    /* 0x0c */
    u8            pad_0e;
    u8            unk_0f;   /* 0x0f */
    u8            pad_10[8];
};

extern char s_clact_c[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02082BCC(void *dst, int fill, u32 size);
struct Obj;
extern void CLACT_ClearActor(struct Obj *o);
extern void  CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void  CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
extern void  CLACT_LinkUnit(struct Bank *bank);

struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId)
{
    struct Bank *bank;
    int          i;

    bank = sub_02030734(heapId, sizeof(struct Bank), 0, s_clact_c, 0x6eb);
    func_02082BCC(bank, 0, sizeof(struct Bank));

    bank->actors = sub_02030734(heapId, count * sizeof(struct Actor), 0,
                                s_clact_c, 0x6ef);
    bank->count = count;
    bank->unk_0f = flag;

    for (i = 0; i < count; i++) {
        CLACT_ClearActor((struct Obj *)(&bank->actors[i]));
    }

    CLACT_SetUnitDefaultRenderer(bank);
    CLACT_SetUnitDrawEnable(bank, 1);
    CLACT_LinkUnit(bank);

    return bank;
}
