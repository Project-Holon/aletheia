/*
 * file:     unit_068989C0.c
 * unit:     yes
 * function: func_068989C0, func_068989CC
 * address:  0x068989C0
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
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D6A0 0x0689D6A0 data a4
 */
#include "../../matched/include/Obj10161.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int w0; u32 w1; u8 pad[0x10]; u32 w6; } D;

extern int BTL_EVENT_GetVar(int k);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(int b);
extern int BTL_SERVER_FLOW_GetTurnCount(int b);
extern int BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(int b, int c);
extern int BTL_SERVER_FLOW_GetPokeParam(int b, int s);
extern int BTL_POKEPARAM_IsFainted(int x);
extern u8 *BTL_SERVER_FLOW_AllocCmdRecord(int b, int n, int k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int n, int v);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg();
extern void BTL_SERVER_FLOW_CommitCmdRecord(int b, void *p);
extern void BTL_EVENT_RemoveFactor(int a);
void *func_068989C0(u32 *p);
void func_068989CC(int a, int b, int c, D *d);
extern char d_0689D6A0[];

/*
 * Follower of the non-C veneer at 0x068989B0; code and pool end at 0x068989CC.
 */
void *func_068989C0(u32 *p)
{
    *p = 1;
    return d_0689D6A0;
}

/*
 * Message pointer y is passed live in r1 to 06898B40, whose fixed veneer
 * targets two-argument BTL_SERVER_FLOW_CommitCmdRecord. Omitting y lost its r0-to-r1 copy.
 */
void func_068989CC(int a, int b, int c, D *d)
{
    if (BTL_EVENT_GetVar(2) == 0x1f && BTL_SERVER_FLOW_CheckShowdownThunk(b) == 0) {
        u8 t = BTL_SERVER_FLOW_GetTurnCount(b);
        if (t >= d->w0) {
            int s = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(b, c);
            u8 k = d->w6;
            if (s != 0x1f && s != k) {
                if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(b, s)) == 0) {
                    u8 *x = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, k);
                    u8 *y;
                    BTL_SERVER_FLOW_InitMsgRecord(x + 4, 2, 0x438);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(x + 4, s);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(x + 4, d->w1);
                    BTL_SERVER_FLOW_CommitCmdRecord(b, x);
                    y = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x27, k);
                    y[4] = k;
                    y[5] = s;
                    ((struct Obj10161 *)y)->f6 = d->w1;
                    BTL_SERVER_FLOW_CommitCmdRecord(b, y);
                }
            }
            BTL_EVENT_RemoveFactor(a);
        }
    }
}
