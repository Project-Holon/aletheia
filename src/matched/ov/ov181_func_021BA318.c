/*
 * unit: no
 * function: STAFF_ROLL_UpdateInput
 * address: 0x021BA318
 * packet: pkt_ov181_021BA318
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetCont 0x0203630C arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern u32 KEY_GetCont(void);
void STAFF_ROLL_UpdateInput(u8 *p){if(**(int **)p){enum {K=0x2d1} k=K;if(p[k]==0)p[k+1]=(KEY_GetCont()&3)?1:0;p[0x2d1]=(p[0x2d1]+1)&3;}}
