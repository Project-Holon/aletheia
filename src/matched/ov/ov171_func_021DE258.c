/*
 * function: func_021DE258
 * address: 0x021DE258
 * packet: pkt_ov171_021DE258
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DE1F8 0x021DE1F8 thumb ov171
 *   func_021DE218 0x021DE218 thumb ov171
 *   func_021DE238 0x021DE238 thumb ov171
 */
extern void func_021DE1F8(char *, int);
extern void func_021DE218(char *, int);
extern void func_021DE238(char *, int);
void func_021DE258(char *p)
{
    unsigned i;
    for(i=0;i<13;i++)func_021DE1F8(p,i);
    for(i=0;i<13;i++)func_021DE218(p,i);
    for(i=0;i<13;i++)func_021DE238(p,i);
}
