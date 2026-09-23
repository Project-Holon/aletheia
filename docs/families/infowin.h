/*
 * docs/families/infowin.h -- shared declarations for the infowin.c family
 * (the top-screen info window: clock, battery, link and wireless icons),
 * 0x02024A20..0x020252D8 in the ARM9 image.  __FILE__ anchor 0x020A7478
 * ("infowin.c"), named by the pool word at 0x02024AB0.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.
 *
 * Members, all Thumb, all EXACT (wave 14 closed the four that were open):
 *   func_02024A20  constructor           src/matched/func_02024A20.c
 *   func_02024ABC  per-frame state poll  src/matched/func_02024ABC.c
 *   func_02024DCC  destructor            src/matched/func_02024DCC.c
 *   func_02024DFC  redraw task callback  src/matched/func_02024DFC.c
 *   func_02025154  tile-rect writer      src/matched/func_02025154.c
 *   func_020251D8  palette loader        src/matched/func_020251D8.c
 *   func_020251FC  graphics setup        src/matched/func_020251FC.c
 *   func_020252A8  RTC poll              src/matched/func_020252A8.c
 *
 * NOTE ON OLD NOTES.  docs/notes/func_02024A20.c.txt (2026-09-21) names the
 * singleton at 0x0202693C and a second global at 0x02020214; both readings
 * are wrong.  Every pool word in the family names 0x0214693C, one pointer.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The singleton, 0x28 bytes (func_02024A20 allocates 0x28 and clears it). */
struct InfoWin {
    u32 f00;        /* +0x00 char base; func_020251FC stores it           */
    u16 f04;        /* +0x04 dirty bits: 1 clock, 4 link, 8 wireless,
                     *       0x10 battery, 0x20 TWL icon; state bits 0x200,
                     *       0x400, 0x800, 0x1000.  Cleared with u16 masks
                     *       (pool 0x0000EFFF, not ~0x1000) and set with the
                     *       spelled-out `f = (u16)(f | X)` (func_02024ABC);
                     *       the draw task retires a bit with `f04 - BIT`  */
    u8  f06;        /* +0x06 bg frame; first argument of every BG call    */
    u8  f07;        /* +0x07 palette row (<< 12, and << 4 in 020251D8)    */
    u8  f08;        /* +0x08 battery blink phase, 0..0x4F                 */
    u8  f09;
    u8  pad0A[2];
    u32 f0C;        /* +0x0C func_0201283C(arg) result; func_0201058C key  */
    u32 f10;        /* +0x10 func_02012BB0(arg) result; 1 = beacon mode    */
    u32 f14;        /* +0x14 PM flag (clock colon tile 11/15, 27/31)       */
    u32 f18;
    u8  f1C;        /* +0x1C minute                                        */
    u8  f1D;        /* +0x1D hour                                          */
    u8  f1E;        /* +0x1E frame counter, 60-frame poll                  */
    u8  f1F;        /* +0x1F func_0203568C() (battery / TWL index)         */
    u32 f20;        /* +0x20 wireless-active latch                         */
    void *f24;      /* +0x24 task handle from func_020056A0                */
};

extern struct InfoWin *gInfoWin;              /* 0x0214693C */
extern const char infowin_File[];             /* 0x020A7478 */

/* Prototypes settled by the matched members. */
void func_02024A20(u8 bg, u8 pal, void *arg, u16 heap);   /* heap is u16 */
void func_02024ABC(void);
void func_02024DFC(void *work);
void func_02025154(u32 base, u32 pal, u8 x, u8 y, u8 w, u8 h); /* all u8 */
int  func_020251D8(int row, const void *colors, int count);
void func_020251FC(u32 bg, u32 pal, u32 heap);
void func_020252A8(void);

/* Externals. */
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);    /* 0x02082BCC */
extern void *func_020056A0(void (*cb)(void *), void *work, u32 pri);
extern int   func_0203568C(void);   /* returns a byte; callers truncate  */
extern void  func_020410D0(u32 bg, u32 x, u32 y, u32 w, u8 h, void *src,
                           u8 sx, u8 sy, u8 sw, u8 sh);
