/*
 * function: WIH_StateOutStartParentMP
 * address:  0x021783FC
 * packet:   pkt_ov014_021783FC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gWihWork     0x021797A8  data  ov014  a4
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   GFL_NET_GetGameKind  0x0203D5D4  arm
 *   WM_StartDataSharing  0x0209004C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *gWihWork;
void WIH_SetError(int error);
void WIH_ChangeSysState(int state);
u32 GFL_NET_GetChildSendSize(void);
u32 GFL_NET_GetMaxConnectNum(void);
u32 GFL_NET_GetGameKind(void);
int WM_StartDataSharing(void *p, u32 a, u32 b, u16 c, u32 d);

void WIH_StateOutStartParentMP(u16 *a)
{
    u16 v1 = a[1];
    u16 mask;
    u32 id;
    u32 flag;
    u32 n;
    int r;
    if (v1 != 0) {
        WIH_SetError(v1);
        WIH_ChangeSysState(9);
        return;
    }
    switch (a[2]) {
    case 10:
        if (*(int *)(gWihWork + 0x1E74) == 4) {
            id = GFL_NET_GetChildSendSize();
            n = GFL_NET_GetMaxConnectNum() - 1;
            mask = (1 << (n + 1)) - 1;
            flag = 1;
            if (GFL_NET_GetGameKind() == 2)
                flag = 0;
            r = WM_StartDataSharing(gWihWork + 0x1444, 13, mask, id, flag);
            if (r != 0) {
                WIH_SetError(r);
                WIH_ChangeSysState(9);
                return;
            }
            WIH_ChangeSysState(5);
            return;
        }
        WIH_ChangeSysState(4);
        break;
    case 11:
    case 12:
    case 13:
        break;
    }
}
