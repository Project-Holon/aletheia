/*
 * function: BTL_SETUP_SetTrainer
 * address:  0x02013284
 * packet:   pkt_02013284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSeason   0x02012984  thumb
 *   BTL_SETUP_CreateTrainerData   0x02013234  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   TPOKE_DATA_GetTrainerKind   0x0202A3FC  thumb
 *   TR_TOOL_LoadTrainerInfo   0x0202A440  thumb
 *   TR_TOOL_BuildParty   0x0202A4B4  thumb
 *   FORMCHANGE_UpdateSeasonForms   0x0216AAE4  thumb
 *
 * btl_setup.c.  The sub-block filler, and the most-called function of the
 * family: every builder in the range (BTL_SETUP_SetupTrainerSingle, BTL_SETUP_SetupTrainerDouble,
 * BTL_SETUP_SetupTrainerTriple, BTL_SETUP_SetupTrainerRotation, BTL_SETUP_SetupTrainerTag, BTL_SETUP_SetupTrainerMulti, BTL_SETUP_SetupCommAiMulti,
 * all EXACT) calls it once or three times.  It lazily fills two slots - the
 * caller's own out-pointer and the object's +0x48 array entry - then, only if
 * the value argument is non-zero, binds them together and picks the object's
 * +0x1a code from a twelve-way switch.
 *
 * This closes the near miss in docs/notes/pkt_02013284.c.txt, which sat at 48
 * concrete bytes out with the size already exact.  Two things closed it.
 *
 * (1) THE ARITY IS SIX, NOT SEVEN.  The note gave it seven parameters
 * (a0..a6).  The six-parameter form is fixed from outside this function by
 * the matched callers, every one of which passes exactly six
 * (o, a1, n, dst, v, h).  Re-spelling the signature that way took the
 * residue from 48 concrete bytes out to 15 and halved the permuter's
 * instruction score, 525 -> 280, with the size unchanged at 184.
 *
 * (2) THE +0x48 SLOT IS REGISTER-OFFSET ADDRESSED, so its base and its
 * scaled index have to be two separate live values.  The image loads it with
 * `ldr r0, [r7, r6]` where r7 is o+0x48 and r6 is n*4; writing the access as
 * a single pointer, `slot = (u32 *)(o + 0x48 + n * 4)`, folds the two into
 * one value and the allocator then has one fewer value to colour, which is
 * what produced the r5/r6/r7 rotation the permuter reported.  Splitting it
 * into a `u8 *base` and a separate `u32 off`, and indexing as
 * `*(u32 *)(base + off)`, keeps both values live and gives the original
 * registers and the original `lsls` / `adds` order.  A `u32 *` base with a
 * divided index (`base[off / 4]`) does NOT work: the compiler folds the
 * scaling back out and the rotation returns.
 *
 * The permuter was the diagnostic here rather than the fix.  `--explain` on
 * the seven-parameter source printed a clean three-way register rotation
 * (r7->r6, r6->r7, r5->...), which is what said the residue was an allocation
 * tie and not a mistranslation, and on the six-parameter source it printed
 * the same rotation at 15 bytes out with every instruction aligned - which
 * localised the fix to the one value that was missing.  Its own best results
 * were rejected on both passes: hill found temp(tmp=*slot) at 11 bytes out
 * but with the instruction score RISING 280 -> 460, the signature of a
 * coincidental byte alignment rather than a real fix.
 *
 * The switch is dense from 2 to 11 with 0, 1, 5 and 10 falling to the
 * default, which is what makes the PC-relative halfword table exist; the
 * `cmp r0, #0xb / bhi` pair is the table's range check.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetTrainer.c \
 *       --func BTL_SETUP_SetTrainer --addr 0x02013284 --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Out;
struct Party;
extern struct Party *POKEPARTY_Create(u32 heap);
extern void *BTL_SETUP_CreateTrainerData(u32 heap);
extern void TR_TOOL_LoadTrainerInfo(u32 id, struct Out *out, u32 heap);
extern void TR_TOOL_BuildParty(u32 a, u32 b, u32 c);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern void FORMCHANGE_UpdateSeasonForms(u32 a, u32 b, u32 c);
extern u8 TPOKE_DATA_GetTrainerKind(u32 key);

void BTL_SETUP_SetTrainer(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h)
{
    u8 *base;
    u32 off;

    if (*dst == 0) {
        *dst = (u32)POKEPARTY_Create(h);
    }
    off = n * 4;
    base = o + 0x48;
    if (*(u32 *)(base + off) == 0) {
        *(u32 *)(base + off) = (u32)BTL_SETUP_CreateTrainerData(h);
    }
    if (v == 0) {
        return;
    }
    TR_TOOL_LoadTrainerInfo(v, (struct Out *)(*(u32 *)(base + off)), h);
    TR_TOOL_BuildParty(v, *dst, h);
    FORMCHANGE_UpdateSeasonForms((u32)a1, *dst, GAME_DATA_GetSeason((const struct BigObj *)((u32)a1)));
    switch (TPOKE_DATA_GetTrainerKind(*(u32 *)(*(u32 *)(base + off) + 4))) {
    case 2:
    case 3:
        ((struct Obj00155 *)o)->f1A = 0x47e;
        break;
    case 7:
    case 8:
        ((struct Obj00155 *)o)->f1A = 0x47f;
        break;
    case 4:
    case 11:
        ((struct Obj00155 *)o)->f1A = 0x480;
        break;
    case 6:
    case 9:
        ((struct Obj00155 *)o)->f1A = 0x491;
        break;
    default:
        ((struct Obj00155 *)o)->f1A = 0x47d;
        break;
    }
}
