/*
 * file:     eventdata_system_p09.c
 * unit:     yes
 * function: func_021621E8, func_0216220C, func_02162230, func_02162254, func_02162278, func_02162298
 * address:  0x021621E8
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
 *   func_02161DC4  0x02161DC4  thumb  ov010
 *   func_02161E78  0x02161E78  thumb  ov010
 *   func_02161E60  0x02161E60  thumb  ov010
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj17712.h"
#include "../../matched/include/Obj18954.h"
#include "../../matched/include/Obj07292.h"
#include "../../matched/include/Obj03062.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { unsigned x; u16 b; u16 t; } S;

extern char *func_02161DC4(char *p, int id, unsigned mode);
extern int func_02161E78();
extern int func_02161E60(int a0, int a1);
extern void func_02082D44(void *, void *, unsigned);
int func_021621E8(int a0, int a1, int a2);
void func_0216220C(u16 *p, S *s);
void func_02162230(char *p, int index, void *s);
int func_02162254(char *p, u16 index, u16 *out);
void func_02162278(char *p, int index, u16 a, u16 b);
int func_02162298(int a0, int a1, int a2);


int func_021621E8(int a0, int a1, int a2)
{
    int t4;
    int t5;
    char *s;

t5 = a1 + 0;
a1 = ((struct Obj17712 *)a2)->f4;
a0 = t5 + 0;
a2 = 1;
t4 = 1;
    s = func_02161DC4((char *)a0, a1, a2);
loc_021621F8:
    if (s == 0) goto loc_02162208;
loc_021621FC:
    a0 = func_02161E78(s);
loc_02162200:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02161E60(a0, a1);
loc_02162208:
a0 = 0;
    return a0;}

void func_0216220C(u16 *p, S *s)
{
    if (s->x == *p) {
        func_02082D44(s, (char *)p + 0x20, 8);
        p[1] |= 8;
    }
}


/*
 * note:     caller 0x02162008 forwards all three of its arguments unchanged
 *           (r0-r2); the copy is MI_CpuCopy8-shaped (src, dst, 8) into the
 *           index-th eight-byte slot after an 8-byte head, then bit index of
 *           the u16 at +2 is set.
 */
void func_02162230(char *p, int index, void *s)
{
    func_02082D44(s, p + 8 + index * 8, 8);
    *(u16 *)(p + 2) = (u16)(*(u16 *)(p + 2) | (1 << index));
}

int func_02162254(char *p, u16 index, u16 *out)
{
    int result = 0;
    if (((struct Obj18954 *)p)->f2 & (1 << index)) {
        func_02082D44(p + 8 + index * 8, out, 8);
        result = 1;
    }
    return result;
}

void func_02162278(char *p, int index, u16 a, u16 b)
{
    *(int *)(p + 0x30 + index * 8) = index;
    *(u16 *)(p + 0x34 + index * 8) = a;
    *(u16 *)(p + 0x36 + index * 8) = b;
    ((struct Obj07292 *)p)->f2 = (u16)(((struct Obj07292 *)p)->f2 | (1 << (index + 5)));
}




int func_02162298(int a0, int a1, int a2)
{
    int a3;

((struct Obj03062 *)a0)->f2E = a2;
a3 = ((struct Obj03062 *)a0)->f4;
((struct Obj03062 *)a0)->f2C = a1;
a2 = ((struct Obj03062 *)a0)->f2;
a1 = 0x10;
((struct Obj03062 *)a0)->f28 = a3;
a1 = a1 | a2;
((struct Obj03062 *)a0)->f2 = a1;
    return a0;}
