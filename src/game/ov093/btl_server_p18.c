/*
 * file:     btl_server_p18.c
 * unit:     yes
 * function: func_021BE3A8, func_021BE400, func_021BE518, func_021BE52C, func_021BE550, func_021BE620, func_021BE66C, func_021BE6A8, func_021BE6EC, func_021BE7E4, func_021BE878, func_021BE8C4, func_021BE8F4, func_021BE924, func_021BE95C, func_021BE994, func_021BE9D0, func_021BEA14, func_021BEA60, func_021BEAB4
 * address:  0x021BE3A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C0450  0x021C0450  thumb  ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021BEC58 0x021BEC58 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 *   func_021C0520 0x021C0520 thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021BCB14 0x021BCB14 thumb ov093
 *   func_021BCB68 0x021BCB68 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021BD148 0x021BD148 thumb ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021BEB14 0x021BEB14 thumb ov093
 *   func_021BEB04 0x021BEB04 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09961.h"
#include "../../matched/include/Obj13311.h"
#include "../../matched/include/Obj21052.h"
#include "../../matched/include/Obj09962.h"

struct Unk021D62A8;
struct Out64B4;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Out { u8 pad[16]; u32 flag : 1; u32 rest : 31; };

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

typedef struct { u8 *a; u32 b, c; u8 d0, flag; u16 pad; } E;

extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_0201BEB8(void *bag, int item);
extern int func_021EF948(int k);
extern void func_021C0450(u8 *p, u8 *q, u16 c, int k);
extern u8 *func_021B9934(char *, int);
extern int func_021D5B7C(void *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
extern u8 func_021D5440(u8 *p);
extern void func_021D7394(int kind);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *, u16, u32);
extern int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D73D4(int kind);
extern void func_021C0520(u8 *, u8 *, u16, u32);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern u32 func_021D6E74(u8 *p);
extern E *func_021BCB14(u8 *, u16, u8, u32);
typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E_021BCB68;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BCB68 e[4]; } S_021BCB68;

extern int func_021BCB68(S_021BCB68 *p, E_021BCB68 *cur);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern void func_021D6E40(u8 *, u8, u16);
extern void func_021CD64C(void *, u8, ...);
extern int func_021BD148(void *p, u8 x);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021C88E4(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5718(u8 *p, u8 *a, u32 b);
extern int func_021BEB14(int a, u8 *b, int c, int d, u8 *e, u8 *g);
extern u8 func_021BEB04(u8 *p, int selector);
int func_021BE3A8(u8 *p, u8 *a, u16 *s);
void func_021BE400(u8 *p, u16 key);
void func_021BE518(struct Unk021BE518 *p);
void func_021BE52C(u8 *p, int a, int b, int c);
void func_021BE550(u8 *p, u8 *b, u16 c, void *unused);
void func_021BE620(u8 *p, u8 *a, u8 *c);
void func_021BE66C(u8 *p, u8 *a, u8 *c, int k);
void func_021BE6A8(u8 *p, u8 *a, u8 *c, int k);
int func_021BE6EC(u8 *p, u8 *a, u16 key, u32 x);
int func_021BE7E4(u8 *p, u8 *a, u32 b, u32 c, u8 *q);
int func_021BE878(u8 *p, u8 *a, u32 v);
void func_021BE8C4(u8 *p, u8 *a);
void func_021BE8F4(u8 *p,u8 *a);
void func_021BE924(u8 *p, u8 *a, u32 v);
void func_021BE95C(u8 *p, u8 *a, u32 v);
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d);
void func_021BE9D0(u8 *p, u8 *a, u32 c, u32 d);
void func_021BEA14(u8 *p, u8 *a, u8 *b, u32 c);
void func_021BEA60(u8 *p, u8 *a, u8 *b, u32 c);
int func_021BEAB4(u8 *p, u8 *a, int b, int c, u8 *q);
extern const u16 d_021EFDB8[3];







int func_021BE3A8(u8 *p, u8 *a, u16 *s)
{
    u16 t = *s;
    int k = 0;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0xF) && (u32)func_0201BEB8((void *)t, (int)0xC)) {
        k = 0xD;
    } else if (func_021EF948(2) && (u32)func_0201BEB8((void *)t, (int)9)) {
        k = 0x14;
    }
    if (k) {
        func_021C0450(p, a, t, k);
        return 1;
    }
    return 0;
}







void func_021BE400(u8 *p, u16 key)
{
    u32 i;
    u8 *a;
    u8 *b;
    u32 lock;
    for (i = 0; i < (*(u8 **)(p + 0x4b0))[0]; i++) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 1]);
        b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 13]);
        if (func_021D5B7C(a) != 0) {
            lock = func_021CC8D8(p + 0x1d74, 3657);
            func_021BEA60(p, a, b, key);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 3659);
            func_021C64B4(p, key, a, (struct Out64B4 *)(*(struct Out * *)&((struct Obj00003 *)p)->f1AB0));
            (*(struct Out **)(p + 0x1ab0))->flag = 1;
            func_021CA7F4(p, a, (*(u8 **)(p + 0x4b0))[i + 7], (const u8 *)(*(struct Out **)(p + 0x1ab0)), ((struct Obj00003 *)p)->f864);
            func_021D7394(func_021D5440(a));
            func_021E02DC(a, key, func_021D59B4(a, 12));
            func_021BEC58(p, a, key, ((struct Obj00003 *)p)->f864);
            func_021E03D8(a, key);
            func_021D73D4(func_021D5440(a));
        }
    }
}







void func_021BE518(struct Unk021BE518 *p)
{
    u32 i;
    p->f0 = 0;
    for (i = 0; i < 6; i++) p->f1[i] = 0x1F;
}






/*
 * evidence: Each byte store may alias p[0], so reread the index.
 */
void func_021BE52C(u8 *p, int a, int b, int c)
{
    if (p[0] < 6) {
        (p + p[0])[1] = a;
        (p + p[0])[13] = b;
        (p + p[0])[7] = c;
        p[0]++;
    }
}






void func_021BE550(u8 *p, u8 *b, u16 c, void *unused)
{
    u8 *a;
    u32 lock;
    if ((*(u8 **)(p + 0x4ac))[0] != 0) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4ac))[1]);
        lock = func_021CC8D8(p + 0x1d74, 3720);
        func_021BEA14(p, a, b, c);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 3722);
        func_021C64B4(p, c, a, ((struct Obj00003 *)p)->f1AB0);
        func_021CA7F4(p, a, (*(u8 **)(p + 0x4ac))[7], ((struct Obj00003 *)p)->f1AB0, ((struct Obj00003 *)p)->f864);
        if (func_021D62C4((struct Unk021D62A8 *)a, 15) != 0 && (u32)func_0201BEB8((void *)c, (int)12) != 0) {
            func_021C0520(p, a, c, 13);
            return;
        }
        func_021E02DC(a, c, func_021D59B4(a, 12));
        func_021BEC58(p, a, c, ((struct Obj00003 *)p)->f864);
        func_021E03D8(a, c);
    }
}







void func_021BE620(u8 *p, u8 *a, u8 *c)
{
    func_021D74F8(3755);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj09961 *)c)->f0);
    func_021D7630(0x16, c[6]);
    func_021D70F0(p, 0xA2);
    c[6] = func_021D775C(0x16);
    func_021D7540(3761);
}






/*
 * evidence: CC8D8 returns its four-byte Lock in r0; preserve that complete
 * word as u32, as matched twin 021BE924 does. CC95C stores r1 unchanged.
 */
void func_021BE66C(u8 *p, u8 *a, u8 *c, int k)
{
    u32 old;
    old = func_021CC8D8((struct Lock *)(p + 0x1D74), 3774);
    func_021BE6A8(p, a, c, k);
    func_021CC95C((u32 *)(p + 0x1D74), old, 3778);
}







void func_021BE6A8(u8 *p, u8 *a, u8 *c, int k)
{
    func_021D74F8(3791);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13311 *)c)->f0);
    func_021D75EC(0x16, c[6]);
    func_021D70F0(p, k);
    func_021D7540(3796);
}






int func_021BE6EC(u8 *p, u8 *a, u16 key, u32 x)
{
    u32 i;
    u32 n;
    u8 id;
    u8 *chosen;
    u32 best;
    u8 chosen_id;
    E *cur;
    E *found[2];
    u32 v;
    for (i = 0; i < 3; i++) {
        if (key == d_021EFDB8[i]) break;
    }
    if (i == 3) goto fail;
    if (func_021D5BB0((struct UtilWork *)a, 10) != 0) goto fail;
    if (func_021D6E74(a) != 0) goto fail;
    n = 0;
    id = func_021D5440(a);
    for (i = 0; i < 3; i++) {
        if (key != d_021EFDB8[i]) {
            found[n] = func_021BCB14(p, d_021EFDB8[i], id, x);
            if (found[n] != 0) {
                n++;
                if (n >= 2) break;
            }
        }
    }
    if (n == 0) goto fail;
    best = 6;
    chosen = found[0]->a;
    for (i = 0; i < n; i++) {
        cur = found[i];
        v = (u32)func_021BCB68((S_021BCB68 *)p, (E_021BCB68 *)cur);
        if (v < best) {
            best = v;
            chosen = cur->a;
        }
    }
    chosen_id = func_021D5440(chosen);
    func_021D5FC0((struct UtilWork *)a, 10);
    func_021D6E40(chosen, id, key);
    func_021CD64C(((struct Obj21052 *)p)->fC, 91, 0x47a, id, chosen_id, 0xffff0000);
    func_021BD148(p, chosen_id);
    return 1;
fail:
    return 0;
}







int func_021BE7E4(u8 *p, u8 *a, u32 b, u32 c, u8 *q)
{
    u32 lk = func_021CC8D8(p + 0x1D74, 3894);
    int r = func_021BE878(p, a, c);
    int s;
    *q = 0;
    if (r) {
        s = func_021B8D8C(((struct Obj09962 *)p)->f4, ((struct Obj09962 *)p)->f8, func_021D5440(a));
        if (func_021C88E4(p) == 2) {
            func_021CD4B0(((struct Obj09962 *)p)->fC, 0x30, s, c, b, 0);
            func_021BE8C4(p, a);
            *q = 1;
        } else {
            func_021C5718(p, a, b);
        }
    }
    func_021CC95C((u32 *)(p + 0x1D74), lk, 3913);
    return r;
}







int func_021BE878(u8 *p, u8 *a, u32 v)
{
    int r;
    func_021D74F8(3931);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0xD, v);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 6);
    r = func_021D775C(0x51);
    func_021D7540(3937);
    return r;
}




void func_021BE8C4(u8 *p, u8 *a)
{
    u32 old;
    old = func_021CC8D8((struct Lock *)(p + 0x1D74), 3951);
    func_021BE8F4(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), old, 3956);
}




void func_021BE8F4(u8 *p,u8 *a)
{
    func_021D74F8(3968);
    func_021D75EC(3,func_021D5440(a));
    func_021D70F0(p,7);
    func_021D7540(3971);
}





void func_021BE924(u8 *p, u8 *a, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1D74, 3985);
    func_021BE95C(p, a, v);
    func_021CC95C((u32 *)(p + 0x1D74), s, 3987);
}




void func_021BE95C(u8 *p, u8 *a, u32 v)
{
    func_021D74F8(4000);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, v);
    func_021D70F0(p, 3);
    func_021D7540(4004);
}



/*
 * Interface: getter's matched Lock return is one full word; original
 * 021CC8DA loads old [r0] into r1; 021CC900 copies r1 to r0 unchanged.
 * This caller
 * saves r0 at 021BE9A8 and restores all bits through r1 at 021BE9BA;
 * 021CC95C is str r1,[r0]; bx lr. Scalar spelling follows matched caller
 * 021BC568 and retains the same word ABI. Struct/union locals used a
 * 12-byte frame and separate 4019 pool; scalar uses original 4-byte frame.
 */
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d)
{
    u32 old;
    old=func_021CC8D8(p+0x1d74, 4017);
    func_021BE9D0(p,a,c,d);
    func_021CC95C((u32 *)(p+0x1d74),old,4019);
}




void func_021BE9D0(u8 *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(4032);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x51, d);
    func_021D70F0(p, 4);
    func_021D7540(4037);
}




void func_021BEA14(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4051);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D70F0(p, 8);
    func_021D7540(4056);
}



void func_021BEA60(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4069);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 9);
    func_021D7540(4075);
}


/*
 * The byte loaded and compared in r1 remains the veneer call's second
 * argument. The veneer at 021BEB04 preserves r0/r1 to its target.
 */
int func_021BEAB4(u8 *p, u8 *a, int b, int c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    func_021BEB14((int)p, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_021BEB04(p + 0x1AB8, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}
