/*
 * function: func_021B9E08
 * address: 0x021B9E08
 * packet: pkt_ov213_021B9E08
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 *   func_021B9830 0x021B9830 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FADE_IsActive(void);
extern void func_021B9830(u8 *task, char *p);
int func_021B9E08(void *a,void *b) {if(FADE_IsActive()==1)return 0;func_021B9830(a,b);return 1;}
