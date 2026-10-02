/*
 * function: func_0217F9BC
 * address: 0x0217F9BC
 * packet: pkt_ov019_0217F9BC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_020470D0(void *p);
extern void func_02046EFC(void *p);
void func_0217F9BC(char *p) { func_020470D0(*(void **)(p+0x14)); func_02046EFC(*(void **)(p+0x18)); *(void **)(p+0x18)=0; func_02046EFC(*(void **)(p+0x14)); *(void **)(p+0x14)=0; }
