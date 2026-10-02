/*
 * function: func_021649C8
 * address: 0x021649C8
 * packet: pkt_ov010_021649C8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_021F5578 0x021F5578 thumb ov082
 *   func_02159168 0x02159168 thumb ov010
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_52 0x00000052 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201210C(void *);
extern void func_021F5578(void *);
extern void func_02159168(int);
extern void func_02034A5C(void *);
extern u8 ov_id_52[];
int func_021649C8(void **p){func_021F5578(func_0201210C(*p));func_02159168(7);func_02034A5C(ov_id_52);return 1;}
