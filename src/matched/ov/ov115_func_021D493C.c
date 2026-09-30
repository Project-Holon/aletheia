/*
 * function: func_021D493C
 * address: 0x021D493C
 * packet: pkt_ov115_021D493C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D4240 0x021D4240 thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4910 0x021D4910 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_020221A4(void);
extern int func_021D4240(u8 *);
extern void func_021D5D3C(int);
extern void func_021D5ED8(int,int);
extern int func_0202EB0C(void);
extern void func_021D426C(u8 *,u32);
extern void func_021D4910(u8 *);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D493C(u8 *p) {
 if (func_020221A4() && func_021D4240(p)) { func_021D5D3C(W(0x38)); if (func_0202EB0C()) func_021D5ED8(W(0x38), 0x2e); else func_021D5ED8(W(0x38), 0x15); func_021D426C(p, (u32)func_021D4910); }
}
