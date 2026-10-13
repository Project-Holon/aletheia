/*
 * file:     btlv_stage.c
 * unit:     yes
 * function: func_021F6560, func_021F6898, func_021F6934, func_021F69B0, func_021F69E8, func_021F6A18, func_021F6A28, func_021F6AA8, func_021F6AD0
 * address:  0x021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   sub_020307B0 0x020307B0 arm
 *   d_0220AC40 0x0220AC40 data
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   func_021F9364 0x021F9364 thumb ov094
 */
#include "../../matched/include/Obj18549.h"
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"

extern void *sub_02030734(u32, u32, int, const char *, u16);

extern void *ARC_TOOL_LoadMember(u32, u32, u32);

extern void *G3D_SYSTEM_CreateResourceArc(u32, u32);

extern int G3D_SYSTEM_TransVramTexture(int *);

extern void *G3D_SYSTEM_CreateRender(void *, u32, void *);

extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);

extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);

extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

extern void func_0207ADC4(int *);

extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);

extern unsigned char *NNS_G3dGetTex(unsigned char *p);

extern void func_0207DCF8(void *);

extern u32 sub_020307B0(void *p);

extern void G3D_SYSTEM_DeleteAnime(struct Rec_v6560 *p);

extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

extern u32 func_020307B0(void *p);

extern void G3D_SYSTEM_DeleteObject(struct Rec_v6560 *p);

extern void G3D_SYSTEM_DeleteRender(struct Rec_v6560 *p);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg_v6560 *a1);

Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap);

void func_021F6898(Obj_021F6898 *o);

void func_021F6934(Obj_021F6934 *o);

void func_021F69B0(Obj_021F69B0 *p);

void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);

int func_021F6A18(char *p);

void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on);

void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b);

int func_021F6AD0(Obj_021F6AD0 *p);

void func_021F9364(P *p);

extern const char d_0220AC40[];

Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap)
{
    Obj_021F6560 *o;
    Rec_v6560 *table;
    int i, k, m;
    int bytes;
    o = sub_02030734(heap, 0xbc, 1, d_0220AC40, 0x63);
    table = ARC_TOOL_LoadMember(0x98, 2, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (mode == 3)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, 0x56);
    else if (table[group].ids[0][variant] != -1)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[0][variant]);
    else
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[0][0]);
    G3D_SYSTEM_TransVramTexture(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group].ids[i][variant] != -1) o->n++;
    o->h1c[0] = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    o->h1c[1] = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    if (mode == 3) {
        o->n = 1;
        o->f10 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0x93);
        *o->f10 = G3D_SYSTEM_CreateResourceArc(11, 0x57);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, 4, 0, d_0220AC40, 0x98);
            o->arr[i] = sub_02030734(o->heap, 0x10, 1, d_0220AC40, 0x99);
            *o->f14[i] = G3D_SYSTEM_CreateAnime(o->h1c[i], *o->f10, 0);
            o->arr[i]->kind = 1;
            o->h24[i] = G3D_SYSTEM_CreateObject((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            G3D_SYSTEM_EnableObjectAnime(o->h24[i], (u16)0);
        }
    } else if (o->n != 0) {
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC40, 0xa7);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, o->n * 4, 0, d_0220AC40, 0xab);
            o->arr[i] = sub_02030734(o->heap, o->n * 16, 1, d_0220AC40, 0xac);
        }
        k = 0;
        for (i = 1; i < 4; i++) {
            if (table[group].ids[i][variant] != -1) {
                o->f10[k] = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[i][variant]);
                for (m = 0; m < 2; m++) {
                    o->f14[m][k] = G3D_SYSTEM_CreateAnime(o->h1c[m], o->f10[k], 0);
                    o->arr[m][k].kind = 0;
                }
                k++;
            }
        }
        for (i = 0; i < 2; i++) {
            o->h24[i] = G3D_SYSTEM_CreateObject((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            for (m = 0; m < o->n; m++) G3D_SYSTEM_EnableObjectAnime(o->h24[i], (u16)m);
        }
    } else {
        o->h24[0] = G3D_SYSTEM_CreateObject((u32)o->h1c[0], 0, (u16)0);
        o->h24[1] = G3D_SYSTEM_CreateObject((u32)o->h1c[1], 0, (u16)0);
    }
    bytes = *(u16 *)(NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(o->f0)) + 0x30) * 8;
    o->fa4 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0xd6);
    o->fa8 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0xd7);
    *o->fa4 = o->f0;
    *o->fa8 = sub_02030734(o->heap, bytes, 0, d_0220AC40, 0xda);
    o->fac = 0;
    o->fad = 1;
    o->xf[0].f0 = 0;
    o->xf[0].f4 = 0;
    o->xf[0].f8 = 0x572f;
    o->xf[0].sx = 0x1000;
    o->xf[0].sy = 0x1000;
    o->xf[0].sz = 0x1000;
    func_0207ADC4(o->xf[0].matrix);
    o->xf[1].f0 = 0;
    o->xf[1].f4 = 0;
    o->xf[1].f8 = -0xcb7d;
    o->xf[1].sx = 0x1000;
    o->xf[1].sy = 0x1000;
    o->xf[1].sz = 0x1000;
    func_0207ADC4(o->xf[1].matrix);
    if (mode == 3) {
        o->xf[0].f8 = 0xa000;
        o->xf[1].f8 = -0xf000;
    }
    func_0207DCF8(&table[group]);
    sub_020307B0(table);
    return o;
}

void func_021F6898(Obj_021F6898 *o)
{
    int i;
    int j;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++)
                G3D_SYSTEM_DeleteAnime(o->f14[j][i]);
            G3D_SYSTEM_DeleteResource(o->f10[i]);
        }
        for (j = 0; j < 2; j++) {
            func_020307B0(o->f14[j]);
            func_020307B0(o->f8[j]);
        }
        func_020307B0(o->f10);
    }
    for (j = 0; j < 2; j++) {
        G3D_SYSTEM_DeleteObject(o->f24[j]);
        G3D_SYSTEM_DeleteRender(o->f1c[j]);
    }
    G3D_SYSTEM_DeleteResource(o->f0);
    func_020307B0(*o->fa8);
    func_020307B0(o->fa8);
    func_020307B0(o->fa4);
    func_020307B0(o);
}

/*
 * Lever: the element address is `i * 16 + (u32)o->arr[j]` (integer first);
 * `&o->arr[j][i]` is normalised pointer-first and swaps the add operands.
 */
void func_021F6934(Obj_021F6934 *o)
{
    int i;
    int j;
    int amt;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++) {
                Ent_021F6934 *e;

                e = (Ent_021F6934 *)(i * 16 + (u32)o->arr[j]);
                amt = 0;
                switch (e->kind) {
                case 0:
                    amt = 0x1000;
                    break;
                case 1:
                    if (e->f4 == 1) {
                        amt = e->f8;
                        e->fc--;
                        if (((Ent_021F6934 *)(i * 16 + (u32)o->arr[j]))->fc == 0)
                            ((Ent_021F6934 *)(i * 16 + (u32)o->arr[j]))->f4 = 0;
                    }
                    break;
                }
                if (amt != 0)
                    G3D_SYSTEM_LoopObjectAnimeFrame(o->h[j], (u16)i, amt);
            }
        }
    }
    func_021F9364((P *)o->sub);
}

/*
 * Applies each of the two transforms whose disable bit is clear.
 */
void func_021F69B0(Obj_021F69B0 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (!(p->off & (1 << i)))
            G3D_SYSTEM_DrawObject(p->h[i], (struct Arg_v6560 *)p->xf[i]);
    }
}

/*
 * lane O10 candidate
 */
void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}

int func_021F6A18(char *p)
{
    return ((struct Obj18549 *)p)->fAC != 0;
}

void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on)
{
    if (mode == 2) {
        if (on)
            o->f = 3;
        else
            o->f = 0;
    } else {
        if (on)
            o->f = o->f | (1 << mode);
        else
            o->f = o->f & ((1 << mode) ^ 3);
    }
}

/*
 * Arms entry j of table i when its state is 1: sets the flag and stores the two values.
 */
void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b)
{
    if (p->tab[i][j].state == 1) {
        p->tab[i][j].armed = 1;
        p->tab[i][j].a = a;
        p->tab[i][j].b = b;
    }
}

/*
 * Returns 1 when any entry of either table is armed.
 */
int func_021F6AD0(Obj_021F6AD0 *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        if (p->x[i].armed == 1 || p->y[i].armed == 1)
            return 1;
    }
    return 0;
}
