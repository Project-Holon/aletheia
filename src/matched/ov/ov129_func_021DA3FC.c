/*
 * function: func_021DA3FC
 * address: 0x021DA3FC
 * packet: pkt_ov129_021DA3FC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *func_020490F4(u32,u16);
extern int func_0204ACEC(void *,u32,u32,u32,u16);
extern void func_02049238(void *);
void func_021DA3FC(u8 *p) { void *f; f=func_020490F4(23,50); *(int *)(p+0x30c)=func_0204ACEC(f,5,0,128,50); func_02049238(f); }
