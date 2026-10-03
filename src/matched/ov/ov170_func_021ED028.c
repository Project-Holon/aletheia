/*
 * function: func_021ED028
 * address: 0x021ED028
 * packet: pkt_ov170_021ED028
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Byte bitfield access reproduces the original ldrb/lsl24/lsr31
 * at 0x021ED042..0x021ED046; a mask test emitted movs/tst instead.
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ECFDC 0x021ECFDC thumb ov170
 */
extern void func_021EC000(char *,int,int);extern void func_021ECFDC(char *,int,int);
typedef struct {unsigned char low:7;unsigned char high:1;} Flag;
void func_021ED028(char *p,unsigned char *q){unsigned i;for(i=28;i<45;i++)func_021EC000(p,i,0);if(!((Flag *)(q+18))->high)func_021ECFDC(p,q[12],q[13]);}
