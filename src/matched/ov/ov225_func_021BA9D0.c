/*
 * function: func_021BA9D0
 * address: 0x021BA9D0
 * packet: pkt_ov225_021BA9D0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: 020414AC original supplies r0=5; retain the visible input despite its void legacy list.
 * argument: 02061CA4 third input is p+4c, represented as void * rather than own u32 payload; integer cast CSE adds r5.
 * symbols:
 *   func_020414AC 0x020414AC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02061CA4 0x02061CA4 arm
 *   func_021BB088 0x021BB088 thumb ov225
 *   func_020355C4 0x020355C4 arm
 *   func_021BB034 0x021BB034 thumb ov225
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 */
#include "../include/Obj00074.h"
#include "../include/Obj26197.h"
#include "../include/Obj26198.h"
#include "../include/Obj26199.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct R;
struct Obj;
extern void func_020414AC(unsigned);
extern struct R *APP_TASKMENU_RES_Create(u16, u16, unsigned, unsigned, u16);
extern int func_02061CA4(void *, unsigned, void *, int);
extern void func_021BB088(char *);
extern u8 func_020355C4(void);
extern u16 func_021BB034(u16 **);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *, unsigned);
void func_021BA9D0(char *p)
{
    func_020414AC(5);
    *(struct R * *)&((struct Obj00074 *)p)->f8 = APP_TASKMENU_RES_Create(5, 4, ((struct Obj26197 *)(*(char * *)&((struct Obj00074 *)p)->f4))->fC, ((struct Obj26198 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f14, ((struct Obj26199 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    ((struct Obj00074 *)p)->f4C = 0x1ce7;
    func_02061CA4((void *)31, 154, p + 0x4c, 2);
    func_02061CA4((void *)31, 186, p + 0x4c, 2);
    func_021BB088(p);
    if (func_020355C4() == 0) {
        APP_TASKMENU_WIN_SetActive(*(struct Obj **)(p + func_021BB034((u16 **)p) * 4 + 0xc), 1);
        ((struct Obj00074 *)p)->f8C = 0;
    }
}
