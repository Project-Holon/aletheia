/*
 * function: func_021F5074
 * address:  0x021F5074
 * packet:   pkt_021F5074
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   func_021F4EDC  0x021F4EDC  thumb
 *   func_021F49A8  0x021F49A8  thumb
 *   func_021F4864  0x021F4864  thumb
 *   tbl_02202BB8  0x02202BB8  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef volatile u16 vu16;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

typedef struct {
    u8 pad0[0xF90];
    void *vblank;
} Work;

extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_02043534(int a);
extern void func_020435F4(u32 a);
extern void func_021F4EDC(Work *p);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(int heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021F49A8(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021F4864(void *unused, Work *p);

extern const struct DispConfig tbl_02202BB8;

void func_021F5074(Work *p)
{
    func_020434CC();
    func_02043588();
    func_02043534(0);
    func_020435F4(0);
    func_021F4EDC(p);
    func_0203F8F4(0x48);
    func_02045088(0x48);
    {
        struct DispConfig c = tbl_02202BB8;

        func_0203FC28(&c);
    }
    func_021F49A8();
    *(vu16 *)0x04000050 = 0;
    *(vu16 *)0x04001050 = 0;
    if (p->vblank == 0) {
        p->vblank = func_020056A0(func_021F4864, p, 0);
    }
}
