/*
 * function: INTRUDE_COMM_RefreshBeacon
 * address:  0x021735FC
 * packet:   pkt_ov011_021735FC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   INTRUDE_COMM_InitBeacon  0x02173590  thumb  ov011
 *   func_0217778C  0x0217778C  thumb  ov014
 */

typedef unsigned char u8;

typedef struct {
    u8 kind;
    u8 a : 4;
    u8 b : 4;
    u8 c : 1;
    u8 d : 5;
    u8 e : 2;
} Hdr;

extern int GFL_NET_GetNegotiationNum(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SYSTEM_CheckError(void);
extern void INTRUDE_COMM_InitBeacon(int a, Hdr *p, int c);
extern void func_0217778C(void);

int INTRUDE_COMM_RefreshBeacon(int a, Hdr *p)
{
    if (p->a != GFL_NET_GetNegotiationNum() || p->c != GFL_NET_SYSTEM_CheckError()) {
        INTRUDE_COMM_InitBeacon(a, p, -1);
        func_0217778C();
        return 1;
    }
    return 0;
}
