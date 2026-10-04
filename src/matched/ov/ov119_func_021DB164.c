/*
 * function: func_021DB164
 * address: 0x021DB164
 * packet: pkt_ov119_021DB164
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB10C 0x021DB10C thumb ov119
 */
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *),func_021D8E84(void *,int),func_021DB10C(void *);
void func_021DB164(char *p) {
 func_02045CAC((struct MsgBank *)(*(unsigned *)(p+0x720)),0x8c,(void *)(*(unsigned *)(p+0x738)));
 func_021E1024(p);
 *(int *)(p+0x1074)=1;
 func_021D8E84(p,(int)func_021DB10C);
}
