/*
 * function: func_021BC12C
 * address:  0x021BC12C
 * packet:   pkt_ov088_021BC12C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov194 id is held in a local (the original keeps it in r7 across the
 * copy loop and reuses it for the unload); the ov204 id is spelled
 * directly and reloaded from the pool for each call.
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_0203159C  0x0203159C  arm
 *   func_021BD25C  0x021BD25C  thumb  ov088
 *   func_02007220  0x02007220  thumb
 *   func_0200846C  0x0200846C  thumb
 *   func_020082EC  0x020082EC  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   func_02031324  0x02031324  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02005A98  0x02005A98  thumb
 *   func_020069D4  0x020069D4  thumb
 *   ov194_id       0x000000C2  data
 *   ov204_id       0x000000CC  data
 *   d_021F557C     0x021F557C  data  ov194  a4
 *   d_021F558C     0x021F558C  data  ov194  a4
 *   d_021BFD20     0x021BFD20  data  ov204  a4
 *   d_021BFD30     0x021BFD30  data  ov204  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Sub02005A98Hdr;
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern char *func_0203159C(int, int, int);
extern void *func_021BD25C(int a, int b);
extern void *func_02007220(struct Sub020071E4Ctrl *ctrl);
extern void *func_0200846C(int a0);
extern void *func_020082EC(int a0);
extern int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
extern u32 func_02031324(int heap);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int handle);
extern struct Sub02005A98Hdr *func_02005A98(const u32 *a0, u32 a1);
extern int func_020069D4(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern u8 ov194_id[];
extern u8 ov204_id[];
extern u32 d_021F557C;
extern u32 d_021F558C[];
extern u32 d_021BFD20;
extern u32 d_021BFD30[];

int func_021BC12C(int a0)
{
    u32 buf[30];
    void *sys;
    char *w;
    u32 n1, n2, i;
    u32 r;
    void *id;

    sys = func_020070A4();
    w = func_0203159C(a0, 0x5c, 1);
    *(u32 *)(w + 0x2c) = (u32)func_021BD25C(1, (int)sys);
    func_02007220(sys);
    *(u32 *)(w + 0x54) = (u32)func_0200846C(1);
    *(u32 *)(w + 0x58) = (u32)func_020082EC(1);
    *(u32 *)(w + 0x0) = 0;
    *(u32 *)(w + 0x4) = *(u32 *)(w + 0x58);
    *(u32 *)(w + 0x8) = *(u32 *)(w + 0x54);
    *(u32 *)(w + 0x28) = (u32)func_0216BFD4(1, 0, 0, 0, 7, 0, 0);
    *(u32 *)(w + 0x30) = func_02031324(1);

    id = ov194_id;
    func_02034AC4((int)id);
    n1 = d_021F557C;
    for (i = 0; i < n1; i++)
        buf[i] = d_021F558C[i];
    func_02034A5C((int)id);

    func_02034AC4((int)ov204_id);
    n2 = d_021BFD20;
    for (i = 0; i < n2; i++)
        buf[n1 + i] = d_021BFD30[i];
    func_02034A5C((int)ov204_id);

    *(u32 *)(w + 0x34) = (u32)func_02005A98(buf, n1 + n2);
    r = func_020069D4(0x23c, 0, 0x40, 0, 0, 0, 0, 0);
    *(u32 *)(w + 0x50) = r;
    *(u32 *)(w + 0x10) = *(u32 *)(w + 0x54);
    *(u32 *)(w + 0x14) = *(u32 *)(w + 0x58);
    *(u32 *)(w + 0x18) = 1;
    *(u32 *)(w + 0x1c) = *(u32 *)(w + 0x2c);
    *(u32 *)(w + 0x20) = r;
    return 1;
}
