/*
 * file:     unit_0273042C.c
 * unit:     yes
 * function: func_0273042C, func_02730440, func_02730454, func_02730468, func_0273063C, func_02730868, func_027309A8, func_027309FC, func_02730B04, func_02730B48, func_02730BD8, func_02730C2C, func_02730CC0, func_02730D50, func_02730DE4, func_02730EEC, func_02730FBC, func_02731000, func_02731060, func_027310C0, func_0273112C, func_02731154, func_027311A0, func_027311E8, func_02731210, func_02731234, func_02731254, func_0273126C, func_027312B4, func_027312D0, func_027312F8
 * address:  0x0273042C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Written from the disassembly; the stand-ins of the earlier
 * restructure output were replaced by real code.
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_02084EB8 0x02084EB8 arm
 *   func_02084C68 0x02084C68 arm
 *   func_02084CEC 0x02084CEC arm
 *   func_02084F10 0x02084F10 arm
 *   func_02088610 0x02088610 arm
 *   func_02004490 0x02004490 thumb
 *   func_02084968 0x02084968 arm
 *   func_02085CBC 0x02085CBC arm
 *   func_02086DB0 0x02086DB0 arm
 *   func_020885A0 0x020885A0 arm
 *   func_02730210 0x02730210 arm twl
 *   func_02730220 0x02730220 arm twl
 *   func_02730230 0x02730230 arm twl
 *   func_02730294 0x02730294 arm twl
 *   func_0273032C 0x0273032C arm twl
 *   func_027303A4 0x027303A4 arm twl
 *   func_027303C4 0x027303C4 arm twl
 *   func_027303EC 0x027303EC arm twl
 *   data_02732F5C 0x02732F5C data twl
 *   data_02732F60 0x02732F60 data twl
 *   data_02732F64 0x02732F64 data twl
 *   data_02732F68 0x02732F68 data twl
 *   data_02732F6C 0x02732F6C data twl
 *   data_02150F68 0x02150F68 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Slot {
    u32 f0;
    u32 f4;
    u32 f8;
};

#define PIN(g, i) (((volatile u16 (*)[8])data_02732F6C)[g][i])

extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern u32 func_02084EB8(void);
extern void func_02084C68(u32, void *, void *);
extern void func_02084CEC(u32, void *, void *);
extern void func_02084F10(u32);
extern int func_02088610(u32, u32, u32);
extern void func_02004490(u32);
extern u32 func_02084968(u32);
extern void func_02085CBC(void);
extern void func_02086DB0(u32, u32, u32);
extern void func_020885A0(u32, void *);
extern u32 func_02730210(u32);
extern u32 func_02730220(u32);
extern u32 func_02730230(u32);
extern u32 func_02730294(u32, u32, u32);
extern u32 func_0273032C(u32, u32, u32);
extern u32 func_027303A4(void);
extern u32 func_027303C4(void);
extern u32 func_027303EC(void);
extern int data_02732F5C;
extern int *data_02732F60;
extern u32 *data_02732F64;
extern int data_02732F68;
extern u16 data_02732F6C[3][8];
extern struct Slot data_02150F68[];

u32 func_0273042C(u32 a);
u32 func_02730440(u32 a);
u32 func_02730454(u32 a);
void func_02730468(void);
void func_0273063C(u32 tag, u32 data, int err);
u32 func_02730868(u32 ch, int n, u32 val);
u32 func_027309A8(u32 ch, int start, int n, u32 val);
u32 func_027309FC(u32 ch, int start, int n, u32 val);
u32 func_02730B04(u32 ch, u32 val);
u32 func_02730B48(u32 ch, u32 val);
u32 func_02730BD8(u32 ch, int start, int n, u32 val);
u32 func_02730C2C(u32 ch, int start, int n, u32 val);
u32 func_02730CC0(u32 ch, u32 val, u32 newval);
u32 func_02730D50(u32 ch, int start, int n, u32 val, u32 newval);
u32 func_02730DE4(u32 ch, int n, u32 val);
u32 func_02730EEC(u32 ch, int start, int n, u32 val);
u32 func_02730FBC(u32 ch, u32 val);
u32 func_02731000(u32 ch, u32 val);
u32 func_02731060(u32 ch, int start, int n, u32 val);
u32 func_027310C0(u32 ch, u32 val);
u32 func_0273112C(u32 ch, u32 idx);
void func_02731154(u32 a, u32 b);
void func_027311A0(u32 data, u32 *cmd, u32 *p2, u32 *p3, u32 *p4);
void func_027311E8(u16 *p);
void func_02731210(u32 id);
u32 func_02731234(u16 *p);
void func_02731254(u32 id, u32 irq);
void func_0273126C(u32 a, u32 b, u32 c);
void func_027312B4(void);
asm void func_027312D0(void);
asm void func_027312F8(void);

u32 func_0273042C(u32 a)
{
    return func_027303A4() + (a << 16);
}

u32 func_02730440(u32 a)
{
    return func_027303C4() + (a << 15);
}

u32 func_02730454(u32 a)
{
    return func_027303EC() + (a << 15);
}

void func_02730468(void)
{
    int i;
    if (data_02732F5C != 0) {
        return;
    }
    data_02732F5C = 1;
    for (i = 0; i < 4; i++) {
        switch (func_02730210(i) & 1) {
        case 0:
            PIN(0, i) = PIN(0, i) & ~0x300;
            PIN(0, i) = PIN(0, i) & ~3;
            break;
        case 1:
            PIN(0, i) = (PIN(0, i) & ~0x300) | 0x100;
            PIN(0, i) = (PIN(0, i) & ~3) | 1;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        switch (func_02730220(i) & 3) {
        case 0:
            PIN(1, i) = PIN(1, i) & ~0x300;
            PIN(1, i) = PIN(1, i) & ~3;
            break;
        case 1:
            PIN(1, i) = (PIN(1, i) & ~0x300) | 0x100;
            PIN(1, i) = (PIN(1, i) & ~3) | 1;
            break;
        default:
            PIN(1, i) = (PIN(1, i) & ~0x300) | 0x200;
            PIN(1, i) = (PIN(1, i) & ~3) | 2;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        switch (func_02730230(i) & 3) {
        case 0:
            PIN(2, i) = PIN(2, i) & ~0x300;
            PIN(2, i) = PIN(2, i) & ~3;
            break;
        case 1:
            PIN(2, i) = (PIN(2, i) & ~0x300) | 0x100;
            PIN(2, i) = (PIN(2, i) & ~3) | 1;
            break;
        default:
            PIN(2, i) = (PIN(2, i) & ~0x300) | 0x200;
            PIN(2, i) = (PIN(2, i) & ~3) | 2;
            break;
        }
    }
    func_020885A0(0x12, func_0273063C);
}

void func_0273063C(u32 tag, u32 data, int err)
{
    u32 cmd, arg, ch, sub;
    u32 result;

    if (err == 0) {
    result = 0;

    func_027311A0(data, &cmd, &ch, &sub, &arg);
    switch (cmd) {
    case 1:
        result = func_02730868(ch, (arg >> 8) & 0xFF, sub);
        break;
    case 2:
        result = func_027309FC(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 3:
        result = func_02730B48(ch, sub);
        break;
    case 4:
        result = func_02730C2C(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 5:
        result = func_02730CC0(ch, sub, (arg >> 12) & 3);
        break;
    case 6:
        result = func_02730D50(ch, (arg >> 8) & 0xF, arg & 0xFF, sub, (arg >> 12) & 3);
        break;
    case 7:
        result = func_02730DE4(ch, arg & 0xFF, sub);
        break;
    case 8:
        result = func_02730EEC(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 9:
        result = func_02731000(ch, sub);
        break;
    case 10:
        result = func_02731060(ch, (arg >> 8) & 0xFF, arg & 0xFF, sub);
        break;
    case 11:
        result = (data_02732F6C[ch][arg] & 0x300) >> 8;
        break;
    case 14:
        result = func_027310C0(ch, sub) & 0xFF;
        break;
    }
    func_02731154(1, result);
    } else {
        if (data_02732F64 != 0) {
            *data_02732F64 = data;
        }
        if (data_02732F60 != 0) {
            *data_02732F60 = 1;
        }
        data_02732F68 = 0;
    }
}

u32 func_02730868(u32 ch, int n, u32 val)
{
    int run, start, i, lim;

    if (ch == 0) {
        n = n / 2;
    }
    run = 0;
    lim = 4;
    if (ch != 0) {
        lim = 8;
    }
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && (cur == val || cur == 3)) {
            if (run == 0) {
                start = i;
            }
            run++;
            if (run >= n) {
                break;
            }
        } else {
            run = 0;
        }
    }
    if (run < n) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        data_02732F6C[ch][start + i] = (data_02732F6C[ch][start + i] & ~3) | val;
        func_02730294(ch, start + i, val);
        func_0273032C(ch, start + i, 1);
    }
    if (ch == 0) {
        return func_0273042C(start);
    }
    if (ch == 1) {
        return func_02730440(start);
    }
    if (ch == 2) {
        return func_02730454(start);
    }
    return 0;
}

u32 func_027309A8(u32 ch, int start, int n, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = func_02731234(&sv);
    r = func_027309FC(ch, start, n, val);
    func_02731254(sv, irq);
    return r;
}

u32 func_027309FC(u32 ch, int start, int n, u32 val)
{
    int end, i;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) != 3 || (cur != val && cur != 3)) {
            return 0;
        }
    }
    for (i = start; i < end; i++) {
        data_02732F6C[ch][i] = (data_02732F6C[ch][i] & ~3) | val;
        func_02730294(ch, i, val);
        func_0273032C(ch, i, 1);
    }
    if (ch == 0) {
        return func_0273042C(start);
    }
    if (ch == 1) {
        return func_02730440(start);
    }
    if (ch == 2) {
        return func_02730454(start);
    }
    return 0;
}

u32 func_02730B04(u32 ch, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = func_02731234(&sv);
    r = func_02730B48(ch, val);
    func_02731254(sv, irq);
    return r;
}

u32 func_02730B48(u32 ch, u32 val)
{
    int lim, i, count;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = (v & ~3) | 3;
            func_02730294(ch, i, 1);
            func_0273032C(ch, i, 0);
            count++;
        }
    }
    return count;
}

u32 func_02730BD8(u32 ch, int start, int n, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = func_02731234(&sv);
    r = func_02730C2C(ch, start, n, val);
    func_02731254(sv, irq);
    return r;
}

u32 func_02730C2C(u32 ch, int start, int n, u32 val)
{
    int count, i, end;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = (v & ~3) | 3;
            func_02730294(ch, i, 1);
            func_0273032C(ch, i, 0);
            count++;
        }
    }
    return count;
}

u32 func_02730CC0(u32 ch, u32 val, u32 newval)
{
    int lim, i, count;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = newval | (v & ~3);
            func_02730294(ch, i, newval);
            func_0273032C(ch, i, 1);
            count++;
        }
    }
    return count;
}

u32 func_02730D50(u32 ch, int start, int n, u32 val, u32 newval)
{
    int count, i, end;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = newval | (v & ~3);
            func_02730294(ch, i, newval);
            func_0273032C(ch, i, 1);
            count++;
        }
    }
    return count;
}

u32 func_02730DE4(u32 ch, int n, u32 val)
{
    int run, start, i, lim;

    if (ch == 0) {
        n = n / 2;
    }
    run = 0;
    lim = 4;
    if (ch != 0) {
        lim = 8;
    }
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && cur == 3) {
            if (run == 0) {
                start = i;
            }
            run++;
            if (run >= n) {
                break;
            }
        } else {
            run = 0;
        }
    }
    if (run < n) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        data_02732F6C[ch][start + i] = (data_02732F6C[ch][start + i] & ~0x300) | (val << 8);
    }
    if (ch == 0) {
        return func_0273042C(start);
    }
    if (ch == 1) {
        return func_02730440(start);
    }
    if (ch == 2) {
        return func_02730454(start);
    }
    return 0;
}

u32 func_02730EEC(u32 ch, int start, int n, u32 val)
{
    int i, end;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][start];
        int hi = v & 0x300;
        if ((v & 3) != 3 || (hi >> 8) != 3) {
            return 0;
        }
    }
    for (i = start; i < end; i++) {
        data_02732F6C[ch][i] = (data_02732F6C[ch][i] & ~0x300) | (val << 8);
    }
    if (ch == 0) {
        return func_0273042C(start);
    }
    if (ch == 1) {
        return func_02730440(start);
    }
    if (ch == 2) {
        return func_02730454(start);
    }
    return 0;
}

u32 func_02730FBC(u32 ch, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = func_02731234(&sv);
    r = func_02731000(ch, val);
    func_02731254(sv, irq);
    return r;
}

u32 func_02731000(u32 ch, u32 val)
{
    int count, i, lim;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if (val == ((v & 0x300) >> 8)) {
            data_02732F6C[ch][i] = (v & ~0x300) | 0x300;
            count++;
        }
    }
    return count;
}

u32 func_02731060(u32 ch, int start, int n, u32 val)
{
    int count, i, end;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if (val == ((v & 0x300) >> 8)) {
            data_02732F6C[ch][i] = (v & ~0x300) | 0x300;
            count++;
        }
    }
    return count;
}

u32 func_027310C0(u32 ch, u32 val)
{
    u32 mask;
    int i, lim;

    mask = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && (cur == val || cur == 3)) {
            mask |= 1 << i;
        }
    }
    return mask;
}

u32 func_0273112C(u32 ch, u32 idx)
{
    return (data_02732F6C[ch][idx] & 3) != 3;
}

void func_02731154(u32 a, u32 b)
{
    while (func_02088610(0x12, b, a) != 0) {
        func_02004490(1);
    }
}

void func_027311A0(u32 data, u32 *cmd, u32 *p2, u32 *p3, u32 *p4)
{
    if (cmd != 0) {
        *cmd = (data >> 20) & 0xF;
    }
    if (p2 != 0) {
        *p2 = (data >> 18) & 3;
    }
    if (p3 != 0) {
        *p3 = (data >> 16) & 3;
    }
    if (p4 != 0) {
        *p4 = (u16)data;
    }
}

void func_027311E8(u16 *p)
{
    *p = func_02084EB8();
    func_02084C68(*p, (void *)0x02FFF680, 0);
}

void func_02731210(u32 id)
{
    func_02084CEC(id, (void *)0x02FFF680, 0);
    func_02084F10(id);
}

u32 func_02731234(u16 *p)
{
    u32 irq = func_02087988();
    func_027311E8(p);
    return irq;
}

void func_02731254(u32 id, u32 irq)
{
    func_02731210(id);
    func_0208799C(irq);
}

void func_0273126C(u32 a, u32 b, u32 c)
{
    u32 bit = 1 << (a + 28);
    data_02150F68[a].f0 = b;
    data_02150F68[a].f8 = c;
    data_02150F68[a].f4 = func_02084968(bit) & bit;
}

void func_027312B4(void)
{
    func_02085CBC();
    func_02086DB0(3, 0x8000000, 0x32);
}

asm void func_027312D0(void)
{
    ldr r0, =0x02FFFDFC
    ldr r0, [r0]
    ldr r0, [r0]
    mov r0, r0, lsl #0x1c
    mov r0, r0, lsr #0x1f
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}

asm void func_027312F8(void)
{
    ldr r0, =0x02FFFD68
    ldrb r0, [r0, #4]
    mov r0, r0, lsl #0x1f
    mov r0, r0, lsr #0x1f
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}
