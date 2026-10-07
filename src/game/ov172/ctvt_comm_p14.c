/*
 * file:     ctvt_comm_p14.c
 * unit:     yes
 * function: func_021BA01C, func_021BA050, func_021BA094, func_021BA098, func_021BA0BC, func_021BA120
 * address:  0x021BA01C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200566C  0x0200566C  thumb
 *   func_021BA1D8  0x021BA1D8  thumb  ov172
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0208B4B8 0x0208B4B8 arm
 *   func_02072CC4 0x02072CC4 arm
 *   func_021BA1E4 0x021BA1E4 thumb ov172
 *   g_021C88EC 0x021C88EC data a4
 *   func_02082A7C 0x02082A7C arm
 *   func_0208B500 0x0208B500 arm
 *   func_0208B528 0x0208B528 arm
 */
#include "../../matched/include/Obj04554.h"
#include "../../matched/include/Obj08260.h"

struct O;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef enum MICResult { MIC_SUCCESS, MIC_BUSY, MIC_ILLEGAL, MIC_SEND_ERROR } MICResult;

typedef struct MICAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop;
    void (*callback)(MICResult, void *);
    void *arg;
} MICAutoParam;

extern void func_0200566C(void);
extern void func_021BA1D8(void *p);
extern unsigned int func_0208BEF0(unsigned int status);
extern void func_0203D7FC(void *p);
extern u32 func_020307B0(void *p);
extern void *func_0208B4B8(void);
extern int func_02072CC4(struct O *);
extern void func_021BA1E4(void *);
extern void func_02082A7C(u32, void *, u32);
extern MICResult func_0208B500(MICAutoParam *);
extern int func_0208B528(void);
void func_021BA01C(char *p);
void func_021BA050(u32 *p);
void func_021BA094(int v);
void func_021BA098(void);
int func_021BA0BC(u32 *p);
void func_021BA114(MICResult result, void *arg);
int func_021BA120(u32 *p);
u32 func_021BA158(u32 *p);
u32 func_021BA15C(u32 *p);
u32 func_021BA170(u32 *p);
extern void *g_021C88EC;


void func_021BA01C(char *p)
{
    func_0200566C();
    *(u32 *)0x021C88EC = 0;
    func_021BA120((u32 *)p);
    func_021BA1D8(p);
    func_0208BEF0(0);
    func_0203D7FC(((struct Obj04554 *)p)->f4);
    func_020307B0(p);
}

void func_021BA050(u32 *p)
{
    u32 n;
    if (p[2] == 1) {
        n = (u32)func_0208B4B8();
        if (n == 0) p[0] = 0;
        else {
            p[0] = n - p[1] + 4;
            if (p[0] > 51200) p[0] = 51200;
        }
    }
    if (p[3] == 1) {
        if (func_02072CC4((struct O *)p[8]) == 0) p[3] = 0;
    }
    func_021BA1E4(p);
}

void func_021BA094(int v)
{
}

void func_021BA098(void)
{
    u8 *p = g_021C88EC;
    if (((struct Obj08260 *)p)->fC == 1) (((struct Obj08260 *)p)->f14)++;
    p = g_021C88EC;
    if (p[16] < 180) p[16]++;
}

/*
 * extent: Callback at 021BA114 stores zero at r1+8 and 51200 at r1.
 */
int func_021BA0BC(u32 *p)
{
    MICAutoParam param;
    param.type = 3;
    param.size = 51200;
    param.buffer = (void *)p[1];
    func_02082A7C(0, param.buffer, param.size);
    if (param.size & 31) param.size &= ~31;
    param.callback = func_021BA114;
    param.loop = 0;
    param.rate = 4097;
    param.arg = p;
    if (func_0208B500(&param) == 0) {
        p[2] = 1;
        p[0] = 0;
        return 1;
    }
    return 0;
}

void func_021BA114(MICResult result, void *arg)
{
    u32 *p = arg;
    p[2] = 0;
    p[0] = 51200;
}

int func_021BA120(u32 *p)
{
    if (p[2] == 0) return 1;
    if (func_0208B528() == 0) {
        p[0] = (u32)func_0208B4B8() - p[1] + 4;
        if (p[0] > 51200) p[0] = 51200;
        p[2] = 0;
        return 1;
    }
    return 0;
}

u32 func_021BA158(u32 *p) { return p[2]; }

u32 func_021BA15C(u32 *p)
{
    if (p[0] > 2048) return p[0] - 2048;
    return 0;
}

u32 func_021BA170(u32 *p) { return p[1]; }
