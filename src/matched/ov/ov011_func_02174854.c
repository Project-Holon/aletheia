/*
 * function: INTRUDE_COMM_SendPageRequest
 * address:  0x02174854
 * packet:   pkt_ov011_02174854
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

typedef struct { unsigned char a : 1; unsigned char b : 1; unsigned char c : 1; } F8;

int INTRUDE_COMM_SendPageRequest(unsigned char *p, int b, int c)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    ((F8 *)(p + 0x8F8))->b = 0;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x228, 4, c, 0, 0, 0);
}
