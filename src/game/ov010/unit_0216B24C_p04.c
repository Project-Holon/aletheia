/*
 * file:     unit_0216B24C_p04.c
 * unit:     yes
 * function: func_0216B970, func_0216B994, func_0216B9D8, func_0216BA08, func_0216BA40, func_0216BA88, func_0216BAE8, func_0216BB18, func_0216BB70, func_0216BB80, func_0216BB90, func_0216BBB4, func_0216BBC4, func_0216BBD4, func_0216BC88, func_0216BCE4, func_0216BD1C, func_0216BD54, func_0216BE20, func_0216BEC0
 * address:  0x0216B970
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200E458 0x0200E458 thumb
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0200C34C 0x0200C34C thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C37C  0x0200C37C  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_020891E0  0x020891E0  arm
 *   d_021723BC 0x021723BC data a1
 *   d_021723BD 0x021723BD data a1
 *   d_021723BE 0x021723BE data a1
 *   d_021723BF 0x021723BF data a1
 *   d_021723C0 0x021723C0 data a1
 *   d_021723C1 0x021723C1 data a1
 *   d_021723C2 0x021723C2 data a1
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F39B8  0x021F39B8  thumb  ov045
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021F3AA0  0x021F3AA0  thumb  ov059
 *   func_021F3B68 0x021F3B68 thumb ov059
 *   func_021F3B40 0x021F3B40 thumb ov059
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202F630  0x0202F630  thumb
 */
struct Blk34;
struct RTCDate;
struct RTCTime;
struct Ctx;
struct Obj00020;
struct VecFx32;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

extern u16 func_0200E458(const u16 *, int);
extern u32 func_0200E47C(u8 *p, int i);
extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(void *sys);
extern u8 func_0200C32C(struct Blk34 *p);
extern u16 func_0200C34C(struct Blk34 *p, u32 i);
extern void *func_0200C0F0(void *sys);
extern unsigned long long func_0200C37C(struct Blk34 *p);
extern u64 func_0203F524();
extern void func_020891E0(struct RTCDate *date, struct RTCTime *time, long long sec);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F39B8();
extern void func_0215897C(void *vm, void *task);
extern void func_021F3AA0();
extern void *func_021F3B68(void *, u32);
extern void *func_021F3B40(void *, u32);
extern void *func_0215A5E4(void *work);
extern void *func_02012934(const struct BigObj *p);
extern u16 *func_02159AE8(void *ctx, void *work);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_0202F488(int a0, int a1);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0202F630(u32 a, u32 b);
u32 func_0216B970(const u16 *p, int index);
int func_0216B994(int c, int vm);
int func_0216B9D8(int a0);
int func_0216BA08(void *p);
int func_0216BA40(int c, int vm);
u16 func_0216BA88(int c);
u16 func_0216BAE8(int p);
int func_0216BB18(void *sys);
int func_0216BB70(int index);
int func_0216BB80(int index);
void func_0216BB90(int index, u8 *out);
int func_0216BBB4(int index);
int func_0216BBC4(int index);
int func_0216BBD4(int c, int vm);
int func_0216BC88(int c, int vm);
int func_0216BCE4(void *ctx, void *vm);
int func_0216BD1C(void *ctx, void *vm);
int func_0216BD54(void *ctx, void *work);
int func_0216BE20(int a, int b, int e, int d, u16 *out);
int func_0216BEC0(int c, int vm);
extern const u8 d_021723BC[];
extern const u8 d_021723BD[];
extern const u8 d_021723BE[], d_021723BF[], d_021723C0[];
extern const u8 d_021723C1[];
extern const u8 d_021723C2[];

u32 func_0216B970(const u16 *p, int index)
{
    u32 x = func_0200E458(p, index);
    x += func_0200E47C((u8 *)p, index);
    if (x > 999999) x = 999999;
    return x;
}


int func_0216B994(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;

    func_0216BB90(vm, buf);
    n = (u8)func_0216BB80(vm);
    lim = func_0216BBB4(vm);
    for (i = 0; i < n; i++) {
        if (func_0216B970((const u16 *)c, buf[i]) < lim) {
            return 0;
        }
    }
    return 1;
}


int func_0216B9D8(int a0)
{
    int t4;
    int t5;
    void *p;

t4 = a0 + 0;
    func_0200E394((void *)a0);
loc_0216B9E0:
a0 = t4 + 0;
    p = func_0200C0E8((void *)a0);
loc_0216B9E6:
    a0 = func_0200C32C(p);
loc_0216B9EA:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216BB18((void *)a0);
loc_0216B9F2:
t4 = a0 + 0;
a0 = t5 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    a0 = func_0216BBC4(a0);
loc_0216B9FC:
    if (a0 > t4) goto loc_0216BA04;
loc_0216BA00:
a0 = 1;
    return a0;
loc_0216BA04:
a0 = 0;
    return a0;}

int func_0216BA08(void *p)
{
    void *q;
    int i, n;
    q = func_0200C0E8(p);
    n = (u8)func_0216BB80(func_0200C32C(q));
    for (i = 0; i < n; i++) {
        if (func_0200C34C(q, (u8)i) == 0) return 0;
    }
    return 1;
}


int func_0216BA40(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;

    func_0216BB90(vm, buf);
    n = (u8)func_0216BB80(vm);
    func_0216BBB4(vm);
    for (i = 0; i < n; i++) {
        if (func_0216B970((const u16 *)c, buf[i]) < 999999) {
            return 0;
        }
    }
    return 1;
}


u16 func_0216BA88(int c)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;
    u32 best;
    void *r7;
    int r4;

    r7 = func_0200E394((void *)c);
    r4 = func_0200C32C(func_0200C0E8((void *)c));
    lim = func_0216BBB4(r4);
    n = (u8)func_0216BB80(r4);
    func_0216BB90(r4, buf);
    best = 1009998;
    for (i = 0; i < n; i++) {
        u32 v = func_0216B970(r7, buf[i]);
        if (v < best) {
            best = v;
        }
    }
    return lim - best;
}

/*
 * arithmetic: subtract in u32, then interpret the resulting sign bit as
 * target int before the BPL clamp; this preserves SUB wrapping without bounds.
 * interface: BB18's old file says void, but this caller loads p into r0
 * at 0216BAFC and BB18 forwards entry r0 to 0200C0F0; preserve that input.
 */
u16 func_0216BAE8(int p)
{
    int index, elapsed, x;
    func_0200E394((void *)p);
    index = func_0200C32C(func_0200C0E8((void *)p));
    elapsed = func_0216BB18((void *)p);
    x = (int)((u32)func_0216BBC4((u8)index) - (u32)elapsed);
    if (x < 0) x = 0;
    return (u16)x;
}


int func_0216BB18(void *sys)
{
    u32 a[7];
    void *r4;
    u64 t;

    r4 = func_0200C0F0(sys);
    if (func_0200C32C(r4) == 0) {
        return 0;
    }
    t = func_0200C37C(r4);
    func_020891E0((struct RTCDate *)(a + 3), (struct RTCTime *)a, func_0203F524() - t);
    if (a[3] != 0 || a[4] > 1 || a[5] > 1) {
        return 24;
    }
    return (u16)a[0];
}

/*
 * arithmetic: address and stride are unsigned 32-bit additions, preserving
 * the original MUL/ADD wrapping for every input bit pattern.
 */
int func_0216BB70(int index)
{
    return *(const u8 *)((u32)d_021723BC + (u32)index * 7u);
}

int func_0216BB80(int index)
{
    return *(const u8 *)((u32)d_021723BD + (u32)index * 7u);
}

/*
 * arithmetic: unsigned 32-bit address/stride arithmetic preserves original
 * MUL/ADD wrapping; each byte load remains ordered before its output store.
 */
void func_0216BB90(int index, u8 *out)
{
    out[0] = *(const u8 *)((u32)d_021723BE + (u32)index * 7u);
    out[1] = *(const u8 *)((u32)d_021723BF + (u32)index * 7u);
    out[2] = *(const u8 *)((u32)d_021723C0 + (u32)index * 7u);
}

int func_0216BBB4(int index)
{
    return *(const u8 *)((u32)d_021723C1 + (u32)index * 7u);
}

int func_0216BBC4(int index)
{
    return *(const u8 *)((u32)d_021723C2 + (u32)index * 7u);
}


int func_0216BBD4(int c, int vm)
{
    void *ws;
    void *p8;
    void *p10;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int buf[3];
    int vec[3];
    int *x;
    int *y;
    int r;

    ws = func_0215A5F4((void *)vm);
    p8 = func_0215A5DC((void *)vm);
    p10 = func_0201210C((void *)p8);
    a1 = func_02159B10((void *)c, (void *)vm);
    a2 = func_02159B10((void *)c, (void *)vm);
    a3 = func_02159B10((void *)c, (void *)vm);
    a4 = func_02159B10((void *)c, (void *)vm);
    a5 = func_02159B10((void *)c, (void *)vm);
    a6 = func_02159B10((void *)c, (void *)vm);
    func_021A3038(func_02188CB4((void *)p10), (struct VecFx32 *)buf);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    if (a1 == 0) {
        x = buf;
        y = vec;
    } else {
        x = vec;
        y = buf;
    }
    r = func_021F39B8(p8, a1, x, y, a5 << 15, a6);
    if (r == 0) {
        return 1;
    }
    func_0215897C(ws, (void *)r);
    return 1;
}


int func_0216BC88(int c, int vm)
{
    void *p;
    int a1;
    int a2;
    int a3;
    int a4;
    int vec[3];

    p = func_0215A5DC((void *)vm);
    a1 = func_02159B10((void *)c, (void *)vm);
    a2 = func_02159B10((void *)c, (void *)vm);
    a3 = func_02159B10((void *)c, (void *)vm);
    a4 = func_02159B10((void *)c, (void *)vm);
    vec[0] = (a2 << 16) + 0x8000;
    vec[1] = a3 << 15;
    vec[2] = (a4 << 16) + 0x8000;
    func_021F3AA0(p, a1, vec);
    return 0;
}

int func_0216BCE4(void *ctx, void *vm)
{
    void *ws, *p, *task;
    ws = func_0215A5F4(vm);
    p = func_0215A5DC(vm);
    task = func_021F3B68(p, func_02159B10(ctx, vm));
    if (task == 0) return 1;
    func_0215897C(ws, task);
    return 1;
}

int func_0216BD1C(void *ctx, void *vm)
{
    void *ws, *p, *task;
    ws = func_0215A5F4(vm);
    p = func_0215A5DC(vm);
    task = func_021F3B40(p, func_02159B10(ctx, vm));
    if (task == 0) return 1;
    func_0215897C(ws, task);
    return 1;
}


/*
 * Script command: reads a species and a flag value and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a kind
 * and, for 647/648, a signature move (548/547, dropped when the flag is 0),
 * and stores func_0216BE20's answer in the second variable; any other
 * species stores 0.
 */
int func_0216BD54(void *ctx, void *work)
{
    void *s = func_02012934(func_0215A5E4(work));
    int species = func_02159B10(ctx, work);
    unsigned int flag = func_02159B10(ctx, work);
    u16 *out = func_02159AE8(ctx, work);
    u16 *res = func_02159AE8(ctx, work);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *res = 0;
        return 0;
    }
    if (flag == 0) {
        move = 0;
    }
    *res = func_0216BE20((int)s, species, move, kind, out);
    return 0;
}


int func_0216BE20(int a, int b, int e, int d, u16 *out)
{
    int found;
    int n;
    int i;
    void *obj;

    n = func_0201AA18((void *)a);
    found = 0;
    *out = 0;
    for (i = 0; i < n; i++) {
        obj = func_0201AB28((void *)a, i);
        if (func_0202F488((int)obj, d) == 0) {
            continue;
        }
        if (b != func_02017E1C(obj, 5, 0)) {
            continue;
        }
        if (e != 0) {
            if (e == func_02017E1C(obj, 0x36, 0)
                || e == func_02017E1C(obj, 0x37, 0)
                || e == func_02017E1C(obj, 0x38, 0)
                || e == func_02017E1C(obj, 0x39, 0)) {
                continue;
            }
        }
        found = 1;
        *out = i;
        break;
    }
    return found;
}


int func_0216BEC0(int c, int vm)
{
    void *r7;
    int k;
    int m;
    int t;
    void *obj;

    r7 = func_02012934(func_0215A5E4((void *)vm));
    k = func_02159B10((void *)c, (void *)vm);
    m = func_02159B10((void *)c, (void *)vm);
    switch (k) {
    case 0xFB:
        t = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        t = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    obj = func_0201AB28((void *)r7, m);
    if (func_0202F488((int)obj, t) == 0) {
        return 0;
    }
    func_0202F630((u32)obj, t);
    return 0;
}
