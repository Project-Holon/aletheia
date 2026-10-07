/*
 * file:     unit_021D85C0_p02.c
 * unit:     yes
 * function: func_021D8C90, func_021D8F78, func_021D8FA0, func_021D92E4, func_021D9320, func_021D9348
 * address:  0x021D8C90
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D9E48 0x021D9E48 thumb ov129
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_021DA320 0x021DA320 thumb ov129
 *   func_021D97CC 0x021D97CC thumb ov129
 *   func_021D97FC 0x021D97FC thumb ov129
 *   func_021D9E60 0x021D9E60 thumb ov129
 *   func_021D97B8 0x021D97B8 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 *   d_021DA830 0x021DA830 data a4
 *   d_021DA84C 0x021DA84C data a4
 *   func_021D9F40 0x021D9F40 thumb ov129
 *   func_021DA004 0x021DA004 thumb ov129
 *   d_021DA718 0x021DA718 data a4 ov129
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D9E98 0x021D9E98 thumb ov129
 *   func_021D93D4 0x021D93D4 thumb ov129
 *   func_021D9EE8 0x021D9EE8 thumb ov129
 *   d_021DA75C 0x021DA75C data a4
 *   func_020457B0 0x020457B0 arm
 *   func_0201F35C 0x0201F35C thumb
 *   func_02045AA8 0x02045AA8 arm
 *   func_02045808 0x02045808 arm
 */
#include "../../matched/include/Obj00361.h"
#include "../../matched/include/Obj00411.h"
#include "../../matched/include/Obj14053.h"
#include "../../matched/include/Obj06479.h"
#include "../../matched/include/Obj08137.h"

struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Pair;
struct U16Vec;
typedef unsigned char u8;

typedef short s16;

typedef unsigned short u16;

typedef struct { s16 x,y; } Pair;

typedef struct { int x,y; } Scale;

typedef unsigned int   u32;

typedef struct { int v[3][5]; } Tbl;

typedef struct { int state, value, flag; struct Obj *handle; char tail[12]; } Record;

typedef signed int     s32;

extern void func_021D9E48(char *,int,int);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021DA158(int x, int flag);
extern void func_021DA320(char *);
extern int func_021D97CC(u8 *p, int value);
extern int func_021D97FC(u8 *p, int value);
extern void func_021D9E60(u8 *p, int n);
extern void func_021D97B8(char *);
extern void func_021D8AF4(char *,int);
extern void func_021D9F40(char *),func_021DA004(char *);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32 a);
extern void func_021D9E98(char *p, int i);
extern void func_021D93D4(char *p);
extern void func_021D9EE8(char *p, int i, int j);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F35C(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045808(struct U16Vec *vec);
int func_021D8C90(char *p);
int func_021D8F78(char *p);
void func_021D8FA0(char *p);
int func_021D92E4(u8 *p);
int func_021D9320(u8 *p);
void func_021D9348(char *p);
extern const int d_021DA830[], d_021DA84C[];
extern const Tbl d_021DA75C;

int func_021D8C90(char *p)
{
    int i,n;
    char *q;
    Scale scale;
    Pair first,second;
    switch(((struct Obj00361 *)p)->f234) {
    case 0:
        func_021D9E48(p,0,0);
        for(i=0;i<((struct Obj00361 *)p)->f23C;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f18) {
                func_0204B454(((struct Obj00411 *)q)->fC,(struct PtS *)&first,0);
                first.x+=((struct Obj00411 *)q)->f14;
                first.y+=((struct Obj00411 *)q)->f16;
                func_0204B404(((struct Obj00411 *)q)->fC,(const struct Vec2 *)(&first),0);
                (((struct Obj00411 *)q)->f18)--;
                if(i>=((struct Obj00361 *)p)->f248 && i<((struct Obj00361 *)p)->f24C) {
                    scale.x=d_021DA830[((struct Obj00411 *)q)->f19];
                    scale.y=scale.x;
                    func_0204B5AC(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                    (((struct Obj00411 *)q)->f19)++;
                }
                if(i>=((struct Obj00361 *)p)->f250 && i<((struct Obj00361 *)p)->f254) {
                    scale.x=d_021DA84C[((struct Obj00411 *)q)->f19];
                    scale.y=scale.x;
                    func_0204B5AC(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                    (((struct Obj00411 *)q)->f19)++;
                }
            }
        }
        for(i=0;i<2;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f168) {
                func_0204B454(((struct Obj00411 *)q)->f15C,(struct PtS *)&second,0);
                second.x+=((struct Obj00411 *)q)->f164;
                second.y+=((struct Obj00411 *)q)->f166;
                func_0204B404(((struct Obj00411 *)q)->f15C,(const struct Vec2 *)(&second),0);
                (((struct Obj00411 *)q)->f168)--;
            }
        }
        if(((struct Obj00361 *)p)->f18==0) {
            for(i=((struct Obj00361 *)p)->f248;i<((struct Obj00361 *)p)->f24C;i++) {
                q=p+i*28;
                func_0204B878(((struct Obj00411 *)q)->fC,func_021DA158(((struct Obj00411 *)q)->f0,((struct Obj00411 *)q)->f8));
            }
            for(i=((struct Obj00361 *)p)->f250;i<((struct Obj00361 *)p)->f254;i++) {
                q=p+i*28;
                func_0204B878(((struct Obj00411 *)q)->fC,func_021DA158(((struct Obj00411 *)q)->f0,((struct Obj00411 *)q)->f8));
            }
            (((struct Obj00361 *)p)->f234)++;
        }
        (((struct Obj00361 *)p)->f238)++;
        break;
    case 1:
        for(i=((struct Obj00361 *)p)->f248;i<((struct Obj00361 *)p)->f24C;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f19!=6) {
                scale.x=d_021DA830[((struct Obj00411 *)q)->f19];
                scale.y=scale.x;
                func_0204B5AC(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                (((struct Obj00411 *)q)->f19)++;
            }
        }
        for(i=((struct Obj00361 *)p)->f250;i<((struct Obj00361 *)p)->f254;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f19!=6) {
                scale.x=d_021DA84C[((struct Obj00411 *)q)->f19];
                scale.y=scale.x;
                func_0204B5AC(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                (((struct Obj00411 *)q)->f19)++;
            }
        }
        (((struct Obj00361 *)p)->f238)++;
        if(((struct Obj00361 *)p)->f238==6) (((struct Obj00361 *)p)->f234)++;
        break;
    default:
        func_021DA320(p);
        if(((struct Obj00361 *)p)->f324==0) n=func_021D97CC((u8 *)p,((struct Obj00361 *)p)->f320);
        else n=func_021D97FC((u8 *)p,((struct Obj00361 *)p)->f320);
        func_021D9E60((u8 *)p,n);
        if(((struct Obj00361 *)p)->f240) func_021D9E48(p,0,1);
        func_021D97B8(p);
        func_021D8AF4(p,1);
        break;
    }
    return 0;
}

extern int (*d_021DA718[])(char *);

int func_021D8F78(char *p) { int v; v=d_021DA718[*(u32 *)(p+0x22c)](p); func_021D9F40(p); func_021DA004(p); return v; }


/*
 * 2026-10-05 (wave P2 lane Q4, pengy share, user-approved for this function only): first draft, no twin found.
 * Earlier (824 B): the flag at [sp+4] is a member of a local struct with the table (struct { int flag; Tbl t; } L);
 * rec[idx] reads go through a const Record pointer; up and left write the store in each arm.
 * 2026-10-05 (wave P2 lane Q4b, 25-compile cap): 836 bytes now, same size as the original, 21 bytes differ, all in
 * the head (first 0x34 bytes). Closed this lane: (b) the L-button block is EXACT: the store of idx - 1 is written in each
 * arm (if (idx == 0) { idx = n; p->188 = idx - 1; } else { p->188 = idx - 1; }); cross-jumping keeps the shared subs/str
 * and leaves the then-arm's b to the next instruction (docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md).
 * (c) the R-button block is EXACT: idx = p->188; if (idx == p->23C - 1) store 0 else store idx + 1, store in each arm.
 * Remaining residue (a): the original emits movs r0,#0; str r0,[sp,#4] right after the row ldrsh and movs r7,#0xbf late.
 * Here the flag store comes after the final ldr r4 (flag init after cur) or before ldr r6 / row ldrsh (row as a local, flag
 * init between row and col; a pointer to the row gives 18 bytes with the store after muls). scheduling off does not change
 * the head, so the order is IR order, not the scheduler. Pragmas tried this lane with no gain: opt_propagation,
 * opt_dead_assignments, peephole, scheduling (no change), opt_common_subs (836 B but 401 bytes differ),
 * opt_lifetimes (34 differ). Tried and rejected: empty else {}, a wrap helper with (n, cur) parameter order (no change).
 * d_021DA75C has no witness outside the function (the pool word is inside it): give it an overlay token
 * in the integrator step.
 *
 * 2026-10-05 (wave P2 lane Q4c): EXACT. The flag is a plain int local (spilled to [sp+4]), not a struct member:
 * row is read into a local, then flag = 0, then cur = T.v[row][col] (IR order puts the zero store right after the row load).
 * d_021DA75C resolves with the data hint without the ov129 token (data a4).
 */
void func_021D8FA0(char *p)
{
    Tbl T = d_021DA75C;
    int flag;
    int row;
    int cur;
    int idx, n, k;
    const Record *r = (const Record *)p;

    row = *(s16 *)(p + 0x1BA);
    flag = 0;
    cur = T.v[row][*(s16 *)(p + 0x1B8)];

    if (*(int *)(p + 0x2FC) == 1 && func_020362DC() != 0) {
        *(int *)(p + 0x2FC) = flag;
        func_021D9E98(p, cur);
        if (cur == 10 || cur == 11) {
            if (*(int *)(p + 0x1A4) == 2) return;
            *(int *)(p + 0x1A4) = 2;
            return;
        }
        if (*(int *)(p + 0x1A4) == 1) return;
        *(int *)(p + 0x1A4) = 1;
        return;
    }
    if (func_0203633C() & 0x40) {
        int v = *(s16 *)(p + 0x1BA);
        if (v > 0) *(s16 *)(p + 0x1BA) = v - 1; else *(s16 *)(p + 0x1BA) = 2;
        flag = 1;
    } else if (func_0203633C() & 0x80) {
        *(s16 *)(p + 0x1BA) += 1;
        *(s16 *)(p + 0x1BA) %= 3;
        flag = 1;
    } else if (func_0203633C() & 0x10) {
        if (cur == 10) *(s16 *)(p + 0x1B8) = 3;
        else if (cur == 11) *(s16 *)(p + 0x1B8) = 0;
        else {
            *(s16 *)(p + 0x1B8) += 1;
            *(s16 *)(p + 0x1B8) %= 5;
        }
        flag = 1;
    } else if (func_0203633C() & 0x20) {
        if (cur == 10) *(s16 *)(p + 0x1B8) = 3;
        else if (cur == 11) *(s16 *)(p + 0x1B8) = 0;
        else {
            int v = *(s16 *)(p + 0x1B8);
            if (v > 0) *(s16 *)(p + 0x1B8) = v - 1; else *(s16 *)(p + 0x1B8) = 4;
        }
        flag = 1;
    } else if (func_020362DC() & 1) {
        if (cur == 10) {
            func_021D93D4(p);
            func_020061E4(1363);
        } else if (cur == 11) {
            if (func_021D9320((u8 *)p)) {
                func_021D9348(p);
                func_020061E4(1357);
            } else {
                func_021D8AF4(p, 4);
            }
        } else {
            if (*(int *)(p + 0x240) == 0) return;
            idx = *(int *)(p + 0x188);
            ((Record *)p)[idx].state = cur + 1;
            func_021D9E48(p, 1, 0);
            func_021D9E48(p, 2, 1);
            func_021D9EE8(p, cur, 2);
            func_0204B878(r[idx].handle, func_021DA158(r[idx].state, r[idx].flag));
            func_0204B878(*(struct Obj **)(p + 0x1CC), 3);
            n = r[idx].value;
            if (idx + 1 == *(int *)(p + 0x23C)) {
                *(int *)(p + 0x31C) = 1;
                *(int *)(p + 0x320) = 0;
                *(s16 *)(p + 0x1B8) = 3;
                *(s16 *)(p + 0x1BA) = 2;
                flag = 1;
            } else {
                k = r[idx + 1].value;
                if (n != k) {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = k;
                } else {
                    *(int *)(p + 0x31C) = 2;
                    *(int *)(p + 0x320) = idx + 1;
                }
                func_020061E4(1356);
            }
        }
    } else if (func_020362DC() & 2) {
        func_021D93D4(p);
        func_020061E4(1363);
    } else if (func_0203633C() & 0x200) {
        idx = *(int *)(p + 0x188);
        if (idx == 0) {
            idx = *(int *)(p + 0x23C);
            *(int *)(p + 0x188) = idx - 1;
        } else {
            *(int *)(p + 0x188) = idx - 1;
        }
        idx = *(int *)(p + 0x188);
        if (r[idx].flag == 1) {
            *(int *)(p + 0x31C) = 2;
            *(int *)(p + 0x320) = idx;
        } else {
            *(int *)(p + 0x31C) = 1;
            *(int *)(p + 0x320) = r[idx].value;
            *(int *)(p + 0x324) = 1;
        }
        func_020061E4(1352);
    } else if (func_0203633C() & 0x100) {
        idx = *(int *)(p + 0x188);
        if (idx == *(int *)(p + 0x23C) - 1) {
            *(int *)(p + 0x188) = 0;
        } else {
            *(int *)(p + 0x188) = idx + 1;
        }
        idx = *(int *)(p + 0x188);
        if (r[idx].flag == 1) {
            *(int *)(p + 0x31C) = 2;
            *(int *)(p + 0x320) = idx;
        } else {
            *(int *)(p + 0x31C) = 1;
            *(int *)(p + 0x320) = r[idx].value;
        }
        func_020061E4(1352);
    }
    if (flag == 1) {
        func_020061E4(1352);
        cur = T.v[*(s16 *)(p + 0x1BA)][*(s16 *)(p + 0x1B8)];
        func_021D9E98(p, cur);
        if (cur == 10 || cur == 11) {
            if (*(int *)(p + 0x1A4) == 2) return;
            *(int *)(p + 0x1A4) = 2;
            return;
        }
        if (*(int *)(p + 0x1A4) != 1) *(int *)(p + 0x1A4) = 1;
    }
}

/*
 * Lever: expand v reads while retaining its declaration/assignment, name n*28, and initialise sum before mul.
 * Permuter found this spelling after38 candidates; baseline DIFF30 bytes; intermediate expand-v DIFF5.
 * trailing: Two zero alignment bytes.
 */
int func_021D92E4(u8 *p)
{
  int n;
  int sum;
  u32 mul;
  u32 v;
  int tmp;
  sum = 0;
  mul = 1;
  for (n = (*((int *) (p + 0x23c))) - 1; n > (-1); n--)
  {
    v = *((int *) (p + (n * 28)));
    tmp = n * 28;
    if (*((int *) (p + tmp)))
      sum += ((*((int *) (p + (n * 28)))) - 1) * mul;
    mul *= 10;
  }

  return sum;
}

/*
 * trailing: Two zero alignment bytes.
 */
int func_021D9320(u8 *p) { if(!((struct Obj14053 *)p)->f328) return 1; if(func_021D92E4(p)<=((struct Obj14053 *)p)->f344) return 1; return 0; }

void func_021D9348(char *p)  {
    int i;
    char *q;
    void *v=func_020457B0(100,50);
    ((struct Obj08137 *)p)->f1F8=1;
    ((struct Obj08137 *)p)->f210=0;
    for(i=0;i<((struct Obj08137 *)p)->f23C;i++)  {
        q=p+i*28;
        if(((struct Obj06479 *)q)->f0==0)  {
            ((struct Obj06479 *)q)->f0=1;
            func_0204B878((struct Obj *)(((struct Obj06479 *)q)->fC),func_021DA158(1,((struct Obj06479 *)q)->f8));
        }
        func_0201F35C(v,((struct Obj06479 *)q)->f0-1,1,1,1);
        func_02045AA8((struct U16Vec *)(((struct Obj08137 *)p)->f348),v);
    }
    func_02045808(v);
    func_021D8AF4(p,3);
}
