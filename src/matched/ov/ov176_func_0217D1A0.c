/*
 * function: func_0217D1A0
 * address: 0x0217D1A0
 * packet: pkt_ov176_0217D1A0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * calls: 021E62CC own source has five inputs, but this caller visibly
 *   stores the sixth at 0217D1B6; retain the zero-extended halfword payload.
 * symbols:
 *   func_021E62CC 0x021E62CC thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E62CC(char *,int,void *,void *,int,u32);
void func_0217D1A0(u8 *p,int mode) {func_021E62CC(*(char **)(p+16),mode,*(void **)(p+36),*(void **)(p+0x1ac),*(int *)(p+0x1a8),*(u16 *)(p+0x1c8));}
