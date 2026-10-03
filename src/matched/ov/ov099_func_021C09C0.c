/*
 * function: func_021C09C0
 * address: 0x021C09C0
 * packet: pkt_ov099_021C09C0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate unsigned word increment and store use raw +0x1e0 addresses;
 *   casting the result to int preserves the original signed modulo.
 * retry: wave76 R24 fresh pass; EXACT in 1 scratch run. Earlier types300 consumed.
 * prototype-evidence: C23C0 forwards index to ov009 56874, whose full body
 *   returns the tested byte. C23B8 forwards index to ov009 56860 and returns
 *   its address. 362DC's own unit returns a pointer, compared by its u32 bits.
 * arithmetic-evidence: unsigned counter increment preserves original wrapping
 *   add; signed interpretation supplies original signed modulo and comparison.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_02156B8C 0x02156B8C thumb ov009
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021C2810 0x021C2810 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA828 0x021BA828 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K242=0x242, K1e0=0x1e0 } Off;
struct W;
struct Work;
struct S;
extern int func_021BA928(struct W *);
extern int func_02156B8C(void);
extern u8 func_021C23C0(int);
extern void func_021BA874(struct Work *, int);
extern void func_021BAAB8(char *, int, int);
extern struct S *func_021C23B8(int);
extern void func_021C2810(struct S *, char *);
extern void func_021C18C8(char *, int, int);
extern void *func_020362DC(void);
extern void func_021BA828(void *);
static inline int Step(int *dst, int old)
{
    int n;
    n = (int)((u32)old + 1);
    *dst = n;
    return n;
}
int func_021C09C0(char *p, int ret)
{
    Off off;
    u32 counter;
    func_021BA928((struct W *)p);
    if (func_02156B8C() != -1) *(int *)(p + 0x1cc) = 11;
    off = K242;
    if (func_021C23C0(*(u16 *)(p + off) - 1) == 0) {
        func_021BA874((struct Work *)p, *(u16 *)(p + off) - 1);
        func_021BAAB8(p, 15, 0);
        *(int *)(p + (off - 0x76)) = 0x13;
        return ret;
    }
    counter = *(u32 *)(p + 0x1e0) + 1u;
    *(u32 *)(p + 0x1e0) = counter;
    if ((int)counter % 900 == 0) {
        func_021C2810(*(struct S **)(p + 8), (char *)func_021C23B8(*(u16 *)(p + off) - 1));
        func_021C18C8(p, 3, 3);
    }
    off = K1e0;
    if (*(int *)(p + off) > 3600) {
        func_021BA874((struct Work *)p, *(u16 *)(p + (off + 0x62)) - 1);
        func_021BAAB8(p, 15, 0);
        *(int *)(p + (off - 0x14)) = 0x13;
        return ret;
    }
    if ((u32)func_020362DC() == 2) {
        func_021BAAB8(p, 0x47, 0);
        func_021BA828(p);
        *(int *)(p + (off - 0x14)) = 0x89;
    }
    return ret;
}


