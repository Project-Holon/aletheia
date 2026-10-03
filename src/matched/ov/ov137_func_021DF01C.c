/*
 * function: func_021DF01C
 * address: 0x021DF01C
 * packet: pkt_ov137_021DF01C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0478 0x021E0478 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E0478(void *,int);
int func_021DF01C(u8 *p) { int i; *(int *)(p+12)+=1; if(*(int *)(p+12)<95) return 0; for(i=0;i<*(int *)(p+48);i++) func_021E0478(p,i); *(int *)(p+12)=0; *(int *)p=26; return 0; }
