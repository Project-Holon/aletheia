/*
 * function: BOX2_SEQ_ShowHandSlotB
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
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_ShowHandSlot 0x021ECFDC thumb ov170
 */
extern void BOX2_SEQ_SetActorDrawEnable(char *,int,int);extern void BOX2_SEQ_ShowHandSlot(char *,int,int);
typedef struct {unsigned char low:7;unsigned char high:1;} Flag;
void BOX2_SEQ_ShowHandSlotB(char *p,unsigned char *q){unsigned i;for(i=28;i<45;i++)BOX2_SEQ_SetActorDrawEnable(p,i,0);if(!((Flag *)(q+18))->high)BOX2_SEQ_ShowHandSlot(p,q[12],q[13]);}
