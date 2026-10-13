/*
 * function: func_021FA12C
 * address: 0x021FA12C
 * packet: pkt_ov094_021FA12C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: arm9 PARTICLE_SetupSystemNoHandlers filed as src/matched/arm9/PARTICLE_SetupSystemNoHandlers.c.
 * witness: func_021FC9F4 filed as src/matched/ov/ov094_func_021FC9F4.c.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   VM_SetWait 0x020113D0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_CreateSystem 0x02050C30 arm
 *   PARTICLE_SetupSystemNoHandlers 0x02051380 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD15C 0x021FD15C thumb ov094
 *   func_021FD19C 0x021FD19C thumb ov094
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE9BC 0x021FE9BC thumb ov094
 *   func_021FC9F4 0x021FC9F4 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { char *state; void *emitter; void *resource; } Callback;
extern char d_0220AE68[];
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void VM_SetWait(char *p, int val);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
extern void PARTICLE_SetupSystemNoHandlers(void *, void *);
extern void *func_020056A0(void (*)(void), void *, int);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD15C(char *, unsigned int, int *);
extern void func_021FD19C(char *p, int i, char *q);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE9BC(void);
extern void func_021FC9F4(void);

int func_021FA12C(void *a, char *s)
{
    int slot;
    int key;
    void *buffer;
    void *resource;
    Callback *cb;
    int line;

    key = func_021FE38C(s, VM_GetU32(a));
    if (func_021FD15C(s, key, &slot) == 1) {
        line = 0x715;
        buffer = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x4800, 0, d_0220AE68, line);
        resource = (void *)PARTICLE_LoadArchiveMember(6, key, (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
        if (buffer != 0 && resource != 0) {
            *(void **)(s + 12 + slot * 4) = PARTICLE_CreateSystem((u32)buffer, 0x4800, 0, 5, 6, 0x36, (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
            if (*(void **)(s + 12 + slot * 4) != 0) {
                PARTICLE_SetupSystemNoHandlers(*(void **)(s + 12 + slot * 4), resource);
                line += 10;
                cb = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 12, 0, d_0220AE68, line);
                cb->state = s;
                cb->emitter = *(void **)(s + 12 + slot * 4);
                cb->resource = resource;
                ((struct Obj00325 *)s)->f0 |= 0x10000;
                func_021F896C(func_020056A0(func_021FE9BC, cb, 0), 0, 1);
                VM_SetWait(a, (int)func_021FC9F4);
                func_021FD19C(s, slot, resource);
            }
        }
        if (*(void **)(s + 12 + slot * 4) == 0) {
            if (buffer != 0)
                func_020307B0(buffer);
            if (resource != 0)
                func_020307B0(resource);
            *(int *)(s + 0x4c + slot * 4) = -1;
        }
    }
    return 1;
}
