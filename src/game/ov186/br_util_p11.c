/*
 * file:     br_util_p11.c
 * unit:     yes
 * function: func_021FE2F8, func_021FE3B4, func_021FE3E4, func_021FE444, func_021FE478, func_021FE4D8, func_021FE54C, func_021FE6C0, func_021FE734, func_021FE768, func_021FE784
 * address:  0x021FE2F8
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02082BCC 0x02082BCC arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207C768 0x0207C768 arm
 *   func_02030734 0x02030734 arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   d_02200D6C 0x02200D6C data a1
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021FE794  0x021FE794  thumb  ov186
 */
#include "../../matched/include/Obj01284.h"
#include "../../matched/include/Obj10797.h"
#include "../../matched/include/Obj02904.h"
#include "../../matched/include/Obj06634.h"

struct Obj02021EE4;
struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Pair_021FE3B4{int x,y;} Pair_021FE3B4;

typedef struct {int x,y;} Pair_021FE444;

typedef struct { int x, y; } Pair_021FE478;

typedef struct {long x,y,z;} VecFx32;

typedef struct {
    int  f0;
    char pad8[8];
    char at_c[0x10];
    int  f1c;
} S;

extern void func_02082BCC(void *,int,int);
extern long func_0207CBD0(const VecFx32 *);
extern u32 func_0207C768(u32,u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02021518(unsigned);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_020215A0(struct PalAnmSlot *,u32);
extern void func_02021540(void *);
extern void func_020307B0(void *);
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
int func_021FE2F8(char *p, int *out, int step);
int func_021FE3B4(u8 *p,const Pair_021FE3B4 *origin,u16 a,u16 b,int duration);
int func_021FE3E4(char *p, int *out, int step);
void func_021FE444(int *p,const Pair_021FE444 *a,const Pair_021FE444 *b,int c,int d);
int func_021FE478(int *p, Pair_021FE478 *out, int step);
void func_021FE4D8(int *p, int a, const int *values, int duration);
int func_021FE54C(char *p,int *out);
int *func_021FE6C0(unsigned heap);
void func_021FE734(char *p);
void func_021FE768(S *p);
void func_021FE784(int a, int b, int c, int d);
extern const short d_020A1B38[];
extern const char d_02200D6C[];

int func_021FE2F8(char *p, int *out, int step)
{
    unsigned short angle_delta;
    signed char direction;
    int angle;
    int initial_angle;
    int duration;
    unsigned short initial_radius;
    int radius_delta;
    int radius, x, y;
    initial_angle = ((struct Obj01284 *)p)->f14;
    angle_delta = ((struct Obj01284 *)p)->f16 - initial_angle;
    initial_radius = ((struct Obj01284 *)p)->f10;
    radius_delta = (short)(*(short *)&((struct Obj01284 *)p)->f12 - (short)initial_radius);
    direction = radius_delta / (radius_delta < 0 ? -radius_delta : radius_delta);
    duration = ((struct Obj01284 *)p)->f18;
    angle = (unsigned short)(initial_angle + angle_delta * step / duration);
    if (radius_delta < 0) radius_delta = -radius_delta;
    radius = initial_radius + direction * (step * radius_delta / duration);
    if (radius < 0) radius = 0;
    x = (d_020A1B38[(angle >> 4) * 2 + 1] * radius) >> 12;
    y = (d_020A1B38[(angle >> 4) * 2] * radius) >> 12;
    x += ((struct Obj01284 *)p)->f0;
    y += ((struct Obj01284 *)p)->f4;
    ((struct Obj01284 *)p)->f8 = x;
    ((struct Obj01284 *)p)->fC = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == ((struct Obj01284 *)p)->f18;
}

/*
 * lever: The two-word origin copy is a Pair assignment; separate field stores reorder it.
 */
int func_021FE3B4(u8 *p,const Pair_021FE3B4 *origin,u16 a,u16 b,int duration)
{
    func_02082BCC(p,0,24);
    *(Pair_021FE3B4 *)p=*origin;
    ((struct Obj10797 *)p)->f14=duration;
    ((struct Obj10797 *)p)->f10=a;
    ((struct Obj10797 *)p)->f12=b;
    return func_021FE3E4((char *)p,0,0);
}

#pragma opt_common_subs off

/*
 * note: pass 2 2026-10-06 P2L30: EXACT (c and c99). The twin shape of
 *   ov186_func_021FE2F8 (x, y products, then x += f0, y += f4, then the two
 *   stores) gives the original tail; with common subexpressions on, the
 *   front end turns the two radius reads into one temp and hoists it to
 *   right after the angle load. #pragma opt_common_subs off keeps the read
 *   inline at its first use (between the two table reads); a named index
 *   local i = (angle >> 4) * 2 then gives the shared index the pragma no
 *   longer finds. Earlier lanes: 26 (P19 lane 5), 15 (G6L8).
 */
int func_021FE3E4(char *p, int *out, int step)
{
    int angle, i, x, y;
    angle = (unsigned short)(*(unsigned short *)(p + 0x12) + 0xFFFF * step / *(int *)(p + 0x14));
    i = (angle >> 4) * 2;
    x = (d_020A1B38[i + 1] * *(unsigned short *)(p + 0x10)) >> 12;
    y = (d_020A1B38[i] * *(unsigned short *)(p + 0x10)) >> 12;
    x += *(int *)p;
    y += *(int *)(p + 4);
    *(int *)(p + 8) = x;
    *(int *)(p + 12) = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == *(int *)(p + 0x14);
}

#pragma opt_common_subs reset

static inline void copyPair(Pair_021FE444 *dest,const Pair_021FE444 *src) { int y,x; y=src->y; x=src->x; dest->y=y; dest->x=x; }

/*
 * lever: inline pair copy loads y then x before storing; aggregate copy differed by 20 bytes, raw field stores by 23, const raw stores by 22.
 */
void func_021FE444(int *p,const Pair_021FE444 *a,const Pair_021FE444 *b,int c,int d) { func_02082BCC(p,0,0x20); copyPair((Pair_021FE444 *)p,a); copyPair((Pair_021FE444 *)(p+2),b); p[7]=d; p[6]=c; func_021FE478(p,0,0); }

int func_021FE478(int *p, Pair_021FE478 *out, int step)
{
    int done = 0;
    int progress = step - p[6];
    if (progress < 0)
        progress = 0;
    p[4] = p[0] + (p[2] - p[0]) * progress / p[7];
    p[5] = p[1] + (p[3] - p[1]) * progress / p[7];
    if (progress >= p[7]) {
        *(Pair_021FE478 *)(p + 4) = *(Pair_021FE478 *)(p + 2);
        done = 1;
    }
    if (out) {
        *out = *(Pair_021FE478 *)(p + 4);
    }
    return done;
}

void func_021FE4D8(int *p, int a, const int *values, int duration)
{
    float value;
    func_02082BCC(p, 0, 0x14);
    p[0] = a;
    if (values[0] > 0)
        value = 0.5f + (float)(values[0] << 12);
    else
        value = (float)(values[0] << 12) - 0.5f;
    p[1] = (int)value;
    if (values[1] > 0)
        value = 0.5f + (float)(values[1] << 12);
    else
        value = (float)(values[1] << 12) - 0.5f;
    p[2] = (int)value;
    p[3] = 0;
    p[4] = duration;
}

static inline int roundFixed(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}

int func_021FE54C(char *p,int *out)
{
    VecFx32 delta;
    int length,x,y;
    delta.x=roundFixed((*(int **)p)[0])-((struct Obj02904 *)p)->f4;
    delta.y=roundFixed((*(int **)p)[1])-((struct Obj02904 *)p)->f8;
    delta.z=0;
    length=func_0207CBD0(&delta);
    if(length) {
        x=func_0207C768((int)(((long long)delta.x* ((struct Obj02904 *)p)->f10+2048)>>12),length);
        y=func_0207C768((int)(((long long)delta.y* ((struct Obj02904 *)p)->f10+2048)>>12),length);
        if((delta.x<0?-delta.x:delta.x)>(x<0?-x:x))((struct Obj02904 *)p)->f4+=x;
        else ((struct Obj02904 *)p)->f4=roundFixed((*(int **)p)[0]);
        if((delta.y<0?-delta.y:delta.y)>(y<0?-y:y))((struct Obj02904 *)p)->f8+=y;
        else ((struct Obj02904 *)p)->f8=roundFixed((*(int **)p)[1]);
    }
    if(out){out[0]=((struct Obj02904 *)p)->f4>>12;out[1]=((struct Obj02904 *)p)->f8>>12;}
    return length==0;
}

int *func_021FE6C0(unsigned heap)
{
    int *p = func_02030734(heap, 0x40, 0, d_02200D6C, 0x62);
    func_02082BCC(p, 0, 0x40);
    p[15] = 0xFFFF;
    p[8] = (int)func_02021518(heap);
    func_0202155C((void *)p[8], 0, 0x200, heap);
    func_0202155C((void *)p[8], 2, 0x1C0, heap);
    func_0202155C((void *)p[8], 1, 0x200, heap);
    func_0202155C((void *)p[8], 3, 0x1C0, heap);
    func_02021EE4((void *)p[8], 1);
    return p;
}

/*
 * extent: two zero alignment bytes at 0x021FE766 follow; no follower.
 * ABI: 02021540's legacy source declares void(void), but this caller loads r0 from p+0x20 at 021FE758; its tail-forward target 020307B0 saves and reads r0. Preserve that pointer argument.
 */
void func_021FE734(char *p) { func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,2); func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,0); func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,3); func_020215A0(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,1); func_02021540(((struct Obj06634 *)p)->f20); func_020307B0(p); }


void func_021FE768(S *p)
{
    int (*fn)(S *, void *);

    fn = (int (*)(S *, void *))p->f1c;
    if (fn != 0) {
        p->f0 = fn(p, p->at_c);
        if (p->f0 != 0)
            p->f1c = 0;
    }
}


void func_021FE784(int a, int b, int c, int d)
{
    func_021FE794((char *)a, b, c, d, 0);
}
