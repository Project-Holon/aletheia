/*
 * function: func_021DDBB0
 * address: 0x021DDBB0
 * packet: pkt_ov137_021DDBB0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021E1AE8 0x021E1AE8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(void *);
typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;
struct BmpMenu;
extern const WinDat d_021E1AE8;
extern struct BmpMenu *func_0201FDA0(const WinDat *,u16,u8,u8,u16);
int func_021DDBB0(char *p,int state) {*(struct BmpMenu **)(p+232)=func_0201FDA0(&d_021E1AE8,31,11,0,114);*(int *)(p+280)=23;func_021DD924(p);return state;}
