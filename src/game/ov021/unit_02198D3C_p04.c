/*
 * file:     unit_02198D3C_p04.c
 * unit:     yes
 * function: func_02198EB0, func_02198EC8, func_02198F20
 * address:  0x02198EB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02198E60  0x02198E60  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_020508EC  0x020508EC  arm
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_020061E4(unsigned int arg);
extern void func_02198E60(void *pipe);
extern void *func_0216D6D4(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D7CC(u32);
void func_02198EB0(void *pipe);
int func_02198EC8(u32 a);
int func_02198F20(u32 a);


/*
 * libmatch places DSPi_WaitForPipe (TwlSDK/libdsp dsp_pipe.o) here, but the
 * call site is func_020061E4, not OS_SleepThread (0x020857B0), and the pool
 * word is the small constant 0x7B7, not DSPiBlockingQueue's absolute address:
 * the overlay stores bss pointers base-relative, so the pool word carries the
 * bss offset.  Reproduced as the literal constant the image holds.  The
 * second call is to the 0xb variant (func_02198E60) of the sync helper.
 */
void func_02198EB0(void *pipe)
{
    func_020061E4(0x7B7);
    func_02198E60(pipe);
}


/*
 * Promoted 2026-10-01: the arm9 leaf func_020508EC is now filed EXACT
 * (src/matched/arm9/func_020508EC.c), which witnesses the call.
 *
 * Addresses are Black-image addresses.
 */
int func_02198EC8(u32 a)
{
    u32 r;
    u16 out;

    func_0216D6D4((void *)a);
    r = func_0216D7A8((void *)a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)a))), (u16)r, &out) == 1) {
            func_0216D674((void *)a, 0);
            func_0216D7CC(a);
            return 1;
        }
    }
    return 0;
}


int func_02198F20(u32 a)
{
    u32 r;
    u16 out;

    func_0216D6D4((void *)a);
    r = func_0216D7A8((void *)a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)a))), (u16)r, &out) == 1) {
            func_0216D7CC(a);
            return 1;
        }
    }
    return 0;
}
