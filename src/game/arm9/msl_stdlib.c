/*
 * file:     msl_stdlib.c
 * unit:     yes
 * function: qsort, rand, srand, MSL_C_LIB_StrReadProc, MSL_C_LIB_CallExitHook, MSL_C_LIB_DefaultExitHook
 * address:  0x0209455C
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 *   MslRandSeed  0x020A8A78  data
 *   gMslExitHook  0x02153FB0  data
 */
#include "msl_crt_shared_types.h"
#include "msl_stdlib.h"

#define table_ptr(i) (((char *)table_base) + (member_size * ((i) - 1)))

#define swap(dst, src, cnt)                          \
    do {                                             \
        size_t n = (cnt);                            \
        unsigned char *p = (unsigned char *)(src);   \
        unsigned char *q = (unsigned char *)(dst);   \
        if (n) do {                                  \
            unsigned char a = *p;                    \
            unsigned char b = *q;                    \
            *q++ = a;                                \
            *p++ = b;                                \
        } while (--n);                               \
    } while (0)

typedef int (*_compare_function)(const void *, const void *);

typedef void (*MslExitHook)(u32, u32, u32);

void qsort(void *table_base, size_t num_members, size_t member_size, _compare_function compare_members);

u32 rand(void);

void srand(u32 v);

void MSL_C_LIB_CallExitHook(u32 a, u32 b, u32 c);

void MSL_C_LIB_DefaultExitHook(void);

extern u32 MslRandSeed;

extern MslExitHook gMslExitHook;

/*
 * note:     MSL stdlib qsort.c `qsort` (heapsort), 312 bytes, the real open
 *           code of worklist row pkt_02094534 (0x02094534..0x0209455C is the
 *           tail of sprintf, already EXACT as src/matched/sprintf.c).
 *           disasm.py has NO label at 0x0209455C (the listing folds
 *           0x02094534..0x02094750 into one block), so the worklist counts
 *           these 312 bytes as data-adjacent extent, not code: integrator,
 *           seed 0x0209455C in layout/function_starts.txt.  Levers: the
 *           swap macro's count is assigned before its two pointers (sets
 *           the mov r2 / ldr r4 / ldr r3 order) and the bytes are unsigned
 *           char (ldrb, MSL is char-unsigned).  Verified with
 *             python3 tools/match.py one --src src/matched/qsort.c \
 *                 --func qsort --addr 0x0209455C --arm
 */
void qsort(void *table_base, size_t num_members, size_t member_size,
                   _compare_function compare_members)
{
    size_t l, r, j;
    char *lp;
    char *rp;
    char *ip;
    char *jp;
    char *kp;

    if (num_members < 2)
        return;

    r = num_members;
    l = (r / 2) + 1;

    lp = table_ptr(l);
    rp = table_ptr(r);

    for (;;) {
        if (l > 1) {
            l--;
            lp -= member_size;
        } else {
            swap(lp, rp, member_size);

            if (--r == 1)
                return;

            rp -= member_size;
        }

        j = l;

        jp = table_ptr(j);

        while (j * 2 <= r) {
            j *= 2;

            ip = jp;
            jp = table_ptr(j);

            if (j < r) {
                kp = jp + member_size;

                if (compare_members(jp, kp) < 0) {
                    j++;
                    jp = kp;
                }
            }

            if (compare_members(ip, jp) < 0)
                swap(ip, jp, member_size);
            else
                break;
        }
    }
}

u32 rand(void)
{
    MslRandSeed = MslRandSeed * 0x41C64E6Du + 0x3039u;
    return (MslRandSeed >> 16) & 0x7FFFu;
}

void srand(u32 v)
{
    MslRandSeed = v;
}

int MSL_C_LIB_StrReadProc(MslStringScan *state, u32 ch, u32 mode)
{
    switch (mode) {
    case 0: {
        const u8 *q = (const u8 *)state->cur;
        u8 c = *q;

        if (c == 0) {
            state->eof = 1;
            return -1;
        }
        state->cur = (const char *)(q + 1);
        return c;
    }
    case 1:
        if (state->eof == 0)
            state->cur = state->cur - 1;
        else
            state->eof = 0;
        return (int)ch;
    case 2:
        return (int)state->eof;
    default:
        return 0;
    }
}

/*
 * Calls the hook stored at 0x02153FB0 when it is set, otherwise falls through
 * to the default handler at 0x02094778.
 *
 * The hook is taken as a three-argument pointer because that is the only thing
 * that reproduces the original's `ldr r3` / `blx r3`: with a zero- or
 * one-argument callee the compiler puts the target in r0 or r1 and the head of
 * the function shifts.  The arguments are passed straight through, so nothing
 * in the bytes fixes their values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_CallExitHook.c \
 *       --func MSL_C_LIB_CallExitHook --addr 0x02094750 --cc 1.1p1 --arm
 */
void MSL_C_LIB_CallExitHook(u32 a, u32 b, u32 c)
{
    if (gMslExitHook != 0) {
        gMslExitHook(a, b, c);
    } else {
        MSL_C_LIB_DefaultExitHook();
    }
}

void MSL_C_LIB_DefaultExitHook(void){ }
