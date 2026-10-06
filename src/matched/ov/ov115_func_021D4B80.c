/*
 * unit: yes
 * function: func_021D4B80, func_021D4BB4
 * address: 0x021D4B80
 * packet: pkt_ov115_021D4B80
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4B80  0x021D4B80  thumb  ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4BC4 0x021D4BC4 thumb ov115
 *   d_021D65D0 0x021D65D0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D4644(u8 *);
extern int func_02167FA8(char *svl, void *result);
extern void func_021D426C(u8 *,u32);
extern void func_021D4BC4(u8 *);
extern u8 d_021D65D0[];
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4B80(u8 *p) {
 if(!func_021D4644(p)) { if(func_02167FA8((char *)d_021D65D0,(void *)(*(int *)(P(0x40)+0x10)))) func_021D426C(p,(u32)func_021D4BC4); else func_021D4644(p); }
}
void func_021D4BB4(u8 *p) { func_021D426C(p,(u32)func_021D4B80); }
