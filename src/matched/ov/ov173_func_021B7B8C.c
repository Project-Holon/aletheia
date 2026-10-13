/*
 * function: func_021B7B8C
 * address: 0x021B7B8C
 * packet: pkt_ov173_021B7B8C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   k_83 0x00000083 data a1
 *   func_021B6460 0x021B6460 thumb ov173
 *   func_021B7438 0x021B7438 thumb ov173
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 */
#include "../include/Obj02217.h"
#include "../include/Obj10670.h"
#include "../include/Obj24187.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6460(char *);
extern u16 func_021B7438(char **);
struct Ctx;
struct IcaAnime;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern char gPokeStatusProcData[];
extern char k_83[];
int func_021B7B8C(char *p)
{
    char *q;
    u32 zero;
    func_021B6460(p);
    q = *(char * *)&((struct Obj02217 *)p)->f0;
    ((struct Obj02217 *)p)->f180 = ((struct Obj10670 *)q)->f0;
    ((struct Obj02217 *)p)->f184 = ((struct Obj10670 *)q)->f8;
    ((struct Obj02217 *)p)->f188 = GAMESYSTEM_GetGameData(((struct Obj10670 *)q)->fC);
    zero = 0;
    ((struct Obj02217 *)p)->f18C = zero;
    ((struct Obj02217 *)p)->f18F = zero;
    ((struct Obj02217 *)p)->f18E = 1;
    ((struct Obj02217 *)p)->f194 = func_021B7438((char **)p);
    ((struct Obj02217 *)p)->f18D = 2;
    ((struct Obj02217 *)p)->f190 = zero;
    ((struct Obj02217 *)p)->f198 = zero;
    GAMESYSTEM_CallProc(((struct Obj24187 *)(*(char * *)&((struct Obj02217 *)p)->f0))->fC, (u32)k_83, gPokeStatusProcData, p + 0x180);
    return 12;
}
