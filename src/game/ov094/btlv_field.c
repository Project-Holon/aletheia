/*
 * file:     btlv_field.c
 * unit:     yes
 * function: func_021F6B04, func_021F6CF0, func_021F6D5C, func_021F6DD4, func_021F6DEC, func_021F6E1C, func_021F6E2C
 * address:  0x021F6B04
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
 *   sub_020307B0 0x020307B0 arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_0220AC50 0x0220AC50 data ov094 a1
 *   func_021F9364 0x021F9364 thumb ov094
 */
#include "../../matched/include/Obj18551.h"
#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"
#include "btlv_field_shared_types.h"

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

extern u32 sub_020307B0(void *p);

extern void G3D_SYSTEM_DeleteAnime(struct Rec_v6560 *p);

extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

extern u32 func_020307B0(void *p);

extern void G3D_SYSTEM_DeleteObject(struct Rec_v6560 *p);

extern void G3D_SYSTEM_DeleteRender(struct Rec_v6560 *p);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg_v6560 *a1);

Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap);

void func_021F6CF0(Obj_021F6CF0 *o);

void func_021F6D5C(Obj_021F6D5C *o);

void func_021F6DD4(Obj_021F6DD4 *p);

void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);

int func_021F6E1C(char *p);

void func_021F6E2C(Obj_021F6E2C *o, u32 v);

void func_021F9364(P *p);

extern const char d_0220AC50[];

/*
 * Lever: u8 variant spills at entry before the other parameter copies;
 * int variant moves that spill three instructions later (8 differing bytes).
 * The ov094 caller at 021F76D6 passes the byte-derived selector.
 */
Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap)
{
    Obj_021F6B04 *o;
    int (*table)[4][4];
    int i, j;
    int bytes;
    o = sub_02030734(heap, 0x70, 1, d_0220AC50, 0x56);
    table = ARC_TOOL_LoadMember(0x98, 1, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (table[group][0][variant] != -1)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group][0][variant]);
    else
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group][0][0]);
    G3D_SYSTEM_TransVramTexture(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group][i][variant] != -1) o->n++;
    o->f14 = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    j = 0;
    if (o->n != 0) {
        o->fc = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7e);
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7f);
        o->f8 = sub_02030734(o->heap, o->n * 16, 1, d_0220AC50, 0x80);
        for (i = 1; i < 4; i++) {
            if (table[group][i][variant] != -1) {
                o->fc[j] = G3D_SYSTEM_CreateResourceArc(11, table[group][i][variant]);
                o->f10[j] = G3D_SYSTEM_CreateAnime(o->f14, o->fc[j], 0);
                o->f8[j].kind = 0;
                j++;
            }
        }
        o->f18 = G3D_SYSTEM_CreateObject((u32)o->f14, (u32 *)o->f10, (u16)o->n);
        for (j = 0; j < o->n; j++) G3D_SYSTEM_EnableObjectAnime(o->f18, (u16)j);
    } else {
        o->f18 = G3D_SYSTEM_CreateObject((u32)o->f14, 0, (u16)0);
    }
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0x1000;
    o->f2c = 0x1000;
    o->f30 = 0x1000;
    func_0207ADC4(o->matrix);
    bytes = *(u16 *)(NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(o->f0)) + 0x30) * 8;
    o->f58 = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xaa);
    o->f5c = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xab);
    *o->f58 = o->f0;
    *o->f5c = sub_02030734(o->heap, bytes, 0, d_0220AC50, 0xae);
    o->f60 = 0;
    o->f61 = 1;
    sub_020307B0(table);
    return o;
}

void func_021F6CF0(Obj_021F6CF0 *o)
{
    int i;

    G3D_SYSTEM_DeleteObject(o->f18);
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            G3D_SYSTEM_DeleteAnime(o->f10[i]);
            G3D_SYSTEM_DeleteResource(o->fc[i]);
        }
        func_020307B0(o->f8);
        func_020307B0(o->f10);
        func_020307B0(o->fc);
    }
    G3D_SYSTEM_DeleteRender(o->f14);
    G3D_SYSTEM_DeleteResource(o->f0);
    func_020307B0(*o->f5c);
    func_020307B0(o->f5c);
    func_020307B0(o->f58);
    func_020307B0(o);
}

/*
 * Lever: the `adds r6, r4, #0` before the loop is a zero (r4 is 0 there) that
 * the loop-back branch skips; it is the constant 0 (default amount and the
 * cleared field), not a copy of i. Flags_021F6560 word is a bitfield (lsls/lsrs).
 */
void func_021F6D5C(Obj_021F6D5C *o)
{
    int i;
    int amt;

    if (o->bit1) {
        o->bit1 = 0;
        return;
    }
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            Ent_021F6D5C *e;

            e = &o->arr[i];
            amt = 0;
            switch (e->kind) {
            case 0:
                amt = 0x1000;
                break;
            case 1:
                if (e->f4 == 1) {
                    amt = e->f8;
                    e->fc--;
                    if (o->arr[i].fc == 0)
                        o->arr[i].f4 = 0;
                }
                break;
            }
            if (amt != 0)
                G3D_SYSTEM_LoopObjectAnimeFrame(o->h18, (u16)i, amt);
        }
    }
    func_021F9364((P *)o->sub);
}

/*
 * Unless flag bit 0 at 0x68 is set, applies the vector at 0x1c to the handle at 0x18.
 */
void func_021F6DD4(Obj_021F6DD4 *p)
{
    if (!p->b0)
        G3D_SYSTEM_DrawObject(p->h, (struct Arg_v6560 *)p->v);
}

void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}

int func_021F6E1C(char *p)
{
    return ((struct Obj18551 *)p)->f60 != 0;
}

/*
 * Unlabelled leaf, filed as the blocker of ov094 func_021F839C (lane S22).
 */
void func_021F6E2C(Obj_021F6E2C *o, u32 v)
{
    o->f = v;
}
