/*
 * file:     unit_021E002C.c
 * unit:     yes
 * function: func_021E002C, func_021E0068, func_021E00C4, func_021E0128, func_021E0190, func_021E01A8
 * address:  0x021E002C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DE5F8 0x021DE5F8 thumb ov170
 *   func_021DD930 0x021DD930 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   func_021DE158 0x021DE158 thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_021EC804 0x021EC804 thumb
 *   func_021EE26C 0x021EE26C thumb
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF6E0 0x021EF6E0 thumb ov170
 */
#include "box2_types.h"
#include "../../matched/include/Obj23868.h"
#include "../../matched/include/Obj23869.h"
#include "../../matched/include/Obj23870.h"
#include "../../matched/include/Obj23871.h"
#include "../../matched/include/Obj23872.h"
#include "../../matched/include/Obj23873.h"
#include "../../matched/include/Obj23874.h"
#include "../../matched/include/Obj23875.h"
#include "../../matched/include/Obj23876.h"
#include "../../matched/include/Obj23877.h"
#include "../../matched/include/Obj18461.h"

struct WinMgr;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u16 id,slot,src,used;int vx,vy;short dx,dy,x,y;} Entry;

extern void func_021DE5F8(u8 *,unsigned);
extern int func_021DD930(u8 *);
extern void func_021DE66C(char *,Entry *);
extern unsigned POKEPARTY_GetCount(void *p);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern void func_021ED6E4(char **p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021ED55C(char **p, int flag);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EDF5C(unsigned char *p);
extern void func_02041EE4(unsigned index, unsigned a, unsigned b);
extern void func_021EC804(char **p, short dx);
extern void func_021EE26C(char *p, int d);
extern int func_021EF5C4(struct WinMgr *mgr);
extern unsigned func_021EF6E0(char *p);
int func_021E002C(u8 *p);
int func_021E0068(char *p);
int func_021E00C4(char *p);
int func_021E0128(char *p);
int func_021E0190(char *p);
int func_021E01A8(char *p);

int func_021E002C(u8 *p){char *s;s=*(char * *)&((BoxTask *)p)->f2C+0x58;switch(((BoxSeq *)s)->fC){case 0:func_021DE5F8(p,p[0x16]);(((BoxSeq *)s)->fC)++;case 1:if(func_021DD930(p)==0){func_021DE66C((char *)p,*(Entry * *)&((BoxSeq *)s)->f8);((BoxSeq *)s)->fC=0;return 0;}break;}return 1;}

/*
 * lever: bind the full party-count-plus-30 expression to an int local.
 */
int func_021E0068(char *p)
{
    char *s;
    int count;
    s = *(char * *)&((BoxTask *)p)->f2C + 0x58;
    switch (((BoxSeq *)s)->fC) {
    case 0:
        count = POKEPARTY_GetCount((*(void *** )p)[2]) + 30;
        func_021DE158((unsigned char *)p, ((BoxTask *)p)->f16, count);
        func_021ED6E4((char **)p, 0);
        (((BoxSeq *)s)->fC)++;
        break;
    case 1:
        if (func_021DD930((unsigned char *)p) == 0) {
            func_021DE66C(p, ((BoxSeq *)s)->f8);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((BoxSeq *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}


int func_021E00C4(char *p)
{
    if (((struct Obj23868 *)(*(char * *)&((BoxTask *)p)->f2C))->f66 == 0x17) {
        func_021ED55C((char **)p, 1);
        if (func_021EF770(*(struct WinMgr * *)&((struct Obj23869 *)(*(char * *)&((BoxTask *)p)->f2C))->f74) == 1)
            func_021EDF5C((unsigned char *)p);
        ((struct Obj23870 *)(*(char * *)&((BoxTask *)p)->f2C))->f66 = 0;
        return 0;
    }
    func_02041EE4(3, 2, 8);
    func_021EC804((char **)p, 8);
    func_021EE26C(*(char * *)&((BoxTask *)p)->f2C, 8);
    func_021EF5C4(*(struct WinMgr * *)&((struct Obj23871 *)(*(char * *)&((BoxTask *)p)->f2C))->f74);
    (((struct Obj23872 *)(*(char * *)&((BoxTask *)p)->f2C))->f66)++;
    return 1;
}


int func_021E0128(char *p)
{
    if (((struct Obj23873 *)(*(char * *)&((BoxTask *)p)->f2C))->f66 == 0x17) {
        func_021ED55C((char **)p, 1);
        if (func_021EF770(*(struct WinMgr * *)&((struct Obj23874 *)(*(char * *)&((BoxTask *)p)->f2C))->f74) == 1)
            func_021EDF5C((unsigned char *)p);
        ((struct Obj23875 *)(*(char * *)&((BoxTask *)p)->f2C))->f66 = 0;
        return 0;
    }
    func_02041EE4(3, 1, 8);
    func_021EC804((char **)p, -8);
    func_021EE26C(*(char * *)&((BoxTask *)p)->f2C, -8);
    func_021EF5C4(*(struct WinMgr * *)&((struct Obj23876 *)(*(char * *)&((BoxTask *)p)->f2C))->f74);
    (((struct Obj23877 *)(*(char * *)&((BoxTask *)p)->f2C))->f66)++;
    return 1;
}

/*
 * 1 when the p+0x2c+0x74 object is live.
 */
int func_021E0190(char *p)
{
    if (func_021EF5C4(*(struct WinMgr **)(((struct Obj18461 *)p)->f2C + 0x74)) != 0)
        return 1;
    return 0;
}

/*
 * Tail forwarder; following code starts at 021E01B0.
 */
int func_021E01A8(char *p)
{
    return func_021EF6E0(p);
}
