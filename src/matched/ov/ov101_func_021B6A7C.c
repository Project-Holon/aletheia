/*
 * function: func_021B6A7C
 * address: 0x021B6A7C
 * packet: pkt_ov101_021B6A7C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6C20 0x021B6C20 thumb ov101
 *   func_021B6A3C 0x021B6A3C thumb ov101
 *   func_021B6AD8 0x021B6AD8 thumb ov101
 *   func_021B6BA8 0x021B6BA8 thumb ov101
 *   func_021B6A60 0x021B6A60 thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B6C20(int *p, int index, int heap, int arg);
extern void func_021B6A3C(u8 *,u32);
extern void func_021B6AD8(u8 *p, u16 *state);
extern void func_021B6BA8(u8 *p, u16 *state);
extern void func_021B6A60(u8 *p, u16 *state);
void func_021B6A7C(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        if(func_021B6C20((int *)(p+4),0,58,(int)p)) *state=1;
        break;
    case 1:
        switch(*(int *)(p+0x20)) {
        case 0: func_021B6A3C(p,(u32)func_021B6AD8); break;
        case 1: func_021B6A3C(p,(u32)func_021B6BA8); break;
        case 2: func_021B6A3C(p,(u32)func_021B6A60); break;
        }
        break;
    }
}
