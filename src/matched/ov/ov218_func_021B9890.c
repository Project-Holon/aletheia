/*
 * function: func_021B9890
 * address: 0x021B9890
 * packet: pkt_ov218_021B9890
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct S S;
extern void TOUCHBAR_Update(struct S *p);
void func_021B9890(S *p)
{
    TOUCHBAR_Update(p);
}
