/*
 * function: VCT_AUDIO_FlushPendingSlot
 * address:  0x021B133C
 * packet:   pkt_ov013_021B133C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   VCT_AUDIO_FindPending  0x021B14A8  arm  ov013
 *   VCT_AUDIO_UnlinkPending  0x021B14F8  arm  ov013
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   g_021B4BA0     0x021B4BA0  data  a4
 */

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
typedef unsigned int   u32;
struct Node;
extern struct Node *VCT_AUDIO_FindPending(u32 type);
extern u32 VCT_AUDIO_UnlinkPending(struct Node *n);
extern void VCT_POOL_FreeFrame(void *p);

extern int g_021B4BA0[3];

void VCT_AUDIO_FlushPendingSlot(unsigned int n)
{
    int s;
    void *p;

    s = OS_DisableInterrupts();
    while ((p = VCT_AUDIO_FindPending(n)) != 0) {
        VCT_AUDIO_UnlinkPending(p);
        VCT_POOL_FreeFrame(p);
    }
    g_021B4BA0[n] = 0;
    OS_RestoreInterrupts(s);
}
