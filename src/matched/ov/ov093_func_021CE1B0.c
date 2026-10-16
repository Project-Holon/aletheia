/*
 * function: BTL_CLIENT_StepPlaybackRecordedAction
 * address: 0x021CE1B0
 * packet: pkt_ov093_021CE1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_ResetActionCursor 0x021CE2E8 thumb ov093
 *   BTL_REC_ReadRecord 0x021EE6B8 thumb ov093
 *   BTL_CLIENT_RequestCounterAdvance 0x021D3F54 thumb ov093
 *   BTL_CLIENT_DisableCounter 0x021D3FD0 thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 */
#include "../include/Obj01893.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a : 5; u8 flag : 1; } Flags;
typedef struct { u32 kind : 4; u32 rest : 28; } Command;
extern void BTL_CLIENT_ResetActionCursor(u8 *);
extern u32 *BTL_REC_ReadRecord(void *,u8,u8 *,u8 *);
extern void BTL_CLIENT_RequestCounterAdvance(u8 *p);
extern void BTL_CLIENT_DisableCounter(unsigned char *p);
typedef unsigned short u16;
struct L;
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
struct H;
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);
int BTL_CLIENT_StepPlaybackRecordedAction(u8 *p,int *state)
{
    u8 count;
    u8 flag;
    u32 *data;
    switch (*state) {
    case 0:
        if (((Flags *)(p+0x1b2))->flag) {
            BTL_CLIENT_ResetActionCursor(p);
            return 1;
        }
        data = BTL_REC_ReadRecord(((struct Obj01893 *)p)->f14,p[0x1a6],&count,&flag);
        if (flag) BTL_CLIENT_RequestCounterAdvance(p+0x18);
        *(u32 * *)&((struct Obj01893 *)p)->fD8 = data;
        ((struct Obj01893 *)p)->fDC = count * 4;
        if (((Command *)data)->kind == 8) {
            BTL_CLIENT_DisableCounter(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                BTLV_SCU_InitMessage((struct L *)(p+0x58),1,0xb7);
                BTLV_CORE_BuildAndPrintMessage(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                (*state)++;
            } else {
                BTL_CLIENT_ResetActionCursor(p);
                p[0x1b2] |= 0x10;
                return 1;
            }
        } else if (((Command *)data)->kind == 9) {
            p[0x1b2] |= 0x20;
            BTL_CLIENT_DisableCounter(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                BTLV_SCU_InitMessage((struct L *)(p+0x58),1,0xb8);
                BTLV_CORE_BuildAndPrintMessage(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                *state += 2;
            } else {
                BTL_CLIENT_ResetActionCursor(p);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(((struct Obj01893 *)p)->f54)) {
            BTL_CLIENT_ResetActionCursor(p);
            p[0x1b2] |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(((struct Obj01893 *)p)->f54)) {
            BTL_CLIENT_ResetActionCursor(p);
            return 1;
        }
        break;
    }
    return 0;
}
