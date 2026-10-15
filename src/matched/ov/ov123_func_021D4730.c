/*
 * function: GSYNC_MENU_DeleteButtonWindows
 * address: 0x021D4730
 * packet: pkt_ov123_021D4730
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero padding at 0x021D4776; next function starts 0x021D4778.
 * symbols:
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 */
extern void BUTTON_MAN_Delete(void *);
typedef unsigned int   u32;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
typedef struct {
    char pad00[0x10];
    void *f10[4];
    void *f20;
    char pad24[0x238];
    int f25c;
} Object;
void GSYNC_MENU_DeleteButtonWindows(Object *p)
{
    int i;
    if (p->f20)
        BUTTON_MAN_Delete(p->f20);
    p->f20 = 0;
    for (i = 0; i < 4; i++) {
        if (p->f10[i]) {
            BMP_WIN_ClearScreen(p->f10[i]);
            func_02041B6C(5);
            BMP_MENUWORK_DrawWindowBorder(p->f10[i], 2);
            BMP_WIN_Delete(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    p->f25c = 0;
}
