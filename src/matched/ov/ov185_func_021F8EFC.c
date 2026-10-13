/*
 * function: func_021F8EFC
 * address: 0x021F8EFC
 * packet: pkt_ov185_021F8EFC
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 */
#include "../include/Obj00278.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021FC4DC(u8 *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern void func_021FFE5C(char *);
void func_021F8EFC(char *p,int *source)
{
    if(*(int *)&((struct Obj00278 *)p)->f0==0) {
        int c=func_021FC4DC((u8 *)source[2]);
        char *result;
        if(*(int *)&((struct Obj00278 *)p)->f4==0)
            ((struct Obj00278 *)p)->f4=func_021FD12C((int)((void *)source[3]),(void *)(*(int *)&((struct Obj00278 *)p)->f2C),((struct Obj00278 *)p)->f30);
        func_021FD170(((struct Obj00278 *)p)->f4,(void *)source[3],(void *)0x2c);
        result=func_021FFBD4(ZUKAN_SAVE_GetFromGameData((void *)source[6]),(void *)source[3],c,*(int *)&((struct Obj00278 *)p)->f28,source[0],((struct Obj00278 *)p)->f38,((struct Obj00278 *)p)->f3C,((struct Obj00278 *)p)->f30);
        *(char * *)&((struct Obj00278 *)p)->f0=result;
        func_021FFE5C(result);
    }
}
