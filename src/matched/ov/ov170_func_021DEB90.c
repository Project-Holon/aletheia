/*
 * function: func_021DEB90
 * address: 0x021DEB90
 * packet: pkt_ov170_021DEB90
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: Original truncates the tile column into r2 before both call kinds, so their column parameters are u8.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`data=(u32)sheet;` before `data=(u32)sheet+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT in
 * --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_02049EB4 0x02049EB4 arm
 *   func_02041090 0x02041090 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02041300 0x02041300 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02049EB4(u32,u32,u32,u32,u16);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_020307B0(void *);
extern void func_02041300(u32,int,u8,int,u8,u8,u8);
void func_021DEB90(void *unused, void *unused2, int x, u32 base, u32 pal)
{
    u8 *sheet;
    void *handle;
    u16 value;
    u32 data;
    u8 row,yn;
    u16 *src;
    u32 cur,high;
    u8 col;
    handle=func_02049EB4(116,13,1,(u32)&sheet,76);
    data=(u32)sheet+12;
    row=0;
    high=pal<<12;
    do{
        src=(u16 *)data+row*21;
        cur=x;
        col=0;
        yn=row+1;
        do{
            value=(src[col]&4095)+high+base;
            func_02041090(3,(u32)&value,(u8)cur,yn,1,1);
            ++cur;if(cur>=64)cur=0;
            ++col;
        }while(col<21);
        ++row;
    }while(row<20);
    func_020307B0(handle);
    func_02041300(3,0xe287,cur,0,2,20,17);
    func_02041300(3,0xe2b0,cur,5,2,1,17);
}
