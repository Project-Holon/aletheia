/*
 * function: DWCi_MOV_WH_StateOutStartChildMP
 * address:  0x02178B98
 * packet:   pkt_ov014_02178B98
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   GFL_NET_GetGameKind  0x0203D5D4  arm
 *   WM_StartDataSharing  0x0209004C  arm
 */
#include "../include/Obj12474.h"
#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;
void func_02178138(int a);
void func_0217814C(int a);
int func_02179498(void);
u32 GFL_NET_GetChildSendSize(void);
u32 GFL_NET_GetMaxConnectNum(void);
u32 GFL_NET_GetGameKind(void);
int WM_StartDataSharing(void *p, int a, u32 mask, u32 b, int c);

void DWCi_MOV_WH_StateOutStartChildMP(u8 *m)
{
    u32 v = ((struct Obj12474 *)m)->f2;
    u32 mask;
    u32 who;
    int c;

    if (v != 0) {
        if (v == 0xF || v == 9 || v == 0xD)
            return;
        func_0217814C(v);
        func_02178138(9);
        return;
    }
    switch (((struct Obj12474 *)m)->f4) {
    case 0xA:
        if (*(u32 *)(((u8 *)g_021797A8) + 0x1E74) == 5) {
            int r;
            int n;

            who = GFL_NET_GetChildSendSize();
            n = GFL_NET_GetMaxConnectNum() - 1;
            mask = (u16)((1 << (n + 1)) - 1);
            c = 1;
            if (GFL_NET_GetGameKind() == 2)
                c = 0;
            r = WM_StartDataSharing(((u8 *)g_021797A8) + 0x1444, 0xD, mask, (u16)who, c);
            if (r != 0) {
                func_0217814C(r);
                func_02179498();
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}
