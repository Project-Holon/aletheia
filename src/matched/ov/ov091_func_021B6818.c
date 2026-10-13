/*
 * function: POKELIST_ExitWork
 * address:  0x021B6818
 * packet:   pkt_ov091_021B6818
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   PLIST_MENU_DeleteTaskMenuWin  0x021BBE44  thumb  ov091
 *   PLIST_MENU_Delete  0x021BBAE0  thumb  ov091
 *   PLIST_MESSAGE_Destroy  0x021BB5FC  thumb  ov091
 *   BMP_WIN_Delete  0x020452E8  arm
 *   PLIST_PLATE_Delete  0x021BA890  thumb  ov091
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   POKELIST_DeleteFonts  0x021B7268  thumb  ov091
 *   PLIST_MENU_ExitTimer  0x021BCD80  thumb  ov091
 *   POKELIST_DeleteClactUnit  0x021B71B0  thumb  ov091
 *   POKELIST_FreeGraphics  0x021B7624  thumb  ov091
 *   POKELIST_ShutdownDisplay  0x021B6FEC  thumb  ov091
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct Node;
struct TaskMenuState;
extern void func_02030EAC(struct Node *n);
extern int POKELIST_IsItemMode(u32 p);
extern void PLIST_MENU_DeleteTaskMenuWin(int x);
extern void PLIST_MENU_Delete(int a, unsigned char *b);
extern void PLIST_MESSAGE_Destroy(void *a, int *s);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PLIST_PLATE_Delete(void *ignored, u8 *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void POKELIST_DeleteFonts(unsigned p);
extern void PLIST_MENU_ExitTimer(char *a);
extern void POKELIST_DeleteClactUnit(unsigned p);
extern void POKELIST_FreeGraphics(char *p);
extern void POKELIST_ShutdownDisplay(int a);
extern void func_020355D8(int a);

#define W(o) (*(int *)(p + (o)))

int POKELIST_ExitWork(u8 *p)
{
    u8 i;

    func_02030EAC((struct Node *)W(4));
    if (POKELIST_IsItemMode((u32)p) == 1) {
        PLIST_MENU_DeleteTaskMenuWin(W(0x108));
        PLIST_MENU_DeleteTaskMenuWin(W(0x10c));
        W(0x108) = 0;
        W(0x10c) = 0;
    }
    PLIST_MENU_Delete((int)p, (unsigned char *)W(0x154));
    PLIST_MESSAGE_Destroy(p, (int *)W(0x150));
    if (W(0x130) != 0)
        BMP_WIN_Delete((struct Descriptor *)W(0x130));
    for (i = 0; i < 6; i++)
        PLIST_PLATE_Delete(p, (u8 *)(((int *)(p + 0x160))[i]));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)W(0x254));
    POKELIST_DeleteFonts((unsigned int)p);
    if (POKELIST_IsItemMode((u32)p) == 1)
        PLIST_MENU_ExitTimer((char *)p);
    POKELIST_DeleteClactUnit((unsigned int)p);
    POKELIST_FreeGraphics((char *)p);
    POKELIST_ShutdownDisplay((int)p);
    if (W(0x18) == 1)
        *(int *)(W(0x280) + 0x34) = 0x18;
    if (W(0x1c) == 1)
        *(int *)(W(0x280) + 0x34) = 0x19;
    if (W(0x20) == 1)
        *(int *)(W(0x280) + 0x34) = 0x1a;
    func_020355D8(W(8));
    return 1;
}
