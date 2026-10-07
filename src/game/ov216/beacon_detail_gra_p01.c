/*
 * file:     beacon_detail_gra_p01.c
 * unit:     yes
 * function: func_021BBD80, func_021BBE18, func_021BBE7C, func_021BBF14, func_021BBF28, func_021BBF60, func_021BBF98, func_021BBFEC, func_021BC0B4
 * address:  0x021BBD80
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BC930 0x021BC930 thumb ov216
 *   func_021BC0C8 0x021BC0C8 thumb ov216
 *   func_021BC1E4 0x021BC1E4 thumb ov216
 *   func_021BC6D8 0x021BC6D8 thumb ov216
 *   func_021BC454 0x021BC454 thumb ov216
 *   func_021BC650 0x021BC650 thumb ov216
 *   func_021BC70C 0x021BC70C thumb ov216
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_021BC398 0x021BC398 thumb ov216
 *   ov067_id 0x00000043 data
 *   ov072_id 0x00000048 data
 *   func_021BC3D4 0x021BC3D4 thumb ov216
 *   func_021BC8A8 0x021BC8A8 thumb ov216
 *   func_021BC6B4 0x021BC6B4 thumb ov216
 *   func_021BC56C 0x021BC56C thumb ov216
 *   func_021BC6FC 0x021BC6FC thumb ov216
 *   func_021BC378 0x021BC378 thumb ov216
 *   func_021BC178 0x021BC178 thumb ov216
 *   func_021BC9D0 0x021BC9D0 thumb ov216
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BC3DC 0x021BC3DC thumb ov216
 *   func_021BCC10 0x021BCC10 thumb ov216
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BC920 0x021BC920 thumb ov216
 *   func_021BCA24 0x021BCA24 thumb ov216
 *   func_021BCCBC  0x021BCCBC  thumb  ov216
 *   func_021BCBA4 0x021BCBA4 thumb ov216
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_02165B10 0x02165B10 thumb ov010
 *   func_02012A54 0x02012A54 thumb
 *   func_020275A8 0x020275A8 thumb
 *   func_02165B04 0x02165B04 thumb ov010
 *   func_02165AC4 0x02165AC4 thumb ov010
 *   func_02165B5C 0x02165B5C thumb ov010
 *   func_02165C10 0x02165C10 thumb ov010
 *   func_02012FFC 0x02012FFC thumb
 *   func_021BBB24 0x021BBB24 thumb ov072
 *   func_021BBB34  0x021BBB34  thumb  ov072
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00366.h"
#include "../../matched/include/Obj01437.h"
#include "../../matched/include/Obj03374.h"
#include "../../matched/include/Obj25767.h"
#include "../../matched/include/Obj10942.h"
#include "../../matched/include/Obj05552.h"
#include "../../matched/include/Obj25768.h"
#include "../../matched/include/Obj14715.h"

struct Obj0203159C;
struct S021BC6B4;
struct S020315D4;
struct Tcbl;
struct PrintSys;
struct Queue;
struct Rec;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_02034AC4(int);
extern void func_0203064C(unsigned,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *,int,int);
extern void *func_021BC930(int,int);
extern void func_021BC0C8(char *);
extern void func_021BC1E4(char *p, u16 heap);
extern void func_021BC6D8(char *);
extern void func_021BC454(char *p, u32 handle);
extern void func_021BC650(char *);
extern void func_021BC70C(char *);
extern void *func_021BCA38(char *p);
extern void *func_021BC398(void *,unsigned);
extern void func_021BC3D4(unsigned char *p);
extern void func_021BC8A8(char *);
extern void func_021BC6B4(struct S021BC6B4 *);
extern void func_021BC56C(char *);
extern unsigned func_021BC6FC(unsigned *);
extern void func_021BC378(char *);
extern void func_021BC178(char *);
extern void func_021BC9D0(unsigned *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
extern void func_021BC3DC(void *);
extern int func_021BCC10(unsigned char *);
extern void func_020310C4(struct Tcbl *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern int func_021BC920(unsigned *);
extern void func_021BCA24(char *);
extern void func_021BCCBC(u8 *p);
extern void func_021BCBA4(unsigned char *);
extern unsigned func_0201C6B4(const struct PrintSys *);
extern void func_0204E720(unsigned,int,int,int);
extern int func_0204E804(void);
extern int func_021B6448(unsigned char *);
extern u8 *func_02165B10(u32);
extern u32 func_02012A54(const struct BigObj *);
extern u32 func_020275A8(u32 a);
extern u8 func_02165B04(u8 *);
extern int func_02165AC4(struct Queue *,struct Rec *,u16 *,int);
extern int func_02165B5C(struct Rec *);
extern int func_02165C10(u8 *);
extern signed char func_02012FFC(void);
extern int func_021BBB24(int);
extern void func_021BBB34(void *p);
extern u32 func_020307B0(void *p);
int func_021BBD80(struct Obj0203159C *obj,int unused1,void *config);
int func_021BBE18(struct S020315D4 *heap,int unused1,int unused2,char *p);
int func_021BBE7C(int unused0,int *state,int unused2,char *p);
int func_021BBF0C(char *p);
int func_021BBF14(char *p);
int func_021BBF28(unsigned char *p);
int func_021BBF60(char *p);
int func_021BBF98(char *p);
void func_021BBFEC(u8 *p);
void func_021BC0B4(char *p);
extern unsigned char ov067_id[],ov072_id[];
extern unsigned char ov072_id[],ov067_id[];

int func_021BBD80(struct Obj0203159C *obj,int unused1,void *config)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov072_id);
    func_0203064C(1,119,3<<16);
    p=func_0203159C(obj,620,119);
    func_02082BCC(p,0,620);
    ((struct Obj00366 *)p)->f14=config;
    ((struct Obj00366 *)p)->f0=119;
    ((struct Obj00366 *)p)->f2=0x8077;
    ((struct Obj00366 *)p)->f50=func_021BC930(0,((struct Obj00366 *)p)->f0);
    func_021BBFEC((u8 *)p);
    func_021BC0C8(p);
    func_021BC1E4(p,((struct Obj00366 *)p)->f0);
    func_021BC6D8(p);
    func_021BC454(p,(u32)(((struct Obj00366 *)p)->f54));
    func_021BC650(p);
    func_021BC70C(p);
    ((struct Obj00366 *)p)->f124=func_021BC398(func_021BCA38(((struct Obj00366 *)p)->f50),((struct Obj00366 *)p)->f0);
    return 1;
}

int func_021BBE18(struct S020315D4 *heap,int unused1,int unused2,char *p)
{
    func_021BC3D4(((struct Obj01437 *)p)->f124);
    func_021BC8A8(p);
    func_021BC6B4((struct S021BC6B4 *)p);
    func_021BC56C(p);
    func_021BC6FC((unsigned *)p);
    func_021BC378(p);
    func_021BC178(p);
    func_021BC0B4(p);
    func_021BC9D0(*(unsigned * *)&((struct Obj01437 *)p)->f50);
    func_020315D4(heap);
    func_020306F0(119);
    func_02034A5C((int)ov072_id);
    func_02034A5C((int)ov067_id);
    return 1;
}

int func_021BBE7C(int unused0,int *state,int unused2,char *p)
{
    if (((struct Obj03374 *)p)->f10) return 1;
    if (*state>=2 && *state<=3) func_021BC3DC(((struct Obj03374 *)p)->f124);
    switch (*state) {
    case 0: *state=func_021BBF28((unsigned char *)p); break;
    case 1: *state=func_021BBF60(p); break;
    case 2: *state=func_021BBF0C(p); break;
    case 3: *state=func_021BBF14(p); break;
    case 4: *state=func_021BBF98(p); break;
    case 5: return 1;
    }
    func_020310C4(*(struct Tcbl * *)&((struct Obj03374 *)p)->f18);
    func_0201C4E4(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C);
    func_021BC920((unsigned *)p);
    func_021BCA24(*(char * *)&((struct Obj03374 *)p)->f50);
    return 0;
}

/*
 * follower: 021BBF0C pool-and-bx thunk forwarding to 021BCC10.
 */
int func_021BBF0C(char *p)
{
    return func_021BCC10((unsigned char *)p);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021BBF14(char *p)
{
    if (((struct Obj25767 *)p)->fC != 0)
        return 3;
    func_021BCCBC((u8 *)p);
    return 2;
}

int func_021BBF28(unsigned char *p){switch(((struct Obj03374 *)p)->f4){case 0:func_021BCBA4(p);(((struct Obj03374 *)p)->f4)++;break;case 1:if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C)){((struct Obj03374 *)p)->f4=0;return 1;}break;}return 0;}

int func_021BBF60(char *p){switch(((struct Obj10942 *)p)->f4){case 0:func_0204E720(3,16,0,0);(((struct Obj10942 *)p)->f4)++;break;case 1:if(func_0204E804()==0){((struct Obj10942 *)p)->f4=0;return 2;}break;}return 1;}

int func_021BBF98(char *p)
{
    switch (((struct Obj05552 *)p)->f4) {
    case 0:
        if (((struct Obj25768 *)(*(char * *)&((struct Obj05552 *)p)->f14))->f9==0) {
            func_021BC3DC(((struct Obj05552 *)p)->f124);
            if (func_021B6448(*(unsigned char * *)&((struct Obj05552 *)p)->f124)!=1) break;
        }
        func_0204E720(3,0,16,0);
        (((struct Obj05552 *)p)->f4)++;
        break;
    case 1:
        if (func_0204E804()==0) {
            ((struct Obj05552 *)p)->f4=0;
            return 5;
        }
        break;
    }
    return 4;
}

/*
 * Verified EXACT Thumb C copied from parked ov032_func_021F27D4 header:
 * u32 func_020275A8(u32 a) { return a; }
 * Singleton TU --suggest-split leaves caller out; no viable partition.
 * Trailing 021BC0B2..021BC0B4 is zero alignment padding.
 * lever: array index uses p[47]++ so byte count advances before the store.
 */
void func_021BBFEC(u8 *p)
{
    int i,count;
    *(u8 **)(p+40)=func_02165B10(*(u16 *)p);
    *(u32 *)(p+32)=func_02012A54(*(const struct BigObj **)(*(u8 **)(p+20)+4));
    *(void **)(p+36)=(void *)func_020275A8((u32)(*(void **)(p+32)));
    count=func_02165B04(*(u8 **)(p+36));
    p[48]=255;
    for(i=0;i<count;i++){
        func_02165AC4(*(struct Queue **)(p+36),*(struct Rec **)(p+40),(u16 *)(p+44),i);
        if(func_02165B5C(*(struct Rec **)(p+40))==0 && func_02165C10(*(u8 **)(p+40))==0){
            if((*(u8 **)(p+20))[8]==i)p[48]=p[47];
            p[p[47]++ +49]=i;
        }
    }
    if(p[48]==255 || p[48]>=p[47])p[48]=0;
    if(p[47]==0)*(u32 *)(p+16)=1;
    p[79]=func_02012FFC();
    *(int *)(p+28)=func_021BBB24(*(u16 *)p);
}


void func_021BC0B4(char *p)
{
    func_021BBB34((void *)(((struct Obj14715 *)p)->f1C));
    func_020307B0((void *)(((struct Obj14715 *)p)->f28));
}
