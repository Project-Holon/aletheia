/*
 * function: func_021BB4EC
 * address:  0x021BB4EC
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049990  0x02049990  arm
 */
typedef struct {
    char pad[0x9a8];
    int f9a8;               /* 0x9a8 */
} Work;

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *o);

void func_021BB4EC(Work *w)
{
    void *o = func_020490F4(0x21, 0x21);

    func_02049990(o, 0x16, 4, 0, (unsigned short)w->f9a8, 0, 0, 0x21);
    func_02049238(o);
}
