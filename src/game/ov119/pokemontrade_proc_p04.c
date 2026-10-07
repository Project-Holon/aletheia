/*
 * file:     pokemontrade_proc_p04.c
 * unit:     yes
 * function: func_021D8F20, func_021D8F60, func_021D8FA4, func_021D8FE4
 * address:  0x021D8F20
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj10353.h"

struct Entry;
struct Link;
typedef unsigned int   u32;

typedef unsigned char u8;

extern int func_021D8A24(void *p);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_020173EC(void);
extern void func_02082D44(void *,void *,int);
int func_021D8F20(void *p,int idx);
void func_021D8F60(void *p,int idx,int x);
void *func_021D8FA4(void *p, int idx);
void func_021D8FE4(int idx,int a,int b,void *p,int id);

int func_021D8F20(void *p,int idx) {
 unsigned v=func_021D8A24(p);
 if(v==0) return *(int *)((char *)p+idx*4+0x5e4);
 if(func_0203D1A4((struct Link *)((unsigned)func_020399A8()))==0) return *(int *)((char *)p+idx*4+0x5e4);
 return *(int *)((char *)p+(1-idx)*4+0x5e4);
}

void func_021D8F60(void *p,int idx,int x) {
 unsigned v=func_021D8A24(p);
 if(v==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 if(func_0203D1A4((struct Link *)((unsigned)func_020399A8()))==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 *(int *)((char *)p+(1-idx)*4+0x5e4)=x;
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021D8FA4(void *p, int idx)
{
    u32 v = func_021D8A24(p);
    if (v == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    if (func_0203D1A4((struct Link *)((u32)func_020399A8())) == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    return *(void **)((char *)p + (1 - idx) * 4 + 0x5DC);
}

void func_021D8FE4(int idx,int a,int b,void *p,int id) {
 if(id==(int)func_020399A8()) {
 int n=func_020173EC();
 func_02082D44(*(void **)((char *)p+idx*4+0x1064),*(void **)((char *)p+idx*4+0x5dc),n);
 if(idx!=func_0203D1A4((struct Link *)func_020399A8())) {
 ((struct Obj10353 *)p)->fF9C=idx+1;
 ((struct Obj10353 *)p)->f11FB=(((struct Obj10353 *)p)->f11FB&~0xf0)|0x10;
 }
 }
}
