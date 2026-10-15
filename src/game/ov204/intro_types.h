#ifndef INTRO_TYPES_H
#define INTRO_TYPES_H

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Obj;

struct WordSet;

struct Rec;

struct Rec3;

/* One slot of the intro command work: tag plus two data words. */
typedef struct Slot { unsigned data[3]; } Slot;

/* A 3D vector of ints (camera position and friends). */
typedef struct IntroVec { int v[3]; } IntroVec;

/*
 * One MCSS animation slot. The object pointer is the MCSS_Add result; the
 * MCSS anim callback (INTRO_G3D_OnAnimEnd) marks animFinished and, when
 * loopAnim is set, restarts the animation.
 */
typedef struct IntroMcssSlot {
    void *object;               /* 0x00: MCSS_Add result */
    unsigned int animFinished;  /* 0x04 */
    unsigned int loopAnim;      /* 0x08 */
} IntroMcssSlot;

/*
 * The intro MCSS effect object (0x6C allocated). Shared by intro_mcss.c
 * (create/delete/add) and intro_g3d.c (slot helpers).
 */
typedef struct IntroMcssWork {
    unsigned short heapId;      /* 0x00 */
    unsigned char pad_2[2];
    void *sys;                  /* 0x04: MCSS_Init result */
    IntroMcssSlot slots[8];     /* 0x08 */
    unsigned int idleTimer;     /* 0x68: random idle countdown */
} IntroMcssWork;

#endif
