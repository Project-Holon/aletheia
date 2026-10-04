/*
 * function: func_021B68A8
 * address: 0x021B68A8
 * packet: pkt_ov180_021B68A8
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_021B8034 0x021B8034 data a4
 *   d_021B801C 0x021B801C data a4
 *   d_021B8028 0x021B8028 data a4
 */
typedef unsigned int   u32;
extern void *func_02014B08(u32 id, void *heap); extern void func_02016020(void *,unsigned); extern void func_02015BF0(void *);
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,void *,void *,void *,unsigned short);
struct Light;
extern void func_02048AD0(struct Light *l);
extern unsigned d_021B8034[]; extern unsigned d_021B801C[]; extern unsigned d_021B8028[];
void func_021B68A8(char *p) {
 *(void **)(p+0x18)=func_02014B08(1,(void *)141); func_02016020(*(void **)(p+0x18),0); func_02015BF0(*(void **)(p+0x18));
 *(void **)(p+0x20)=func_02048A24(2,0x60000,0xFFFA0000,0xFFF80000,0x80000,0x1000,0x400000,0,d_021B8034,d_021B801C,d_021B8028,141);
 func_02048AD0(*(void **)(p+0x20));
}
