/*
 * function: func_021F4524
 * address: 0x021F4524
 * packet: pkt_ov194_021F4524
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045874 0x02045874 arm
 *   func_021F2328 0x021F2328 thumb ov194
 *   STRBUF_IsEqual 0x0204589C arm
 *   func_021F253C 0x021F253C thumb ov194
 *   func_02045838 0x02045838 arm
 *   func_02045808 0x02045808 arm
 *   func_020458F8 0x020458F8 arm
 */
#include "../include/Obj03343.h"
#include "../include/Obj10811.h"
#include "../include/Obj24911.h"
#include "../include/Obj24912.h"
#include "../include/Obj24913.h"
#include "../include/Obj24914.h"
#include "../include/Obj24915.h"
#include "../include/Obj24916.h"
#include "../include/Obj24917.h"
#include "../include/Obj24918.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Buf;
struct U16Vec;
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
struct Strbuf;
extern void func_021F2328(char *,struct Strbuf *);
extern int STRBUF_IsEqual(struct Buf *a, struct Buf *b);
extern int func_021F253C(u8 *p);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
void func_021F4524(char *p) {
    int text;
    char *obj;
    ((struct Obj24911 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=0;
    text=(int)func_02045874((struct U16Vec *)(((struct Obj24912 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),30);
    func_021F2328(p+0x68,(struct Strbuf *)((struct Obj24913 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20);
    if (STRBUF_IsEqual((struct Buf *)text,(struct Buf *)(((struct Obj24914 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20)))
        ((struct Obj24915 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    if (!func_021F253C((u8 *)((int)(p+0x68)))) {
        func_02045838((struct U16Vec *)(((struct Obj24916 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),(struct U16Vec *)text);
        ((struct Obj24917 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    }
    func_02045808((struct U16Vec *)text);
    if (!func_020458F8((struct U16Vec *)(((struct Obj24918 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20))) {
        obj=*(char * *)&((struct Obj03343 *)p)->f2C4;
        if (((struct Obj10811 *)obj)->f0!=0 && ((struct Obj10811 *)obj)->f0!=3) ((struct Obj10811 *)obj)->f1C=1;
    }
}
