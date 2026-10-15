/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov133_021B6100
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021B69AC 0x021B69AC thumb ov133
 *   func_021B6BA4 0x021B6BA4 thumb ov133
 *   func_021B6E74 0x021B6E74 thumb ov133
 *   func_021B6F00 0x021B6F00 thumb ov133
 *   func_021B9DE8 0x021B9DE8 thumb ov133
 *   func_021B9B48 0x021B9B48 thumb ov133
 *   func_021B6884 0x021B6884 thumb ov133
 *   func_020056A0 0x020056A0 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021B9028 0x021B9028 thumb ov133
 *   MUSICAL_SAVE_GetFittingSetting 0x0200A828 thumb
 *   MUSICAL_SAVE_SetFittingSetting 0x0200A834 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021BA600 0x021BA600 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021BA600[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct Big;
extern void func_021B69AC(u8 *);
extern void func_021B6BA4(u8 *);
extern void func_021B6E74(u8 *);
extern void func_021B6F00(u8 *);
extern void func_021B9DE8(u8 *);
extern void func_021B9B48(u8 *);
extern void func_021B6884(void *unused, u8 *p);
extern void *func_020056A0(void *,void *,int);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void func_021B9028(u8 *,int,u16);
struct Big;
extern u32 MUSICAL_SAVE_GetFittingSetting(struct Big *p);
extern void MUSICAL_SAVE_SetFittingSetting(struct Big *p, u8 value);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
u8 *func_021B6100(u8 *parent, int heap)
{
    u8 *p = func_02030734(heap, 0x18f0, 1, d_021BA600, 0x1de);
    u32 t, m;
    *(u16 *)p = heap;
    *(u8 **)(p + 4) = parent;
    *(u32 *)(p + 0xc) = 7;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x18) = 0;
    *(u32 *)(p + 0x30) = 0;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x3c) = 0;
    *(u32 *)(p + 0x40) = 0;
    *(u32 *)(p + 0x98) = 0;
    *(u32 *)(p + 0xa4) = 8;
    *(u16 *)(p + 0x182c) = 0;
    *(u16 *)(p + 0x1838) = 0;
    *(u16 *)(p + 0x183a) = 0;
    *(u32 *)(p + 0x183c) = 0;
    *(u8 *)(p + 0x18c6) = 0;
    *(u32 *)(p + 0x18c8) = 0;
    *(u32 *)(p + 0x18d0) = 0;
    *(u32 *)(p + 0x18cc) = 0;
    *(u16 *)(p + 0x18d4) = 0xff;
    *(u8 *)(p + 0x18c1) = 0;
    *(u32 *)(p + 0x1834) = 0;
    *(u32 *)(p + 0x18ec) = 0;
    *(u16 *)(p + 0x182e) = 0;
    *(u32 *)(p + 0x34) = 10;
    func_021B69AC(p);
    func_021B6BA4(p);
    func_021B6E74(p);
    func_021B6F00(p);
    func_021B9DE8(p);
    func_021B9B48(p);
    *(void **)(p + 8) = func_020056A0((void *)func_021B6884, p, 8);
    WIPE_SYS_Start((void *)2, 1, 1, 0x7fff, 18, 1, *(u16 *)p);
    t = *(u32 *)(p + 0x1834) + 0x18000;
    *(u16 *)(p + 0x18c2) = 10;
    m = *(u16 *)(p + 0xa8) * 0x1249;
    {
        u16 x;
        if (t >= m)
            x = (t - m) / 0x1249;
        else
            x = t / 0x1249;
        func_021B9028(p, 8, x);
    }
    *(u32 *)(p + 0xa4) = 8;
    *(u32 *)(p + 0x98) = 1;
    *(u32 *)(p + 0x9c) = 0;
    *(u32 *)(p + 0xa0) = *(u16 *)(p + 0x182c) % 0x1249 + 0x10000;
    if (MUSICAL_SAVE_GetFittingSetting((struct Big *)(*(u32 *)(*(u8 **)(p + 4) + 8))) == 0) {
        MUSICAL_SAVE_SetFittingSetting((struct Big *)(*(u32 *)(*(u8 **)(p + 4) + 8)), 1);
        *(u32 *)(p + 0x1840) = 1;
    } else {
        *(u32 *)(p + 0x1840) = 0;
    }
    GFL_USE_CancelChangeAndPlayBgm(0x454, 0xffff);
    GFL_NET_RestartWithDefaultTimeout(0, *(u16 *)p);
    return p;
}
