/*
 * Types shared by the intrude field code (intrude_field.c) and the sub screen
 * code (intrude_subdisp.c) of ov018. Needs u8, u16 and s16 from the including
 * file.
 */
#ifndef INTRUDE_FIELD_TYPES_H
#define INTRUDE_FIELD_TYPES_H

struct GameSystem;
struct FieldMap;

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
