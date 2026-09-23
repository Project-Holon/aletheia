/*
 * docs/families/net_err.h -- shared declarations for the net_err.c family
 * (0x0200F6D8..0x0201034C in the ARM9 image).  The __FILE__ anchor is
 * "net_err.c" at 0x020A7234 (layout/file_anchors.txt, pool site 0x0200F730
 * in sub_0200F6D8).  The family is the network error screen: it saves the
 * whole 2D display state into one module object, draws an error window on
 * BG1, waits for A/B, and restores everything.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Every declaration is derived from an EXACT file in src/matched, named
 * beside it.  Addresses are Black-image addresses.
 *
 * ISA: Thumb throughout.  COMPILER: dsi/1.1p1 for every function (no sp2
 * pin in this family; 1.1p1's "repeated small constant held in a callee-
 * saved register" behaviour is visible and correct here, e.g. the constant
 * 1 in r5 of func_020101D4 and the 0 in r4 of func_0200FC0C).
 *
 * ============================================================================
 * THE TWO SPELLING RULES THAT CLOSED WAVE 13 (read before writing C here)
 * ============================================================================
 *  1. REACH THE MODULE OBJECT THROUGH A NAMED LOCAL (`u8 *g = g_0214617C;`).
 *     mwccarm then rematerialises the pool word per access and reaches the
 *     +0x59/+0x5A/+0x58 bytes with `adds rN, #0x59; ldrb [rN]`.  Spelling
 *     the extern directly (`g_0214617C[0x59]`) folds to a SECOND pool word
 *     g+0x40 (0x021461BC) with `ldrb [rN, #0x19]` -- which is also correct,
 *     but only where the image has that 0x021461BC word (sub_0200FB6C,
 *     unit_0200F7C0, and the last test of sub_0200FD38).  The pool tells you
 *     which spelling each access used.
 *  2. The NitroSDK gx.h / g2.h / pad.h inlines are real here: GXDispCnt,
 *     GXBg01Control and GXWndPlane bitfields, GX[S]_SetVisiblePlane /
 *     SetVisibleWnd, G2_SetBG1Control / G2_BG1Mosaic / G2_SetBG1Offset,
 *     G2[S]_SetWndOutsidePlane / SetWndOBJInsidePlane, PAD_DetachedCover and
 *     PAD_Read.  Write them as the SDK spells them (see func_0200F83C.c and
 *     sub_0200FD38.c for copies) and the bit twiddling comes out exact.
 *     A wait loop in this family is
 *        while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) != 0)
 *     where KeyFilter drops the opposing D-pad bits (k & ~((k&0x40)<<1) &
 *     ~((k&0x20)>>1)) -- func_0200FC0C.c.
 * ------------------------------------------------------------------------- */

#ifndef NET_ERR_H
#define NET_ERR_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

/* ------------------------------------------------------------------ *
 * 1.  THE MODULE OBJECT at 0x0214617C (0x64 bytes, MI_CpuFill8'd by
 *     sub_0200F6D8 / sub_0200F6B8).  Declared in matched files variously as
 *     u8[] / u32[] / struct pads; offsets are what the code constrains.
 * ------------------------------------------------------------------ */
typedef struct NetErrWork {
    void *bg1Char;      /* +0x00 0x4000-byte BG1 char backup; sub_0200F6D8 allocates, FD38 saves, FEBC restores */
    void *bg1Scr;       /* +0x04 0x800-byte BG1 screen backup */
    void *pltt;         /* +0x08 0x20-byte palette backup (0x05000000) */
    u32   dispCnt;      /* +0x0C GXDispCnt of the main engine; sub_0200FD38 */
    u16   bg1Cnt;       /* +0x10 GXBg01Control saved by FD38, unpacked by FEBC */
    u16   pad12;
    int   bright;       /* +0x14 main master brightness; sub_0200F800 writes it back */
    int   subBright;    /* +0x18 sub master brightness */
    BOOL  hBlank;       /* +0x1C GX_HBlankIntr(FALSE) result; func_0200FC0C, FD38 */
    BOOL  vBlank;       /* +0x20 GX_VBlankIntr(FALSE) result */
    u32   bankBG;       /* +0x24 func_020808F4() result, back through GX_SetBankForBG */
    u32   bankSubBG;    /* +0x28 func_020809A0() result, back through GX_SetBankForSubBG */
    u32   state;        /* +0x2C 0 idle, 1 claimed (sub_0200FAAC), 2 showing (sub_0200FB38, FC0C) */
    u32   f30;          /* +0x30 cleared by func_0200FC0C */
    u16   bldCnt;       /* +0x34 main BLDCNT (FD38 stores BOTH engines here -- image bug) */
    u16   subBldCnt;    /* +0x36 sub BLDCNT (FEBC restores from here) */
    u32   f38;          /* +0x38 func_02043668() result, back via func_020435F4 */
    int   subWnd;       /* +0x3C GXS visible-window mask */
    u16   pltt0;        /* +0x40 sub BG palette colour 0 (0x05000400); set to 0x7EEA */
    u16   pad42;
    u32   f44;          /* +0x44 sub_0200F7E8 setter; ==1 keeps the screen dark (func_0200F83C) */
    u32   err[4];       /* +0x48 16-byte error block copied from func_0203CA98(); sub_0200FAAC.
                         *       err[3] (+0x54) is the 0x3EE..0x3F7 reason code
                         *       sub_02010158 maps; err[1] (+0x4C) picks the +0x5C result */
    u8    f58;          /* +0x58 func_0203C990() byte; message index in non-link modes */
    u8    linkMode;     /* +0x59 func_0203D798()[0x65]; 1, 2, 6 = link modes; 0x60 = no backup */
    u8    useStored;    /* +0x5A one-shot: use +0x60 verbatim (func_020101D4 clears it) */
    u8    pad5b;
    u32   result;       /* +0x5C 1 or 2; sub_0200FB24 returns it while +0x2C is set */
    u32   errNo;        /* +0x60 error number; sub_0200F7C0 sets it; indexes the
                         *       sixteen-entry u16 tables 0x0209DEB0 / 0x0209DED0 */
} NetErrWork;

extern u8 g_0214617C[];   /* 0x0214617C  the object above */
extern u8 g_021461BC[];   /* 0x021461BC  == g_0214617C + 0x40, the folded pool word */

/* ------------------------------------------------------------------ *
 * 2.  FUNCTIONS (all thumb; EXACT file named)
 * ------------------------------------------------------------------ */
void  sub_0200F6B8(void);                 /* reset, MI_CpuFill8 0x64 */
void  sub_0200F6D8(u32 heap);             /* allocate the three backups */
void  sub_0200F734(void);                 /* PENDING MATCH: overlay callee 0x02156460 is a Thumb label
                                           * in ov009 (declare `thumb ov009`) but its only caller is
                                           * this function; needs an overlay sole-ref rule */
void  func_0200F7B8(u32 a);               /* tail call to func_0200FC0C */
void  sub_0200F7C0(u32 err);              /* unit_0200F7C0: set +0x60 and show */
void  sub_0200F7E8(u32 v);                /* +0x44 setter */
void  sub_0200F800(void);                 /* restore master brightness */
void  sub_0200F824(void);                 /* poll link, OS_WaitIrq */
void  func_0200F83C(void);                /* fatal-error screen (window planes) */
void  sub_0200FA84(void);                 /* abort if func_02010054() */
void  sub_0200FA94(void);                 /* abort path: never returns */
void  sub_0200FAAC(void);                 /* claim: snapshot error state */
u32   sub_0200FB24(void);                 /* result getter */
/*    sub_0200FB38 (unlabelled, DIFF r0/r1 swap) bumps +0x2C from 1 to 2 */
void  sub_0200FB6C(void);                 /* free the backups */
void  sub_0200FBA0(void);                 /* clear +0x2C and +0x5C */
u32   sub_0200FBB0(void);                 /* link poll loop */
u32   func_0200FC0C(u32 a0);              /* blocking error screen, returns 1 if shown */
void  sub_0200FD38(u32 a0, u32 a1);       /* save 2D state and draw */
void  sub_0200FEBC(BOOL keepDark);        /* restore 2D state; EXACT once G2_SetBG1Control
                                           * takes the SDK ENUM parameter types (see
                                           * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md) */
u32   func_02010054(void);                /* "module live"; NOT CTRDGi_IsTaskAvailable
                                           * (symbols_sdk.json's name is a false
                                           * signature hit, dupes 11) */
void  sub_02010068(u32 which);            /* load the window graphics */
u32   sub_02010158(u8 *errBlock);         /* reason code -> message id */
void  func_020101D4(u32 a0, u32 a1);      /* draw the message window */
int   func_0201034C(void);                /* one frame: func_020053EC, func_02034F5C, ... */

#endif /* NET_ERR_H */
