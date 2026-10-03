/*
 * function: func_021D8190
 * address: 0x021D8190
 * packet: pkt_ov116_021D8190
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   func_0202EE30 0x0202EE30 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
void func_021D8190(u8 *p) { *(u8 **)(p+0x98c)=func_0202EE30((void *)func_020056BC(),*(void **)(p+0x97c),15,16,*(u16 *)(p+4)); }
