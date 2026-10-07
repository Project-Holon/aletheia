/*
 * file:     btl_server_p128.c
 * unit:     yes
 * function: func_021CD644, func_021CD64C, func_021CD6AC, func_021CD6EC
 * address:  0x021CD644
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
 *   func_021CCAD4   0x021CCAD4  thumb ov093
 *   func_021CCAE0  0x021CCAE0  thumb  ov093
 *   func_021CCB98  0x021CCB98  thumb  ov093
 *   func_021CCB18  0x021CCB18  thumb  ov093
 *   func_021CCBE8  0x021CCBE8  thumb  ov093
 */
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef char *va_list;

extern u8 func_021CCAD4(u8 *p);
extern void func_021CCAE0(void *w, u16 v);
extern void func_021CCB98(void *w, s32 v);
extern u16 func_021CCB18(void *r);
extern s32 func_021CCBE8(void *r);
u8 func_021CD644(u8 *p);
void func_021CD64C(void *w, u8 id, ...);
void func_021CD6AC(void *r, u8 cmd, s32 *out);
void func_021CD6EC(void);


/*
 * tail-call thunk to func_021CCAD4
 */
u8 func_021CD644(u8 *p)
{
    return func_021CCAD4(p);
}


void func_021CD64C(void *w, u8 id, ...)
{
    va_list ap;
    u16 v;
    s32 x;

    va_start(ap, id);
    v = va_arg(ap, s32);
    func_021CCAE0(w, id);
    func_021CCAE0(w, v);
    if (id == 0x5C) {
        func_021CCAE0(w, va_arg(ap, s32));
    }
    do {
        x = va_arg(ap, s32);
        func_021CCB98(w, x);
    } while (x != (s32)0xFFFF0000);
}


void func_021CD6AC(void *r, u8 cmd, s32 *out)
{
    int i;

    i = 1;
    out[0] = func_021CCB18(r);
    if (cmd == 0x5c) {
        out[1] = func_021CCB18(r);
        i++;
    }
    for (; i < 16; i++) {
        out[i] = func_021CCBE8(r);
        if (out[i] == 0xFFFF0000) {
            break;
        }
    }
}


/*
 * empty function: bx lr
 */
void func_021CD6EC(void)
{
}
