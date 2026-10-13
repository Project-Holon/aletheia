/*
 * function: func_021D4360
 * address: 0x021D4360
 * packet: pkt_ov115_021D4360
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203C600 has no outside code witness; the integrator owns it.
 * blocker: 0x0203C600 ARM verified EXACT in ov099_func_021BEB68.c.
 *   extern char *d_021469DC;
 *   extern void func_0203C0F4(void);
 *   int func_0203C600(void) {
 *       return *(void **)(d_021469DC + 8) == (void *)func_0203C0F4;
 *   }
 *   symbols: d_021469DC 0x021469DC data; func_0203C0F4 0x0203C0F4 arm.
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
 */
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
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4360(u8 *p) {
 if(func_0203C600()) { if(W(0x20)) { func_021D5D3C((u8 *)W(0x38)); func_021D5C94((u8 *)W(0x38)); if(func_0202EB0C()) func_021D5ED8((u8 *)W(0x38),44); else func_021D5ED8((u8 *)W(0x38),19); func_021D426C(p,(u32)func_021D4310); } else if(*(int *)(P(0x40)+0x10)) { func_021D426C(p,(u32)func_021D4BB4); } else { func_021D426C(p,(u32)func_021D4AB0); } } else func_021D4644(p);
}
