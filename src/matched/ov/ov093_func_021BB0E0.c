/*
 * function: BTL_SERVER_StepRequestPokeReplace
 * address: 0x021BB0E0
 * packet: pkt_ov093_021BB0E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: case 3 falls through to case 4; case 5 polls before dispatching
 * the result field through its nested switch.
 * symbols:
 *   BTL_SERVER_SendCommandData 0x021BB724 thumb ov093
 *   BTL_SERVER_AreRepliesReady 0x021BB798 thumb ov093
 *   BTL_SERVER_ClearReplies 0x021BB7D0 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   BTL_SERVER_SetHandler 0x021BABEC thumb ov093
 *   BTL_SERVER_StepSelectEnding 0x021BB280 thumb ov093
 *   BTL_SERVER_StepRequestPokeChange 0x021BAEF8 thumb ov093
 *   BTL_SERVER_CollectReplies 0x021BB6A8 thumb ov093
 *   BTL_SERVER_SendActionPacket 0x021BB628 thumb ov093
 *   BTL_SERVER_FLOW_ResetInitStateAfterSelect 0x021BBD20 thumb ov093
 *   BTL_SERVER_FLOW_StartAfterPokeSelect 0x021BBD2C thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   BTL_SERVER_GotoSelectCommands 0x021BABF4 thumb ov093
 */
#include "../include/Obj02775.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern void BTL_SERVER_ClearReplies(const u8 *p);
extern int func_021BA618(char *p);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepSelectEnding(u8 *);
extern int BTL_SERVER_StepRequestPokeChange(u8 *, int *);
extern void BTL_SERVER_CollectReplies(u8 *);
extern int BTL_SERVER_SendActionPacket(u8 *, int, int);
extern void BTL_SERVER_FLOW_ResetInitStateAfterSelect(u8 *p);
extern int BTL_SERVER_FLOW_StartAfterPokeSelect(u8 *p, int a);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern void BTL_SERVER_GotoSelectCommands(void *);
int BTL_SERVER_StepRequestPokeReplace(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        BTL_SERVER_SendCommandData(p, 6, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            if (func_021BA618(((struct Obj02775 *)p)->fC)) {
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
            } else {
                BTL_SERVER_CollectReplies(p);
                if (BTL_SERVER_SendActionPacket(p, 3, 0)) (*s)++;
                else *s += 2;
            }
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            (*s)++;
        }
        break;
    case 3:
        BTL_SERVER_ClearReplies(p);
        BTL_SERVER_FLOW_ResetInitStateAfterSelect(((struct Obj02775 *)p)->f44);
        (*s)++;
    case 4: {
        int *q;
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        q[0] = 0;
        q[1] = 0;
        ((struct Obj02775 *)p)->f48 = BTL_SERVER_FLOW_StartAfterPokeSelect(((struct Obj02775 *)p)->f44, (int)(p + 0xb4));
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        BTL_SERVER_SendCommandData(p, 8, (int)(q + 2), q[0]);
        (*s)++;
        break;
    }
    case 5:
        if (BTL_SERVER_AreRepliesReady(p)) {
            BTL_SERVER_ClearReplies(p);
            switch (((struct Obj02775 *)p)->f48) {
            case 1: *s = 0; break;
            case 3: *s = 4; break;
            case 2: BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepRequestPokeChange); break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj02775 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj02775 *)p)->f44)));
                BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepSelectEnding);
                break;
            case 5: return 1;
            case 0:
            default: BTL_SERVER_GotoSelectCommands(p); break;
            }
        }
        break;
    }
    return 0;
}
