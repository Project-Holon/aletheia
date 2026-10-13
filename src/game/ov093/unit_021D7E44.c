/*
 * file:     unit_021D7E44.c
 * unit:     yes
 * function: func_021D7E44, func_021D7E90, func_021D7EB4, func_021D7EF0, func_021D7F00, func_021D7F2C, func_021D7F38, func_021D7F4C, func_021D7F60, func_021D7F88, func_021D7FBC, func_021D7FF8, func_021D804C, func_021D8058, func_021D805C, func_021D806C, func_021D8090, func_021D80A8, func_021D80BC
 * address:  0x021D7E44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   data_021F6360  0x021F6360  data  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_02019C90  0x02019C90  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0202A3FC 0x0202A3FC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0202A230 0x0202A230 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   d_021F042D     0x021F042D  data  ov093  a1
 *   func_02020FE4 0x02020FE4 thumb
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   sub_0201BD28   0x0201BD28  thumb
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   func_021B8C50  0x021B8C50  thumb  ov093
 *   func_021B8D38  0x021B8D38  thumb  ov093
 *   func_021B8778  0x021B8778  thumb  ov093
 */
#include "btl_calc_types.h"
#include "unit_021D794C_types.h"
#include "../arm9/btl_setup_types.h"

struct BtlPokeParam;
struct BtlParty;

/* Number of move ids (0 is not a move). */
#define BTL_MOVE_ID_LIMIT 0x230
/* BattleSetupParam.competitor value of a trainer battle. */
#define BTL_COMPETITOR_TRAINER 1
/* Argument index of the money rate in the trainer record reader. */
#define TRAINER_PARAM_MONEY_RATE 10
/* Value id of the level in the Pokemon value reader. */
#define POKE_VALUE_LEVEL 158

u32 func_021D78AC(u32 range);
u16 func_021D5444(struct BtlPokeParam *bpp);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
u32 func_02019C90(u16 species, u16 form, u32 paramId);
extern u8 func_0202A3FC(u32 trainerId);
extern u32 func_0201AA18(struct Party *party);
extern void *func_0201AB28(struct Party *party, u32 index);
extern u32 func_0202A230(u32 trainerId, u32 paramIndex);
extern u32 func_02017E1C(void *mon, u32 valueId, u32 arg);
u8 func_021B9B94(struct BtlParty *party);
extern struct BtlPokeParam *func_021B9C00(struct BtlParty *party, u32 index);
extern u32 func_02020FE4(void *mon, u32 paramId, u32 heapId);
extern int func_021D5814(struct BtlPokeParam *bpp, int type);
extern u32 func_021B8588(void *main);
extern u8 func_021D5440(struct BtlPokeParam *bpp);
extern int func_021B8D8C(void *main, void *posTable, u32 pokeId);
extern u32 sub_0201BD28(u16 moveId, u32 fieldIndex);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 bit);
extern u8 func_021B8C50(void *main, u32 basePos, int lane);
extern u8 func_021B8D38(void *main, void *posTable, int posCode, u8 *outPokeIds);
extern u8 func_021B8778(void *main, int posCode, u8 *outPositions);
u16 func_021D7E44(const u16 *excludedMoves, int excludedCount);
int func_021D7E90(const u16 *list, u32 count, u32 value);
u32 func_021D7EB4(struct BtlPokeParam *bpp);
u32 func_021D7EF0(u32 rule);
u32 func_021D7F00(u32 rule);
u8 func_021D7F2C(u32 rule, u8 startIndex);
int func_021D7F38(u32 trainerId);
int func_021D7F4C(u32 trainerId);
int func_021D7F60(u32 trainerId);
u32 func_021D7F88(struct BattleSetupParam *setup);
u32 func_021D7FBC(struct BattleTrainerData *trainer, struct Party *party);
u32 func_021D7FF8(u32 badgeCount, struct BtlParty *party);
void func_021D804C(u32 heapId);
void func_021D8058(void);
u32 func_021D805C(void *mon, u32 paramId);
u32 func_021D806C(const u8 *pokeIds);
void func_021D8090(u32 packed, u8 *pokeIds);
int func_021D80A8(struct BtlPokeParam *bpp);
int func_021D80BC(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId);
extern struct BtlCalcWork data_021F6360;
/* Money lost on defeat per level point, by badge count (0 to 8). */
extern u8 d_021F042D[];


/* A random move id that is not in the given list (the move id table is the work table). */
u16 func_021D7E44(const u16 *excludedMoves, int excludedCount)
{
    u16 moveId;
    u16 count = 0;

    for (moveId = 1; moveId < BTL_MOVE_ID_LIMIT; moveId++) {
        if (func_021D7E90(excludedMoves, excludedCount, moveId) == 0)
            data_021F6360.workTable[count++] = moveId;
    }
    return data_021F6360.workTable[(u16)func_021D78AC(count)];
}

/* True when the value is in the list of halfwords. */
int func_021D7E90(const u16 *list,u32 count,u32 value) { u32 index; for(index=0;index<count;index++) { if(value==list[index]) return 1; } return 0; }


/* Experience a defeated Pokemon gives: base experience * level / 5. */
u32 func_021D7EB4(struct BtlPokeParam *bpp)
{
    int species = func_021D5444(bpp);
    u16 form = func_021D59B4(bpp, BTL_BPP_VALUE_FORM);
    u16 level = func_021D59B4(bpp, BTL_BPP_VALUE_LEVEL);
    u32 baseExp = func_02019C90(species, form, 9);
    return (baseExp * level) / 5;
}

/*
 * True for the rules with several fighters per side that are not rotation (double, triple).
 * lever: nonzero/non-3 conjunction puts return 1 before the return 0 arm.
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * semantics: original compares full-word r0 with 0 and 3; no arithmetic,
 * domain bounds, narrowed input, uninitialized values or side effects.
 */
u32 func_021D7EF0(u32 rule)
{
    if (rule != BTL_RULE_SINGLE && rule != BTL_RULE_ROTATION) return 1;
    return 0;
}

/* Number of Pokemon that fight at once on one side: 1, 2, 3, and 1 for rotation. */
u32 func_021D7F00(u32 rule) { switch(rule) { case BTL_RULE_SINGLE:return 1; case BTL_RULE_DOUBLE:return 2; case BTL_RULE_TRIPLE:return 3; case BTL_RULE_ROTATION:return 1; default:return 1; } }


/* First list index to scan: 3 in a rotation battle, else the given start. */
u8 func_021D7F2C(u32 rule, u8 startIndex)
{
    if (rule == BTL_RULE_ROTATION)
        startIndex = 3;
    return startIndex;
}

/* Trainer table category 2 (guess: gym leader). */
int func_021D7F38(u32 trainerId) { if(func_0202A3FC(trainerId)==2) return 1; return 0; }

/* Trainer table category 3 (guess: Elite Four). */
int func_021D7F4C(u32 trainerId) { if(func_0202A3FC(trainerId)==3) return 1; return 0; }

/* A boss trainer: category 2 or 3, or trainer 89. */
int func_021D7F60(u32 trainerId) { if(func_021D7F38(trainerId)) return 1; if(func_021D7F4C(trainerId)) return 1; return trainerId==89; }

/* Prize money of a trainer battle: the sum over the two enemy trainer slots (1 and 3). */
u32 func_021D7F88(struct BattleSetupParam *setup) { u32 money=0; if(setup->competitor==BTL_COMPETITOR_TRAINER) { if(setup->trainerData[1] && setup->party[1]) money+=func_021D7FBC(setup->trainerData[1],setup->party[1]); if(setup->trainerData[3] && setup->party[3]) money+=func_021D7FBC(setup->trainerData[3],setup->party[3]); } return money; }

/* Prize money of one trainer: money rate * level of the last party member * 4. */
u32 func_021D7FBC(struct BattleTrainerData *trainer,struct Party *party) { u8 count; void *lastMon; u32 moneyRate; if(party) { count=(u8)func_0201AA18(party); if(count) { lastMon=func_0201AB28(party,count-1); moneyRate=func_0202A230(trainer->trainerId,TRAINER_PARAM_MONEY_RATE); return moneyRate*func_02017E1C(lastMon,POKE_VALUE_LEVEL,0)*4; } } return 0; }


/* Money lost on defeat: badge table value * highest party level * 4. */
u32 func_021D7FF8(u32 badgeCount, struct BtlParty *party)
{
    u32 count = func_021B9B94(party);
    u32 maxLevel = 1;
    u32 index;
    u32 level;

    for (index = 0; index < count; index++) {
        level = func_021D59B4(func_021B9C00(party, (u8)index), BTL_BPP_VALUE_LEVEL);
        if (level > maxLevel)
            maxLevel = level;
    }
    if (badgeCount >= 9)
        badgeCount = 8;
    return d_021F042D[badgeCount] * (maxLevel << 2);
}

/*
 * Stores the heap id that the battle uses for temporary reads. It sits in the
 * low halfword of the first word of the calculation work, which the shared
 * header (btl_calc_types.h, read only for this lane) declares as a u32 reserved.
 */
void func_021D804C(u32 heapId) { (*(u16 *)&data_021F6360.reserved)=heapId; }

void func_021D8058(void) { }

/* Reads a Pokemon parameter with the stored heap id. */
u32 func_021D805C(void *mon,u32 paramId) { return func_02020FE4(mon,paramId,(*(u16 *)&data_021F6360.reserved)); }

/* Packs six Pokemon ids (5 bits each) into one word. */
u32 func_021D806C(const u8 *pokeIds) { u32 packed=0; u32 index; for(index=0;index<6;index++) packed|=(pokeIds[index]&31)<<(index*5); return packed; }

/* Unpacks six Pokemon ids from a word. */
void func_021D8090(u32 packed,u8 *pokeIds) { u32 index; for(index=0;index<6;index++) { pokeIds[index]=packed&31; packed>>=5; } }


/* Target kind that Curse uses: 7 (the user), or 0 for a ghost-type user. */
int func_021D80A8(struct BtlPokeParam *bpp)
{
    int targetKind = 7;
    if (func_021D5814(bpp, BTL_TYPE_GHOST)) targetKind = 0;
    return targetKind;
}


/*
 * Picks the target position of a move automatically: from the attacker's
 * position and the move's target kind, narrowed to a range code (range in the
 * high byte, position in the low byte), then a random position or Pokemon
 * from that range. 6 means no target.
 */
int func_021D80BC(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId)
{
    u32 rule;
    int posCode;
    u32 targetKind;
    u8 reachesFar;
    u8 candidates[8];
    u8 candidate;

    rule = func_021B8588(main);
    posCode = func_021B8D8C(main, posTable, func_021D5440(attacker));
    targetKind = sub_0201BD28(moveId, 0x1B);
    if (moveId == 0xAE) targetKind = func_021D80A8(attacker);

    if (rule == BTL_RULE_SINGLE) {
        switch (targetKind) {
        case 0:
        case 3:
        case 4:
        case 5:
        case 9:
            return func_021B8C50(main, posCode, 0);
        case 1:
        case 7:
            return posCode;
        case 13:
        default:
            return 6;
        }
    }

    reachesFar = 0;
    if (rule == BTL_RULE_TRIPLE) reachesFar = WAZA_TOOL_GetFlag(moveId, 0xB);

    switch (targetKind) {
    case 0:
    case 3:
    case 9:
        if (reachesFar) posCode = (u16)(posCode | (6 << 8));
        else posCode = (u16)(posCode | (1 << 8));
        break;
    case 1:
        posCode = (u16)(posCode | (3 << 8));
        break;
    case 2:
        if (reachesFar) posCode = (u16)(posCode | (7 << 8));
        else posCode = (u16)(posCode | (4 << 8));
        break;
    case 7:
        return posCode;
    default:
        return 6;
    }

    /* candidate holds the number of Pokemon in range, then the index picked. */
    candidate = func_021B8D38(main, posTable, posCode, candidates);
    if (candidate) {
        candidate = func_021D78AC(candidate);
        return func_021B8D8C(main, posTable, candidates[candidate]);
    }
    candidate = func_021B8778(main, posCode, candidates);
    if (candidate) return candidates[(u8)func_021D78AC(candidate)];
    return 6;
}
