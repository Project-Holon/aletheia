/*
 * Types shared by the intrude field code (intrude_field.c) and the sub screen
 * code (intrude_subdisp.c) of ov018. Needs u8, u16, u32 and s16 from the
 * including file.
 */
#ifndef INTRUDE_FIELD_TYPES_H
#define INTRUDE_FIELD_TYPES_H

struct GameSystem;
struct FieldMap;

/*
 * One entry of the Entralink zone table INTRUDE_FIELD_gZonePositions (0x0C
 * bytes), returned by INTRUDE_FIELD_FindZonePos to both the field code and the
 * sub screen. The field code reads zoneId/tileX/tileY/tileZ (the anchor tile of
 * INTRUDE_FIELD_GetZoneAnchor); the sub screen reads zoneId/zoneIdAlt/townId
 * and x/y (the position on the map screen). The two views used disjoint fields
 * of the same record, so this is one struct, not two.
 */
typedef struct IntrudeZonePos {
    u32 zoneId : 10;        /* 0x00 */
    u32 zoneIdAlt : 10;     /* second zone this entry also stands for */
    u32 townId : 10;        /* town the warp event targets */
    u32 flags : 2;          /* never read */
    s16 tileX;              /* 0x04: anchor tile, read by INTRUDE_FIELD_GetZoneAnchor */
    s16 tileY;              /* 0x06 */
    s16 tileZ;              /* 0x08 */
    u8 x;                   /* 0x0A: position on the sub screen */
    u8 y;                   /* 0x0B */
} IntrudeZonePos;

/*
 * Work of the player spin that changes the appearance (0x18 bytes). The
 * mirrored-player animation of the sub screen (INTRUDE_FIELD_InitMmdlCopyAnime)
 * uses the same record and also fills copyIndex and copyMmdl.
 */
typedef struct PlayerSpinWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    s16 shownStep;                  /* 0x08 */
    s16 stepFrames;                 /* 0x0A: counts down from 15, the turn gets faster */
    u16 objCode;                    /* 0x0C: appearance to switch to */
    u8 kind;                        /* 0x0E */
    u8 flag;                        /* 0x0F */
    u8 state;                       /* 0x10 */
    u8 dirIndex;                    /* 0x11: index into the turn command list */
    u8 switched;                    /* 0x12: set once the appearance changed */
    u8 copyIndex;                   /* 0x13: copy animation only: direction code of the copy, 3 = right */
    void *copyMmdl;                 /* 0x14: copy animation only: field model of the copy, 0 = none */
} PlayerSpinWork;

#endif
