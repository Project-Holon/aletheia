/*
 * Types of the union room field code (ov019 union_chara.c and union_oneself.c): the actions of
 * the avatars of the other players on the field and of the player's own
 * avatar.  The shared room types (UnionCharaSlot, UnionMySituation, ...) are
 * in ../ov012/union_comm_types.h.
 * Needs u8, u16, u32, s16 and ../ov012/union_comm_types.h from the including
 * file.
 */
#ifndef UNION_CHARA_TYPES_H
#define UNION_CHARA_TYPES_H

/* Phases of one action of an avatar or of the player (start, main, end). */
#define UNION_ACTION_PHASE_MAX 3

/* Actions of the avatar of another player (UnionCharaSlot.action). */
#define UNION_CHARA_ACTION_IDLE      0
#define UNION_CHARA_ACTION_APPEAR    1
#define UNION_CHARA_ACTION_DISAPPEAR 2
#define UNION_CHARA_ACTION_TALK      3

/* Header of a field object, as FLDMMDL_AddMmdl reads it (0x24 bytes). */
typedef union UnionCharaMmdlHeader {
    u32 raw[9];
    struct {
        u16 objId;             /* 0x00 */
        u16 graphicsId;        /* 0x02 */
        u16 moveCode;          /* 0x04 */
        u16 rest[15];          /* 0x06 */
    } f;
} UnionCharaMmdlHeader;

typedef struct UnionGridPos {
    s16 x;
    s16 z;
} UnionGridPos;

typedef int (*UnionCharaActionFunc)(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
typedef int (*UnionOneselfActionFunc)(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step);

/* The action tables are three symbols one word apart (start, main, end), with
 * 12 bytes per action. */
typedef struct UnionCharaActionEntry {
    UnionCharaActionFunc func;
    u32 otherPhases[2];
} UnionCharaActionEntry;

typedef struct UnionOneselfActionEntry {
    UnionOneselfActionFunc func;
    u32 otherPhases[2];
} UnionOneselfActionEntry;

#endif
