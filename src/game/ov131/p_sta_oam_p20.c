/*
 * file:     p_sta_oam_p20.c
 * unit:     yes
 * function: func_021D87E0, func_021D881C, func_021D8830
 * address:  0x021D87E0
 * region:   ov131
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
 *   func_02045B38 0x02045B38 arm
 *   d_021DC834 0x021DC834 data a1
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021D8A2C 0x021D8A2C thumb ov131
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021D9670 0x021D9670 thumb ov131
 *   func_021D9568 0x021D9568 thumb ov131
 *   func_021D92B0 0x021D92B0 thumb ov131
 */
#include "../../matched/include/Obj23147.h"
#include "../../matched/include/Obj00091.h"
#include "../../matched/include/Obj03816.h"

struct MsgBank;
struct Rec;
struct PrintSys;
typedef unsigned short u16;

typedef unsigned int u32;

struct S { u32 a; u32 pad[19]; void *f50; u32 pad2[3]; unsigned char b60; };

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern void func_021D8A2C(unsigned char *, unsigned char *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021D9670(unsigned char *, unsigned char *);
extern void func_021D9568(unsigned char *, unsigned char *);
extern void func_021D92B0(unsigned char *, unsigned char *);
void *func_021D87E0(u16 *a);
void func_021D881C(void *a, u8 *p);
void func_021D8830(unsigned char *a, unsigned char *p);
extern const char d_021DC834[];

void *func_021D87E0(u16 *a) {
 struct S *p = func_02030734(*a, 0x3b8, 0, d_021DC834, 0xaf);
 p->a = 0;
 p->b60 = 0;
 p->f50 = func_02045B38(0, 2, 0xaa, *a);
 return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D881C(void *a, u8 *p)
{
    func_02045C04(((struct Obj23147 *)p)->f50);
    func_020307B0(p);
}

void func_021D8830(unsigned char *a, unsigned char *p)
{
    func_021D8A2C(a,p);
    if (((struct Obj00091 *)p)->f8 == 1) {
        if (func_0201C6B4(((struct Obj03816 *)a)->f84) == 1) {
            func_021D9670(a,p);
            func_021D9568(a,p);
            ((struct Obj00091 *)p)->f8=0;
        }
    } else func_021D92B0(a,p);
    if (p[0x60]) p[0x60]--;
}
