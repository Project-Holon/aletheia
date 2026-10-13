/*
 * function: BTL_SERVER_FLOW_ProcInterruptMove
 * address: 0x021BE550
 * packet: pkt_ov093_021BE550
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMoveInterruptEvent 0x021BEA14 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_GetMoveParam 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   BTL_SERVER_FLOW_PushMoveFailMessage 0x021C0520 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021BEC58 0x021BEC58 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *, int);
extern u32 func_021CC8D8(void *, int);
extern void BTL_SERVER_FLOW_DispatchMoveInterruptEvent(u8 *, u8 *, u8 *, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
struct Out64B4;
struct Unk021D62A8;
extern void BTL_SERVER_FLOW_GetMoveParam(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
extern void BTL_SERVER_FLOW_PushMoveFailMessage(u8 *, u8 *, u16, u32);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *, u16, u32);
extern int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d);
extern void func_021E03D8(u8 *a, int b);
void BTL_SERVER_FLOW_ProcInterruptMove(u8 *p, u8 *b, u16 c, void *unused)
{
    u8 *a;
    u32 lock;
    if ((*(u8 **)(p + 0x4ac))[0] != 0) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4ac))[1]);
        lock = func_021CC8D8(p + 0x1d74, 3720);
        BTL_SERVER_FLOW_DispatchMoveInterruptEvent(p, a, b, c);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 3722);
        BTL_SERVER_FLOW_GetMoveParam(p, c, a, ((struct Obj00003 *)p)->f1AB0);
        func_021CA7F4(p, a, (*(u8 **)(p + 0x4ac))[7], ((struct Obj00003 *)p)->f1AB0, ((struct Obj00003 *)p)->f864);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 15) != 0 && WAZA_TOOL_GetFlag(c, 12) != 0) {
            BTL_SERVER_FLOW_PushMoveFailMessage(p, a, c, 13);
            return;
        }
        func_021E02DC(a, c, func_021D59B4(a, 12));
        func_021BEC58(p, a, c, ((struct Obj00003 *)p)->f864);
        func_021E03D8(a, c);
    }
}
