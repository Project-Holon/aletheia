/*
 * function: func_02212854
 * address: 0x02212854
 * packet: pkt_ov199_02212854
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: EA04 consumes the live return register from E9F4, with no new setup.
 * lever: derive an integer offset before adding the base, then reduce the enum.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E9F4 0x0200E9F4 thumb
 *   func_0200EA04 0x0200EA04 thumb
 *   func_02005C44 0x02005C44 thumb
 *   func_02005D90 0x02005D90 thumb
 *   d_02213D04 0x02213D04 data a1 ov199
 */
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned);
extern void func_02082BCC(void *, int, int);
typedef unsigned short u16;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern int func_0200E9F4(void *);
extern int func_0200EA04(int);
extern u16 func_02005C44(void);
extern void func_02005D90(unsigned, unsigned);
extern const char d_02213D04[];
typedef enum { tag_2854 = 0x2c0 } Offset2854;
int *func_02212854(int unused, unsigned heap, char *ctx)
{
    Offset2854 offset = tag_2854;
    int *p = func_02030734(heap, 0x44, 0, d_02213D04, offset);
    func_02082BCC(p, 0, 0x44);
    p[2] = (int)(ctx + 4);
    p[3] = *(int *)(ctx + 0x20);
    p[0] = *(int *)(ctx + 0x1c) - 2;
    p[5] = *(int *)(ctx + 0x28);
    p[6] = *(int *)(ctx + 0x2c);
    p[7] = (int)(ctx + 0x40);
    p[8] = (int)(ctx + (offset - 0xf4));
    offset -= 0xf0;
    p[9] = (int)(ctx + offset);
    p[15] = (int)(ctx + 0x7d4);
    p[10] = (int)(ctx + 0x8a8);
    p[11] = (int)(ctx + 0x1b4);
    p[12] = (int)(ctx + 0x224);
    p[13] = (int)(ctx + 0x22c);
    p[14] = (int)(ctx + 0x778);
    p[16] = (int)(ctx + 0x8ac);
    {
        void *q = func_02012EBC(*(void **)(ctx + 4));
        p[4] = func_0200EA04(func_0200E9F4(q));
    }
    if (func_02005C44() != 0x487) func_02005D90(0x487, 0xffff);
    return p;
}
