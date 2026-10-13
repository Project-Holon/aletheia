/*
 * function: func_021DF7F0
 * address: 0x021DF7F0
 * packet: pkt_ov119_021DF7F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021E67C4 0x021E67C4 thumb ov119
 *   func_021DF8A0 0x021DF8A0 thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
typedef unsigned short u16;

extern int func_021D8AA8(void *);
typedef unsigned int   u32;
struct Entry;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void func_021E67C4(void *,int);
extern void func_021DF8A0(void *,int,int);
extern int func_021D8A24(void *);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
void func_021DF7F0(void *p)
{
    unsigned x,y;
    unsigned char slot;
    if (!func_021D8AA8(p)) return;
    if (!TOUCHPANEL_GetPointTrg(&x,&y)) return;
    if(x<8 || x>=104 || y<144 || y>=168) return;
    slot=(x-8)/24U;
    if(slot>=4) slot=3;
    func_021E67C4(p,slot);
    func_021DF8A0(p,slot,0);
    if(func_021D8A24(p)) GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc0d,1,(u32)(&slot));
}
