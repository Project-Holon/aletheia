/*
 * function: DSP_SwitchProcessMemory
 * address:  0x02705A4C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSPi_CommitWram 0x0270541C arm twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct Chan {
    u32 pad[5];
    void *file;
    u16 f18;
    u16 f1a;
    u32 f1c;
    u32 busy[2];
    u32 tabA[8];
    u32 tabB[8];
} Chan;

u32 DSPi_CommitWram(Chan *c, s32 sel, u32 idx, s32 mode);

u32 DSP_SwitchProcessMemory(Chan *c, s32 sel, u32 start, u32 count, s32 mode)
{
    u32 end;
    s32 i;
    u32 *tab;
    start <<= 1;
    if (count < 1) {
        count = 1;
    }
    end = start + count * 2 - 1;
    tab = sel == 1 ? &c->busy[0] : &c->busy[1];
    for (i = start >> 15; i <= (s32)(end >> 15); i++) {
        if (*tab & (1 << i)) {
            if (!DSPi_CommitWram(c, sel, i, mode)) {
                return 0;
            }
        }
    }
    return 1;
}
