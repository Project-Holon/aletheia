/*
 * file:     unit_02175C40_p05.c
 * unit:     yes
 * function: func_02176048, func_02176158
 * address:  0x02176048
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175FB8  0x02175FB8  thumb  ov011
 *   func_020392B8  0x020392B8  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02175920  0x02175920  thumb  ov011
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_02173E6C 0x02173E6C thumb ov011
 *   memset 0x02082BCC arm
 */
#include "../../matched/include/Obj12438.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f0_0 : 15;
    u32 f0_15 : 7;
    u32 f0_22 : 10;
    u32 kind : 4;
    u32 f4_4 : 28;
    u32 w8[4];
} Head;

typedef struct {
    u16 name[8];
    u8 b10;
    u8 pad11;
    u16 pad12;
} Name;

typedef struct {
    Head head;
    Name name;
    u8 b2C;
} Src;

typedef struct {
    Head head;
    Name name;
    u8 idx;
    u8 b2D;
    u8 b2E;
    u16 h30;
    u16 h32;
} Rec;

typedef struct {
    u8 state;
    Rec rec;
} Entry;

typedef struct {
    u8 pad0[0x78];
    Rec tmp;
    u8 padAC[0xE8 - 0xAC];
    Entry entries[1];
} Work;

extern void func_02082BCC(void *p, int v, int n);
extern int func_02175B14(u8 *p);
extern int func_02175FB8(void *p, Src *src);
extern u32 func_020392B8(void);
extern int func_0203D1B4(void);
extern void func_02175920(void *p);
extern u32 func_0203F4FC(void);
extern int func_02173E6C(int a, int b, int c);
extern void *memset(void *p, int value, unsigned int size);
int func_02176048(u8 *a0, Work *p, Src *src, int idx);
void func_02176158(int a, u8 *p);


int func_02176048(u8 *a0, Work *p, Src *src, int idx)
{
    Rec *tmp = &p->tmp;

    func_02082BCC(&p->entries[idx], 0, sizeof(Entry));
    if (func_02175B14(a0 + 0x1AC) == 1) {
        p->entries[idx].state = 2;
        return 0;
    }
    if (func_02175FB8(a0 + 0x1AC, src) == 0) {
        p->entries[idx].state = 2;
        return 0;
    }
    if (src->head.kind == 0 || src->head.kind == 3) {
        if (func_020392B8() != 2 || func_0203D1B4() != 2) {
            p->entries[idx].state = 4;
            return 0;
        }
    }
    tmp->head = src->head;
    tmp->name = src->name;
    tmp->idx = idx;
    tmp->b2D = src->name.b10;
    tmp->b2E = src->b2C;
    tmp->h30 = 10;
    tmp->h32 = src->head.f0_22;
    p->entries[idx].rec = *tmp;
    p->entries[idx].state = 1;
    func_02175920(p);
    ((struct Obj12438 *)p)->f190 = func_0203F4FC();
    *((u8 *)p + 0x19C) = 0;
    return 1;
}

/*
 * Lever: split the offset arithmetic and the memset pointer calculation.
 * Once-300 permuter found this semantically unchanged spelling at candidate 74.
 * The three-iteration bound proves i stays 0..2; all call inputs are explicit.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`offset = i;` before `offset = i;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02176158(int a, u8 *p)
{
    unsigned int offset;
    int i;
    u8 *tmp;
    for (i = 0; i < 3; i++) {
        do {
            offset = i;
            offset = offset * 0x38;
            if (p[0xe8 + offset] != 0) {
                if (func_02173E6C(a, (int)((p + 0xe8) + offset), i) == 1) {
                    tmp = p + 0xe8;
                    tmp = tmp + offset;
                    memset(tmp, 0, 0x38);
                }
            }
        } while (0);
    }
}
