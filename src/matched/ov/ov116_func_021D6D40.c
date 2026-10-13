/*
 * function: func_021D6D40
 * address: 0x021D6D40
 * packet: pkt_ov116_021D6D40
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02012EF0 has no witness outside 021D6D40..021D6E3C;
 * singleton tu --suggest-split returns MATCH252, no viable partition.
 * blocker: 02012EF0 verified EXACT12 in B10/12EF0-proof.log, no region,
 * fixed dsi/1.1p1 -O4,p Thumb; copied prior 6CBC blocker, owner the integrator.
 *   extern int func_020071CC(void *, int);
 *   int func_02012EF0(void **p) { return func_020071CC(*p, 58); }
 * evidence: 084F4 is bx lr and preserves its incoming pointer in r0;
 * caller consumes it despite the matched callee's void signature.
 * evidence: 08550's matched body returns zero-extended byte +1d;
 * original caller explicitly truncates that r0 before the byte bitfield.
 * A wide extern and explicit u8 cast retain that redundant conversion.
 * checks: 1 own callee/unit bodies and original live registers agree;
 * 2 full 6CBC/6A5C/6E50 twins; 3 wide8550+u8 cast fixes missing4B;
 * 4 redundant-bitfield/result-truncation idioms; 5 fresh full idiom ls
 * and full 6C50/6A5C/6E50 neighbours. Iteration2, no stop exhaustion.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02009470 0x02009470 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_02012EF0 0x02012EF0 thumb
 *   func_0200E6F0 0x0200E6F0 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_02008530 0x02008530 thumb
 *   d_0209DF08 0x0209DF08 data a1
 *   d_0209DF0C 0x0209DF0C data a1
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_02025C88 0x02025C88 thumb
 *   func_0200E6FC 0x0200E6FC thumb
 *   func_0200DCF8 0x0200DCF8 thumb
 *   func_0200DC74 0x0200DC74 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 a : 1, b : 1, c : 6; } Bits;
struct Big;
struct BigObj;
struct Blk1AC;
struct Rec0200E6FC;
struct Sub0200852CObj;
struct Sub02009470Obj;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_02012EF0(void **p);
extern void *func_0200E6F0(u32);
extern void func_02082BCC(void *, u8, u32);
extern const void *func_020084F4(const void *p);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 d_0209DF08, d_0209DF0C;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 func_02025C88(u32);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u16 func_0200DCF8(struct Blk1AC *p);
extern void func_0200DC74(struct Blk1AC *p, u32 which, void *dest);
void func_021D6D40(u8 *p, void *save, void *idx)
{
    void *profile, *n, *object;
    int i;
    profile = func_02012EBC(save);
    func_02009470(profile);
    func_0201283C(save);
    n = func_02012EF0(save);
    object = func_0200E6F0((u32)profile);
    func_02082BCC(p, 0, 240);
    func_02082D44(func_020084F4(idx), p + 0xb4, 16);
    *(u32 *)(p + 0xc8) = func_02008530(idx);
    p[0xc4] = d_0209DF08;
    p[0xc5] = d_0209DF0C;
    p[0xc6] = func_0200856C(idx);
    p[0xc7] = func_02008570(idx);
    ((Bits *)(p + 0xd4))->b = (u8)(u32)func_02008550(idx);
    p[0xd5] = func_02008554(idx);
    p[0xd5] = func_02025C88(p[0xd5]);
    for (i = 0; i < 3; i++) func_0200E6FC(object, i + 1, (struct Rec0200E6FC *)(p + 0xd6 + i * 8));
    func_0200E6FC(object, 4, (struct Rec0200E6FC *)(p + 0xcc));
    *(u16 *)(p + 0xee) = func_0200DCF8(n);
    func_0200DC74(n, 1, p);
}
