/*
 * file:     btl_server_p130.c
 * unit:     yes
 * function: func_021CDA0C, func_021CDA18, func_021CDC0C, func_021CDD34, func_021CDD50, func_021CDD94, func_021CDDA0, func_021CDDCC
 * address:  0x021CDA0C
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
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   func_021EEBE8 0x021EEBE8 thumb ov093
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021EEC4C 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006740 0x02006740 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021BA73C 0x021BA73C thumb ov093
 *   func_02006734 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   func_02005DF8 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021BA7F8 0x021BA7F8 thumb ov093
 *   d_021EFFEC 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 */
#include "../../matched/include/Obj00463.h"
#include "../../matched/include/Obj00818.h"
#include "../../matched/include/Obj09986.h"

struct Q;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef int (*Callback)(u8 *,int *);

typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags_021CDA18;

typedef struct { u8 id; u8 flag; u16 pad; Callback callbacks[3]; } Entry;

typedef struct {
    int a;
    int b;
} S;

struct Flags_021CDDA0 { u8 pad[0x1b2]; u8 low:4; u8 flag:1; u8 high:3; };

struct Flags_021CDDCC { u8 pad[0x1b2]; u8 low:5; u8 flag:1; u8 high:2; };

extern void func_021D3FDC(u8 *p, struct Q *q);
extern u8 func_021EEBE8(void *);
extern int func_021EEC20(int,u32 **);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int func_021EEC4C(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void func_02005CA4(int,u32);
extern void func_02006740(void);
extern int func_02005E50(void);
extern u16 func_021D3FA8(u8 *p);
extern void func_021BA73C(char *,int);
extern void func_02006734(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void func_02005DF8(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern void func_021BA7F8(char *p);
extern int func_021F8524(int);
void func_021CDA0C(struct QE *p, u32 v);
int func_021CDA18(u8 *p);
int func_021CDC0C(u8 *p);
void func_021CDD34(u8 *p);
Callback func_021CDD50(u8 *p,u32 id,int *out);
void func_021CDD94(char *p, int *o);
int func_021CDDA0(u8 *p);
u32 func_021CDDCC(struct Flags_021CDDCC *p);
extern const Entry d_021EFFEC[15];

void func_021CDA0C(struct QE *p, u32 v)
{
    p->v = v;
    p->z = 0;
}

int func_021CDA18(u8 *p)
{
    u32 id, *pair, x, y;
    int flag, n;
    func_021D3FDC(p,(struct Q *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        id = func_021EEBE8(((struct Obj00463 *)p)->f50);
        if (p[0x1a7] == 2 && (((Flags_021CDA18 *)(p+0x1b2))->f4 || ((Flags_021CDA18 *)(p+0x1b2))->f5) && !id) return 0;
        func_021CDD34(p);
        if (id == 9) {
            func_021EEC20(*(int *)&((struct Obj00463 *)p)->f50,&pair);
            x = pair[0]; y = pair[1];
            ((struct Obj00463 *)p)->f30 = y;
            ((struct Obj00463 *)p)->f2C = x;
            ((struct Obj00463 *)p)->fCC = 0;
            p[0x1a8] = 3;
        } else if (id) {
            *(Callback *)&((struct Obj00463 *)p)->fC8 = func_021CDD50(p,id,&flag);
            if (flag) {
                if (!func_021D3FAC(p+0x18)) { p[0x1a8] = 6; break; }
            } else func_021D3FC4(p+0x18);
            if (*(Callback *)&((struct Obj00463 *)p)->fC8) {
                p[0x1a8] = 1;
                ((struct Obj00463 *)p)->fCC = 0;
            } else {
                ((struct Obj00463 *)p)->fCC = 0;
                p[0x1a8] = 2;
            }
        } else if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 1:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
            if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
            else p[0x1a8] = 2;
        }
        break;
    case 2:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 0;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 7;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 6:
        if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
        break;
    case 4:
        if (func_021D3F60(p+0x18) == 1) p[0x1a8] = 7;
        else {
            if (((struct Obj00463 *)p)->f54) { func_02005CA4(1,62); func_02006740(); }
            p[0x1a8] = 5;
        }
        break;
    case 5:
        if (!func_02005E50()) {
            n = func_021D3FA8(p+0x18);
            func_02005CA4(0,1);
            func_021BA73C(*(char * *)&((struct Obj00463 *)p)->f0,n);
            func_02006734(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}

/*
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 */
int func_021CDC0C(u8 *p)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC(p,(struct Q *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        p[0x1a8] = 1;
    case 1:
        if (!func_021D3F98(p+0x18)) {
            id = func_021EEBE8(((struct Obj00818 *)p)->f50);
            if (id) {
                zero = 0;
                *(Callback *)&((struct Obj00818 *)p)->fC8 = func_021CDD50(p,id,0);
                if (*(Callback *)&((struct Obj00818 *)p)->fC8) {
                    p[0x1a8] = 2;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
                else {
                    func_021CDD34(p);
                    p[0x1a8] = 3;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
            }
        } else {
            if (((struct Obj00818 *)p)->f54) {
                func_02005CA4(1,1);
                func_021EAE24(((struct Obj00818 *)p)->f54);
                func_02005DF8(30);
                func_021F88BC(0);
                func_02006740();
            }
            p[0x1a8] = 4;
        }
        break;
    case 2:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            p[0x1a8] = 3;
            ((struct Obj00818 *)p)->fCC = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00818 *)p)->f50,((struct Obj00818 *)p)->fD8,((struct Obj00818 *)p)->fDC)) p[0x1a8] = 1;
        break;
    case 4:
        if (((struct Obj00818 *)p)->f54) {
            if (func_021EAE34(((struct Obj00818 *)p)->f54)) {
                if (!func_02005E50()) {
                    n = (int)func_021D3FA8(p+0x18);
                    func_021EAE74(((struct Obj00818 *)p)->f54,n,n);
                    func_021BA7F8(((struct Obj00818 *)p)->f0);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}

void func_021CDD34(u8 *p)
{
    ((struct Obj09986 *)p)->fE0 = 0;
    *(u8 * *)&((struct Obj09986 *)p)->fD8 = p+0xe0;
    ((struct Obj09986 *)p)->fDC = 4;
}

Callback func_021CDD50(u8 *p,u32 id,int *out)
{
    u32 i;
    for (i=0; i<15; i++) {
        if (d_021EFFEC[i].id == id) {
            if (out) *out = d_021EFFEC[i].flag;
            return d_021EFFEC[i].callbacks[p[0x1a7]];
        }
    }
    return 0;
}


void func_021CDD94(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x2c);
}

/*
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 owner Ilias). Integrator: seed label.
 */
int func_021CDDA0(u8 *p) { if(p[0x1a7]!=2) { if(*(u16 *)(p+0xe6)) return func_021F8524(0); return 0; } return ((struct Flags_021CDDA0 *)p)->flag; }

u32 func_021CDDCC(struct Flags_021CDDCC *p) { return p->flag; }
