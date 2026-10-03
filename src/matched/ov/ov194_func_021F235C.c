/*
 * function: func_021F235C
 * address: 0x021F235C
 * packet: pkt_ov194_021F235C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F2190 0x021F2190 thumb ov194
 *   func_02045A98 0x02045A98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F2190(char *,u16);
extern u16 func_02045A98(void);
void func_021F235C(char *p) { int i; for(i=0;i<*(u16 *)(p+32);i++)func_021F2190(p,*(u16 *)((u32)p+(u32)i*2+22));*(u16 *)(p+32)=0;*(u16 *)((u32)p+*(u16 *)(p+32)*2+22)=func_02045A98();*(u32 *)(p+40)=1; }
