/*
 * function: WIH_StateInStartParentMP
 * address:  0x02178304
 * packet:   pkt_ov014_02178304
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of DWCi_MOV_WH_StateInStartChildMP (the DWC copy of the NitroSDK wh.c MP start), with a
 * state guard in front: states 4 and 5 (+0x1E70) already run MP, else the
 * state setter WIH_ChangeSysState(4) runs first, and the callback is
 * WIH_StateOutStartParentMP.
 *
 * symbols:
 *   gWihWork                  0x021797A8  data   ov014  a4
 *   sWihFileName                  0x02179794  data   ov014  a1
 *   WIH_StateOutStartParentMP               0x021783FC  thumb  ov014
 *   WIH_SetError               0x0217814C  thumb  ov014
 *   WIH_ChangeSysState               0x02178138  thumb  ov014
 *   WM_GetMPSendBufferSize      0x0208EC34  arm
 *   WM_GetMPReceiveBufferSize   0x0208ECA4  arm
 *   WM_StartMP                  0x0208FC4C  arm
 *   GFL_NET_FreeAligned               0x0203D7FC  arm
 *   GFL_NET_AllocAligned               0x0203D7C8  arm
 *   GFL_NET_GetGameKind               0x0203D5D4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern u8 *gWihWork;
extern char sWihFileName[];

extern void WIH_StateOutStartParentMP(u16 *a);
extern void WIH_SetError(int err);
extern void WIH_ChangeSysState(int state);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_StartMP(void (*cb)(void *), void *recvBuf, u16 recvSize,
                      void *sendBuf, u16 sendSize, u16 mpFreq);
extern void GFL_NET_FreeAligned(void *p);
extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);
extern u32 GFL_NET_GetGameKind(void);

BOOL WIH_StateInStartParentMP(void)
{
    int result;
    u16 freq;

    if (*(int *)(gWihWork + 0x1E70) == 4 || *(int *)(gWihWork + 0x1E70) == 5)
        return 1;

    WIH_ChangeSysState(4);

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (*(void **)(gWihWork + 0x1E6C) != 0) {
        GFL_NET_FreeAligned(*(void **)(gWihWork + 0x1E6C));
        GFL_NET_FreeAligned(*(void **)(gWihWork + 0x1E68));
    }

    *(int *)(gWihWork + 0x1E90) = WM_GetMPReceiveBufferSize();
    *(int *)(gWihWork + 0x1E8C) = WM_GetMPSendBufferSize();

    *(void **)(gWihWork + 0x1E6C) =
        GFL_NET_AllocAligned(*(u16 *)(gWihWork + 0x1EC0),
                      *(int *)(gWihWork + 0x1E90) + 0x20, sWihFileName, 0x4A7);
    *(void **)(gWihWork + 0x1E68) =
        GFL_NET_AllocAligned(*(u16 *)(gWihWork + 0x1EC0),
                      *(int *)(gWihWork + 0x1E8C) + 0x20, sWihFileName, 0x4A8);

    freq = (GFL_NET_GetGameKind() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))WIH_StateOutStartParentMP,
                        *(void **)(gWihWork + 0x1E6C),
                        (u16)*(int *)(gWihWork + 0x1E90),
                        *(void **)(gWihWork + 0x1E68),
                        (u16)*(int *)(gWihWork + 0x1E8C),
                        freq);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}
