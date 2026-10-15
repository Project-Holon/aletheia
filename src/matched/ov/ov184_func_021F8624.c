/*
 * function: func_021F8624
 * address:  0x021F8624
 * packet:   pkt_021F8624
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: every concrete byte reproduces; 0x021FE7B0 and 0x021FD744 lie
 *   outside ov184's 0x5A0-byte region and no listing labels them, so the
 *   two calls stay wildcarded.
 *
 * symbols:
 *   BR_FADE_Start   0x021FE784  thumb
 *   BR_FADE_GetResult   0x021FE7B0  thumb
 *   func_021FD744   0x021FD744  thumb
 *   BR_PROC_SYS_PopEntry   0x021F9BA0  thumb
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   release the two child handles on 2.
 */
#include "../include/Obj08318.h"


extern int BR_FADE_Start(int, int, int, int);
extern int BR_FADE_GetResult(int);
extern void func_021FD744(int);
extern void BR_PROC_SYS_PopEntry(int);

void func_021F8624(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start(*(int *)(((struct Obj08318 *)p)->f30), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(*(int *)(((struct Obj08318 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD744(((struct Obj08318 *)p)->fC);
        BR_PROC_SYS_PopEntry(*(int *)(((struct Obj08318 *)p)->f30 + 0x10));
        break;
    }
}
