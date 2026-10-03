/*
 * function: func_021F89B4
 * address: 0x021F89B4
 * packet: pkt_ov135_021F89B4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 * symbols:
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_021F8A3C 0x021F8A3C thumb ov135
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021F50EC(u8 *);
extern void func_021F8A3C(void *);
int func_021F89B4(u8 *p) {func_021F50EC(p);func_021F8A3C(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(*(int *)(p+32)){case 19:case 21:*(u32 *)(p+40)=2;break;case 20:*(u32 *)(p+40)=4;break;}return 1;}
