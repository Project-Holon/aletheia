/*
 * function: func_021DD5C8
 * address: 0x021DD5C8
 * packet: pkt_ov183_021DD5C8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_0200DABC 0x0200DABC thumb
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021DE084 0x021DE084 thumb ov183
 *   d_021E3350 0x021E3350 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct Record { u8 a, b, c, d; int value; };
struct Triple { int a, b, c; };
extern const struct Record d_021E3350[];
extern int func_021FC20C(char *);
extern int func_021FC214(char *);
extern void func_021FB964(int, int, int);
extern void *func_021FC6A4(int, u8, u8, u8, u8, u8, void *, u16);
extern void func_021FC868(void *, int, int, int);
extern void func_021FC754(void *, int, int, int, u16);
extern void *func_021FD12C(int, int, int);
extern void func_021FD170(void *, int, int);
extern int func_0200DABC(int);
extern int func_021FC124(int, int, struct Triple *);
extern void func_021DE084(void *, int, struct Triple *, int, short, short, u16);
void func_021DD5C8(char *p, char *q)
{
    int first, second, v;
    struct Triple triple;
    const struct Record *rec;
    u8 a, b, c, d;
    first = func_021FC20C(*(char **)(q + 8));
    second = func_021FC214(*(char **)(q + 8));
    func_021FB964(*(int *)(q + 8), 14, *(u16 *)(p + 0x7c));
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    *(void **)(p + 0x34) = func_021FC6A4(1, a, b, c, d, 14, *(void **)(p + 4), *(u16 *)(p + 0x7c));
    func_021FC868(*(void **)(p + 0x34), 0, 1, 0);
    func_021FC754(*(void **)(p + 0x34), second, rec->value, first, 0x3da0);
    *(void **)(p + 0x1c) = func_021FD12C(*(int *)(q + 8), *(int *)(p + 4), *(u16 *)(p + 0x7c));
    func_021FD170(*(void **)(p + 0x1c), *(int *)(q + 8), 0x86);
    v = func_0200DABC(*(int *)(q + 0x10));
    func_021FC124(*(int *)(q + 8), 13, &triple);
    func_021DE084((void *)(p + 8), *(int *)(q + 4), &triple, v, 0x68, 0x58, *(u16 *)(p + 0x7c));
}
