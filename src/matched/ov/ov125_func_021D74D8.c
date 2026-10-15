/*
 * function: GDS_RAP_GetVideoReply
 * address:  0x021D74D8
 * packet:   pkt_ov125_021D74D8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 * note: 2026-10-05 (D4-14): the xor/orr equality is a 64-bit compare; written as u64 loads, EXACT.
 * symbols:
 *   GDS_SOCKET_GetReply  0x021D85E8  arm  ov125
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;


extern char *GDS_SOCKET_GetReply(void);
typedef unsigned int   u32;
extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

typedef unsigned long long u64;
int GDS_RAP_GetVideoReply(void *unused, char **out)
{
    char *p = (char *)GDS_SOCKET_GetReply();
    char *s = p + 4;
    u64 id;

    *out = s + 0xC;
    id = *(u64 *)(p + 8);
    if (*(u64 *)(s + 0xC4) != id) {
        *(u64 *)(s + 0xC4) = id;
        *(u16 *)(*out + 0xC0) = GF_STANDARD_SetupCalc((u8 *)(*out + 0x80), 0x38);
    }
    return *(int *)(p + 8);
}
