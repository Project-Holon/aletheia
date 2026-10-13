/*
 * function: WIFICLUB_ClearPeerActors
 * address: 0x021BE26C
 * packet: pkt_ov099_021BE26C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUBACTOR_Exit 0x021B9670 thumb ov099
 *   WIFICLUB_ClearSlotState 0x021C203C thumb ov099
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void WIFICLUBACTOR_Exit(char *);
extern void WIFICLUB_ClearSlotState(char *,int);
extern void MI_CpuFill8(void *,int,int);
void WIFICLUB_ClearPeerActors(char *p) {
 int i;
 WIFICLUBACTOR_Exit(p+0x274);
 for (i=0;i<33;i++) {
  *(int *)((unsigned int)p+(unsigned int)i*4+0x814)=0;
  WIFICLUB_ClearSlotState(p,i+1);
 }
 MI_CpuFill8(p+0x50,0,32);
}
