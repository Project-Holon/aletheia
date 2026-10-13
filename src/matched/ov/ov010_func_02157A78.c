/*
 * function: DELIVERY_IRC_StepWaitEndSync
 * address:  0x02157A78
 * packet:   pkt_ov010_02157A78
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   func_0217998C  0x0217998C  thumb ov015
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb
 *   DELIVERY_IRC_StepExitParent  0x02157A30  thumb
 *   DELIVERY_IRC_StepExitChild  0x02157A58  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 GFL_NET_IsParentAid(void);
extern void func_0217998C(int);
extern void DELIVERY_IRC_SetStepAtLine(int a, int b, int c);
extern void DELIVERY_IRC_StepExitParent(int p);
extern void DELIVERY_IRC_StepExitChild(int p);

void DELIVERY_IRC_StepWaitEndSync(u32 *p)
{
    int k = 0x23;
    void *h = GFL_NET_HANDLE_GetCurrentHandle();

    if (func_02039CB4(h, 0x23, (u8)*p) != 0) {
        if (GFL_NET_IsParentAid() != 0) {
            k = 0x12C;
            func_0217998C(k);
            k -= 0x19;
            DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepExitParent, k);
            return;
        }
        k += 0xF3;
        DELIVERY_IRC_SetStepAtLine((int)p, (int)DELIVERY_IRC_StepExitChild, k);
    }
}
