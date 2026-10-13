#ifndef OV038_FIELD_GIMMICK_PLATE_DOORS_TYPES_H
#define OV038_FIELD_GIMMICK_PLATE_DOORS_TYPES_H

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/*
 * Runtime state of gimmick 38 (FIELDMAP common work, block 1, 0x24 bytes).
 * The saved state is FieldGimmickPlateDoorsWork (src/game/ov037/gimmick_save_types.h).
 */
typedef struct FieldGimmickPlateDoorsRuntime {
    unsigned char switchIdx;        /* 0x00 switch of the running switch event */
    unsigned char plateIdx;         /* 0x01 plate of the running plate event */
    unsigned char scriptVariant;    /* 0x02 selects the script of the scripted event */
    unsigned char doorIdx;          /* 0x03 door of the running door event */
    unsigned char plateDoorIdx;     /* 0x04 door that the pressed plate opens */
    unsigned char slideFrames;      /* 0x05 frames of the slide in progress */
    unsigned char side;             /* 0x06 which side the player pushes from (0 or 1) */
    unsigned char holdFrames;       /* 0x07 frames the push key is held */
    VecFx32 doorPos;                /* 0x08 home position of the door */
    int acmdList;                   /* 0x14 player animation command list, 0 when none */
    int acmdDone;                   /* 0x18 the push animation has ended */
    int acmdActive;                 /* 0x1C the push animation was started */
    int slideSePlayed;              /* 0x20 the slide sound was started */
} FieldGimmickPlateDoorsRuntime;

#endif
