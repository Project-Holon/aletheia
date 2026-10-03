/*
 * function: func_021BA1C8
 * address: 0x021BA1C8
 * packet: pkt_ov213_021BA1C8
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B9EB0 0x021B9EB0 thumb ov213
 *   func_0204B8A0 0x0204B8A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021B9EB0(void *,u32);
extern void func_0204B8A0(u32,u16);
void func_021BA1C8(char *p,void *list,const u8 *flags,int index) {void *entry=0;int value;if(index<(int)func_0201AA18(list))entry=func_0201AB28(*(void **)p,index);value=func_021B9EB0(entry,flags[index]);func_0204B8A0(*(u32 *)(p+12+index*4),value);}
