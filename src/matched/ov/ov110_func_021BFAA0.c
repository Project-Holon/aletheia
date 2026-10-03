/*
 * function: func_021BFAA0
 * address: 0x021BFAA0
 * packet: pkt_ov110_021BFAA0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: outside window inline binds its masked load and plane OR in one
 *   initializer; splitting tmp and tmp |= wnd folds constants differently.
 * volatile: 0x021BFAD0 WININ, 0x021BFAF2 DISPCNT, 0x021BFB00 WINOUT,
 *   0x021BFB1E DISPCNT reads.
 * symbols:
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_0207D63C 0x0207D63C arm
 *   func_02040588 0x02040588 arm
 *   func_021BC868 0x021BC868 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef enum { FALSE, TRUE } BOOL;
typedef enum { PLANE_NONE=0, PLANE_ALL=31 } Plane;
typedef enum { WINDOW_NONE=0, WINDOW_0=1, WINDOW_1=2, WINDOW_OBJ=4 } Window;
extern void func_021BAD2C(u8 *,int);
extern void func_0207D63C(void *,int,int,int,int);
typedef unsigned int   u32;
extern void func_02040588(u32 which, u32 enable);
extern void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
static inline void inside(Plane wnd,BOOL effect) {
    unsigned tmp=(*(volatile u16 *)0x04000048 & ~0x3f00) | ((unsigned)wnd<<8);
    if(effect) tmp|=0x2000;
    *(volatile u16 *)0x04000048=tmp;
}
static inline void outside(Plane wnd,BOOL effect) {
    unsigned tmp=(*(volatile u16 *)0x0400004a & ~0x3f) | (unsigned)wnd;
    if(effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=tmp;
}
static inline void wndpos(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04000042=(x1<<8)|x2;
    *(volatile u16 *)0x04000046=(y1<<8)|y2;
}
static inline void visible(Window wnd) {
    *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0xe000) | (wnd<<13);
}
void func_021BFAA0(u8 *p) {
    func_021BAD2C(*(u8 **)p,1);
    func_0207D63C((void *)0x04000050,4,63,0,16);
    func_02040588(2,1);
    inside(31,1);
    *(u8 *)(p+0x8c)=*(volatile u8 *)0x0400004a;
    *(unsigned *)(p+0x90)=(*(volatile unsigned *)0x04000000 & 0xe000)>>13;
    outside(27,1);
    wndpos(0,0,255,168);
    visible(2);
    *(unsigned *)(p+0x88)=0;
    func_021BC868(p+0x4c,4,63,0,124,12);
}
