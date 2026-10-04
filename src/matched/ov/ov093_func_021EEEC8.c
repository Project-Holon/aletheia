/*
 * function: func_021EEEC8
 * address:  0x021EEEC8
 * packet:   pkt_ov093_021EEEC8
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
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_0201F250  0x0201F250  thumb
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
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021EEFE0(void *s, const u32 *values, void *w);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void func_021EEEC8(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[0], b, (void *)d_021F6398.fc);
    func_021EEFE0((void *)d_021F6398.fc, (const u32 *)c, (void *)d_021F6398.f8);
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}
