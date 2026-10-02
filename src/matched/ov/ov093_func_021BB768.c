/*
 * function: func_021BB768
 * address: 0x021BB768
 * packet: pkt_ov093_021BB768
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB830 0x021BB830 thumb ov093
 *   func_021EEB70 0x021EEB70 thumb ov093
 *   func_021EEB00 0x021EEB00 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BB830(u8 *);
extern void func_021EEB70(u32);
extern void func_021EEB00(u32, int, int, int);
void func_021BB768(u8 *p, int a, u32 i, int b, int c) {
    u8 *q;
    q = (u8 *)((u32)p + 20);
    if (func_021BB830((u8 *)((u32)q+i*12))) {
        func_021EEB70(*(u32 *)((u32)q+i*12));
        func_021EEB00(*(u32 *)((u32)q+i*12),a,b,c);
    }
}
