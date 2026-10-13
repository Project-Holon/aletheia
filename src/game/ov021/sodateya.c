/*
 * file:     sodateya.c
 * unit:     yes
 * function: func_021C31D4, func_021C31FC, func_021C3204, func_021C3248, func_021C3250, func_021C3270, func_021C32BC, func_021C32F4, func_021C335C, func_021C3378, func_021C33A4, func_021C33E0, func_021C3400, func_021C340C, func_021C341C, func_021C3490, func_021C34B4, func_021C34C4, func_021C34F8, func_021C3510, func_021C3530, func_021C360C, func_021C3670, func_021C36B0, func_021C36EC, func_021C37F8, func_021C385C, func_021C3898, func_021C38DC, func_021C38F4, func_021C3A00, func_021C3A44, func_021C3A70, func_021C3A7C, func_021C3A90, func_021C3AAC, func_021C3ADC, func_021C3B0C, func_021C3B2C, func_021C3BB0, func_021C3BCC, func_021C3BD4, func_021C3C04, func_021C3C30, func_021C3C5C, func_021C3C78, func_021C3C88, func_021C3D1C, func_021C3DA8, func_021C3DE4, func_021C3E38, func_021C3E64, func_021C3F60, func_021C3FC0, func_021C4018, func_021C4024, func_021C4030, func_021C4078, func_021C4084, func_021C40F8, func_021C4160, func_021C4238, func_021C42BC, func_021C42F4, func_021C4340, func_021C447C, func_021C4504, func_021C452C
 * address:  0x021C31D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the day care work functions 021C31D4..021C360C from fld3d_ci.c (lane FXC2: __FILE__ sodateya.c on 021C31D4; the functions before it use Fld3dCi and the fld3d_ci.c string and data pool).
 * Split from fldeff_ripple.c at 0x021C3670 (lane FXC, CL128: day care breeding code; __FILE__ sodateya.c on 0x021C31D4).
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA8D8     0x021DA8D8  data  ov021  a4
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BCEC  0x0200BCEC  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_021C34C4  0x021C34C4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   d_021DA960     0x021DA960  data  ov021  a4
 *   func_02005728  0x02005728  thumb  ov021
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   d_021DA930     0x021DA930  data  ov021  a4
 *   d_021DA918     0x021DA918  data  ov021  a4
 *   func_02008530  0x02008530  thumb
 *   func_02017ED8  0x02017ED8  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DA908     0x021DA908  data  ov021  a4
 *   d_021DA8F8     0x021DA8F8  data  ov021  a4
 *   func_020212B0  0x020212B0  thumb
 *   d_021DA8E8     0x021DA8E8  data  ov021  a4
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02008510  0x02008510  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   func_02018198  0x02018198  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201B9F0  0x0201B9F0  thumb
 *   g_020A7370     0x020A7370  data
 *   d_021DA948     0x021DA948  data  ov021  a4
 *   func_02021288  0x02021288  thumb
 *   func_0202130C  0x0202130C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   d_021DE458     0x021DE458  data  ov021
 *   func_0200BC4C  0x0200BC4C  thumb
 *   func_0201A9C8  0x0201A9C8  thumb
 *   func_021C38DC  0x021C38DC  thumb  ov021
 *   func_0200BCD8  0x0200BCD8  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BC88  0x0200BC88  thumb
 *   func_021C36B0  0x021C36B0  thumb  ov021
 *   func_020173F0  0x020173F0  thumb
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0216556C  0x0216556C  thumb  ov010
 *   func_021C3898  0x021C3898  thumb  ov021
 *   func_0200BC20  0x0200BC20  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0200BD48  0x0200BD48  thumb
 *   func_021C385C  0x021C385C  thumb  ov021
 *   func_0200BC10  0x0200BC10  thumb
 *   func_0201850C  0x0201850C  thumb
 *   func_021C36EC  0x021C36EC  thumb  ov021
 *   func_02018584  0x02018584  thumb
 *   func_021C3670  0x021C3670  thumb  ov021
 *   func_020181F4  0x020181F4  thumb
 *   func_020180F4  0x020180F4  thumb
 *   d_021DA8C8     0x021DA8C8  data  ov021  a4
 */
#include "../arm9/billboard_act_types.h"

/*
 * breeding code (sodateya.c); 0x021C457C..0x021C4788 are script and event
 * glue; the water ripple field effect proper starts at 0x021C47B4.
 */

struct Pokemon;
struct Personal;
struct MyStatus;
struct FieldMap;
struct MsgBank;
struct StrBuf;

/* Mon data ids read and written through the Pokemon data accessors. */
enum {
    MON_DATA_SPECIES = 5,
    MON_DATA_HELD_ITEM = 6,
    MON_DATA_OT_ID = 7,
    MON_DATA_FRIENDSHIP = 9,
    MON_DATA_ABILITY = 0xA,
    MON_DATA_LANGUAGE = 0xC,
    MON_DATA_MOVE1 = 0x36,
    MON_DATA_MOVE2 = 0x37,
    MON_DATA_MOVE3 = 0x38,
    MON_DATA_MOVE4 = 0x39,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_GENDER = 0x6E,
    MON_DATA_FORM = 0x6F,
    MON_DATA_NATURE = 0x70,
    MON_DATA_NICKNAME = 0x73,
    MON_DATA_OT_NAME = 0x8D,
    MON_DATA_ABILITY_SET = 0xB2
};

/* Species and items the breeding rules test for. */
#define SPECIES_DITTO 0x84
#define SPECIES_NIDORAN_F 0x1D
#define SPECIES_VOLBEAT 0x139
#define SPECIES_ILLUMISE 0x13A
#define SPECIES_PHIONE 0x1E9
#define SPECIES_MANAPHY 0x1EA
#define SPECIES_PICHU 0xAC
#define SPECIES_BASCULIN 0x226
#define ITEM_EVERSTONE 0xE5
#define ITEM_LIGHT_BALL 0xEC
#define MOVE_VOLT_TACKLE 0x158

#define GENDER_MALE 0
#define GENDER_FEMALE 1
#define GENDER_NONE 2

/* Egg group 15 is "undiscovered": those Pokemon never breed. */
#define EGG_GROUP_UNDISCOVERED 0xF
#define PERSONAL_EGG_GROUP_1 0x18
#define PERSONAL_EGG_GROUP_2 0x19

/* Breeding compatibility scores. */
#define BREED_SCORE_LOW 0x14
#define BREED_SCORE_MID 0x32
#define BREED_SCORE_HIGH 0x46

#define SPECIES_COUNT 0x289
typedef unsigned long long u64;

#define DAYCARE_SLOT_COUNT 2
#define STEPS_PER_EGG_CHECK 0x10
#define SODATEYA_EGG_MET_PLACE 0xEA62
#define TM_ITEM_FIRST 0x148
#define TM_ITEM_LAST 0x272

/* Day care work (0x10 bytes, allocated by func_021C31D4). */
typedef struct SodateyaWork {
    u16 heapId;                           /* 0x00 */
    u16 pad02;
    struct FieldMap *fieldMap;            /* 0x04 */
    void *dayCare;                        /* 0x08 */
    u16 stepCount;                        /* 0x0C steps walked since the last egg check */
} SodateyaWork;

/* The offspring being rolled from two parents (0x8C bytes). */
typedef struct DayCareEgg {
    u32 species;                          /* 0x00 */
    u32 form;                             /* 0x04 */
    u32 level;                            /* 0x08 */
    u32 nature;                           /* 0x0C */
    u32 ability;                          /* 0x10 */
    u32 baseFriendship;                   /* 0x14 */
    u32 ivs[6];                           /* 0x18 */
    u32 otId;                             /* 0x30 */
    u32 personalRnd;                      /* 0x34 */
    u32 moveCount;                        /* 0x38 */
    u32 moves[4];                         /* 0x3C */
    u32 abilitySlot;                      /* 0x4C 0 or 1: the two normal abilities, 2: hidden */
    u32 natureFromFather;                 /* 0x50 */
    u32 natureFromMother;                 /* 0x54 */
    u32 fatherIvFlags[6];                 /* 0x58 IVs taken from the father */
    u32 motherIvFlags[6];                 /* 0x70 IVs taken from the mother */
    u32 inheritedIvCount;                 /* 0x88 */
} DayCareEgg;

/* The four move slots of a Pokemon, as mon data ids. */
typedef struct MoveSlotIdTable { u32 ids[4]; } MoveSlotIdTable;

/* The six IVs or the six power items, in HP, Atk, Def, SpAtk, SpDef, Speed order. */
typedef struct StatTable { u32 ids[6]; } StatTable;

/* A baby species, the incense that lets it hatch, and the species hatched without it. */
typedef struct IncenseBabyEntry {
    u32 babySpecies;
    u32 incenseItem;
    u32 adultSpecies;
} IncenseBabyEntry;

typedef struct IncenseBabyTable { IncenseBabyEntry entries[12]; } IncenseBabyTable;

/* Learnset entry; the pair 0xFFFF, 0xFFFF ends the list. */
typedef struct LearnsetEntry {
    u16 move;
    u16 level;
} LearnsetEntry;

extern u32 func_02017E1C(const struct Pokemon *mon, u32 dataId, u32 arg);
extern int func_0200BCA8(void *dayCare, int slot);
extern void func_0200BCEC(void *dayCare, int slot, int newSlot);
extern u32 func_02019C90(u16 species, u16 form, u32 groupField);
extern int func_0200BCB8(void *dayCare);
extern u32 func_02005728(u32 range);
extern struct FieldMap *func_02188C80(struct FieldMap *p);
extern void *func_020120F4(const void *p);
extern struct MyStatus *func_02012944(void *p);
extern struct Pokemon *func_0200BC2C(void *dayCare, int slot);
extern u32 func_02007C34(void *p, void *party);
extern void *func_02012F98(void *p);
extern u32 func_02082BCC(void *dst, u32 value, u32 size);
extern void *func_0201ADE4(u32 species, int form, u32 heapId);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02008530(const struct MyStatus *status);
extern u32 func_02017ED8(u32 otId, u32 personalRnd);
extern void func_0201ADD0(unsigned int species, int form, void *dest);
extern void *func_02048F60(u32 archive, u32 member, u32 heapId);
extern u32 func_020307B0(void *p);
extern u16 func_020212B0(u16 item);
extern void func_02017588(struct Pokemon *mon, u16 species, u16 level, unsigned long long otId, u32 power, unsigned long long personalRnd);
extern void func_02017E40(struct Pokemon *mon, u32 dataId, u32 value);
extern void func_02018A00(struct Pokemon *mon, u32 species, u32 form);
extern struct StrBuf *func_02008510(struct MyStatus *status, int heapId);
extern void func_02045808(struct StrBuf *str);
extern struct StrBuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0202F190(struct Pokemon *mon, u32 a1, struct MyStatus *status, u32 place, u16 heapId);
extern void func_02018198(struct Pokemon *mon);
extern void func_020185C4(struct Pokemon *mon);
extern void func_0201B9F0(struct Pokemon *mon);
extern u32 func_02021288(u32 item);
extern u32 func_0202130C(u32 item);
extern void func_02048F74(void *dst, u32 archive, u32 member, u32 mode, u32 *sizeOut);
extern void *g_020A7370;

int func_021C3670(void *mon, u32 move);
void func_021C36B0(void *dayCare);
int func_021C36EC(struct Pokemon *monA, struct Pokemon *monB);
int func_021C37F8(struct Pokemon *monA, struct Pokemon *monB);
int func_021C385C(SodateyaWork *work);
void func_021C3898(SodateyaWork *work, struct Pokemon *eggMon);
int func_021C38DC(struct FieldMap *fieldMap, void *party);
void func_021C38F4(u16 heapId, struct MyStatus *myStatus, u32 metPlace, struct Pokemon *father, struct Pokemon *mother, struct Pokemon *eggMon);
void func_021C3A00(struct Pokemon **parents);
void func_021C3A44(struct Pokemon **parents);
void func_021C3A70(struct Pokemon **parents);
int func_021C3A7C(DayCareEgg *egg);
void func_021C3A90(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3AAC(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3ADC(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3B0C(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3B2C(struct Pokemon **parents, DayCareEgg *egg);
struct Pokemon *func_021C3BB0(struct Pokemon **parents);
int func_021C3BCC(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3BD4(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3C04(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3C30(struct Pokemon **parents, DayCareEgg *egg);
struct Pokemon *func_021C3C5C(struct Pokemon **parents);
void func_021C3C78(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3C88(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3D1C(struct Pokemon **parents, DayCareEgg *egg, u32 heapId);
void func_021C3DA8(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3DE4(struct Pokemon **parents, DayCareEgg *egg, u32 heapId);
void func_021C3E38(DayCareEgg *egg, u32 heapId);
void func_021C3E64(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3F60(struct Pokemon **parents, DayCareEgg *egg);
void func_021C3FC0(struct Pokemon **parents, DayCareEgg *egg);
void func_021C4018(struct MyStatus *myStatus, DayCareEgg *egg);
void func_021C4024(struct Pokemon **parents, DayCareEgg *egg);
void func_021C4030(struct Pokemon **parents, DayCareEgg *egg);
u32 func_021C4078(void);
void func_021C4084(DayCareEgg *egg);
void func_021C40F8(struct Pokemon **parents, DayCareEgg *egg, u32 heapId);
void func_021C4160(struct Pokemon **parents, DayCareEgg *egg);
void func_021C4238(struct Pokemon **parents, DayCareEgg *egg, u32 heapId);
void func_021C42BC(struct Pokemon **parents, DayCareEgg *egg);
void func_021C42F4(DayCareEgg *egg, u32 move);
void func_021C4340(struct Pokemon *mon, const DayCareEgg *egg, struct MyStatus *myStatus, u32 metPlace, u16 heapId);
int func_021C447C(u32 heapId, u32 species, u32 form, u32 tmItem);
u16 func_021C4504(u16 species);
u8 func_021C452C(u32 species, u32 form, u32 ability, u32 heapId);
extern const MoveSlotIdTable d_021DA8D8;
extern IncenseBabyTable d_021DA960;
extern const StatTable d_021DA930;
extern StatTable d_021DA918;
extern MoveSlotIdTable d_021DA908;
extern const MoveSlotIdTable d_021DA8F8;
extern MoveSlotIdTable d_021DA8E8;
extern const StatTable d_021DA948;
extern void *func_02030734(u32, u32, int, const char *, u16);
void *func_02012934(const void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0200BC4C(void *dayCare, s32 slot, const void *mon);
extern u32 func_0201A9C8(void *p, s32 idx);
extern u32 func_02017988(void *p, u32 a);
extern u32 func_0200BCD8(void *dayCare, u32 slot);
extern u32 func_0201A98C(void *p, const void *src);
extern void func_0200BC88(void *dayCare, s32 slot);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CED4(void *p, u16 id);
extern void func_0200CDE0(void *p, void *m);
extern void *func_020173F0(u16 species, u16 level, unsigned long long id, u16 heap);
extern int func_0200BCA0(void *dayCare);
extern void func_0216556C(void);
extern void func_0200BC20(void *dayCare);
extern u8 func_02012984(const void *p);
extern void func_0216AAE4(void *sys, void *party, int season);
extern void func_0200BD48(void *dayCare, int steps);
extern void func_0200BC10(void *dayCare);
extern u32 func_0201296C(const void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA14(void *p);
extern u32 func_020143CC(u32 a, u32 b);
extern u32 func_0201850C(u16 species, u16 form, u32 exp);
extern u32 func_02018584(u16 a, u16 b, u16 c);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_020180F4(void *p, int move);
SodateyaWork *func_021C31D4(u32 heapId, void *fieldMap, void *dayCare);
void func_021C31FC(void *work);
void func_021C3204(SodateyaWork *work, void *party, u32 partyPos);
void func_021C3248(void *mon);
void func_021C3250(void *mon);
void func_021C3270(SodateyaWork *work, u32 slot, void *party);
void func_021C32BC(SodateyaWork *work, void *mon);
void func_021C32F4(SodateyaWork *work, void *party);
void func_021C335C(SodateyaWork *work);
int func_021C3378(SodateyaWork *work);
void func_021C33A4(void *fieldMap);
void func_021C33E0(void *fieldMap);
int func_021C3400(void *work);
int func_021C340C(SodateyaWork *work);
int func_021C341C(SodateyaWork *work, u32 slot);
int func_021C3490(SodateyaWork *work, int slot);
int func_021C34B4(SodateyaWork *work, int slot);
u8 func_021C34C4(SodateyaWork *work);
void *func_021C34F8(SodateyaWork *work, u32 slot);
u32 func_021C3510(u32 exp, u32 gain);
void func_021C3530(void *mon, u32 gain);
void func_021C360C(void *mon, u32 move);
extern char d_021DE458[];
extern const MoveSlotIdTable d_021DA8C8;
/*
 * Allocates and initialises the 0x10-byte day care work.
 */
SodateyaWork *func_021C31D4(u32 heapId, void *fieldMap, void *dayCare)
{
    SodateyaWork *work = func_02030734(heapId, 0x10, 0, d_021DE458, 0x6A);
    work->heapId = heapId;
    work->fieldMap = fieldMap;
    work->dayCare = dayCare;
    work->stepCount = 0;
    return work;
}

/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 */
void func_021C31FC(void *work)
{
    func_020307B0(work);
}

/* Deposits the party member at partyPos in the day care when there is room. */
void func_021C3204(SodateyaWork *work, void *party, u32 partyPos)
{
    int count = func_0200BCB8(work->dayCare);
    u32 mon = (u32)func_0201AB28(party, partyPos);
    if (count < 2) {
        func_021C3248((void *)mon);
        func_021C3250((void *)mon);
        func_0200BC4C(work->dayCare, count, (void *)mon);
        func_0201A9C8(party, partyPos);
        func_021C38DC(work->fieldMap, party);
    }
}

/*
 * Tail-call thunk: forwards to func_0201B9F0 with no argument change.
 */
void func_021C3248(void *mon)
{
    func_0201B9F0(mon);
}

/* Reverts a Shaymin (species 0x1EC) to its first form. */
void func_021C3250(void *mon)
{
    if (func_02017E1C(mon, 5, 0) == 0x1EC)
        func_02017988(mon, 0);
}

/* Takes the pokemon of day care slot out into the party, with the experience it gained. */
void func_021C3270(SodateyaWork *work, u32 slot, void *party)
{
    u32 mon;
    if (func_0200BCA8(work->dayCare, slot) == 1) {
        mon = (u32)func_0200BC2C(work->dayCare, slot);
        func_021C3530((void *)mon, func_0200BCD8(work->dayCare, slot));
        func_021C32BC(work, (void *)mon);
        func_0201A98C(party, (void *)mon);
        func_0200BC88(work->dayCare, slot);
        func_021C36B0(work->dayCare);
    }
}

/*
 * Returns the Pokemon's held item to the bag when it fits.
 */
void func_021C32BC(SodateyaWork *work, void *mon)
{
    void *bag = func_0200CA1C(func_020120F4(func_02188C80(work->fieldMap)));
    if (func_0200CED4(bag, func_02017E1C(mon, 5, 0)) == 0)
        func_0200CDE0(bag, mon);
}

/* Takes the egg out of the day care into the party. */
void func_021C32F4(SodateyaWork *work, void *party)
{
    u32 egg = (u32)func_020173F0(1, 1, 1, work->heapId);
    u32 gameData;
    if (func_0200BCA0(work->dayCare) == 1) {
        func_0216556C();
        func_021C33E0(work->fieldMap);
        func_021C3898(work, (struct Pokemon *)egg);
        func_0201A98C(party, (void *)egg);
        func_0200BC20(work->dayCare);
        func_020307B0((void *)egg);
        gameData = (u32)func_020120F4(func_02188C80(work->fieldMap));
        func_0216AAE4((void *)gameData, party, func_02012984((void *)gameData));
    }
}

/*
 * Declines the egg: clears it from the day care and the egg flag.
 */
void func_021C335C(SodateyaWork *work)
{
    if (func_0200BCA0(work->dayCare) == 1) {
        func_0200BC20(work->dayCare);
        func_021C33E0(work->fieldMap);
    }
}

/* Advances the step counter by one; 1 when an egg was produced. */
int func_021C3378(SodateyaWork *work)
{
    func_0200BD48(work->dayCare, 1);
    if (func_021C385C(work) == 1) {
        func_0200BC10(work->dayCare);
        func_021C33A4(work->fieldMap);
        return 1;
    }
    return 0;
}

/*
 * Sets event flag 0x4139 when the party is not full.
 */
void func_021C33A4(void *fieldMap)
{
    void *gameData = func_020120F4(func_02188C80(fieldMap));
    void *eventWork = (void *)func_0201296C(gameData);
    void *party = func_02012934(gameData);
    if ((int)func_0201AA18(party) < (int)func_0201AA14(party))
        *((u16 *)func_020143CC((u32)eventWork, 0x4139)) = 1;
}

/*
 * Clears event flag 0x4139 (EXACT*: unlabelled follower).
 */
void func_021C33E0(void *fieldMap)
{
    *((u16 *)func_020143CC(func_0201296C(func_020120F4(func_02188C80(fieldMap))), 0x4139)) = 0;
}

/*
 * Unlabelled leaf in ov021 (the listing prints it as a `.word` run at
 * 0x021C3400, next to ov010's field-VM code); ov010's func_0215CE98 reaches
 * it across the overlay pair.  Eight-byte thunk: load [a+8] and tail-call
 * the ARM9 helper.
 */
int func_021C3400(void *work)
{
    return func_0200BCA0(((SodateyaWork *)work)->dayCare);
}

/* Number of pokemon in the day care. */
int func_021C340C(SodateyaWork *work)
{
    return (u8)func_0200BCB8(work->dayCare);
}

/* Level the pokemon of slot has reached from the experience it gained. */
int func_021C341C(SodateyaWork *work, u32 slot)
{
    u32 mon;
    u32 form;
    u32 exp;
    u32 species;
    if (func_0200BCA8(work->dayCare, slot) != 1)
        return 1;
    mon = (u32)func_0200BC2C(work->dayCare, slot);
    species = func_02017E1C((void *)mon, 5, 0);
    form = func_02017E1C((void *)mon, 0x6F, 0);
    exp = func_02017E1C((void *)mon, 8, 0);
    func_02017E1C((void *)mon, 0x9E, 0);
    return func_0201850C(species, form, func_021C3510(exp, func_0200BCD8(work->dayCare, slot)));
}

/*
 * Levels gained by the slot-i day-care Pokemon (EXACT*: pad).
 */
int func_021C3490(SodateyaWork *work, int slot)
{
    int level = func_02017E1C((void *)func_0200BC2C(work->dayCare, slot), 0x9E, 0);
    return func_021C341C(work, slot) - level;
}

/* Price to take the pokemon of slot back: 100 per level gained, plus one. */
int func_021C34B4(SodateyaWork *work, int slot)
{
    return ((func_021C3490(work, slot) + 1) * 100);
}

/*
 * Compatibility of the two deposited Pokemon, 0 when fewer than two (EXACT*: pad).
 */
u8 func_021C34C4(SodateyaWork *work)
{
    void *first;
    if (func_0200BCB8(work->dayCare) < 2)
        return 0;
    first = func_0200BC2C(work->dayCare, 0);
    return func_021C36EC(first, func_0200BC2C(work->dayCare, 1));
}

/* Pokemon in day care slot. */
void *func_021C34F8(SodateyaWork *work, u32 slot)
{
    func_0200BCA8(work->dayCare, slot);
    return func_0200BC2C(work->dayCare, slot);
}

/*
 * Saturating 32-bit add (EXACT*: pad).
 */
u32 func_021C3510(u32 exp, u32 gain)
{
    u64 sum = (u64)exp + gain;
    if (sum > 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return sum;
}

/*
 * Gives the pokemon the gained experience and teaches the moves of the levels
 * crossed. Learnset walk as in func_021C4084. Load-bearing: level is read from
 * the first entry copy right after it is made (the value stays in the
 * register), move from the second copy, and move is u32/int (u16 sinks its
 * load to the call).
 */
void func_021C3530(void *mon, u32 gain)
{
    LearnsetEntry learnset[26];
    LearnsetEntry entryE, entryD, entryC, entryA;
    u32 species;
    u32 form;
    u32 maxExp;
    int oldLevel;
    int newLevel;
    u32 exp;
    int i;
    int atEnd;
    int level;
    u32 move;
    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6f, 0);
    maxExp = func_02018584(species, form, 100);
    oldLevel = func_02017E1C(mon, 0x9e, 0);
    exp = func_021C3510(func_02017E1C(mon, 8, 0), gain);
    if (maxExp < exp)
        exp = maxExp;
    func_02017E40(mon, 8, exp);
    func_020185C4(mon);
    i = 0;
    newLevel = func_02017E1C(mon, 0x9e, 0);
    func_0201ADD0((u16)species, (u16)form, learnset);
    goto test;
body:
    entryE = entryA;
    level = entryE.level;
    entryD = entryA;
    move = entryD.move;
    if (newLevel < level)
        return;
    if (oldLevel < level)
        func_021C360C(mon, move);
    i++;
test:
    entryA = learnset[i];
    entryC = entryA;
    atEnd = 0;
    if (entryC.move == 0xffff && entryC.level == 0xffff)
        atEnd = 1;
    if (!atEnd)
        goto body;
}

/*
 * Teaches a move: into the first empty move slot, else asks to replace one.
 */
void func_021C360C(void *mon, u32 move)
{
    MoveSlotIdTable slotIds = d_021DA8C8;
    int i;
    if (move != 0 && func_021C3670(mon, move) == 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(mon, slotIds.ids[i], 0) == 0) {
                func_020181F4(mon, move, (u8)i);
                return;
            }
        }
        func_020180F4(mon, (u16)move);
    }
}

/*
 * Addresses are Black-image addresses.
 */

/* Returns 1 when the Pokemon knows the move. */
int func_021C3670(void *mon, u32 move)
{
    MoveSlotIdTable slotIds = d_021DA8D8;
    int i;

    for (i = 0; i < 4; i++) {
        if (move == func_02017E1C(mon, slotIds.ids[i], 0))
            return 1;
    }
    return 0;
}

/*
 * Compacts the two day-care slots so occupied ones come first.
 */
void func_021C36B0(void *dayCare)
{
    int i, j;

    for (i = 0; i < DAYCARE_SLOT_COUNT; i++) {
        if (func_0200BCA8(dayCare, i) == 1)
            continue;
        for (j = i + 1; j < DAYCARE_SLOT_COUNT; j++) {
            if (func_0200BCA8(dayCare, j) == 1)
                func_0200BCEC(dayCare, j, j - 1);
        }
    }
}

/*
 * Breeding compatibility of two party Pokemon: 0 when they cannot breed,
 * else the score from func_021C37F8. The last test is spelled as the negated
 * conjunction returning 0, so the fall-through is the call.
 */
int func_021C36EC(struct Pokemon *monA, struct Pokemon *monB)
{
    u32 species[2];
    u32 form[2];
    u32 gender[2];
    u32 eggGroup1[2];
    u32 eggGroup2[2];
    struct Pokemon *mons[2];
    int i;

    mons[0] = monA;
    mons[1] = monB;
    for (i = 0; i < 2; i++) {
        species[i] = func_02017E1C(mons[i], MON_DATA_SPECIES, 0);
        func_02017E1C(mons[i], MON_DATA_OT_ID, 0);
        form[i] = func_02017E1C(mons[i], MON_DATA_FORM, 0);
        gender[i] = func_02017E1C(mons[i], MON_DATA_GENDER, 0);
        eggGroup1[i] = func_02019C90(species[i], form[i], PERSONAL_EGG_GROUP_1);
        eggGroup2[i] = func_02019C90(species[i], form[i], PERSONAL_EGG_GROUP_2);
    }
    if (eggGroup1[0] == EGG_GROUP_UNDISCOVERED || eggGroup1[1] == EGG_GROUP_UNDISCOVERED
        || eggGroup2[0] == EGG_GROUP_UNDISCOVERED || eggGroup2[1] == EGG_GROUP_UNDISCOVERED)
        return 0;
    if (species[0] == SPECIES_DITTO && species[1] == SPECIES_DITTO)
        return 0;
    if (species[0] == SPECIES_DITTO || species[1] == SPECIES_DITTO)
        return func_021C37F8(monA, monB);
    if (gender[0] == gender[1])
        return 0;
    if (gender[0] == GENDER_NONE || gender[1] == GENDER_NONE)
        return 0;
    if (eggGroup1[0] != eggGroup1[1] && eggGroup1[0] != eggGroup2[1]
        && eggGroup2[0] != eggGroup1[1] && eggGroup2[0] != eggGroup2[1])
        return 0;
    return func_021C37F8(monA, monB);
}

/*
 * Breeding score: 70 for the same species and the same trainer, 20 for
 * different species and the same trainer, 50 otherwise.
 */
int func_021C37F8(struct Pokemon *monA, struct Pokemon *monB)
{
    u32 species[2];
    u32 otId[2];
    struct Pokemon *mons[2];
    int i;

    mons[0] = monA;
    mons[1] = monB;
    for (i = 0; i < 2; i++) {
        species[i] = func_02017E1C(mons[i], MON_DATA_SPECIES, 0);
        otId[i] = func_02017E1C(mons[i], MON_DATA_OT_ID, 0);
    }
    if (species[0] != species[1]) {
        if (otId[0] == otId[1])
            return BREED_SCORE_LOW;
        return BREED_SCORE_MID;
    }
    if (otId[0] == otId[1])
        return BREED_SCORE_MID;
    return BREED_SCORE_HIGH;
}

/*
 * Step counter: every 16 steps rolls for an egg against compatibility.
 */
int func_021C385C(SodateyaWork *work)
{
    u16 oldCount = work->stepCount;

    work->stepCount = oldCount + STEPS_PER_EGG_CHECK;
    if (oldCount > 0xFF) {
        work->stepCount = 0;
        if (func_0200BCB8(work->dayCare) >= 2) {
            u32 roll = func_02005728(0x640);
            if (roll < func_021C34C4(work))
                return 1;
        }
    }
    return 0;
}

/* Builds the egg Pokemon from the two Pokemon in the day care. */
void func_021C3898(SodateyaWork *work, struct Pokemon *eggMon)
{
    struct MyStatus *myStatus = func_02012944(func_020120F4(func_02188C80(work->fieldMap)));
    struct Pokemon *father = func_0200BC2C(work->dayCare, 0);
    struct Pokemon *mother = func_0200BC2C(work->dayCare, 1);

    func_021C38F4(work->heapId, myStatus, SODATEYA_EGG_MET_PLACE, father, mother, eggMon);
}

/*
 * Runs a field-map accessor chain on the party after a Pokemon was left in the day care.
 */
int func_021C38DC(struct FieldMap *fieldMap, void *party)
{
    return func_02007C34(func_02012F98(func_020120F4(func_02188C80(fieldMap))), party);
}

/*
 * Day-care offspring builder: runs every step of the 0x8C-byte egg record
 * over the parent pair and hands the result to func_021C4340.
 */
void func_021C38F4(u16 heapId, struct MyStatus *myStatus, u32 metPlace, struct Pokemon *father, struct Pokemon *mother, struct Pokemon *eggMon)
{
    DayCareEgg egg;
    struct Pokemon *parents[2];

    parents[0] = father;
    parents[1] = mother;
    func_021C3A00(parents);
    func_021C3A44(parents);
    func_021C3A7C(&egg);
    func_021C3A90(parents, &egg);
    func_021C3AAC(parents, &egg);
    func_021C3ADC(parents, &egg);
    func_021C3B0C(parents, &egg);
    func_021C3B2C(parents, &egg);
    func_021C3BCC(parents, &egg);
    func_021C3BD4(parents, &egg);
    func_021C3C04(parents, &egg);
    func_021C3C30(parents, &egg);
    func_021C3C78(parents, &egg);
    func_021C3C88(parents, &egg);
    func_021C3D1C(parents, &egg, heapId);
    func_021C3DA8(parents, &egg);
    func_021C3DE4(parents, &egg, heapId);
    func_021C3E38(&egg, heapId);
    func_021C3E64(parents, &egg);
    func_021C3F60(parents, &egg);
    func_021C3FC0(parents, &egg);
    func_021C4018(myStatus, &egg);
    func_021C4024(parents, &egg);
    func_021C4030(parents, &egg);
    func_021C4084(&egg);
    func_021C40F8(parents, &egg, heapId);
    func_021C4160(parents, &egg);
    func_021C4238(parents, &egg, heapId);
    func_021C42BC(parents, &egg);
    func_021C4340(eggMon, &egg, myStatus, metPlace, heapId);
}

/*
 * Puts the father first: parents[0] ends up male (or the non-Ditto),
 * parents[1] female. The result of the second gender read of each pair is unused.
 */
void func_021C3A00(struct Pokemon **parents)
{
    u32 gender = func_02017E1C(parents[0], MON_DATA_GENDER, 0);

    func_02017E1C(parents[1], MON_DATA_GENDER, 0);
    if (gender == GENDER_FEMALE)
        func_021C3A70(parents);
    func_02017E1C(parents[0], MON_DATA_GENDER, 0);
    if (func_02017E1C(parents[1], MON_DATA_GENDER, 0) == GENDER_MALE)
        func_021C3A70(parents);
}

/*
 * Swaps the parents when parents[0] is a Ditto and parents[1] is genderless,
 * so the Ditto ends up second.
 */
void func_021C3A44(struct Pokemon **parents)
{
    u32 species = func_02017E1C(parents[0], MON_DATA_SPECIES, 0);
    u32 gender = func_02017E1C(parents[1], MON_DATA_GENDER, 0);

    if (species == SPECIES_DITTO && gender == GENDER_NONE)
        func_021C3A70(parents);
}

void func_021C3A70(struct Pokemon **parents)
{
    struct Pokemon *tmp = parents[0];

    parents[0] = parents[1];
    parents[1] = tmp;
}

/* Clears the egg record and sets its level to 1. */
int func_021C3A7C(DayCareEgg *egg)
{
    func_02082BCC(egg, 0, sizeof(DayCareEgg));
    egg->level = 1;
    return 1;
}

/*
 * Stores the base form of the mother's species.
 */
void func_021C3A90(struct Pokemon **parents, DayCareEgg *egg)
{
    egg->species = func_021C4504(func_02017E1C(func_021C3BB0(parents), MON_DATA_SPECIES, 0));
}

/*
 * Nidoran family: offspring species is a coin flip of 0x1D / 0x20.
 */
void func_021C3AAC(struct Pokemon **parents, DayCareEgg *egg)
{
    u32 species = func_02017E1C(func_021C3BB0(parents), MON_DATA_SPECIES, 0);

    if (species == SPECIES_NIDORAN_F || species - 0x20 <= 2) {
        if (func_02005728(2) == 0)
            egg->species = SPECIES_NIDORAN_F;
        else
            egg->species = 0x20;
    }
}

/*
 * Volbeat / Illumise: offspring species is a coin flip of the two.
 */
void func_021C3ADC(struct Pokemon **parents, DayCareEgg *egg)
{
    u32 species = func_02017E1C(func_021C3BB0(parents), MON_DATA_SPECIES, 0);

    if (species == SPECIES_VOLBEAT || species == SPECIES_ILLUMISE) {
        if (func_02005728(2) == 0)
            egg->species = SPECIES_VOLBEAT;
        else
            egg->species = SPECIES_ILLUMISE;
    }
}

/*
 * Manaphy parents produce Phione.
 */
void func_021C3B0C(struct Pokemon **parents, DayCareEgg *egg)
{
    if (func_02017E1C(func_021C3BB0(parents), MON_DATA_SPECIES, 0) == SPECIES_MANAPHY)
        egg->species = SPECIES_PHIONE;
}

/*
 * Incense babies: when the baby species is in the table and neither parent
 * holds its incense, the offspring is the adult species instead.
 */
void func_021C3B2C(struct Pokemon **parents, DayCareEgg *egg)
{
    IncenseBabyTable table = d_021DA960;
    int i;
    u32 fatherItem, motherItem;
    struct Pokemon *mon = func_021C3BB0(parents);

    i = 0;
    func_02017E1C(mon, MON_DATA_SPECIES, 0);
    func_02017E1C(mon, MON_DATA_HELD_ITEM, 0);
    fatherItem = func_02017E1C(parents[0], MON_DATA_HELD_ITEM, 0);
    motherItem = func_02017E1C(parents[1], MON_DATA_HELD_ITEM, 0);
    for (; i < 12; i++) {
        if (egg->species == table.entries[i].babySpecies
            && fatherItem != table.entries[i].incenseItem
            && motherItem != table.entries[i].incenseItem) {
            egg->species = table.entries[i].adultSpecies;
            return;
        }
    }
}

/* The parent whose species and form the offspring takes: the mother, or the father when she is a Ditto. */
struct Pokemon *func_021C3BB0(struct Pokemon **parents)
{
    if (func_02017E1C(parents[1], MON_DATA_SPECIES, 0) == SPECIES_DITTO) {
        return parents[0];
    }
    return parents[1];
}

/* The offspring starts in form 0. */
int func_021C3BCC(struct Pokemon **parents, DayCareEgg *egg)
{
    egg->form = 0;
    return 0;
}

/*
 * Copies the parent's form for species 0x1A6..0x1A7 (Shellos, Gastrodon).
 */
void func_021C3BD4(struct Pokemon **parents, DayCareEgg *egg)
{
    struct Pokemon *mon = func_021C3C5C(parents);
    u32 species = func_02017E1C(mon, MON_DATA_SPECIES, 0);

    if (species - 0x1A6 <= 1)
        egg->form = func_02017E1C(mon, MON_DATA_FORM, 0);
}

/*
 * Copies the parent's form for species 0x19C..0x19D (Burmy, Wormadam).
 */
void func_021C3C04(struct Pokemon **parents, DayCareEgg *egg)
{
    struct Pokemon *mon = func_021C3C5C(parents);
    u32 species = func_02017E1C(mon, MON_DATA_SPECIES, 0);

    if (species - 0x19C <= 1)
        egg->form = func_02017E1C(mon, MON_DATA_FORM, 0);
}

/*
 * Copies the parent's form for Basculin.
 */
void func_021C3C30(struct Pokemon **parents, DayCareEgg *egg)
{
    struct Pokemon *mon = func_021C3C5C(parents);
    u32 species = func_02017E1C(mon, MON_DATA_SPECIES, 0);

    if (species == SPECIES_BASCULIN)
        egg->form = func_02017E1C(mon, MON_DATA_FORM, 0);
}

/* Same choice as func_021C3BB0, kept as its own function by the original. */
struct Pokemon *func_021C3C5C(struct Pokemon **parents)
{
    if (func_02017E1C(parents[1], MON_DATA_SPECIES, 0) == SPECIES_DITTO) {
        return parents[0];
    }
    return parents[1];
}

/*
 * Rolls the offspring nature.
 */
void func_021C3C78(struct Pokemon **parents, DayCareEgg *egg)
{
    egg->nature = func_02005728(0x19);
}

/*
 * Everstone: a parent holding it passes its nature on (half the time when
 * one holds it, a coin flip between the two when both do).
 */
void func_021C3C88(struct Pokemon **parents, DayCareEgg *egg)
{
    int fatherHolds, motherHolds;
    u32 fatherNature, motherNature;

    fatherHolds = 0;
    if (func_02017E1C(parents[0], MON_DATA_HELD_ITEM, 0) == ITEM_EVERSTONE)
        fatherHolds = 1;
    motherHolds = 0;
    if (func_02017E1C(parents[1], MON_DATA_HELD_ITEM, 0) == ITEM_EVERSTONE)
        motherHolds = 1;
    fatherNature = func_02017E1C(parents[0], MON_DATA_NATURE, 0);
    motherNature = func_02017E1C(parents[1], MON_DATA_NATURE, 0);
    if (fatherHolds || motherHolds) {
        if (func_02005728(2) == 0)
            return;
    }
    if (fatherHolds && motherHolds) {
        if (func_02005728(2) == 0) {
            egg->nature = fatherNature;
            egg->natureFromFather = 1;
        } else {
            egg->nature = motherNature;
            egg->natureFromMother = 1;
        }
    } else if (fatherHolds) {
        egg->nature = fatherNature;
        egg->natureFromFather = 1;
    } else if (motherHolds) {
        egg->nature = motherNature;
        egg->natureFromMother = 1;
    }
}

/*
 * Rolls the ability slot of the offspring from the mother's ability slot.
 */
void func_021C3D1C(struct Pokemon **parents, DayCareEgg *egg, u32 heapId)
{
    u32 species = func_02017E1C(parents[1], MON_DATA_SPECIES, 0);
    u32 form = func_02017E1C(parents[1], MON_DATA_FORM, 0);
    u32 ability = func_02017E1C(parents[1], MON_DATA_ABILITY, 0);
    u32 motherSlot = (u32)func_021C452C((u16)species, (u16)form, (u16)ability, heapId);
    u32 roll = func_02005728(100);

    switch (motherSlot) {
    default:
    case 0:
        if (roll < 0x50)
            egg->abilitySlot = 0;
        else
            egg->abilitySlot = 1;
        return;
    case 1:
        if (roll < 0x14)
            egg->abilitySlot = 0;
        else
            egg->abilitySlot = 1;
        return;
    case 2:
        if (roll < 0x14)
            egg->abilitySlot = 0;
        else if (roll < 0x28)
            egg->abilitySlot = 1;
        else
            egg->abilitySlot = 2;
        return;
    }
}

/*
 * Sets the ability slot by coin flip when a parent is a Ditto.
 */
void func_021C3DA8(struct Pokemon **parents, DayCareEgg *egg)
{
    u32 fatherSpecies = func_02017E1C(parents[0], MON_DATA_SPECIES, 0);
    u32 motherSpecies = func_02017E1C(parents[1], MON_DATA_SPECIES, 0);

    if (fatherSpecies == SPECIES_DITTO || motherSpecies == SPECIES_DITTO) {
        if (func_02005728(2) == 0)
            egg->abilitySlot = 0;
        else
            egg->abilitySlot = 1;
    }
}

/*
 * Looks up the ability of the chosen slot in the personal data of the
 * offspring species, falling back to slot 0 when it is empty.
 */
void func_021C3DE4(struct Pokemon **parents, DayCareEgg *egg, u32 heapId)
{
    u32 abilities[3];
    struct Personal *personal = func_0201ADE4((u16)egg->species, (u16)egg->form, heapId);

    abilities[0] = func_0201AE1C(personal, 0x1a);
    abilities[1] = func_0201AE1C(personal, 0x1b);
    abilities[2] = func_0201AE1C(personal, 0x1c);
    func_0201AE14(personal);
    if (egg->abilitySlot < 2) {
        egg->ability = abilities[egg->abilitySlot];
        if (egg->ability == 0)
            egg->ability = abilities[0];
    }
}

/*
 * Reads personal-data field 0x15 (base friendship) for the species/form pair.
 */
void func_021C3E38(DayCareEgg *egg, u32 heapId)
{
    void *personal = func_0201ADE4((u16)egg->species, (u16)egg->form, heapId);
    u32 baseFriendship = func_0201AE1C(personal, 0x15);

    func_0201AE14(personal);
    egg->baseFriendship = baseFriendship;
}

/*
 * Power items: a parent holding one passes the matching IV on. The flag
 * array must be a struct member (egg->fatherIvFlags[i]); spelled as a flat
 * index the compiler folds the offset into the index and spills it.
 */
void func_021C3E64(struct Pokemon **parents, DayCareEgg *egg)
{
    StatTable powerItems;
    int fatherHolds;
    int motherHolds;
    int fatherStat;
    int motherStat;
    u32 fatherItem;
    u32 motherItem;
    int i;

    fatherHolds = 0;
    motherHolds = 0;
    fatherItem = func_02017E1C(parents[0], MON_DATA_HELD_ITEM, 0);
    motherItem = func_02017E1C(parents[1], MON_DATA_HELD_ITEM, 0);
    powerItems = d_021DA930;
    for (i = 0; i < 6; i++) {
        if (fatherItem == powerItems.ids[i]) {
            fatherHolds = 1;
            fatherStat = i;
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        if (motherItem == powerItems.ids[i]) {
            motherHolds = 1;
            motherStat = i;
            break;
        }
    }
    if (fatherHolds && motherHolds) {
        if (func_02005728(2) == 0) {
            egg->fatherIvFlags[fatherStat] = 1;
            egg->inheritedIvCount++;
        } else {
            egg->motherIvFlags[motherStat] = 1;
            egg->inheritedIvCount++;
        }
    } else if (fatherHolds) {
        egg->fatherIvFlags[fatherStat] = 1;
        egg->inheritedIvCount++;
    } else if (motherHolds) {
        egg->motherIvFlags[motherStat] = 1;
        egg->inheritedIvCount++;
    }
}

/*
 * Picks random IVs from random parents until three are inherited.
 */
void func_021C3F60(struct Pokemon **parents, DayCareEgg *egg)
{
    while (egg->inheritedIvCount < 3) {
        u32 stat = func_02005728(6);

        if (func_02005728(2) == 0) {
            if (egg->fatherIvFlags[stat] == 0 && egg->motherIvFlags[stat] == 0) {
                egg->fatherIvFlags[stat] = 1;
                egg->inheritedIvCount++;
            }
        } else {
            if (egg->fatherIvFlags[stat] == 0 && egg->motherIvFlags[stat] == 0) {
                egg->motherIvFlags[stat] = 1;
                egg->inheritedIvCount++;
            }
        }
    }
}

/*
 * Copies the flagged IVs from the parents into the egg.
 */
void func_021C3FC0(struct Pokemon **parents, DayCareEgg *egg)
{
    StatTable ivIds = d_021DA918;
    u32 *ids = ivIds.ids;
    int i;

    for (i = 0; i < 6; i++) {
        if (egg->fatherIvFlags[i] != 0)
            egg->ivs[i] = func_02017E1C(parents[0], ids[i], 0);
        if (egg->motherIvFlags[i] != 0)
            egg->ivs[i] = func_02017E1C(parents[1], ids[i], 0);
    }
}

/* The egg belongs to the player: copies the trainer id. */
void func_021C4018(struct MyStatus *myStatus, DayCareEgg *egg)
{
    egg->otId = func_02008530(myStatus);
}

/* Rolls the personality value of the egg. */
void func_021C4024(struct Pokemon **parents, DayCareEgg *egg)
{
    egg->personalRnd = func_021C4078();
}

/*
 * Masuda method: parents of different languages get up to five more
 * personality rolls, stopping at the first shiny one.
 */
void func_021C4030(struct Pokemon **parents, DayCareEgg *egg)
{
    int i = 0;
    u32 fatherLanguage = func_02017E1C(parents[0], MON_DATA_LANGUAGE, 0);

    if (fatherLanguage == func_02017E1C(parents[1], MON_DATA_LANGUAGE, 0))
        return;
    if (func_02017ED8(egg->otId, egg->personalRnd) != 0)
        return;
    do {
        egg->personalRnd = func_021C4078();
        if (func_02017ED8(egg->otId, egg->personalRnd) != 0)
            return;
        i++;
    } while (i < 5);
}

/*
 * Random 32-bit value (tail call with minus one).
 */
u32 func_021C4078(void)
{
    return func_02005728(-1);
}

/*
 * Adds the moves the baby learns by level up at its starting level. The
 * learnset walk is a rotated loop (goto test) with the entry copied three times.
 */
void func_021C4084(DayCareEgg *egg)
{
    LearnsetEntry learnset[26];
    LearnsetEntry copyA, copyB, probe, entry;
    int i;
    int isEnd;
    u32 entryLevel, eggLevel, move;

    func_0201ADD0((u16)egg->species, (u16)egg->form, learnset);
    i = 0;
    goto test;
body:
    copyA = entry;
    copyB = entry;
    entryLevel = copyA.level;
    eggLevel = egg->level;
    move = copyB.move;
    if (eggLevel < entryLevel)
        return;
    func_021C42F4(egg, move);
    i++;
test:
    entry = learnset[i];
    probe = entry;
    isEnd = 0;
    if (probe.move == 0xffff && probe.level == 0xffff)
        isEnd = 1;
    if (!isEnd)
        goto body;
}

/*
 * Egg moves: moves the father knows that are in the egg move list of the
 * offspring species. The third parameter must exist and is forwarded as the
 * heap id; with two parameters the table copy takes r3/r2 instead of r4/r3.
 */
void func_021C40F8(struct Pokemon **parents, DayCareEgg *egg, u32 heapId)
{
    MoveSlotIdTable slotIds = d_021DA908;
    u32 *ids = slotIds.ids;
    u16 *eggMoves = func_02048F60(0x7b, egg->species, heapId);
    int eggMoveCount = eggMoves[0];
    int i;

    for (i = 0; i < 4; i++) {
        u32 move = func_02017E1C(parents[0], ids[i], 0);
        int j;

        for (j = 1; j <= eggMoveCount; j++) {
            if (move == eggMoves[j]) {
                func_021C42F4(egg, move);
                break;
            }
        }
    }
    func_020307B0(eggMoves);
}

/*
 * Moves of the offspring's learnset that both parents know. Twin of
 * func_021C4084 (same goto-rotated learnset walk). The call result must be
 * a named local (v == move gives cmp r0, r5), and isEnd = 0 goes after the
 * entry copies, as in the twin.
 */
void func_021C4160(struct Pokemon **parents, DayCareEgg *egg)
{
    LearnsetEntry learnset[26];
    MoveSlotIdTable slotIds = d_021DA8F8;
    LearnsetEntry copy, probe, entry;
    int i;
    int fatherKnows;
    int motherKnows;
    int isEnd;
    int slot;
    u32 move;
    u32 value;

    func_0201ADD0((u16)egg->species, (u16)egg->form, learnset);
    i = 0;
    goto test;
body:
    copy = entry;
    move = copy.move;
    fatherKnows = 0;
    motherKnows = 0;
    for (slot = 0; slot < 4; slot++) {
        value = func_02017E1C(parents[0], slotIds.ids[slot], 0);
        if (value == move) {
            fatherKnows = 1;
            break;
        }
    }
    for (slot = 0; slot < 4; slot++) {
        value = func_02017E1C(parents[1], slotIds.ids[slot], 0);
        if (value == move) {
            motherKnows = 1;
            break;
        }
    }
    if (fatherKnows && motherKnows)
        func_021C42F4(egg, move);
    i++;
test:
    entry = learnset[i];
    probe = entry;
    isEnd = 0;
    if (probe.move == 0xffff && probe.level == 0xffff)
        isEnd = 1;
    if (!isEnd)
        goto body;
}

/*
 * TM moves: moves the father knows that match a TM the offspring species can learn.
 */
void func_021C4238(struct Pokemon **parents, DayCareEgg *egg, u32 heapId)
{
    MoveSlotIdTable slotIds = d_021DA8E8;
    int i;

    for (i = 0; i < 4; i++) {
        u32 move = func_02017E1C(parents[0], slotIds.ids[i], 0);
        int tmItem;

        for (tmItem = TM_ITEM_FIRST; tmItem <= TM_ITEM_LAST; tmItem++) {
            if (move == func_020212B0(tmItem)) {
                if (func_021C447C(heapId, (u16)egg->species, (u16)egg->form, (u16)tmItem)) {
                    func_021C42F4(egg, move);
                    break;
                }
            }
        }
    }
}

/*
 * Pichu offspring learns Volt Tackle when a parent holds a Light Ball.
 */
void func_021C42BC(struct Pokemon **parents, DayCareEgg *egg)
{
    if (egg->species == SPECIES_PICHU) {
        if (func_02017E1C(parents[0], MON_DATA_HELD_ITEM, 0) == ITEM_LIGHT_BALL
            || func_02017E1C(parents[1], MON_DATA_HELD_ITEM, 0) == ITEM_LIGHT_BALL)
            func_021C42F4(egg, MOVE_VOLT_TACKLE);
    }
}

/*
 * Adds a move to the egg, skipping duplicates; when all four slots are
 * full the oldest move drops out.
 */
void func_021C42F4(DayCareEgg *egg, u32 move)
{
    int i;
    u32 count;

    if (move == 0)
        return;
    count = egg->moveCount;
    for (i = 0; i < count; i++) {
        if (move == egg->moves[i])
            return;
    }
    if (count < 4) {
        egg->moves[count] = move;
        egg->moveCount = egg->moveCount + 1;
        return;
    }
    for (i = 0; i < 3; i++)
        egg->moves[i] = egg->moves[i + 1];
    egg->moves[i] = move;
}

/*
 * Builds the day-care egg/offspring Pokemon from the 0x8C-byte egg record
 * (the struct func_021C38F4 fills on its stack). The bl to the Thumb
 * tail-call stub func_02018198 is witnessed by
 * src/matched/arm9/func_02018198.c.
 *
 * Load-bearing: const DayCareEgg *egg (the species/level loads rise above
 * the zero stack-argument stores), and heapId u16 at both callees
 * (func_02008510, func_0202F190) so it is re-read from its stack slot per call.
 */
void func_021C4340(struct Pokemon *mon, const DayCareEgg *egg, struct MyStatus *myStatus, u32 metPlace, u16 heapId)
{
    StatTable ivIds = d_021DA948;
    int i;
    struct StrBuf *str;

    func_02017588(mon, egg->species, egg->level, egg->otId, -1, egg->personalRnd);
    func_02017E40(mon, MON_DATA_FORM, egg->form);
    func_02017E40(mon, MON_DATA_NATURE, egg->nature);
    func_02017E40(mon, MON_DATA_FRIENDSHIP, egg->baseFriendship);
    if (egg->abilitySlot == 2)
        func_02018A00(mon, egg->species, egg->form);
    else
        func_02017E40(mon, MON_DATA_ABILITY_SET, egg->ability);
    for (i = 0; i < 6; i++) {
        if (egg->fatherIvFlags[i] != 0 || egg->motherIvFlags[i] != 0)
            func_02017E40(mon, ivIds.ids[i], egg->ivs[i]);
    }
    func_02017E40(mon, MON_DATA_MOVE1, egg->moves[0]);
    func_02017E40(mon, MON_DATA_MOVE2, egg->moves[1]);
    func_02017E40(mon, MON_DATA_MOVE3, egg->moves[2]);
    func_02017E40(mon, MON_DATA_MOVE4, egg->moves[3]);
    str = func_02008510(myStatus, heapId);
    func_02017E40(mon, MON_DATA_OT_NAME, (u32)str);
    func_02045808(str);
    str = func_02045EC0(g_020A7370, 0x28a);
    func_02017E40(mon, MON_DATA_NICKNAME, (u32)str);
    func_02045808(str);
    func_0202F190(mon, 5, myStatus, metPlace, heapId);
    func_02017E40(mon, MON_DATA_IS_EGG, 1);
    func_02018198(mon);
    func_020185C4(mon);
    func_0201B9F0(mon);
}

/*
 * Tests whether a species can learn a TM: reads the TM bit mask in the
 * personal data (four 32-bit words, TM index split across them).
 */
int func_021C447C(u32 heapId, u32 species, u32 form, u32 tmItem)
{
    u32 tmIndex, personal, mask;

    if (species >= SPECIES_COUNT)
        return 0;
    if (func_02021288(tmItem) == 0)
        return 0;
    personal = (u32)func_0201ADE4(species, form, heapId);
    tmIndex = func_0202130C(tmItem);
    if (tmIndex < 0x20) {
        mask = func_0201AE1C((const struct Personal *)personal, 0x27);
    } else if (tmIndex < 0x40) {
        mask = func_0201AE1C((const struct Personal *)personal, 0x28);
        tmIndex -= 0x20;
    } else if (tmIndex < 0x60) {
        mask = func_0201AE1C((const struct Personal *)personal, 0x29);
        tmIndex -= 0x40;
    } else {
        mask = func_0201AE1C((const struct Personal *)personal, 0x2a);
        tmIndex -= 0x60;
    }
    func_0201AE14((void *)personal);
    return mask & (1 << tmIndex);
}

/*
 * Maps a species to its base form via the evolution table (species below
 * 0x289).
 */
u16 func_021C4504(u16 species)
{
    u16 baseSpecies;

    if (species >= SPECIES_COUNT)
        return species;
    func_02048F74(&baseSpecies, 0x14, species, 0, (u32 *)2);
    return baseSpecies;
}

/*
 * Position of an ability among the three ability slots of a species/form
 * (0 when it matches none).
 */
u8 func_021C452C(u32 species, u32 form, u32 ability, u32 heapId)
{
    u32 abilities[3];
    u32 personal = (u32)func_0201ADE4(species, form, heapId);
    u32 slot;

    abilities[0] = func_0201AE1C((const struct Personal *)personal, 0x1a);
    abilities[1] = func_0201AE1C((const struct Personal *)personal, 0x1b);
    abilities[2] = func_0201AE1C((const struct Personal *)personal, 0x1c);
    func_0201AE14((void *)personal);
    for (slot = 0; slot < 3; slot++) {
        if (ability == abilities[slot])
            break;
    }
    if (slot >= 3)
        slot = 0;
    return slot;
}
