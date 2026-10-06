/*
 * function: func_021B97BC
 * address: 0x021B97BC
 * packet: pkt_ov181_021B97BC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9CC8 0x021B9CC8 thumb ov181
 *   func_021BA5E8 0x021BA5E8 thumb ov181
 *   func_021BA6F0 0x021BA6F0 thumb ov181
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_021BA2AC 0x021BA2AC thumb ov181
 *   func_021BA390 0x021BA390 thumb ov181
 *   d_021BABD0 0x021BABD0 data a4
 */
#include "../include/Obj01003.h"
#include "../include/Obj24500.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
typedef int (*Command)(char *,char *);
extern const Command d_021BABD0[];
extern void func_021B9CC8(char *);
extern int func_021BA5E8(char *),func_021BA6F0(char *);
extern int func_02005F38(void);
extern void func_02005E30(u32);
extern int func_021BA2AC(u8 *p, int a);
extern void func_021BA390(char *);
int func_021B97BC(char *p) {
    char *row;
    if(((struct Obj01003 *)p)->f2EC==0) {
        for(;;) {
            row=*(char * *)&((struct Obj01003 *)p)->f2D4+((struct Obj01003 *)p)->f2D8*16;
            if(((struct Obj01003 *)p)->f2D8==*(u32 *)((u32)p+((struct Obj01003 *)p)->f2BB*8+0xbc)) {
                func_021B9CC8(p);
                (((struct Obj01003 *)p)->f2BB)++;
                *(u16 *)&((struct Obj01003 *)p)->f2DA=((struct Obj24500 *)row)->f4;
                ((struct Obj01003 *)p)->f2EC=1;
                ((struct Obj01003 *)p)->f2D8+=2;
                break;
            }
            if(d_021BABD0[*(u8 *)(row+6)](p,row)==1) {
                (((struct Obj01003 *)p)->f2D8)++;
                break;
            }
            (((struct Obj01003 *)p)->f2D8)++;
        }
    }
    switch(((struct Obj01003 *)p)->f2EC) {
    case 1:
        if(((struct Obj01003 *)p)->f2DA<=0) {
            ((struct Obj01003 *)p)->f2DA=0; ((struct Obj01003 *)p)->f2EC=0;
        } else if(((struct Obj01003 *)p)->f2D2==1) ((struct Obj01003 *)p)->f2DA-=4;
        else (((struct Obj01003 *)p)->f2DA)--;
        break;
    case 2: if(func_021BA5E8(p)==0) ((struct Obj01003 *)p)->f2EC=0; break;
    case 3: if(func_021BA6F0(p)==0) ((struct Obj01003 *)p)->f2EC=0; break;
    case 5:
        if(func_02005F38()==1) func_02005E30(64);
        return func_021BA2AC((u8 *)p,2);
    }
    func_021BA390(p);
    return 4;
}
