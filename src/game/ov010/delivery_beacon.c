/*
 * file:     delivery_beacon.c
 * unit:     yes
 * function: func_0215766C, func_021576A8, func_021576AC, func_021576B8, func_021576C4, func_021576CC, func_021576D0, func_02157700, func_02157724, func_02157760, func_02157818, func_02157870, func_0215788C, func_021578A0, func_021578F0, func_02157910, func_02157928, func_02157938, func_02157948
 * address:  0x0215766C
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
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021727F4  0x021727F4  data
 *   func_02034714 0x02034714 arm
 *   d_021727F0 0x021727F0 data a4
 *   func_02177B2C  0x02177B2C  thumb  ov014
 *   func_02177BAC  0x02177BAC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_021780C4  0x021780C4  thumb  ov014
 *   func_02177BCC  0x02177BCC  thumb  ov014
 *   func_0203F328  0x0203F328  arm
 *   func_0203D010 0x0203D010 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_021727E0  0x021727E0  data  ov010
 *   d_02172780  0x02172780  data  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0203CEAC  0x0203CEAC  arm
 */
#include "../../matched/include/Obj09266.h"
#include "../../matched/include/Obj18736.h"
#include "../../matched/include/Obj04145.h"
#include "../../matched/include/Obj04913.h"
#include "../../matched/include/Obj04914.h"
#include "../../matched/include/Obj18737.h"

struct Req;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef enum { INDEX_ZERO = 0 } Index;

typedef struct P {
    u8 pad00[0x31B8];
    u8 sel;
} P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *, void *, u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u8 *func_02177B2C(int);
extern void func_02177BAC(u32 idx);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_021780C4(u32 i);
extern void func_02177BCC(void);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void func_0203D010(void);
extern int func_0203CD98(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern int func_0203CEAC(int a0);
u8 *func_0215766C(u8 *p);
void func_021576B8(char *a0, int a1);
void func_021576C4(char *p, int v, int line);
void func_021576CC(void);
void *func_021576D0(u8 *p);
void func_02157700(int *p);
int func_02157724(u8 *p);
void func_02157760(u8 *q);
void func_02157818(u8 *p);
void func_02157870(void *p);
void func_0215788C(void *p);
int func_021578A0(u32 *p);
int func_021578F0(void *p);
int func_02157910(u8 *p);
void func_02157928(u8 *p);
int func_02157938(void *a0);
extern const char d_021727F4[];
extern char d_021727F0[];
extern u8 d_021727E0[];
extern u8 d_02172780[];


u8 *func_0215766C(u8 *p)
{
    int v = ((struct Obj09266 *)p)->f31B4;
    int rem = v % 0x12;
    u32 q = v / 0x12;

    if (q >= ((struct Obj09266 *)p)->f78) {
        q = 0;
        ((struct Obj09266 *)p)->f31B4 = 0;
    }
    return p + 0x7C + q * 0x708 + rem * 100;
}


int func_021576A8(void) { return 100; }

int func_021576AC(int a, int b) { return a == b; }





/*
 * Recursive MATCH unblocker: matched so the ABS32 site in
 * ov010_func_021576C4 attests as `matched`.
 */
void func_021576B8(char *a0, int a1)
{
    ((struct Obj18736 *)a0)->f31BC = a1;
}






/*
 * Unblocked by matching func_021576B8 (ov010, EXACT). The ABS32 site +0004 now
 * attests as `matched`.
 * The listing extent is now 8 bytes, so the verdict is plain EXACT.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void func_021576C4(char *p, int v, int line)
{
    func_021576B8(p, v);
}





/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 */
void func_021576CC(void)
{
}





void *func_021576D0(u8 *p)
{
    void *buf;

    buf = func_02030734(*(u16 *)(p + 6), 0x31C0, 1, d_021727F4, 0x127);
    func_02082D44(p, buf, 0x7C);
    return buf;
}




void func_02157700(int *p) { if (p[2] != 0 && p[2] >= 0x5e8) func_02034714(d_021727F0, 0, d_021727F0); }




/*
 * extent: 58-byte body followed by 2-byte alignment padding.
 * lever: enum bound preserves the entry guard; declare index before bound.
 */
int func_02157724(u8 *p) { int i; Index n; n = p[0xd9]; if (n == 0) return 0; for (i = 0; i < n; i++) { if (n != p[i * 100 + 0xd9]) return 0; } return 1; }





/*
 * Wave 75: ov014 leaves 0x021780C4 and 0x02177BCC filed and verified;
 *   all six relocations resolve. 0x02177BAC was already matched.
 * levers (lane R1): the old 3-slot frame miss was the `sel`/`sel2` locals, which
 *   copy-propagate into one; the original writes p->sel directly and the two stack
 *   slots are the loop-hoisted 0x31B8 address. `(e+0x60) & (q+0x14)` operand order,
 *   and the CRC result in a named local for `cmp r0, r1`.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = q;` before `base = q + 0x7C;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02157760(u8 *q)
{
    P *p = (P *)q;
    u8 *base;

    int i;
    u8 *e;
    int idx;
    u32 crc;

    base = q + 0x7C;

    for (i = 0; i < 16; i++) {
        e = func_02177B2C(i);
        if (e == 0)
            continue;
        if (e[0x5F] != ((struct Obj04145 *)q)->f10) {
            func_02177BAC(i);
        } else if ((((struct Obj04913 *)e)->f60 & ((struct Obj04145 *)q)->f14) == 0) {
            func_02177BAC(i);
        } else if (e[0x5E] != p->sel && p->sel != 0xFF) {
            func_02177BAC(i);
        } else {
            idx = e[0x5C] - 1;
            if (idx >= 0x12)
                continue;
            if (q[idx * 100 + 0xD8] != 0)
                continue;
            crc = func_0203F1FC(e + 8, 0x54);
            if (crc != ((struct Obj04913 *)e)->f0) {
                func_02177BAC(i);
            } else {
                if (p->sel == 0xFF)
                    p->sel = e[0x5E];
                func_021780C4(i);
                func_02082D44(e, base + idx * 100, 100);
                func_02177BCC();
            }
        }
    }
}




void func_02157818(u8 *p)
{
    u8 *base;
    int i;

    base = p;
    i = 0;
    base = p + 0x7C;

    for (; i < 0x12; i++) {
        u32 off = i * 0x54;
        u8 *e = base + i * 100;
        u32 n;

        func_0203F328((u16 *)(e + 8), 0x54, ((struct Obj18737 *)e)->f4);
        n = (u16)off;
        if (((struct Obj04914 *)p)->f8 > (int)(n + 0x54))
            func_02082D44(e + 8, (u8 *)((struct Obj04914 *)p)->fC + off, 0x54);
        else
            func_02082D44(e + 8, (u8 *)((struct Obj04914 *)p)->fC + off, ((struct Obj04914 *)p)->f8 - n);
    }
}



/*
 * extent: 28-byte lead followed by existing matched ov010_func_0215788C.c.
 */
void func_02157870(void *p) { func_0203D010(); func_021576C4(p, (int)func_02157760, 0x1d7); }




/*
 * Unlabelled tail-call thunk hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 */
void func_0215788C(void *p)
{
    func_021576C4(p, (int)func_02157870, 0x1DD);
}




int func_021578A0(u32 *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_021727E0[7] = *p;
    *((u8 *)p + 0x31B8) = 0xFF;
    func_02157700((int *)p);
    func_0203CBAC((struct Req *)d_02172780, (u32)func_0215788C, (u32)p);
    func_021576C4((char *)p, (int)func_021576CC, 0x1F2);
    return 1;
}




/*
 * Unlabelled leaf, blocker of ov021 func_021D0C58: whether any of 18 slots (stride 100) has its flag byte set.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
int func_021578F0(void *p)
{
    int i;

    for (i = 0; i < 18; i++) {
        if (((u8 *)p)[i * 100 + 0xd9] != 0) {
            return 1;
        }
    }
    return 0;
}



/*
 * extent: 22 bytes of code followed by 2-byte alignment padding.
 */
int func_02157910(u8 *p) { int r; r = func_02157724(p); if (r) func_02157818(p); return r; }



void func_02157928(u8 *p) { (*(void (**)(u8 *))(p + 0x31bc))(p); }




int func_02157938(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_0215793E:
a0 = 0;
    a0 = (void *)func_0203CEAC((int)a0);
loc_02157944:
    return (int)a0;}


typedef struct { u8 pad00[0x670]; u16 f670; } Dress_02157948;
void func_02157948(Dress_02157948 *d)
{
    d->f670 = 1;
}
