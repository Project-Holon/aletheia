/*
 * function: func_021F6D58
 * address: 0x021F6D58
 * packet: pkt_ov215_021F6D58
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02015E04 0x02015E04 thumb
 *   func_02015F50 0x02015F50 thumb
 */
typedef unsigned char u8;
struct McssFade;
extern void func_02015E04(void *);
extern void func_02015F50(struct McssFade *,u8,u8,int,unsigned);
void func_021F6D58(char *p){func_02015E04(*(void **)(p+52));func_02015F50(*(struct McssFade **)(p+52),0,16,0,32767);}
