/*
 * function: func_02178AB8
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
 * block behind g_021797A8, buffers at +0x1E6C/+0x1E68, heap at +0x1EC0),
 * then calls WM_StartMP with callback func_02178B98; anything but
 * WM_ERRCODE_OPERATING (2) goes to the error setter func_0217814C.
 *
 * symbols:
 *   g_021797A8                  0x021797A8  data   ov014  a4
 *   d_02179794                  0x02179794  data   ov014  a1
 *   func_02178B98               0x02178B98  thumb  ov014
 *   func_0217814C               0x0217814C  thumb  ov014
 *   WM_GetMPSendBufferSize      0x0208EC34  arm
 *   WM_GetMPReceiveBufferSize   0x0208ECA4  arm
 *   WM_StartMP                  0x0208FC4C  arm
 *   func_0203D7FC               0x0203D7FC  arm
 *   func_0203D7C8               0x0203D7C8  arm
 *   func_0203D5D4               0x0203D5D4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern u8 *g_021797A8;
extern char d_02179794[];

extern void func_02178B98(void *arg);
extern void func_0217814C(int err);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_StartMP(void (*cb)(void *), void *recvBuf, u16 recvSize,
                      void *sendBuf, u16 sendSize, u16 mpFreq);
extern void func_0203D7FC(void *p);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern u32 func_0203D5D4(void);

BOOL func_02178AB8(void)
{
    int result;
    u16 freq;

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (*(void **)(g_021797A8 + 0x1E6C) != 0) {
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E6C));
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E68));
    }

    *(int *)(g_021797A8 + 0x1E90) = WM_GetMPReceiveBufferSize();
    *(int *)(g_021797A8 + 0x1E8C) = WM_GetMPSendBufferSize();

    *(void **)(g_021797A8 + 0x1E6C) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E90) + 0x20, d_02179794, 0x7FA);
    *(void **)(g_021797A8 + 0x1E68) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E8C) + 0x20, d_02179794, 0x7FB);

    freq = (func_0203D5D4() == 2) ? 1 : 2;

    result = WM_StartMP(func_02178B98,
                        *(void **)(g_021797A8 + 0x1E6C),
                        (u16)*(int *)(g_021797A8 + 0x1E90),
                        *(void **)(g_021797A8 + 0x1E68),
                        (u16)*(int *)(g_021797A8 + 0x1E8C),
                        freq);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}
