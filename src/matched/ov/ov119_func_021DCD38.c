/*
 * function: func_021DCD38
 * address: 0x021DCD38
 * packet: pkt_ov119_021DCD38
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_STATUS_IsLocked 0x020275DC thumb
 *   func_021DD90C 0x021DD90C thumb ov119
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021D8A50 0x021D8A50 thumb ov119
 *   func_021DF868 0x021DF868 thumb ov119
 *   func_0204A600 0x0204A600 arm
 *   func_02027974 0x02027974 thumb
 *   func_02028178 0x02028178 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021DF978 0x021DF978 thumb ov119
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   func_021E31B4 0x021E31B4 thumb ov119
 *   func_02047970 0x02047970 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb ov009
 *   GFL_NET_IsNetTypeWifi 0x0203D29C arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_0200FB38 0x0200FB38 thumb
 *   func_021DC818 0x021DC818 thumb ov119
 *   func_0202223C 0x0202223C thumb
 */
typedef unsigned char u8;
typedef unsigned u32;
typedef struct Bits {u8 low:4,high:4;} Bits;
struct Light;
struct McssSys;
struct Tcbl;
extern int BEACON_STATUS_IsLocked(void);
extern int func_021D8A24(void *);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void func_021DD90C(u8 *p, int i, int msg, int force);
extern void func_021D9468(void *,int,void *);
extern void func_021D8A50(void *);
extern void func_021DF868(void *);
extern void func_0204A600(void),func_02027974(void *),func_02028178(u8 *);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned short u16;
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *);
extern void func_0201DD78(u32,u32,u32);
extern void func_020310C4(struct Tcbl *p);
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021DF978(void *);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *sys);
extern void func_021E31B4(void *);
extern void func_02047970(void);
extern void func_0200F7C0(unsigned);
extern void func_021B9774(u8 *);
extern void func_021B9838(u8 *);
extern void DWC_RAP_SetErrorCallback(int,int);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void func_0200FB38(void);
extern void func_021DC818(char *);
extern void func_0202223C(unsigned,unsigned);
#define I(o) (*(int *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
#define B(o) (*(u8 *)(p+(o)))
int func_021DCD38(int a,int b,int c,char *p)
{
    int result=1;
    void (*callback)(char *)=*(void (**)(char *))(p+0x5ec);
    int i;
    u8 rgb[3];
    if(BEACON_STATUS_IsLocked()) return 0;
    if(callback) {
        callback(p);
        I(0xf2c)++;
        result=0;
        for(i=0;i<2;i++) func_021DD90C((u8 *)p,i,*(u8 *)(p+i+0x11e8),0);
    }
    if(I(0xf9c) && B(0x11f3)==0) {
        func_021D9468(p,1,*(void **)(p+(I(0xf9c)-1)*4+0x5dc));I(0xf9c)=0;
    }
    func_021D8A50(p);func_021DF868(p);func_0204A600();
    if(P(0x64c)) func_02027974(P(0x64c));
    if(P(0x648)) func_02028178(P(0x648));
    if(((Bits *)(p+0x11fb))->high) {
        if(func_0203D3A8((struct Entry *)((unsigned)func_020399A8()),0xc17,0,0)) ((Bits *)(p+0x11fb))->high=0;
    }
    if(P(0x744)) {
        GF_FONT_GetTextColor(&rgb[2],&rgb[1],&rgb[0]);
        func_0201DD78(1,2,15);
        func_020310C4(P(0x744));
        func_0201DD78(rgb[2],rgb[1],rgb[0]);
        func_0201C4E4(P(0x740));
    }
    func_021DF978(p);func_02047964();func_02048AD0(P(0x810));func_020479D8();
    MCSS_Main(P(0x840));MCSS_Draw(P(0x840));func_021E31B4(p);func_02047970();
    if(func_021D8A24(p) && I(0xef8)==0 && func_0200FB24()) {
        if(B(0x11f7)) func_0200F7C0(41);
        if(P(0)) {
            func_021B9774(P(0));func_021B9838(P(0));P(0)=0;
            DWC_RAP_SetErrorCallback(0,0);DWC_RAPCOMMON_DestroySubHeap();
        }
        if(GFL_NET_IsNetTypeWifi()) DWC_RAPCOMMON_HandleNetError(1,1);
        else if(I(0x118c)!=1) func_0200FB38();
        *(int *)((char *)P(8)+8)=2;
        func_021DC818(p);
        result=1;
        func_0202223C(0,0);func_0202223C(1,0);
    }
    return result;
}
