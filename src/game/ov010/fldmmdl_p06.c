/*
 * file:     fldmmdl_p06.c
 * unit:     yes
 * function: func_0216CC40, func_0216CC58, func_0216CCB0, func_0216CCCC
 * address:  0x0216CC40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02030734  0x02030734  arm
 *   func_0216E280  0x0216E280  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 *   func_0216E290  0x0216E290  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 */
#include "../../matched/include/Obj04949.h"
#include "../../matched/include/Obj12056.h"

struct Big;
struct Ctx;
struct Rec94;
typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void *func_0216E280(int a0, int a1);
extern int func_0216E290();
extern int func_020307B0();
void MI_CpuFill8(void *dst, u8 val, u32 size);
void func_0216CC40(void *a);
char *func_0216CC58(int a, int b, int c);
int func_0216CCB0(int a0);
void func_0216CCCC(Obj *o);
extern char d_02172B48[];

/*
 * extent: zero alignment halfword at 0x0216CC56, then labelled 0x0216CC58.
 * interface: r1=0x34 is visibly supplied to the accessor despite its body only reading r0.
 */
void func_0216CC40(void *a) {
    *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(a)),0x34)=1;
}


char *func_0216CC58(int a, int b, int c)
{
    char *p = (char *)func_02030734(a, 0x48, 1, d_02172B48, 0xc3);
    ((struct Obj04949 *)p)->f18 = (int)func_02030734(a, b << 8, 1, d_02172B48, 0xc4);
    ((struct Obj04949 *)p)->f4 = b;
    ((struct Obj04949 *)p)->f8 = a;
    ((struct Obj04949 *)p)->f2C = c;
    ((struct Obj04949 *)p)->fC = 0x80;
    func_0216E280((int)p, a);
    ((struct Obj04949 *)p)->f44 = (int)func_02030734(a, 0xc4 << 2, 1, d_02172B48, 0xcf);
    return p;
}


int func_0216CCB0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216E290(a0);
loc_0216CCB8:
a0 = ((struct Obj12056 *)t4)->f44;
    a0 = func_020307B0(a0);
loc_0216CCBE:
a0 = ((struct Obj12056 *)t4)->f18;
    a0 = func_020307B0(a0);
loc_0216CCC4:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0216CCCA:
    return a0;}


/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * clears the 0x310-byte buffer at +0x44, a tail call through a pool word.
 * Callee of ov020 func_021857C0.
 */
void func_0216CCCC(Obj *o)
{
    MI_CpuFill8(o->f44, 0, 0x310);
}
