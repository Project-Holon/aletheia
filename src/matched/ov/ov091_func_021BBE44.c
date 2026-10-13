/*
 * unit:     yes
 * function: func_021BBE44, func_021BBE50, func_021BBE5C
 * address:  0x021BBE44
 * packet:   pkt_021BBE44
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three null-guarded wrappers, each into an ARM9 routine.
 *
 * symbols:
 *   func_02028148  0x02028148  thumb
 *   func_02028178  0x02028178  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void func_02028148(u8 *p);
extern void func_02028178(u8 *p);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);

void func_021BBE44(int x)
{
    if (x != 0)
        func_02028148((u8 *)x);
}

void func_021BBE50(int x)
{
    if (x != 0)
        func_02028178((u8 *)x);
}

void func_021BBE5C(int x, int f)
{
    if (x != 0)
        APP_TASKMENU_WIN_SetActive((struct Obj *)x, f);
}
