/*
 * function: func_021E5098
 * address: 0x021E5098
 * packet: pkt_ov119_021E5098
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initial guard is a forward goto, with the exit after the body.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021E8530 0x021E8530 data a4
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 */
#include "../include/Obj00001.h"
#include "../include/Obj22808.h"
typedef unsigned short u16;
extern char d_021E8530[];
extern void *func_02030734(unsigned heapId, unsigned size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern unsigned int POKE_TOOL_GetGraphicIndex(void *mon);
typedef unsigned int   u32;
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082D44(void *, const void *, int);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021E5098(char *p, int b)
{
    int i, n, x, t, out;
    void *a;
    if (b == 0) *(int *)&((struct Obj00001 *)p)->f1184 = (int)func_02030734(((struct Obj00001 *)p)->f5F4, 0x5ac00, 0, d_021E8530, 0x50b);
    a = func_020490F4(7, ((struct Obj00001 *)p)->f5F4);
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = (int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828), b, i, p);
            if (x) x = POKE_TOOL_GetGraphicIndex((void *)x);
            else x = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
            t = (int)ARC_UTIL_LoadBgCharDataFromHandle(a, x, 0, (u32)(&out), ((struct Obj00001 *)p)->f5F4);
            func_02082D44(((struct Obj22808 *)out)->f14, (void *)(*(int *)&((struct Obj00001 *)p)->f1184 + n * 512), 512);
            n++;
            func_020307B0((void *)t);
        }
    }
    goto done;
check:
    if (b < 25) goto body;
done:
    ARC_TOOL_DeleteHandle(a);
}
