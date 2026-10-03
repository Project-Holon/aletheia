/*
 * function: func_021F51B0
 * address: 0x021F51B0
 * packet: pkt_ov112_021F51B0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F5330 0x021F5330 thumb ov112
 *   func_021F5644 0x021F5644 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F5330(int,int);
extern void func_021F5644(void *);
extern void func_020307B0(void *);
typedef struct { int f0, f4, active; } Fields;
void func_021F51B0(int a) { int i; for(i=0;i<8;i++) { if(((Fields *)(a+i*556))->active==1)func_021F5330(a,a+8+i*556); } func_021F5644(*(void **)(a+4)); func_020307B0((void *)a); }
