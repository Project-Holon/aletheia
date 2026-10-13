/*
 * function: BTL_ADAPTER_Update
 * address:  0x021EEB2C
 * packet:   pkt_ov093_021EEB2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_ADAPTER_StartSend  0x021EEB84  thumb  ov093
 *   BTL_ADAPTER_PollSend  0x021EEBA4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern int BTL_ADAPTER_StartSend(W *);
extern int BTL_ADAPTER_PollSend(W *);

int BTL_ADAPTER_Update(W *p)
{
    switch (p->mode) {
    case 1:
        if (BTL_ADAPTER_StartSend(p) == 0)
            break;
        p->mode = 3;
    case 3:
        if (BTL_ADAPTER_PollSend(p) == 0)
            break;
        p->mode = 4;
    case 4:
        return 1;
    }
    return 0;
}
