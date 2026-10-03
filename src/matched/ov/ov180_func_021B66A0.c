/*
 * function: func_021B66A0
 * address: 0x021B66A0
 * packet: pkt_ov180_021B66A0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02047CFC 0x02047CFC arm
 *   func_021B65FC 0x021B65FC thumb ov180
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
struct Util;
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct Util *func_02047CFC(u16,u16,u16);
extern void func_021B65FC(void);
void func_021B66A0(char *p) {func_02046440(0,1,0,1,4096,141,func_021B65FC);*(struct Util **)(p+16)=func_02047CFC(32,32,141);}
