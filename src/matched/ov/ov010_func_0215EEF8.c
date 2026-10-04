/*
 * function: func_0215EEF8
 * address: 0x0215EEF8
 * packet: pkt_ov010_0215EEF8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_02159058 0x02159058 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct C { u8 pad00[8]; void *f8; u16 fc; };
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern void func_02159058(int, int, int, int, u16);
int func_0215EEF8(void *p, void *unused, struct C *ctx)
{
    int h;
    int t;
    func_0201296C(func_020120F4(ctx->f8));
    h = ctx->fc;
    t = func_021587B0((int)p, 0x271c, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}
