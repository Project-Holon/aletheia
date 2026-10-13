/*
 * function: STARTMENU_NewGameIntroInit
 * address:  0x021BC12C
 * packet:   pkt_ov088_021BC12C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov194 id is held in a local (the original keeps it in r7 across the
 * copy loop and reuses it for the unload); the ov204 id is spelled
 * directly and reloaded from the pool for each call.
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   SAVE_CONTROL_INTR_Create  0x021BD25C  thumb  ov088
 *   func_02007220  0x02007220  thumb
 *   MYSTATUS_Create  0x0200846C  thumb
 *   CONFIG_Create  0x020082EC  thumb
 *   NAMEIN_SETUP_CreateArgs  0x0216BFD4  thumb  ov010
 *   PROCSYS_Create  0x02031324  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_USE_LoadWaveArcSet  0x02005A98  thumb
 *   PM_VOICE_Prepare  0x020069D4  thumb
 *   ov194_id       0x000000C2  data
 *   ov204_id       0x000000CC  data
 *   d_021F557C     0x021F557C  data  ov194  a4
 *   d_021F558C     0x021F558C  data  ov194  a4
 *   d_021BFD20     0x021BFD20  data  ov204  a4
 *   d_021BFD30     0x021BFD30  data  ov204  a4
 */
#include "../include/Obj00964.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Sub02005A98Hdr;
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
extern struct Sub02007084Ctrl *func_020070A4(void);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *SAVE_CONTROL_INTR_Create(int a, int b);
extern void *func_02007220(struct Sub020071E4Ctrl *ctrl);
extern void *MYSTATUS_Create(int a0);
extern void *CONFIG_Create(int a0);
extern int *NAMEIN_SETUP_CreateArgs(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
extern void *PROCSYS_Create(int a0);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int handle);
extern struct Sub02005A98Hdr *GFL_USE_LoadWaveArcSet(const u32 *a0, u32 a1);
extern int PM_VOICE_Prepare(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern u8 ov194_id[];
extern u8 ov204_id[];
extern u32 d_021F557C;
extern u32 d_021F558C[];
extern u32 d_021BFD20;
extern u32 d_021BFD30[];

int STARTMENU_NewGameIntroInit(struct Obj0203159C *a0)
{
    u32 buf[30];
    void *sys;
    char *w;
    u32 n1, n2, i;
    u32 r;
    void *id;

    sys = func_020070A4();
    w = PROCSYS_AllocProcWork(a0, 0x5c, 1);
    ((struct Obj00964 *)w)->f2C = (u32)SAVE_CONTROL_INTR_Create(1, (int)sys);
    func_02007220(sys);
    ((struct Obj00964 *)w)->f54 = (u32)MYSTATUS_Create(1);
    ((struct Obj00964 *)w)->f58 = (u32)CONFIG_Create(1);
    ((struct Obj00964 *)w)->f0 = 0;
    ((struct Obj00964 *)w)->f4 = ((struct Obj00964 *)w)->f58;
    ((struct Obj00964 *)w)->f8 = ((struct Obj00964 *)w)->f54;
    ((struct Obj00964 *)w)->f28 = (u32)NAMEIN_SETUP_CreateArgs(1, 0, 0, 0, 7, 0, 0);
    ((struct Obj00964 *)w)->f30 = (unsigned int)PROCSYS_Create(1);

    id = ov194_id;
    func_02034AC4((int)id);
    n1 = d_021F557C;
    for (i = 0; i < n1; i++)
        buf[i] = d_021F558C[i];
    func_02034A5C((int)id);

    func_02034AC4((int)ov204_id);
    n2 = d_021BFD20;
    for (i = 0; i < n2; i++)
        buf[n1 + i] = d_021BFD30[i];
    func_02034A5C((int)ov204_id);

    ((struct Obj00964 *)w)->f34 = (u32)GFL_USE_LoadWaveArcSet(buf, n1 + n2);
    r = PM_VOICE_Prepare(0x23c, 0, 0x40, 0, 0, 0, 0, 0);
    ((struct Obj00964 *)w)->f50 = r;
    ((struct Obj00964 *)w)->f10 = ((struct Obj00964 *)w)->f54;
    ((struct Obj00964 *)w)->f14 = ((struct Obj00964 *)w)->f58;
    ((struct Obj00964 *)w)->f18 = 1;
    ((struct Obj00964 *)w)->f1C = ((struct Obj00964 *)w)->f2C;
    ((struct Obj00964 *)w)->f20 = r;
    return 1;
}
