/*
 * function: DWCi_MOV_WH_StateInStartChildMP
 * address:  0x02178AB8
 * packet:   pkt_ov014_02178AB8
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The DWC copy of the NitroSDK demo wh.c's MP start (DWCi_MOV_WH_*): frees
 * and re-allocates the MP receive and send buffers (sizes from
 * WM_GetMP{Receive,Send}BufferSize, kept at +0x1E90/+0x1E8C of the work
 * block behind gWihWork, buffers at +0x1E6C/+0x1E68, heap at +0x1EC0),
 * then calls WM_StartMP with callback DWCi_MOV_WH_StateOutStartChildMP; anything but
 * WM_ERRCODE_OPERATING (2) goes to the error setter WIH_SetError.
 *
 * symbols:
 *   gWihWork                  0x021797A8  data   ov014  a4
 *   sWihFileName                  0x02179794  data   ov014  a1
 *   DWCi_MOV_WH_StateOutStartChildMP               0x02178B98  thumb  ov014
 *   WIH_SetError               0x0217814C  thumb  ov014
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

extern void DWCi_MOV_WH_StateOutStartChildMP(u8 *m);
extern void WIH_SetError(int err);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_StartMP(void (*cb)(void *), void *recvBuf, u16 recvSize,
                      void *sendBuf, u16 sendSize, u16 mpFreq);
extern void GFL_NET_FreeAligned(void *p);
extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);
extern u32 GFL_NET_GetGameKind(void);

BOOL DWCi_MOV_WH_StateInStartChildMP(void)
{
    int result;
    u16 freq;

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
                      *(int *)(gWihWork + 0x1E90) + 0x20, sWihFileName, 0x7FA);
    *(void **)(gWihWork + 0x1E68) =
        GFL_NET_AllocAligned(*(u16 *)(gWihWork + 0x1EC0),
                      *(int *)(gWihWork + 0x1E8C) + 0x20, sWihFileName, 0x7FB);

    freq = (GFL_NET_GetGameKind() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))DWCi_MOV_WH_StateOutStartChildMP,
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
