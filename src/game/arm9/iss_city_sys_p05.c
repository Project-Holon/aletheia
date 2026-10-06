/*
 * file:     iss_city_sys_p05.c
 * unit:     yes
 * function: func_0202AD10, func_0202AD44, func_0202AD78, func_0202AD88, func_0202AD8C, func_0202ADA0, func_0202ADB4
 * address:  0x0202AD10
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj15816.h"
#include "../../matched/include/Obj16758.h"
#include "../../matched/include/Obj15817.h"

typedef unsigned int u32;

typedef unsigned char u8;

extern int  func_0202AE08(void *obj);
extern int  func_0202AE34(void *obj);
extern int  func_0202AE68(void *obj);
extern u32 func_0202AE04(void *obj);
extern int func_0202AEBC(int a0);
extern void func_0202ABFC(void *obj, u32 value);
void func_0202AD10(void *obj);
void func_0202AD44(void *obj);
int func_0202AD78(int a0);
u32 sub_0202AD88(void *obj);
int func_0202AD8C(int a0);
int func_0202ADA0(int a0, int a1);
int func_0202ADB4(int a0, int a1);


void func_0202AD10(void *obj)
{
    int a = func_0202AE08(obj);
    int b = func_0202AE68(obj);

    if (a != 0 || b != 0) {
        func_0202AEBC((int)obj);
    }
    if ((int)func_0202AE04(obj) >= 0x7f) {
        func_0202ABFC(obj, 0);
    }
}


void func_0202AD44(void *obj)
{
    int a = func_0202AE34(obj);
    int b = func_0202AE68(obj);

    if (a != 0 || b != 0) {
        func_0202AEBC((int)obj);
    }
    if ((int)func_0202AE04(obj) <= 0) {
        func_0202ABFC(obj, 0);
    }
}


int func_0202AD78(int a0){ int t0 = func_0202AD88(a0); return *(int *)(((char *)(((struct Obj15816 *)((char *)((a0 + 0))))->f14) + ((int)((t0 << 2)) << 0))); }


/*
 * A plain byte getter at offset 0x19. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AD88.c \
 *       --func sub_0202AD88 --addr 0x0202AD88 --cc 1.1p1 --thumb
 */
u32 sub_0202AD88(void *obj)
{
    return ((struct Obj16758 *)obj)->f19;
}

int func_0202AD8C(int a0){ int t0; t0 = func_0202AD88(a0); if ((unsigned int)(t0) != (unsigned int)(0xff)) {  return 1; } else {  return 0; } }

int func_0202ADA0(int a0, int a1){ int t0; t0 = func_0202ADD8(a0, a1); if ((unsigned int)(t0) != (unsigned int)(0xff)) {  return 1; } else {  return 0; } }


int func_0202ADB4(int a0, int a1){ int t0, t1; t0 = func_0202AD88(a0); t1 = func_0202ADD8((int)((a0 + 0) + 0), (int)((a1 + 0) + 0)); if ((unsigned int)((t0 + 0)) == (unsigned int)(t1)) {  return 0; } else { ((struct Obj15817 *)((char *)((a0 + 0))))->f19 = (unsigned char)t1; return 1; } }
