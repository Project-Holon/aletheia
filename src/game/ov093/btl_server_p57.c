/*
 * file:     btl_server_p57.c
 * unit:     yes
 * function: func_021C2E64, func_021C2F70
 * address:  0x021C2E64
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C2E4C 0x021C2E4C thumb ov093
 *   func_0201C020 0x0201C020 thumb
 *   func_021C3008 0x021C3008 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C78A8 0x021C78A8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   sub_0201C0BC  0x0201C0BC  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct { u32 x; } W;

enum Kind { K0, K1, K10 = 10 };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

typedef signed char s8;

typedef signed short s16;

extern u8 func_021D5440(u8 *p);
extern u32 func_021C2E4C(u8 *);
extern u8 func_0201C020(u16);
extern int func_021C3008(u8 *, u8, u8 *, enum Kind, s32, u8, u16, u32, int, u32);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C78A8(u8 *, u8 *, u32, u32, u32);
extern u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k);
void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2);

/*
 * lever: enum Kind keeps the output guard in r0 and reloads it into r3 at the call.
 */
int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k)
{
    u8 id;
    int result;
    u32 count, i;
    u32 serial;
    enum Kind kind;
    s32 value;
    int ok;
    u8 j;
    u32 lock;
    result = 0;
    id = func_021D5440(a);
    serial = func_021C2E4C(p);
    count = func_0201C020(*q);
    for (i = 0; i < count; i++) {
        ok = 0;
        func_021C2F70(p, *q, i, a, b, (s32 *)&kind, &value);
        if (kind != 0) {
            if (kind != 10) {
                ok = func_021C3008(p, id, b, kind, value, id, ok, serial, k, 1);
            } else {
                for (j = 1; j < 6; j++) {
                    if (func_021C3008(p, id, b, j, value, id, 0, serial, k, 1)) ok = 1;
                }
            }
            if (ok) {
                lock = func_021CC8D8((struct Lock *)(p + 0x1d74), 8247);
                func_021C78A8(p, b, *q, kind, value);
                func_021CC95C((u32 *)(p + 0x1d74), lock, 8249);
                result = 1;
            }
        }
    }
    return result;
}


void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = sub_0201C0BC(x, y, s2);
    func_021D74F8(8275);
    func_021D75EC(3, func_021D5440(c));
    func_021D75EC(4, func_021D5440(s0));
    func_021D75A8(0x1F, *s1);
    func_021D75A8(0x20, *s2);
    func_021D75A8(0x35, 1);
    func_021D70F0(p, 0x59);
    *s1 = func_021D775C(0x1F);
    *s2 = func_021D775C(0x20);
    m = (u8)func_021D775C(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    func_021D7540(8290);
    if (*s1 == 8)
        *s1 = 0;
}
