/*
 * function: func_021E2E48
 * address: 0x021E2E48
 * packet: pkt_ov183_021E2E48
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;

void func_021E2E48(char *p,int a,int b) { void (*f)(int,int);f=*(void (**)(int,int))(p+4);if(f){f(a,b);*(int *)(p+4)=0;} }
