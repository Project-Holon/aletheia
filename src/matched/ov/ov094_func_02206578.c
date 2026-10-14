/*
 * function: BTLV_INPUT_SetSelection
 * address:  0x02206578
 * packet:   pkt_ov094_02206578
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetCont  0x0203630C  arm
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 *   BTLV_INPUT_ButtonFlashTaskMain  0x0220663C  thumb  ov094
 *   BTLV_INPUT_ButtonFlashTaskEnd  0x02206710  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data   ov094
 */
#include "../include/Obj00823.h"
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned int lo : 31;
    unsigned int top : 1;
} Top;

typedef struct {
    char *s;
    int f4;
    int f8;
    int fc;
} Ctx;

extern unsigned int KEY_GetCont(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);
extern void BTLV_INPUT_ButtonFlashTaskMain(void);
extern void BTLV_INPUT_ButtonFlashTaskEnd(void *h);
extern char d_0220AEB0[];

int BTLV_INPUT_SetSelection(char *s, int a, int b)
{
    Ctx *c;
    int flag;

    if (b < 0)
        return a;
    if ((KEY_GetCont() & 0x200) && a < 4 && (((struct Obj00823 *)s)->f58 == 2 || ((struct Obj00823 *)s)->f58 == 5))
        ((struct Obj00823 *)s)->f70 = a | 0x8000;
    else
        ((struct Obj00823 *)s)->f70 = a;
    c = func_02030734((u16)((((struct Obj00823 *)s)->f240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0x1440);
    flag = 0;
    if ((0x10000 & b) == 0)
        flag = 1;
    ((Top *)(s + 0x68))->top = flag;
    c->s = s;
    c->f4 = 0;
    c->f8 = (u16)b;
    if (((struct Obj00823 *)s)->f220 == 1 && c->f8 == 0)
        c->fc = 1;
    else
        c->fc = 0;
    BTLV_INPUT_RegisterTask(s, (int)func_02030DA8(((struct Obj00823 *)s)->f0, (void *)BTLV_INPUT_ButtonFlashTaskMain, c, 0), (int)((void *)BTLV_INPUT_ButtonFlashTaskEnd));
    return -1;
}
