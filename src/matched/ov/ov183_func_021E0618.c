/*
 * function: BR_CODEIN_ProfileScreenMain
 * address: 0x021E0618
 * packet: pkt_ov183_021E0618
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E06CE alignment padding.
 * symbols:
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_CODEIN_ProfileUpdate 0x021E0754 thumb ov183
 *   BR_CODEIN_ProfileGetState 0x021E075C thumb ov183
 *   BR_CODEIN_ProfileGetValue 0x021E0764 thumb ov183
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 */
#include "../include/Obj04576.h"
typedef unsigned long long u64;
extern void BR_FADE_Start(int, int, int, int);
extern int BR_FADE_GetResult(int *);
typedef unsigned int   u32;
struct PrintSys;
extern void BR_CODEIN_ProfileUpdate(char *p);
extern int BR_CODEIN_ProfileGetState(char *p);
extern unsigned long long BR_CODEIN_ProfileGetValue(char *p);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern void BR_PROC_SYS_PushEntry(unsigned *ctx, unsigned index);
extern void BR_UTIL_FlushWindow(void *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BR_UTIL_RunHandles(char *p);
int BR_CODEIN_ProfileScreenMain(int unused, int *state, int *q, int *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start(q[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((int *)q[0])) *state = 2;
        break;
    case 2:
        BR_CODEIN_ProfileUpdate((char *)p[1]);
        switch (BR_CODEIN_ProfileGetState((char *)p[1])) {
        case 1: BR_PROC_SYS_PopEntry((unsigned int *)q[3]); *state = 3; break;
        case 2: ((struct Obj04576 *)q)->f10 = BR_CODEIN_ProfileGetValue((char *)p[1]); BR_PROC_SYS_PushEntry((unsigned int *)q[3], 2); *state = 3; break;
        }
        break;
    case 3:
        BR_FADE_Start(q[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (BR_FADE_GetResult((int *)q[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (p[2]) BR_UTIL_FlushWindow((void *)p[2]);
    PRINTSYS_QUE_Main((struct PrintSys *)p[3]);
    BR_UTIL_RunHandles((char *)p[5]);
    return 0;
}
