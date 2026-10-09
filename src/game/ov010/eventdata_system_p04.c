/*
 * file:     eventdata_system_p04.c
 * unit:     yes
 * function: func_021621E8, func_0216220C, func_02162230, func_02162254, func_02162278, func_02162298, func_021622AC, func_021622D8, func_021622F4, func_0216230C, func_02162330, func_02162358, func_02162370, func_0216237C, func_021623BC, func_021623DC
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_0217299C     0x0217299C  data  ov010  a1
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02162530 0x02162530 thumb ov010
 */
#include "../../matched/include/Obj17712.h"
#include "../../matched/include/Obj18954.h"
#include "../../matched/include/Obj07292.h"
#include "../../matched/include/Obj03062.h"
#include "../../matched/include/Obj18955.h"
#include "../../matched/include/Obj18956.h"
#include "../../matched/include/Obj07202.h"
#include "../../matched/include/Obj12334.h"
#include "../../matched/include/Obj09161.h"
#include "../../matched/include/Obj04155.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { unsigned x; u16 b; u16 t; } S;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { unsigned char pad[0x3f]; unsigned char low:7; unsigned char flag:1; } Flags;

extern char *func_02161DC4(char *p, int id, unsigned mode);
extern int func_02161E78();
extern int func_02161E60(int a0, int a1);
extern void func_02082D44(void *, void *, unsigned);
extern int func_02082BCC();
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
extern int func_020307B0();
extern void func_02162530(char *);
int func_021621E8(int a0, int a1, int a2);
void func_0216220C(u16 *p, S *s);
/* * note: caller 0x02162008 forwards all three of its arguments unchanged * (r0-r2); the copy is MI_CpuCopy8-shaped (src, dst, 8) into the * index-th eight-byte slot after an 8-byte head, then bit index of * the u16 at +2 is set. */ void func_02162230(char *p, int index, void *s);
int func_02162254(char *p, u16 index, u16 *out);
void func_02162278(char *p, int index, u16 a, u16 b);
int func_02162298(int a0, int a1, int a2);
int func_021622AC(char *p, int index, void *out);
int func_021622D8(char *p, void *out);
int func_021622F4(int a0, int a1, int a2);
/* * domain: Primary calls at 0216213C/0216216E receive loop index 0..2 * from 02162120 (zero at 0216212A; increment/test at 02162188..18C). * ov011 02172D70 passes Work+0x35C through 02161F74 to 02162120. * 02172BC0 allocates 0x94C bytes and initializes that 0x48-byte record * with 02161F54. The clear spans offsets 8..31; the mask reads offset 2. * Thus primary shift counts 0..2 are defined; no arbitrary-u32 domain claim. */ void func_0216230C(char *p, unsigned i);
/* * domain: Primary ov011 call 02174C8C reaches this through thunk 02162038. * Its byte counter is zeroed at 02174C64..68, loaded at 02174C88, and * increments/tests against 3 at 02174C90..9A: index 0..2, shifts 5..7. * The record is Work+0x35C (02174C62/6A/8A); 02172BC0 allocates * 0x94C bytes and 02161F54 initializes this 0x48-byte record. * Clears cover offsets 0x30..0x47; mask halfword offset 2 is initialized. * No arbitrary-u32 domain claim: all primary arithmetic stays in range. */ void func_02162330(char *p, unsigned i);
void func_02162358(int a0);
/* * Predicate: is the argument >= 7. * * Addresses are Black-image addresses. */ int func_02162370(int a);
int func_0216237C(int a);
int func_021623BC(int a0);
void func_021623DC(char *p);
extern char d_0217299C[];





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




int func_021622AC(char *p, int index, void *out)
{
    int result = 0;
    if (((struct Obj18955 *)p)->f2 & (1 << (index + 5))) {
        func_02082D44(p + 0x30 + index * 8, out, 8);
        result = 1;
    }
    return result;
}




int func_021622D8(char *p, void *out)
{
    int result = 0;
    if (((struct Obj18956 *)p)->f2 & 16) {
        func_02082D44(p + 0x28, out, 8);
        result = 1;
    }
    return result;
}





int func_021622F4(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x20;
a1 = 0;
a2 = 8;
    a0 = func_02082BCC(a0, a1, a2);
loc_02162302:
a1 = ((struct Obj07202 *)t4)->f2;
a0 = 8;
a1 = a1 &~ a0;
((struct Obj07202 *)t4)->f2 = a1;
    return a0;}




/*
 * domain: Primary calls at 0216213C/0216216E receive loop index 0..2
 *   from 02162120 (zero at 0216212A; increment/test at 02162188..18C).
 *   ov011 02172D70 passes Work+0x35C through 02161F74 to 02162120.
 *   02172BC0 allocates 0x94C bytes and initializes that 0x48-byte record
 *   with 02161F54. The clear spans offsets 8..31; the mask reads offset 2.
 *   Thus primary shift counts 0..2 are defined; no arbitrary-u32 domain claim.
 */
void func_0216230C(char *p, unsigned i) { func_02082BCC(p+8+i*8,0,8); ((struct Obj07292 *)p)->f2 = ((struct Obj07292 *)p)->f2 & ~(1<<i); }




/*
 * domain: Primary ov011 call 02174C8C reaches this through thunk 02162038.
 *   Its byte counter is zeroed at 02174C64..68, loaded at 02174C88, and
 *   increments/tests against 3 at 02174C90..9A: index 0..2, shifts 5..7.
 *   The record is Work+0x35C (02174C62/6A/8A); 02172BC0 allocates
 *   0x94C bytes and 02161F54 initializes this 0x48-byte record.
 *   Clears cover offsets 0x30..0x47; mask halfword offset 2 is initialized.
 *   No arbitrary-u32 domain claim: all primary arithmetic stays in range.
 */
void func_02162330(char *p, unsigned i) { func_02082BCC(p+0x30+i*8,0,8); ((struct Obj12334 *)p)->f2 = ((struct Obj12334 *)p)->f2 & ~(1<<(i+5)); }





void func_02162358(int a0)
{
    int a1;
    int a2;
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x28;
a1 = 0;
a2 = 8;
    a0 = func_02082BCC(a0, a1, a2);
loc_02162366:
a1 = ((struct Obj07202 *)t4)->f2;
a0 = 0x10;
a1 = a1 &~ a0;
((struct Obj07202 *)t4)->f2 = a1;
    return;}



/*
 * Predicate: is the argument >= 7.
 *
 * Addresses are Black-image addresses.
 */
int func_02162370(int a)
{
return a >= 7;
}




int func_0216237C(int a)
{
    void **p = (void **)func_02030734(a, 0xAA8, 1, d_0217299C, 0xAF);
    p[1] = func_020490F4(0x7D, a);
    p[2] = func_020490F4(0x7E, a);
    p[3] = func_020490F4(0x39, a);
    return (int)p;
}




int func_021623BC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj09161 *)t4)->f4;
    func_02049238((void *)a0);
loc_021623C6:
a0 = ((struct Obj09161 *)t4)->f8;
    func_02049238((void *)a0);
loc_021623CC:
a0 = ((struct Obj09161 *)t4)->fC;
    func_02049238((void *)a0);
loc_021623D2:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_021623D8:
    return a0;}

void func_021623DC(char *p) { func_02162530(p); *(char * *)&((struct Obj04155 *)p)->f120=p+0x2328; ((struct Obj04155 *)p)->f34=0; ((Flags *)p)->flag=0; }
