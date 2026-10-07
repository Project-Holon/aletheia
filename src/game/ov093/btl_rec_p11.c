/*
 * file:     btl_rec_p11.c
 * unit:     yes
 * function: func_021EEEC8, func_021EEEF4
 * address:  0x021EEEC8
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
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_0201F250  0x0201F250  thumb
 *   d_021F39D8  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   func_021EF1CC  0x021EF1CC  thumb  ov093
 */
struct MsgBank;
struct WordSet;
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

typedef struct {
    u16 id;
    u16 pad;
    u32 pad2;
} E;

typedef struct {
    void (*fn)(u32, u32, u32);
    u32 pad;
} F;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021EEFE0(void *s, const u32 *values, void *w);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021EF1CC(u32 a, u32 b, u32 c);
void func_021EEEC8(u32 a, u32 b, u32 c);
void func_021EEEF4(u32 a, u16 b, u32 c);
extern D d_021F6398;
extern E d_021F39D8[];
extern F d_021F39DC[];


void func_021EEEC8(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[0], b, (void *)d_021F6398.fc);
    func_021EEFE0((void *)d_021F6398.fc, (const u32 *)c, (void *)d_021F6398.f8);
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}


void func_021EEEF4(u32 a, u16 b, u32 c)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (b == d_021F39D8[i].id) {
            d_021F39DC[i].fn(a, b, c);
            return;
        }
    }
    func_021EF1CC(a, b, c);
}
