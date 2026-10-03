/*
 * function: func_021E72FC
 * address: 0x021E72FC
 * packet: pkt_ov177_021E72FC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: full flag byte times 32 narrowed by fourth callee parameter; no three-bit mask.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 */
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0204B294(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned func_0204AC18(void *, unsigned, unsigned, unsigned short, unsigned, unsigned, unsigned);
extern unsigned func_0204A6C8(void *, unsigned, unsigned, unsigned, unsigned);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern const unsigned char d_021E8CBE[];
void func_021E72FC(unsigned char *p, unsigned idx, unsigned owner, unsigned heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    *(unsigned *)(p + 0x1e8) = func_0204AC18(handle, 0, *(unsigned *)(p + 0x234), p[0x233] * 32, d_021E8CBE[idx], 1, heap);
    *(unsigned *)(p + 0x1ec) = func_0204A6C8(handle, idx + 0x31, 0, *(unsigned *)(p + 0x234), heap);
    *(unsigned *)(p + 0x1f0) = func_0204AF28(handle, 0x41, 0x42, heap);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.y = 0;
    req.x = 0;
    req.flag = 1;
    *(void **)(p + 0x188) = func_0204B294(owner, *(unsigned *)(p + 0x1ec), *(unsigned *)(p + 0x1e8), *(unsigned *)(p + 0x1f0), &req, *(unsigned *)(p + 0x234), heap);
    func_0204B6F4(*(void **)(p + 0x188), 0, 1);
}
