/*
 * function: func_0217F7B8
 * address: 0x0217F7B8
 * packet: pkt_ov019_0217F7B8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021915B4 0x021915B4 thumb ov021
 *   func_0201A570 0x0201A570 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021915B4(void *p);
extern void func_0201A570(void *p);
void func_0217F7B8(char *p) { if(*(void **)(p+0x3530)) { func_021915B4(*(void **)(p+0x2818)); *(void **)(p+0x2818)=0; func_0201A570(*(void **)(p+0x3530)); *(void **)(p+0x3530)=0; } }
