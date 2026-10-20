#ifndef MUSICAL_EVENT_SHARED_TYPES_H
#define MUSICAL_EVENT_SHARED_TYPES_H

#include "../ov010/event_ircbattle_shared_types.h"

#include "../types.h"

struct MusicalSave;

/* ---- musical ---- */

/* One equipped prop of a performer, indexed by body slot. */
typedef struct MusicalEquip {
    u16 propId;                         /* 0xFF = none */
    s16 offset;
    u8 order;                           /* position in the show record list */
    u8 pad5;
} MusicalEquip;

#define MUSICAL_EQUIP_SLOTS 9

#define MUSICAL_APPEAL_KINDS 4

#define MUSICAL_PERFORMERS 4

typedef struct MusicalPerformer {
    u32 origin;                         /* 0x00: MUSICAL_PERFORMER_* */
    u8 pad04[4];
    u16 monsNo;                         /* 0x08 */
    u8 gender;                          /* 0x0A */
    u8 form;                            /* 0x0B */
    u8 shiny;                           /* 0x0C */
    u8 pad0D[3];
    u32 personality;                    /* 0x10 */
    MusicalEquip equips[MUSICAL_EQUIP_SLOTS]; /* 0x14 */
    u16 totalScore;                     /* 0x4A */
    u16 appealScore[MUSICAL_APPEAL_KINDS]; /* 0x4C */
    u32 equipUsed[MUSICAL_EQUIP_SLOTS]; /* 0x54 */
    u16 appealBase;                     /* 0x78 */
} MusicalPerformer;

/* The four performers of one show, plus what created them. */
typedef struct MusicalStage {
    void *session;                      /* 0x00 */
    MusicalPerformer *performers[MUSICAL_PERFORMERS]; /* 0x04 */
    struct MusicalShowProgram *program; /* 0x14 */
    void *musicalSystem;                /* 0x18 */
    u8 pad1C[4];
} MusicalStage;

/* A show program of the musical system table (0x2C bytes). */
typedef struct MusicalProgramEntry {
    u8 id;                              /* 0x00 */
    u8 bonus[MUSICAL_APPEAL_KINDS];     /* 0x01 */
    u8 bonusTotal;                      /* 0x05 */
    u8 propRow;                         /* 0x06 */
    u8 pad07[0x14 - 0x07];
    u16 levelRequired;                  /* 0x14 */
    u8 pad16[0x2C - 0x16];
} MusicalProgramEntry;

/* Head of the ov112 musical system object. */
typedef struct MusicalSystemHead {
    u32 reserved00;                     /* 0x00 */
    MusicalProgramEntry *programs;      /* 0x04 */
    const void *msgFile;                /* 0x08 */
} MusicalSystemHead;

/* One prop slot of an NPC template. */
typedef struct MusicalRivalProp {
    u16 propId;                         /* 0x1FE, 0x1FF = none */
    u8 bodySlot;
    u8 pad03;
} MusicalRivalProp;

/* An NPC performer template (0x2C bytes, in the table behind the program). */
typedef struct MusicalRivalEntry {
    u16 monsNo;                         /* 0x00 */
    u8 personality[4];                  /* 0x02 */
    u16 appealBase;                     /* 0x06 */
    u8 pad08[4];
    MusicalRivalProp props[8];          /* 0x0C */
} MusicalRivalEntry;

typedef struct MusicalRivalTable {
    u8 pad00[0x0C];
    MusicalRivalEntry entries[1];       /* 0x0C */
} MusicalRivalTable;

/* NPC bytes read by the accessors (same 0x2C-byte records). */
typedef struct MusicalNpcInfo {
    u8 pad00[0x0E];
    u8 portraitClass;                   /* 0x0E */
    u8 nameId;                          /* 0x0F */
    u8 pad10[0x1C];
} MusicalNpcInfo;

/*
 * The random show program: the appeal bonus to split, the share per prop,
 * the three NPC picks, and the table the picks index. The table is read in
 * three layouts by different functions, hence the union.
 */
typedef struct MusicalShowProgram {
    u8 categoryBonus[MUSICAL_APPEAL_KINDS]; /* 0x00 */
    u8 sharePerProp[MUSICAL_APPEAL_KINDS];  /* 0x04 */
    u8 picks[4];                        /* 0x08: three used */
    union {
        MusicalProgramEntry *programs;
        MusicalRivalTable *rivals;
        MusicalNpcInfo *npcInfo;
    } catalog;                          /* 0x0C */
} MusicalShowProgram;

/* Parameter block of the dress-up proc (12 bytes, heap). */
typedef struct MusicalDressupParam {
    void *session;                      /* 0x00 */
    MusicalPerformer *performer;        /* 0x04 */
    struct MusicalSave *save;           /* 0x08 */
} MusicalDressupParam;

#endif
