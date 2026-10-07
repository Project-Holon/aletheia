/*
 * file:     script_command_p06.c
 * unit:     yes
 * function: func_021FB808, func_021FB8CC, func_021FB948, func_021FBA14
 * address:  0x021FB808
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   d_021FDD00 0x021FDD00 data a1
 *   func_021FAEE8 0x021FAEE8 thumb ov132
 *   func_021F8084 0x021F8084 thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 *   _u32_div_f 0x0209C2B0 arm
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_021FAE1C  0x021FAE1C  thumb  ov132
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021F8068  0x021F8068  thumb  ov112
 */
#include "../../matched/include/Obj04517.h"
#include "../../matched/include/Obj08165.h"
#include "../../matched/include/Obj03823.h"
#include "../../matched/include/Obj03824.h"
#include "../../matched/include/Obj04518.h"
#include "../../matched/include/Obj08166.h"

struct Cursor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct TaskData { void *context; int tick, duration, count; void *slot; int amplitude; void *owner; void *task; } TaskData;

typedef signed short s16;

typedef struct { int x, y, z; } Vec;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FB1F4(char *, int);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021FADA0(char *p, u32 fn, u32 arg, u32 key);
extern int func_021FAEE8(char *p);
extern void func_021F8084(void *unused, u32 *p, const u32 *q);
extern void func_021FADF8(char *p, char *q);
extern int func_021FAE1C(char *p, int *out);
extern int func_0209C0A4();
extern void func_021F8068(int self, char *p, u16 v);
int func_021FB808(int unused, char *p);
void func_021FB8CC(int unused, char *p);
int func_021FB948(int unused,char *p);
void func_021FBA14(int a0, int *a1);
extern const char d_021FDD00[];
extern const s16 d_020A1B38[];

/*
 * note: task allocation is 32 bytes; the product local reproduces count-first multiply scheduling.
 */
int func_021FB808(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char * *)&((struct Obj04517 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj04517 *)p)->f4));
    duration = func_0201134C(((struct Obj04517 *)p)->f4);
    count = func_0201134C(((struct Obj04517 *)p)->f4);
    amplitude = func_0201134C(((struct Obj04517 *)p)->f4);
    wait = func_0201134C(((struct Obj04517 *)p)->f4);
    func_021F9DA0(((struct Obj08165 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = func_02030734(((struct Obj08165 *)obj)->f0, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = func_021F9DA4(((struct Obj08165 *)obj)->f34, i);
            data->amplitude = amplitude;
            data->context = ((struct Obj08165 *)obj)->f34;
            data->tick = 0;
            data->duration = duration;
            data->count = count;
            data->task = func_021FADA0(obj, (u32)func_021FB8CC, (u32)data, 10);
        }
    }
    if (wait == 1) {
        int product;
        product = count;
        product *= duration;
        ((struct Obj04517 *)p)->f14 = product;
        return 1;
    }
    return 0;
}

void func_021FB8CC(int unused, char *p)
{
    void *ctx;
    ctx = func_021F9DA0(((struct Obj03823 *)p)->f0);
    if (func_021FAEE8(p) == 2) {
        Vec zero = { 0, 0, 0 };
        func_021F8084(ctx, ((struct Obj03823 *)p)->f10, (const u32 *)(&zero));
        func_021FADF8(((struct Obj03823 *)p)->f18, ((struct Obj03823 *)p)->f1C);
        return;
    }
    else {
        Vec v;
        int sine;
        v.x = 0;
        sine = d_020A1B38[((int)(((u32)((struct Obj03823 *)p)->f4 << 15) / (u32)((struct Obj03823 *)p)->f8) >> 4) * 2];
        v.y = -(int)(((long long)sine * ((struct Obj03823 *)p)->f14 + 0x800) >> 12);
        v.z = 0;
        func_021F8084(ctx, ((struct Obj03823 *)p)->f10, (const u32 *)(&v));
    }
}

int func_021FB948(int unused,char *p)
{
    char *owner,*q;
    int mask;
    u32 rate,start,delta,wait;
    u8 i;
    owner=*(char * *)&((struct Obj04518 *)p)->f0;
    mask=func_021FB1F4(p,func_0201134C(((struct Obj04518 *)p)->f4));
    rate=func_0201134C(((struct Obj04518 *)p)->f4);
    start=func_0201134C(((struct Obj04518 *)p)->f4);
    delta=func_0201134C(((struct Obj04518 *)p)->f4);
    wait=func_0201134C(((struct Obj04518 *)p)->f4);
    func_021F9DA0(((struct Obj08166 *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            q=func_02030734(((struct Obj08166 *)owner)->f0,36,0,d_021FDD00,0x493);
            *(char * *)&((struct Obj03824 *)q)->f1C=owner;
            ((struct Obj03824 *)q)->f18=func_021F9DA4(((struct Obj08166 *)owner)->f34,i);
            ((struct Obj03824 *)q)->f0=((struct Obj08166 *)owner)->f34;
            ((struct Obj03824 *)q)->f4=start;
            ((struct Obj03824 *)q)->f8=start+delta;
            ((struct Obj03824 *)q)->fC=rate;
            ((struct Obj03824 *)q)->fE=0;
            ((struct Obj03824 *)q)->f20=func_021FADA0(owner,(u32)func_021FBA14,(u32)q,10);
        }
    }
    if(wait==1) {((struct Obj04518 *)p)->f14=rate;return 1;}
    return 0;
}


/*
 * note:     the bl to 0x021F8068 named an unlabelled leaf in the co-resident
 *           ov112 (ov112 0x021F36C0..0x021F8480 abuts ov132 0x021F8480..);
 *           it was filed EXACT as src/matched/ov112_func_021F8068.c, so the
 *           site now attests as `matched` and every concrete byte reproduces.
 *           EXACT* only because the inferred extent runs into an unlabelled
 *           follower in ov132; there is no byte difference.
 */
void func_021FBA14(int a0, int *a1)
{
    int r4 = (int)func_021F9DA0((char *)a1[0]);
    int local;
    if (func_021FAE1C((char *)a1, &local) == 1) {
        func_021F8068(r4, (char *)a1[6], (u16)func_0209C0A4(a1[2] << 16, 0x168));
        func_021FADF8((char *)a1[7], (char *)a1[8]);
    } else {
        func_021F8068(r4, (char *)a1[6], (u16)func_0209C0A4(local << 16, 0x168));
    }
}
