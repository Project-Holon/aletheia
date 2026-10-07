/*
 * file:     c_gear_power_onoff_p01.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF2C, func_021EFF3C, func_021EFF78, func_021EFFD4
 * address:  0x021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F0678    0x021F0678 data ov035 a1
 *   func_02012138 0x02012138 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0201214C 0x0201214C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021F0640 0x021F0640 data ov035 a4
 *   func_021A0FA0 0x021A0FA0 thumb ov021
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021F000C 0x021F000C thumb ov035
 *   func_021F0140 0x021F0140 thumb ov035
 *   func_021F0168 0x021F0168 thumb ov035
 *   func_0203D34C 0x0203D34C arm
 *   func_021A12D4 0x021A12D4 thumb ov021
 *   func_021A0FB4 0x021A0FB4 thumb ov021
 *   func_021F0218 0x021F0218 thumb ov035
 *   func_021F015C 0x021F015C thumb ov035
 *   func_021F0100 0x021F0100 thumb ov035
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 */
#include "../../matched/include/Obj02409.h"
#include "../../matched/include/Obj04315.h"
#include "../../matched/include/Obj05127.h"

struct Ctx;
struct PrintSys;
struct GfFont;
struct MsgBank;
struct Rec;
typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02012138(const struct Ctx *);
extern int func_0202EB44(void);
extern u32 func_0201214C(const struct Ctx *);
extern u32 func_020307B0(void *p);
extern void func_021A0FA0(int *p, int v);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern void func_0201DD68(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int func_0201C440(void *p);
extern void func_021F000C(char *p, u32 heap);
extern void func_021F0140(void *, int);
extern void func_021F0168(int *p, int a1);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021A12D4(u32 *p, u32 x);
extern void func_021A0FB4(u32 *p, u32 a);
extern void func_021F0218(char *);
extern void func_021F015C(char *);
extern void func_021F0100(char *);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
void *func_021EFEC0(int a0, int a1, void *a2);
void func_021EFF2C(char *p);
void func_021EFF3C(char *p, int a1);
void func_021EFF78(char *p, void *a1);
void func_021EFFD4(char *p);
extern char d_021F0678[];


void *func_021EFEC0(int a0, int a1, void *a2)
{
    char *p = (char *)func_02030734((u32)a2, 0x50, 1, d_021F0678, 0x12D);
    ((struct Obj02409 *)p)->f4 = a1;
    ((struct Obj02409 *)p)->f8 = func_02012138((const struct Ctx *)a1);
    *(int *)&((struct Obj02409 *)p)->fC = a0;
    ((struct Obj02409 *)p)->f0 = (short unsigned int)a2;
    func_021EFF78(p, a2);
    if (func_0202EB44() == 0)
        ((struct Obj02409 *)p)->f48 = 2;
    else if (func_0201214C((const struct Ctx *)a1) == 1)
        ((struct Obj02409 *)p)->f48 = 1;
    else
        ((struct Obj02409 *)p)->f48 = 0;
    func_021EFF3C(p, 1);
    return p;
}

void func_021EFF2C(char *p) { func_021EFFD4(p); func_020307B0(p); }

extern int (*d_021F0640[])(char *);

void func_021EFF3C(char *p, int a1) { if(((struct Obj02409 *)p)->f4E==0) { if(d_021F0640[*(unsigned short *)(p+0x48)](p)) { func_021A0FA0(((struct Obj02409 *)p)->fC,14); ((struct Obj02409 *)p)->f4E=1; } } func_0201C4E4(((struct Obj02409 *)p)->f3C); }


void func_021EFF78(char *p, void *a1)
{
    *(int *)&((struct Obj04315 *)p)->f34 = (int)func_0201D7EC(0x17, 0, 0, 0, (unsigned int)a1);
    func_0201DD68();
    ((struct Obj04315 *)p)->f38 = (int)func_02045B38(0, 2, 0x16, (unsigned int)a1);
    *(int *)&((struct Obj04315 *)p)->f3C = func_0201C440(a1);
    func_021F000C(p, (u32)a1);
    func_021F0140(p, (int)a1);
    func_021F0168((int *)p, (int)a1);
    func_0203D34C(0, (u32)a1);
    func_021A12D4((u32 *)(((struct Obj04315 *)p)->fC), (int)a1);
}

void func_021EFFD4(char *p) { func_021A0FB4(((struct Obj05127 *)p)->fC,((struct Obj05127 *)p)->f0); func_021F0218(p); func_021F015C(p); func_021F0100(p); func_0201C6EC(((struct Obj05127 *)p)->f3C); func_0201C4C0(((struct Obj05127 *)p)->f3C); func_02045C04(((struct Obj05127 *)p)->f38); func_0201D83C(((struct Obj05127 *)p)->f34); }
