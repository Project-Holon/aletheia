/*
 * function: func_021B7CA4
 * address: 0x021B7CA4
 * packet: pkt_ov104_021B7CA4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 102 code bytes then two zero alignment bytes before 021B7D0C.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0204B3B4(void *);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_0204B1CC(void *);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,int);
void func_021B7CA4(void **p) { int i; for(i=0;i<35;i++) if(p[i+10]) func_0204B3B4(p[i+10]); func_0204ADA4(p[1]); func_0204A8D4(p[2]); func_0204AFD8(p[3]); func_0204ADA4(p[4]); func_0204A8D4(p[5]); func_0204AFD8(p[6]); func_0204ADA4(p[7]); func_0204A8D4(p[8]); func_0204AFD8(p[9]); func_0204B1CC(p[0]); func_0204A5AC(); func_02082BCC(p,0,0xb4); }
