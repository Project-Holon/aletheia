/*
 * function: func_021E2A98
 * address: 0x021E2A98
 * packet: pkt_ov119_021E2A98
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: WININ re-read at 021E2A9E and 021E2AB6; WINOUT and DISPCNT hardware read-modify-write, WIN0/1 positions hardware stores.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;
#define WININ (*(volatile u16 *)0x04001048)
#define WINOUT (*(volatile u16 *)0x0400104a)
#define DISPCNT (*(volatile u32 *)0x04001000)
static inline void W1Inside(int wnd,BOOL effect) {
    u32 tmp=(WININ & ~0x3f00)|((u32)wnd<<8);
    if(effect) tmp|=0x2000;
    WININ=(u16)tmp;
}
static inline void W0Inside(int wnd,BOOL effect) {
    u32 tmp=(WININ & ~0x3f)|((u32)wnd);
    if(effect) tmp|=0x20;
    WININ=(u16)tmp;
}
static inline void Outside(int wnd,BOOL effect) {
    u32 tmp=(WINOUT & ~0x3f)|((u32)wnd);
    if(effect) tmp|=0x20;
    WINOUT=(u16)tmp;
}
static inline void Position1(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001042=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001046=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}
static inline void Position0(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}
static inline void Visible(int window) {DISPCNT=(DISPCNT&~0xe000)|(window<<13);}
struct Node;
extern void func_02030EAC(struct Node *n);
void func_021E2A98(void *a,char *p) {
    W1Inside(0x10,0);
    Position1(0x30,0,0xd0,0x20);
    W0Inside(0x11,0);
    Position0(0xe0,0xa9,0xff,0xc0);
    Outside(0x1f,1);
    Visible(3);
    p[0x11f9]=0;
    func_02030EAC(a);
}
