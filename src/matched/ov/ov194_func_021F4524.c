/*
 * function: NAMEIN_GRAPHIC_CommitName
 * address: 0x021F4524
 * packet: pkt_ov194_021F4524
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_Clone 0x02045874 arm
 *   NAMEIN_GRAPHIC_CopyToStrbuf 0x021F2328 thumb ov194
 *   STRBUF_IsEqual 0x0204589C arm
 *   NAMEIN_GRAPHIC_HasNonSpace 0x021F253C thumb ov194
 *   STRBUF_Copy 0x02045838 arm
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_GetLength 0x020458F8 arm
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
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
struct Strbuf;
extern void NAMEIN_GRAPHIC_CopyToStrbuf(char *,struct Strbuf *);
extern int STRBUF_IsEqual(struct Buf *a, struct Buf *b);
extern int NAMEIN_GRAPHIC_HasNonSpace(u8 *p);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
void NAMEIN_GRAPHIC_CommitName(char *p) {
    int text;
    char *obj;
    ((struct Obj24911 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=0;
    text=(int)STRBUF_Clone((struct U16Vec *)(((struct Obj24912 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),30);
    NAMEIN_GRAPHIC_CopyToStrbuf(p+0x68,(struct Strbuf *)((struct Obj24913 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20);
    if (STRBUF_IsEqual((struct Buf *)text,(struct Buf *)(((struct Obj24914 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20)))
        ((struct Obj24915 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    if (!NAMEIN_GRAPHIC_HasNonSpace((u8 *)((int)(p+0x68)))) {
        STRBUF_Copy((struct U16Vec *)(((struct Obj24916 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20),(struct U16Vec *)text);
        ((struct Obj24917 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f1C=1;
    }
    STRBUF_Delete((struct U16Vec *)text);
    if (!STRBUF_GetLength((struct U16Vec *)(((struct Obj24918 *)(*(char * *)&((struct Obj03343 *)p)->f2C4))->f20))) {
        obj=*(char * *)&((struct Obj03343 *)p)->f2C4;
        if (((struct Obj10811 *)obj)->f0!=0 && ((struct Obj10811 *)obj)->f0!=3) ((struct Obj10811 *)obj)->f1C=1;
    }
}
