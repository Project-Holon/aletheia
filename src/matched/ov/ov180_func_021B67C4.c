/*
 * function: func_021B67C4
 * address: 0x021B67C4
 * packet: pkt_ov180_021B67C4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020515B4 0x020515B4 arm
 *   d_021B80CC 0x021B80CC data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {int a,b,c;} Triple;
extern Triple d_021B80CC;
extern int func_020515B4(void *p, int b, int c);
void func_021B67C4(char *p,int a){Triple v;v=d_021B80CC;func_020515B4(*(void **)(p+40),a,(int)((int *)&v));}
