/*
 * file:     unit_068987A8.c
 * unit:     yes
 * function: func_068987A8, func_068987B4
 * address:  0x068987A8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D6A8 0x0689D6A8 data a4
 */
#include "../../matched/include/Obj03722.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern int BTL_SERVER_FLOW_GetPokeViewPos(void *, u32);
extern void *BTL_SERVER_FLOW_GetPokeParam(void *, int);
extern int BTL_POKEPARAM_IsHpFull(void *);
extern int func_021D62A8(void *);
extern u8 *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern int func_021D59B4(void *, int);
extern void BTL_EVENT_RemoveFactor(void *);
void *func_068987A8(unsigned int *state);
void func_068987B4(void *a, void *b, u8 c);
extern unsigned char d_0689D6A8[];

/*
 * extent: 12-byte store-and-return follower after non-C veneer 06898798.
 */
void *func_068987A8(unsigned int *state)
{
    *state = 2;
    return d_0689D6A8;
}

/*
 * lever: u8 spilled third parameter keeps its reload after the halfword store.
 * audit: permuter only narrowed byte-valued c; no address/index, return or volatile mutation.
 * budget: 4 iterations, first nonshrinker r2, streak 3; extraction/scheduling variants 2/2.
 * checks: 1 veneer targets and matched prototypes; 2 ov095 98328 and ov093 E8190 twins; 3 u8 flag unchanged, const b CCERR (2/2); 4 inline/store/enum idioms; 5 refreshed directory and twins.
 * permuter: once budget 300 types, EXACT at candidate 157; u8 c adopted after behavior audit.
 */
void func_068987B4(void *a, void *b, u8 c)
{
    u8 slot;
    void *m;
    int flag;
    u8 *p;
    int value;
    slot = (u8)BTL_EVENT_GetVar(2);
    if (c == BTL_SERVER_FLOW_GetPokeViewPos(b, slot)) {
        m = BTL_SERVER_FLOW_GetPokeParam(b, slot);
        flag = 0;
        if (BTL_POKEPARAM_IsHpFull(m) == 0)
            flag = 1;
        if (func_021D62A8(m) != 0)
            flag = 1;
        if (flag != 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x37, slot);
            ((struct Obj03722 *)p)->f4 = 0x27f;
            p[6] = c;
            p[7] = 6;
            BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x2b9);
            BTL_SERVER_FLOW_AppendMsgRecordArg(p + 12, slot);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            if (BTL_POKEPARAM_IsHpFull(m) == 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord(b, 5, slot);
                p[6] = slot;
                value = func_021D59B4(m, 14);
                ((struct Obj03722 *)p)->f4 = value - func_021D59B4(m, 13);
                BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            }
            if (func_021D62A8(m) != 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord(b, 11, slot);
                p[20] = 1;
                p[8] = slot;
                *(int *)(p + 4) = 36;
                BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            }
        }
        BTL_EVENT_RemoveFactor(a);
    }
}
