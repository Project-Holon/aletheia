/*
 * function: GAME_BEACON_SEARCH_BuildBeaconHeader
 * address:  0x02164EB4
 * packet:   pkt_ov010_02164EB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears a 100-byte record and fills its header bitfields from SDK
 * queries; 0x02FFFFA8 is the shared-area halfword read as a cast
 * constant (no relocation).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetParentalControlInfoPtr  0x02087E60  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Hdr {
    u8 f00;             /* 0x00 */
    u8 f01_lo : 4;      /* 0x01 */
    u8 f01_hi : 4;
    u8 f02_0 : 1;       /* 0x02 */
    u8 f02_1 : 5;
    u8 f02_6 : 1;
    u8 f02_7 : 1;
    u8 f03_0 : 1;       /* 0x03 */
    u8 f03_1 : 1;
    u8 f03_2 : 6;
    u32 f04;            /* 0x04 */
} Hdr;

typedef struct Flags {
    u32 b0 : 1;
    u32 b1 : 4;
    u32 b5 : 1;
    u32 rest : 26;
} Flags;

extern void MI_CpuFill8(void *p, int v, u32 n);
extern int GFL_NET_GetNegotiationNum(void);
extern u32 GFL_NET_SYSTEM_CheckError(void);
extern int OS_IsRunOnTwl(void);
extern Flags *OS_GetParentalControlInfoPtr(void);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);

void GAME_BEACON_SEARCH_BuildBeaconHeader(Hdr *p, void *src)
{
    int v;
    int t;

    MI_CpuFill8(p, 0, 100);
    p->f00 = 3;
    p->f01_lo = (u8)GFL_NET_GetNegotiationNum();
    p->f01_hi = 3;
    p->f02_0 = (u8)GFL_NET_SYSTEM_CheckError();
    p->f02_1 = 0;
    p->f04 = func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(src));
    p->f02_7 = (u8)OS_IsRunOnTwl();
    p->f02_6 = 0;
    t = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    p->f03_1 = (u8)t;
    if (p->f02_7 == 1) {
        v = 1;
        if (OS_GetParentalControlInfoPtr()->b0 == 0 || OS_GetParentalControlInfoPtr()->b5 == 0)
            v = 0;
        p->f02_6 = v;
    }
}
