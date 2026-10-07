/*
 * file:     p_sta_oam_p08.c
 * unit:     yes
 * function: func_021D62B4, func_021D62E4, func_021D62F4
 * address:  0x021D62B4
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
 *   func_02045770 0x02045770 arm
 *   func_021D6244 0x021D6244 thumb ov131
 *   func_021DBF2C 0x021DBF2C thumb ov131
 *   func_02017E88 0x02017E88 thumb
 */
#include "../../matched/include/Obj23130.h"
#include "../../matched/include/Obj23131.h"

struct Descriptor;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern void *func_02045770(struct Descriptor *p);
extern void func_021D6244(unsigned char *,int,void *,int,unsigned short,unsigned short,unsigned short);
extern unsigned int func_021DBF2C(unsigned int, unsigned int);
extern u32 func_02017E88(void *p, u32 id, u32 v);
void func_021D62B4(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f);
int func_021D62E4(char *p);
int func_021D62F4(char *p, void *q);

void func_021D62B4(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 func_021D6244(p,(int)func_02045770((struct Descriptor *)a),b,c,d,e,f);
}


int func_021D62E4(char *p)
{
    char *q = *(char * *)&((struct Obj23130 *)p)->f8;

    return ((struct Obj23131 *)q)->f20 == 1;
}

int func_021D62F4(char *p, void *q)
{
    unsigned char i;
    for (i = 0; i < 0x50; i++) {
        if (func_02017E88(q, func_021DBF2C(i, 0), 0) == 1) {
            return 1;
        }
    }
    return 0;
}
