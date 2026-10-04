/*
 * function: func_021F962C
 * address:  0x021F962C
 * packet:   pkt_021F962C
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC   0x02012EBC  thumb
 *   func_021FC4DC   0x021FC4DC  thumb
 *   func_020071CC   0x020071CC  thumb
 *
 * Fill the output record from the source object and its nested handle.
 */


typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern u32 func_021FC4DC(u8 *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *, unsigned int);

void func_021F962C(char *r5, int *r4)
{
    int x;
    x = (int)func_02012EBC((struct Big *)(*(int *)(*(int *)(*(int *)((char *)r4 + 0x18) + 0xC) + 4)));
    *(int *)(r5 + 8) = r4[1];
    *(int *)r5 = r4[3];
    *(int *)(r5 + 0xC) = r4[2];
    *(int *)(r5 + 4) = func_021FC4DC((u8 *)r4[0]);
    *(int *)(r5 + 0x10) = (int)func_020071CC((struct Sub020071CCCtrl *)x, 0x3a);
    *(int *)(r5 + 0x14) = *(int *)(*(int *)(*(int *)((char *)r4 + 0x18) + 0xC) + 4);
}
