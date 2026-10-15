/*
 * function: MB_UTIL_MSG_SetKeyWaitFlag
 * address:  0x021F1B24
 * packet:   pkt_ov107_021F1B24
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0xC];
    void *f10;
    unsigned char pad14[0x24];
    int f38;
} Ov107Ctx;

typedef unsigned int   u32;
struct Cfg;
void BMP_WIN_MakeScreen(struct Cfg *cfg);
void BG_SYS_PushTile(u32 index);

void MB_UTIL_MSG_SetKeyWaitFlag(Ov107Ctx *p, int x)
{
    p->f38 = x;
    BMP_WIN_MakeScreen(p->f10);
    BG_SYS_PushTile(p->f02);
}
