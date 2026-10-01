/*
 * function: func_021B67BC
 * address: 0x021B67BC
 * packet: pkt_ov172_021B67BC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   func_021B680C 0x021B680C arm ov172
 *   func_0203D7FC 0x0203D7FC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02085D3C(void);
extern int func_021B680C(void);
extern void func_0203D7FC(u32);
extern void func_020307B0(void *);
void func_021B67BC(char *p)
{
    u8 i;
    if (*(u32 *)(p + 0x10) != 0) return;
    if ((func_02085D3C() == 1 ? func_021B680C() : 0) != 0) return;
    if (*(u32 *)(p + 0xC) == 1) {
        for (i = 0; i < *(u8 *)(p + 8); i++)
            func_0203D7FC((*(u32 **)(p + 4))[i]);
    }
    func_020307B0(*(void **)(p + 4));
    *(u8 *)(p + 8) = 0;
    *(u32 *)(p + 4) = 0;
}
