/*
 * function: func_021D683C
 * address: 0x021D683C
 * packet: pkt_ov125_021D683C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7700 0x021D7700 thumb ov125
 *   func_021D730C 0x021D730C thumb ov125
 *   func_021D7154 0x021D7154 thumb ov125
 *   func_021D71CC 0x021D71CC thumb ov125
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb  arm9
 */
#include "../include/Obj06472.h"
#include "../include/Obj22996.h"
typedef unsigned short u16;
extern char *func_021D7700(void);
typedef unsigned int   u32;
struct ObjC4;
extern int func_021D730C(char *p);
extern void BATTLE_REC_GetModeLayout(u16, int *, int *);
extern int func_021D7154(int, int, int *, int *);
extern void func_021D71CC(const void *src, void *dst, u32 n);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern void func_02082D44(void *, const void *, unsigned int);
int func_021D683C(char *p, void *dst)
{
    char *r;
    char *out;
    char *base;
    int outer, inner;
    int n, m;
    int i;
    r = func_021D7700();
    if (!func_021D730C(p)) return 0;
    BATTLE_REC_GetModeLayout(((struct Obj22996 *)r)->fA6, &n, &m);
    base = r + 0xd00;
    out = p + 0x498;
    for (i = 0; i < 12; i++) {
        if (!func_021D7154((int)p, i, &outer, &inner)) break;
        func_021D71CC(base + outer * 676 + inner * 112 + 50, out + i * 22, 11);
    }
    ((struct Obj06472 *)p)->f5A0 = 0;
    p[0x403] = 0;
    *(char * *)&((struct Obj06472 *)p)->f174 = r;
    func_02082D44(dst, BATTLE_REC_GetWork(), 128);
    p[0x401] = 60;
    ((struct Obj06472 *)p)->f3D8 = 0x55f0;
    return 1;
}
