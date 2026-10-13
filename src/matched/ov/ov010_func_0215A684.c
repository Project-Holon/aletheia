/*
 * unit:     yes
 * function: SCRCMD_WORK_SetWaitCount
 * address:  0x0215A684
 * packet:   pkt_ov010_0215A684
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00005.h"

#define W(p) (*(int *)((char *)(p)))
#define S(p, o) (*(unsigned short *)((char *)(*(int *)((char *)(p) + 0x20)) + (o)))
#define I(p, o) (*(int *)((char *)(*(int *)((char *)(p) + 0x20)) + (o)))

void SCRCMD_WORK_SetWaitCount(int *p, unsigned short v)
{
    S(p, 0x106) = v;
}

int SCRCMD_WORK_CountDownWait(int *p)
{
    unsigned short *q = &S(p, 0x106);
    if (*q == 0) {
        return 1;
    }
    *q = *q - 1;
    return 0;
}

int SCRCMD_WORK_GetFadeParam(int *p)
{
    return I(p, 0x108);
}

void SCRCMD_WORK_SetFadeParam(int *p, int v)
{
    I(p, 0x108) = v;
}

int SCRCMD_WORK_GetFadeState(int *p)
{
    return I(p, 0x10c);
}

void SCRCMD_WORK_SetFadeState(int *p, int v)
{
    I(p, 0x10c) = v;
}

void SCRCMD_WORK_AddAnimeTask(int *p, int v)
{
    int i;
    char *q = (char *)*(int *)&((struct Obj00005 *)p)->f20;
    for (i = 0; i < 8; i++) {
        int *e = (int *)(q + i * 4);
        if (e[5] == 0) {
            e[5] = v;
            return;
        }
    }
}
