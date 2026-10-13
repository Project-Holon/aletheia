/*
 * function: func_02212560
 * address: 0x02212560
 * packet: pkt_ov199_02212560
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: case 1 precedes case 0 to preserve the backward shared assignment.
 * ABI exception: 3159C legacy void callee leaves allocator pointer in r0;
 * caller immediately uses this result as its workspace.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02082D44 0x02082D44 arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   BATTLE_REC_AllocWork 0x0200B400 thumb
 *   func_0221336C 0x0221336C thumb ov199
 *   func_022136E4 0x022136E4 thumb ov199
 *   func_02213808 0x02213808 thumb ov199
 *   func_02012934 0x02012934 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 *   d_02213C58 0x02213C58 data a4 ov199
 */
#include "../include/Obj01177.h"
#include "../include/Obj25291.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Party;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, unsigned);
extern void func_02082D44(const void *, void *, unsigned);
extern void *GAME_DATA_Create(u16);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void BATTLE_REC_AllocWork(unsigned);
extern void func_0221336C(char *, int);
extern void *func_022136E4(void *, void *, void *, int);
extern void func_02213808(char *p, int value);
extern void *func_02012934(const struct BigObj *p);
extern int POKE_REGULATION_GetDataSize(void);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern u32 func_020307B0(void *p);
extern const char d_02213D00[];
extern const unsigned d_02213C58[];
int func_02212560(void *a, int unused, u8 *arg)
{
    u8 *p;
    void *v;
    u8 *dst;
    unsigned kind;
    switch (((struct Obj25291 *)arg)->f8) {
    case 1: kind = 1; break;
    case 0: kind = 1; break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    GFL_HEAP_CreateChildHeap(kind, 0x56, 0x8000);
    p = PROCSYS_AllocProcWork(a, 0x8b0, 0x56);
    MI_CpuFill8(p, 0, 0x8b0);
    func_02082D44(arg, p + 4, 0x14);
    ((struct Obj01177 *)p)->f20 = 0;
    if (((struct Obj01177 *)p)->f4 == 0) {
        ((struct Obj01177 *)p)->f4 = GAME_DATA_Create(1);
        ((struct Obj01177 *)p)->f0 = 1;
    }
    ((struct Obj01177 *)p)->f30 = POKEPARTY_Create(0x56);
    ((struct Obj01177 *)p)->f34 = POKEPARTY_Create(0x56);
    ((struct Obj01177 *)p)->f38 = POKEPARTY_Create(0x56);
    ((struct Obj01177 *)p)->f3C = POKEPARTY_Create(0x56);
    BATTLE_REC_AllocWork(0x56);
    func_0221336C((char *)p, 0x56);
    ((struct Obj01177 *)p)->f18 = func_022136E4((void *)d_02213C58, (void *)9, p, 0x56);
    switch (((struct Obj01177 *)p)->fC) {
    case 0:
        ((struct Obj01177 *)p)->f1C = 0;
        func_02213808(((struct Obj01177 *)p)->f18, 0);
        break;
    case 1:
        ((struct Obj01177 *)p)->f1C = 2;
        func_02213808(((struct Obj01177 *)p)->f18, 4);
        break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    dst = *(u8 * *)&((struct Obj01177 *)p)->f28;
    switch (((struct Obj01177 *)p)->f10) {
    case 0:
        v = func_02012934(((struct Obj01177 *)p)->f4);
        func_02082D44(v, dst + 0xd4, POKE_REGULATION_GetDataSize());
        break;
    case 1:
        v = func_0200BAF4((int)func_0200BAC8(GAME_DATA_GetSaveControl(((struct Obj01177 *)p)->f4)), 0x8056);
        func_02082D44(v, dst + 0xd4, POKE_REGULATION_GetDataSize());
        func_020307B0(v);
        break;
    }
    return 1;
}
