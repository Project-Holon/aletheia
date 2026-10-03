/*
 * function: func_021BE6F0
 * address: 0x021BE6F0
 * packet: pkt_ov099_021BE6F0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BE786.
 * lever: a named u8 local narrows the accessor result before bitfield masking.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021C1908 0x021C1908 thumb ov099
 *   func_021C27E8 0x021C27E8 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    u32 f0, f4;
    u8 pad8[12];
    u8 f14, f15, f16, f17, f18, f19, f1a;
    u8 bits0:2;
    u8 bits2:2;
    u8 bits4:4;
} State;
extern u8 *func_02012944(void *);
extern int func_02008550(void *);
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_021C1908(char *, int, int);
extern void func_021C27E8(void *, u8);
extern void func_021C2864(void *, u8);
extern void func_021BE6E4(char *);
void func_021BE6F0(char *p, int a, int b)
{
    void *q;
    u8 t;
    q = func_02012944(*(void **)(p + 0xc4));
    (*(State **)(p + 8))->f15 = 0x15;
    (*(State **)(p + 8))->f16 = 2;
    t = func_02008550(q);
    (*(State **)(p + 8))->bits2 = t;
    (*(State **)(p + 8))->f14 = func_02008554(q);
    func_021C1908(p, a, b);
    (*(State **)(p + 8))->f19 = func_0200856C(q);
    (*(State **)(p + 8))->f1a = func_02008570(q);
    func_021C27E8(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C2864(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    (*(State **)(p + 8))->f4 = func_02008530(q);
    (*(State **)(p + 8))->f0 = func_0200853C(q);
    func_021BE6E4(p);
}
