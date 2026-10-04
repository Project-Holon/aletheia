/*
 * function: func_021BE600
 * address: 0x021BE600
 * packet: pkt_ov099_021BE600
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C24D4 0x021C24D4 thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   func_02156D84 0x02156D84 thumb ov009
 *   func_021563D0 0x021563D0 thumb ov009
 *   func_021BEEBC 0x021BEEBC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02005C4C 0x02005C4C thumb
 *   func_02005D90 0x02005D90 thumb
 */
#include "../include/Obj03733.h"
#include "../include/Obj22044.h"
#include "../include/Obj22045.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern void func_021C24D4(char *, int);
extern int func_02156A3C(void);
struct Sub020097BCObj;
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern int func_02156D84(void);
extern void func_021563D0(void);
extern void func_021BEEBC(char *);
extern void func_021C18C8(char *p, int kind, int value);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern u32 func_02005C4C(void);
extern void func_02005D90(int, int);
int func_021BE600(char *p, int ret)
{
    if (((struct Obj22044 *)(*(char * *)&((struct Obj03733 *)p)->f248))->fC) {
        func_021C24D4(p, 4);
        func_02009B80(((struct Obj03733 *)p)->f4, func_02156A3C());
        if ((unsigned)(((struct Obj03733 *)p)->f135C - 3) <= 1 && !func_02156D84()) {
            func_021563D0();
            func_021BEEBC(p);
            ((struct Obj03733 *)p)->f242 = ((struct Obj22045 *)(*(char * *)&((struct Obj03733 *)p)->f248))->f47;
            func_021C18C8(p, 4, 3);
            func_02039C68((struct Link *)func_020399A8(), 0x18, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0xac;
        } else {
            func_02039C68((struct Link *)func_020399A8(), 0x12, 0xa);
            ((struct Obj03733 *)p)->f1CC = 0x93;
        }
    } else {
        ((struct Obj03733 *)p)->f1CC = 9;
        func_021C24D4(p, 1);
    }
    if (func_02005C4C() != 0x424) func_02005D90(0x424, 0xffff);
    return ret;
}
