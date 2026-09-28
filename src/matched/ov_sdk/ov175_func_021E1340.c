/*
 * function: func_021E1340
 * address:  0x021E1340
 * packet:   pkt_ov175_021E1340
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GdbShutdown (dwc_gdb.o)
 *
 * symbols:
 *   func_021E17D8  0x021E17D8  arm  ov175
 *   func_021E13BC  0x021E13BC  arm  ov175
 *   func_021BF57C  0x021BF57C  arm  ov114
 *   func_021DD250  0x021DD250  arm  ov175
 *   func_021E191C  0x021E191C  arm  ov175
 *   g_021E5334     0x021E5334  data
 *   g_021E4594     0x021E4594  data
 *   g_021E45A8     0x021E45A8  data
 */

typedef struct {
    int unk0;
    void *sake;
    int state;
} Tbl;
extern Tbl g_021E5334;
extern char g_021E4594[];
extern char g_021E45A8[];
extern void func_021E17D8(int line, char *fmt, ...);
extern void func_021E13BC(void);
extern int func_021BF57C(void);
extern void func_021DD250(void *sake);
extern void func_021E191C(void);

int func_021E1340(void)
{
    if (g_021E5334.state == 0) {
        func_021E17D8(0x1a6, g_021E4594);
        return 0x13;
    }
    if (g_021E5334.state == 2) {
        func_021E17D8(0x1ab, g_021E45A8);
        return 0x14;
    }
    func_021E13BC();
    g_021E5334.state = 0;
    func_021BF57C();
    func_021DD250(g_021E5334.sake);
    func_021E191C();
    return 0;
}
