/*
 * file:     trcard_sys_p06.c
 * unit:     yes
 * function: func_0216F2E0, func_0216F31C
 * address:  0x0216F2E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02031324 0x02031324 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02031348 0x02031348 arm
 *   d_021C39D4 0x021C39D4 data ov110 a4
 *   ov110_id 0x0000006E data a1
 *   func_0216F088  0x0216F088  thumb  ov010
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E714  0x0200E714  thumb
 *   func_0202715C  0x0202715C  thumb
 */
#include "../../matched/include/Obj01640.h"
#include "../../matched/include/Obj19155.h"

struct Big;
struct Rec0200E714;
typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02031324(int a0);
extern void *func_02012EBC(struct Big *p);
extern void func_02031348(void *,u32,const void *,void *);
extern int func_0216F088(int a0);
extern int func_0200E6F0(void);
extern void func_0200E714(struct Rec0200E714 *dst, int idx, struct Rec0200E714 *src);
extern void func_0202715C(u32 a0);
int func_0216F2E0(char *p);
int func_0216F31C(char *a);
extern const u32 d_021C39D4[];
extern char ov110_id[];

/*
 * Interface: 02031324 veneer forwards heap in r0 and returns allocation from
 * 02031354; 02031348 forwards all four arguments to 020314F4.
 */
int func_0216F2E0(char *p) { if (((struct Obj01640 *)p)->f8==0) ((struct Obj01640 *)p)->f8=func_02031324((u16)(((struct Obj01640 *)p)->f0)); ((struct Obj01640 *)p)->fC=func_02012EBC(((struct Obj19155 *)(*(char * *)&((struct Obj01640 *)p)->f18))->f4); func_02031348(((struct Obj01640 *)p)->f8,(u32)ov110_id,d_021C39D4,p+12); return 4; }


/*
 * Byte-correct. Blocker: func_0200E714 (site +004C) is an unlabelled ARM9 Thumb
 * leaf (copies four halfwords to dst[idx*4]) whose only caller is this
 * function; no witness. Its C is parked: docs/notes/pkt_ov010_0200E714.c.txt
 * (register naming r3/r4 swapped).
 */
int func_0216F31C(char *a)
{
    char *w;
    u16 *src;
    int t;

    if (func_0216F088((int)(a + 8)) == 0)
        return 4;
    if (*(u16 **)(a + 0x14) != 0) {
        func_02012EBC((struct Big *)(*(int *)(*(char **)(a + 0x18) + 4)));
        t = func_0200E6F0();
        w = **(char ***)(a + 0x18);
        src = *(u16 **)(a + 0x14);
        *(u16 *)(w + 0x6c) = src[0];
        *(u16 *)(w + 0x6e) = src[1];
        *(u16 *)(w + 0x70) = src[2];
        *(u16 *)(w + 0x72) = src[3];
        func_0200E714((struct Rec0200E714 *)t, 0, *(void **)(a + 0x14));
        func_0202715C((u32)(*(void **)(a + 0x14)));
    }
    return 1;
}
