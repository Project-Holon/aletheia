/*
 * function: func_02212560
 * address: 0x02212560
 * packet: pkt_ov199_02212560
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: case 1 precedes case 0 to preserve the backward shared assignment.
 * ABI exception: 3159C legacy void callee leaves allocator pointer in r0;
 * caller immediately uses this result as its workspace.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02082D44 0x02082D44 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0201A920 0x0201A920 thumb
 *   func_0200B400 0x0200B400 thumb
 *   func_0221336C 0x0221336C thumb ov199
 *   func_022136E4 0x022136E4 thumb ov199
 *   func_02213808 0x02213808 thumb ov199
 *   func_02012934 0x02012934 thumb
 *   func_0201A918 0x0201A918 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 *   d_02213C58 0x02213C58 data a4 ov199
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Party;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(void *, unsigned, unsigned);
extern void func_02082BCC(void *, int, unsigned);
extern void func_02082D44(const void *, void *, unsigned);
extern void *func_020124F4(u16);
extern struct Party *func_0201A920(u32 heap);
extern void func_0200B400(unsigned);
extern void func_0221336C(char *, int);
extern void *func_022136E4(void *, void *, void *, int);
extern void func_02213808(char *p, int value);
extern void *func_02012934(const struct BigObj *p);
extern int func_0201A918(void);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern void func_020307B0(void *);
extern const char d_02213D00[];
extern const unsigned d_02213C58[];
int func_02212560(void *a, int unused, u8 *arg)
{
    u8 *p;
    void *v;
    u8 *dst;
    unsigned kind;
    switch (*(unsigned *)(arg + 8)) {
    case 1: kind = 1; break;
    case 0: kind = 1; break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_0203064C(kind, 0x56, 0x8000);
    p = func_0203159C(a, 0x8b0, 0x56);
    func_02082BCC(p, 0, 0x8b0);
    func_02082D44(arg, p + 4, 0x14);
    *(unsigned *)(p + 0x20) = 0;
    if (*(void **)(p + 4) == 0) {
        *(void **)(p + 4) = func_020124F4(1);
        *(unsigned *)p = 1;
    }
    *(void **)(p + 0x30) = func_0201A920(0x56);
    *(void **)(p + 0x34) = func_0201A920(0x56);
    *(void **)(p + 0x38) = func_0201A920(0x56);
    *(void **)(p + 0x3c) = func_0201A920(0x56);
    func_0200B400(0x56);
    func_0221336C((char *)p, 0x56);
    *(void **)(p + 0x18) = func_022136E4((void *)d_02213C58, (void *)9, p, 0x56);
    switch (*(unsigned *)(p + 0xc)) {
    case 0:
        *(unsigned *)(p + 0x1c) = 0;
        func_02213808(*(void **)(p + 0x18), 0);
        break;
    case 1:
        *(unsigned *)(p + 0x1c) = 2;
        func_02213808(*(void **)(p + 0x18), 4);
        break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    dst = *(u8 **)(p + 0x28);
    switch (*(unsigned *)(p + 0x10)) {
    case 0:
        v = func_02012934(*(void **)(p + 4));
        func_02082D44(v, dst + 0xd4, func_0201A918());
        break;
    case 1:
        v = func_0200BAF4((int)func_0200BAC8(func_02012EBC(*(void **)(p + 4))), 0x8056);
        func_02082D44(v, dst + 0xd4, func_0201A918());
        func_020307B0(v);
        break;
    }
    return 1;
}
