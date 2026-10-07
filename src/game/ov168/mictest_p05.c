/*
 * file:     mictest_p05.c
 * unit:     yes
 * function: func_02184780, func_02184818, func_0218483C
 * address:  0x02184780
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0203F5FC 0x0203F5FC arm
 *   func_0204B550 0x0204B550 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02035C08  0x02035C08  arm
 */
#include "../../matched/include/Obj10644.h"

struct Obj;
struct Actor;
struct Node;
struct Bank;
struct CharBuf;
struct Descriptor;
struct Rec;
struct Blk37;
typedef signed short s16;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0207C9D0(void *, void *, void *);
extern int func_0203F5FC(u32 x);
extern void func_0204B550(struct Actor *actor, signed short value, u32 axis);
extern void func_02030EAC(struct Node *n);
extern int func_02035C08(const void *p);
void func_02184780(void *task, int *p);
void func_02184818(char *p);
int func_0218483C(void);

/*
 * extent: two-byte alignment padding at 0x02184816.
 * Verified blocker C copied from ov137_func_021E09C0.c;
 * S13/blocker_0203F5FC-r1.log reports EXACT, 64 bytes:
 */
void func_02184780(void *task, int *p)
{
    s16 x;
    s16 y;
    int angle;
    if (p[1] != 0) {
        p[1]--;
        if (p[1] == 0)
            func_0204B3DC((void *)p[0], 1);
        return;
    }
    func_0207C9D0(p + 2, p + 5, p + 2);
    x = p[2] >> 12;
    y = p[3] >> 12;
    p[8] += p[9];
    while (p[8] > 0x168000)
        p[8] -= 0x168000;
    angle = func_0203F5FC((u16)(p[8] >> 12));
    x += (s16)((p[10] * angle) >> 12);
    func_0204B550((void *)p[0], x, 0);
    func_0204B550((void *)p[0], y, 1);
    if (y < -16) {
        func_0204B3DC((void *)p[0], 0);
        func_02030EAC(task);
        p[11] = 0;
    }
}

void func_02184818(char *p) { int i; char *q;for(i=0;i<3;i++){q=p+i*0x30;if(*(struct Node * *)&((struct Obj10644 *)q)->f7C){func_02030EAC(*(struct Node * *)&((struct Obj10644 *)q)->f7C);*(struct Node * *)&((struct Obj10644 *)q)->f7C=0;}} }


int func_0218483C(void)
{
    return func_02035C08((void *)0x0218486E);
}
