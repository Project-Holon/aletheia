/*
 * file:     btl_rec_p14.c
 * unit:     yes
 * function: func_021EF6B0, func_021EF6E8
 * address:  0x021EF6B0
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
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data   a4
 *   func_021EF6F0  0x021EF6F0  thumb  ov093
 */
struct MsgBank;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

extern void func_021EEFE0(void *s, const u32 *values, void *w);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021EF6F0(u32 a, u32 b, u32 c);
void func_021EF6B0(u32 a, u32 b, u32 c);
void func_021EF6E8(u32 a, u32 b, u32 c);
extern D d_021F6398;


void func_021EF6B0(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.f24, b, (void *)d_021F6398.fc);
    d_021F6398.f5a = 1;
    func_021EEFE0((void *)d_021F6398.fc, (const u32 *)c, (void *)d_021F6398.f8);
    d_021F6398.f5a = 0;
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}


/*
 * Tail-call stub (ldr r3,[pc]; bx r3) to func_021EF6F0; callee of func_021EA55C case 6.
 */
void func_021EF6E8(u32 a, u32 b, u32 c)
{
    func_021EF6F0(a, b, c);
}
