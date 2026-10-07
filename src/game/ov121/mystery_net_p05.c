/*
 * file:     mystery_net_p05.c
 * unit:     yes
 * function: func_021DE500, func_021DE550, func_021DE570
 * address:  0x021DE500
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D798 0x0203D798 arm
 *   func_021DE5D8 0x021DE5D8 thumb ov121
 *   func_021DE5F8 0x021DE5F8 thumb ov121
 *   func_020103E4 0x020103E4 thumb
 *   func_021DE308 0x021DE308 thumb ov121
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CA98 0x0203CA98 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_02059F18 0x02059F18 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_0200FA84 0x0200FA84 thumb
 */
#include "../../matched/include/Obj10422.h"
#include "../../matched/include/Obj22914.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0203CD98(void);
extern char *func_0203D798(void);
extern int func_021DE5D8(void *);
extern int func_021DE5F8(void *);
extern void func_020103E4(u8 *);
extern void func_021DE308(char *,unsigned);
extern void func_0200FBA0(void);
extern u32 func_0200FB24(void);
extern u32 func_0203CA98(void);
extern void func_0203CA04(void);
extern void func_02059F18(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
extern void func_0200FA84(void);
int func_021DE500(void *p);
void func_021DE550(char *p);
int func_021DE570(char *p);

/*
 * extent: two bytes of zero alignment padding after the return.
 */
int func_021DE500(void *p)
{
    int result=0;
    if (func_0203CD98()) {
        switch (*(unsigned char *)(func_0203D798()+0x65)) {
        case 0: case 5: result=func_021DE5D8(p); break;
        case 1: result=func_021DE570(p); break;
        case 3: result=func_021DE5F8(p); break;
        case 2: case 4: default: break;
        }
    }
    return result;
}

void func_021DE550(char *p) {if(*(u8 * *)&((struct Obj10422 *)p)->f10) {func_020103E4(*(u8 * *)&((struct Obj10422 *)p)->f10); *(int *)&((struct Obj10422 *)p)->f10=0;} func_021DE308(p,0); func_0200FBA0();}

int func_021DE570(char *p)
{
    int result=0;
    if (func_0200FB24()) {
        switch (*(unsigned *)(func_0203CA98()+4)) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            if (((struct Obj22914 *)p)->f790==1) return result;
            func_0203CA04();
            func_02059F18();
            func_0200FBB0();
            func_0200F83C();
            func_0200FBA0();
            result=1; break;
        case 7:
            func_0203CA04();
            func_0200FA84();
            result=3; break;
        case 0: default: break;
        }
    }
    return result;
}
