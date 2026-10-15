/*
 * function: TRCARD_SYS_Exit
 * address:  0x0216F1E0
 * packet:   pkt_0216F1E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 72 compiled 70
 *
 * symbols:
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008554  0x02008554  thumb
 *   GAME_BEACON_SetTrainerView  0x02027174  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */
#include "../include/Obj07206.h"
#include "../include/Obj07207.h"
#include "../include/Obj09171.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int GAME_BEACON_SetTrainerView();
extern int func_020307B0();
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);

int TRCARD_SYS_Exit(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    u8 *p;

t5 = a2 + 0;
t6 = a0 + 0;
a0 = ((struct Obj09171 *)t5)->f8;
t4 = a3 + 0;
    if (a0 == 0) goto loc_0216F202;
loc_0216F1EE:
a0 = ((struct Obj09171 *)t5)->f4;
    p = GAME_DATA_GetMyStatus((void *)a0);
loc_0216F1F4:
    a0 = func_02008554((const struct Sub0200852CObj *)p);
loc_0216F1F8:
a1 = ((struct Obj07207 *)t4)->f1C;
    if (a1 == a0) goto loc_0216F202;
loc_0216F1FE:
    a0 = GAME_BEACON_SetTrainerView(a0);
loc_0216F202:
a0 = ((struct Obj07207 *)t4)->f18;
a0 = ((struct Obj07206 *)a0)->f10;
((struct Obj09171 *)t5)->f10 = a0;
a0 = ((struct Obj07207 *)t4)->f18;
a0 = ((struct Obj07206 *)((char *)a0))->f0;
    a0 = func_020307B0(a0);
loc_0216F210:
a0 = ((struct Obj07207 *)t4)->f18;
    a0 = func_020307B0(a0);
loc_0216F216:
a0 = t6 + 0;
    func_020315D4((struct Proc *)a0);
loc_0216F21C:
a0 = 0x26;
    GFL_HEAP_DeleteChecked(a0);
loc_0216F222:
a0 = 1;
    return a0;}
