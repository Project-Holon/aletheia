/*
 * function: func_021BF8E0
 * address: 0x021BF8E0
 * packet: pkt_ov208_021BF8E0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov072_id 0x00000048 data a1
 *   func_021C1F44 0x021C1F44 thumb ov208
 *   func_021C0C00 0x021C0C00 thumb ov208
 *   func_021C0B58 0x021C0B58 thumb ov208
 *   func_021C0950 0x021C0950 thumb ov208
 *   func_021C0898 0x021C0898 thumb ov208
 *   func_021BC97C 0x021BC97C thumb ov208
 *   func_021C06A0 0x021C06A0 thumb ov208
 *   func_021C0524 0x021C0524 thumb ov208
 *   func_021C03C4 0x021C03C4 thumb ov208
 *   func_021BC61C 0x021BC61C thumb ov208
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_021C06EC 0x021C06EC thumb ov208
 *   func_021BBB34 0x021BBB34 thumb ov072
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 *   func_02034A5C 0x02034A5C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Node;
extern void func_021C1F44(int a);
extern void func_021C0C00(void *a, void *b);
extern void func_021C0B58(void *, char *, void *);
extern void func_021C0950(void *, char *, void *);
extern void func_021C0898(void *, char *, void *);
extern void func_021C06A0(void *, char *, void *);
extern void func_021C0524(void *, char *, void *);
extern void func_021C03C4(void *, char *, void *);
extern void func_021C06EC(void *, char *, void *);
extern void func_021BC97C(char *p);
extern void func_021BC61C(char *p);
extern void func_021BC464(void *);
extern void func_021BBB34(void *);
extern void func_021BC34C(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *);
extern void func_02034A5C(int);
extern u8 ov072_id[];
/* Caller explicitly loads r2 for the three-argument teardown helpers. */
u32 func_021BF8E0(void *a0, u32 a1, void *a2, char *p, void *a4)
{
    u8 i;
    func_021C1F44(*(u32 *)(p + 0x94));
    for (i = 0; i < 2; i++) {
        char *q = p + i * 4;
        if (*(u32 *)(q + 0x5c) != 0) func_021C0C00((void *)(*(u32 *)(q + 0x4c)), (void *)(*(u32 *)(q + 0x5c)));
        *(u32 *)(q + 0x5c) = 0;
    }
    func_021C0B58(a2, p, a4);
    func_021C0950(a2, p, a4);
    func_021C0898(a2, p, a4);
    func_021BC97C(*(void **)(p + 8));
    func_021C06A0(a2, p, a4);
    func_021C0524(a2, p, a4);
    func_021C03C4(a2, p, a4);
    func_021BC61C(*(void **)(p + 0x420));
    func_021BC464(*(void **)(p + 0x41c));
    func_021BC464(*(void **)(p + 0x418));
    func_021C06EC(a2, p, a4);
    func_02030EAC(*(void **)(p + 0x410));
    func_02049238(*(void **)(p + 0x40c));
    func_021BBB34(*(void **)(p + 0x3c8));
    func_021BC34C(a0);
    func_02034A5C((int)ov072_id);
    return 1;
}
