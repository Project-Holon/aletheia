/*
 * function: FIELD_MSGBG_SetupSysFrameBg
 * address:  0x02192EE0
 * packet:   pkt_ov021_02192EE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   d_021D3F18     0x021D3F18  data  a4
 */

typedef unsigned short u16;
typedef struct { int w[8]; } B32;

extern const B32 d_021D3F18;
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetTileEntry(int, int, int, int, int, int, int);
extern void BG_SYS_PushTile(u32 index);
extern void func_0207D63C(int, int, int, int, int);
extern void BG_SYS_SetPriority(int idx, unsigned short val);

void FIELD_MSGBG_SetupSysFrameBg(int a)
{
    B32 tmp;

    func_02040588(2, 0);
    if (a == 1) {
        tmp = d_021D3F18;
        BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&tmp), 0);
    } else {
        *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & 0x43) | 0x1F10;
    }
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    BG_SYS_SetPriority(2, 2);
    func_02040588(2, 1);
}
