/*
 * function: INTRUDE_COMM_VIEW_SetupBackgrounds
 * address: 0x021D424C
 * packet: pkt_ov122_021D424C
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D5780 0x021D5780 data a4
 *   d_021D57A0 0x021D57A0 data a4
 *   d_021D57C0 0x021D57C0 data a4
 *   d_021D57E0 0x021D57E0 data a4
 *   d_021D5800 0x021D5800 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Config { u32 w[8]; } Config;
extern const Config d_021D5780, d_021D57A0, d_021D57C0, d_021D57E0, d_021D5800;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
void INTRUDE_COMM_VIEW_SetupBackgrounds(void *a0)
{
    Config a, b, c, d, e;
    a = d_021D5780;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&a), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b = d_021D57A0;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&b), 0);
    func_02040588(4, 1);
    func_020409B4(4);
    c = d_021D57C0;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&c), 0);
    BG_SYS_Init(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    d = d_021D57E0;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&d), 0);
    func_02040588(6, 1);
    func_020409B4(6);
    e = d_021D5800;
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&e), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}
