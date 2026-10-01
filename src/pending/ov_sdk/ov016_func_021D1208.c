/*
 * function: DWCi_WINlInitEx
 * address:  0x021D1208
 * packet:   pkt_ov016_021D1208
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss, 788 of 796 bytes)
 *
 * lane W8b (2026-10-01, deadline hit): re-confirmed 788/796, 504 concrete,
 *           26/32 relocs.  Whole standing gap is the front end's fp-priority:
 *           ours homes the MSGlGetEx result `ms` to fp (`mov fp,r0` at +0064)
 *           and copies `msg` to ip (`mov ip,r0`), giving a 0x20 frame plus a
 *           dummy padding r3; the image homes `msg` to fp transiently (+002C)
 *           and spills `ms` to [sp+0x14] (+0064), giving frame 0x24 and no
 *           padding.  With `volatile int d = dark;` dark is already on the
 *           stack at [sp+0x10] exactly as DWARF says; only `ms` differs.
 *           Measured inert this wave (all 788/504, 26/32): a one-member
 *           `struct { u16 *p; } msloc` wrapper (scalarised, ms still fp),
 *           the reverse-DWARF declaration order EFF,ms,obj,i, declaring ms
 *           at its assignment site (C99), and declaration order permutations.
 *           `void *msg` param is a compile error at the MSGlGetEx call.
 *           This is the 1024-vs-1025 allocator tie documented by
 *           vendor-front-end-parameter-register-set-cannot-be-forced.md and
 *           a-spilled-pointer-parameter-tie-is-the-front-ends-not-a-source-shape.md.
 *
 * blocker:  whole function reconstructed (prologue GUI setup, per-type
 *           button loop, font/canvas formation, window-plane setup, blend
 *           register, taskV/taskMove selection).  Now 788 of 796 bytes and
 *           504 concrete (was 784/567): the image spills `dark` to a WORD
 *           slot at [sp+0x10] and reloads it at +0x98 and +0x28C, so `dark`
 *           is read through a volatile int local (`volatile int d = dark;`,
 *           used for both `g_021DE658->dark = d;` and `if (d)`); that drops
 *           the whole function into the image's spilling shape.  `volatile
 *           u8`, `volatile bool`, a volatile `bool dark` parameter and a
 *           plain `int dark` parameter all measure 788/504 or worse
 *           (volatile param 804/518), so the remaining 8 bytes are elsewhere.
 *           Residue, 196 diff lines: the frame is still 0x20 against 0x24 and
 *           our push carries a padding r3 the image does not need (image push
 *           {r4..fp,lr}, ours {r3,r4..fp,lr}); the image hoists the DWCiMsgCmn
 *           pool word to r4 and the EFF source word to r5, and `dark` lands
 *           in fp/ip instead of the image's byte-store order.  147 of the
 *           lines are one instruction shifted.
 *
 * lane W7 (2026-09-30): re-measured 788/796, 26/32 relocations, 504 concrete
 * bytes.  The whole 8-byte gap is the unresolved `ms` spill: the image stores
 * ms to [sp+0x14] and reloads it, giving a 0x24 frame with a 9-register push;
 * this build keeps ms live in a callee-saved register (fp), so the frame is
 * 0x20 and the push carries a padding r3, and every later offset shifts.
 * Measured and rejected this wave: `u16 * volatile ms` (800/553), an `ms[1]`
 * array (788/504, scalarised), an address-taken `u16 **pms` (784/581), a
 * `hundred`/`volatile hundred` 0x100 local (788/504, 792/552), and keeping the
 * msg parameter in a local (788/504).  This is the 1.1p1 register allocator's
 * rematerialisation policy, not a source or witness problem.
 *
 * lane W8 (2026-09-30, deadline hit): re-confirmed 788/796, 504 concrete, 26/32
 *           relocs.  Whole 8-byte gap is exactly the `ms` slot: image frame
 *           0x24 with 9-word push {r4-r8,sb,sl,fp,lr}; ours 0x20 with a dummy
 *           padding r3 -> 10-word push.  Image slot order is dark 0x10, ms
 *           0x14, obj 0x18, EFF 0x1c (reloading ms at +01E8 via `ldr r0,[sp,
 *           #0x14]`); ours has obj 0x14, EFF 0x18 and keeps ms in fp (`mov fp,
 *           r0` at +0064).  Measured this wave: holding ms in a `u32` local and
 *           casting at the call is byte-identical to the `u16 *` spelling
 *           (788/504) -- the allocator still keeps it in fp and only realigns
 *           with r3.  Forcing the spill by declaration order/env/type resists
 *           under 1.1p1 (see W7 list).  blocker unchanged: image spills the ms
 *           return to [sp+0x14]; this allocator hoists it into a callee-saved
 *           register instead.
 *
 * sdk:      DWCi_WINlInitEx (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_MSGlGetEx                   0x021c1048 arm
 *   DWCi_HEAPlAllocEx                0x021d6414 arm
 *   G2x_SetBlendBrightness_          0x0207d658 arm
 *   DWCi_CEINlSetExCell              0x021d5394 arm
 *   DWCi_CELLlSetPosition            0x021d5118 arm
 *   DWCi_CELLlSetPriority            0x021d51f0 arm
 *   DWCi_FNTlFormEx                  0x021d5950 arm
 *   DWCi_CELLlForm                   0x021d4e1c arm
 *   DWCi_CMNlFontFlag                0x021bd3cc arm
 *   DWCi_FNTlDrawRect                0x021d5e5c arm
 *   DWCi_FNTlDisp                    0x021d5f28 arm
 *   DWCi_GXlSetWndPlane              0x021d61f4 arm
 *   DWCi_GXlSetWndPosition           0x021d60ec arm
 *   disp                             0x021d1868 arm
 *   DWCi_TSKlForm                    0x021d7680 arm
 *   g_021DAA58                       0x021daa58 data
 *   g_021DE598                       0x021de598 data
 *   g_021DE658                       0x021de658 data
 *   g_021DA9A0                       0x021da9a0 data
 *   g_021DA9A6                       0x021da9a6 data
 *   g_021DA9C8                       0x021da9c8 data
 *   g_021DA9E6                       0x021da9e6 data
 *   g_021DA9E8                       0x021da9e8 data
 *   g_021DA9AC                       0x021da9ac data
 *   taskV                            0x021d1598 arm  ov016
 *   taskMove                         0x021d15f0 arm  ov016
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned char bool;

typedef struct {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    u16 countWait;
    signed char count;
    signed char input;
    u8 type;
    u8 wait;
    u8 dark;
} MemWinT;

extern u16 *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, bool head);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void *DWCi_FNTlFormEx(int lcd, int width, int height, bool head, int *obj, int font);
extern void *DWCi_CELLlForm(int lcd, int num, bool head);
extern unsigned long DWCi_CMNlFontFlag(void);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, u16 *txt);
extern void DWCi_FNTlDisp(void *canvas, int x, int y, void *cell, int prio);
extern void DWCi_GXlSetWndPlane(int lcd, int wnd, int plane, bool effect);
extern void DWCi_GXlSetWndPosition(int lcd, int wnd, void *r);
extern void disp(int y);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskV(void *task);
extern void taskMove(void *task);

extern u8 g_021DAA58[6];
extern void *g_021DE598;
extern MemWinT *g_021DE658;
extern u8 g_021DA9A0[6];
extern u8 g_021DA9A6[6];
extern u8 g_021DA9C8[];
extern u16 g_021DA9E6[];
extern u16 g_021DA9E8[];
extern u16 g_021DA9AC[4];

void func_021D1208(int msg, int type, bool dark, int n, int num)
{
    u8 EFF[6];
    int obj;
    int i;
    volatile int d = dark;

    EFF[0] = g_021DAA58[0];
    EFF[1] = g_021DAA58[1];
    EFF[2] = g_021DAA58[2];
    EFF[3] = g_021DAA58[3];
    EFF[4] = g_021DAA58[4];
    EFF[5] = g_021DAA58[5];

    u16 *ms = DWCi_MSGlGetEx(g_021DE598, msg, n, num);
    g_021DE658 = (MemWinT *)DWCi_HEAPlAllocEx(0x20, 4);
    g_021DE658->type = type;
    g_021DE658->input = -2;
    g_021DE658->dark = d;
    G2x_SetBlendBrightness_(0x04000050, 0x1f, 0);

    g_021DE658->cellWin = DWCi_CEINlSetExCell(0, g_021DA9A0[type], 0);
    DWCi_CELLlSetPosition(g_021DE658->cellWin, -1, 0x100, 0);
    DWCi_CELLlSetPriority(g_021DE658->cellWin, -1, 0);

    for (i = 0; i < g_021DA9A6[type]; i++) {
        g_021DE658->button[i] = DWCi_CEINlSetExCell(i, g_021DA9C8[i + type * 2], i);
        DWCi_CELLlSetPosition(g_021DE658->button[i], -1, 0x100, i);
        DWCi_CELLlSetPriority(g_021DE658->button[i], -1, i);
    }

    g_021DE658->canv = DWCi_FNTlFormEx(0, 0x20, 0xc, 1, &obj, 0);
    g_021DE658->cellChar = DWCi_CELLlForm(0, obj, 0);
    DWCi_FNTlDrawRect(g_021DE658->canv, 0, 0, g_021DA9E6[type * 2], g_021DA9E8[type * 2], 2, DWCi_CMNlFontFlag(), ms);
    DWCi_FNTlDisp(g_021DE658->canv, 0x100, 0, g_021DE658->cellChar, 0);

    DWCi_GXlSetWndPlane(0, 0, 0x1f, 0);
    DWCi_GXlSetWndPlane(0, 1, 0x1f, EFF[g_021DE658->type]);
    DWCi_GXlSetWndPlane(0, 3, 0x1f, 1);
    DWCi_GXlSetWndPosition(0, 1, g_021DA9AC);

    disp(0xc0);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xE000) | 0x6000;

    if (d)
        g_021DE658->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskV, 0, 0x78);
    else
        g_021DE658->task = DWCi_TSKlForm(1, (void (*)(void *, void *))taskMove, 0, 0x78);
}






