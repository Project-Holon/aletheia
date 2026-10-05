/*
 * function: func_021D7D0C
 * address: 0x021D7D0C
 * packet: pkt_ov116_021D7D0C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-04 wave D3 lane19: DIFF, 5 listing lines. Whole body matches except the last call func_02049B40(0x17,5,0,0x180,0x20,heap): original stores the 0x20 stack arg (r6, shared with the two func_0203FA08 r1 args) first and loads heap from [sp,#0x14] after it; ours loads heap first. Tried: 6-int and u32-heap prototypes, unprototyped, literal 0x20 vs c20 local, u32 c20, int heap param. Stack slots follow decl order: res,pa,pb,arc,done,t,j,k,q (pb=p;pb+=0x14 and pa=p+0x1f4 assigned after k=0). sh=t>>8 hoisted before a/b.
 * 2026-10-05 (wave D4 lane 04): DIFF, 10 bytes, unchanged. Tried: house prototype func_02049B40(u32
 * x5, u16 f) (adds a lsls/lsrs of heap, 40 bytes); a u16 heap parameter (352 bytes). Residue: the
 * original stores the 0x20 stack argument (r6) before it reloads heap from [sp,#0x14].
 * 2026-10-05 (wD5 lane 11): DIFF, still the same 5 lines (last call setup only). The region after the
 *   last func_0201F5DC call is identical up to the p+0x988 store; the original then keeps the heap reload
 *   after the str r6,[sp] (as if the load had a memory dependence on the outgoing-argument store), ours
 *   hoists it. Tried: offset local `off = 0x1f4` with `off - 0x74` for the 0x180 argument, `k = 0x978` local
 *   for the 0x978/0x984/0x988 fields, u8 c20, const and volatile heap parameter (volatile homes r0-r3, worse),
 *   *(u32 *)&heap at the last call (worse), variadic prototypes (int,int,int,int,...) and (...,int,...),
 *   returning the call result. None moves the load.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203FA08 0x0203FA08 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02021F64 0x02021F64 thumb
 *   func_021D7F54 0x021D7F54 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32, u32);
extern void func_02049B68(void *, int, int, int, int, u32);
extern u32 func_02049740(void *, int, int, int, int, u32);
extern void func_02049990(void *, int, int, int, u16, int, int, u32);
extern void *func_02049F78(void *, u32, void *, u32);
extern void func_02049238(void *);
extern int func_02049B40(int, int, int, int, int, u32);
extern void func_02082BCC(void *, int, u32);
extern void func_02082D44(const void *, void *, u32);
extern void func_020307B0(void *);
extern void *func_020056A0(void *, void *, int);
extern void func_020862F0(void *, u32);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0203FA08(int, int, int);
extern void *func_0201F5DC(int, int, int, u32);
extern void func_02021F64(void *, void *, u16, u8, u16);
extern void func_021D7F54(void *);
struct Arc { int f0; int f4; int f8; u8 *fC; };
void func_021D7D0C(u8 *p, u32 heap) {
    struct Arc *res;
    u8 *pa;
    u8 *pb;
    void *arc;
    int done;
    int t;
    int j;
    int k;
    u8 *q;
    void *blk;
    int m;
    int n;
    int sh;
    int c20;
    u8 *a;
    u8 *b;
    arc = func_020490F4(0x91, heap);
    j = 0;
    func_02049B68(arc, 3, 4, 0, j, heap);
    func_02049990(arc, 6, 4, 0, (u16)func_02049740(arc, 4, 4, 0, j, heap), j, j, heap);
    func_02049B68(arc, 3, 0, 0, j, heap);
    func_02049990(arc, 5, 0, 0, (u16)func_02049740(arc, 4, 0, 0, j, heap), j, j, heap);
    func_02049990(arc, 7, 3, 0, (u16)func_02049740(arc, 4, 3, 0, j, heap), j, j, heap);
    func_02082BCC(p + 0xc, 0, 0x970);
    blk = func_02049F78(arc, 2, &res, (u16)heap);
    func_02082D44(res->fC, p + 0x14, 0x1e0);
    func_02082D44(res->fC, p + 0x1f4, 0x1e0);
    func_020307B0(blk);
    k = 0;
    pa = p + 0x1f4;
    pb = p;
    pb += 0x14;
    for (; k < 15; k++) {
        n = k + 1;
        if (n >= 15) n -= 15;
        t = 0;
        done = 0;
        q = p + n * 32;
        for (;;) {
            a = pb + k * 32;
            sh = t >> 8;
            b = pa + j * 32;
            for (m = 4; m < 11; m++) {
                func_02021F64(a + m * 2, b + m * 2, 1, (u8)sh, *(u16 *)(q + 0x14 + m * 2));
            }
            j++;
            if (done == 1) break;
            t += 0x600;
            if (t >= 0x1000) { t = 0x1000; done = 1; }
        }
    }
    func_020862F0(p + 0x1f4, 0x780);
    *(u32 *)(p + 0x10) = 1;
    *(void **)(p + 0xc) = func_020056A0((void *)func_021D7F54, p + 0xc, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    p[0x978] = 0;
    func_02049238(arc);
    c20 = 0x20;
    func_0203FA08(1, c20, 0);
    func_0203FA08(2, c20, 0);
    *(void **)(p + 0x984) = func_0201F5DC(1, 0xd, 0, heap);
    *(void **)(p + 0x988) = func_0201F5DC(2, 0xd, 0, heap);
    func_02049B40(0x17, 5, 0, 0x180, c20, heap);
}
