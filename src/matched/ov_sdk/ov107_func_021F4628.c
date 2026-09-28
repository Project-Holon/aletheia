/*
 * function: MBi_OnInitializeDone
 * address:  0x021F4628
 * packet:   pkt_ov107_021F4628
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 *
 * symbols:
 *   WM_SetIndCallback                0x0208eac8 arm
 *   MBi_CheckWmErrcode               0x021f6334 arm
 *   WM_SetLifeTime                   0x02090dec arm
 *   MBi_ParentCallback               0x021f46c8 arm
 *   mbi_life_mp                      0x021f6e58 data
 */
typedef unsigned short u16;

struct MBiLife {
    u16 mp;
    u16 cam;
    u16 table_no;
    u16 frame;
};

extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int WM_SetIndCallback(void (*callback)(void *));
extern int WM_SetLifeTime(void (*callback)(void *), u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
extern void MBi_ParentCallback(void *arg);
extern struct MBiLife mbi_life_mp;

static void MBi_OnInitializeDone(void)
{
    MBi_CheckWmErrcode(0x80, WM_SetIndCallback(MBi_ParentCallback));
    MBi_CheckWmErrcode(0x1D, WM_SetLifeTime(MBi_ParentCallback, mbi_life_mp.table_no, mbi_life_mp.cam, mbi_life_mp.frame, mbi_life_mp.mp));
}
