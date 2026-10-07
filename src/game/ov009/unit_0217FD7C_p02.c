/*
 * file:     unit_0217FD7C_p02.c
 * unit:     yes
 * function: func_0218005C, func_02180080
 * address:  0x0218005C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02181DA0  0x02181DA0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021C2324  0x021C2324  arm  ov114
 */
typedef struct GSSoapTask {
    void (*callback)(int, void *, void *, void *);
    char pad4[0xc];
    void *f10;
    void *f14;
    char pad18[8];
    void *f20;
    char pad24[8];
    int result;
} GSSoapTask;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void func_02181DA0(int x);
void func_0217EAE0(void *p);
void func_021C2324(int x, int y);
void func_0218005C(void *theTask);
int func_02180080(int *p);


/*
 * sdk:      gsiSoapTaskCallback (gssoap.o)
 */
void func_0218005C(void *theTask)
{
    GSSoapTask *aSoapTask = (GSSoapTask *)theTask;
    aSoapTask->callback(aSoapTask->result, aSoapTask->f10, aSoapTask->f14, aSoapTask->f20);
}


/*
 * Destructor: releases three optional sub-objects then the object itself, and
 * always reports success.
 */
int func_02180080(int *p)
{
    if (p[5])
        func_02181DA0(p[5]);
    if (p[6])
        func_0217EAE0((void *)p[6]);
    if (p[7])
        func_021C2324(p[10], p[7]);
    func_0217EAE0((void *)((int)p));
    return 1;
}
