/*
 * unit:     yes
 * address:  0x0201A920
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKEPARTY_Create, POKEPARTY_Init, POKEPARTY_InitEx, POKEPARTY_Add,
 *           POKEPARTY_RemoveMember
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * POKEPARTY_Init is the six-slot spelling of POKEPARTY_InitEx and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * POKEPARTY_Add's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * POKEPARTY_RemoveMember compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * symbols:
 *   pokeparty_File  0x020A7304  data
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   POKEPARTY_SetSlotFlag  0x0201ACDC  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

struct PartyMon {
    u32 w[0x37];
};

struct Party {
    s32 capacity;
    s32 count;
    struct PartyMon mon[6];
    u8  unk530;
};

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
struct Sav;
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern void POKEPARTY_SetSlotFlag(void *p, u32 pos, u32 mode);

extern const char pokeparty_File[];

void POKEPARTY_Init(struct Party *p);
void POKEPARTY_InitEx(struct Party *p, s32 capacity);

struct Party *POKEPARTY_Create(u32 heap)
{
    struct Party *p = (struct Party *)func_02030734(heap, sizeof(struct Party), 0,
                                                   pokeparty_File, 65);

    POKEPARTY_Init(p);
    return p;
}

void POKEPARTY_Init(struct Party *p)
{
    POKEPARTY_InitEx(p, 6);
}

void POKEPARTY_InitEx(struct Party *p, s32 capacity)
{
    s32 i;

    MIi_CpuClearFast(0, p, sizeof(struct Party));
    p->capacity = capacity;
    p->count = 0;
    p->unk530 = 0;
    for (i = 0; i < 6; i++) {
        POKE_TOOL_ClearPartyParam((struct Sav *)(&p->mon[i]));
    }
}

u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src)
{
    if (p->count >= p->capacity) {
        return 0;
    }
    p->mon[p->count] = *src;
    POKEPARTY_SetSlotFlag(p, p->count, 1);
    p->count = p->count + 1;
    return 1;
}

u32 POKEPARTY_RemoveMember(struct Party *p, s32 idx)
{
    s32 i;

    for (i = idx; i < p->count - 1; i++) {
        p->mon[i] = p->mon[i + 1];
    }
    POKE_TOOL_ClearPartyParam((struct Sav *)(&p->mon[i]));
    p->count = p->count - 1;
    return 1;
}
