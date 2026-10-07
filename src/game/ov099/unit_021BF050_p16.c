/*
 * file:     unit_021BF050_p16.c
 * unit:     yes
 * function: func_021C14EC, func_021C1510, func_021C158C, func_021C15C0
 * address:  0x021C14EC
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
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_020414AC 0x020414AC arm
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   func_020362DC 0x020362DC arm
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj10211.h"
#include "../../matched/include/Obj13703.h"
#include "../../matched/include/Obj22057.h"

struct Entry;
struct Link;
struct BigObj;
struct Sub020097BCFriend;
struct Sub020097BCObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C14EC;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int   u32_021C1510;

typedef unsigned int u32_021C158C;

typedef unsigned int u32_021C15C0;

extern int func_021BA928(void *p);
extern void func_021BA828(char *p);
extern int func_021C1154(char *p);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern u32_021C1510 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern int func_0200F4E4(void *o);
extern void func_021BA8EC(char *);
extern int func_02156A3C(void);
extern int func_021C23B8(int i);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_020414AC(int);
extern int func_021BE4F0(char *,int);
extern int func_021BF03C(char *);
extern u32_021C15C0 func_020362DC(void);
BOOL func_021C14EC(char *p);
int func_021C1510(char *p, int ret);
int func_021C158C(char *p,int ret);
int func_021C15B4(char *p,int ret);
int func_021C15C0(char *p,int ret);


/*
 * True when the guard answers true or the pointer 0x190 bytes in is still unset.
 */
BOOL func_021C14EC(char *p)
{
    if (func_021BA928(p) != 0) {
        return 1;
    }

    if (((struct Obj00008 *)p)->f190 == 0) {
        return 1;
    }

    return 0;
}

int func_021C1510(char *p, int ret)
{
    void *s;
    unsigned count;
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 18, 10) != 0) {
            if (func_021C14EC(p) == 1) {
                func_0200F4E4(func_020099C8((struct Sub020097BCObj *)func_0201283C(((struct Obj10211 *)p)->fC4), 0));
                func_021BA8EC(p);
                s = (void *)func_021C23B8(func_02156A3C());
                func_021BDD48(p, s);
                count = func_021BDD54(p, s);
                if (count == 3) {
                    ((struct Obj10211 *)p)->f1CC = 65;
                } else {
                    func_021C18C8(p, 4, count);
                    ((struct Obj10211 *)p)->f1CC = 115;
                }
            }
        }
    }
    return ret;
}

int func_021C158C(char *p,int ret){func_020414AC(3);((struct Obj13703 *)p)->f1358=0;((struct Obj13703 *)p)->f1CC=func_021BE4F0(p,0);return ret;}

int func_021C15B4(char *p,int ret){((struct Obj22057 *)p)->f1CC=47;return ret;}

/*
 * Extent remainder: two-byte alignment padding.
 */
int func_021C15C0(char *p,int ret){if(!func_021BA928(p))return ret;if(func_021BF03C(p))((struct Obj00008 *)p)->f1CC=48;if(func_020362DC()&3)((struct Obj00008 *)p)->f1CC=48;return ret;}
