/*
 * function: func_021E0CA4
 * address: 0x021E0CA4
 * packet: pkt_ov137_021E0CA4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E078C 0x021E078C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E078C(char *,char *);
int func_021E0CA4(char *p) { char *q; q=*(char **)(p+16); *(int *)(q+56)=4096; *(int *)(q+60)=4096; *(int *)(q+64)=4096; *(int *)(q+84)=0xc0000; func_021E078C(*(char **)(p+20),q); *(int *)(p+12)=0x8000; *(int *)p=1; return 0; }
