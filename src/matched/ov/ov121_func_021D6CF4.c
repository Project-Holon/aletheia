/*
 * function: MYSTERY_CreateParticle
 * address: 0x021D6CF4
 * packet: pkt_ov121_021D6CF4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   d_021DFB80 0x021DFB80 data ov121 a1
 */
extern void MI_CpuFill8(void *, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern const char d_021DFB80[];
void MYSTERY_CreateParticle(int *p, int heap)
{
    void *v;
    MI_CpuFill8(p, 0, 16);
    p[3] = 1;
    v = func_02030734(heap, 0x4800, 0, d_021DFB80, 0x482);
    p[2] = (int)v;
    p[0] = (int)PARTICLE_CreateSystemDefault((int)v, 0x4800, 1, heap);
}
