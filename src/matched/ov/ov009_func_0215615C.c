/*
 * function: DWC_RAP_SendHeartbeat
 * address:  0x0215615C
 * packet:   pkt_ov009_0215615C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_RAP_CanSendToAllPeers  0x0215610C  thumb  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   func_02176FD4  0x02176FD4  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char *g_021A8264;
extern int DWC_RAP_CanSendToAllPeers(void);
extern int DWC_GetAIDBitmap(void);
extern unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);

int DWC_RAP_SendHeartbeat(u32 idx)
{
    if (*(u32 *)(g_021A8264 + 0x760) == 0 && DWC_RAP_CanSendToAllPeers() != 0
        && (DWC_GetAIDBitmap() & 0xFFFE) != 0) {
        *(u32 *)(g_021A8264 + 0x760) = 1;
        *(u32 *)g_021A8264 = ((u32)*(u16 *)(g_021A8264 + 0x794) << 8) | 2;
        func_02176FD4(DWC_GetAIDBitmap(), g_021A8264, 4);
        *(u32 *)(g_021A8264 + idx * 4 + 0x784) = 0;
        return 1;
    }
    return 0;
}
