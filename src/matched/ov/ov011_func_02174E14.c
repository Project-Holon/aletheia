/*
 * function: func_02174E14
 * address: 0x02174E14
 * packet: pkt_ov011_02174E14
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    u16 low : 9;
    u16 state : 6;
    u16 high : 1;
} F86;
void func_02174E14(u8 *p, int a)
{
    ((F86 *)(p + 0x86))->state = (u16)a;
    p[0x900] = 1;
}
