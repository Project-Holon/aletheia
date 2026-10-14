/*
 * function: WORLDTRADE_DEPOSIT_CreateSpeciesMenuList
 * address: 0x021F875C
 * packet: pkt_ov135_021F875C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 arrays at 0xEF0 and 0xF04 preserve base/index load scheduling; raw offset casts differ by 8 bytes.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   WORLDTRADE_DEPOSIT_CreateSpeciesMenu 0x021F86A8 thumb ov135
 *   d_02202ED8 0x02202ED8 data a4
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 */
#include "../include/Obj06512.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0xEF0]; u16 a[10]; u16 b[10]; } Work;
typedef struct { u32 w[4]; u16 count, rows; u32 rest[8]; } Menu;
extern const Menu d_02202ED8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag);
extern void func_0201F73C(void *win, int a, int b, int c);
struct Obj;
struct Src;
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(Work *p, void **menu, void *win, void *endmsg, void *msg, u8 *cfg, void *bag)
{
    int kind;
    int count;
    Menu src;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    kind = ((struct Obj06512 *)cfg)->f6 + ((struct Obj06512 *)cfg)->f4;
    count = WORLDTRADE_DEPOSIT_CreateSpeciesMenu(menu, msg, endmsg, *(u16 * *)&((struct Obj06512 *)cfg)->f18, ((struct Obj06512 *)cfg)->f14, ((struct Obj06512 *)cfg)->f1C, kind, bag);
    src = d_02202ED8;
    src.count = count;
    src.w[0] = (u32)*menu;
    src.w[3] = (u32)win;
    func_0201F73C(win, 0, 31, 11);
    return BMP_MENULIST_Create((struct Src *)(&src), p->a[kind], p->b[kind], 0x48);
}
