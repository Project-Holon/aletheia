/*
 * unit: no
 * function: GSYNC_DISP_SetIconRecord
 * address: 0x021D6A70
 * packet: pkt_ov123_021D6A70
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
void GSYNC_DISP_SetIconRecord(u8 *p,int i,int a,int b,int c){if(a!=0 && a<=493){*(s16 *)(p+(u32)i*24+0x4104)=a;*(s16 *)(p+(u32)i*24+0x4106)=b;if(c>2)c=0;*(s16 *)((u32)p+(u32)i*24+0x4108)=c;}}
