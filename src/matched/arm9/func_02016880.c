/*
 * function: MCSS_TransTextureTask
 * address:  0x02016880
 * packet:   pkt_020163C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   NNSi_G2dLoadVramResourceSub  0x02063A54  arm
 *   NNSi_G2dLoadVramResourceBySel  0x02063E54  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj_02016880 {
    void *f00;                    /* +0x00 */
    void *f04;                    /* +0x04 */
    u32  f08;                     /* +0x08 */
    u32  f0c;                     /* +0x0c */
    void *f10;                    /* +0x10 */
    void *f14;                    /* +0x14 */
    u32  f18;                     /* +0x18 */
    u32  f1c;                     /* +0x1c */
    struct Obj20_02016880 *f20;   /* +0x20 */
    u32 *f24;                     /* +0x24 */
    u32  f28;                     /* +0x28 */
};

struct Obj20_02016880 {
    u8   pad00[0xc];
    void *f0c;                    /* +0x0c */
};

struct Out;
struct Res;
extern void NNSi_G2dLoadVramResourceSub(struct Res *r, u32 dst, int mode, struct Out *out);
extern void NNSi_G2dLoadVramResourceBySel(void *a, u32 b, int c, u32 d);
extern u32 GFL_HEAP_Free(void *p);
struct Node;
extern void TCB_DeleteTask(struct Node *n);

void MCSS_TransTextureTask(void *a0, struct Obj_02016880 *a1)
{
    if (a1->f28 == 0) {
        u32 v = *(volatile u16 *)0x04000006;

        if (v < 0xc0 || v > 0xc8)
            return;
    }
    if (a1->f10 != 0) {
        NNSi_G2dLoadVramResourceSub(a1->f00, a1->f18, 0, (struct Out *)a1->f08);
        GFL_HEAP_Free(a1->f10);
        if (((a1->f24[0x140 / 4] << 4) >> 0x1c) == 0) {
            a1->f10 = 0;
            return;
        }
    }
    if (a1->f24 != 0)
        a1->f24[0x140 / 4] |= 0x2000;
    if (a1->f14 != 0) {
        NNSi_G2dLoadVramResourceBySel(a1->f04, a1->f1c, 0, a1->f0c);
        GFL_HEAP_Free(a1->f14);
    }
    if (a1->f24 != 0)
        a1->f24[0] = 0;
    if (a1->f20 != 0 && a1->f20->f0c != 0)
        a1->f20->f0c = 0;
    GFL_HEAP_Free(a1);
    TCB_DeleteTask(a0);
}
