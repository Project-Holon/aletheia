/*
 * file:     fld_trade_p17.c
 * unit:     yes
 * function: func_021CE9E4, func_021CEA28, func_021CEA50
 * address:  0x021CE9E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 */
#include "../../matched/include/Obj00011.h"

struct MsgBank;
struct P;
struct U16Vec;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18;
} S;

typedef struct {
    u8 f0;
    u8 pad1[0x2B];
} Slot;

typedef struct {
    u8 pad0[0x70];
    Slot slots[4];
    u8 pad120[0x550 - 0x120];
    u8 f550[4];
} Work;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_02190F7C(struct P *p);
extern void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);
void func_021CE9E4(S *p, u32 m);
void func_021CEA28(Work *p);
int func_021CEA50(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021CE9E4(S *p, u32 m)
{
    u32 n;

    if (m == 8 && ((struct Obj00011 *)p)->f57A == 8)
        return;
    ((struct Obj00011 *)p)->f57A = m;
    n = (u32)func_02045EC0((struct MsgBank *)p->f8, m);
    func_0201F250((struct WordSet *)p->f4, (void *)p->f18, (void *)n);
    func_02045808((struct U16Vec *)n);
    func_02190F7C((struct P *)p->f14);
    func_02190EB8((struct P *)p->f14, 0, 0, p->f18);
}


void func_021CEA28(Work *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        p->f550[i] = p->slots[i].f0;
    }
}


int func_021CEA50(u8 *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (p[0x550 + i] != p[0x70 + i * 0x2c]) {
            return 0;
        }
    }
    return 1;
}
