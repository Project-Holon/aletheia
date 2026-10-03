/*
 * function: func_021F4D40
 * address: 0x021F4D40
 * packet: pkt_ov112_021F4D40
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204F5A8 0x0204F5A8 arm
 *   func_0204F1A0 0x0204F1A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u16 low:4; u16 bit4:1; u16 rest:11; } Bits;
extern void func_0204F5A8(void *,u32);
extern void func_0204F1A0(void *,u32);
void func_021F4D40(u8 *p,u8 *e) { func_0204F5A8(*(void **)(p+4),*(u32 *)(e+8)); if (((Bits *)e)->bit4==1) func_0204F1A0(*(void **)(p+4),*(u32 *)(e+4)); *(u16 *)e=*(u16 *)e & ~1; *(u16 *)e=*(u16 *)e & ~2; }
