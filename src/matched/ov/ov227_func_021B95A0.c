/*
 * function: EVENT_PDC_RETURN_CreateArgs
 * address: 0x021B95A0
 * packet: pkt_ov227_021B95A0
 * region: ov227
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021B98C0 0x021B98C0 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern const char d_021B98C0[];
extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
void *EVENT_PDC_RETURN_CreateArgs(u32 a, int b, u32 c, u32 heap){u32 *p; p=func_02030734(heap,12,0,d_021B98C0,94);p[0]=a;p[1]=b;p[2]=c;return p;}
