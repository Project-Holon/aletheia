/*
 * function: BR_RES_ApplyBgSet
 * address: 0x021FBDA4
 * packet: pkt_ov186_021FBDA4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 index);
void BR_RES_ApplyBgSet(int a,unsigned mode)
{
    switch(mode){
    case 24:
        func_020414EC(2);func_020409B4(2);
        func_020414EC(5);func_020409B4(5);break;
    case 0:func_020414EC(3);func_020409B4(3);break;
    case 1:func_020414EC(6);func_020409B4(6);break;
    case 2:func_020414EC(0);func_020409B4(0);break;
    case 5:case 9:case 15:case 20:case 21:case 22:case 23:case 26:case 27:case 28:case 29:case 30:
        func_020414EC(5);func_020409B4(5);break;
    case 3:case 4:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 16:case 17:case 18:case 19:case 25:
        func_020414EC(2);func_020409B4(2);break;
    case 14:break;
    }
}
