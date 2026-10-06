/*
 * function: func_021E32EC
 * address:  0x021E32EC
 * packet:   pkt_ov119_021E32EC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047910  0x02047910  arm
 *   func_02047964  0x02047964  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02051534  0x02051534  arm
 *   func_02051574  0x02051574  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02011590  0x02011590  thumb
 *   d_021E7AC8  0x021E7AC8  data a4
 *   d_021E8144  0x021E8144  data a4
 */
#include "../include/Obj00907.h"

typedef unsigned short u16;

typedef struct {
    void (*fn)(char *p, void *out);
    int unused;
} Handler;

typedef struct {
    int x;
    int amount;
} Cfg;

typedef struct {
    char pad00[0x90];
    int *a90;           /* 0x090 */
    int *a94;           /* 0x094 */
    int *a98;           /* 0x098 */
    int *a9C;           /* 0x09C */
    int pada0[2];       /* 0x0A0 */
    int aA8;            /* 0x0A8 */
    int aAC;            /* 0x0AC */
} Sub;

extern const Handler d_021E7AC8[];
extern Cfg d_021E8144;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
struct Light;
extern int func_0204779C(int *p);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern int func_02051534(void);
extern int func_02051574(void);
typedef signed int     s32;
struct Arg;
struct IcaAnime;
extern void func_02047A60(void *a0, struct Arg *a1);
extern u32 func_02011590(struct IcaAnime *p, s32 v);

void func_021E32EC(char *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = ((struct Obj00907 *)p)->f109C;
    if (idx == -1)
        return;
    if (d_021E7AC8[idx].fn != 0)
        d_021E7AC8[idx].fn(p, buf);
    if (((struct Obj00907 *)p)->f824 != 0xFFFF) {
        q = (void *)func_02048A18(((struct Obj00907 *)p)->f820, ((struct Obj00907 *)p)->f824);
        n = func_0204779C(q);
        for (i = 0; i < n; i++)
            func_02047910(q, (u16)i, d_021E8144.amount);
    }
    func_02047964();
    func_02048AD0(((struct Obj00907 *)p)->f83C);
    func_020479D8();
    if (((struct Obj00907 *)p)->fC != 0) {
        func_02051534();
        func_02051574();
    }
    if (((struct Obj00907 *)p)->f824 != 0xFFFF)
        func_02047A60((void *)func_02048A18(((struct Obj00907 *)p)->f820, ((struct Obj00907 *)p)->f824), (struct Arg *)buf);
    if (*(Sub * *)&((struct Obj00907 *)p)->fC != 0) {
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a90 != 0) {
            if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->aA8 == 0)
                (*(Sub * *)&((struct Obj00907 *)p)->fC)->aA8 = func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a90), d_021E8144.amount);
            if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->aAC == 0)
                (*(Sub * *)&((struct Obj00907 *)p)->fC)->aAC = func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a94), d_021E8144.amount);
        }
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a9C != 0)
            func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a9C), d_021E8144.amount);
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a98 != 0)
            func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a98), d_021E8144.amount);
    }
}
