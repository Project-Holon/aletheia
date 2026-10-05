/*
 * function: func_021E0954
 * address: 0x021E0954
 * packet: pkt_ov183_021E0954
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: The explicit entry guard encloses a do-while; a for adds a second entry test (308 B DIFF to 306 B EXACT*).
 * trailing: 021E0A86..021E0A88 is two zero alignment bytes.
 * abi: 0204B294 caller uses returned r0 despite callee's void spelling; fifth payload remains its u32 address word.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`heapA=0x25c;` before `heapA=0x34c;`; `aA=0x25c;` before `aA=0x26c;` and
 * 5 more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_021E0E40 0x021E0E40 thumb ov183
 */
#include "../include/Obj08316.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
struct Obj;
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);
extern int func_021E0E40(int,int);
void func_021E0954(char *p)
{
    int i,special,normal,base;
    u32 owner;
    int heapA,aA,bA,cA,heapB,aB,bB,cB,countOffset,recordOffset;
    Params params;
    normal=0;
    base=0x25c;
    owner=*(u32 *)(p+base);
    params.a=normal;params.b=normal;params.c=normal;params.flag=10;params.pad=normal;
    special=0;i=0;
    if(*(int *)(p+base-0x20)+2>0) {
        heapA=0x34c;
        aA=0x26c;
        bA=0x260;
        cA=0x284;
        heapB=0x34c;
        aB=0x26c;
        bB=0x260;
        cB=0x284;
        countOffset=0x23c;
        recordOffset=0x150;
        do {
            char *q;
            q=p+special*28;
            if(i==*(int *)(q+recordOffset)+special+1) {
                void *obj;
                params.a=i*8+76;params.b=24;params.c=22;
                obj=func_0204B294((void *)owner,*(u32 *)(p+aB),*(u32 *)(p+bB),*(u32 *)(p+cB),&params,1,*(u16 *)(p+heapB));
                ((struct Obj08316 *)q)->f15C=obj;func_0204B688(obj,1);
                special++;
            } else {
                void *obj;
                params.a=i*8+76;params.b=24;
                q=p+normal*28;
                params.c=func_021E0E40(((struct Obj08316 *)q)->f0,((struct Obj08316 *)q)->f8);
                obj=func_0204B294((void *)owner,*(u32 *)(p+aA),*(u32 *)(p+bA),*(u32 *)(p+cA),&params,1,*(u16 *)(p+heapA));
                ((struct Obj08316 *)q)->fC=obj;func_0204B688(obj,1);
                normal++;
            }
            i++;
        } while(i<*(int *)(p+countOffset)+2);
    }
}
