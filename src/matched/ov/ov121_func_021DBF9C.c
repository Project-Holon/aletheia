/*
 * function: func_021DBF9C
 * address: 0x021DBF9C
 * packet: pkt_ov121_021DBF9C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC02C 0x021DC02C thumb ov121
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021DC024(void *);
extern char *func_021DC02C(void *);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 func_02020E60(u32,u32);
int func_021DBF9C(void *p)
{
    char *q;
    switch(func_021DC024(p)) {
    case 1:
        q=func_021DC02C(p);
        return func_0201BABC(*(u16 *)(q+26),*(u8 *)(q+28),*(u8 *)(q+53),*(u8 *)(q+92));
    case 2:
        q=func_021DC02C(p);
        return func_02020E60((u16)*(u32 *)q,1);
    default: return 12;
    }
}
