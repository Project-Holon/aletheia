/*
 * function: func_021FEEA8
 * address: 0x021FEEA8
 * packet: pkt_ov094_021FEEA8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * levers: grouped vectors fix stack order; integer address arithmetic on the
 * second buffer argument prevents CSE; b34 is one two-bit assignment.
 * blocker: ARM9 0x02015D94 and 0x02015D88 have no outside witness.
 * Verified scratch C, EXACT (blocker_02015D94_r1.log):
 * void MCSS_SetShadowOffset(char *p, int *src) {
 *     *(int *)(p + 0x17c) = src[0];
 *     *(int *)(p + 0x180) = src[1];
 *     *(int *)(p + 0x184) = src[2];
 * }
 * Verified scratch C, EXACT (blocker_02015D88_r1.log):
 * typedef unsigned short u16;
 * void MCSS_SetShadowRotateZ(char *p, u16 value) { *(u16 *)(p + 0x17a) = value; }
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_0202D034 0x0202D034 thumb
 *   MCSS_Add 0x020159C8 thumb
 *   MCSS_SetShadowAlpha 0x02015FD4 thumb
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 *   MCSS_SetShadowRotateZ 0x02015D88 thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   func_022003EC 0x022003EC thumb ov094
 *   func_022018A8 0x022018A8 thumb ov094
 *   func_0220055C 0x0220055C thumb ov094
 *   func_02201A20 0x02201A20 thumb ov094
 *   func_022006B4 0x022006B4 thumb ov094
 *   func_02201718 0x02201718 thumb ov094
 */
#include "../include/Obj13604.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { Vec orient, pos; } Vectors;
typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b34 : 2;
    unsigned int b5 : 1;
} Flags;
extern u32 func_02017E1C(void *, u32, u32);
struct Obj;
struct Rec;
struct Sub150;
extern u32 func_02017EAC(void *p);
extern u32 func_02019C90(u16, u16, u32);
extern int func_0202D034(u32, u32);
extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void MCSS_SetShadowAlpha(char *p, int v);
extern void MCSS_SetShadowOffset(char *p, int *src);
extern void MCSS_SetShadowRotateZ(char *p, u16 value);
extern void MCSS_SetAnimCallback(void *, u32, void *, u32);
extern void func_022003EC(void *, void *, int *, int);
extern void func_022018A8(void *, Vec *, int);
extern void func_0220055C(void *, int, int);
extern int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3);
extern void func_022006B4(void *, int);
extern void func_02201718(int i);
void func_021FEEA8(char *w, void *src, int key)
{
    int i;
    int off;
    int visible;
    u16 angle;
    Vectors vectors;
    u32 a, b;
    for (i = 0; i < 14; i++) {
        if (*(void **)(w + i * 0x5c + 8) == 0)
            break;
    }
    if (key < 14 && i < 14) {
        off = i * 0x5c;
        *(int *)(w + 0x48 + off) = 0;
        ((Flags *)(w + 0x54 + off))->b0 = 0;
        ((Flags *)(w + 0x54 + off))->b1 = 0;
        ((Flags *)(w + 0x54 + off))->b5 = 0;
        ((Flags *)(w + 0x54 + off))->b2 = ((struct Obj13604 *)w)->f534;
        *(int *)(w + 0x50 + off) = key;
        *(u32 *)(w + 0x3c + off) = func_02017E1C(src, 0, 0);
        *(u32 *)(w + 0x44 + off) = func_02017E1C(src, 0x98, 0);
        if (func_02017EAC(src) == 1)
            *(int *)(w + 0x48 + off) |= 2;
        func_022003EC(w, src, (int *)(w + 0xc + off), key);
        func_022018A8(w, &vectors.pos, key);
        *(void **)(w + 8 + off) = MCSS_Add(((struct Obj13604 *)w)->f4, vectors.pos.x, vectors.pos.y, vectors.pos.z, (void *)((u32)w + 0xc + off));
        func_0220055C(w, key, 1);
        *(u32 *)(w + 0x34 + off) = func_02017E1C(src, 5, 0);
        *(u32 *)(w + 0x38 + off) = func_02017E1C(src, 0x6f, 0);
        *(u16 *)(w + 0x40 + off) = func_02019C90(*(u32 *)(w + 0x34 + off), *(u32 *)(w + 0x38 + off), 0x26);
        a = func_02017E1C(src, 0xa0, 0);
        b = func_02017E1C(src, 0xa1, 0);
        *(u16 *)(w + 0x42 + off) = func_0202D034(a, b);
        if (func_02201A20(*(int *)(w + 0x34 + off), key, (int *)(&vectors.orient), &angle, &visible) == 0) {
            vectors.orient.x = -0x400;
            vectors.orient.y = 0;
            vectors.orient.z = -0x600;
            angle = 0xf800;
            visible = 1;
        }
        if (visible == 0)
            MCSS_SetShadowAlpha(*(void **)(w + 8 + off), 0);
        else {
            MCSS_SetShadowOffset(*(void **)(w + 8 + off), (int *)(&vectors.orient));
            MCSS_SetShadowRotateZ(*(void **)(w + 8 + off), angle);
        }
        ((Flags *)(w + 0x54 + off))->b34 = 3;
        func_022006B4(w, key);
        MCSS_SetAnimCallback(*(void **)(w + 8 + off), i, (void *)func_02201718, 1);
    }
}
