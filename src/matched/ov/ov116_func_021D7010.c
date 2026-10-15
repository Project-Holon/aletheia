/*
 * function: WIFI_BSUBWAY_ReadRecordUnits
 * address: 0x021D7010
 * packet: pkt_ov116_021D7010
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   D_020A7370 0x020A7370 data a4
 *   MSGDATA_ReadUnits 0x02045F5C arm
 */
struct MsgData;
struct Record { unsigned short id:11; unsigned short rest:5; };
extern struct MsgData *D_020A7370;
extern void MSGDATA_ReadUnits(struct MsgData *,unsigned int,unsigned short *,unsigned int);
void WIFI_BSUBWAY_ReadRecordUnits(unsigned int a,unsigned int b) { unsigned int p; p=a+0x70+b*0x3c; MSGDATA_ReadUnits(D_020A7370,((struct Record *)p)->id,(unsigned short *)(p+0x22),11); }
