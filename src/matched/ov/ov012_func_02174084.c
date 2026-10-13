/*
 * function: UNION_COMMAND_SendAppLeaveData
 * address:  0x02174084
 * packet:   pkt_ov012_02174084
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 */

typedef struct { int w[8]; } B32;
typedef struct { B32 a; unsigned char t[8]; } Msg;

extern void MI_CpuFill8(void *p, int v, int n);
extern void OS_GetMacAddress(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void UNION_COMMAND_SendAppLeaveData(int a, B32 *src)
{
    Msg m;

    MI_CpuFill8(&m, 0, 0x28);
    m.a = *src;
    OS_GetMacAddress(m.t);
    GFL_NET_SendDataMask((int)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x1413, 0x28, (u32)(&m), 1, 0, 0);
}
