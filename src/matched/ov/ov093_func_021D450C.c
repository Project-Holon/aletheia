/*
 * function: BTL_NET_SendPerapVoice
 * address:  0x021D450C
 * packet:   pkt_ov093_021D450C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B00  0x02007B00  thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u8 pad04[0x3b18];
    u32 f3b1c;
};

extern struct S *gBtlNet;
extern void *func_02007B50(void **p);
extern u32 func_02007B00(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 BTL_NET_SendPerapVoice(u32 *a)
{
    u32 t;

    if (func_02007B50((void **)a) != 0) {
        t = func_02007B00();
    } else {
        t = 4;
        a = &gBtlNet->f3b1c;
        *a = 0;
    }
    return GFL_NET_SendData(gBtlNet->f00, 0xff, 0x103, t, (u32)a, 0, 1, 1);
}
