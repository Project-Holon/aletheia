/*
 * function: func_021B78A0
 * address: 0x021B78A0
 * packet: pkt_ov173_021B78A0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0204A9D0;
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int,struct Sub0204A9D0 *);
extern u32 func_020307B0(void *p);
void func_021B78A0(u32 a,int b,u32 c,u32 d,u16 heap) {void *raw;struct Sub0204A9D0 *out;raw=ARC_UTIL_LoadScreenDataFromHandle((void *)a,c,d,(u32)(&out),heap);CLACT_TransferCharacter(b,out);func_020307B0(raw);}
