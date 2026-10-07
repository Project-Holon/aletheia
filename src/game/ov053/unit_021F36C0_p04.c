/*
 * file:     unit_021F36C0_p04.c
 * unit:     yes
 * function: func_021F3A38, func_021F3A5C, func_021F3A6C, func_021F3A7C, func_021F3AA0, func_021F3B10, func_021F3B20, func_021F3B30
 * address:  0x021F3A38
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005728 0x02005728 thumb
 *   func_021C4E08 0x021C4E08 thumb ov021
 *   func_02005F24 0x02005F24 thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   _fflt  0x0209BDBC  arm
 *   _fdiv  0x0209CE10  arm
 *   _fleq  0x0209BC0C  arm
 *   _fls   0x0209BC74  arm
 *   _fsub  0x0209CB8C  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02082A7C 0x02082A7C arm
 */
#include "../../matched/include/Obj13117.h"
#include "../../matched/include/Obj03650.h"

typedef unsigned int u32;

extern unsigned func_02005728(unsigned);
extern int func_021C4E08(void *, int);
extern void func_02005F24(u32, u32);
extern void *func_02188C58(void *p);
extern void func_0218ECE4(int, int *);
extern void func_02082A7C(int, void *, unsigned int);
void func_021F3A38(char *a, int i);
int func_021F3A5C(char *p, int i);
void func_021F3A6C(int *p);
void func_021F3A7C(char *p, int a);
int func_021F3AA0(char *a, int b);
void func_021F3B10(char *p, int target);
void func_021F3B20(char *p, int target);
void func_021F3B30(void *p);

/*
 * note: Inline random call keeps the returned value on the right of the add.
 *       The final two bytes of the handed extent are alignment padding.
 */
void func_021F3A38(char *a, int i)
{
    ((int *)(a + 0x1c))[i] = ((int *)(a + 0x30))[i] +
        func_02005728(((int *)(a + 0x44))[i] - ((int *)(a + 0x30))[i] + 1);
}

int func_021F3A5C(char *p, int i) { return func_021C4E08(*(void **)(p+8+4*i),0); }

void func_021F3A6C(int *p) { func_02005F24(((struct Obj13117 *)p)->f58, ((struct Obj13117 *)p)->f64); }

void func_021F3A7C(char *p, int a) { int v=func_021F3AA0(p,a); if (((struct Obj03650 *)p)->f64<v) func_021F3B10(p,v); else if(v<((struct Obj03650 *)p)->f64) func_021F3B20(p,v); }


int func_021F3AA0(char *a, int b)
{
    int v[3];
    float x;
    float r;

    func_0218ECE4((int)func_02188C58((void *)b), v);
    x = v[1] / 4096.0f;
    if (x <= *(float *)(a + 0x5c))
        return 0;
    if (*(float *)(a + 0x60) < x)
        return 0x7f;
    r = *(float *)(a + 0x60) - *(float *)(a + 0x5c);
    return (int)(127.0f * (x - *(float *)(a + 0x5c)) / r);
}


void func_021F3B10(char *p, int target) { ((struct Obj03650 *)p)->f64 += 16; if (target < ((struct Obj03650 *)p)->f64) ((struct Obj03650 *)p)->f64=target; }


void func_021F3B20(char *p, int target) { ((struct Obj03650 *)p)->f64 -= 16; if (((struct Obj03650 *)p)->f64 < target) ((struct Obj03650 *)p)->f64=target; }

void func_021F3B30(void *p) { func_02082A7C(0,p,0x90); }
