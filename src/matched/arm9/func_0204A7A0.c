/*
 * function: CLACT_RegisterEmptyCharacter
 * address:  0x0204A7A0
 * packet:   pkt_0204A6C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   g_ClactEmptyCharTemplate     0x020A1430  data
 *   s_clact_c      0x020A7F74  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   CLACT_SetupCharacterVram   0x0204DACC  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *
 * Claims the first busy cell (bit 31 of +0x3c) of the singleton's table at
 * +0x104, like its sibling CLACT_RegisterCharacter, but builds a fresh character
 * record: the 0x18-byte template at 0x020A1430 is copied to the stack, the
 * DISPCNT OBJ-mapping bits and the size patched in, and the sixth word
 * holds a scratch block from GFL_HEAP_Alloc (clact.c, line 0x3c8) that is
 * registered through CLACT_SetupCharacterVram and freed at the end.  Returns the cell
 * index, or -1 when none is found.
 *
 * Shape notes:
 *  - `struct Slot *slot` is declared before `u32 i` (wave 18): that order
 *    gives the image's whole allocation (size r8, a2 r7, heapId lr, the -1
 *    in sb, i r6, slot r5, &t r4).
 *  - The body sits inside `if (i != (u32)-1) { ... return i; }` with a
 *    trailing `return -1;`.  The image returns the compare's -1 register
 *    (`moveq r0, sb`).  An early `if (i == -1) return i;` returns r6
 *    (1 out); an early `return -1;` recolours the function (47).  With the
 *    guard inverted the -1 is returned from the same register the compare
 *    used and the colouring is kept.  See
 *    docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_RegisterEmptyCharacter.c  *       --func CLACT_RegisterEmptyCharacter --addr 0x0204A7A0 --cc 1.1p1 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Slot  { u8 pad_00[0x24]; u32 unk_24; u8 pad_28[0x14]; u32 unk_3c; };

struct Owner {
    u8            pad_00[8];
    struct Slot  *slots;
    void         *slots2;
    u8            pad_10[4];
    volatile u16  count;
    volatile u16  count2;
};

struct Sys { u8 pad_00[0x104]; struct Owner owner; };

struct Templ { u32 w0, w1, w2, w3, w4; void *w5; };

extern struct Sys *g_ClactSystem;
extern const struct Templ g_ClactEmptyCharTemplate;
extern char s_clact_c[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Ovr;
struct Res;
struct Sink;
extern void CLACT_SetupCharacterVram(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);
extern u32 GFL_HEAP_Free(void *p);

s32 CLACT_RegisterEmptyCharacter(u32 size, u32 a2, u16 heapId)
{
    struct Sys   *sys;
    struct Owner *owner;
    struct Slot  *slot;
    u32 i;
    struct Templ t;

    sys   = g_ClactSystem;
    owner = &sys->owner;

    for (i = 0; i < owner->count; i++) {
        if ((owner->slots[i].unk_3c >> 31) != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot = &sys->owner.slots[i];
        t = g_ClactEmptyCharTemplate;
        t.w2 = *(volatile u32 *)0x04000000 & 0x00300010;
        t.w4 = size;
        t.w5 = GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), size, 1, s_clact_c, 0x3c8);

        CLACT_SetupCharacterVram((struct Res *)(&g_ClactSystem->owner), i, (struct Sink *)(&t), 0, a2);

        slot->unk_3c &= ~0x80000000;
        slot->unk_24 = 0;
        slot->unk_3c &= ~1;
        GFL_HEAP_Free(t.w5);
        return i;
    }
    return -1;
}
