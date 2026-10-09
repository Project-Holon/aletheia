/*
 * file:     btl_server_p02.c
 * unit:     yes
 * function: func_021BBB48, func_021BBB60, func_021BBC34, func_021BBC44
 * address:  0x021BBB48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_021C3B68 0x021C3B68 thumb ov093
 *   func_021BB878 0x021BB878 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021BD8F0 0x021BD8F0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021C84E8  0x021C84E8  thumb  ov093
 *   func_021BBCC4  0x021BBCC4  thumb  ov093
 *   func_021D6EE8  0x021D6EE8  thumb  ov093
 *   func_021BB920  0x021BB920  thumb  ov093
 *   func_021D74E4  0x021D74E4  thumb  ov093
 *   func_021BBCD4  0x021BBCD4  thumb  ov093
 *   func_021BC610  0x021BC610  thumb  ov093
 *   func_021BBFA8  0x021BBFA8  thumb  ov093
 */
#include "../../matched/include/Obj21039.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09958.h"
#include "../../matched/include/Obj02776.h"

struct S2;
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02049238(u32);
extern u32 func_020307B0(void *p);
extern char *func_021B8714(char **p);
extern int func_021C3B68(u8 *, int, u8);
extern u8 *func_021BB878(u8 *p, u32 i);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern void func_021BD8F0(u8 *, u8, u8, u8);
extern u32 func_021B8588(void **p);
extern void func_021B8750(char *p, unsigned char k, void *m);
extern int func_021BDA00(u8 *);
extern void func_021C84E8(u8 *p);
extern void func_021BBCC4(u8 *p);
extern void func_021D6EE8(void);
extern void func_021BB920(u8 *p);
extern void func_021D74E4(void);
extern void func_021BBCD4(u8 *p);
extern u8 func_021BC610(u8 *p, int a, u8 *q, int n);
extern u8 func_021BBFA8(u8 *p, u8 k);
void func_021BBB48(u8 *p);
int func_021BBB60(u8 *p);
void func_021BBC34(u8 *p);
int func_021BBC44(u8 *p, int a);


void func_021BBB48(u8 *p)
{
    func_02049238(((struct Obj21039 *)p)->f4A4);
    func_020307B0(p);
}



int func_021BBB60(u8 *p)
{
    u8 *initial;
    u32 i;
    int result;
    void *m;
    u32 *out = *(u32 * *)&((struct Obj00003 *)p)->fC;
    out[0] = 0;
    result = 0;
    out[1] = 0;
    initial = (u8 *)func_021B8714((char * *)(((struct Obj00003 *)p)->f4));
    if (initial[8] && func_021C3B68(p, initial[8], 255)) result = 1;
    for (i = 0; i < 4; i++) {
        u8 *q = func_021BB878(((struct Obj00003 *)p)->f0, (u8)i);
        if (q) {
            u32 j;
            for (j = 0; j < q[9]; j++) {
                m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                if (m && !func_021D5B68(m)) func_021BD8F0(p, i, j, j);
            }
            if (func_021B8588(((struct Obj00003 *)p)->f4) == 3) {
                for (j = 0; j < 3; j++) {
                    m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                    if (m && !func_021D5B68(m)) func_021B8750(((struct Obj00003 *)p)->f4, i, m);
                }
            }
        }
    }
    if (func_021BDA00(p)) result = 1;
    return result;
}




void func_021BBC34(u8 *p)
{
    p[0x77c] = 0;
    p[0x783] = 0;
}


int func_021BBC44(u8 *p, int a)
{
    int *q;
    u32 i;

    ((struct Obj02776 *)p)->f14 = 0;
    q = *(int * *)&((struct Obj02776 *)p)->fC;
    q[0] = 0;
    q[1] = 0;
    if (p[0x77c] == 0) {
        func_021C84E8(p);
        func_021BBCC4(p + 0x3e0);
        for (i = 0; i < 4; i++)
            p[i + 0x1fe8] = 0;
        func_021D6EE8();
        func_021BB920((u8 *)(((struct Obj02776 *)p)->f0));
        func_021D74E4();
        func_021BBCD4(p);
        p[0x782] = func_021BC610(p, a, p + 0x7e0, 6);
        p[0x77c] = 1;
    }
    p[0x783] = func_021BBFA8(p, p[0x783]);
    return ((struct Obj02776 *)p)->f14;
}
