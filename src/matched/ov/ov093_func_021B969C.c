/*
 * function: func_021B969C
 * address: 0x021B969C
 * packet: pkt_ov093_021B969C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (258 bytes, two trailing padding bytes)
 * symbols:
 *   func_021B985C 0x021B985C thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D6B84 0x021D6B84 thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_0201A98C 0x0201A98C thumb
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021D5864 0x021D5864 thumb ov093
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021D6C3C 0x021D6C3C thumb ov093
 *   func_021D5848 0x021D5848 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021B985C(char *p, int i);
extern char *func_021B9AEC(char *, int);
struct Party;
struct PartyMon;
struct QH;
struct R4;
struct Rec534;
struct Work;
extern u32 func_0201AA18(void *p);
extern void func_0201A948(struct Party *p);
extern void *func_021B9BF0(void *, u8);
extern void func_021D6B84(void *, int);
extern void *func_021D5844(void *);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern int func_021D6C24(struct R4 *p);
extern void *func_021D5864(struct Work *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021D6C3C(void **p, void *q);
extern void func_021D5848(struct QH *p, void *v);
void func_021B969C(char *a, char *b, int k, int flag)
{
    void *list;
    char *g;
    u32 n, i, j;
    void *m, *e;
    void *h;
    u8 links[6];
    list = (void *)func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    func_0201A948(*(void **)(b + 0x2b8));
    for (i = 0; i < 6; i++) links[i] = 6;
    for (i = 0; i < n; i++) {
        m = func_021B9BF0(g, i);
        func_021D6B84(m, flag);
        func_0201A98C(*(void **)(b + 0x2b8), func_021D5844(m));
        if (func_021D6C24(m)) {
            h = func_021D5864(m);
            for (j = 0; j < n; j++) {
                if (h == func_021D5844(func_021B9BF0(g, j))) {
                    links[i] = j;
                    break;
                }
            }
        }
    }
    func_0201AC2C(*(void **)(b + 0x2b8), list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        m = func_021B9BF0(g, i);
        func_021D6C3C(m, e);
        if (links[i] != 6)
            func_021D5848(m, func_0201AB28(list, links[i]));
    }
}
