/*
 * function: func_021BDB50
 * address: 0x021BDB50
 * packet: pkt_ov110_021BDB50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02024158 0x02024158 thumb
 *   func_02035D20 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned int u32;
extern int func_02024158(u32);
extern int func_02035D20(u32 *,u32 *);
int func_021BDB50(u32 *p) {
 u32 x,y;
 int result;
 if(func_02024158(*p)) return -1;
 if(!func_02035D20(&x,&y)) return -1;
 if(y>168) { result=x/24U-1; if(result>=0 && result<5) return result; }
 return -1;
}
