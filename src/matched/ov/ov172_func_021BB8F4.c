/*
 * function: CTVT_DRAW_CheckLeave
 * address:  0x021BB8F4
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Maps the +4 state to an output code through the two ARM9 probes, 9/6/0xd.
 *
 * symbols:
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   COMM_TVT_SYS_GetComm  0x021BDFE4  thumb  ov172
 *   CTVT_COMM_GetNetMode  0x021B80E4  thumb  ov172
 *   COMM_TVT_SYS_GetMemberCount  0x021BE054  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 COMM_TVT_SYS_GetEndRequested(void *p);
extern u32 COMM_TVT_SYS_GetComm(void *p);
extern u32 CTVT_COMM_GetNetMode(int unused, char *p);
extern u8 COMM_TVT_SYS_GetMemberCount(void *p);

int CTVT_DRAW_CheckLeave(void *a0, int *out)
{
    if (COMM_TVT_SYS_GetEndRequested(a0) == 1) {
        int v = CTVT_COMM_GetNetMode((int)a0, (char *)COMM_TVT_SYS_GetComm(a0));

        *out = (v == 5) ? 9 : 6;
        return 1;
    }
    if (COMM_TVT_SYS_GetMemberCount(a0) <= 1) {
        *out = 0xd;
        return 1;
    }
    return 0;
}
