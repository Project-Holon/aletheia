/*
 * function: func_021C87B0
 * address: 0x021C87B0
 * packet: pkt_ov128_021C87B0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021C8808, 021C8814 read WINOUT; 021C8828 reads DISPCNT.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   d_021CA6C8 0x021CA6C8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Point {s16 x,y;} Point;
typedef struct Entry {s16 x,y; s16 rest[3];} Entry;
extern const Entry d_021CA6C8[];
extern void func_0204B3DC(void *,u32);
extern void func_0204B878(void *,u16);
extern void func_0204B9A0(void *);
extern void func_0204B92C(void *,int);
extern void func_0204B404(void *,const Point *,u32);
extern void func_020061E4(int);
static inline void Outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400004A & ~0x3F) | wnd;
    if(effect) tmp |= 0x20;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}
void func_021C87B0(u8 *p)
{
    Point pos;
    func_0204B3DC(*(void **)(p + 0x1a0),1);
    func_0204B878(*(void **)(p + 0x1a0),1);
    func_0204B9A0(*(void **)(p + 0x1a0));
    *(int *)(p + 0x1a8)=0;
    func_0204B92C(*(void **)(p + 0x1a0),1);
    pos.x=d_021CA6C8[*(s16 *)(p + 4)].x * 8;
    pos.y=d_021CA6C8[*(s16 *)(p + 4)].y * 8 - 4;
    func_0204B404(*(void **)(p + 0x1a0),&pos,0);
    *(volatile u16 *)0x0400004A=(u16)((*(volatile u16 *)0x0400004A & ~0x3F00) | 0x700);
    Outside(31,1);
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0xe000) | 0x8000;
    func_020061E4(0x668);
}
