/*
 * function: GDS_SOCKET_GetMaxReplySizeOf
 * address: 0x021D89EC
 * packet: pkt_ov125_021D89EC
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT*
 * lever: for(;;) with an explicit sentinel break preserves the uninverted loop.
 * extent: already matched GDS_SOCKET_SslAuthCallback follows the function.
 * symbols:
 *   sGdsRequestIds 0x021D8CD0 data a4
 */
typedef struct { int words[8]; } Table;
extern const Table sGdsRequestIds;
int GDS_SOCKET_GetMaxReplySizeOf(int n)
{
    Table table = sGdsRequestIds;
    int size;
    int i;
    int got;
    switch (n) {
    case -1:
        size = -1;
        for (i = 0; ; i++) {
            if (table.words[i] == -1) break;
            got = GDS_SOCKET_GetMaxReplySizeOf(table.words[i]);
            if (got > size) size = got;
        }
        if (size == -1) return -1;
        break;
    case 0: size = 0x400; break;
    case 0x5208: size = 8; break;
    case 0x5209: size = 0xb30; break;
    case 0x55f0: size = 8; break;
    case 0x55f1: size = 0x1864; break;
    case 0x55f2: size = 0x18b0; break;
    case 0x55f3: size = 0; break;
    default: return -1;
    }
    return size + 8;
}
