/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36E8, func_021F3724, func_021F3768
 * address:  0x021F36C0
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_0200B3A8  0x0200B3A8  thumb
 *   d_021F3840     0x021F3840  data ov037 a1
 *   d_021F3834     0x021F3834  data a1
 */
#include "unit_021F36C0_types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern void *func_020127A4(struct GameData *gameData);
extern void *func_0200B3A4(struct GimmickWork *gimmick, u32 gimmickId);
extern u16 *func_0200B3A8(struct GimmickWork *gimmick, u32 gimmickId);
void func_021F36C0(unsigned int gameSystem, int setFirst, int setSecond);
void func_021F36E8(struct GameSystem *gameSystem, int enable);
void func_021F3724(unsigned int gameSystem, int buttonMask);
void func_021F3768(unsigned int gameSystem, unsigned short **foundVars);

/* Per switch: the two plates it lights (-1 for none). Per door: the two plates that open it. */
extern signed char d_021F3840[][2];
extern unsigned char d_021F3834[][2];


/* Marks the first and second flag of gimmick 39 as set. */
void func_021F36C0(unsigned int gameSystem, int setFirst, int setSecond)
{
    Gimmick39Work *work = func_0200B3A4(func_02012EC4(func_020120F4((const struct GameSystem *)gameSystem)), 2);

    if (setFirst)
        work->firstFlag = 1;
    if (setSecond)
        work->secondFlag = 1;
}

/* Sets the flag of gimmick 40 and its byte mirror. */
void func_021F36E8(struct GameSystem *gameSystem, int enable)
{
    struct GameData *gameData;
    Gimmick40Work *work;
    gameData = func_020120F4(gameSystem);
    work = func_0200B3A4(func_02012EC4(gameData), 3);
    func_020127A4(gameData);
    if (enable) work->enabled = 1;
    else work->enabled = 0;
    if (work->enabled) work->enabledByte = 1;
    else work->enabledByte = 0;
}


/* Sets the three flags of gimmick 42 from the low three bits of the mask. */
void func_021F3724(unsigned int gameSystem, int buttonMask)
{
    Gimmick42Work *work = func_0200B3A4(func_02012EC4(func_020120F4((const struct GameSystem *)gameSystem)), 4);
    unsigned char i;

    for (i = 0; i < 3; i++)
        work->flag[i] = 0;
    if (buttonMask & 1)
        work->flag[0] = 1;
    if ((buttonMask >> 1) & 1)
        work->flag[1] = 1;
    if ((buttonMask >> 2) & 1)
        work->flag[2] = 1;
}


/*
 * Rebuilds the state of gimmick 38 from its saved progress: every found switch
 * sets its script variable and lights its plates, and every door whose two
 * plates are lit opens.  The last door is always open.
 */
void func_021F3768(unsigned int gameSystem, unsigned short **foundVars)
{
    struct GimmickWork *gimmickSave = func_02012EC4(func_020120F4((const struct GameSystem *)gameSystem));
    Gimmick38Work *work = func_0200B3A4(gimmickSave, 6);
    u16 *progress = func_0200B3A8(gimmickSave, 6);
    int switchIdx;
    int linkIdx;
    int plateIdx;

    for (switchIdx = 0; switchIdx < 8; switchIdx++) {
        if (progress[switchIdx] != 0) {
            work->switchFound[switchIdx] = 1;
            *foundVars[switchIdx] = 1;
            for (linkIdx = 0; linkIdx < 2; linkIdx++) {
                plateIdx = d_021F3840[switchIdx][linkIdx];
                if (plateIdx != -1)
                    work->platePressed[plateIdx] = 1;
            }
        }
    }
    for (switchIdx = 0; switchIdx < 6; switchIdx++) {
        for (linkIdx = 0; linkIdx < 2; linkIdx++) {
            if (work->platePressed[d_021F3834[switchIdx][linkIdx]] == 0)
                break;
        }
        if (linkIdx == 2)
            work->doorOpen[switchIdx] = 1;
    }
    work->doorOpen[6] = 1;
}
