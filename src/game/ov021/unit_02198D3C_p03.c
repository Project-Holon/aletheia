/*
 * file:     unit_02198D3C_p03.c
 * unit:     yes
 * function: func_02198E60, func_02198E7C, func_02198E98
 * address:  0x02198E60
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02198E44  0x02198E44  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0216D674(void *p, u16 v);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern u32 func_0216D7CC(u32);
extern void func_020061E4(unsigned int arg);
extern void func_02198E44(void *pipe);
int func_02198E60(u32 a, u32 b, u32 c, u32 d);
int func_02198E7C(u32 a, u32 b, u32 c, u32 d);
void func_02198E98(void *pipe);


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02198E60(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 11);
func_0216D7CC(a);
return 0;
}


int func_02198E7C(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 12);
func_0216D7CC(a);
return 0;
}


/*
 * libmatch places DSPi_WaitForPipe (TwlSDK/libdsp dsp_pipe.o) here, but the
 * call site is func_020061E4, not OS_SleepThread (0x020857B0), and the pool
 * word is the small constant 0x7B7, not DSPiBlockingQueue's absolute address:
 * the overlay stores bss pointers base-relative, so the pool word carries the
 * bss offset.  Reproduced as the literal constant the image holds.
 */
void func_02198E98(void *pipe)
{
    func_020061E4(0x7B7);
    func_02198E44(pipe);
}
