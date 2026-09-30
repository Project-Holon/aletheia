/*
 * function: func_021D4708
 * address: 0x021D4708
 * packet: pkt_ov115_021D4708
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_02009800 0x02009800 thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4474 0x021D4474 thumb ov115
 *   func_021D497C 0x021D497C thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D5E6C(int);
extern int func_021D5EA8(int);
extern void *func_0200B1D4(void *,int);
extern void *func_0200B358(void *);
extern void *func_02012EBC(void *);
extern void func_0200BBD8(void *,int);
extern void *func_0200BAC8(void *);
extern void func_0200B110(void *,int,int);
extern void func_02009800(int);
extern void func_021D426C(u8 *,u32);
extern void func_021D4474(u8 *);
extern void func_021D497C(u8 *);
extern void func_021D5F7C(int);
extern void func_021D5CCC(int,int);
extern void func_021D5E34(int);

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4708(u8 *p) {
 void *v; if(func_021D5E6C(W(0x30))) { if(!func_021D5EA8(W(0x30))) { v=func_0200B1D4(func_0200B358(func_02012EBC((void *)W(0x44))),0); func_0200BBD8(func_0200BAC8(func_02012EBC((void *)W(0x44))),1); func_0200B110(v,10,5); *(int *)(P(0x40)+0x1c)=0; func_02009800(W(0x3c)); func_021D426C(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; func_021D426C(p,(u32)func_021D497C); } func_021D5F7C(W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC(W(0x38),35); func_021D5E34(W(0x30)); W(0x30)=0; }
}
