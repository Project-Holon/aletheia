/*
 * function: func_021BF9FC
 * address: 0x021BF9FC
 * packet: pkt_ov204_021BF9FC
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing two bytes are zero alignment padding; separate component stores preserve ascending order.
 * symbols:
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 */

struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_0207ADC4(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern void func_02047A60(void *, void *);

void func_021BF9FC(char *p)
{
    struct Transform { int pos[3]; int scale[3]; int matrix[9]; } t;
    func_02048AD0(*(void **)(p + 12));
    if (*(unsigned int *)(p + 20) != 0 && *(unsigned int *)(p + 24) != 0)
    {
        t.pos[0] = 0;
        t.pos[1] = 0;
        t.pos[2] = 0;
        t.scale[0] = 4096;
        t.scale[1] = 4096;
        t.scale[2] = 4096;
        func_0207ADC4(t.matrix);
        func_02047A60((void *)func_02048A18(*(void **)(p + 8), *(unsigned short *)(p + 16)), &t);
    }
}
