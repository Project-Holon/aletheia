/*
 * file:     btl_rec_p12.c
 * unit:     yes
 * function: func_021EEF20, func_021EEF98, func_021EEFE0
 * address:  0x021EEF20
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
 *   func_02045A98  0x02045A98  arm
 *   func_0201D5C4  0x0201D5C4  thumb
 *   func_0201D5CC  0x0201D5CC  thumb
 *   func_0201D670  0x0201D670  thumb
 *   func_0201D5F4  0x0201D5F4  thumb
 *   func_0201D658  0x0201D658  thumb
 *   func_0201D688  0x0201D688  thumb
 *   func_02045A90  0x02045A90  arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F020 0x0201F020 thumb
 *   func_021EED00 0x021EED00 thumb ov093
 *   func_021EED24 0x021EED24 thumb ov093
 *   func_021EED48 0x021EED48 thumb ov093
 *   func_021EED6C 0x021EED6C thumb ov093
 *   func_021EED90 0x021EED90 thumb ov093
 *   d_021F63D8 0x021F63D8 data ov093 a4
 */
#include "../../matched/include/G_H.h"

struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u16 func_02045A98(void);
extern u32 func_0201D5C4(void);
extern u32 func_0201D5CC(const u16 *p);
extern u32 func_0201D670(const u16 *p, u32 i);
extern u32 func_0201D5F4(const u16 *p);
extern u32 func_0201D658(const u16 *p);
extern u16 *func_0201D688(u16 *p);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F020(struct WordSet *p, u32 i, u32 v);
extern void func_021EED00(u8 a, u32 b);
extern void func_021EED24(u8 a, u32 b);
extern void func_021EED48(u8 a, u8 b);
extern void func_021EED6C(void *w, u8 i, u8 a);
extern void func_021EED90(void *w, u8 i, u8 a);
u16 *func_021EEF20(u16 *p, u32 *o1, u16 *o2, u8 *o3);
u8 func_021EEF98(void *s);
void func_021EEFE0(void *s, const u32 *values, void *w);
extern struct H d_021F63D8;


/*
 * Walks a message string for the first 0xF000 tag that func_0201D5CC calls a
 * word reference; the guard on p wraps the whole walk (two `return 0` tails).
 */
u16 *func_021EEF20(u16 *p, u32 *o1, u16 *o2, u8 *o3)
{
    u16 end;
    u32 tag;

    if (p != 0) {
        end = func_02045A98();
        tag = func_0201D5C4();
        while (*p != end) {
            if (*p == tag) {
                if (func_0201D5CC(p) != 0) {
                    *o3 = func_0201D670(p, 0);
                    *o1 = func_0201D5F4(p);
                    *o2 = func_0201D658(p);
                    return func_0201D688(p);
                }
                p = func_0201D688(p);
            } else {
                p = p + 1;
            }
        }
        return 0;
    }
    return 0;
}


u8 func_021EEF98(void *s)
{
    u32 o1;
    u16 o2;
    u8 o3;
    u16 *p;
    u8 n;

    p = func_02045A90(s);
    n = 0;
    if (p != 0) {
        do {
            p = func_021EEF20(p, &o1, &o2, &o3);
            if (p != 0 && o1 == 1) {
                if (o2 == 1 || o2 == 2 || o2 == 12)
                    n = n + 1;
            }
        } while (p != 0);
    }
    return n;
}


/*
 * Two passes over message tags: count removed slots, then install values.
 * A u8 kind local narrows before argument setup; const values schedules
 * the index shift ahead of the last outgoing argument store.
 */
void func_021EEFE0(void *s, const u32 *values, void *w)
{
    u16 end;
    u32 tag;
    u8 removed[8];
    u16 *p;
    u32 i;
    u32 slot;
    u32 index;
    u8 group;
    u8 kind;
    end = func_02045A98();
    tag = func_0201D5C4();
    for (i = 0; i < 8; i++)
        removed[i] = 0;
    p = func_02045A90(s);
    while (*p != end) {
        if (*p == tag) {
            if (func_0201D5CC(p)) {
                slot = func_0201D670(p, 0);
                if ((u8)func_0201D5F4(p) == 1 && func_0201D658(p) == 14) {
                    for (i = slot + 1; i < 8; i++)
                        removed[i]++;
                }
            }
            p = func_0201D688(p);
        } else
            p++;
    }
    p = func_02045A90(s);
    while (*p != end) {
        if (*p == tag) {
            if (func_0201D5CC(p)) {
                slot = func_0201D670(p, 0);
                index = slot;
                group = func_0201D5F4(p);
                if (slot >= removed[slot])
                    index = slot - removed[slot];
                if (group == 2) {
                    kind = func_0201D658(p) + 1;
                    func_0201EFA4(w, slot, values[index], kind, 0, 1);
                } else {
                    switch (func_0201D658(p)) {
                    case 14:
                        func_021EED6C(w, slot, values[index]);
                        break;
                    case 0:
                        func_021EED90(w, slot, values[index]);
                        break;
                    case 2:
                        if (d_021F63D8.f1a == 0)
                            func_021EED00(values[index], slot);
                        else
                            func_021EED24(values[index], slot);
                        break;
                    case 12:
                        func_021EED24(values[index], slot);
                        break;
                    case 1:
                        func_021EED48(values[index], slot);
                        break;
                    case 3:
                        func_0201F020(w, slot, values[index]);
                        break;
                    case 6:
                        func_0201EF8C(w, slot, values[index]);
                        break;
                    case 7:
                        func_0201EF34(w, slot, values[index]);
                        break;
                    case 9:
                        func_0201EF40(w, slot, values[index]);
                        break;
                    case 15:
                        func_0201F020(w, slot, values[index]);
                        break;
                    }
                }
            }
            p = func_0201D688(p);
        } else
            p++;
    }
}
