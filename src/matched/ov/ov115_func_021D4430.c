/*
 * function: func_021D4430
 * address: 0x021D4430
 * packet: pkt_ov115_021D4430
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_02156C84 0x02156C84 thumb ov009
 *   func_021D5C24 0x021D5C24 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D43F4 0x021D43F4 thumb ov115
 *   func_021D4360 0x021D4360 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D5C70(u8 *p);
extern unsigned char func_02156C84(void);
extern void func_021D5C24(void *,int);
extern void func_021D426C(u8 *,u32);
extern void func_021D43F4(u8 *);
extern void func_021D4360(u8 *);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4430(u8 *p) {
 if(func_021D5C70((u8 *)W(0x38))) { if(func_02156C84() && !W(0x24) && *(int *)(P(0x40)+0x14)!=2) { func_021D5C24((void *)W(0x38),30); func_021D426C(p,(u32)func_021D43F4); } else { func_021D4360(p); } }
}
