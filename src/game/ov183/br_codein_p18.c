/*
 * file:     br_codein_p18.c
 * unit:     yes
 * function: func_021DF388, func_021DF3DC
 * address:  0x021DF388
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF5B8 0x021DF5B8 thumb ov183
 *   func_021FCE0C 0x021FCE0C thumb ov186
 *   func_021FCDE8 0x021FCDE8 thumb ov186
 *   func_020437AC 0x020437AC arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021DF620 0x021DF620 thumb ov183
 */
#include "../../matched/include/Obj02522.h"
#include "../../matched/include/Obj00786.h"

struct Obj020437AC;
struct WordSet;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed char s8;

extern void func_021DF5B8(char *);
extern int func_021FCE0C(char *p, unsigned field);
extern u32 func_021FCDE8(u8 *p, u16 i);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021FCC80(char *p);
extern u32 func_0201F868(void *p);
extern void func_02082BCC(void *, int, unsigned int);
extern void func_021FCD0C(char *p);
extern void func_021DF620(char *, unsigned int, s8, int);
void func_021DF388(char *p);
void func_021DF3DC(char *p, int a);

/*
 * trailing: two zero alignment bytes at 0x021DF3DA
 */
void func_021DF388(char *p)
{
    unsigned int i;
    func_021DF5B8(p);
    for (i = 0; i < func_021FCE0C(((struct Obj02522 *)p)->f4, 3); i++) {
        func_020437AC((struct Obj020437AC *)func_021FCDE8(((struct Obj02522 *)p)->f4, i));
    }
    func_0201ED04(((struct Obj02522 *)p)->f8);
    func_021FCC80(((struct Obj02522 *)p)->f4);
    func_0201F868(((struct Obj02522 *)p)->f0);
    func_02082BCC(p, 0, 0xD4);
}

/*
 * trailing: two zero alignment bytes at 0x021DF41A
 */
void func_021DF3DC(char *p, int a)
{
    unsigned int old, current;
    s8 direction;
    old = func_021FCE0C(((struct Obj00786 *)p)->f4, 1);
    func_021FCD0C(((struct Obj00786 *)p)->f4);
    current = func_021FCE0C(((struct Obj00786 *)p)->f4, 1);
    direction = func_021FCE0C(((struct Obj00786 *)p)->f4, 2);
    if (direction != 0 && old != current) func_021DF620(p, current, direction, a);
}
