/*
 * file:     unit_021BF050_p12.c
 * unit:     yes
 * function: func_021C1064, func_021C10A8, func_021C1154, func_021C11A0
 * address:  0x021C1064
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BA7D8 0x021BA7D8 thumb ov099
 *   func_0203C3EC 0x0203C3EC arm
 *   func_0203CB00 0x0203CB00 arm
 *   func_021BE900 0x021BE900 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_0203C5EC 0x0203C5EC arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02039C68 0x02039C68 arm
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_020399EC 0x020399EC arm
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj03735.h"

struct Entry;
struct Link;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

extern void func_021C19A8(char *);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_0203C554(u32 a);
extern void func_021C2408(char *);
extern void func_021BA8EC(char *);
extern int func_02006224(u32 a0);
extern int func_02156A3C(void);
extern unsigned char func_021C23C0(void *a);
extern int func_021C23B8(int i);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern u8 func_021BDD48(char *, void *);
extern int func_021C27E0(void *);
extern void func_021BA7D8(void *p);
extern int func_0203C3EC(void);
extern int func_0203CB00(void);
extern void func_021BE900(char *);
extern int func_021BA928(void *);
extern int func_0203C5EC(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern void func_02082BCC(void *, int, int);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern void func_021BC090(void *);
extern u32 func_0203D1A4(struct Link *p);
extern int func_02039ACC(void);
extern int func_020399EC(void);
int func_021C1064(char *p,int ret);
int func_021C10A0(char *p,int ret);
int func_021C10A4(char *p,int ret);
int func_021C10A8(char *p, int ret);
int func_021C1154(char *p);
int func_021C11A0(char *p, int ret);

int func_021C1064(char *p,int ret) {
    func_021C19A8(p);
    func_021C18C8(p,1,2);
    func_0203C554(1);
    ((struct Obj00008 *)p)->f1F0=-1;
    ((struct Obj00008 *)p)->f1CC=11;
    func_021C2408(p);
    func_021BA8EC(p);
    return ret;
}

int func_021C10A0(char *p,int ret){return ret;}

int func_021C10A4(char *p,int ret){return ret;}

int func_021C10A8(char *p, int ret)
{
    int zero = 0;
    void *s;
    if (func_02006224(0) != 0) return ret;
    if (func_021C23C0((void *)func_02156A3C()) == 0) {
        func_021BA874(p, ((struct Obj03735 *)p)->f1F0);
        func_021BAAB8(p, 15, zero);
        ((struct Obj03735 *)p)->f1CC = 19;
        return ret;
    }
    s = (void *)func_021C23B8(func_02156A3C());
    func_021BDD48(p, ((struct Obj03735 *)p)->f8);
    func_021BDD48(p, s);
    func_021C27E0(((struct Obj03735 *)p)->f8);
    ((struct Obj03735 *)p)->f242 = func_02156A3C() + 1;
    if (((struct Obj03735 *)p)->f1351 == 0) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 8, zero);
    }
    func_021BA7D8(p);
    ((struct Obj03735 *)p)->f1CC = 41;
    ((struct Obj03735 *)p)->f1E0 = 30;
    return ret;
}

int func_021C1154(char *p)
{
    if (func_0203C3EC() >= 3) {
        func_021BA874(p, *(int *)(p + 0x1f0));
        func_021BAAB8(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else {
        if (func_0203CB00() != 0) func_021BE900(p);
        else return 0;
    }
    *(unsigned short *)(p + 0x244) = 0;
    return 1;
}

/*
 * extent: 021C1286..021C1288 is two zero alignment bytes.
 *   extern char *d_021469DC;
 *   int func_0203C5EC(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 * prototype: 399A8 leaves a live pointer consumed by 399B8, 39C68 and 3D1A4.
 */
int func_021C11A0(char *p, int ret)
{
    func_021BA928(p);
    if (func_0203C3EC() >= 4 || func_0203C5EC() != 0) {
        if (*(u16 *)(p + 0x244) != 0) {
            func_021BAAB8(p, 0x44, 0);
        } else {
            func_021BA874(p, *(int *)(p + 0x1f0));
            func_021BAAB8(p, 15, 0);
        }
        *(u16 *)(p + 0x244) = 0;
        *(int *)(p + 0x1cc) = 19;
    } else if (func_021C1154(p) == 0) {
        if (*(int *)(p + 0x1e0) > 1) --*(int *)(p + 0x1e0);
        if (*(int *)(p + 0x1e0) == 0) {
            if (func_020399B8((u8 *)func_020399A8()) != 0) {
                func_02082BCC(p + 0x1f4, 0, 0x40);
                func_02039C68((struct Link *)func_020399A8(), 14, 10);
                *(u16 *)(p + 0x244) = 0;
                func_021BAAB8(p, 0x45, 0);
                func_021BC090(p);
                *(int *)(p + 0x1cc) = 0x2a;
            }
        } else if (*(int *)(p + 0x1e0) == 1) {
            if (func_0203D1A4((struct Link *)func_020399A8()) != 0) {
                if (func_02039ACC() == 1) *(int *)(p + 0x1e0) = 0;
            } else if (func_020399EC() != 0 && func_02039ACC() == 1) {
                *(int *)(p + 0x1e0) = 0;
            }
        }
    }
    return ret;
}
