/*
 * function: func_021F5CAC
 * address:  0x021F5CAC
 * packet:   pkt_ov107_021F5CAC
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_StartParentCore (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_02082A48  0x02082A48  arm
 *   func_021F1B3C  0x021F1B3C  arm  ov107
 *   func_021F6804  0x021F6804  arm  ov107
 *   func_021F6830  0x021F6830  arm  ov107
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F3F78  0x021F3F78  arm  ov107
 *   func_021F5BE0  0x021F5BE0  arm  ov107
 *   func_0208799C  0x0208799C  arm
 *   func_020885EC  0x020885EC  arm
 *   func_021F1D80  0x021F1D80  arm  ov107
 *   func_021F46C8  0x021F46C8  arm  ov107
 *   g_021F6F90     0x021F6F90  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern unsigned char g_021F6F90[];

extern unsigned long func_02087988(void);
extern void func_02082A48(u16 data, void *destp, u32 size);
extern void func_021F1B3C(void (*callback)(u16, u32, void *));
extern void func_021F6804(u16 childMaxSize);
extern void func_021F6830(void *buf);
extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern void func_021F3F78(void);
extern int func_021F5BE0(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_020885EC(int fifotag, int proc);
extern void func_021F1D80(u16 type, void *arg);
extern void func_021F46C8(void *arg);

#define WM   (*(u8 **)(g_021F6F90 + 0xC))
#define PBUF (*(u8 **)(g_021F6F90 + 0x10))

int func_021F5CAC(int channel)
{
    int i;
    int ret;
    void (*cb_tmp)(u16, u32, void *);
    u32 enabled;

    enabled = func_02087988();
    *(u16 *)(WM + 0x32) = channel;
    *(u32 *)(g_021F6F90 + 4) = ((u32)PBUF + 0x1f + 0x7d00) & ~0x1f;
    cb_tmp = *(void (**)(u16, u32, void *))(PBUF + 0x1000 + 0x4e4);
    func_02082A48(0, PBUF + 0x1340, 0x69c0);
    func_021F1B3C(cb_tmp);
    *(int *)(PBUF + 0x1000 + 0x318) = *(u16 *)(WM + 0x500) - 6;
    func_021F6804(*(u16 *)(WM + 0x502));
    func_021F6830(PBUF + 0x138 + 0x1400);
    ret = 0;
    for (i = 0; i < 15; i++) {
        *(int *)(PBUF + i * 4 + 0x1000 + 0x4e8) = ret;
        *(signed char *)(PBUF + i + 0x1000 + 0x526) = -1;
    }
    *(u8 *)(PBUF + 0x1000 + 0x524) = ret;
    func_02082A48(ret, PBUF + 0x388 + 0x1400, 0x5d40);
    func_02082BCC(PBUF + 0x354 + 0x1400, ret, 0x1e);
    ret = 1;
    *(u16 *)(WM + 0x500 + 0x24) = ret;
    *(void **)(WM + 0x51c) = (void *)func_021F1D80;
    *(void **)(WM + 0x508) = (void *)func_021F46C8;
    *(u16 *)(WM + 0x34) = *(u16 *)(WM + 0x500);
    *(u16 *)(WM + 0x500 + 0x18) = (*(u16 *)(WM + 0x34) + 0x23) & ~0x1f;
    *(u16 *)(WM + 0x36) = *(u16 *)(WM + 0x502);
    *(u16 *)(WM + 0x500 + 0x1a) = (((*(u16 *)(WM + 0x36) + 0xe) * 15 + 0x29) & ~0x1f) << 1;
    func_021F3F78();
    i = func_021F5BE0();
    func_0208799C(enabled);
    *(int *)(PBUF + 0x7000 + 0x4c8) = func_020885EC(0xf, ret);
    return i;
}
