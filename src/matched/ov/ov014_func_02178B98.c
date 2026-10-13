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
 *   gWihWork     0x021797A8  data  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_Finalize  0x02179498  thumb  ov014
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

extern struct S *gWihWork;
void WIH_ChangeSysState(int a);
void WIH_SetError(int a);
int WIH_Finalize(void);
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
        WIH_SetError(v);
        WIH_ChangeSysState(9);
        return;
    }
    switch (((struct Obj12474 *)m)->f4) {
    case 0xA:
        if (*(u32 *)(((u8 *)gWihWork) + 0x1E74) == 5) {
            int r;
            int n;

            who = GFL_NET_GetChildSendSize();
            n = GFL_NET_GetMaxConnectNum() - 1;
            mask = (u16)((1 << (n + 1)) - 1);
            c = 1;
            if (GFL_NET_GetGameKind() == 2)
                c = 0;
            r = WM_StartDataSharing(((u8 *)gWihWork) + 0x1444, 0xD, mask, (u16)who, c);
            if (r != 0) {
                WIH_SetError(r);
                WIH_Finalize();
                return;
            }
            WIH_ChangeSysState(5);
            return;
        }
        WIH_ChangeSysState(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}
