/*
 * function: func_02164778
 * address: 0x02164778
 * packet: pkt_ov010_02164778
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   func_021F3800 0x021F3800 thumb ov047
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_47 0x0000002F data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5DC(void *a0);
extern int func_02034AC4(int);
extern void func_021F3800(void *);
extern void func_02034A5C(void *);
extern u8 ov_id_47[];
int func_02164778(void *a,void *b){void *v=func_0215A5DC(b);func_02034AC4((int)ov_id_47);func_021F3800(v);func_02034A5C(ov_id_47);return 0;}
