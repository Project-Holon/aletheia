/*
 * function: func_021D6CC4
 * address:  0x021D6CC4
 * packet:   pkt_ov118_021D6CC4
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Size-correct (320 bytes) but a header register permutation: the original
 * keeps `this` in r5, the index in r7 and the func_021D8FA4 result in r4,
 * and re-reads the 0x844 base inline; dsi/1.1p1 assigns r4=temp / r7=this /
 * r6=index and spills the base, so 143 bytes differ though every call,
 * branch and store is in the same order. The data table d_021D8398 also
 * has no witness outside the range (sole-ref/data refuses). Reached twice
 * from the root. Parked as a near miss; the root still attests it by label.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02015C30  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   d_021D7CDC     0x021D7CDC  data  ov118
 *   d_021D8470     0x021D8470  data  ov118
 *   d_021D8880     0x021D8880  data  ov118
 *   d_021D8398     0x021D8398  data  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 v[4];
} Quad;

extern u32 func_021D8AA8(void *);
extern u32 func_021D8FA4(void *, int);
extern u32 func_02017E1C(u32, int, int);
extern void func_02006984(u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_02015C30(u32, void *);
extern void func_021DFD24(u32);
extern u32 func_021DFBB4(u32, int, void *, u32, const void *);
extern const Quad d_021D7CDC;
extern const u32 d_021D8470[];
extern const u32 d_021D8880[];
extern const u32 d_021D8398[];

void func_021D6CC4(void *a0, int a1)
{
    u32 x;
    u8 buf[12];

    x = func_021D8FA4(a0, 1 - func_021D8AA8(a0));
    func_02017E1C(x, 7, 0);
    if (func_02017E1C(x, 0x4c, 0) == 0) {
        func_02006984(func_02017E1C(x, 0xab, 0), func_02017E1C(x, 0x6f, 0),
                      0x40, 0, 0, 0, 0, 0);
    }
    if (*(u8 *)((char *)a0 + 0x11EE) == 0) {
        func_02015C30(((u32 *)((char *)a0 + 0x844))[a1], buf);
        func_021DFD24(*(u32 *)((char *)a0 + 0x868));
        if (*(u8 *)((char *)a0 + 0x11F0) == 0)
            *(u32 *)((char *)a0 + 0x868) =
                func_021DFBB4(((u32 *)((char *)a0 + 0x844))[a1], 0x28, buf, *(u16 *)((char *)a0 + 0x5F4), d_021D8470);
        else
            *(u32 *)((char *)a0 + 0x868) =
                func_021DFBB4(((u32 *)((char *)a0 + 0x844))[a1], 0x14, buf, *(u16 *)((char *)a0 + 0x5F4), d_021D8880);
        return;
    } else {
        Quad t;
        u32 r6;

        t = d_021D7CDC;
        r6 = ((u32 *)((char *)a0 + 0x844))[t.v[a1]];
        func_02015C30(((u32 *)((char *)a0 + 0x844))[a1], buf);
        func_021DFD24(*(u32 *)((char *)a0 + 0x868));
        if (*(u8 *)((char *)a0 + 0x11F0) == 0)
            *(u32 *)((char *)a0 + 0x868) =
                func_021DFBB4(r6, 0x12, buf, *(u16 *)((char *)a0 + 0x5F4), d_021D8398);
        else
            *(u32 *)((char *)a0 + 0x868) =
                func_021DFBB4(r6, 0x14, buf, *(u16 *)((char *)a0 + 0x5F4), d_021D8880);
    }
}
