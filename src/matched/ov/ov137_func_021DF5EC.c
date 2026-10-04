/*
 * function: func_021DF5EC
 * address: 0x021DF5EC
 * packet: pkt_ov137_021DF5EC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021E1784 0x021E1784 thumb ov137
 *   func_0201088C 0x0201088C thumb
 *   func_0202EE30 0x0202EE30 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_021E1784(void *, int);
extern void *func_0201088C(unsigned, unsigned);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
int func_021DF5EC(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 205, 40)) {
        func_021E1784(p, (*(int **)(p + 40))[3]);
        *(void **)(p + 3488) = func_0201088C(114, (*(unsigned **)(*(u8 **)(p + 216) + 20))[1]);
        *(void **)(p + 3496) = func_0202EE30(*(void **)(p + 3480), *(void **)(p + 3312), 15, 16, 114);
        *(int *)p = 44;
    }
    return 0;
}
