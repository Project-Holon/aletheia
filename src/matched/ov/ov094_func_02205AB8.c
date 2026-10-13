/*
 * function: func_02205AB8
 * address: 0x02205AB8
 * packet: pkt_ov094_02205AB8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: entry reads use the indexed aggregate; the zero store uses its raw
 * offset. This avoids retaining a common entry pointer across both frees.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0220684C 0x0220684C thumb ov094
 *   func_02204C48 0x02204C48 thumb ov094
 *   d_0220AEB0 0x0220AEB0 data ov094 a1
 */
#include "../include/Obj01049.h"
typedef unsigned short u16;
typedef struct { void *entry; int extra; } Entry;
typedef struct { char pad[0x1c8]; Entry entries[3]; } Work;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(unsigned int h);
extern void CLACT_ReleaseCellAnim(unsigned int h);
extern void CLACT_ReleasePalette(unsigned int h);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern void *func_020056A0(void *cb, void *ctx, int a);
extern void func_0220684C(char *p, int a, int b);
extern void func_02204C48(void *, int *);
extern const char d_0220AEB0[];
void func_02205AB8(char *p)
{
    int i;
    int empty = 1;
    int *ctx;
    for (i = 0; i < 3; i++) {
        if (((Work *)p)->entries[i].entry != 0) {
            CLACT_DeleteActor(((Work *)p)->entries[i].entry);
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x1b0));
            *(void **)(p + i * 8 + 0x1c8) = 0;
            *(int *)(p + i * 4 + 0x1b0) = -1;
            empty = 0;
        }
    }
    if (((struct Obj01049 *)p)->f1C0 != -1) {
        CLACT_ReleaseCellAnim(((struct Obj01049 *)p)->f1C0);
        ((struct Obj01049 *)p)->f1C0 = -1;
    }
    if (((struct Obj01049 *)p)->f1BC != -1) {
        CLACT_ReleasePalette(((struct Obj01049 *)p)->f1BC);
        ((struct Obj01049 *)p)->f1BC = -1;
    }
    if (!empty) {
        ctx = func_02030734((u16)((((struct Obj01049 *)p)->f240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x11b2);
        ctx[0] = (int)p;
        func_0220684C(p, (int)func_020056A0((void *)func_02204C48, ctx, 0), 0);
    }
}
