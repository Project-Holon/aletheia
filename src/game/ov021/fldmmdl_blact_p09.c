/*
 * file:     fldmmdl_blact_p09.c
 * unit:     yes
 * function: func_0219D2F4, func_0219D324, func_0219D390, func_0219D3B4, func_0219D3E4, func_0219D3F0
 * address:  0x0219D2F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02050468  0x02050468  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219C880  0x0219C880  thumb  ov021
 *   d_021D7F68  0x021D7F68  data  ov021
 *   func_0219C4AC  0x0219C4AC  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D8064     0x021D8064  data a2
 *   d_021D75C4     0x021D75C4  data ov021 a2
 */
#include "../../matched/include/Obj04225.h"
#include "../../matched/include/Obj02700.h"
#include "../../matched/include/Obj03579.h"
#include "../../matched/include/Obj00429.h"

struct BbActSys;
struct BbActRec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;

extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020307B0(void *p);
extern int func_0216DA30(int a0, int a1);
extern int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D598(void *p);
extern void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
extern int func_0219C4AC(u32 a, u32 b, u32 c, u32 d);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
void func_0219D2F4(u8 *s);
void func_0219D324(int *obj, int *rec);
void func_0219D390(u8 *s);
int func_0219D3B4(u8 *s, u32 p, u16 id);
char *func_0219D3E4(int i);
unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
extern char d_021D7F68[];
extern unsigned short d_021D8064[];
extern unsigned short d_021D75C4[];


void func_0219D2F4(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj04225 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_02050468((struct BbActSys *)(((struct Obj04225 *)s)->f4), e->id, 1);
                e->p = 0;
            }
        }
        func_020307B0(((struct Obj04225 *)s)->f20);
    }
}


void func_0219D324(int *obj, int *rec)
{
    int h;
    unsigned int n;

    h = rec[0];
    if (func_0216DA30(h, (int)rec) == 0) {
        func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, *((unsigned short *)(rec + 1) + 1));
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8((void *)h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != func_0216D598((void *)h)) {
            func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, n);
        }
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
    }
}


void func_0219D390(u8 *s)
{
    Slot *e = *(Slot * *)&((struct Obj03579 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_0219D324((int *)s, (int *)e);
            }
        }
    }
}


int func_0219D3B4(u8 *s, u32 p, u16 id)
{
    Slot *e = *(Slot * *)&((struct Obj00429 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0 && e->p == p && e->id == id) {
                return 1;
            }
        }
    }
    return 0;
}


/*
 * Indexes an array of 8-byte records based at 0x021D7F68.
 */
char *func_0219D3E4(int i)
{
    return d_021D7F68 + i * 8;
}


unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5)
{
    unsigned short *q;
    struct {
        int w0;
        unsigned char b4;
        unsigned char b5;
        unsigned char b6;
        unsigned char b7;
        int w2;
    } s;

    if (a5 == -1) {
        return (unsigned short)func_0219C4AC(o[1], a4, a2, a3);
    }
    s.w0 = a4;
    s.b4 = 0;
    s.b5 = d_021D8064[a3];
    q = d_021D75C4 + a2 * 2;
    s.b6 = q[0];
    s.b7 = q[1];
    s.w2 = a5;
    return func_020500F0((struct BbActSys *)o[1], (const struct BbActRec *)(&s), 1);
}
