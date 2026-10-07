/*
 * file:     unit_021B95A0_p03.c
 * unit:     yes
 * function: func_021B9F1C, func_021B9F40, func_021B9F9C, func_021B9FD8
 * address:  0x021B9F1C
 * region:   ov181
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02048C4C 0x02048C4C arm
 *   func_020480E4 0x020480E4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_02046788 0x02046788 arm
 *   func_02043658 0x02043658 arm
 *   func_021BA2D8 0x021BA2D8 thumb ov181
 *   func_021BA128 0x021BA128 thumb ov181
 *   func_02047910 0x02047910 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047970 0x02047970 arm
 *   d_021BAC2C 0x021BAC2C data a4
 *   d_021BACE4 0x021BACE4 data a4
 */
#include "../../matched/include/Obj03877.h"
#include "../../matched/include/Obj06588.h"
#include "../../matched/include/Obj14410.h"
#include "../../matched/include/Obj10722.h"

struct Ctx;
struct Rec;
struct Arg;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(void *);
extern void func_020480E4(struct Ctx *,unsigned);
extern void func_02047E54(struct Rec *);
extern void func_02046788(void);
extern unsigned func_02043658(void);
extern void func_021BA2D8(char *);
extern void func_021BA128(char *);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_02047970(void);
void func_021B9F1C(char *p);
void func_021B9F40(char *p);
void func_021B9F9C(u8 *p);
void func_021B9FD8(u8 *p,int a,int b);
extern const unsigned d_021BAC2C[];
extern const u8 d_021BACE4[];

/*
 * Verified scratch blocker.c with one --arm (no --region), fixed flags: EXACT, 12 bytes.
 * extern void func_020307B0(void *);
 * void func_02048C4C(void *p) { func_020307B0(p); }
 * Blocker symbols: func_020307B0 0x020307B0 arm.
 */
void func_021B9F1C(char *p){func_02048AC4(*(void **)(p+12));func_02048C4C(*(void **)(p+16));func_020480E4(*(struct Ctx **)(p+8),*(unsigned short *)(p+24));func_02047E54(*(struct Rec **)(p+8));func_02046788();}

void func_021B9F40(char *p)
{
    unsigned i;
    if (**(int * *)&((struct Obj03877 *)p)->f0 != 1 && (func_02043658() & 1)) {
        func_021BA2D8(p);
        func_021BA128(p);
        for (i = 0; i < ((struct Obj03877 *)p)->f24; i++)
            func_02047910(((struct Obj03877 *)p)->f20, (unsigned short)i, 0x1000);
        func_02047964();
        func_020479D8();
        func_02047A60(((struct Obj03877 *)p)->f20, (struct Arg *)d_021BAC2C);
        func_02047970();
    }
}

void func_021B9F9C(u8 *p){u32 i;*(const void * *)&((struct Obj06588 *)p)->f0=d_021BACE4;((struct Obj06588 *)p)->f74=7;((struct Obj06588 *)p)->f78=0;((struct Obj06588 *)p)->f76=0;((struct Obj06588 *)p)->f7C=0;for(i=0;i<16;i++){u8 *q=p+i*4;((struct Obj14410 *)q)->f34=65535;((struct Obj14410 *)q)->f36=0;}}

void func_021B9FD8(u8 *p,int a,int b){u32 i;for(i=0;i<16;i++){u8 *q=p+i*4;if(((struct Obj10722 *)q)->f34==65535){((struct Obj10722 *)q)->f34=a;((struct Obj10722 *)q)->f36=b;return;}}}
