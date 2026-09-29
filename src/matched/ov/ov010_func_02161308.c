/*
 * function: func_02161308
 * address:  0x02161308
 * packet:   pkt_ov010_02161308
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocate an 8-byte record and store the save handle at +4. The extent
 * also holds the unlabelled leaf at 0x02161340 (nonzero test of *r1).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char d_02172978[];

extern void *func_020120F4(void *p);
extern void *func_02012EBC(void *p);
extern void func_0200873C(void *p);
extern u32 *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);

u32 *func_02161308(char *c)
{
    u32 *r;

    func_0200873C(func_02012EBC(func_020120F4(**(void ***)(c + 0x18))));
    r = func_02030734(4, 8, 1, d_02172978, 0x705);
    r[1] = **(u32 **)(c + 0x18);
    return r;
}

int func_02161340(int a0, int *a1)
{
    if (*a1 != 0)
        return 1;
    return 0;
}
