/*
 * file:     unit_02164D64_p01.c
 * unit:     yes
 * function: func_02164D64, func_02164D74, func_02164EE0
 * address:  0x02164D64
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WCM_InitEx                   0x02164D74  arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MI_CpuFill8          0x02082BCC arm
 *   func_02165B68        0x02165B68 arm ov009
 *   func_02164F38        0x02164F38 arm ov009
 *   func_021658F8        0x021658F8 arm ov009
 *   func_02166304        0x02166304 arm ov009
 *   func_02087058        0x02087058 arm
 *   func_02086FE8        0x02086FE8 arm
 *   func_02087244        0x02087244 arm
 *   func_02087208        0x02087208 arm
 *   func_02087254        0x02087254 arm
 *   WCMi_OverridedDeviceId 0x021AA7D4 data
 *   wcmw                 0x021AA7D8 data
 *   g_021AA7D4                      0x021AA7D4 data
 */
typedef struct WCMWork {
    unsigned char pad0[0x1294];
    unsigned char alarm[0x12D8 - 0x1294];
    unsigned short maxScanTime;
    unsigned short wmState;
    unsigned char resetting0;
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

extern void WCM_InitEx(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char func_02165B68(void);
extern long func_02164F38(long *size, unsigned char deviceId);
extern void func_021658F8(void);
extern void func_02166304(void);
extern long func_02087058(void);
extern void func_02086FE8(void);
extern long func_02087244(void);
extern void func_02087208(void);
extern void func_02087254(void *alarm);
asm void CRYPTOi__BN_lshift1(void);
long func_02164D74(void *buf, long len, unsigned char deviceId);
long WCM_Finish(void);
extern char g_021AA7D4[];

asm void CRYPTOi__BN_lshift1(void)
{
	ldr ip, =WCM_InitEx
	mov r2, #1
	bx ip
}


static unsigned char WCMi_OverridedDeviceId = 0;

static WCMWork *wcmw = 0;


/*
 * sdk:      WCM_InitEx (libwcm.TWL.HYB.a system.o)
 *
 * lane04 (2026-10-01): EXACT. WCMi_OverridedDeviceId and wcmw are two
 * separate statics in system.o's .bss (0x021AA7D4 / +4), not one struct:
 * defined here as zero-initialised file statics (layout matches the vendor,
 * .bss anchored on WCMi_OverridedDeviceId), the `p` stand-in local is gone,
 * and the pool load / expectLen spill schedule falls out as in the image.
 *
 * near miss (history): 364 B both; only the +0x18..+0x28 schedule differs (original loads
 * the 0x021AA7D4 pool word before `mov r1,#0`, ours after).  wave7: sdkobj
 * confirms the object is Metrowerks 4.0.0.1024 -> dsi/1.1p1, so this residue is
 * a shape this front end has not been given (the DWARF locals are exactly
 * expectLen [fb+0], e r5, matching the source); wave7 re-measured declaration
 * swap, `if (wcmw)` and the guard-before-init forms, all still 18.
 *
 * lane T5 (2026-09-30).  HEADER REPAIR: the `symbols:` block used bare hex
 * addresses (`OS_DisableInterrupts 02087988 arm`), which SYMBOL_RE rejects, so the
 * whole block was dropped (`symbols_lines` empty) and the one ABS32 stayed
 * wildcarded.  With `0x` addresses the sites go 18 of 18 resolved, the ABS32
 * g_021AA7D4 resolving as sole-ref - the row's ceiling is now EXACT rather than
 * MATCH.  The instruction residue is unchanged at 18 concrete bytes.
 * Pin sweep (all 9 dsi compilers x 4 flag sets): 1.1p1 -O4,p is the unique best.
 * Residue is a six-instruction schedule rotation at +0018..+0028, same 364 bytes:
 *   +0018  image `ldr sb, [pc, #0x148]`  | ours `mov r1, #0`
 *   +0028  image `str r1, [sp]`          | ours `mov r5, r0`
 *   i.e. the image loads the 0x021AA7D4 pool word first and sinks the spill of
 *   expectLen below the wcmw load, this build materialises the zero and spills it
 *   immediately.  Measured worse: `long expectLen = 0;` as a declaration
 *   initialiser (396/345), `expectLen` before the OS_DisableInterrupts call (396),
 *   both as declaration initialisers (400).  lane U22 adds nine more shapes, all
 *   at exactly 18: `expectLen = 0;` sunk to just before MI_CpuFill8 (70), after
 *   the first wcmw guard (28), a comma expression `e = ..., expectLen = 0;`,
 *   swapped local declaration order, `if (wcmw)` without `!= 0`,
 *   both locals as declaration initialisers, a volatile-cast read of `wcmw`,
 *   `expectLen` zeroed as `unsigned long`, and `expectLen = 0;` moved after the
 *   two pointer guards.  The pool load and the spill are one independent
 *   instruction pair and this front end will not rotate them into the image's
 * order from any statement position.
 *
 * wave8: tried the const-pointer hoist lever from
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md
 * on the field read (`const WCMSysState *` local over &g_021AA7D4, and an
 * inline `((const WCMSysState *)&g_021AA7D4)->wcmw` cast at the guard); both
 * still 18 bytes, schedule unchanged.  The lever needs a pointer parameter;
 * it does not reach a load through a global object.  Also tried: caching the
 * read in a `WCMWork *wcmw` local before and after `expectLen = 0`, and a
 * non-const named `WCMSysState *p = &g_021AA7D4` with the guard written
 * `wcmw`; all three still emit exactly `mov r1,#0; ldr sb; str r1,[sp];
 * ldr r2,[sb,#4]; mov r5,r0` (18 concrete bytes), i.e. the front end never
 * hoists the address load above the zero materialisation.  blocker: the
 * `ldr sb` address load and the `str r1,[sp]` expectLen spill will not swap.
 */
long func_02164D74(void *buf, long len, unsigned char deviceId)
{
    long expectLen;
    unsigned long e;

    e = OS_DisableInterrupts();
    expectLen = 0;
    if (wcmw != 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (buf == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (((unsigned long)buf & 0x1f) != 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    MI_CpuFill8(buf, 0, len);
    if (deviceId == 0) {
        deviceId = WCMi_OverridedDeviceId;
        if (deviceId == 0) {
            deviceId = func_02165B68();
        }
    }
    if (func_02164F38(&expectLen, deviceId) == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (len < expectLen) {
        OS_RestoreInterrupts(e);
        return 6;
    }
    wcmw = buf;
    ((WCMWork *)buf)->phase = 1;
    wcmw->wmState = 0;
    wcmw->maxScanTime = 0;
    wcmw->resetting0 = 0;
    wcmw->resetting = 0;
    wcmw->deviceId = deviceId;
    func_021658F8();
    func_02166304();
    if (func_02087058() == 0) {
        func_02086FE8();
    }
    if (func_02087244() == 0) {
        func_02087208();
    }
    func_02087254(wcmw->alarm);
    OS_RestoreInterrupts(e);
    return 0;
}


long WCM_Finish(void)
{
    unsigned long e = OS_DisableInterrupts();
    char *w = *(char **)(g_021AA7D4 + 4);

    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (*(unsigned char *)(w + 0x1000 + 0x2de) != 1) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    *(void **)(g_021AA7D4 + 4) = 0;
    OS_RestoreInterrupts(e);
    return 0;
}
