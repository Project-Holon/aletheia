/*
 * function: func_021D6B84
 * address:  0x021D6B84
 * packet:   pkt_ov093_021D6B84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E40  0x02017E40  thumb
 *   func_02017F9C  0x02017F9C  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D505C  0x021D505C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    void *w;
    u8 pad4[4];
    u32 f8;
    u8 padC[4];
    u16 f10;
    u16 f12;
    u8 pad14[7];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;

extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_02017F9C(void *p, u32 v);
extern void func_020185C4(void *p);
extern int func_021D62A8(u8 *p);
extern void func_021D505C(void *p);

void func_021D6B84(Obj *p, int flag)
{
    void *w = p->w;
    u32 r;

    func_02017E40(w, 8, p->f8);
    func_02017E40(w, 0xa0, p->f10);
    if (p->f10 != 0)
        func_02017F9C(w, func_021D62A8((u8 *)p));
    else
        func_02017F9C(w, 0);
    func_021D505C(p);
    if (p->f1b_b5 || flag != 0)
        r = p->f1b_lo;
    else
        r = ((u8 *)p)[0x141];
    func_02017E40(w, 0x6f, (u8)r);
    func_020185C4(w);
    func_02017E40(w, 6, p->f12);
}
