/*
 * file:     unit_021D551C_p02.c
 * unit:     yes
 * function: func_021D55A4, func_021D566C
 * address:  0x021D55A4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   G2x_SetBlendBrightness_          0x0207D658  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   g_021DAA6C                       0x021DAA6C  data
 *   MemEffect                        0x021DE67C  data
 *   taskFade                         0x021D566C  arm
 *   func_0207C958 0x0207C958 arm
 *   func_0207D6C0 0x0207D6C0 arm
 *   func_021D7724 0x021D7724 arm ov016
 *   g_021DAA68 0x021DAA68 data
 *   g_021DAA64 0x021DAA64 data
 *   g_021DE67C 0x021DE67C data
 */
#include "../../matched/include/G_MEMEFFECT.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef short s16;

typedef _Bool bool;

typedef struct { s8 b[4]; } S4;

struct tagEFFPRM {
    void *task;
    s16 conut;
    u16 frame;
    u8 kind;
    bool flag;
};

struct tagMEMEFFECT {
    struct tagEFFPRM param[2];
};

typedef unsigned long u32;

typedef struct {
    char pad0[4];
    s16 count;
    u16 max;
    u8 index;
    u8 active;
} Prm;

typedef struct { u8 b[4]; } U4;

extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);
extern long func_0207C958(long a, long b);
extern void func_0207D6C0(u32 addr, int brightness);
extern void func_021D7724(int kind, void *task);
bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
void func_021D566C(void *task, void *work);
extern struct tagMEMEFFECT *MemEffect;
extern S4 g_021DAA6C;
extern U4 g_021DAA68;
extern S4 g_021DAA64;
extern struct MEMEFFECT *g_021DE67C;


static void taskFade(void *task, void *work);


bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame)
{
    S4 BRIGHT = g_021DAA6C;
    struct tagEFFPRM *prm;
    bool ok;

    if (lcd == 1)
        prm = &MemEffect->param[0];
    else
        prm = &MemEffect->param[1];
    if (prm->flag)
        return 0;
    if (lcd == 1)
        G2x_SetBlendBrightness_(0x04001050, plane, BRIGHT.b[kind]);
    else
        G2x_SetBlendBrightness_(0x04000050, plane, BRIGHT.b[kind]);
    ok = 1;
    prm->task = DWCi_TSKlForm(ok, taskFade, prm, 0xc8);
    prm->conut = 0;
    prm->kind = kind;
    prm->frame = frame;
    prm->flag = ok;
    return ok;
}


/*
 * sdk:      taskFade (libdwcutil.TWL.HYB.a(effect.o))
 */
void func_021D566C(void *task, void *work)
{
    U4 TABLE = g_021DAA68;
    S4 BRIGHT = g_021DAA64;
    Prm *prm = (Prm *)work;
    int value;

    prm->count++;
    value = func_0207C958(prm->count * 16, prm->max);
    if (TABLE.b[prm->index] & 1)
        value = 16 - value;
    if (TABLE.b[prm->index] & 0x10)
        value = -value;
    if (prm == ((Prm *)g_021DE67C))
        func_0207D6C0(0x04001050, value);
    else
        func_0207D6C0(0x04000050, value);
    if (prm->count < prm->max)
        return;
    if (prm == ((Prm *)g_021DE67C))
        func_0207D6C0(0x04001050, BRIGHT.b[prm->index]);
    else
        func_0207D6C0(0x04000050, BRIGHT.b[prm->index]);
    prm->active = 0;
    func_021D7724(1, task);
}
