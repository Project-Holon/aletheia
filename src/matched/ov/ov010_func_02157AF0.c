/*
 * function: DELIVERY_IRC_StepSendData
 * address:  0x02157AF0
 * packet:   pkt_ov010_02157AF0
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
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   DELIVERY_IRC_SetStepAtLine  0x02157960  thumb
 *   DELIVERY_IRC_StepStartEndSync  0x02157AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned int   u32;
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void DELIVERY_IRC_SetStepAtLine(int a, int b, int c);
extern void DELIVERY_IRC_StepStartEndSync(int *p);

void DELIVERY_IRC_StepSendData(int *p)
{
    u8 *b = (u8 *)p;
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, (u8)p[0]) == 0)
        return;
    if (b[0x675] != 0) {
        if (b[0x676] == 1) {
            int *e = (int *)(b + 8 + b[0x677] * 16);
            int k = 0xFF;
            if (GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, (unsigned)(p[0] << 24) >> 16, e[0], e[1], 0, 0, 1) == 0)
                return;
            DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepStartEndSync), k + 0x2F);
            return;
        }
        DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepStartEndSync), 0x133);
        return;
    }
    DELIVERY_IRC_SetStepAtLine((int)p, (int)((void *)DELIVERY_IRC_StepStartEndSync), 0x137);
}
