/*
 * file:     wifilogin_disp_p02.c
 * unit:     yes
 * function: func_021D4360, func_021D43CC
 * address:  0x021D4360
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
 *   func_0203C600 0x0203C600 arm
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5C94 0x021D5C94 thumb ov115
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4310 0x021D4310 thumb ov115
 *   func_021D4BB4 0x021D4BB4 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_02156C84 0x02156C84 thumb ov009
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02156C98 0x02156C98 thumb ov009
 */
#include "../../matched/include/Obj22588.h"

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0203C600(void);
extern void func_021D5D3C(u8 *p);
extern void func_021D5C94(u8 *p);
extern void func_021D5ED8(u8 *p, u32 n);
extern u32 func_0202EB0C(void);
extern void func_021D426C(u8 *,u32);
extern void func_021D4310(u8 *);
extern void func_021D4BB4(u8 *);
extern void func_021D4AB0(unsigned char *a);
extern int func_021D4644(u8 *);
extern u32 func_020221A4(void);
extern int func_021D5C70(int);
extern void *func_021D5D5C(u8 *,int,int,int);
extern unsigned char func_02156C84(void);
extern int func_02012DD0(u8 *);
extern void func_02156C98(int);
void func_021D4360(u8 *p);
void func_021D43CC(u8 *p);

void func_021D4360(u8 *p) {
 if(func_0203C600()) { if(W(0x20)) { func_021D5D3C((u8 *)W(0x38)); func_021D5C94((u8 *)W(0x38)); if(func_0202EB0C()) func_021D5ED8((u8 *)W(0x38),44); else func_021D5ED8((u8 *)W(0x38),19); func_021D426C(p,(u32)func_021D4310); } else if(*(int *)(P(0x40)+0x10)) { func_021D426C(p,(u32)func_021D4BB4); } else { func_021D426C(p,(u32)func_021D4AB0); } } else func_021D4644(p);
}

void func_021D43CC(u8 *p) { int r; if(func_02156C84()) { r=func_02012DD0(*(u8 * *)&((struct Obj22588 *)p)->f44); switch(r) { case 0: case 1: return; default: func_02156C98(r); break; } } func_021D4360(p); }
