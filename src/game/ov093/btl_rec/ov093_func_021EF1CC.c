/*
 * function: func_021EF1CC
 * address:  0x021EF1CC
 * packet:   pkt_ov093_021EF1CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_02045CAC  0x02045CAC  arm
 *   func_021EEF98  0x021EEF98  thumb  ov093
 *   func_021EF280  0x021EF280  thumb  ov093
 *   func_021EF204  0x021EF204  thumb  ov093
 */

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

extern D d_021F6398;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u8 func_021EEF98(void *s);
extern void func_021EF280(u32 a, u32 b, u32 c);
extern void func_021EF204(u32 a, u32 b, u32 *p);

void func_021EF1CC(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[1], b, (void *)d_021F6398.fc);
    if (func_021EEF98((void *)d_021F6398.fc) == 2)
        func_021EF280(a, b, c);
    else
        func_021EF204(a, b, (u32 *)c);
}
