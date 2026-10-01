/*
 * function: func_021B9B7C
 * address: 0x021B9B7C
 * packet: pkt_ov224_021B9B7C
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The read-only cfg table is const: removing const delayed signed-halfword
 * loads past outgoing argument stores (108 bytes,19 concrete bytes out).
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021B989C 0x021B989C thumb ov224
 *   vecA 0x021B9C3C data
 *   vecB 0x021B9C30 data
 *   vecC 0x021B9C48 data
 *   cfg 0x020A1EB8 data
 */
typedef unsigned int u32;
typedef signed short s16;
extern const s16 cfg[];
extern u32 vecA[],vecB[],vecC[];
extern void func_021B989C(void);
extern void func_02046440(u32,u32,u32,u32,unsigned short,u32,void(*)(void));
extern void *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,void *,void *,void *,u32);
void func_021B9B7C(void **p,u32 heap)
{
    func_02046440(0,1,0,1,0,heap,func_021B989C);
    *p = func_02048A24(0,cfg[6],cfg[7],0x1555,0,0x1000,0x400000,0,
        vecA,vecB,vecC,heap);
}
