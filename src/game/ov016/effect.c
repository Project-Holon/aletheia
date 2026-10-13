/*
 * file:     effect.c
 * unit:     yes
 * function: func_021D551C, func_021D556C, func_021D5580, func_021D55A4, func_021D566C, func_021D5790, func_021D57EC
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
 *   MemEffect                        0x021DE67C  data
 *   G2x_SetBlendBrightness_          0x0207D658  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   g_021DAA6C                       0x021DAA6C  data
 *   taskFade                         0x021D566C  arm
 *   func_0207C958 0x0207C958 arm
 *   func_0207D6C0 0x0207D6C0 arm
 *   func_021D7724 0x021D7724 arm ov016
 *   g_021DAA68 0x021DAA68 data
 *   g_021DAA64 0x021DAA64 data
 *   DWCi_TSKlDelete                  0x021D7724  arm
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

extern void *func_021D6414(unsigned long size, int alignment);
extern void func_0207D658(u32_021D551C addr, int plane, int brightness);
extern void func_021D6438(void **mem);
extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);
extern long func_0207C958(long a, long b);
extern void func_0207D6C0(u32_021D55A4 addr, int brightness);
extern void func_021D7724(int kind, void *task);
extern void DWCi_TSKlDelete(int kind, void *task);
void func_021D551C(void);
void func_021D556C(void);
bool DWCi_EFFlCheck(int lcd);
bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
void func_021D566C(void *task, void *work);
bool DWCi_EFFlWait(int frame);
extern struct MEMEFFECT *MemEffect;
extern S4 g_021DAA6C;
extern U4 g_021DAA68;
extern S4 g_021DAA64;




/*
 * Allocate a 0x18-byte block, publish it, and clear two 0x1000-wide register spans.
 * Addresses are Black-image addresses.
 */
void func_021D551C(void)
{
    unsigned short *p;

    *(int *)0x021DE67C = (int)func_021D6414(0x18, 4);
    p = (unsigned short *)0x04000050;
    func_0207D658((u32_021D551C)p, 0x3f, 0x10);
    func_0207D658((u32_021D551C)(p + 0x800), 0x3f, 0x10);
}




/*
 * Tail-call func_021D6438 with the address of 0x021DE67C.
 * Addresses are Black-image addresses.
 */
void func_021D556C(void)
{
    func_021D6438((void *)0x021DE67C);
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




static void taskFade(void *task, void *work);




bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame)
{
    S4 BRIGHT = g_021DAA6C;
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
void func_021D566C(void *task, void *work)
{
    U4 TABLE = g_021DAA68;
    S4 BRIGHT = g_021DAA64;
    struct EFFPRM *prm = work;
    int value;

    prm->count++;
    value = func_0207C958(prm->count * 16, prm->max);
    if (TABLE.b[prm->index] & 1)
        value = 16 - value;
    if (TABLE.b[prm->index] & 0x10)
        value = -value;
    if (prm == &MemEffect->param[0])
        func_0207D6C0(0x04001050, value);
    else
        func_0207D6C0(0x04000050, value);
    if (prm->count < prm->max)
        return;
    if (prm == &MemEffect->param[0])
        func_0207D6C0(0x04001050, BRIGHT.b[prm->index]);
    else
        func_0207D6C0(0x04000050, BRIGHT.b[prm->index]);
    prm->active = 0;
    func_021D7724(1, task);
}



static void taskWait(void *task, void *work);



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
