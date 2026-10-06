/*
 * function: func_021DBC3C
 * address: 0x021DBC3C
 * packet: pkt_ov131_021DBC3C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020307B0(void *p);
void func_021DBC3C(u8 *p)
{
    u8 i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            func_0204A8D4((u32)(*(void **)(p + 0x14 + (j + i * p[0x22]) * 4)));
            func_0204B3B4(*(void **)(p + 4 + (j + i * p[0x22]) * 4));
        }
    }
    func_020307B0(p);
}
