/*
 * function: func_021C64E0
 * address:  0x021C64E0
 * packet:   pkt_ov114_021C64E0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      nhttpCleanupCallback (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   func_021C5E78  0x021C5E78  arm  ov114
 *   func_021C78DC  0x021C78DC  arm  ov114
 *   func_021C7930  0x021C7930  arm  ov114
 *   g_021D3B9C     0x021D3B9C  data
 */

typedef struct NdGlobals {
    unsigned char pad0[0x14];
    void (*f14)(void *arg);
    void *f18;
    void *f1C;
    unsigned char pad1[0x24 - 0x20];
    void (*f24)(void);
} NdGlobals;

extern void func_021C5E78(void);
extern void func_021C78DC(void);
extern void func_021C7930(void);
extern NdGlobals g_021D3B9C;

void func_021C64E0(void)
{
    func_021C5E78();
    func_021C78DC();
    func_021C7930();
    g_021D3B9C.f14(g_021D3B9C.f18);
    g_021D3B9C.f14(g_021D3B9C.f1C);
    g_021D3B9C.f24();
}
