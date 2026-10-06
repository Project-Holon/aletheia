/*
 * function: func_021B98A0
 * address: 0x021B98A0
 * packet: pkt_ov213_021B98A0
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_021BA920 0x021BA920 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Util Util;
struct Sub {u32 a,b;Util *util;u16 index;};
extern u32 func_02048A18(u8 *a0, int i);
extern int func_021BA920(int *p, u32 b, u32 c);
void func_021B98A0(char *p) {int *object;int i;struct Sub *sub;sub=(struct Sub *)(p+0x24);object=(int *)func_02048A18((u8 *)sub->util,sub->index);for(i=0;i<4;i++){int value=1;if(*(u32 *)(p+0x4850+i*0x54))value=3;func_021BA920(object,i+1,value);}}
