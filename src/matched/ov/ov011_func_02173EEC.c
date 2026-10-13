/*
 * function: INTRUDE_CMD_SendGroupRecord
 * address:  0x02173EEC
 * packet:   pkt_ov011_02173EEC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_IsSendQueueEntryOfHandle  0x0203D578  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
int GFL_NET_IsSendQueueEntryOfHandle(int a, int b);
void MI_CpuCopy8(char *d, char *s, int n);
typedef unsigned int   u32;
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_CMD_SendGroupRecord(char *a, char *b)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    if (GFL_NET_IsSendQueueEntryOfHandle((int)GFL_NET_HANDLE_GetCurrentHandle(), 0x212) == 1) {
        return 0;
    }
    MI_CpuCopy8(b + 0x78, a + 0x3F0, 0x34);
    return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x212, 0x34, (u32)(a + 0x3F0), 0, 0, 1);
}
