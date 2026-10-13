/*
 * function: func_02047180
 * address:  0x02047180
 * packet:   pkt_020470D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964  0x0206E964  arm
 *   G3D_SYSTEM_AllocTexVramKeys  0x02047260  arm
 *   G3D_SYSTEM_AllocPlttVramKey  0x020472F8  arm
 *   func_02069FF8  0x02069FF8  arm
 *   NNS_G3dPlttSetPlttKey  0x0206A124  arm
 */

typedef unsigned int u32;

struct Layer;
extern unsigned char *func_0206E964(unsigned char *p);
extern int  G3D_SYSTEM_AllocTexVramKeys(u32 h, u32 *a, u32 *b);
extern int G3D_SYSTEM_AllocPlttVramKey(struct Layer *layer, u32 *out);
extern void func_02069FF8(char *p, int a, int b);
extern void NNS_G3dPlttSetPlttKey(int *p, int v);

int func_02047180(u32 *p)
{
    u32 h;
    u32 a;
    u32 b;
    u32 c;

    h = (u32)func_0206E964((unsigned char *)p[1]);
    if (h == 0)
        goto fail;
    if (G3D_SYSTEM_AllocTexVramKeys(h, &a, &b) == 0)
        return 0;
    if (G3D_SYSTEM_AllocPlttVramKey((struct Layer *)h, &c) == 0)
        return 0;
    func_02069FF8((char *)h, a, b);
    NNS_G3dPlttSetPlttKey((int *)h, c);
    return 1;
fail:
    return 0;
}
