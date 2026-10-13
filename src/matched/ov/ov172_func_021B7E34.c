/*
 * function: func_021B7E34
 * address: 0x021B7E34
 * packet: pkt_ov172_021B7E34
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE00C 0x021BE00C thumb ov172
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   func_021B8050 0x021B8050 thumb ov172
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   GFL_NET_StartByNetType 0x0203D01C arm
 *   func_02179328 0x02179328 thumb ov014
 *   func_021B8130 0x021B8130 thumb ov172
 *   func_021B8614 0x021B8614 thumb ov172
 *   GFL_NET_ConnectMacAddressParent 0x0203CFF0 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021C6ED4 0x021C6ED4 data a4
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021B8154 0x021B8154 thumb ov172
 *   func_021B8448 0x021B8448 thumb ov172
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   func_0200FB24 0x0200FB24 thumb
 */
#include "../include/Obj00289.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags;
extern u16 func_021BE00C(u16 *p);
extern void GFL_NET_SetWaitMode(int a);
extern void func_021B8050(void *a, void *b);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_BeaconScanStart(void);
extern void GFL_NET_StartByNetType(void);
extern void func_02179328(void *v);
extern int func_021B8130(void *a0, u8 *a1);
extern void func_021B8614(int unused, int unused2, void *p);
extern void GFL_NET_ConnectMacAddressParent(void *p);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern u8 d_021C6ED4[];
struct Link;
extern void func_02039C68(struct Link *p, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *p, u32 a, u32 b);
extern void func_021B8154(void *p, char *q);
extern void func_021B8448(void *p, char *q);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern u32 func_0200FB24(void);
void func_021B7E34(void *p, char *q)
{
    u32 h;
    u8 i;
    u8 j;
    func_021BE00C(p);
    switch (((struct Obj00289 *)q)->f8) {
    case 0:
        if (((struct Obj00289 *)q)->f178 == 0)
            break;
        if (((struct Obj00289 *)q)->f178 == 5) {
            GFL_NET_SetWaitMode(0);
            ((struct Obj00289 *)q)->f8 = 5;
            ((struct Obj00289 *)q)->f174 = ((struct Obj00289 *)q)->f178;
        } else {
            ((struct Obj00289 *)q)->f8 = 1;
        }
        break;
    case 1:
        func_021B8050(p, q);
        ((struct Obj00289 *)q)->f8 = 2;
        break;
    case 2:
        if (GFL_NET_GetRunState() != 1)
            break;
        switch (((struct Obj00289 *)q)->f178) {
        case 2:
            GFL_NET_BeaconScanStart();
            ((struct Obj00289 *)q)->f8 = 7;
            break;
        case 3:
            GFL_NET_StartByNetType();
            func_02179328(func_021B8130);
            ((struct Obj00289 *)q)->f8 = 3;
            break;
        case 4:
            if (((struct Obj00289 *)q)->f174 == 2)
                func_021B8614((int)p, (int)q, q + 0x64);
            GFL_NET_ConnectMacAddressParent(q + 0x17c);
            ((struct Obj00289 *)q)->f8 = 3;
            break;
        }
        ((struct Obj00289 *)q)->f174 = ((struct Obj00289 *)q)->f178;
        break;
    case 3:
        if (GFL_NET_HANDLE_CheckNegotiation() == 1)
            ((struct Obj00289 *)q)->f8 = 4;
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        break;
    case 4:
        if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetCurrentHandle()) == 1)
            ((struct Obj00289 *)q)->f8 = 7;
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        break;
    case 5:
        h = (u32)GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_COMMAND_AddCommandTable(0x2000, (u32)d_021C6ED4, 4, (u32)q);
        func_02039C68((struct Link *)h, 8, 0x20);
        ((struct Obj00289 *)q)->f8 = 6;
        break;
    case 6:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x20) == 1)
            ((struct Obj00289 *)q)->f8 = 7;
        break;
    case 7:
        func_021B8154(p, q);
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        if (((struct Obj00289 *)q)->f174 == 2)
            func_021B8448(p, q);
        break;
    case 8:
        GFL_NET_Exit(0);
        ((struct Obj00289 *)q)->f8 = 11;
        break;
    case 11:
        if (GFL_NET_IsSessionNull() != 1)
            break;
        if (((struct Obj00289 *)q)->f178 == 1)
            ((struct Obj00289 *)q)->f8 = 12;
        else
            ((struct Obj00289 *)q)->f8 = 1;
        break;
    case 9:
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20);
        ((struct Obj00289 *)q)->f8 = 10;
        break;
    case 10:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20) == 1) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
            ((struct Obj00289 *)q)->f8 = 12;
        }
        if (func_0200FB24() != 0) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
            ((struct Obj00289 *)q)->f8 = 12;
        }
        break;
    }
    if (((struct Obj00289 *)q)->f3D0 != 0) {
        (((struct Obj00289 *)q)->f3D0)--;
        if (((struct Obj00289 *)q)->f3D0 == 0) {
            for (i = 0; i < 3; i++)
                for (j = 0; j < 6; j++)
                    *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
            ((Flags *)(q + 0x2d))->b1 = 0;
        }
    }
}
