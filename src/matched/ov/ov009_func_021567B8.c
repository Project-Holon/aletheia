/*
 * function: DWC_RAP_PollFriendStatus
 * address:  0x021567B8
 * packet:   pkt_ov009_021567B8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_IsBuddyFriendData  0x0205912C  arm
 *   DWC_GetFriendStatusData  0x02168848  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern int DWC_IsBuddyFriendData(u8 *);
extern unsigned char DWC_GetFriendStatusData(void *p, int a, int b);
extern void MI_CpuFill8(u8 *, u32, u32);

void DWC_RAP_PollFriendStatus(void)
{
    if (*(u8 **)(g_021A8264 + 0x100) != 0) {
        u32 i = *(u32 *)(g_021A8264 + 0x74c) & 0x1f;
        u32 o = i * 12;
        int n;
        if (DWC_IsBuddyFriendData(*(u8 **)(g_021A8264 + 0x100) + o) != 0) {
            u32 r = DWC_GetFriendStatusData(*(u8 **)(g_021A8264 + 0x100) + o,
                                  (int)(g_021A8264 + 0x34c + i * 32), (int)(&n));
            if (n < 1) {
                (g_021A8264 + i)[0x32c] = 0;
                MI_CpuFill8(g_021A8264 + 0x34c + i * 32, 0, 0x20);
            } else {
                (g_021A8264 + i)[0x32c] = r;
            }
        }
        *(u32 *)(g_021A8264 + 0x74c) += 1;
    }
}
