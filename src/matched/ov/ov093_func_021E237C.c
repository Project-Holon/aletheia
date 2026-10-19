/*
 * function: HAND_WAZA_UproarStart
 * address: 0x021E237C
 * packet: pkt_ov093_021E237C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Word return from BTL_SICKCONT_MakeKind2 reserves the unused aggregate slot;
 * u8 c schedules its stack reload after the zero store at 021E23CE.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SICKCONT_MakeKind2 0x021E896C thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke 0x021C7D00 thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 */
#include "../include/Obj05222.h"
#include "../include/Obj13508.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
struct QQ;
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern Word BTL_SICKCONT_MakeKind2(int, int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *p, int b);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
void HAND_WAZA_UproarStart(void *a, void *b, u8 c, u8 *d)
{
    u8 *p;
    u8 *buf;
    u32 flags;
    unsigned i;
    u8 *entry;
    if (c != BTL_EVENT_GetVar(3)) return;
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(b, c), 25) != 0) return;
    if (((struct Obj13508 *)d)->f18 != 0) return;
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 12, c);
    ((struct Obj05222 *)p)->f4 = 25;
    *(Word *)(p + 8) = BTL_SICKCONT_MakeKind2(3, BTL_EVENT_GetFactorKey(a));
    p[12] = 0;
    p[15] = c;
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 703);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    flags = BTL_SERVER_FLOW_GetFrontPosOfPoke(b, c);
    buf = BTL_SERVER_FLOW_GetScratchBuffer(b, 7);
    buf[0] = BTL_SERVER_FLOW_CollectAlivePokeIds(b, (u16)(flags | 0x800), buf + 1);
    for (i = 0; i < buf[0]; i++) {
        entry = buf + i;
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(b, entry[1]), 2) != 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 11, c);
            ((struct Obj05222 *)p)->f4 = 2;
            p[20] = 1;
            p[8] = entry[1];
            BTL_SERVER_FLOW_InitMsgRecord(p + 24, 2, 706);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 24), entry[1]);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
    ((struct Obj13508 *)d)->f18 = 1;
}
