/*
 * function: func_021D4CE4
 * address: 0x021D4CE4
 * packet: pkt_ov115_021D4CE4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D4DF4 0x021D4DF4 thumb ov115
 *   func_021D5A88 0x021D5A88 thumb ov115
 *   func_021D5E48 0x021D5E48 thumb ov115
 */
typedef unsigned char u8; typedef unsigned int u32;
extern u32 func_020221A4(void); extern int func_021D5C70(int); extern void func_021D426C(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D4DF4(u8 *p); extern void func_021D5A88(void *); extern void func_021D5E48(void *);
int func_021D4CE4(int a,int b,int c,u8 *p) { int r=1; void (*cb)(u8 *); func_021D4DF4(*(void **)(p+0x34)); func_021D5A88(*(void **)(p+0x38)); cb=*(void (**)(u8 *))p; if(cb) { cb(p); r=0; } if(*(void **)(p+0x30)) func_021D5E48(*(void **)(p+0x30)); return r; }
