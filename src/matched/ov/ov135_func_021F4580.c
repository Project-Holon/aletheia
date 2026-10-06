/*
 * function: func_021F4580
 * address:  0x021F4580
 * packet:   pkt_021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
 * symbols:
 *   func_02202608  0x02202608  thumb
 *   func_022026D8  0x022026D8  thumb
 *   func_021F489C  0x021F489C  thumb
 *   func_021F5074  0x021F5074  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args;

typedef struct {
    u8 pad0[0xB68];
    void *words;
    void *msg[5];
    u8 padB80[0xEA8 - 0xB80];
    void *mon;
    u8 padEAC[0xF94 - 0xEAC];
    void *rec;
    u8 padF98[0xF9C - 0xF98];
    void *recMem;
    u8 ctx[0x12F0 - 0xFA0];
    void *save;
    u8 pad12F4[0x132C - 0x12F4];
} Work;

struct Ctx;
struct MsgBank;
struct WordSet;
extern int func_02034AC4(s32 handle);
extern u8 ov114_id[];
extern u8 ov067_id[];
extern void func_0203064C(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_02031324(int a0);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_022026D8(void *ctx, u32 arg);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021F489C(Work *p, Args *args);
extern void func_0204335C(u32 keep);
extern void func_021F5074(Work *p);
extern void func_02005DE4(void *p);
extern void func_02005D28(void);

extern Work *g_02203F80;
extern const char str_02203AF8[];

int func_021F4580(void *proc, int *seq, Args *args)
{
    Work *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x48, 0x30100);
    p = func_0203159C(proc, sizeof(Work), 0x48);
    func_02082BCC(p, 0, sizeof(Work));
    g_02203F80 = p;
    p->mon = func_02202608(0x48);
    p->save = func_02031324(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec = func_02030CBC(8, p->recMem);
    func_022026D8(p->ctx, args->x20);
    p->words = func_0201EC74(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    func_021F489C(p, args);
    func_0204335C(0);
    func_021F5074(p);
    func_02005DE4(0);
    func_02005D28();
    return 1;
}
