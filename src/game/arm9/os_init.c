/*
 * file:     os_init.c
 * unit:     yes
 * function: func_02086348, OS_Init, func_02086374
 * address:  0x02086348
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      OSi_WaitVCount0 (libos.TWL.HYB.a os_init.o)
 * asm:      no-prologue code on r12 that writes the register base itself (0x04000000, bit 0 clear) to IME to disable interrupts; the DWARF subprogram has no DW_TAG_variable children.
 *   (none)
 * blocker:  02086374 -- a tail call through a pool word
 *           (docs/idioms/tail-call-is-a-pool-word-and-bx.md), and that pool
 *           word is the only reference to 0x02086374 anywhere in the image,
 *           so the `literal` class discards its only witness and no cut
 *           helps: the pool is inside this function's own 12-byte extent.
 *           func_02086374 is itself MATCH-capped (eleven callees each called
 *           from exactly one site), so the `matched` class cannot reach it
 *           either.  Every concrete byte is right: `ldr ip, [pc] ; bx ip`
 *           plus the pool word, 8 bytes of code.
 * A one-line forwarder to the driver at 0x02086374; mwccarm emits exactly
 * this shape for an ARM tail call, which is why the eight bytes are
 * reproducible at all.
 *
 * symbols:
 *   PXI_Init  0x02088498  arm
 *   func_020863E0  0x020863E0  arm
 *   func_02084B90  0x02084B90  arm
 *   func_020864FC  0x020864FC  arm
 *   func_0208475C  0x0208475C  arm
 *   func_020849F4  0x020849F4  arm
 *   func_02086DD8  0x02086DD8  arm
 *   func_0208361C  0x0208361C  arm
 *   func_02087578  0x02087578  arm
 *   func_02087EA8  0x02087EA8  arm
 *   OS_InitThread  0x02085264  arm
 *   func_02087B78  0x02087B78  arm
 *   GFL_USE_CtrdgDummyInit  0x02005438  thumb
 *   func_02075CAC  0x02075CAC  arm
 *   func_02082198  0x02082198  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_0208C960  0x0208C960  arm
 *   func_0208B8B0  0x0208B8B0  arm
 *   func_020883D4  0x020883D4  arm
 */
extern void PXI_Init(void);
extern void func_020863E0(void);
extern void func_02084B90(void);
extern void func_020864FC(void);
extern void func_0208475C(void);
extern void func_020849F4(void);
extern void func_02086DD8(void);
extern void func_0208361C(void);
extern void func_02087578(void);
extern void func_02087EA8(void);
extern void OS_InitThread(void);
extern void func_02087B78(void);
extern void GFL_USE_CtrdgDummyInit(void);
extern void func_02075CAC(void);
extern void func_02082198(void);
extern int  OS_IsRunOnTwl(void);
extern void func_0208C960(void);
extern void func_0208B8B0(void);
extern void func_020883D4(void);
asm void func_02086348(void);
void OS_Init(void);
void func_02086374(void);

/* hand-written in the original: no-prologue code on r12 that stores its own register base to IME */
asm void func_02086348(void)
{
    mov r12, #0x4000000
    ldr r1, [r12, #0x208]
    str r12, [r12, #0x208]
@_wait:
    ldrh r0, [r12, #6]
    cmp r0, #0
    bne @_wait
    str r1, [r12, #0x208]
    bx lr
}


void OS_Init(void)
{
    func_02086374();
}


void func_02086374(void)
{
    PXI_Init();
    func_020863E0();
    func_02084B90();
    func_020864FC();
    func_0208475C();
    func_020849F4();
    func_02086DD8();
    func_0208361C();
    func_02087578();
    func_02087EA8();
    OS_InitThread();
    func_02087B78();
    GFL_USE_CtrdgDummyInit();
    func_02075CAC();
    func_02082198();
    if (OS_IsRunOnTwl() == 1)
        func_0208C960();
    func_0208B8B0();
    func_02086348();
    if (OS_IsRunOnTwl() != 1)
        return;
    func_020883D4();
}
