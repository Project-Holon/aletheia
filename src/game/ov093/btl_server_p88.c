/*
 * file:     btl_server_p88.c
 * unit:     yes
 * function: func_021C7F4C, func_021C7F68, func_021C7FCC, func_021C7FE0, func_021C8010, func_021C8020, func_021C8030, func_021C804C, func_021C80AC, func_021C8114, func_021C8120, func_021C812C, func_021C8130, func_021C8138, func_021C8140
 * address:  0x021C7F4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8778   0x021B8778  thumb  ov093
 *   func_021B98A4   0x021B98A4  thumb  ov093
 *   func_021D5B68   0x021D5B68  thumb  ov093
 *   func_021D5440   0x021D5440  thumb  ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13340.h"
#include "../../matched/include/Obj18333.h"

struct Unk021B8CB0;
typedef unsigned char u8;

struct Flag { u8 pad[0x78a]; u8 low:3; u8 set:1; u8 high:4; };

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 lo : 4; u32 hi : 28; } W;

typedef union { u32 u; W w; } U;

typedef struct { u8 *a; U b; u32 c; u32 d; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int func_021D5B68(void *p);
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern char *func_021B9AF8(char *, int);
extern u8 func_021B9010(u8 *p, u8 k);
extern int func_021B8B9C(u8 *, unsigned int);
extern int func_021B8D8C(void *, void *, unsigned int);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D80BC(void *, int, int, u16);
int func_021C7F4C(struct Flag *p);
u8 func_021C7F68(int *p, int b, u8 *out);
char *func_021C7FCC(u8 *p, int i);
char *func_021C7FE0(u8 *p, int v);
int func_021C8010(u8 *p, unsigned int v);
u8 func_021C8020(u8 *p, u8 v);
int func_021C8030(u8 *p, int v, u16 k);
int func_021C804C(S *p, u8 key, u32 *out);
int func_021C80AC(u8 *p, int key);
u16 func_021C8114(u8 *p);
u8 *func_021C8120(u8 *p, int b);
/* 021C812C adds r0,#0x1c */ u8 *func_021C812C(u8 *p);
/* 021C8130 movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */ u8 *func_021C8130(u8 *p);
u16 func_021C8138(struct Q7 *p);
unsigned char func_021C8140(char *p, int i);

int func_021C7F4C(struct Flag *p) { if (p->set) return 0; p->set = 1; return 1; }


/*
 * Named by the parked ov093 file func_021D85F4.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 */
u8 func_021C7F68(int *p, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)func_021B8778((struct Unk021B8CB0 **)p[1], b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)p[2], buf[i]);
        int ok = (x != 0) ? (func_021D5B68(x) == 0) : 0;

        if (ok)
            out[j++] = func_021D5440(x);
    }
    return j;
}

char *func_021C7FCC(u8 *p, int i) { return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8, func_021B8DDC(i)); }

/*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 */
char *func_021C7FE0(u8 *p, int v) { unsigned int k; k=func_021B9010(*(u8 * *)&((struct Obj00003 *)p)->f4, func_021B8DDC(v)); if(func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4,k)) return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8,k); return 0; }

int func_021C8010(u8 *p, unsigned int v) { return func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, v); }

/*
 * extent: two bytes alignment padding follow.
 */
u8 func_021C8020(u8 *p, u8 v) { return func_021D5440((u8 *)func_021B98AC(*(char *const * *)&((struct Obj00003 *)p)->f8, v)); }

int func_021C8030(u8 *p, int v, u16 k) { return func_021D80BC(((struct Obj00003 *)p)->f4, *(int *)&((struct Obj00003 *)p)->f8, (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,v), k); }


/*
 * Levers: the record array read as p->e[i] of the twins' S (func_021BCA08,
 * func_021BCAAC), which keeps i*16 live and recomputes p+i*16 for the second
 * load; the second word as a union of u32 and a 4-bit bitfield read in place
 * (a union local takes a stack slot); key as a u8 parameter, which puts its
 * spill ahead of the count load (int/u32 key leave it after).
 */
int func_021C804C(S *p, u8 key, u32 *out)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (key == func_021D5440(p->e[i].a)) {
            if (p->e[i].b.w.lo != 6) {
                *out = p->e[i].b.u;
                return 1;
            }
        }
    }
    return 0;
}


int func_021C80AC(u8 *p, int key)
{
    u32 i;
    u32 total;
    u32 flagged;
    flagged = 0;
    total = 0;
    for (i = 0; i < p[0x782]; i++) {
        u8 *e = p + i * 16;
        if (key != func_021D5440(*(u8 * *)&((struct Obj13340 *)e)->f7E0)) {
            total++;
            if (e[0x7ed] != 0) {
                flagged++;
            }
        }
    }
    return total == flagged;
}


/*
 * ldrh at #0x1f74 (pool constant)
 */
u16 func_021C8114(u8 *p)
{
    return ((struct Obj18333 *)p)->f1F74;
}


/*
 * pointer add #0x1fec
 */
u8 *func_021C8120(u8 *p, int b)
{
    return p + 0x1fec;
}


/* 021C812C  adds r0,#0x1c */
u8 *func_021C812C(u8 *p) { return p + 0x1c; }


/* 021C8130  movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x3e; lsls r1, r1, #4; adds r0, r0, r1; bx lr.
 */
u8 *func_021C8130(u8 *p) { return p + 0x3e0; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0, #0x10]; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021C8138(struct Q7 *p) { return (u16)p->v; }

unsigned char func_021C8140(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x7d9);
}
