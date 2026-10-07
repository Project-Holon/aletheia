/*
 * file:     wifilogin_disp_p04.c
 * unit:     yes
 * function: func_021D4510, func_021D456C
 * address:  0x021D4510
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4474 0x021D4474 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 *   func_021D5C94 0x021D5C94 thumb ov115
 */
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D5E6C(u8 *p);
extern u8 func_021D5EA8(u8 *p);
extern void func_021D426C(u8 *,u32);
extern void func_021D4474(u8 *);
extern void func_021D4AB0(unsigned char *a);
extern void func_021D5F7C(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_021D5E34(u8 *p);
extern void func_021D5C94(u8 *p);
void func_021D4510(u8 *p);
void func_021D456C(u8 *p);

void func_021D4510(u8 *p) {
 if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; func_021D426C(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; func_021D426C(p,(u32)func_021D4AB0); } func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}

void func_021D456C(u8 *p) {
 if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; func_021D426C(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; func_021D426C(p,(u32)func_021D4AB0); } func_021D5F7C((u8 *)W(0x38)); func_021D5C94((u8 *)W(0x38)); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); }
}
