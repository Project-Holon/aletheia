/*
 * file:     eventdata_system_p10.c
 * unit:     yes
 * function: func_021622AC, func_021622D8, func_021622F4, func_0216230C, func_02162330, func_02162358
 * address:  0x021622AC
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
 *   func_02082D44 0x02082D44 arm
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj18955.h"
#include "../../matched/include/Obj18956.h"
#include "../../matched/include/Obj07202.h"
#include "../../matched/include/Obj07292.h"
#include "../../matched/include/Obj12334.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02082D44(void *, void *, unsigned);
extern int func_02082BCC();
int func_021622AC(char *p, int index, void *out);
int func_021622D8(char *p, void *out);
int func_021622F4(int a0, int a1, int a2);
void func_0216230C(char *p, unsigned i);
void func_02162330(char *p, unsigned i);
void func_02162358(int a0);

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
