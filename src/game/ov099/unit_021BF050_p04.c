/*
 * file:     unit_021BF050_p04.c
 * unit:     yes
 * function: func_021BFDA8, func_021BFDD0, func_021BFE54, func_021BFE9C
 * address:  0x021BFDA8
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
 *   func_021563EC 0x021563EC thumb ov009
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_020399EC 0x020399EC arm
 *   func_021563D0 0x021563D0 thumb ov009
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203C554 0x0203C554 arm
 *   func_021BA928 0x021BA928 thumb ov099
 */
#include "../../matched/include/Obj22052.h"
#include "../../matched/include/Obj07958.h"
#include "../../matched/include/Obj10209.h"
#include "../../matched/include/Obj00008.h"

struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned int   u32;

extern int func_021563EC(void);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern unsigned func_02039CB4(struct Link *,unsigned,unsigned);
extern int func_020399EC(void);
extern void func_021563D0(void);
extern void func_021C24A4(char *,int);
extern void func_021BA8EC(char *);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_0203C554(u32 a);
extern int func_021BA928(void *);
int func_021BFDA8(char *p, int ret);
int func_021BFDD0(char *p,int ret);
int func_021BFE54(char *p, int ret);
int func_021BFE9C(char *p,int ret);

/*
 * Extent ends with two-byte alignment padding at 0x021BFDCE.
 */
int func_021BFDA8(char *p, int ret) {
 if (!func_021563EC()) { func_02039C68((struct Link *)func_020399A8(),24,10); ((struct Obj22052 *)p)->f1CC=172; }
 return ret;
}

int func_021BFDD0(char *p,int ret) {
    ((struct Obj07958 *)p)->f1355=0;
    if(func_02039CB4((struct Link *)func_020399A8(),18,10) || func_020399EC()!=2) {
        if((unsigned)(((struct Obj07958 *)p)->f135C-3)<=1){
            func_021563D0();
            func_021C24A4(p,127);
            func_021BA8EC(p);
            func_021C18C8(p,3,3);
            ((struct Obj07958 *)p)->f1CC=154;
        } else {
            func_021C18C8(p,1,2);
            func_0203D7B0(0); func_0203D7BC(0);
            func_02039C68((struct Link *)func_020399A8(),21,10);
            ((struct Obj07958 *)p)->f1CC=159;
        }
    }
    return ret;
}

int func_021BFE54(char *p, int ret) {
    if (func_02039CB4((struct Link *)func_020399A8(),21,10) || func_020399EC()!=2) {
        func_0203C554(1);
        ((struct Obj10209 *)p)->f1F0=-1;
        ((struct Obj10209 *)p)->f1E0=20;
        func_021BA8EC(p);
        ((struct Obj10209 *)p)->f1CC=57;
    }
    return ret;
}

int func_021BFE9C(char *p,int ret) {
 if (!func_021BA928(p)) return ret;
 if (--((struct Obj00008 *)p)->f1E0<0) {
  func_02039C68((struct Link *)func_020399A8(),18,10);
  ((struct Obj00008 *)p)->f1CC=147;
 }
 return ret;
}
