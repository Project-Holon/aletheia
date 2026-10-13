/*
 * function: INTRUDE_COMM_SendUnionInfo
 * address:  0x02174734
 * packet:   pkt_ov011_02174734
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
int GFL_NET_IsSendQueueEntryOfHandle(int a, int b);
void MI_CpuCopy8(void *d, void *s, int n);
typedef unsigned int   u32;
u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_COMM_SendUnionInfo(char *p, int b, void *c)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle((int)GFL_NET_HANDLE_GetCurrentHandle(), 0x225) == 1) {
        return 0;
    }
    MI_CpuCopy8(c, p + 0x460, 0x1E8);
    return GFL_NET_SendDataMask((int)GFL_NET_HANDLE_GetCurrentHandle(), b & 0xFF, 0x225, 0x1E8, (u32)c, 0, 0, 1);
}
