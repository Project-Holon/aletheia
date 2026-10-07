/*
 * file:     no_gear_p02.c
 * unit:     yes
 * function: func_021F0058, func_021F007C, func_021F00C4, func_021F00C8, func_021F00F8
 * address:  0x021F0058
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EFF54 0x021EFF54 thumb ov030
 *   func_021EFECC 0x021EFECC thumb ov030
 *   func_021EFEC4 0x021EFEC4 thumb ov030
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_02030734  0x02030734  arm
 *   str_021F01C0   0x021F01C0  data   ov030  a1
 *   func_020120F4 0x020120F4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 */
#include "../../matched/include/Obj20401.h"
#include "../../matched/include/Obj13049.h"

struct BigObj;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021EFF54(void);
extern void func_021EFECC(void *);
extern void func_021EFEC4(void *, void (*)(void *), int);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
void func_021F0058(void *p);
void func_021F007C(char *p);
void func_021F00C4(void *unused);
char *func_021F00C8(u32 a, u32 *b, u32 c);
void func_021F00F8(char *p);
void func_021F0114(void);
extern char str_021F01C0[];

void func_021F0058(void *p)
{
    func_021EFF54();
    func_021EFECC(p);
    func_021EFEC4(p, func_021F00C4, 0x149);
}


/*
 * (followed by an unlabelled 2-byte `bx lr` stub at 0x021F00C4)
 */
void func_021F007C(char *p)
{
    u32 v = ((struct Obj20401 *)p)->f14;

    func_0203FB44(6, (u16)v, (u16)(v >> 16));
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02043598(0x10, 0);
}

/*
 * extent: empty callback bx lr, two-byte alignment then separate constructor
 * starts 0x021F00C8; callback alone is reproduced.
 * interface: func_021F0058 installs this callback and func_021F00F8 invokes
 * it with its object pointer in r0. Empty body does not read that context.
 */
void func_021F00C4(void *unused)
{
}


char *func_021F00C8(u32 a, u32 *b, u32 c)
{
    char *w;

    w = func_02030734(0x15, 0x20, 1, str_021F01C0, 0x17A);
    *(u16 *)(w + 8) = 0x15;
    *(u32 *)(w + 0x18) = c;
    func_021F0058(w);
    return w;
}

/*
 * extent: empty follower func_021F0114 then two-byte zero padding.
 */
void func_021F00F8(char *p)
{
    if (*(void (**)(char *))p != 0) {
        (*(void (**)(char *))p)(p);
    }
    func_0201058C((void *)func_0201283C(func_020120F4(((struct Obj13049 *)p)->f18)));
}

void func_021F0114(void)
{
}
