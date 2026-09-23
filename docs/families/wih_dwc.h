/*
 * docs/families/wih_dwc.h -- shared declarations for the wih_dwc.c family
 * (the DWC side of the wireless hand-off, "wih"), 0x02010360..0x02010888 in
 * the ARM9 image, plus the later wih_dwc.c rows 0x02010AC4.., 0x02010DCC.
 * __FILE__ anchor 0x020A7244 "wih_dwc.c", loaded by sub_02010360 (pool word
 * 0x020103D8) and func_02010794 (0x020107C8); the four zero bytes before it,
 * 0x020A7240, are the argument of the file's warning call func_02034714.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Written 2026-09-23
 * (wave 14) from the family's sources:
 *   EXACT   func_0201045C, sub_02010498, sub_020104F8, func_0201054C,
 *           sub_0201057C, func_02010794, func_020107CC, unit_02010848
 *           (func_02010848, func_02010864, func_02010884), func_02010888
 *   MATCH   sub_02010360, func_020103E4, func_0201058C, sub_020107FC
 *           (src/pending): every concrete byte right, each blocked ONLY on
 *           an unlabelled ov014 (wih.c) callee, see "Seeds" below.
 *
 * Seeds the family needs (integrator, layout/function_starts.txt):
 *   ov014 0x0217963C thumb  bl from arm9 0x020103B6 and 0x020103FE
 *   ov014 0x02177B80 thumb  bl from arm9 0x0201081A
 *   ov014 0x02178098 thumb  bl from arm9 0x020105E8
 *   arm9  0x02010848, 0x02010864, 0x02010884 thumb (unit_02010848.c)
 */

#ifndef WIH_DWC_H
#define WIH_DWC_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The global at 0x021461E0: word 0 is the live object (NULL when closed),
 * word 1 a second buffer func_02010794 allocates (0xA00 bytes, line 0x1C0).
 * Files that only touch word 0 declare it as `extern u8 *g_021461E0`. */
struct WihCtx {
    u8 *f0;         /* +0x00  struct WihDwc * */
    u8 *f4;         /* +0x04 */
};

/* The object, 0x328 bytes, allocated by sub_02010360 (line 0x49). */
struct WihDwc {
    u8  rec[4][0xC0];   /* +0x000  received records, filled by func_0201045C
                         *         (MI_CpuCopy8 of 0xC0 bytes), drained by
                         *         func_0201058C */
    u32 buf;            /* +0x300  func_0205D010()-sized buffer, line 0x4C */
    u8 *ctx4;           /* +0x304  copy of WihCtx.f4 */
    u8  pad308[4];
    u16 f30C;           /* +0x30C  nonzero pauses the countdowns */
    u16 hold;           /* +0x30E  countdown, 400 on a latch */
    u16 cap;            /* +0x310  capacity (the constructor's index arg) */
    u16 latched;        /* +0x312  func_02010848 reads it */
    u16 pending;        /* +0x314  func_02010864 raises it (below 4) */
    u16 count;          /* +0x316  records queued this frame */
    int timer[4];       /* +0x318  countdowns (600, 600, 400, 400),
                         *         sub_02010498 decrements */
};

extern struct WihCtx g_021461E0;
extern u8 sWihDwc;          /* 0x020A7240 */
extern u8 sWihDwcFile[];    /* 0x020A7244 "wih_dwc.c" */
extern u8 ov015_id[];       /* 0x0000000F, pooled linker symbol */

extern void  func_02034714(void *dst, u32 val, void *dst2);   /* warning */
extern u8   *func_0203D7C8(void *heap, u32 size, u8 *file, u32 line);
extern void  func_0203D7FC(u32 p);                            /* free */
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size); /* 0x02082D44 */
extern void  OS_GetMacAddress(u8 *mac);                       /* 0x02087C6C */
extern u8   *func_0203D798(void);    /* DWC context; +0x62 slot count,
                                      * +0x67 connection state */
extern int   func_0205D01C(u32 buf, u8 *rec, void *out40); /* 0x40-byte out */

/* ov014 (wih.c) entry points, unlabelled in asm/overlays/ov014.s: */
extern void  func_0217963C(void (*cb)(const void *src)); /* sets +0x1E88 */
extern int   func_02177B80(int slot);
extern u8    func_02178098(u8 slot);

u8  *sub_02010360(int idx, void *heap);           /* create  */
void func_020103E4(u8 *p);                         /* destroy */
void func_0201045C(const void *src);               /* receive callback */
void sub_02010498(void);                           /* countdown tick */
int  sub_020104F8(u8 *rec);
int  func_0201054C(const u8 *rec);
u32  func_0201057C(const u8 *rec);
u32  func_0201058C(void *key);                     /* per-frame status flags */
void func_02010794(u8 *p);
void func_020107CC(void);
int  sub_020107FC(void *key);                      /* slot lookup, -1 none */
u16  func_02010848(void);
void func_02010864(u32 v);
void func_02010884(void);

#endif
