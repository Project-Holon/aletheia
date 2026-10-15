/*
 * file:     fade.c
 * unit:     yes
 * function: FADE_Create, FADE_Update, FADE_GetSpeed, FADE_SetSpeed, FADE_ResetSpeed, FADE_Start, FADE_IsActive, FADE_ApplyBrightness
 * address:  0x0204E5E8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_0209C0A4   0x0209C0A4  arm
 *   GXx_SetMasterBrightness_   0x0207D534  arm
 *   fade_File       0x020A7F8C  data
 *   g_02146A7C      0x02146A7C  data
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Fade {
    u32 flags;    /* 0x00 */
    s32 start;    /* 0x04 */
    s32 cur;      /* 0x08 */
    s32 end;      /* 0x0c */
    s32 wait;     /* 0x10 */
    s32 interval; /* 0x14 */
    s32 step;     /* 0x18 */
    s32 speed;    /* 0x1c */
} Fade;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u32 val, u32 size);
extern s32   func_0209C0A4(s32 a, s32 b);
extern void  GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
void FADE_Create(u32 heap);
void FADE_Update(void);
s32 FADE_GetSpeed(void);
void FADE_SetSpeed(s32 a);
void FADE_ResetSpeed(void);
void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int FADE_IsActive(void);
void FADE_ApplyBrightness(void);
extern const char fade_File[];
extern Fade *g_02146A7C;

/*
 * fade.c: allocate the 0x20-byte singleton on the caller's heap, publish it at
 * 0x02146A7C, clear it, then hand it to the fade initialiser.
 *
 * The heap id is the u16 parameter (the `lsl #16`/`lsr #16` pair at the top of
 * the function is the zero-extension of a `unsigned short` argument), and it
 * is forwarded to the allocator as its first argument, so the allocator takes
 * (heap, size, align, file, line) exactly as func_0204E8C0's does.  The
 * allocator's result stays in r0 across the store to the global, so the clear
 * call's first argument is that same value, not a fresh load of the global.
 */
void FADE_Create(u32 heap)
{
    g_02146A7C = func_02030734((u16)heap, 0x20, 0, fade_File, 50);

    MI_CpuFill8(g_02146A7C, 0, 0x20);
    FADE_ResetSpeed();
}

void FADE_Update(void)
{
    if (g_02146A7C == 0) {
        return;
    }
    if ((g_02146A7C->flags & 0xf) == 0) {
        return;
    }
    if (g_02146A7C->wait != 0) {
        g_02146A7C->wait = g_02146A7C->wait - 1;
        return;
    }
    g_02146A7C->wait = g_02146A7C->interval;
    g_02146A7C->cur = g_02146A7C->cur + g_02146A7C->step;
    if ((g_02146A7C->cur >= g_02146A7C->end && g_02146A7C->step > 0) ||
        (g_02146A7C->cur <= g_02146A7C->end && g_02146A7C->step < 0)) {
        g_02146A7C->cur = g_02146A7C->end;
    }
    FADE_ApplyBrightness();
    if (g_02146A7C->cur == g_02146A7C->end) {
        g_02146A7C->flags = 0;
    }
}

s32 FADE_GetSpeed(void)
{
    return g_02146A7C->speed;
}

/*
 * Setter for +0x1c of the singleton reached through the pointer at
 * 0x02146A7C.  Same object as src/matched/unit_0204E720.c.
 */
void FADE_SetSpeed(s32 a)
{
    g_02146A7C->speed = a;
}

/*
 * Arms +0x1c of the singleton reached through the pointer at 0x02146A7C:
 * the same field FADE_SetSpeed sets from an argument, here forced to 1.
 * Same object as src/matched/unit_0204E720.c.
 */
void FADE_ResetSpeed(void)
{
    g_02146A7C->speed = 1;
}

/*
 * Set up the singleton at 0x02146A7C for a new run.  The object is reached
 * through a pointer variable, so every store to a field is followed by a
 * fresh load of the pointer: the compiler cannot prove a store through it
 * does not overwrite the pointer itself.  Where two fields are read and one
 * written (the +0x18 * +0x1c product) one load of the pointer serves all
 * three accesses.
 *
 * The sign of the fourth argument is tested once, on the `movs` that parks
 * it in r4, and the `rsb`/`cmp`/`movge` triple inside the negative arm is
 * an absolute value written in the source: the compiler does not propagate
 * the branch condition into it.
 */
void FADE_Start(u32 a, s32 b, s32 c, s32 d)
{
    g_02146A7C->flags = a;
    g_02146A7C->start = b;
    g_02146A7C->end = c;

    if (d < 0) {
        g_02146A7C->step = (d < 0 ? -d : d) + 1;
        g_02146A7C->wait = 0;
        g_02146A7C->interval = 0;
    } else {
        g_02146A7C->step = 1;
        g_02146A7C->wait = d;
        g_02146A7C->interval = d;
    }

    g_02146A7C->step = g_02146A7C->step * g_02146A7C->speed;

    if (d > 0) {
        Fade *p = g_02146A7C;

        p->wait = func_0209C0A4(p->wait, p->speed);
        g_02146A7C->interval = d;
    }

    if (g_02146A7C->start > g_02146A7C->end)
        g_02146A7C->step = g_02146A7C->step * 0xffffffff;

    g_02146A7C->cur = g_02146A7C->start;

    FADE_ApplyBrightness();
}

int FADE_IsActive(void)
{
    return g_02146A7C->flags != 0;
}

/*
 * Push the current fade level at +0x08 of the singleton out to whichever of
 * the four master-brightness slots the low nibble of +0x00 selects: bit 0
 * and bit 1 darken the main and sub engine (the level is negated), bits 2
 * and 3 brighten them (it is not).  The two register addresses 0x0400006c
 * and 0x0400106c are MASTER_BRIGHT for the two engines and are the
 * function's only two pool words besides the singleton pointer.
 *
 * The pointer and the flag word are re-read from scratch in front of every
 * one of the four tests, because GXx_SetMasterBrightness_ is opaque and may write
 * either of them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FADE_ApplyBrightness.c \
 *       --func FADE_ApplyBrightness --addr 0x0204E824 --cc 1.1p1 --arm
 */
void FADE_ApplyBrightness(void)
{
    if (g_02146A7C->flags & 1)
        GXx_SetMasterBrightness_((void *)0x0400006c, -g_02146A7C->cur);

    if (g_02146A7C->flags & 2)
        GXx_SetMasterBrightness_((void *)0x0400106c, -g_02146A7C->cur);

    if (g_02146A7C->flags & 4)
        GXx_SetMasterBrightness_((void *)0x0400006c, g_02146A7C->cur);

    if (g_02146A7C->flags & 8)
        GXx_SetMasterBrightness_((void *)0x0400106c, g_02146A7C->cur);
}