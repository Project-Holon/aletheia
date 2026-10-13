/*
 * file:     effect.c
 * unit:     yes
 * function: DWCi_EFFlInit, DWCi_EFFlEnd, DWCi_EFFlCheck, DWCi_EFFlFade, taskFade, DWCi_EFFlWait, DWCi_EffectTaskWait
 * address:  0x021D551C
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
 *   DWCi_HEAPlAllocEx              0x021D6414  arm  ov016
 *   DWCi_HEAPlFree_                0x021D6438  arm  ov016
 *   MemEffect                        0x021DE67C  data
 *   G2x_SetBlendBrightness_          0x0207D658  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   sEffectTable3                       0x021DAA6C  data
 *   taskFade                         0x021D566C  arm
 *   FX_DivS32 0x0207C958 arm
 *   DWCi_WindowG2x_ChangeBlendBrightness_ 0x0207D6C0 arm
 *   DWCi_TSKlDelete 0x021D7724 arm ov016
 *   sEffectTable2 0x021DAA68 data
 *   sEffectTable1 0x021DAA64 data
 */
typedef unsigned int   u32_021D551C;

typedef _Bool bool;

struct EFFPRM {
    void *task;                 /* +0x00 */
    short count;                /* +0x04 */
    unsigned short max;         /* +0x06 */
    unsigned char index;        /* +0x08 */
    bool active;                /* +0x09 */
    char pad[2];
};

struct MEMEFFECT {
    struct EFFPRM param[2];
};

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef short s16;

typedef struct { s8 b[4]; } S4;

typedef unsigned long u32_021D55A4;

typedef struct { u8 b[4]; } U4;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);
extern long FX_DivS32(long a, long b);
extern void DWCi_WindowG2x_ChangeBlendBrightness_(u32_021D55A4 addr, int brightness);
extern void DWCi_TSKlDelete(int kind, void *task);
void DWCi_EFFlInit(void);
void DWCi_EFFlEnd(void);
bool DWCi_EFFlCheck(int lcd);
bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
bool DWCi_EFFlWait(int frame);
extern struct MEMEFFECT *MemEffect;
extern S4 sEffectTable3;
extern U4 sEffectTable2;
extern S4 sEffectTable1;


/*
 * Allocate a 0x18-byte block, publish it, and clear two 0x1000-wide register spans.
 * Addresses are Black-image addresses.
 */

static void taskFade(void *task, void *work);
static void taskWait(void *task, void *work);
void DWCi_EFFlInit(void)
{
    unsigned short *p;

    *(int *)0x021DE67C = (int)DWCi_HEAPlAllocEx(0x18, 4);
    p = (unsigned short *)0x04000050;
    G2x_SetBlendBrightness_((u32_021D551C)p, 0x3f, 0x10);
    G2x_SetBlendBrightness_((u32_021D551C)(p + 0x800), 0x3f, 0x10);
}


/*
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE67C.
 * Addresses are Black-image addresses.
 */
void DWCi_EFFlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE67C);
}


bool DWCi_EFFlCheck(int lcd)
{
    struct EFFPRM *p;

    if (lcd == 1)
        p = &MemEffect->param[0];
    else
        p = &MemEffect->param[1];
    return p->active;
}


bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame)
{
    S4 BRIGHT = sEffectTable3;
    struct EFFPRM *prm;
    bool ok;

    if (lcd == 1)
        prm = &MemEffect->param[0];
    else
        prm = &MemEffect->param[1];
    if (prm->active)
        return 0;
    if (lcd == 1)
        G2x_SetBlendBrightness_(0x04001050, plane, BRIGHT.b[kind]);
    else
        G2x_SetBlendBrightness_(0x04000050, plane, BRIGHT.b[kind]);
    ok = 1;
    prm->task = DWCi_TSKlForm(ok, taskFade, prm, 0xc8);
    prm->count = 0;
    prm->index = kind;
    prm->max = frame;
    prm->active = ok;
    return ok;
}


/*
 * sdk:      taskFade (libdwcutil.TWL.HYB.a(effect.o))
 */
static void taskFade(void *task, void *work)
{
    U4 TABLE = sEffectTable2;
    S4 BRIGHT = sEffectTable1;
    struct EFFPRM *prm = work;
    int value;

    prm->count++;
    value = FX_DivS32(prm->count * 16, prm->max);
    if (TABLE.b[prm->index] & 1)
        value = 16 - value;
    if (TABLE.b[prm->index] & 0x10)
        value = -value;
    if (prm == &MemEffect->param[0])
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04001050, value);
    else
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04000050, value);
    if (prm->count < prm->max)
        return;
    if (prm == &MemEffect->param[0])
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04001050, BRIGHT.b[prm->index]);
    else
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04000050, BRIGHT.b[prm->index]);
    prm->active = 0;
    DWCi_TSKlDelete(1, task);
}


bool DWCi_EFFlWait(int frame)
{
    struct EFFPRM *prm = MemEffect->param;

    if (prm->active != 0)
        return 0;
    prm->task = DWCi_TSKlForm(1, taskWait, prm, 0xc8);
    prm->count = 0;
    prm->max = frame;
    prm->active = 1;
    return 1;
}


static void taskWait(void *task, void *work)
{
    struct EFFPRM *prm = work;

    prm->count++;
    if (prm->count < prm->max)
        return;
    prm->active = 0;
    DWCi_TSKlDelete(1, task);
}
