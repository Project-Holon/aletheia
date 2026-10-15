/*
 * function: MCSS_TransPaletteTask
 * address:  0x0201691C
 * packet:   pkt_020163C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   NNSi_G2dInitVramHandleEx  0x020637D4  arm
 *   NNSi_G2dLoadVramResourceBySel  0x02063E54  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj24_0201691C {
    u8   pad00[4];
    void *f04;      /* +0x04 */
    void *f08;      /* +0x08 */
};

struct Obj04_0201691C {
    u8   pad00[0xc];
    void *f0c;      /* +0x0c */
};

struct Obj_0201691C {
    u8   pad00[4];
    struct Obj04_0201691C *f04;   /* +0x04 */
    u8   pad08[4];
    void *f0c;                    /* +0x0c */
    u8   pad10[0xc];
    u32  f1c;                     /* +0x1c */
    u8   pad20[4];
    struct Obj24_0201691C *f24;   /* +0x24 */
    u32  f28;                     /* +0x28 */
};

struct Node;
extern void NNSi_G2dInitVramHandleEx(u32 *p);
extern void NNSi_G2dLoadVramResourceBySel(void *a, u32 b, int c, void *d);
extern u32 GFL_HEAP_Free(void *p);
extern void TCB_DeleteTask(struct Node *n);

void MCSS_TransPaletteTask(void *a0, struct Obj_0201691C *a1)
{
    if (a1->f28 == 0) {
        u32 v = *(volatile u16 *)0x04000006;

        if (v < 0xc0 || v > 0xc8)
            return;
    }
    NNSi_G2dInitVramHandleEx(a1->f0c);
    NNSi_G2dLoadVramResourceBySel(a1->f04, a1->f1c, 0, a1->f0c);
    if (a1->f24 != 0) {
        if (a1->f24->f04 == a0)
            a1->f24->f04 = 0;
        if (a1->f24->f08 == a0)
            a1->f24->f08 = 0;
    }
    GFL_HEAP_Free(((struct Obj04_0201691C *)a1->f04)->f0c);
    GFL_HEAP_Free(a1->f04);
    GFL_HEAP_Free(a1);
    TCB_DeleteTask(a0);
}
