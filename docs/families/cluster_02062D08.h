/*
 * docs/families/cluster_02062D08.h -- shared declarations for the
 * pseudo-family at 0x02062BF4..0x02062F38 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.
 *
 * WHAT IT IS.  The NitroSystem G2D ANIMATION CONTROLLER (g2d_Animation.c
 * shape): func_02062D4C ticks it, func_02062BF4 handles reaching an edge of
 * the sequence (loop / reverse / stop by play mode), func_02062D08 seeks to a
 * frame index, func_02062F00 is the seek-and-reset-time wrapper,
 * sub_02062F1C the current frame index, func_02062D40 the current frame's
 * content.  The bank types it walks are cluster_02062688.h's AnimSequence /
 * AnimFrame.
 *
 * COMPILER.  Mixed.  ../2.0/sp2: func_02062BF4, func_02062D4C.  dsi/1.1p1:
 * func_02062D08, func_02062D40, func_02062F00, sub_02062F1C.  The 2.0 tell in
 * func_02062D4C is every inline instance's 0/1 constants hoisted into their
 * OWN callee-saved pair and a ten-register push (1.1p1 pushes six).
 *
 * ISA: ARM.  Always pass `--arm`.
 */
#ifndef CLUSTER_02062D08_H
#define CLUSTER_02062D08_H

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;
typedef int            BOOL;

typedef struct { void *pContent; u16 frames; u16 pad; } Frame;   /* stride 8 */

typedef struct {
    u16    numFrames;          /* 0x00  forward edge = array + numFrames      */
    u16    loopStartFrameIdx;  /* 0x02  backward edge = array + this - 1      */
    u32    animType;           /* 0x04 */
    u32    playMode;           /* 0x08  used when ctrl +0x18 is 0             */
    Frame *pFrameArray;        /* 0x0c */
} Seq;

typedef struct {
    u32  type;                 /* 0x20  0 none, 2 on frameIdx, 3 every frame  */
    u32  param;                /* 0x24  callback argument 1                   */
    void (*pFunc)(u32 param, u32 idx);   /* 0x28                              */
    u16  frameIdx;             /* 0x2c  ldrh                                  */
} Functor;

typedef struct {
    Frame  *pCurrent;          /* 0x00 */
    Frame  *pActiveCurrent;    /* 0x04  last frame with a non-zero length     */
    BOOL    bReverse;          /* 0x08  xor'd with (speed > 0): teq           */
    BOOL    bActive;           /* 0x0c  tick requires == 1                    */
    s32     currentTime;       /* 0x10  fx32                                  */
    s32     speed;             /* 0x14  fx32, sign is direction               */
    u32     overriddenPlayMode;/* 0x18 */
    Seq    *pAnimSequence;     /* 0x1c */
    Functor callback;          /* 0x20 */
} Ctrl;

extern s32  func_02091588(s32 x);                 /* abs, MSL                 */
extern void func_02062BF4(Ctrl *p);               /* edge handler, sp2        */
extern BOOL func_02062D4C(Ctrl *p, s32 frames);   /* tick, sp2, EXACT wave 12 */
extern int  func_02062D08(void *p, u32 i);        /* seek, 1.1p1              */
extern int  func_02062F00(void *p);               /* seek + time = 0          */
extern u16  sub_02062F1C(const void *p);          /* (cur - array) >> 3       */

/* func_02062D4C levers: the loop test is an inline `if (bActive && time >=
   len << 12) return 1; return 0;`; the edge test binds only `cur` before the
   direction test and reads the array inside each arm; the frame index is the
   u32 byte difference >> 3 narrowed to u16.                                  */

#endif /* CLUSTER_02062D08_H */
