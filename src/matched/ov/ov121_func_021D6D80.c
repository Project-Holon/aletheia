/*
 * function: func_021D6D80
 * address: 0x021D6D80
 * packet: pkt_ov121_021D6D80
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6DB4 0x021D6DB4 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D9F08(u8 *,int,int,int);
extern void func_021D81B0(u8 *,u32,int);
extern void func_021DA8B0(void *,void *);
extern void func_021D6DB4(void *,int *);
void func_021D6D80(void *a,int b,u8 *p)
{
    func_021D9F08(*(u8 **)(p+0x284),*(int *)(p+0x3a4),79,0);
    func_021D81B0(p,0,29);
    func_021DA8B0(a,func_021D6DB4);
}
