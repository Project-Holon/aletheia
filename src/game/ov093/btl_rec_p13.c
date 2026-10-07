/*
 * file:     btl_rec_p13.c
 * unit:     yes
 * function: func_021EF694, func_021EF6A8
 * address:  0x021EF694
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_02045CAC  0x02045CAC  arm
 *   func_021EF6B0  0x021EF6B0  thumb  ov093
 */
struct MsgBank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021EF6B0(u32 a, u32 b, u32 c);
void func_021EF694(u32 a, u32 b);
void func_021EF6A8(u32 a, u32 b, u32 c);
extern D d_021F6398;


void func_021EF694(u32 a, u32 b)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[3], b, (void *)a);
}


void func_021EF6A8(u32 a, u32 b, u32 c)
{
    func_021EF6B0(a, b, c);
}
