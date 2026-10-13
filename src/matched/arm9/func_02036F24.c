/*
 * function: GFL_NET_WM_ICON_LoadGraphics
 * address:  0x02036F24
 * packet:   pkt_02036F24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0200F168   0x0200F168  thumb
 *   func_0200F16C   0x0200F16C  thumb
 *   func_020490F4   0x020490F4  arm
 *   func_02049B68   0x02049B68  arm
 *   GFL_NET_WM_ICON_GetCharOffset   0x02036F04  arm
 *   func_02049800   0x02049800  arm
 *   func_02049238   0x02049238  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0200F168(void);
struct Sub0200F16CHdr;
extern void func_0200F16C(struct Sub0200F16CHdr *hdr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a0, u32 a1, void *a2, int a3, int a4, int a5);
extern int GFL_NET_WM_ICON_GetCharOffset(int a0);
extern void func_02049800(void *a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void func_02049238(void *a0);

void GFL_NET_WM_ICON_LoadGraphics(int a0, int b, int c)
{
    u32 t[3];
    int q;
    int p;
    void *v;
    int idx;
    int t2;

    v = func_020490F4(func_0200F168(), (u16)((c & 0x7fff) | 0x8000));
    func_0200F16C((struct Sub0200F16CHdr *)t);
    if (a0 == 1) {
        p = 1;
        q = 0;
    } else {
        p = 5;
        q = 1;
    }
    func_02049B68(v, t[2], (void *)p, 0x1c0, 0x20, c);
    idx = (b == 0) ? 1 : 0;
    t2 = GFL_NET_WM_ICON_GetCharOffset(a0);
    func_02049800(v, t[idx], q, t2, 0, 0, c);
    func_02049238(v);
}
