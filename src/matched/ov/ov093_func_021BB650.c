/*
 * function: BTL_SERVER_BuildActionPacket
 * address:  0x021BB650
 * packet:   pkt_ov093_021BB650
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_REC_InitPacket  0x021EE8B4  thumb  ov093
 *   BTL_ADAPTER_GetSendBuffer  0x021EEB64  thumb  ov093
 *   BTL_REC_AddRecord  0x021EE8F4  thumb  ov093
 *   BTL_REC_FinishPacket  0x021EE96C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BTL_REC_InitPacket(u8 *p, int b);
struct QW;
extern u32 BTL_ADAPTER_GetSendBuffer(struct QW *p, u32 *out);
extern void BTL_REC_AddRecord(u8 *p, u8 idx, const void *src, u32 n);
extern u32 BTL_REC_FinishPacket(u8 *p, int a, int b);

int BTL_SERVER_BuildActionPacket(u8 *p, int a, int b, int c)
{
    u32 i;
    u32 v;

    BTL_REC_InitPacket(p + 0x68, b);
    for (i = 0; i < 4; i++) {
        if (p[i * 12 + 0x1f] != 0xff) {
            u32 r = BTL_ADAPTER_GetSendBuffer((struct QW *)(*(u32 *)(p + i * 12 + 0x14)), &v);

            BTL_REC_AddRecord(p + 0x68, i, (const void *)r, (v << 22) >> 24);
        }
    }
    return BTL_REC_FinishPacket(p + 0x68, a, c);
}
