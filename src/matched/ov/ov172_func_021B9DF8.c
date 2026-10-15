/*
 * function: CTVT_TALK_CheckEnd
 * address:  0x021B9DF8
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Maps the +4 state to an output code through the two ARM9 probes.
 *
 * symbols:
 *   COMM_TVT_SYS_GetEndRequested  0x021BE0D0  thumb  ov172
 *   COMM_TVT_SYS_GetComm  0x021BDFE4  thumb  ov172
 *   func_021B80E4  0x021B80E4  thumb  ov172
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
extern u32 func_021B80E4(int unused, char *p);
extern u8 COMM_TVT_SYS_GetMemberCount(void *p);

int CTVT_TALK_CheckEnd(void *p, int *out)
{
    if (COMM_TVT_SYS_GetEndRequested(p) == 1) {
        int v = func_021B80E4((int)p, (char *)COMM_TVT_SYS_GetComm(p));

        *out = (v == 5) ? 0x10 : 0xd;
        return 1;
    }
    if (COMM_TVT_SYS_GetMemberCount(p) <= 1) {
        *out = 0x14;
        return 1;
    }
    return 0;
}
