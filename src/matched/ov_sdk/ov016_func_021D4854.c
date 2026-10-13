/*
 * function: Parent_get_child_data_kind
 * address:  0x021D4854
 * packet:   pkt_ov016_021D4854
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021DE668  0x021DE668  data
*/

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 sSendBuf[256];
    u8 sRecvBuf[256];
} Wk;

extern Wk *g_021DE668;

u16 Parent_get_child_data_kind(void)
{
    return *(u16 *)(g_021DE668->sRecvBuf + 0x44);
}
