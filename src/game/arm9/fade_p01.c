/*
 * file:     fade_p01.c
 * unit:     yes
 * function: func_0204E5E8, func_0204E638
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
 *   func_0204E708   0x0204E708  arm
 *   fade_File       0x020A7F8C  data
 *   g_02146A7C      0x02146A7C  data
 *   func_0204E824  0x0204E824  arm
 */
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed int s32;

typedef struct S0204E638 {
    u32 f00;
    u8 pad04[4];
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
} S0204E638;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u32 val, u32 size);
extern void  func_0204E708(void);
extern void func_0204E824(void);
void func_0204E5E8(u32 heap);
void func_0204E638(void);
extern const char fade_File[];
extern S0204E638 *g_02146A7C;


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
void func_0204E5E8(u32 heap)
{
    g_02146A7C = func_02030734((u16)heap, 0x20, 0, fade_File, 50);

    MI_CpuFill8(g_02146A7C, 0, 0x20);
    func_0204E708();
}


void func_0204E638(void)
{
    if (g_02146A7C == 0) {
        return;
    }
    if ((g_02146A7C->f00 & 0xf) == 0) {
        return;
    }
    if (g_02146A7C->f10 != 0) {
        g_02146A7C->f10 = g_02146A7C->f10 - 1;
        return;
    }
    g_02146A7C->f10 = g_02146A7C->f14;
    g_02146A7C->f08 = g_02146A7C->f08 + g_02146A7C->f18;
    if ((g_02146A7C->f08 >= g_02146A7C->f0c && g_02146A7C->f18 > 0) ||
        (g_02146A7C->f08 <= g_02146A7C->f0c && g_02146A7C->f18 < 0)) {
        g_02146A7C->f08 = g_02146A7C->f0c;
    }
    func_0204E824();
    if (g_02146A7C->f08 == g_02146A7C->f0c) {
        g_02146A7C->f00 = 0;
    }
}
