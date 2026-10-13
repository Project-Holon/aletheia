/*
 * function: cbConfig
 * address:  0x021C15FC
 * packet:   pkt_ov016_021C15FC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gRakuStatus  0x021DE594  data
*/

typedef struct {
    int a;
    int b;
    int c;
} Cfg3;

extern int *gRakuStatus;

void cbConfig(Cfg3 *cfg)
{
    *(Cfg3 *)gRakuStatus = *cfg;
}
