/*
 * file:     the_end_graphic_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B964C, func_021B96BC, func_021B9784, func_021B9788
 * address:  0x021B95A0
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B9B9C 0x021B9B9C data a2
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B98E4 0x021B98E4 thumb ov182
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020111E8 0x020111E8 thumb
 *   func_0207E468 0x0207E468 arm
 *   func_021B9814 0x021B9814 thumb ov182
 *   d_021B9BAC 0x021B9BAC data a4
 *   func_020403F4 0x020403F4 arm
 *   func_021B9810 0x021B9810 thumb ov182
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B998C 0x021B998C thumb ov182
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E804 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B99E8 0x021B99E8 thumb ov182
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 */
#include "../../matched/include/Obj03328.h"
#include "../../matched/include/Obj06593.h"
#include "../../matched/include/Obj06594.h"

struct Obj0203159C;
struct GfFont;
struct Node;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {u32 id; u32 v[10];} Record;

extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, int, int);
extern char *func_021B98E4(int a, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void *func_020056A0(void (*)(void), void *, int);
extern unsigned func_020111E8(void);
extern void func_0207E468(void *, int, int);
extern void func_021B9814(void *, void *, void *);
extern void func_020403F4(u32 i);
extern void func_021B9810(void *);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021B998C(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern int func_0204E804(void);
extern unsigned func_020362DC(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021B99E8(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(unsigned char *);
extern void func_020409B4(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
int func_021B95A0(void *task, int b, int c);
int func_021B964C(void *task, int b, int c, char *p);
int func_021B96BC(void *a, unsigned *state, void *c, char *p);
void func_021B9784(void);
void func_021B9788(unsigned short *p);
extern const u16 d_021B9B9C;
extern const Record d_021B9BAC[1];

int func_021B95A0(void *task, int b, int c)
{
    u16 value[1];
    char *p;
    u16 *vp;
    value[0] = d_021B9B9C;
    vp = value;
    func_0203064C(1, 0x88, 0x30000);
    p = func_0203159C(task, 0x1c, 0x88);
    func_02082BCC(p, 0, 0x1c);
    ((struct Obj03328 *)p)->f0 = 0x88;
    ((struct Obj03328 *)p)->f10 = c;
    ((struct Obj03328 *)p)->f4 = func_021B98E4(1, ((struct Obj03328 *)p)->f0);
    ((struct Obj03328 *)p)->f8 = func_0201D7EC(0x17, 0, 0, 0, ((struct Obj03328 *)p)->f0);
    ((struct Obj03328 *)p)->fC = (void *)func_0201C440((void *)(((struct Obj03328 *)p)->f0));
    func_0204047C(1, 1);
    func_0204047C(2, 0);
    ((struct Obj03328 *)p)->f14 = func_020056A0(func_021B9784, p, 1);
    func_021B9788((u16 *)p);
    if (func_020111E8() == 0x14)
        func_0207E468(vp, 0, 2);
    func_021B9814((void *)0x10, 0, 0);
    return 1;
}

/*
 * volatile: hardware 04001050 and 04001000 read/write at 021B966C-021B967A.
 */
int func_021B964C(void *task, int b, int c, char *p)
{
    int i;
    for (i = 0; i < sizeof(d_021B9BAC) / sizeof(d_021B9BAC[0]); i++)
        func_020403F4((u8)d_021B9BAC[i].id);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    func_021B9810(p);
    func_02030EAC(((struct Obj06593 *)p)->f14);
    func_0201C6EC(((struct Obj06593 *)p)->fC);
    func_0201C4C0(((struct Obj06593 *)p)->fC);
    func_0201D83C(((struct Obj06593 *)p)->f8);
    func_021B998C(((struct Obj06593 *)p)->f4);
    func_020315D4(task);
    func_020306F0(0x88);
    return 1;
}

int func_021B96BC(void *a, unsigned *state, void *c, char *p)
{
    int ready;
    switch (*state) {
    case 0: *state = 4; break;
    case 1:
        if (!func_0204E804()) *state = 2;
        break;
    case 2:
        ready = 0;
        if (++((struct Obj06594 *)p)->f18 > 0x384) ready = 1;
        if (ready) {
            *state = 3;
            func_021B9814(0, (void *)0x10, 0);
        }
        break;
    case 3:
        if (!func_0204E804()) {
            func_021B9788((u16 *)p);
            func_021B9814((void *)0x10, 0, 0);
            *state = 4;
        }
        break;
    case 4:
        if (!func_0204E804()) {
            ((struct Obj06594 *)p)->f18 = 0;
            *state = 5;
        }
        break;
    case 5:
        if ((func_020362DC() & 0xb) || ++((struct Obj06594 *)p)->f18 > 0x384) {
            *state = 6;
            func_021B9814(0, (void *)0x10, 0);
        }
        break;
    case 6:
        if (!func_0204E804()) *state = 7;
        break;
    case 7: return 1;
    }
    func_0201C4E4(((struct Obj06594 *)p)->fC);
    func_021B99E8(*(char * *)&((struct Obj06594 *)p)->f4);
    return 0;
}

void func_021B9784(void)
{
}

void func_021B9788(unsigned short *p)
{
    unsigned char *q = func_020490F4(0xdc, *p);
    func_02049B68(q, 2, 0, 0, 0, *p);
    func_02049658(q, 3, 1, 0, 0, 0, *p);
    func_020498F4(q, 5, 1, 0, 0, 0, *p);
    if (func_020111E8() == 0x14)
        func_020413B0(1, 0, 0, 0x20, 0x18, 1);
    func_02049238(q);
    func_020409B4(1);
    func_02040588(1, 1);
    func_02040588(2, 0);
}
