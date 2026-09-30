/*
 * function: func_021D456C
 * address: 0x021D456C
 * packet: pkt_ov115_021D456C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4474 0x021D4474 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5C94 0x021D5C94 thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D5E6C(int);
extern int func_021D5EA8(int);
extern void func_021D426C(u8 *,u32);
extern void func_021D4474(u8 *);
extern void func_021D4AB0(u8 *);
extern void func_021D5F7C(int);
extern void func_021D5C94(int);
extern void func_021D5E34(int);
extern void func_021D5CCC(int,int);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D456C(u8 *p) {
 if(func_021D5E6C(W(0x30))) { if(!func_021D5EA8(W(0x30))) { *(int *)(P(0x40)+0x1c)=0; func_021D426C(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; func_021D426C(p,(u32)func_021D4AB0); } func_021D5F7C(W(0x38)); func_021D5C94(W(0x38)); func_021D5E34(W(0x30)); W(0x30)=0; if(!*(int *)(P(0x40)+4)) func_021D5CCC(W(0x38),35); }
}
