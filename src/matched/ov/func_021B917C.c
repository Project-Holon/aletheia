/*
 * function: BTL_MAIN_JudgeResultThunk
 * address:  0x021B917C
 * packet:   pkt_021B917C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_JudgeResult   0x021BA54C  thumb ov093
 *   BTL_MAIN_JudgeResultThunk   0x021B917C  thumb ov093
 *
 * tail-call thunk to BTL_MAIN_JudgeResult
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_MAIN_JudgeResult(char *p);

int BTL_MAIN_JudgeResultThunk(char *p)
{
    return BTL_MAIN_JudgeResult(p);
}
