/*
 * function: func_021E57E0
 * address:  0x021E57E0
 * packet:   pkt_021E57E0
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC   0x02012EBC  thumb
 *   func_02012944   0x02012944  thumb
 *   func_0200CA1C   0x0200CA1C  thumb
 *   func_0200873C   0x0200873C  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0200CA38   0x0200CA38  thumb
 *
 * Populate the 0x28-byte record from the two source objects.
 */


typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Blk37;
struct Sub02008700Obj;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *a);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern unsigned int func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);

void func_021E57E0(int *r5, int *r6, char *r4)
{
    int a;
    int b;
    a = (int)func_02012EBC((struct Big *)r5[5]);
    func_02012944((void *)r5[5]);
    b = (int)func_0200CA1C((void *)r5[5]);
    *(int *)r4 = r6[1];
    *(int *)(r4 + 8) = r5[5];
    *(int *)(r4 + 4) = (int)func_0200873C((void *)a);
    *(char *)(r4 + 0xC) = 1;
    *(char *)(r4 + 0xD) = 1;
    *(char *)(r4 + 0xE) = func_0201AA18((void *)r6[1]);
    *(char *)(r4 + 0xF) = 0;
    *(char *)(r4 + 0x10) = 0;
    *(char *)(r4 + 0x11) = 0;
    *(char *)(r4 + 0x12) = 0;
    *(short *)(r4 + 0x14) = 0;
    *(int *)(r4 + 0x18) = func_0200CA38((struct Blk37 *)b);
    *(int *)(r4 + 0x20) = 0;
    *(int *)(r4 + 0x24) = 0;
}
